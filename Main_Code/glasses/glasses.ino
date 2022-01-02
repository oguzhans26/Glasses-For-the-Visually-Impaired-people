//icnluding libraries and defining pins
#include <math.h>
#include <Wire.h>
#define echoPin 4
#define trigPin 5
#define buzzerPin 8
int ADXL345 = 0x53;
float X_out, Y_out, Z_out;

//setup code area
void setup() 
{
  //Serial.begin(9600); if somethings get wrong you can include these code
 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin,OUTPUT);
  Wire.begin();
  Wire.beginTransmission(ADXL345);
  Wire.write(0x2D);
  Wire.write(8);
  Wire.endTransmission();
  delay(10);

}
//main code area
void loop() {

  veri();
  unsigned int  uzaklik = abs(mesafe() * cos(abs(Z_out+-0.1) * M_PI /2));
  unsigned int zaman =map(uzaklik,0, 250,600,5000);

//if somethings get wrong you can include these codes
  /*
  Serial.print("uzaklik:\t:");
  Serial.println(uzaklik);
  Serial.print("mesafe:\t:");
  Serial.print(mesafe());
  Serial.println(" ");
  Serial.println(-Z_out+0.1);
  Serial.print("aci:\t:      ");
  Serial.println(Y_out * 90);
  Serial.print("mesafe:\t:      ");
  Serial.println(mesafe());
*/
 if(uzaklik<300)
 {
 tone(buzzerPin,zaman);
delay(50);
noTone(buzzerPin);
delay(50);}
else
{
  noTone(buzzerPin);
}
}
 //accelometer
void veri()
{
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32); // Start with register 0x32 (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
  X_out = ( Wire.read() | Wire.read() << 8); // X-axis value
  X_out = X_out / 256; // this proses is make data in -1 and +1 
  Y_out = ( Wire.read() | Wire.read() << 8); // Y-axis value
  Y_out = Y_out / 256;
  Z_out = ( Wire.read() | Wire.read() << 8); // Z-axis value
  Z_out = Z_out / 256;
}
// ultrasonic sensor
int mesafe()
{
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  delay(50);
  return distance;
}
