#include <EEPROM.h>
int address = 100;
int login;
String file = "datalog";
String ext = ".txt";

void setup() {
  Serial.begin(9600);
  login = EEPROM.read(address) +1 ;
  Serial.print("Login: ");
  Serial.println(login);
  EEPROM.write(address,login);
  file = file + login + ext;
  Serial.println(file);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
