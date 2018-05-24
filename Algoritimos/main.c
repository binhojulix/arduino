/*
 * GccApplication2.c
 *
 * Created: 14/05/2016 19:28:18
 * Author : binho
 */ 
#define  F_CPU 20000
#include <avr/io.h>
#include <util/delay.h>
#define setBit(valor,bit)   (valor|=(1<<bit))
#define clearBit(valor, bit) (valor &= ~(1<<bit))
#define toggleBit(valor, bit)  (valor ^= (1<<bit))

void blink(void);

int main(void)
{
	DDRB |= 1<<DDB0 | 1<<DDB1 | 1<<DDB5; //define pinos como saida
	DDRD |= 1<< DDB1; //define pino como saida
	DDRD &= ~(1<<DDB0); //define como entrada pin0
	enum Tempo {CURTO=50, MEDIO=100, LONGO=150};
	
    /* Replace with your application code */
	enum Tempo time_duration = CURTO;
	
    while (1) 
    {
		PORTD ^= 1<<PORTD1;
	
		int state = (PIND & (1 << PIND0)); // Le oe stado do pind0
		if(state){
			blink();
		}
		
		_delay_ms(time_duration);
		
		
    }
}


void blink(){
	PORTB ^= (1<<PORTB0) | (1<<PORTB1) | (1<<PORTB5); // Inverte o estado de portb0 e portb1
}

