/*Distance measurement using HC-SR04 using 8 bit timer0
*With frequency 16 MHZ and Prescaler clck/1, 
*each tick increment counter every 6.25e-8 (0.0000000625 s)
*Using a running counter and the tick period, 
*we will determine time taken for each pulse
*/


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define trig_DDR		DDRD
#define echo_DDR		DDRB
#define trig_PORT		PORTD
#define echo_PORT		PORTB
#define trig_PIN		PD7
#define echo_PIN		PB0
#define echo_PORTIN		PINB
#define echo_PCICR		PCIE0
#define echo_PCMSK		PCMSK0
#define echo_PCINT		PCINT0


#define	buzzer_DDR		DDRB
#define buzzer_PORT		PORTB
#define buzzer_PIN		PB1


#define CLOCK_PERIOD 	0.0000000625
#define SPEED_SOUND		340


unsigned long running = 0;	//running counter to manage overflow	
unsigned  stop;				//keep track of the last timer0 register value
int complete = 0;			//status of measure
int cm = 0;					//store distance in cm


/*function prototypes*/
void play_sound();
void beep();
int getDistance();
void HCSR04_setup();
void sendPulse();


int main(void){
	HCSR04_setup();
  	while(1){
   	 	
    	sendPulse();
    	cm = getDistance();
      	if(cm <= 45){
        	beep();
      	}
    	
  	}  
}

/*******************buzzer*****************************************/

/*This function will play a sound for a certain duration*/

void play_sound(){
  int i;
  int duration = 200;
  int period = 1;		//period in ms
  int cycles = duration /period;		//the number of cycles for that duration
  /*set buzzer pin to output*/
  buzzer_DDR |= 1 << buzzer_PIN;
  
  for(i = 0; i < cycles; i++)
  {
  	/*wait for half a period before setting the buzzer to HIGH*/
    _delay_us(500); 			
    buzzer_PORT |= (1 << buzzer_PIN); 
    
    /*wait for half a period before setting the buzzer to LOW*/
    _delay_us(500); 
     buzzer_PORT &= ~(1 << buzzer_PIN); 
  
  }  
  
}

/*This function will play 2 sound beep in between pauses*/
void beep(){	
   play_sound();
   _delay_ms(200);
   play_sound();
   _delay_ms(500);

} 








/*************************HC-SR04**********************************/

int getDistance(){
  	while(!complete);						 	//wait for measurement to be complete
  	long total_ticks = stop + running; 
  	float time = total_ticks * CLOCK_PERIOD; 	// in seconds seconds
  	float distance = (SPEED_SOUND * time)/2; 
  	return distance*100;
  
  
}  

 void sendPulse(){

	/*sets the trigger pin to HIGH for 10 ms*/
   	PORTD |= (1 << PD7);
    _delay_us(10);
   	PORTD &= ~(1 << PD7);
  } 

void HCSR04_setup(){
  	
  	sei();									//enable external register
    trig_DDR |= 1 << trig_PIN;				//set trigger pin to output for trigger
  	echo_DDR &= ~(1 << echo_PIN);			//set pin 8 to input for echo
    trig_PORT &= ~(1 << trig_PIN); 			//clear trigger pin by setting that pin to low
   	PCICR |= 1 << echo_PCICR; 				//enable pin change interrupt for port
   	echo_PCMSK |= 1 << echo_PCINT;			//enable pin change interrupt for pin
  	TIMSK0 |= 1<< TOIE0;					//enable overflow interrupt for timer0
}


ISR(TIMER0_OVF_vect){
  running += 255;
}

ISR(PCINT0_vect){
  if((echo_PORTIN & (1 << echo_PIN)) > 0){	//rising edge when, echo pin becomes HIGH from LOW
    running = TCNT0;						//reset running counter for new distance measurement
  	TCCR0B |= 1 << CS00; 					//start timer0 by setting prescaler to clck/1
    complete = 0;
  } 
  else{
    stop = TCNT0; 							//get the last value from the timer counter register
   	TCCR0B = 0x00;							//stop the timer
    TCNT0 = 0x00;							//reset timer0 rgister
    complete = 1;							//measurement complete
 }
  
}
