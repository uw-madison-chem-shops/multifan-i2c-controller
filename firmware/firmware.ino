
#include <Wire.h>

byte fan1 = 0;
byte fan2 = 0;
byte fan3 = 0;
byte fan4 = 0;
bool dirty = true;

int pin1 = 9;
int pin2 = 10;
int pin3 = 5;
int pin4 = 6;

void setup() {
  Wire.begin(0x08);  // join I2C bus as Slave with address 0x08

  // event handler initializations
  Wire.onReceive(dataRcv);   // register an event handler for received data

  // pinMode
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
}

void loop() {
  if (dirty) {
    analogWrite(pin1, setpoint2duty(fan1));
    analogWrite(pin2, setpoint2duty(fan1));
    analogWrite(pin3, setpoint2duty(fan1));
    analogWrite(pin4, setpoint2duty(fan1));
    dirty = false;
  }
}

int setpoint2duty(int setpoint) {
  // I accidentally wired it for 0 to 12 v
  // in reality I want 0 to 5
  float factor = 106.0 / 255.0;
  return 255 - (setpoint * factor);
}

//received data handler function
void dataRcv(int numBytes) {
  while (Wire.available()) {
    fan1 = Wire.read();
    fan2 = Wire.read();
    fan3 = Wire.read();
    fan4 = Wire.read();
    dirty = true;
  }
}
