#include<avr/io.h>

int main(void){
  
  unsigned char i;
  DDRA = 0x00; // PORTA INPUT
  DDRB = 0xFF; // PORTB OUTPUT
  PORTB = 0x00; //Liga todos os leds
  while(1){
    i = PINA;
    PORTB=i;
  }
  return i;
}

