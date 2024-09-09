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
 
int main(int argc, char **argv){
	
	/* check port number is passed in in on command line */			
	
	/* variables required for solution */
	int sockfd;	
	struct sockaddr_in server_addr, client_addr;
	char buffer[BUFFER_SIZE];
	socklen_t addr_size;
	char *ip = "127.0.0.1";
	bool cont = true;
	
	
	/* Create a UDP Socket */ 
	
	
	/* Initialise the sockaddr_in structure 
	 * use memset to zero the struct out
	*/	
	
	
	/* bind server address to socket descriptor */
	
	while (cont) {

		/* clear buffer */
			
		/* Calculating the Client Datagram length */
			
		/* use recvfrom to receive data from client */
			
			
		/* Output the message from the client */		
		

		/* If termination message sent from server exit while loop*/
			
	
		/* Clear the buffer and send a message from the server to the client */
			
	}

	// Closing the Socket File Descriptor.
	
	return 0;
}
