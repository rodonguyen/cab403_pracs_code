#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

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
    printf("\nCorrect usage: ./program <port number>\n");
    return EXIT_FAILURE;
  }

  /* Create a TCP/IP socket making sure to select appropriate family, communication type &
   * protocol */
  int fd = socket(AF_INET, SOCK_STREAM, 0); // File Descriptor for the socket
  if (fd == -1)
  {
    perror("\nError: socket()\n"); // TODO: try to simulate an error case
    return EXIT_FAILURE;
  }

  /* Declare a data structure to specify the socket address (IP Address + Port)
   * Complete the Internet socket address structure
   * An IPv4 socket address structure - use memset to zero the struct out
   */
  struct sockaddr_in server_address;
  server_address.sin_port = htons(atoi(argv[1]));
  server_address.sin_addr.s_addr = htonl(INADDR_ANY); // 127.0.0.1
  server_address.sin_family = AF_INET;                // address family / domain

  /* Assign a name to the socket created - Implement bind() system call */
  if (bind(fd, (struct sockaddr *)&server_address, sizeof(server_address)))
  {
    perror("Error: bind()");
    return EXIT_FAILURE;
  }

  /* Place server in passive mode - listen for incomming client request  */
  int result = listen(fd, 10);
  if (result == -1)
  {
    perror("Error: listen()");
    return EXIT_FAILURE;
  }

  /* infinite loop */
  while (1)
  {
    /*  Generate a new socket for data transfer with the client */
    //  Tutor: socket runs concurrently
    clientfd = accept(fd, &clientaddr, &addrlen);

    /* receive the incomming client data */
    int bytes_received = recv(clientfd, buffer, 1023, 0);
    // "hello" => 5 bytes

    if (bytes_received >= BUFFER_SIZE)
    {
      bytes_received = BUFFER_SIZE - 1;
    }

    /* add null terminator to received data and print out message */
    buffer[bytes_received] = '\0'; // accessing the bytes / slot after the last byte of the string, preventing printing over the data received and wasting computation
    printf("> Number of Bytes received: %d. Data: %s\n", bytes_received, buffer);

    /* close the socket used to receive data */
    close(clientfd);
  }

  /* shutdown the connection - end communication to and from the socket SHUT_RDWR */
  if (shutdown(clientfd, SHUT_RDWR) == -1)
  {
    perror("Error: shutdown()");
    return EXIT_FAILURE;
  }

  // Tutor: It's important to note that after calling shutdown(), you can still call close() to release the resources associated with the socket. However, if you call close() without calling shutdown() first, the connection will be abruptly terminated without sending any signal to the other end.

  /* sockets can remain open after program termination - close listening socket*/
  if (close(fd) == -1)
  {
    perror("Error: close()");
    return EXIT_FAILURE;
  }
}
