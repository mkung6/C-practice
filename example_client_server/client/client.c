#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8080

int main() {
    int clientSocket, valread;
    struct sockaddr_in serverAddr;
    char buffer[1024] = {0};

    char *test = "Test Message";

    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      printf("\nSocket creation error\n");
      return -1;
    }

    memset(&serverAddr, '0', sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0) {
      printf("\nInvalid address / Address not supported\n");
      return -1;
    }

    if (connect(clientSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
      printf("\nConnection Failed \n");
      return -1;
    }
    send(clientSocket, test, strlen(test), 0);
    printf("Test message sent\n");

    valread = read(clientSocket, buffer, 1024);

    int n;
    while ((n = read(clientSocket, buffer, 1024)) > 0) {
      buffer[n] = '\0';
    }
    printf("read: %s\n", buffer);
    getchar();
    close(clientSocket);
    return 0;
}
