#include <SoftwareSerial.h>

SoftwareSerial BTserial(8,9); 
 
// Change DEBUG to true to output debug information to the serial monitor
boolean DEBUG = true;
 
void setup()  
{
    if (DEBUG)
    {
        // open serial communication for debugging and show 
        // the sketch filename and the date compiled
        Serial.begin(9600);
        Serial.println(__FILE__);
        Serial.println(__DATE__);
        Serial.println(" ");
    }
 
    //  open software serial connection to the Bluetooth module.
    BTserial.begin(9600); 
    if (DEBUG)  {   Serial.println("BTserial started at 9600");     }
 
} // void setup()
 
 
void loop()  
{
    BTserial.write("<LEDON>");
    if (DEBUG) {Serial.println("LEDON command sent");}    
    delay (1000);
 
    BTserial.write("<LEDOFF>");
    if (DEBUG) {Serial.println("LEDOFF command sent");}      
    delay (1000);    
}
