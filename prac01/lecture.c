#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

void playWithMemoryAddress()
{
  int *ptr;
  int x = 10;
  ptr = &x;
  printf("The value of x is %d\n", *ptr);
  // free(ptr);
}

int main()
{
  // An example of memory leak
  // While it's running, check "program" process in system monitor
  int *data;

  size_t large_size = 1000000000; // 1 billion (bytes) = 1 GB!!!
  int iteration = 0;

  // Get the current memory consumption of the program in KB
  system("ps -o rss= -p $PPID");

  while (true)
  {
    data = (int *)malloc(large_size);  // (m)emory (alloc)ation, allocation 1 GB of memory each iteration!
    // printf("Iteration %d\n", iteration);
    if (data == NULL)
    {
      printf("\n===\nMemory allocation failed at iteration %d\n", iteration);
      break;
    }
    iteration++;
    sleep(0.3);

    // Free up the memory (at data pointer) will solve the problem
    // free(data);
  }
  system("ps -o rss= -p $PPID");

  return 0;
}