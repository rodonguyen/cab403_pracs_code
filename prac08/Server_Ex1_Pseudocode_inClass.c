#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1023

int main(int argc, char **argv)
{

  /* client file descriptor */
  int clientfd;
  /* receive buffer */
  char buffer[BUFFER_SIZE];

  struct sockaddr clientaddr;
  socklen_t addrlen;

  /* Check user has passed in the port number at the command line
   * local host will be used as the default address
   */
  if (argc != 2)
  {
    printf("\nCorrect usage: a.out <port number>\n");
    return -1;
  }

  /* Create a TCP/IP socket making sure to select appropriate family, communication type &
   * protocol
   */
  int fd = socket(AF_INET, SOCK_STREAM, 0); // File Descriptor for the socket
  if (fd == -1)
  {
    perror("\nError: socket()\n"); // TODO: try to simulate an error case
    return 1;
  }

  /* Declare a data structure to specify the socket address (IP Address + Port)
   * Complete the Internet socket address structure
   * An IPv4 socket address structure - use memset to zero the struct out
   */
  struct sockaddr_in server_address;                     // https://man7.org
  memset(&server_address, '\0', sizeof(server_address)); // zero out the struct to avoid garbage values
  server_address.sin_port = htons(atoi(argv[1]));        // port number
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);    // IP address
  server_address.sin_family = AF_INET;                   // address family

  // TODO: close the socket/server used in this server_address if there's any
  // if (close(fd) == -1)
  // {
  //   perror("Error: close()");
  //   return 1;
  // }

  /* Assign a name to the socket created - Implement bind() system call */
  if (bind(fd, (struct sockaddr *)&server_address, sizeof(server_address)))
  {
    perror("Error: bind()");
    return 1;
  }

  /* Place server in passive mode - listen for incomming client request  */
  if (listen(fd, 10) == -1)
  {
    perror("Error: listen()");
    return 1;
  }

  /* infinite loop */
  while (1)
  {

    /*  Generate a new socket for data transfer with the client. 
    clientfd will wait for new connection from the client side. Once connected, clientaddr will be set to  the client's address, addrlen is the length of clientaddr */
    clientfd = accept(fd, &clientaddr, &addrlen);

    /* receive the incomming client data */
    int bytes_received = recv(clientfd, buffer, 1023, 0);  // Tutor: setting flag to 0 means that you want to receive the data in its default behavior without any special options. 

    /* add null terminator to received data and print out message, avoiding wasting computation to go above the received data and print empty in the buffer */
    buffer[bytes_received] = '\0';
    printf("> Number of Bytes received: %d. Data: %s\n", bytes_received, buffer);

    /* close the socket used to receive data */
    close(clientfd);
  }

  /* shutdown the connection - end communication to and from the socket SHUT_RDWR */
  if (shutdown(clientfd, SHUT_RDWR) == -1)
  {
    perror("Error: shutdown()");
    return 1;
  }

  /* sockets can remain open after program termination - close listening socket*/
  if (close(fd) == -1)
  {
    perror("Error: close()");
    return 1;
  }

  // TODO: find a way to close the server gracefully. Currently, ctrl + C doesn't allow the close() and shutdown() to run
  printf("Server closed successfully\n");
  return 0;
}
