/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */


//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

unsigned int pin13=13;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(pin13, HIGH);
  delay(1000);
    digitalWrite(pin13, LOW);
    delay(1000);
    Serial.println("Hello World");
}
