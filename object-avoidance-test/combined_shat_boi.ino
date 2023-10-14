const int rightEcho = 5;
const int rightTrig = 4;
const int frontEcho = 6;
const int frontTrig = 7;
const int leftEcho = 9;
const int leftTrig = 8;
const int leftForward = 13;
const int leftBackward = 12;
const int rightForward = 11;
const int rightBackward = 10;

void setup() {
  Serial.begin(9600);
  pinMode(rightTrig, OUTPUT);
  pinMode(frontTrig, OUTPUT);
  pinMode(leftTrig, OUTPUT);
  pinMode(rightEcho, INPUT);
  pinMode(frontEcho, INPUT);
  pinMode(leftEcho, INPUT);
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);
}

int distanceRight() {
  digitalWrite(rightTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(rightTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(rightTrig, LOW);
  int right = pulseIn(rightEcho, HIGH);
  right = right / 29 / 2;
  return right;
}

int distanceFront() {
  digitalWrite(frontTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(frontTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(frontTrig, LOW);
  int front = pulseIn(frontEcho, HIGH);
  front = front / 29 / 2;
  return front;
}

int distanceLeft() {
  digitalWrite(leftTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(leftTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(leftTrig, LOW);
  int left = pulseIn(leftEcho, HIGH);
  left = left / 29 / 2;
  return left;
}

void moveForward() {
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightBackward, LOW);
}

void turnRight() {
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, LOW);
  delay(200);
}

void turnLeft() {
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightBackward, LOW);
  delay(200);
}

void loop() {
  // distance in cm
  moveForward();
  int right = distanceRight();
  int front = distanceFront();
  int left = distanceLeft();
  // delay(20);
  // Serial.println("Right distance: " + String(right));
  // Serial.println("Front distance: " + String(front));
  // Serial.println("Left distance: " + String(left));
  // Serial.println();
  if (front < 20) {
    if (left > 20) {
      turnLeft();
    } else if (left < 20 && right > 20) {
      turnRight();
    }
  }
  delay(1000);
}
