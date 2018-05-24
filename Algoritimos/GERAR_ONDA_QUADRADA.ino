int potenciometroFino =12;
int potenciometroGrosso =13;
int frequencia =0;
int pinoFrequencia =11;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  frequencia = analogRead(potenciometroGrosso)*10 + analogRead(potenciometroFino);
  tone(pinoFrequencia, frequencia);
}
