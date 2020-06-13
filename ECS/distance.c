#include "distance.h"



int getDistance(){
  	while(!complete);			//wait for measurement to be complete
  	long total_ticks = stop + running; 
  	float time = total_ticks * CLOCK_PERIOD; // in seconds seconds
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
  	
  	sei();					//enable external register
    trig_DDR |= 1 << trig_PIN;			//set trigger pin to output for trigger
  	echo_DDR &= ~(1 << echo_PIN);		//set pin 8 to input for echo
    trig_PORT &= ~(1 << trig_PIN); 		//clear trigger pin by setting that pin to low
   	PCICR |= 1 << echo_PCICR; 		//enable pin change interrupt for port
   	echo_PCMSK |= 1 << echo_PCINT;		//enable pin change interrupt for pin
  	TIMSK0 |= 1<< TOIE0;			//enable overflow interrupt for timer0
}


ISR(TIMER0_OVF_vect){
  running += 255;
}

ISR(PCINT0_vect){
  if((echo_PORTIN & (1 << echo_PIN)) > 0){	//rising edge when, echo pin becomes HIGH from LOW
    running = 0;				//reset running counter for new distance measurement
  	TCCR0B |= 1 << CS00; 			//start timer0 by setting prescaler to clck/1
    complete = 0;
  } 
  else{
    stop = TCNT0; 				//get the last value from the timer counter register
   	TCCR0B = 0x00;				//stop the timer
    TCNT0 = 0x00;				//reset timer0 rgister
    complete = 1;				//measurement complete
 }
  
}
