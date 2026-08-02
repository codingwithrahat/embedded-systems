int irPin = 13;

void setup(){
  pinMode(irPin, INPUT);
  Serial.begin(9600);
}

void loop(){

  int s = digitalRead(irPin);

  if(s == 1){
    Serial.print(s);
    Serial.println(" - Objcet ditected (without black)");   
  }else{
    Serial.print(s);
    Serial.println(" - No object or black object");
  }

  delay(2000);

}