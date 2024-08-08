#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  pid_t pid = fork();
  //        ^
  // From here on, the program is splitted into two processes
  // printf("\nFork returned: %d\n", pid);

  if (pid == 0)
  {
    printf("\nC: Child => PPID: %d PID: %d\n", getppid(), getpid());
    exit(EXIT_SUCCESS);
    printf("\nC: This will not be printed because the child process is terminated.\n");
  }
  else if (pid > 0)
  {
    printf("\nP: Parent => PID: %d\n", getpid());
    printf("\nP: Waiting for child process to finish.\n");
    wait(NULL);
    printf("\nP: Child process finished.\n");
  }
  else
  {
    printf("\nUnable to create child process.\n");
  }
  return EXIT_SUCCESS;
}