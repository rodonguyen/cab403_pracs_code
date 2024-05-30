#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5

// Shared data
pthread_mutex_t mutex;
pthread_cond_t full, empty;

int buffer[BUFFER_SIZE] = {0};
int in = 0, out = 0;

void *producer(void *arg);
void *consumer(void *arg);

int main(int argc, char *argv[])
{
  pthread_t producer1, producer2, consumer1, consumer2;

  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&full, NULL);
  pthread_cond_init(&empty, NULL);

  pthread_create(&producer1, NULL, producer, NULL);
  pthread_create(&producer2, NULL, producer, NULL);
  pthread_create(&consumer1, NULL, consumer, NULL);
  pthread_create(&consumer2, NULL, consumer, NULL);

  pthread_join(producer1, NULL);
  pthread_join(producer2, NULL);
  pthread_join(consumer1, NULL);
  pthread_join(consumer2, NULL);

  pthread_mutex_destroy(&mutex);

  return 0;
}

void printBuffer()
{ 
  for (int i = 0; i < BUFFER_SIZE; i++)
  {
    printf("%d ", buffer[i]);
  }
  printf("\n");
}

void *producer(void *arg)
{
  for (;;)
  {
    pthread_mutex_lock(&mutex);
    while ((in + 1) % BUFFER_SIZE == out) // while the buffer is full
    {
      pthread_cond_wait(&empty, &mutex); // wait until there is an "empty" buffer, while waiting, unlock the mutex for other threads
    }
    printf("Producer turn: ");
    buffer[in] = 1;
    in = (in + 1) % BUFFER_SIZE;
    pthread_cond_signal(&full);
    printBuffer();
    pthread_mutex_unlock(&mutex);
    sleep(1);
  }
}

void *consumer(void *arg)
{
  for (;;)
  {
    pthread_mutex_lock(&mutex);
    while (in == out)
    {
      pthread_cond_wait(&full, &mutex);
    }
    printf("Consumer turn: ");
    buffer[out] = 0;
    out = (out + 1) % BUFFER_SIZE;
    pthread_cond_signal(&empty);
    printBuffer();
    pthread_mutex_unlock(&mutex);
    sleep(1);
  }
}
