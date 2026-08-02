int motionPin = 13;
int buzzer = 12;


void setup(){
  pinMode(motionPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop(){

  int f = digitalRead(motionPin);

  Serial.println(f);

  if(f == HIGH){
    digitalWrite(buzzer, HIGH);
  }else{
    digitalWrite(buzzer, LOW);
  }
}