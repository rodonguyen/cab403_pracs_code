#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

// char *message = "This is a message from parent, code 123!";

int main(int argc, char *argv[])
{
  const int READ_INDEX = 0;
  const int WRITE_INDEX = 1;
  const int BUFFER_SIZE = 1024;

  char buffer[BUFFER_SIZE]; // This buffer has 1 KB = 1024 bytes
  int fd[2];                // file descriptors for the pipe, store the location to read and write. When we create an integer array of size 2, we are effectively creating pointers, one for reading and one for writing
  pipe(fd);                 // create pipe - and it's unidirectional

  char buffer2[BUFFER_SIZE];
  int fd2[2];
  pipe(fd2);

  pid_t pid = fork();
  if (pid > 0)
  { /* I am the parent, and I'm sending data to child process */
    read(fd2[READ_INDEX], buffer2, BUFFER_SIZE);
    printf("I got the following message from my child: %s\n", buffer2);

    // write(fd[WRITE_INDEX], argv[1], strlen(argv[1]) + 1);  // TODO: try with data size 1024
    write(fd[WRITE_INDEX], argv[1], strlen(argv[1]) + 900); // TODO: try with data size 1024

    wait(NULL);
    printf("Child is terminated!\n");
  }
  else if (pid == 0)
  { /* Child process reads the data */
    write(fd2[WRITE_INDEX], argv[2], strlen(argv[2]) + 1);
    read(fd[READ_INDEX], buffer, BUFFER_SIZE);

    printf("I got the following message from my parent: %s\n", buffer);
    printf("Child is done!\n");
    exit(EXIT_SUCCESS);
  }
  else
  {
    printf("Unable to create child process.\n");
  }

  // send data from child to parent
  printf("\n\n");
  int fd3[2];
  pipe(fd3);
  char *message = "Pipe pipe pipe!";
  if (fork() == 0)
  {
    // I am the child
    write(fd2[1], message, strlen(message) + 1);
  }
  else
  {
    // Parent process
    pid_t parentpid = getpid();
    printf("PARENT: I am the parent process!\n");
    printf("PARENT: Here's my PID: %d\n", parentpid);
    printf("PARENT: My child's PID is: %d\n", getppid());
    read(fd2[0], buffer, strlen(message) + 1);
    printf("I got the following message from my child: %s\n\n--", buffer);
  }
}

// int main (int argc, char* argv[])
// {
//   // pid_t childpid; // variable to store the child's pid
//   char buffer[1024];  // 1024 bytes
//   int fd[2]; // file descriptors for the pipe, store the location to read and write
//   pipe(fd); // create pipe - and it's unidirectional

//   int fd2[2];
//   pipe(fd2);
//   char buffer2[1024];  // 1024 bytes

//   if (fork() != 0) // a bit dangerous to not check for negative values
//   {
//     // I am the parent, > 0 to be exact
//     write(fd[1], argv[1], strlen(argv[1]) + 1);
//     read(fd2[0], buffer2, 1024);
//     // wait(NULL);  // wait try removing wait() and exit()
//     printf("I got the following message from my child: %s\n", buffer2);
//   }
//   else
//   {
//     // // Child code
//     // childpid = getpid();
//     // printf("CHILD: I am the child process!\n");
//     // printf("CHILD: Here's my PID: %d\n", childpid);
//     // printf("CHILD: My parent's PID is: %d\n", getppid());
//     write(fd2[1], argv[2], strlen(argv[2]) + 1);
//     read(fd[0], buffer, 1024);
//     printf("I got the following message from my parent: %s\n", buffer);
//     // exit(EXIT_SUCCESS);
//   }

// Merge them together
// TODO
// }


hellomake: hellomake.o hellomake.h
  command1
  command2