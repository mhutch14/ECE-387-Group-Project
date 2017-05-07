#include <arduino.h>

int IN1,IN2,IN3,IN4,spdl,spdd;//Sve bez a, DA


void set_pins(int IN1a, int IN2a, int IN3a, int IN4a, int spdla, int spdda){
  pinMode(IN1a,OUTPUT);
  pinMode(IN2a,OUTPUT);
  pinMode(IN3a,OUTPUT); 
  pinMode(IN4a,OUTPUT);
  pinMode(spdla,OUTPUT);

  IN1=IN1a;//da 
  IN2=IN2a;
  IN3=IN3a;
  IN4=IN4a;
  spdl=spdla;
  spdd=spdda;

}
  



void lmot (char smjer,int brzina){
  analogWrite(spdl,brzina);
  switch (smjer){
   case 'F' :{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    break;
   }
   case 'B' :{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    break;
    }
    }
  
}

void dmot (char smjer,int brzina){
  analogWrite(spdd,brzina);
  switch (smjer){
   case 'F' :{
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    break;
   }
   case 'B' :{
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    break;
    }
    }

}

void lmot_stop (){
  analogWrite(spdl,0);
  }
void dmot_stop(){
  analogWrite(spdd,0);
}



