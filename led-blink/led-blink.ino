int pin = 13;
int pin2 = 12;

void setup()
{
    pinMode(pin, OUTPUT);
    pinMode(pin2, OUTPUT);
}

void loop()
{
    digitalWrite(pin, HIGH);
    delay(100);

    digitalWrite(pin, LOW);
    delay(100);

    digitalWrite(pin2, HIGH);
    delay(100);

    digitalWrite(pin2, LOW);
    delay(100);
}