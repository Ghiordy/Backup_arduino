
int sensorPin = A9;    
int sensorValue = 0;  
void setup() {
Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);//LEEMOS LA LECTURA DEL SENSOR
  Serial.print("EL VARLOR ES: ");
  Serial.print(sensorValue);// MOSTRAMOS LA LECTURA DE SENSOR
  Serial.print("  voltaje es:  ");
  Serial.println(sensorValue*(3.3/135));//MULTIPLICAMOS PARA SABER EL VOLTAJE
  delay(1000);
}
