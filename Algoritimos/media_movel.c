#define pot A0;//potenciometro na entrada analogicia 0

//=================================================
//------constrantes auxiliares--------------
#define n 10

//=================================================
//------Variáveis globais--------------
int original; //recebe o valor do potenciometro
int filtrado; //recebe o valor original filtrado
int numbers[n];




void setUp(){
	Serial.begin(9600);
	pinMode(pot, INPUT);
}

void loop(){
	original = analogRead(pot); // recebe o valor do potenciometro
	filtrado = moving_average();
	Serial.print(original);
	Serial.print(" ");
	Serial.println(filtrado);
	delay(20);
}

long moving_average(){
	for(int i=n-1; i>0; i--)
		numbers[i] = numbers[i-1];
	numbers[0]=original;
	long acumulador = 0;
	for(int i=0; i<n; i++){
		acumulador+=numbers[i]
	}
	return acumulador/n;
}

