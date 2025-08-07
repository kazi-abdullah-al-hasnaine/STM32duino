#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Servo myservo;

int pos = 0;

void setup() {
  myservo.attach(PA0);        // Servo signal pin
  Wire.begin();               // I2C begin

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // I2C address usually 0x3C
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  

  while (1){
for (pos = 0; pos <= 180; pos += 10) {
    myservo.write(pos);
    showAngle(pos);
    delay(500);
  }

  for (pos = 180; pos >= 0; pos -= 10) {
    myservo.write(pos);
    showAngle(pos);
    delay(500);
  }
  }  // halt after one sweep
}

void showAngle(int angle) {
  display.clearDisplay();
  display.setCursor(0, 20);
  display.print("Angle: ");
  display.print(angle);
  display.print(" deg");
  display.display();
}
