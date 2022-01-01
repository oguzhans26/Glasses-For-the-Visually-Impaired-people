//icnluding libraries and defining pins
#include <math.h>
#include <Wire.h>
int ADXL345 = 0x53;
float X_out, Y_out, Z_out;
//setup code area
void setup() 
{
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(ADXL345);
  Wire.write(0x2D);
  Wire.write(8);
  Wire.endTransmission();
  delay(10);
}
//main code area
void loop() {
  //accelerometer calculations
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32); // Start with register 0x32 (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
  X_out = ( Wire.read() | Wire.read() << 8); // X-axis value
  X_out = X_out / 256; //For a range of +-2g, we need to divide the raw values by 256, according to the datasheet
  Y_out = ( Wire.read() | Wire.read() << 8); // Y-axis value
  Y_out = Y_out / 256;
  Z_out = ( Wire.read() | Wire.read() << 8); // Z-axis value
  Z_out = Z_out / 256;
  

  //print values of sensor
  Serial.print("X axis");
  Serial.println(X_out);
  Serial.print("Y axis");
  Serial.println(Y_out);
  Serial.print("Z axis");
  Serial.println(Z_out);
}
