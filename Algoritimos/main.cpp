/*
 * GccApplication2.c
 *
 * Created: 14/05/2016 19:28:18
 * Author : binho
 */ 
#define  F_CPU 20000
#include <avr/io.h>
#include <util/delay.h>
#include "lib/BlinkState.h"
#include "lib/PWMControle.h"
#define setBit(valor,bit)   (valor|=(1<<bit))
#define clearBit(valor, bit) (valor &= ~(1<<bit))
#define toggleBit(valor, bit)  (valor ^= (1<<bit))

class Blink{
	
	public:void blink(){
		PORTB ^= (1<<PORTB0) | (1<<PORTB5); // Inverte o estado de portb0 e portb1
	}
};


int main(void)
{
	
	DDRB |= 1<<DDB0 | 1<<DDB5; //define pinos como saida

	DDRD &= ~(1<<DDB0); //define como entrada pin0
	
	PORTD |= 1<<PORTD1; // pind1 sempre como high
	
	enum DurationTime {CURTO=50, MEDIO=75, LONGO=100};
	BlinkState blinkstate(0);
	Blink myBlink;
	DurationTime durationTime = LONGO;
	PWMControle controle(10);
	controle.onPWM();
	
    /* Replace with your application code */
    while (1) 
    {
		bool state = blinkstate.blinkVerification();
				
		if(state){
			myBlink.blink();
			
		}
		
		_delay_ms(durationTime);
		
    }
}

