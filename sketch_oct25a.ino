void setup() {
  // put your setup code here, to run once:
//pinMode(22,OUTPUT);

pinMode(7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(7,123);
delay(5000);
}
