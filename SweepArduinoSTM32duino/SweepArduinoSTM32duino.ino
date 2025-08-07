#include <Servo.h>

Servo myservo;
int pos = 0;

void setup() {
  myservo.attach(PA0);       // Servo connected to PA1
  pinMode(PC13, OUTPUT);     // LED connected to PC13 (on-board LED for Blue Pill)
}

void loop() {
  while (1){
 // Sweep from 0° to 180°
  for (pos = 0; pos <= 180; pos++) {
    myservo.write(pos);
    delay(15);
   
  }

  // Sweep from 180° to 0°
  for (pos = 180; pos >= 0; pos--) {
    myservo.write(pos);
    delay(15);
  }

  // Blink LED on PC13 once
  digitalWrite(PC13, LOW);   // Turn on LED (active low on Blue Pill)
  delay(500);
  digitalWrite(PC13, HIGH);  // Turn off LED
  delay(500);
  }
 

  // Stop the loop
   // Infinite loop to stop further execution
}
