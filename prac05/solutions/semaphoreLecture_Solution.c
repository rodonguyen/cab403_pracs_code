#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define THREADS 4
int shared = 0;
sem_t sem;

void *threadFunc(void *param) {
    int loops = atoi(param);
    for (int j = 0; j < loops; j++) {		
		sem_wait(&sem);
        shared++;      
        sem_post(&sem); 
	}
	return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t t[THREADS];
	pthread_attr_t attr;  //set of thread attributes
	
	if (argc != 2) {
		fprintf(stderr, "Usage a.out <integer value>\n");
		return EXIT_FAILURE;
	}
	if (atoi(argv[1])<0) {
		fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
		return EXIT_FAILURE;
	}
	/* get thread attributes */
	pthread_attr_init(&attr);
	sem_init(&sem,0,1);

    for (int i = 0; i < THREADS; ++i) {
        pthread_create(&t[i], &attr,  threadFunc, argv[1]);        
    }

    for (int i = 0; i < THREADS; ++i) {
       pthread_join(t[i] , NULL);       
    }
    
    printf("Using %d loops the sum result is = %d\n", atoi(argv[1]), shared);
    exit(EXIT_SUCCESS);
}
