#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define TRUE 1

buffer_item buffer[BUFFER_SIZE];
pthread_mutex_t mutex;
sem_t empty; // semaphore to keep track of empty slots in the buffer
sem_t full;  // semaphore to keep track of full slots in the buffer

int insertPointer = 0, removePointer = 0;

void *producer(void *param);
void *consumer(void *param);

int insert_item(buffer_item item)
{
  // Acquire Empty Semaphore
  sem_wait(&empty);

  // print
  int temp_var1, temp_var2;
  sem_getvalue(&empty, &temp_var1);
  sem_getvalue(&full, &temp_var2);
  printf("\tInserting... empty = %d, full = %d\n", temp_var1, temp_var2);

  // Acquire mutex lock to protect buffer
  pthread_mutex_lock(&mutex);
  buffer[insertPointer++] = item;
  insertPointer = insertPointer % BUFFER_SIZE;

  // print
  printf("\tinsertPointer = %d\n", insertPointer);

  // Release mutex lock and full semaphore
  pthread_mutex_unlock(&mutex);
  sem_post(&full);

  return 0;
}

int remove_item(buffer_item *item)
{
  /* insert your code here for Task 1 (a) */
  /* Acquire Full Semaphore */
  sem_wait(&full);

  // print
  int temp_var1, temp_var2;
  sem_getvalue(&empty, &temp_var1);
  sem_getvalue(&full, &temp_var2);
  printf("\tRemoving... empty = %d, full = %d\n", temp_var1, temp_var2);

  /* Acquire mutex lock to protect buffer */
  pthread_mutex_lock(&mutex);

  // Remove item from buffer
  *item = buffer[removePointer];
  buffer[removePointer] = -1;
  removePointer = (removePointer + 1) % BUFFER_SIZE;

  // print
  printf("\tremovePointer = %d\n", removePointer);

  /* Release mutex lock and empty semaphore */
  pthread_mutex_unlock(&mutex);
  sem_post(&empty);

  return 0;
}

int main(int argc, char *argv[])
{
  int i, j;

  if (argc != 4)
  {
    fprintf(stderr, "Useage: <sleep time> <producer threads> <consumer threads>\n");
    return -1;
  }

  /* insert you code below for Task 1 (b) */
  /* Get command line arguments argv[1], argv[2], argv[3]*/
  int sleepTime = atoi(argv[1]);
  int producerThreadNumber = atoi(argv[2]);
  int consumerThreadNumber = atoi(argv[3]);
  pthread_t producer_thread_ids[producerThreadNumber];
  pthread_t consumer_thread_ids[consumerThreadNumber];

  /* Initialize the the locks */
  pthread_mutex_init(&mutex, NULL);
  sem_init(&empty, 0, BUFFER_SIZE);
  sem_init(&full, 0, 0);

  srand(123);

  // quick check for sanity
  int value1, value2;
  sem_getvalue(&full, &value1);
  printf("Initialised value in main of full semaphore = %d\n", value1);
  sem_getvalue(&empty, &value2);
  printf("Initialised value in main of empty semaphore = %d\n\n", value2);

  // Create the producer and consumer threads
  for (i = 0; i < producerThreadNumber; i++)
  {
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&producer_thread_ids[i], &attr, producer, NULL);
  }

  for (j = 0; j < consumerThreadNumber; j++)
  {
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&consumer_thread_ids[j], &attr, consumer, NULL);
  }

  // Sleep for user specified time
  sleep(sleepTime);

  return 0;
}

void *producer(void *param)
{
  buffer_item random;
  int r;

  while (TRUE)
  {
    r = rand() % 5;
    sleep(r);
    random = rand();

    if (insert_item(random))
    {
      fprintf(stderr, "Error");
    }
    else
    {
      printf("Producer produced %d \n", random);
    }
  }
}

void *consumer(void *param)
{
  buffer_item random;
  int r;

  while (TRUE)
  {
    r = rand() % 5;
    sleep(r);

    if (remove_item(&random))
    {
      fprintf(stderr, "Error Consuming");
    }
    else
    {
      printf("Consumer consumed %d \n", random);
    }
  }
}
