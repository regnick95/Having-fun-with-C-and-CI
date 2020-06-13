#include "buzzer.h"


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
