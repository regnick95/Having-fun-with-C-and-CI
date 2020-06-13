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


#define CLOCK_PERIOD 		0.0000000625
#define SPEED_SOUND		340


unsigned long running;			//running counter to manage overflow	
unsigned  stop;				//keep track of the last timer0 register value
int complete;				//status of measure
int cm;					//store distance in cm


/*function prototypes*/
int getDistance();
void HCSR04_setup();
void sendPulse();
