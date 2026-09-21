int led = 3;

void setup(){
  pinMode(led, OUTPUT);
}

void loop(){
  for(int i = 0; i<256; i++){
    analogWrite(led, i);
    delay(10);
  }

  delay(20000);

  for(int i = 255; i>=0; i--){
    analogWrite(led, i);
    delay(10);
  }
}