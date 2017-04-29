unsigned long amp  = 500;
//gera onda quadrada
//soma das harmonicas impares 
//soma dos senos

void setup(){
	Serial.begin(9600);
}

void loop(){
	for(int i=0; i<360; i++){
		Serial.println(((amp/1) * sin(i*1*(PI/180)))
				     + ((amp/3) * sin(i*3*(PI/180)))
				     + ((amp/5) * sin(i*5*(PI/180)))
			);
	}
}