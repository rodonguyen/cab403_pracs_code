#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

// char *message = "This is a message from parent, code 123!";

// int main()
int main (int argc, char* argv[])
{
  // pid_t childpid; // variable to store the child's pid
  char buffer[1024];  // 1024 bytes
  int fd[2]; // file descriptors for the pipe, store the location to read and write
  pipe(fd); // create pipe - and it's unidirectional
  
  int fd2[2]; 
  pipe(fd2);
  char buffer2[1024];  // 1024 bytes

  if (fork() != 0) // a bit dangerous to not check for negative values
  { 
    // I am the parent, > 0 to be exact
    write(fd[1], argv[1], strlen(argv[1]) + 1);
    read(fd2[0], buffer2, 1024);
    // wait(NULL);  // wait try removing wait() and exit()
    printf("I got the following message from my child: %s\n", buffer2);
  }
  else
  { 
    // // Child code 
    // childpid = getpid();
    // printf("CHILD: I am the child process!\n");
    // printf("CHILD: Here's my PID: %d\n", childpid);
    // printf("CHILD: My parent's PID is: %d\n", getppid());
    write(fd2[1], argv[2], strlen(argv[2]) + 1);
    read(fd[0], buffer, 1024);
    printf("I got the following message from my parent: %s\n", buffer);
    // exit(EXIT_SUCCESS);
  }

  // // send data from child to parent
  // printf("\n\n");
  // pid_t parentpid;
  // int fd2[2]; 
  // pipe(fd2);
  // // change message
  // message = "This is a message from child!!! 123";
  // if (fork() == 0)
  // { 
  //   // I am the child 
  //   write(fd2[1], message, strlen(message) + 1);
  // }
  // else
  // { 
  //   // Parent process 
  //   parentpid = getpid();
  //   printf("PARENT: I am the parent process!\n");
  //   printf("PARENT: Here's my PID: %d\n", parentpid);
  //   printf("PARENT: My child's PID is: %d\n", getppid());
  //   read(fd2[0], buffer, strlen(message) + 1);
  //   printf("I got the following message from my child: %s\n\n--", buffer);
  // }

  // Merge them together
  // TODO
}