#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 1023

int main(int argc, char **argv)
{

  /* check port number is passind in on command line */
  if (argc != 2)
  {
    printf("Usage: %s <port>\n", argv[0]);
    return 1;
  }

  int socket_fd;
  struct sockaddr_in server_addr, client_addr;
  char buffer[BUFFER_SIZE];
  socklen_t addr_size;
  char *IP = "127.0.0.1";
  char *CLOSE_CONNECTION_MESSAGE = "Closing connection to the server.\n";
  char *DATA_RECEIVED_SUCCESS_MESSAGE = "Server: Message received successfully\n";

  /* Create a UDP Socket */
  socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
  if (socket_fd < 0)
  {
    perror("[-]socket error");
    return 1;
  }

  /* Initialise the sockaddr_in structure
   * use memset to zero the struct out */
  memset(&server_addr, '\0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[1])); // The htons function is a network byte order conversion function in C. It stands for "host to network short."
  server_addr.sin_addr.s_addr = inet_addr(IP);

  /* bind server address to socket descriptor */
  if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
  {
    perror("[-] bind error");
    return 1;
  }
  bool is_continuing = true;
  while (is_continuing)
  {

    /* clear buffer */
    bzero(buffer, BUFFER_SIZE);
    /* Calculating the Client Datagram length */
    addr_size = sizeof(client_addr);
    /* use recvfrom to receive data from client */
    int messageSize = recvfrom(socket_fd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &addr_size);
    buffer[messageSize] = '\0';

    /* check end connection message sent. strncasecmp() function performs a byte-by-byte comparison of
       the strings s1 and s2, ignoring the case of the characters */
    if (strncasecmp(buffer, "q", 1) == 0)
    {
      printf("\nShutdown sent - closing sockets\n");
      is_continuing = false;
    }

    /* Output the message from the client */
    printf("[+] Data recv: %s\n", buffer);

    /* Clear the buffer and send a message from the server to the client */
    bzero(buffer, BUFFER_SIZE);

    if (is_continuing)
    {
      strcpy(buffer, DATA_RECEIVED_SUCCESS_MESSAGE);
    }
    else
    {
      strcpy(buffer, CLOSE_CONNECTION_MESSAGE);
      printf("\nTermination message sent from client\nClosing socket\n");
    }

    sendto(socket_fd, buffer, 1024, 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
    
    printf("[+] Data send: %s\n", buffer);
  }

  // Closing the Socket File Descriptor.
  close(socket_fd);

  return 0;
}
