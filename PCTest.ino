#include <SoftwareSerial.h>
 # include<Wire.h>
# include<Servo.h> 
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
#define led 2

SoftwareSerial BTSerial(10,11); // RX | TX,
int servopin = 12; 
Servo servo;
int frequencyR = 0;
int frequencyG =0;
int frequencyB = 0;
//int led = 10;
String key = String("");
String can = String("Coke");


char INBYTE;
int  LED = 13; // LED on pin 13

void setup() {
  Wire.begin();
  servo.attach(servopin);
  pinMode(led, OUTPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  digitalWrite(led,HIGH);
 
  servo.write(0);
  
  BTSerial.begin(38400); 
  pinMode(LED, OUTPUT);


}

void loop() {

  Wire.beginTransmission(8);
  Wire.write('H');
  Wire.endTransmission();

  //if(key == String("")){
  BTSerial.println("Press 0 for sprite, 1 for pepsi or 2 for coke");
  while (!BTSerial.available()){
      Wire.beginTransmission(8);
  Wire.write('H');
  Wire.endTransmission();// stay here so long as COM port is empty   
  }
  INBYTE = BTSerial.read();        // read next available byte
   if( INBYTE == '0' ){
    key = String("Sprite");  // if it's a 0 (zero) tun LED off
    Wire.beginTransmission(8);
    Wire.write('L');
    Wire.endTransmission();
   }
  if( INBYTE == '1' ){
    key = String("Pepsi"); // if it's a 1 (one) turn LED on
Wire.beginTransmission(8);
    Wire.write('L');
    Wire.endTransmission();
  }
  if( INBYTE == '2' ){
    key = String("Coke"); // if it's a 1 (one) turn LED on
    Wire.beginTransmission(8);
    Wire.write('L');
    Wire.endTransmission();
  }
  delay(50);
 // }

  while(key != String("")){
    // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequencyR = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequencyR = map(frequencyR, 25,72,255,0);
  // Printing the value on the serial monitor
  //Serial.print("R= ");//printing name
  //Serial.print(frequencyR);//printing RED color frequency
  //Serial.print("  ");
  delay(100);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequencyG = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequencyG = map(frequencyG, 30,90,255,0);
  // Printing the value on the serial monitor

 // Serial.print("G= ");//printing name
  //Serial.print(frequencyG);//printing RED color frequency
  //Serial.print("  ");
  delay(100);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequencyB = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequencyB = map(frequencyB, 25,70,255,0);
  // Printing the value on the serial monitor

 // Serial.print("B= ");//printing name
 // Serial.print(frequencyB);//printing RED color frequency
  //Serial.println("  ");
  delay(100);
if (frequencyR> frequencyG && frequencyR > frequencyB&& frequencyR < 50){
 // Serial.print("Coke");
  can = String("Coke");
}
if (frequencyG > frequencyR && frequencyG > frequencyB){
 // Serial.print("Sprite");
  can = String("Sprite");
}
if (frequencyB > frequencyR && frequencyB > frequencyG){
  //Serial.print("Pepsi");
  can = String("Pepsi");
}
if (can == key){
 
//  delay(1000);
  char c = 'H';
  if (c == 'H'){
    Wire.beginTransmission(8);

    Wire.write('H');
   
   
    Wire.endTransmission();
    
    
    delay(1000);
      servo.write(63);
   //   Wire.endTransmission();
    delay(2000);
  }
  //delay(3000);
  c = 'L';
    
if(c=='L'){
      
      Wire.beginTransmission(8);
      Wire.write('L');
      Wire.endTransmission();
      delay(15000);
} 
    key = String("");
    }

  } 
  
}
