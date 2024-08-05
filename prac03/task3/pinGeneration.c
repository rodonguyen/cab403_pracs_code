#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int getPIN()
{
  // use PPID and PID as the seed
  srand(getpid() + getppid());
  int secret = 1000 + rand() % 9000;
  return secret;
}

int main(int argc, char *argv[])
{
  int fd[2];
  pipe(fd);
  pid_t pid = fork();

  if (pid > 0)
  {
    close(0); // close the read end of the pipe
    close(fd[1]); // close the write end of the pipe
    dup(fd[0]); // duplicate the read end of the pipe to stdin

    int secretNumber;
    size_t readBytes = read(fd[0], &secretNumber, sizeof(secretNumber));
    printf("Waiting for PIN...\n");
    wait(NULL);
    printf("Bytes read: %ld\n", readBytes);
    printf("PIN: %d\n", secretNumber);
  }
  else if (pid == 0)
  {
    close(1);
    close(fd[0]);
    dup(fd[1]);

    int secret = getPIN();
    write(fd[1], &secret, sizeof(secret));
    exit(EXIT_SUCCESS);
  }

  return EXIT_SUCCESS;
}
