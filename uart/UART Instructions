## Connections

| Raspberry Pi | ESP8266 |
|-------------|---------|
| GPIO14 (TXD) | RX |
| GPIO15 (RXD) | TX |
| GND | GND |

---

## Steps
1. Enable UART on the Raspberry Pi (`raspi-config`).
a) 
![enablept1](images/interfacing_options)
b)
![enablept2](images/enable_uart_pt1)
c)
![enablept3](images/enable_uart_pt2)
d)
![enablept4](images/enable_uart_pt3)
e)
![enablept5](images/enable_uart_pt4)

3. Connect the pins as shown above.
4. Upload `esp_uart.ino` to the ESP8266.
5. Compile and run on Raspberry Pi:
   ```bash
   gcc pi_uart.c -o uart_test
   ./uart_test
