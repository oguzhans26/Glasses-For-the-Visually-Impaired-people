//pins are defined
#define echoPin 6
#define trigPin 7
void setup() {
  
  Serial.begin(9600); //serial is starting
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  
  long duration, distance; // some calculations is made
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2; // 1/58.2 is speed of sound
  delay(50);
  Serial.println(distance); //calculated distance is printed on serial
}
