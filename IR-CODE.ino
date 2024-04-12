// Define motor pins
#define motor1Pin1 10  // Motor 1 direction pin 1
#define motor1Pin2 11  // Motor 1 direction pin 2
#define motor2Pin1 12  // Motor 2 direction pin 1
#define motor2Pin2 13  // Motor 2 direction pin 2

// Define IR sensor pins
#define leftSensor A0   // Left IR sensor connected to analog pin A0
#define rightSensor A1  // Right IR sensor connected to analog pin A1


// Setup function runs once when the program starts
void setup() {
  // Set motor control pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
}

// Loop function runs repeatedly as long as the Arduino is powered
void loop() {
  // Read sensor values
  int leftValue = analogRead(leftSensor);
  int rightValue = analogRead(rightSensor);
  
  // If both sensors detect black, move forward
  if (leftValue < 500 && rightValue < 500) {
    moveForward();
  }
  // If left sensor detects black, turn right
  else if (leftValue < 500 && rightValue >= 500) {
    turnRight();
  }
  // If right sensor detects black, turn left
  else if (leftValue >= 500 && rightValue < 500) {
    turnLeft();
  }
  // If both sensors detect white, stop
  else {
    stopMoving();
  }
}

// Function to move the robot forward
void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

// Function to turn the robot left
void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

// Function to turn the robot right
void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

// Function to stop the robot
void stopMoving() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
