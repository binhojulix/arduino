#include<Arduino.h>



class Blink{
  public:
    void blink(int led){
    
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led, LOW); 
    }

  
};

