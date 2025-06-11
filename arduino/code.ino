#include <Servo.h>

// Define motor pins
const int motor1 = 26;  // Motor 1 connected to GPIO 4
const int motor2 = 27;  // Motor 2 connected to GPIO 5
const int motor3 = 7;  // Motor 3 connected to GPIO 6
const int motor4 = 6;  // Motor 4 connected to GPIO 7

// Define servo pin
const int servoPin = 16;  // Servo pin connected to GPIO 15

// Define ultrasonic sensor pins
const int trigPin = 10;  // Trig pin connected to GPIO 3
const int echoPin = 11;  // Echo pin connected to GPIO 2

// Define enable pins
const int ena = 17;  // Enable pin A connected to GPIO 10
const int enb = 15;  // Enable pin B connected to GPIO 11

// Create Servo object
Servo servo;

// Motor speed settings
const int speed = 128;  // Speed of the robot (0-255)

void setup() {
  // Initialize motor pins as outputs
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);

  // Initialize enable pins as outputs
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  // Initialize ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize servo motor
  servo.attach(servoPin);
  servo.write(90);  // Center the servo

  // Set PWM frequency for enable pins
  analogWriteFreq(1000);

  // Set maximum duty cycle for maximum speed
  analogWrite(ena, speed);
  analogWrite(enb, speed);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  setServo(90);
  delay(100);
  int distance = getDistance();
  Serial.println(distance);
  if (distance > 15) {
    delay(10);
    moveForward();
  } else {
    stop();
    setServo(0);
    delay(700);
    distance = getDistance();
    if (distance > 15) {
      delay(1000);
      turnRight();
      stop();
    } else {
      setServo(180);
      delay(700);
      distance = getDistance();
      if (distance > 15) {
        delay(1000);
        turnLeft();
        stop();
      } else {
        delay(100);
        moveBackward();
        turnRight();
        stop();
        turnRight();
        stop();
      }
    }
  }
}

// Functions for motor movements
void moveForward() {
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
}

void moveBackward() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  delay(500);
}

void turnLeft() {
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  delay(400);
}

void turnRight() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
  delay(400);
}
void stop() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
  delay(250);
}

// Function to get the distance from the ultrasonic sensor
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int cm = duration * 0.0343 / 2;  // Convert time to cm
  return cm;
}

// Function to set the servo angle
void setServo(int angle) {
  int dutyCycle = map(angle, 0, 180, 544, 2400);  // Map angle to duty cycle
  servo.writeMicroseconds(dutyCycle);
}
