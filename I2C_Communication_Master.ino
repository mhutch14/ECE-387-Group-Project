//i2c Slave Code
#include <Wire.h>



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Wire.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()){
  char c = Serial.read();
  if(c == 'H'){
    Wire.beginTransmission(5);
    Wire.write('H');
    Wire.endTransmission();
  }else if(c == 'L'){
    Wire.beginTransmission(5);
    Wire.write('L');
    Wire.endTransmission();
  }
  
  }
}
