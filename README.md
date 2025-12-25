# Raspberry-Pi-x-ESP8266-communication-protocols
This project demonstrates practical communication between a Raspberry Pi and an ESP8266 (NodeMCU) using UDP, UART, and I2C protocols.  It includes embedded C code for the Raspberry Pi (Linux) and Arduino IDE code for ESP8266.

## Features
- **UDP Socket Communication**
  - Raspberry Pi acts as server  
  - Multiple clients (optional for expansion)  

- **UART Communication**  
  - Raspberry Pi ↔ ESP8266  
  - Baudrate: 115200, 8N1  
  - Bidirectional messaging  

- **I2C Communication**  
  - Raspberry Pi configured as I2C slave  
  - ESP8266 as I2C master  
  - Demonstrates data transfer and acknowledgement  

----------------------------------------------------------------------------------------------------------------------------------------------------------------

## Hardware Requirements
- Raspberry Pi (any model with GPIO)  
- NodeMCU (ESP8266)  
- Jumper wires  
- Optional: Pmod sensors (for later projects)  

----------------------------------------------------------------------------------------------------------------------------------------------------------------

## Raspberry Pi Pin Configuration

**UART**
| Raspberry Pi | ESP8266 |
|--------------|---------|
| GPIO14 (TXD) | RX      |
| GPIO15 (RXD) | TX      |
| GND          | GND     |

**I2C**
| Raspberry Pi | ESP8266 |
|--------------|---------|
| GPIO2 (SDA)  | D2      |
| GPIO3 (SCL)  | D1      |
| GND          | GND     |

----------------------------------------------------------------------------------------------------------------------------------------------------------------

## Software Setup

### Raspberry Pi
1. Enable **I2C** and **UART** using `sudo raspi-config`  
2. Compile and run:
```bash
gcc UdpServer.c -o udp_server
./udp_server

gcc UdpClient.c -o udp_client
./udp_client

gcc pi_uartt.c -o uart_test
./uart_test

gcc pi_i2c.c -o i2c_slave
./i2c_slave

Note: ESP8266 (NodeMCU) was used as a communication endpoint with Raspberry Pi
using both UART and I2C protocols. UART was configured at 115200 baud
for serial data exchange. ESP8266 acted as I2C master while Raspberry Pi
was configured as slave. Successful bidirectional data transfer was observed.
