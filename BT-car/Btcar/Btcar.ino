const int motorASpeed = 5;
const int motorA1 = 2;
const int motorA2 = 3;
const int motorB1 = 4;
const int motorB2 = 7;
const int motorBSpeed = 6;

const int trigPin = 9;
const int echoPin = 8;
int duration, distance;

const int blink = 13;

int state;
int vSpeed = 255;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorASpeed, OUTPUT);
  pinMode(motorBSpeed, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(blink, OUTPUT);
  Serial.begin(9600);
}

void left() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void right() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);

  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void backward() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void forward() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void stopMotors() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}

int getDistance() {
  // digitalWrite(trigPin, LOW);
  // delayMicroseconds(2);
  // digitalWrite(trigPin, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(trigPin, LOW);
  // duration = pulseIn(echoPin, HIGH);
  // distance = (duration * 0.0343) / 2;
  // return distance;

  // digitalWrite(trigPin, LOW);
  // delayMicroseconds(2);
  // digitalWrite(trigPin, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(trigPin, LOW);

  // duration = pulseIn(echoPin, HIGH);
  // distance = (duration * .0343) / 2;
  // Serial.print("Distance: ");
  // Serial.println(distance);
  // delay(100);
  //return distanceCm;
}

void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();

    switch (state) {
      case '0': vSpeed = 0; break;
      case '5': vSpeed = 130; break;
      case '6': vSpeed = 160; break;
      case '7': vSpeed = 190; break;
      case '8': vSpeed = 210; break;
      case '9': vSpeed = 230; break;
      case 'q': vSpeed = 255; break;
    }

    analogWrite(motorASpeed, vSpeed);
    analogWrite(motorBSpeed, vSpeed);
  }

  if (state == 'W') {
    digitalWrite(13, HIGH);
  }
  if (state == 'w') {
    digitalWrite(13, LOW);
  }
  if (state == 'F') forward();
  if (state == 'B') backward();
  if (state == 'L') left();
  if (state == 'R') right();
  if (state == 'S') stopMotors();
}