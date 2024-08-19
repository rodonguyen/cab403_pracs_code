#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

#define FALSE 0
#define TRUE !FALSE
#define BUFFER_SIZE 5
#define MAX_SLEEP 5.0

typedef struct message_queue
{
  time_t buffer[BUFFER_SIZE];
  int keep_running;
  int position;
  int has_room;
} mq; //mq is an alias for `struct message_queue`

void *producer_function(void *arg)
{
  mq *message_queue = arg;
  int sleeptime;
  time_t message;

  srand((unsigned)time(NULL)); /* seed the random number generator.*/

  while (message_queue->keep_running)
  {
    /*
     * The ANSI C standard only states that rand() is a
     * random number generator which generates integers
     * in the range [0,RAND_MAX] inclusive, with RAND_MAX
     * being a value defined in stdlib.h, and RAND_MAX being at least 32767.
     *
     */
    /*sleeptime = 1 + (int)( MAX_SLEEP * rand() / (RAND_MAX + 1.0) ); */
    sleeptime = (int)(MAX_SLEEP * rand() / (RAND_MAX + 1.0));
    printf("Producer sleeping for %d seconds\n", sleeptime);
    fflush(stdout);
    sleep(sleeptime);

    message = time(NULL);
    printf("Producer produced %s", ctime(&message));

    /* this is the blocking send */

    while (message_queue->has_room == FALSE)
    {
      /* no room */
      printf("Producer Blocked\n");
      fflush(stdout);
      sleep(1);
    }

    printf("Producer UnBlocked\n");
    fflush(stdout);

    message_queue->buffer[message_queue->position++] = message;
    
    // Add the second time
    if (message_queue->position < BUFFER_SIZE)
    {
      message_queue->buffer[message_queue->position++] = message;
    }

    printf("\t\tItems in buffer: %d\n", message_queue->position);
    fflush(stdout);

    if (message_queue->position == BUFFER_SIZE)
    {
      message_queue->has_room = FALSE;
      printf("Full\n");
      fflush(stdout);
    }
  }
  printf("Producer told to stop.\n");
  fflush(stdout);
  return NULL;
}

void *consumer_function(void *arg)
{
  mq *message_queue = arg;
  time_t message;
  int sleeptime;

  srand((unsigned)time(NULL)); /* seed the random number generator.*/

  while (message_queue->keep_running)
  {
    /*
     * The ANSI C standard only states that rand() is a
     * random number generator which generates integers
     * in the range [0,RAND_MAX] inclusive, with RAND_MAX
     * being a value defined in stdlib.h, and RAND_MAX being at least 32767.
     *
     */
    /*sleeptime = 1 + (int)( MAX_SLEEP * rand() / (RAND_MAX + 1.0) ); */
    sleeptime = (int)(MAX_SLEEP * rand() / (RAND_MAX + 1.0));

    printf("\tConsumer 1 sleeping for %d seconds\n", sleeptime);
    fflush(stdout);
    sleep(sleeptime);

    /* this is the blocking receive */

    printf("\tConsumer 1 wants to consume\n");
    fflush(stdout);

    while (message_queue->position == 0)
    {
      /* nothing there so I have to wait */
      printf("\tConsumer 1 Blocked\n");
      fflush(stdout);
      sleep(1);
    }

    printf("\tConsumer 1 UnBlocked\n");
    fflush(stdout);

    message = message_queue->buffer[--message_queue->position];
    message_queue->has_room = TRUE;

    printf("\tConsumer 1 consumed %s", ctime(&message));
    printf("\t\tItems in buffer: %d\n", message_queue->position);
    fflush(stdout);
  }
  printf("\tConsumer 1 told to stop.\n");
  fflush(stdout);
  return NULL;
}

void *consumer_function2(void *arg)
{
  mq *message_queue = arg;
  time_t message;
  int sleeptime;

  srand((unsigned)time(NULL)); /* seed the random number generator.*/

  while (message_queue->keep_running)
  {
    /*
     * The ANSI C standard only states that rand() is a
     * random number generator which generates integers
     * in the range [0,RAND_MAX] inclusive, with RAND_MAX
     * being a value defined in stdlib.h, and RAND_MAX being at least 32767.
     *
     */
    /*sleeptime = 1 + (int)( MAX_SLEEP * rand() / (RAND_MAX + 1.0) ); */
    sleeptime = (int)(MAX_SLEEP * rand() / (RAND_MAX + 1.0));

    printf("\tConsumer 2 sleeping for %d seconds\n", sleeptime);
    fflush(stdout);
    sleep(sleeptime);

    /* this is the blocking receive */

    printf("\tConsumer 2 wants to consume\n");
    fflush(stdout);

    while (message_queue->position == 0)
    {
      /* nothing there so I have to wait */
      printf("\tConsumer 2 Blocked\n");
      fflush(stdout);
      sleep(1);
    }

    printf("\tConsumer 2 UnBlocked\n");
    fflush(stdout);

    message = message_queue->buffer[--message_queue->position];
    message_queue->has_room = TRUE;

    printf("\tConsumer 2 consumed %s", ctime(&message));
    printf("\t\tItems in buffer: %d\n", message_queue->position);
    fflush(stdout);
  }
  printf("\tConsumer 2 told to stop.\n");
  fflush(stdout);
  return NULL;
}

int main()
{
  pthread_t producer;
  pthread_t consumer;
  pthread_t consumer2;
  mq messages;
  char ignore_this[80];

  messages.keep_running = TRUE;
  messages.position = 0;
  messages.has_room = TRUE;

  // if (has_error)
  if (pthread_create(&producer, NULL, producer_function, &messages))
  {
    printf("error creating thread.");
    abort();
  }
  if (pthread_create(&consumer, NULL, consumer_function, &messages))
  {
    printf("error creating thread.");
    abort();
  }
  if (pthread_create(&consumer2, NULL, consumer_function2, &messages))
  {
    printf("error creating thread.");
    abort();
  }

  fgets(ignore_this, 80, stdin);
  messages.keep_running = FALSE;
  if (pthread_join(producer, NULL))
  {
    printf("error joining producer thread");
    abort();
  }
  if (pthread_join(consumer, NULL))
  {
    printf("error joining consumer thread");
    abort();
  }

  return 0;
}
