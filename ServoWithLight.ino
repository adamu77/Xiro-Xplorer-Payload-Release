#include <Servo.h>

Servo myservo;
const int analogInPin = A0;

int sensorValue = 0;
int Timer = 0;

void setup() 
{
  myservo.attach(12);
  Serial.begin(9600);
  myservo.writeMicroseconds(1000);
  delay(5000);
}

void loop() {

sensorValue = analogRead(analogInPin);

  if (sensorValue > 200) {
    Serial.println("On");
    myservo.writeMicroseconds(1000);
    Timer = 0;
    }

  else if (sensorValue <= 200 && Timer < 6) {
    Serial.println("Going");
    Timer++;
    delay(200);
    }
    
else {
  
Serial.println("Off");
myservo.writeMicroseconds(1600);
  }

  Serial.println(sensorValue);
  delay(200);
}

