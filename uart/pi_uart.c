/*
 * File: pi_uartt.c
 * Description: UART communication between Raspberry Pi and ESP8266
 * Note: Enable UART using raspi-config before running
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define UART_DEVICE "/dev/serial0"
#define BAUDRATE B115200

int main() {
    int uart_fd;
    struct termios options;

    uart_fd = open(UART_DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (uart_fd == -1) {
        perror("Failed to open UART");
        exit(EXIT_FAILURE);
    }

    printf("UART opened successfully.\n");

    tcgetattr(uart_fd, &options);
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_cflag &= ~CRTSCTS;

    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    options.c_oflag &= ~OPOST;

    tcsetattr(uart_fd, TCSANOW, &options);
    printf("UART configured at 115200 8N1.\n");

    char buffer[256];

    // Continuous UART receive loop (Ctrl+C to exit)
    while (1) {
        int bytes = read(uart_fd, buffer, sizeof(buffer) - 1);
        if (bytes > 0) {
            buffer[bytes] = '\0';
            printf("[ESP → Pi]: %s\n", buffer);
        }
        sleep(1);
    }

    close(uart_fd);
    return 0;
}
