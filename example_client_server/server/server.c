#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <semaphore.h>

#define PORT 8080

void * socketHandler(void *arg);

void * socketHandler(void *arg) {
  int newSocket = *((int*)arg);
  char client_message[2000];
  char buffer[1024];
  int read_size;

  recv(newSocket, client_message, 2000, 0);
  send(newSocket, client_message, strlen(client_message), 0);

  close(newSocket);
  pthread_exit(NULL);
}

int main()
{
    int serverSock, newSocket;
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;
    int i;

    if ((serverSock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
      perror("socket failed");
      exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    if (bind(serverSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr))<0) {
      perror("bind failed");
      exit(EXIT_FAILURE);
    }

    if (listen(serverSock, 50) == 0) {
      printf("Listening...\n");
    } else {
      printf("Error listening\n");
      exit(EXIT_FAILURE);
    }

    pthread_t thread_id[60];
    i = 0;
    while (1) {
      addr_size = sizeof(serverStorage);
      newSocket = accept(serverSock, (struct sockaddr*)&serverStorage, &addr_size);

      if (pthread_create(&thread_id[i], NULL, socketHandler, &newSocket) != 0) {
        printf("Failed to create thread\n");
      }

      if (i >= 50) {
        i = 0;
        while (i < 50) {

          pthread_join(thread_id[i++], NULL);
        }
        i = 0;
      }
      close(serverSock);
      return 0;
    }


}
