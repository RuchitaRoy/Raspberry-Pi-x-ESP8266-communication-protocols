/*
 * File: esp_i2c_master.ino
 * Description: ESP8266 I2C Master communicating with Raspberry Pi
 */

#include <Wire.h>

#define SLAVE_ADDR 0x08

void setup() {
  Wire.begin(D2, D1);  // SDA, SCL
  Serial.begin(115200);
  delay(1000);
  Serial.println("ESP8266 I2C Master Started");
}

void loop() {
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write("Hello Pi via I2C");
  Wire.endTransmission();

  delay(100);

  Wire.requestFrom(SLAVE_ADDR, 16);
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println();

  delay(2000);
}
