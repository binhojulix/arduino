#include <avr/wdt.h>

void setup() {   
   pinMode(12, OUTPUT); //use um LEd no pino 12 
   wdt_enable(WDTO_2S); //Função que ativa e altera o Watchdog
}

void loop()
{
  digitalWrite(12, HIGH);   
  delay(1000);              
  digitalWrite(12, LOW);  
  delay(1000); 
  wdt_reset(); //diz que esta tudo ok
}
