#include <avr/wdt.h>

void setup() 
{ 
  
   // Output to relay
   pinMode(2, OUTPUT); 
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   
   // Output to LEDs
   pinMode(6, OUTPUT); // Blue 2
   pinMode(7, OUTPUT); // Blue 3
   pinMode(8, OUTPUT); // Blue 4
   pinMode(9, OUTPUT); // Blue 5
   pinMode(10, OUTPUT); // Red 2
   pinMode(11, OUTPUT); // Red 3
   pinMode(12, OUTPUT); // Red 4
   pinMode(13, OUTPUT); // Red 5
   
   // Set the relays to turn them off 
   for (int thisPin = 2; thisPin <= 5; thisPin++) {
     digitalWrite(thisPin, HIGH);
   }
   
   // Set the blue LEDs to LOW to turn them on (remember a resistor for each)
   for (int thisPin = 6; thisPin <= 9; thisPin++) {
     digitalWrite(thisPin, LOW);
   }
   
   // Set the red LEDs to HIGH to turn them off (remember a resistor for each)
   for (int thisPin = 10; thisPin <= 13; thisPin++) {
     digitalWrite(thisPin, HIGH);
   }
   
   // Input from sensors
   pinMode(A2, INPUT);
   pinMode(A3, INPUT);
   pinMode(A4, INPUT);
   pinMode(A5, INPUT);
   
   Serial.begin(9600);
   wdt_enable(WDTO_8S); // Enable the watchdog timer, 8 seconds
} 

void loop()
{
  wdt_reset(); // Tell the watchdog we're ok...
  for (int thisPin = 2; thisPin <= 5; thisPin++) {
    Serial.println(thisPin);
    if(digitalRead(thisPin + 14) == LOW) {
      // Sensor is active, do something...
      // First wait a moment, and see if it's still active
      delay(250);
      if(digitalRead(thisPin + 14) == LOW) {
        // Sensor is still active, must be intentional
        
        if(digitalRead(thisPin) == HIGH) {
          // Relay associated with the sensor is high (off) so change it...
          digitalWrite(thisPin, LOW);
          digitalWrite(thisPin+4, HIGH);  // Blue off
          digitalWrite(thisPin+8, LOW);   // Red on
        } else {
          digitalWrite(thisPin, HIGH);    // Relay off
          digitalWrite(thisPin+4, LOW);   // Blue on
          digitalWrite(thisPin+8, HIGH);  // Red off
        } 
        
        // After the change, add another delay so we don't do too much...
        delay(500);
        if(digitalRead(thisPin + 14) == LOW) {
          // User still has hand over sensor, so continue to wait...
          delay(500);
        }
        if(digitalRead(thisPin + 14) == LOW) {
          // User still has hand over sensor, so continue to wait...
          delay(500);
        }
        if(digitalRead(thisPin + 14) == LOW) {
          // User still has hand over sensor, so continue to wait...
          delay(500);
        }
        if(digitalRead(thisPin + 14) == LOW) {
          // User still has hand over sensor, so continue to wait...
          delay(500);
        }
        if(digitalRead(thisPin + 14) == LOW) {
          // User still has hand over sensor, so continue to wait...
          delay(500);
        }
      }
    }
  }
}
