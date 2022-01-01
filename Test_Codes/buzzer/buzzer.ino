#define buzzerPin 10

void setup()
{
  pinMode(buzzerPin,OUTPUT);
}
void loop()
{
tone(buzzerPin,2000);
delay(100);
noTone(buzzerPin);
delay(100);
}
