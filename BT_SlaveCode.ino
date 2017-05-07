#include <AltSoftSerial.h>
AltSoftSerial BTserial; 
 
// Change DEBUG to true to output debug information to the serial monitor
boolean DEBUG = true;
 
 
// Variables used for incoming data
 
 
const byte maxDataLength = 20;          // maxDataLength is the maximum length allowed for received data.
char receivedChars[maxDataLength+1] ;
boolean newData = false;               // newData is used to determine if there is a new command
 
 
 
void setup()  
{
    // LED on pin 13
    pinMode(3, OUTPUT); 
    digitalWrite(3,LOW);
 
 
    if (DEBUG)
    {
        // open serial communication for debugging and show the sketch name and the date compiled
        Serial.begin(9600);
        Serial.println(__FILE__);
        Serial.println(__DATE__);
        Serial.println(" ");
    }
 
    //  open software serial connection to the Bluetooth module.
    BTserial.begin(9600); 
    if (DEBUG)  {   Serial.println(F("AltSoftSerial started at 9600"));     }
 
    newData = false;
 
} // void setup()
 
 
 
void loop()  
{
         recvWithStartEndMarkers();   
         //Serial.println(newData);// check to see if we have received any new commands
         if (newData)  {   processCommand();  }    // if we have a new command do something
}
 
 
void processCommand()
{
    //Serial.println(DEBUG);
    newData = false;
    if (DEBUG)  {   
      Serial.print("recieved data = ");  
      Serial.println(receivedChars);         }
 
    if (strcmp ("LEDON",receivedChars))  {
      digitalWrite(3,HIGH);   
      }
    else if (strcmp ("LEDOFF",receivedChars)) 
    { digitalWrite(3,LOW);    }
}
 
// function recvWithStartEndMarkers by Robin2 of the Arduino forums
// See  http://forum.arduino.cc/index.php?topic=288234.0
void recvWithStartEndMarkers() 
{
     static boolean recvInProgress = false;
     static byte ndx = 0;
     char startMarker = '<';
     char endMarker = '>';
 
     if (BTserial.available() > 0) 
     {
          char rc = BTserial.read();
          Serial.print(".avail");
          if (recvInProgress == true) 
          {
                Serial.print("endMark");
               if (rc != endMarker) 
               {
                    if (ndx < maxDataLength) { receivedChars[ndx] = rc; ndx++;  }
               }
               else 
               {
                     receivedChars[ndx] = '\0'; // terminate the string
                     recvInProgress = false;
                     ndx = 0;
                     newData = true;
               }
          }
          else if (rc == startMarker) { recvInProgress = true; }
     }
 
}
