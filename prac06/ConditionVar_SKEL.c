#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define MAX_ITEMS 5

int buffer[BUFFER_SIZE] = {0};
int produce_pointer = 0;
int consume_pointer = 0;
pthread_mutex_t mutex;
pthread_cond_t full, empty;

void *producer(void *arg);
void *consumer(void *arg);

void printBuffer()
{
  for (int i = 0; i < BUFFER_SIZE; i++)
  {
    printf(" %d ", buffer[i]);
  }
  printf("\n");
}

void *producer(void *arg)
{
  for (;;)
  {
    pthread_mutex_lock(&mutex);
    while ((produce_pointer + 1) % BUFFER_SIZE == consume_pointer) // while the buffer is full
    {
      pthread_cond_wait(&empty, &mutex); // wait until there is an "empty" buffer, while waiting, unlock the mutex for other threads}
    }

    buffer[produce_pointer] = 1;
    produce_pointer = (produce_pointer + 1) % BUFFER_SIZE;

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
    while (produce_pointer == consume_pointer)
    {
      pthread_cond_wait(&full, &mutex);
    }
    buffer[consume_pointer] = 0; // consume/ remove item from buffer
    consume_pointer = (consume_pointer + 1) % BUFFER_SIZE;

    pthread_cond_signal(&empty);
    printBuffer();
    pthread_mutex_unlock(&mutex);

    sleep(1);
  }
}

int main(int argc, char *argv[])
{
  pthread_t producerThread1, producerThread2, consumerThread1, consumerThread2;
  // mutex not used as yet
  pthread_mutex_init(&mutex, NULL);

  pthread_create(&producerThread1, NULL, producer, NULL);
  pthread_create(&producerThread2, NULL, producer, NULL);
  pthread_create(&consumerThread1, NULL, consumer, NULL);
  pthread_create(&consumerThread2, NULL, consumer, NULL);

  pthread_join(producerThread1, NULL);
  pthread_join(producerThread1, NULL);
  pthread_join(consumerThread1, NULL);
  pthread_join(consumerThread2, NULL);

  pthread_mutex_destroy(&mutex);

  return 0;
}
