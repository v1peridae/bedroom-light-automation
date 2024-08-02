#include <Servo.h>

const int trigPin = 9;
const int echoPin = 8;

const int servoPin = 6;

Servo myServo;

long duration;
int distance;

const int thresholdDistance = 30;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(servoPin);

  myServo.write(0); 
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < thresholdDistance) {
    myServo.write(0);  
  }
  else {
    myServo.write(90);
  }

  delay(100);
}
