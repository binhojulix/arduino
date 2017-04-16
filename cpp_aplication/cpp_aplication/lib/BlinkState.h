#include<avr/io.h>

class BlinkState{
	
	public:
		
		BlinkState(int pininho){
			pino = pininho;
		}
		
		bool blinkVerification(){
			bool state = (PIND & (1 << PIND0)); // Le oe stado do pind0
			if (state){
				return true;
				}else{
				return false;
			}
		}
	private:
		int pino;
		
};


