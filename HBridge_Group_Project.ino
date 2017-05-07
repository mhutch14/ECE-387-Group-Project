#include <SoftwareSerial.h>
#include "l298n_lib.h"

int value;

void setup() {
  set_pins(9, 8, 7, 6, 10, 5);
  
  Serial.begin(38400);
}

void loop() {
  //value = 'F';


  switch (value){
    
    case 'F' : {
      lmot('B',255); 
      dmot('B',255);
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
      }
  }
}

