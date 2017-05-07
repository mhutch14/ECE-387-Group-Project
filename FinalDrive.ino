#include <SoftwareSerial.h>
#include <Wire.h>
#include "l298n_lib.h"
#define S0_L 13
#define S1_L 12
#define S2_L 11
#define S3_L 4
#define sensorOut_L 3
#define LED 2

int frequencyR_L = 0;
int frequencyG_L = 0;
int frequencyB_L = 0;

int value;
char c;

void setup() {
  set_pins(9, 8, 7, 6, 10, 5);

  Wire.begin(8);
  Wire.onReceive(receiveEvent);

  pinMode(S0_L, OUTPUT);
  pinMode(S1_L, OUTPUT);
  pinMode(S2_L, OUTPUT);
  pinMode(S3_L, OUTPUT);
  pinMode(sensorOut_L, INPUT);
  pinMode(LED, OUTPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0_L,HIGH);
  digitalWrite(S1_L,LOW);
  digitalWrite(LED, HIGH);
  
  Serial.begin(9600);
}

void loop() {
    lmot('B',200); 
    dmot('B',200);
    
   // dmot_stop();
   // lmot_stop();
  /*switch (value){
    
    case 'F' : {
      lmot('F',255); 
      dmot('F',255);
      delay(1000);
      value = 'B';
      break;  
      }
    case 'B' :{
      lmot ('B',255);
      dmot ('B',255);
      break;
      }     
    
    case 'L':{
      dmot ('F',255);
      lmot_stop(); // u sluèaju skretanja motor može stati naredbom lmot_stop ,tj dmot_stop
     break;   
       }
    
    case 'R':{
      dmot_stop();
      lmot( 'F',255);
      break;
      }
    case 'I':{
      dmot( 'F',127);
      lmot( 'F',255);
      break;
      } 
    case 'G':{
      dmot('F',255);
      lmot( 'F',127);
      break;
      } 
    case 'J':{
      dmot( 'B',127);
      lmot( 'B',255);
      break;
      } 
     case 'H':{
      dmot('B',255);
      lmot( 'B',127);
      break;
      } 
    case 'S' :{            
      dmot_stop();
      lmot_stop();
      }*/

  // Setting red filtered photodiodes to be read
  digitalWrite(S2_L,LOW);
  digitalWrite(S3_L,LOW);
  // Reading the output frequency
  frequencyR_L = pulseIn(sensorOut_L, LOW);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequencyR_L);//printing RED color frequency
  Serial.print("  ");
  //delay(150);

  
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2_L,HIGH);
  digitalWrite(S3_L,HIGH);
  // Reading the output frequency
  frequencyG_L = pulseIn(sensorOut_L, LOW);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequencyG_L);//printing RED color frequency
  Serial.print("  ");
 // delay(150);

  
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2_L,LOW);
  digitalWrite(S3_L,HIGH);
  // Reading the output frequency
  frequencyB_L = pulseIn(sensorOut_L, LOW);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequencyB_L);//printing RED color frequency
  Serial.println("  ");
 // delay(150);

 if(frequencyR_L < 850 && frequencyG_L < 850 && frequencyB_L < 850) {
     dmot_stop();
     lmot('F',255);
    // dmot_stop();
    // lmot_stop(); 
     Serial.println("White");
  }

  /*if(frequencyR_L > 710 && frequencyG_L > 920 && frequencyB_L > 790) {
     //dmot_stop();
     //lmot_stop();
     lmot('B',255); 
     dmot('B',238);
     Serial.println("Brown");
  }*/

  if(frequencyB_L >frequencyR_L && frequencyB_L >frequencyG_L && frequencyR_L  > 1500) {
    // dmot_stop();
    // lmot_stop();
     dmot('F',255);
     lmot_stop();
     Serial.println("Green");
  }

  if(c == 'H') {
        lmot_stop();
        dmot_stop();
        delay(5000);
      Serial.print(c);
      }
      
      if(c == 'L') {
        Serial.print(c);
         lmot('B',210); 
         dmot('B',200);
      }
}

  void receiveEvent(int howMany) {
 // while(Wire.available()) {
     c = Wire.read();

   /*   if(c == 'H') {
        lmot_stop();
        dmot_stop();
        delay(5000);
      Serial.print(c);
      }
      Serial.print(c);
      if(c == 'L') {
        Serial.print(c);
         lmot('B',210); 
         dmot('B',200);
      }*/
 // }
}
  



