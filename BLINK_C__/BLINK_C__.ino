#include "Blink.h"
#define led 8
Blink my_blink;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  my_blink.blink(led);
  
}
