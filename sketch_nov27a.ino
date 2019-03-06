#include<TimerOne.h>
int enaR = 0;
int RIGHT_o = 31;

void setup() {
  // put your setup code here, to run once:
  attachInterrupt(2,flasher,HIGH);
  pinMode(RIGHT_o,OUTPUT);
  pinMode(13,OUTPUT);
  Timer1.initialize(500000);
  Timer1.attachInterrupt(flasher);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2)==1){enaR=1;}
  else{enaR=0;}
}

void flasher(){
    if(enaR==0){
    enaR=1;
    digitalWrite(RIGHT_o,HIGH);
        if(digitalRead(RIGHT_o)==1){
          digitalWrite(RIGHT_o,LOW);
          }
        else{
          digitalWrite(RIGHT_o,HIGH);
          }
    }
  else{
    enaR=0;
//    Timer1.stop();
    }
  }
