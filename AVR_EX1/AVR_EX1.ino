#include<avr/io.h>
#include<util/delay.h>


#define setBit(valor,bitt) (valor |= (1<<bitt))
#define clearBit(valor,bitt)(valor &= ~(1<<bitt)) 
#define toogle(valor, bitt) (valor ^= (1<<bitt))
#define readState(valor, bitt) (valor &= (1<< bitt))

int main(void){
 
    setBit(DDRB, DDB5); //Setar PB5 do banco B(DDRB) como output.
    DDRB |= ((1<<DDB0) | (1<<DDB1)); // Setar PD0 e  PD1 do banco D (DDRD) como output.
    
    clearBit(DDRD, DDD0); // Seta PD0 do banco D(DDRD) como imput.
    setBit(DDRD, DDD1); //Seta PD1 do banco D(DDRD) como output.
    
    PORTD |= (1<<PORTD1);  //LIGA O PIND1
    
  while(1){
    
    bool x = (PIND & (1 << PIND0)); // Le oe stado do pind0
    
     if(x){//faz a leitura do pino 0 da portb (PB0)
       toogle(PORTB, PINB5); // Inverte o estado do PB5 do portB
       PORTB ^= (1<<PORTB0) | (1<<PORTB1); // Inverte o estado de portb0 e portb1
       _delay_ms(10);
    }
  }
}








