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
  int client_fd;
  /* receive buffer */
  char receive_buffer[BUFFER_SIZE];

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

  /* Create a TCP/IP socket, making sure to select appropriate family,
      communication type & protocol
      https://man7.org/linux/man-pages/man2/socket.2.html  */
  int fd = socket(AF_INET, SOCK_STREAM, 0); // File Descriptor for the socket
  if (fd == -1)
  {
    perror("\nError: socket()\n");
    return 1;
  }

  /* Declare a data structure to specify the socket address (IP Address + Port)
   * Complete the Internet socket address structure
   * An IPv4 socket address structure - use memset to zero the struct out
   */
  struct sockaddr_in server_address;                     // https://man7.org/linux/man-pages/man3/sockaddr.3type.html
  memset(&server_address, '\0', sizeof(server_address)); // zero out the struct to avoid garbage values
  server_address.sin_port = htons(atoi(argv[1]));        // port number
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);    // IP address
  server_address.sin_family = AF_INET;                   // address family

  /* Assign a name to the socket created - Implement bind() system call
     Tutor: When a server application wants to listen for incoming connections, it needs to bind a socket to a specific IP address and port number. This allows the server to receive incoming connections on that specific address and port. */
  if (bind(fd, (struct sockaddr *)&server_address, sizeof(server_address)))
  {
    perror("Error: bind()");
    return 1;
  }

  /* Place server in passive mode - listen for incoming client request  */
  if (listen(fd, 10) == -1)
  {
    perror("Error: listen()");
    return 1;
  }

  /* infinite loop */
  while (1)
  {
    /*  Generate a new socket for data transfer with the client */
    client_fd = accept(fd, &clientaddr, &addrlen);
    if (client_fd == -1)
    {
      perror("Error: accept()");
      return 1;
    }

    /* receive the incoming client data */
    int bytes_received = recv(client_fd, receive_buffer, 1023, 0);  // Tutor: setting flag to 0 means that you want to receive the data in its default behavior without any special options. https://man7.org/linux/man-pages/man2/recvmsg.2.html
    if (bytes_received == -1)
    {
      perror("Error: bytesrcv");
      return 1;
    }

    /* add null terminator to received data and print out message */
    receive_buffer[bytes_received] = '\0';
    printf("\nNumber of Bytes received: %d.\nData: %s\n\n", bytes_received, receive_buffer);

    /* check if the client data is 'q' to close and shutdown the server */
    if (strcmp(receive_buffer, "q") == 0)
    {
      /* shutdown the connection - end communication to and from the socket SHUT_RDWR */
      if (shutdown(client_fd, SHUT_RDWR) == -1)
      {
        perror("Error: shutdown()");
        return 1;
      }

      /* close the socket used to receive data */
      close(client_fd);

      /* close the main socket */
      close(fd);
      printf("Server closed successfully\n");
      return 0;
    }

    /* close the socket used to receive data */
    close(client_fd);
  }
  
  return 0;
}
