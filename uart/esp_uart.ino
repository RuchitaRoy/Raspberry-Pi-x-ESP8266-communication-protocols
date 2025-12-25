/*
 * File: esp_uart.ino
 * Description: ESP8266 UART communication with Raspberry Pi
 * Baudrate: 115200
 */

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Hello from ESP8266 via UART");
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    Serial.print("ESP received: ");
    Serial.println(data);
  }
  delay(1000);
}
