#include <Servo.h>

// ---- Pin definitions ----
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;

// ---- Settings ----
const int distanceThreshold = 10;   // cm - move servo if object is within this distance
const int restAngle = 0;            // servo resting position
const int moveAngle = 90;           // servo position when object detected

Servo myServo;

long duration;
int distance;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(servoPin);
  myServo.write(restAngle);   // start at rest position
}

void loop() {
  distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= distanceThreshold) {
    // Object detected within threshold -> move servo
    myServo.write(moveAngle);
  } else {
    // No object nearby -> return to rest position
    myServo.write(restAngle);
  }

  delay(200); // small delay for stability
}

// Function to measure distance using HC-SR04
int getDistance() {
  // Clear trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send 10us pulse to trigger
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pin, return sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout (~5m range)

  // Calculate distance in cm (speed of sound = 0.034 cm/us)
  int calculatedDistance = duration * 0.034 / 2;

  return calculatedDistance;
}
