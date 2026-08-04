int trigPin = 13;
int echoPin = 12;

int led = 2;
int led2 = 3;
int led3 = 4;

int push = 10;
int buzzer = 8;

bool washing = false;
bool carDetected = false;
bool buttonPressed = false;

int lastState = LOW;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(push, INPUT);

  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long time = pulseIn(echoPin, HIGH, 30000);
  float distance = (time * 0.0344) / 2;

  if (distance >= 50 && distance <= 150) {

    if (!carDetected) {
      Serial.println("Car Detected");
      carDetected = true;
    }

    digitalWrite(led, HIGH);

    int currentState = digitalRead(push);

    if (currentState == HIGH && lastState == LOW) {

      washing = !washing;
      buttonPressed = true;

      if (washing) {
        Serial.println("Washing Started");
      } else {
        Serial.println("Washing Stopped");
      }

      delay(200);
    }

    lastState = currentState;

    if (!buttonPressed) {
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }
    else if (washing) {
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
    }
    else {
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
    }

  } 
  else {

    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

    washing = false;
    buttonPressed = false;
    lastState = LOW;

    if (carDetected) {

      Serial.println("Car Left");

      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);

      carDetected = false;
    }
  }

  delay(100);
}