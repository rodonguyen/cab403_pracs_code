#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define TRUE 1

buffer_item buffer[BUFFER_SIZE];
pthread_mutex_t mutex;
sem_t empty;
sem_t full;

int insertPointer = 0, removePointer = 0;

void *producer(void *param);
void *consumer(void *param);

int insert_item(buffer_item item)
{
	int value = 0, val1 = 0;
	//Acquire Empty Semaphore
	sem_wait(&empty);

	//Acquire mutex lock to protect buffer
	pthread_mutex_lock(&mutex);
	sem_getvalue(&empty, &val1);
	printf("\nStarting to produce - Semaphore empty value = %d\n", val1);
	buffer[insertPointer++] = item;
	insertPointer = insertPointer % BUFFER_SIZE;

	//Release mutex lock and full semaphore
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
	sem_getvalue(&full, &value);
	printf("\nFinished producing - Semaphore full value = %d\n", value);

	return 0;
}

int remove_item(buffer_item *item)
{
	int value = 0, val1 = 0;
	//Acquire Full Semaphore
	sem_wait(&full);

	//Acquire mutex lock to protect buffer
	pthread_mutex_lock(&mutex);
	sem_getvalue(&full, &value);
	printf("Currently consuming - Semaphore full value = %d", value);
	*item = buffer[removePointer];
	buffer[removePointer++] = -1;
	removePointer = removePointer % BUFFER_SIZE;

	//Release mutex lock and empty semaphore
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
	sem_getvalue(&empty, &val1);
	printf("\nFinished consuming - Semaphore empty value = %d\n", val1);

	return 0;
}

int main(int argc, char *argv[])
{
	int sleepTime, producerThreads, consumerThreads;
	int i, j, value1 = 0, value2 = 0;

	if (argc != 4)
	{
		fprintf(stderr, "Useage: <sleep time> <producer threads> <consumer threads>\n");
		return -1;
	}

	sleepTime = atoi(argv[1]);
	producerThreads = atoi(argv[2]);
	consumerThreads = atoi(argv[3]);
	pthread_t tid[producerThreads];
	pthread_t cid[consumerThreads];

	//Initialize the the locks
	printf("%d\n", pthread_mutex_init(&mutex, NULL));
	printf("%d\n", sem_init(&empty, 0, BUFFER_SIZE));
	printf("%d\n", sem_init(&full, 0, 0));
	srand(time(0));

	sem_getvalue(&full, &value1);
	printf("\n\nInitialised value in main of full semaphore = %d\n", value1);
	sem_getvalue(&empty, &value2);
	printf("\n\nInitialised value in main of empty semaphore = %d\n", value2);

	//Create the producer and consumer threads
	for (i = 0; i < producerThreads; i++)
	{

		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&tid[i], &attr, producer, NULL);
	}

	for (j = 0; j < consumerThreads; j++)
	{

		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&cid[j], &attr, consumer, NULL);
	}

	//Sleep for user specified time
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
			fprintf(stderr, "Error");

		printf("Producer produced %d \n", random);
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
			fprintf(stderr, "Error Consuming");
		else
			printf("Consumer consumed %d \n", random);
	}
}
