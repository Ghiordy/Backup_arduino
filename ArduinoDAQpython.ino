#include <LiquidCrystal.h>
#include <DHT.h>    // importa la Librerias DHT
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float Sensibilidad=0.066; //sensibilidad en Voltios/Amperio para sensor de 5A
int sensorVpin = A9;    
int sensorVvalue;  
float dataV;

int SENSOR = A10;     // pin DATA de DHT22 a pin digital 2
float TEMPERATURA;
float HUMEDAD;
DHT dht(SENSOR, DHT22);

void setup() {
Serial.begin(9600);
lcd.begin(16,2);
lcd.clear();
//pinMode(A10,INPUT);
}

void loop() {
  if(millis() To + 1000){
    lcd.clear();
    lcd.setCursor(0,0);
    TEMPERATURA = dht.readTemperature();
    Serial.print(TEMPERATURA);
    Serial.print(",");
    lcd.print("T:"+String(TEMPERATURA));
    HUMEDAD = dht.readHumidity();
    Serial.print(HUMEDAD);  
    Serial.print(",");
    lcd.print("H:"+String(HUMEDAD));
    sensorVvalue = analogRead(sensorVpin);//LEEMOS LA LECTURA DEL SENSOR
    dataV = sensorVvalue*(0.0244);
    Serial.print(dataV);//MULTIPLICAMOS PARA SABER EL VOLTAJE
    lcd.print("V:"+String(dataV));
    //delay(1000);
    float voltajeIsensor= analogRead(A8)*(5.0 / 1023.0); //lectura del sensor   
    float I=(voltajeIsensor-2.5)/Sensibilidad; //Ecuación  para obtener la corriente
    Serial.print(",");
    Serial.println(I); 
    lcd.print("I:"+String(I));
    //delay(1000);
    To = millis();}
}
