#include "buzzer.h"
#include "distance.h"

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
