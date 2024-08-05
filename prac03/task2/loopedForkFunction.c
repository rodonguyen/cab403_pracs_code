#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  for (int i = 1; i <= 5; i++)
  {
    pid_t pid = fork();

    if (pid == 0)
    {
      printf("Child process => PPID=%d, PID=%d\n", getppid(), getpid());
      exit(0);
    }
    else
    {
      printf("\nParent process => PID=%d", getpid());
      printf("\nWaiting for child processes to finish...\n");
      wait(NULL);   // issue a wait() system call to move itself off the ready queue until the termination of the child
      printf("\nChild process finished.\n");
    }
  }
  return EXIT_SUCCESS;
}
