void setup() {
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(A0);
  long mv = map(raw, 0, 1023, 0, 5000);   // 0-1023 ke 0-5000 mV te map
  float voltage = mv / 1000.0;

  Serial.print("Voltage: ");
  Serial.print(voltage, 2);
  Serial.println(" V");
  delay(500);
}