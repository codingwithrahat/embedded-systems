int motorPin1 = 9;
int motorPin2 = 10;
int enablePin = 11;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  
  digitalWrite(enablePin, HIGH); //always enable
}

void loop() {
  
   // forward
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(3000);

  // stop 
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  delay(3000);
  
  //backward
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(3000);
  
  // stop 
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  delay(3000);

}