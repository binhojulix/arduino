int ANA2=2;

void setup() {
  // put your setup code here, to run once:
  pinMode(ANA2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float val = (analogRead(ANA2)*5)/1023;
}
