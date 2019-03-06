//For more details go to  mchp.blogspot.com
#include <DHT.h>        // standard DHT library
#define DHT1PIN 2//12      // signal pin for sensor #1
#define DHT2PIN 5//15      // signal pin for sensor #2
#define DHTTYPE DHT22   // defining the sensor type - DHT 22  (AM2302)
DHT dht1(DHT1PIN, DHTTYPE);
DHT dht2(DHT2PIN, DHTTYPE);
//#include <Adafruit_LiquidCrystal.h> // using Adafruit LCD library 
//(works well with 2004 LCD)
//Adafruit_LiquidCrystal lcd(5, 4, 3, 2, 1, 0); // LCD pinout
//byte degreeChar[8] =  // creating a Celsius degree sign
///{ B01100,
//  B10010,
//  B10010,
//  B01100,
//  B00000,
//  B00000,
//  B00000,
//  B00000,
//};

void setup()  {
  pinMode(10, OUTPUT); // I use those pins to power the sensors
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(17, OUTPUT);
  digitalWrite(10, LOW); // GND for sensor #1
  digitalWrite(13, HIGH); // VDD for sensor #1
  digitalWrite(17, LOW); // GND for sensor #2
  digitalWrite(14, HIGH); // VDD for sensor #2
  //lcd.begin(20, 4); //  start LCD
  Serial.begin(9600);
  dht1.begin(); //  start sensor1
  dht2.begin(); //  start sensor2
}
void loop()
{
  float h1 = dht1.readHumidity();     // variable for humidity of sensor #1
  float t1 = dht1.readTemperature();  // variable for temperature of sensor #1
  float h2 = dht2.readHumidity();     // variable for humidity of sensor #2
  float t2 = dht2.readTemperature();  // variable for temperature of sensor #2
  delay(2000);                        // wait 2 seconds for sensors to be ready
  if (isnan(t1) || isnan(h1)) {       // checking sensor #1
    //lcd.setCursor(0, 0);
    Serial.println("DHT22 SENSOR 1 ERROR");// print error message
    //if sensor is not working
  }
  else {                              // if sensor OK - print measurements
    Serial.print("t1=");
    Serial.print(t1);
    Serial.print(",h1=");
    Serial.println(h1);
  }
  if (isnan(t2) || isnan(h2)) {       // checking sensor #2
    Serial.println("DHT22 SENSOR 2 ERROR");// print error message
    //if sensor is not working
  }
  else {                              // if sensor OK - print measurements
    Serial.print("t2=");
    Serial.print(t2);
    Serial.print("h2=");
    Serial.println(h2);
  }
}
