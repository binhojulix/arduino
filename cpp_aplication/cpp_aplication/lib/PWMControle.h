#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <util/delay.h>

class PWMControle{
	public:
	
		PWMControle(int velocidade){
			_velocidade = velocidade;
		}
		
		int getVelocidade(){
			return _velocidade;
		}
		
		void onPWM(){
			TCCR2A = _BV(COM2A0) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
			TCCR2B = _BV(WGM22) | _BV(CS22);
			OCR2A = 180;
			OCR2B = 50;
	
		}
		
	private:
		int	_velocidade;
		 
	
	
};