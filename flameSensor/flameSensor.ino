int flamePin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(flamePin, INPUT);
}

void loop() {
  int val = digitalRead(flamePin);
  
  //active low
  if (val == LOW) {
    Serial.println("FIRE");
  } else {
    Serial.println("SAFE");
  }
  delay(500);
}