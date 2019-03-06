void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

String tx = "palabra";
int i=0;
void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(tx+i);
}
