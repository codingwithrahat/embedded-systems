int trigPin = 10;
int echoPin = 8;
int led = 13;
int buzzer = 12;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
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
  float distance = (0.0344 * time) / 2;

  Serial.println(distance);

  if(distance <= 100){
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
  }else{
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }
  
  delay(500);

}
