
#include <avr/interrupt.h>
#include <avr/sleep.h>

byte mode; // SLEEP_MODE_IDLE, SLEEP_MODE_PWR_DOWN, SLEEP_MODE_PWR_SAVE, SLEEP_MODE_ADC, SLEEP_MODE_STANDBY, SLEEP_MODE_EXT_STANDBY
void setup(){
  // configurações básicas do Arduino
  
  // aqui você pode colocar o codigo que seleciona o Modo
  set_sleep_mode(mode); // seleciona como o Arduino irá dormir, isso impacta na forma que o Arduino acorda

  // outras configurações básicas do Arduino conforme seu projeto;
}

bool devodormir = false;
void loop(){

  // seu código no qual precisa executar antes de colocar o Arduino para dormir
  
  cli(); // é preciso dar uma pausa em todas as interrupções para a proxima configuração
  if (devodormir) // controlo se devo ativar ou não o modo dormir.
  {
    sleep_enable(); // ativo o recurso para dormir
    sei(); // abilito de novo as interrupções, se eu não fizer isso apenas com reset para acordar o Arduino
    sleep_cpu(); // aqui o Arduino Dorme
    sleep_disable(); // aqui algo o acordou. a forma de acordar o Arduino muda conforme o modo que se escolheu.
  }
  sei(); // reativo todas as interrupções se eu precisar delas.
  
  // code que deve ser executado depois de acordar o Arduino.
}
