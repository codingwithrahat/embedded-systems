int potPin = A0;

void setup() {
  pinMode(potPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  int val = analogRead(potPin);

  float convVoltage = val * (5.0 / 1023.0);

  Serial.println(convVoltage);


}
