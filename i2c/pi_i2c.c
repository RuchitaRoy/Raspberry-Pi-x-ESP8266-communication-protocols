/*
 * File: pi_i2c.c
 * Description: Raspberry Pi acting as I2C slave
 * ESP8266 acts as I2C master
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define SLAVE_ADDR 0x08

int main() {
    int file;
    char buffer[32];
    char *i2c_bus = "/dev/i2c-1"; // Custom I2C bus via overlay

    printf("Starting Raspberry Pi I2C Slave...\n");

    file = open(i2c_bus, O_RDWR);
    if (file < 0) {
        perror("Failed to open I2C bus");
        return 1;
    }

    ioctl(file, I2C_SLAVE, SLAVE_ADDR);

    while (1) {
        int len = read(file, buffer, sizeof(buffer));
        if (len > 0) {
            buffer[len] = '\0';
            printf("Received from ESP8266: %s\n", buffer);
        }

        char ack[] = "ACK_FROM_PI";
        write(file, ack, sizeof(ack));
        usleep(100000);
    }

    close(file);
    return 0;
}
