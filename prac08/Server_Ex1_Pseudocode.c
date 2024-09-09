#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1023

int main(int argc, char **argv) {
	
	/* client file descriptor */
	int clientfd;
	/* receive buffer */
	char buffer[BUFFER_SIZE];
	
	struct sockaddr clientaddr;
	socklen_t addrlen;
	
	/* Check user has passed in the port number at the command line 
	 * local host will be used as the default address 
	*/
	
		
	/* Create a TCP/IP socket making sure to select appropriate family, communication type & 
	 * protocol
	 */
	
	 
	/* Declare a data structure to specify the socket address (IP Address + Port)
	 * Complete the Internet socket address structure
	 * An IPv4 socket address structure - use memset to zero the struct out
	 */
	
	
	 /* Assign a name to the socket created - Implement bind() system call */
	
	 
	 /* Place server in passive mode - listen for incomming client request  */
	
	  
	  /* infinite loop */
	  while (1) {
		  
		  /*  Generate a new socket for data transfer with the client */
		 
		 
		  
		  /* receive the incomming client data */
		 
		  
		  /* add null terminator to received data and print out message */
		 
		  /* close the socket used to receive data */
		 
		 
	  } // end while
	  
	   /* shutdown the connection - end communication to and from the socket SHUT_RDWR */
	  

		/* sockets can remain open after program termination - close listening socket*/
	
		
}
