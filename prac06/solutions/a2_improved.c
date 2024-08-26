#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>

void *addMillion(void *arg);
int globalVar = 0;
pthread_mutex_t lock;

int main(int argc, char *argv[])
{
  pthread_mutex_init(&lock, NULL);

  // measure exec time
  struct timeval start, end;
  gettimeofday(&start, NULL);

  pthread_t thread1, thread2;
  pthread_create(&thread1, NULL, addMillion, NULL);
  pthread_create(&thread2, NULL, addMillion, NULL);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  printf("Total for globalVar = %d\n", globalVar);

  gettimeofday(&end, NULL);
  double elapsedTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
  printf("Execution time: %.6f seconds\n", elapsedTime);

  return 0;
}

void *addMillion(void *ptr)
{
  int localSum = 0;

  for (int i = 0; i < 1000000; i++)
  {
    localSum++;
  }

  // Lock the mutex before updating the global variable
  if (pthread_mutex_lock(&lock))
  {
    perror("\nError with mutex lock\n");
  }
  globalVar += localSum;
  if (pthread_mutex_unlock(&lock))
  {
    perror("\nError unlocking mutex\n");
  }
  return NULL;
}
