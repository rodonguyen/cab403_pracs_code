#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

char *message = "This is a message from parent!!!";

// int main (int argc, char* argv[])
int main()
{
  pid_t childpid; /* variable to store the child's pid */
  char buf[1024];
  int fd[2]; // file descriptors for the pipe
  pipe(fd); // create pipe - and it's unidirectional
  if (fork() != 0)
  { 
    // I am the parent 
    write(fd[1], message, strlen(message) + 1);
    wait(NULL);  // try removing wait() and exit()
    printf("Done part 1\n");
  }
  else
  { 
    // Child code 
    childpid = getpid();
    printf("CHILD: I am the child process!\n");
    printf("CHILD: Here's my PID: %d\n", childpid);
    printf("CHILD: My parent's PID is: %d\n", getppid());
    read(fd[0], buf, strlen(message) + 1);
    printf("I got the following message from my parent: %s\n", buf);
    exit(EXIT_SUCCESS);
  }

  // send data from child to parent
  printf("\n\n");
  pid_t parentpid;
  int fd2[2]; 
  pipe(fd2);
  // change message
  message = "This is a message from child!!! 123";
  if (fork() == 0)
  { 
    // I am the child 
    write(fd2[1], message, strlen(message) + 1);
  }
  else
  { 
    // Parent process 
    parentpid = getpid();
    printf("PARENT: I am the parent process!\n");
    printf("PARENT: Here's my PID: %d\n", parentpid);
    printf("PARENT: My child's PID is: %d\n", getppid());
    read(fd2[0], buf, strlen(message) + 1);
    printf("I got the following message from my child: %s\n\n--", buf);
  }

  // Merge them together
  // TODO
}