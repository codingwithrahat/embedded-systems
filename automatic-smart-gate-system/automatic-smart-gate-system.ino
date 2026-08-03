#include<Servo.h>

int trigPin = 11;
int echoPin = 12;
int t2 = 10;
int e2 = 9;

Servo servo;
Servo servo2;

int cnt = 0;
bool flag = false;

void setup(){
  servo.attach(6);
  servo2.attach(5);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(t2, OUTPUT);
  pinMode(e2, INPUT);

  Serial.begin(9600);
}

void loop(){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  double time = pulseIn(echoPin, HIGH, 30000);

  double dis = (time * 0.0344) / 2;

  digitalWrite(t2, LOW);
  delayMicroseconds(2);

  digitalWrite(t2, HIGH);
  delayMicroseconds(10);

  digitalWrite(t2, LOW);

  double time2 = pulseIn(e2, HIGH, 30000);

  double dis2 = (time2 * 0.0344) / 2;

	
  if(dis < 200){
    Serial.println("Gate Open");
    
    servo.write(0);
    servo2.write(0);

    delay(1000);
    
    if(dis2 <= 100 && flag == false){
    	cnt++;
      	flag = true;
      
    	Serial.print("Person Entered. Total = ");
    	Serial.println(cnt);
    }
    
  }else{
   	Serial.println("Gate Close"); 
    
    delay(1000);
  
  	servo.write(90);
  	servo2.write(90);
  }
  if(dis2 > 100){
     flag = false; 
  }
      
   delay(100);


}