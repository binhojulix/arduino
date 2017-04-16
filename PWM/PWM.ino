/*
PWM
controla a luminosidade de um led conforme o valor do potenciometro
*/
 
 int ledPin = 3; // pino do led
 int analogPin = 0; // pino para leitura do potenciômetro
 int val = 0; //variável para armazenar o valor lido
 
 void setup()
 { 
    pinMode(ledPin, OUTPUT); // configura pino como saída
 }
 
 void loop()
 {
    val = analogRead(analogPin);  // le o valor analógico
    analogWrite(ledPin, val / 4); // aciona led com o valor analógico lido
                                   //dividido por 4 para ajustar ao valor  
                                   //máximo que pode ser atribuído a função
}
