const int rightEcho = 5;
const int rightTrig = 4;
const int frontEcho = 6;
const int frontTrig = 7;
const int leftEcho = 9;
const int leftTrig = 8;

void setup() {
  Serial.begin(9600);
  pinMode(rightTrig, OUTPUT);
  pinMode(frontTrig, OUTPUT);
  pinMode(leftTrig, OUTPUT);
  pinMode(rightEcho, INPUT);
  pinMode(frontEcho, INPUT);
  pinMode(leftEcho, INPUT);
}

void loop() {
  digitalWrite(rightTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(rightTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(rightTrig, LOW);
  int right = pulseIn(rightEcho, HIGH);
  digitalWrite(frontTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(frontTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(frontTrig, LOW);
  int front = pulseIn(frontEcho, HIGH);
  digitalWrite(leftTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(leftTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(leftTrig, LOW);
  int left = pulseIn(leftEcho, HIGH);

  // distance in cm
  int distanceRight = right / 29 / 2;
  int distanceFront = front / 29 / 2;
  int distanceLeft = left / 29 / 2;

  Serial.print("Right distance: ");
  Serial.println(distanceRight);
  Serial.print("Front distance: ");
  Serial.println(distanceFront);
  Serial.print("Left distance: ");
  Serial.println(distanceLeft);
  Serial.println();
  delay(1000);
}
