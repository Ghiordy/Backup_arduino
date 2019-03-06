#include <TimerOne.h>

int count=1;
int enaR=0;
void setup() {
  attachInterrupt(0,enc,HIGH);
  //Timer1.initialize(350000);
  //Timer1.start();
  //Timer1.attachInterrupt(conteo_int);
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(31,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  digitalWrite(31,LOW);
}

void loop() {
  if(count%2==0){digitalWrite(LED_BUILTIN,HIGH);}
  else{digitalWrite(LED_BUILTIN,LOW);}
}

void conteo_int(){
  count++;
  }

void enc(){
  delay(250);
  digitalWrite(31,HIGH);
  //Timer1.stop();
  if(enaR==0){
    Timer1.initialize(350000);
    Timer1.start();
    Timer1.attachInterrupt(conteo_int);
    enaR=1;
    }
  else{
    Timer1.stop();
    enaR=0;
    }
}
