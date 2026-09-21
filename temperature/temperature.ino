int tempPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(tempPin);

  int temp = map(value, 20, 358, -40, 125);

  Serial.println(temp);

  delay(1000);
}