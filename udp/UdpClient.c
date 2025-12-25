/*
 * File: UdpClient.c
 * Description: UDP client implementation on Linux (Raspberry Pi)
 * Protocol: UDP (IPv4)
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT    8080
#define MAXLINE 1024

int main() {
    int sockfd;
    char buffer[MAXLINE];
    char *hello = "Hello from client";
    struct sockaddr_in servaddr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    socklen_t len;

    sendto(sockfd, hello, strlen(hello), MSG_CONFIRM,
           (struct sockaddr *)&servaddr, sizeof(servaddr));

    printf("Message sent to server.\n");

    int n = recvfrom(sockfd, buffer, MAXLINE, MSG_WAITALL,
                     (struct sockaddr *)&servaddr, &len);

    buffer[n] = '\0';
    printf("Server says: %s\n", buffer);

    close(sockfd);
    return 0;
}
