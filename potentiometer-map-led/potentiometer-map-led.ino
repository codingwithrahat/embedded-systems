int led = 3;
int potPin = A0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  int val = analogRead(potPin);

  int mapVal = map(val, 0, 1023, 0, 255);

  Serial.println(mapVal);

  analogWrite(led, mapVal);

}
