#include <avr/io.h>
#include <util/delay.h>

#define	buzzer_DDR		DDRB
#define buzzer_PORT		PORTB
#define buzzer_PIN		PB1


void play_sound();
void beep();
