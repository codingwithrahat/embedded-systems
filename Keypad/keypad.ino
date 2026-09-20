#include<Keypad.h>

const byte rows = 4;
const byte colum = 4;

char keys[rows][colum] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowpins[rows] = {13, 12, 11, 10};
byte columpins[colum] = {9, 8, 7, 6};

Keypad keypad = Keypad(makeKeymap(keys), rowpins, columpins, rows, colum); 

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char key = keypad.getKey();

  if(key){
    Serial.println(key);
  }
}