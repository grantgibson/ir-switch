// Store current switch status 
int myOn[6];

// Store last sensor value
int myLock[6];

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
   
   // Set the relays to LOW to turn them off 
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
} 
void loop()
{
  for (int thisPin = 2; thisPin <= 5; thisPin++) {
    if(digitalRead(thisPin + 14) == LOW) {
      // Sensor is active, do something...
      if(myLock[thisPin] == 0) {
        // First time, action is unlocked so do it...
        if(myOn[thisPin]) {
          // Currently on, so turn off relay
          digitalWrite(thisPin, HIGH);
          // Turn off red LED, turn on blue
          digitalWrite(thisPin+8, HIGH);
          digitalWrite(thisPin+4, LOW);
          // Store that this pin is off
          myOn[thisPin] = 0;
        } else {
          // Currently off, so turn on relay
          digitalWrite(thisPin, LOW);
          // Turn off blue LED, turn on red
          digitalWrite(thisPin+8, LOW);
          digitalWrite(thisPin+4, HIGH);
          // Store that this pin is on
          myOn[thisPin] = 1;
        }
        // Set the lock
        myLock[thisPin] = 1;
        delay(250);
      }
    } else {
      // When the sensor is inactive again, unset the lock
      myLock[thisPin] = 0;
    }
  }

}
