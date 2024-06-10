#include <Wire.h>

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 0;

void loop()
{
  Wire.beginTransmission(0x08);
  Wire.write(0xFF);
  Wire.write(0x00);
  Wire.write(0x00);
  Wire.write(0x00);
  Wire.endTransmission();
  delay(1000);

  Wire.beginTransmission(0x08);
  Wire.write(0x00);
  Wire.write(0xFF);
  Wire.write(0x00);
  Wire.write(0x00);
  Wire.endTransmission();
  delay(1000);

  Wire.beginTransmission(0x08);
  Wire.write(0x00);
  Wire.write(0x00);
  Wire.write(0xFF);
  Wire.write(0x00);
  Wire.endTransmission();
  delay(1000);

  Wire.beginTransmission(0x08);
  Wire.write(0x00);
  Wire.write(0x00);
  Wire.write(0x00);
  Wire.write(0xFF);
  Wire.endTransmission();
  delay(1000);
}