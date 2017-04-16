// Daremos um nome ao pino que ficara o LED:
int led = 13;

//portas 2 e 3 aceitam sinal de interrupção

void interrupt(){
  digitalWrite(led, HIGH); // Liga o LED (HIGH = nível lógico alto)
  delay(5000);
}
 
// Esta função "setup" roda uma vez quando a placa e ligada ou resetada
void setup() {
  pinMode(led, OUTPUT); // Configura o pino do led (digital) como saída
  //porta, funcao, modo
  attachInterrupt(0,interrupt,RISING); //Configurando a interrupção
}
 
// Função que se repete infinitamente quando a placa é ligada
void loop() {
  digitalWrite(led, HIGH); // Liga o LED (HIGH = nível lógico alto)
  delay(1000);             // Espera um segundo
  digitalWrite(led, LOW);  // Desliga o LED (LOW = nível lógico baixo)
  delay(1000);             // Espera um segundo
}
