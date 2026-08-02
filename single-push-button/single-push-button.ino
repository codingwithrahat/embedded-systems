int singlePush = 6;
int cnt = 0;

void setup() {

  pinMode(singlePush, INPUT);
  Serial.begin(9600);

}

void loop() {

  int m = digitalRead(singlePush);

	//active low  
  if(m == 0){
    delay(2000);
    cnt++;
    
  	Serial.println(cnt);
	}
}
