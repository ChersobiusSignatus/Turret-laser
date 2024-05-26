#define PIN_LED 12
#define PIN_PHOTO_SENSOR A0
int number = 1;

void setup()
{
  Serial.begin(9600); 
  Serial.println("Let's play!"); 
  pinMode(PIN_LED, OUTPUT); 
}

void loop()
{
  int lightLevel = analogRead(PIN_PHOTO_SENSOR);

  if (lightLevel < 500) { 
    digitalWrite(PIN_LED, HIGH);
    Serial.print("Hit!   ");
    Serial.print(number);
    Serial.print("   times");
    Serial.println(" ");
        number += 1;
    delay(1000);
    digitalWrite(PIN_LED, LOW);
    delay(3000);
  }
  else
  {
    digitalWrite(PIN_LED, LOW);
  }
}
