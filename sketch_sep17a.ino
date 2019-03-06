/*
  Capitulo 7 de Arduino desde cero en Español
  Programa que utiliza el sensor DHT22 o DHT11 para obtener datos de temperatura
  y humedad. Deben instalarse la Librerias DHT Sensor Library y Adafruit Unified Sensor.

  Autor: bitwiseAr  

*/

#include <DHT.h>    // importa la Librerias DHT
#include <DHT_U.h>

int SENSOR = 2;     // pin DATA de DHT22 a pin digital 2
int TEMPERATURA;
int HUMEDAD;

DHT dht(SENSOR, DHT22);   // creacion del objeto, cambiar segundo parametro
        // por DHT11 si se utiliza en lugar del DHT22
void setup(){
  Serial.begin(9600);   // inicializacion de monitor serial
  dht.begin();      // inicializacion de sensor
}

void loop(){
  TEMPERATURA = dht.readTemperature();  
  HUMEDAD = dht.readHumidity();
  Serial.print("T:");
  Serial.print(TEMPERATURA);
  Serial.print("H:");
  Serial.println(HUMEDAD);
  delay(500);
}
