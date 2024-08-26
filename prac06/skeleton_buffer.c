#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define TRUE 1

buffer_item buffer[BUFFER_SIZE];
pthread_mutex_t mutex;
sem_t empty;
sem_t full;

int insertPointer = 0, removePointer = 0;

void *producer(void *param);
void *consumer(void *param);

int insert_item(buffer_item item) {
	//Acquire Empty Semaphore
	sem_wait(&empty);

	//Acquire mutex lock to protect buffer
	pthread_mutex_lock(&mutex);
	buffer[insertPointer++] = item;
	insertPointer = insertPointer % BUFFER_SIZE;

	//Release mutex lock and full semaphore
	pthread_mutex_unlock(&mutex);
	sem_post(&full);

	return 0;
}

int remove_item(buffer_item *item) {
	/* insert your code here for Task 1 (a) */

	/* Acquire Full Semaphore */

	/* Acquire mutex lock to protect buffer */

	/* Release mutex lock and empty semaphore */

	return 0;
}

int main(int argc, char *argv[]) {
	int sleepTime, producerThreads, consumerThreads;
	int i, j;

	if (argc != 4) 	{
		fprintf(stderr, "Useage: <sleep time> <producer threads> <consumer threads>\n");
		return -1;
	}

	/* insert you code below for Task 1 (b) */

	/* Get command line arguments argv[1], argv[2], argv[3]*/

	/* Initialize the the locks */

	/* Create the producer and consumer threads */

	/* Sleep for user specified time */

	return 0;
}

void *producer(void *param) {
	buffer_item random;
	int r;

	while (TRUE) 	{
		r = rand() % 5;
		sleep(r);
		random = rand();

		if (insert_item(random)) {
			fprintf(stderr, "Error");
		} else {
			printf("Producer produced %d \n", random);
		}
	}
}

void *consumer(void *param) {
	buffer_item random;
	int r;

	while (TRUE) 	{
		r = rand() % 5;
		sleep(r);

		if (remove_item(&random)) {
			fprintf(stderr, "Error Consuming");
		} else {
			printf("Consumer consumed %d \n", random);
		}
	}
}
