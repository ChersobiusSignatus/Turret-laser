#include <Servo.h> 

Servo servo1; 
Servo servo2;

int joyX = A1; 
int joyY = A0;

int joyValX, joyValY;

const int servoSpeed = 1; 
const int deadZone = 10; 

static int lastJoyValX = 90; 
static int lastJoyValY = 90; 

int laserPin = 7;
int buttonPin = 2;

void setup() {
  servo1.attach(3); 
  servo2.attach(4);

  pinMode(laserPin, OUTPUT); 
  pinMode(buttonPin, INPUT_PULLUP); 
}

void loop() {
  joyValX = analogRead(joyX); 
  joyValX = map(joyValX, 0, 1023, 0, 180); 

  joyValY = analogRead(joyY); 
  joyValY = map(joyValY, 0, 1023, 0, 180);

  // Adjust servo movement with dead zone
  if (abs(joyValX - lastJoyValX) > deadZone) {
    if (joyValX > lastJoyValX) {
      lastJoyValX += servoSpeed; 
      if (lastJoyValX > joyValX) lastJoyValX = joyValX;
    } else {
      lastJoyValX -= servoSpeed; 
      if (lastJoyValX < joyValX) lastJoyValX = joyValX;
    }
    servo1.write(lastJoyValX);
    delay(50); 
  }

  if (abs(joyValY - lastJoyValY) > deadZone) {
    if (joyValY > lastJoyValY) {
      lastJoyValY += servoSpeed; 
      if (lastJoyValY > joyValY) lastJoyValY = joyValY;
    } else {
      lastJoyValY -= servoSpeed; 
      if (lastJoyValY < joyValY) lastJoyValY = joyValY;
    }
    servo2.write(lastJoyValY);
    delay(50j); 
  }

  if (digitalRead(buttonPin) == LOW) {
    digitalWrite(laserPin, HIGH); 
  } else {
    digitalWrite(laserPin, LOW); 
  }
}
