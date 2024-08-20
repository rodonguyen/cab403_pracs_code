#include <unistd.h>    /* Symbolic Constants */
#include <sys/types.h> /* Primitive System Data Types */
#include <errno.h>     /* Errors */
#include <stdio.h>     /* Input/Output */
#include <stdlib.h>    /* General Utilities */
#include <pthread.h>   /* POSIX Threads */
#include <string.h>    /* String handling */

#define MESSAGE_REPEAT 2

/* struct to hold data to be passed to a thread
   this shows how multiple data items can be passed to a thread */
typedef struct str_thdata
{
  int thread_no;
  char message[100];
} thread_data;

/* prototype for thread routine */
void *print_message_function(void *ptr);
void *sum_some_numbers(void *ptr);

int main(int argc, char *argv[])
{
  pthread_t thread1, thread2, thread3; /* thread variables */
  thread_data data1, data2, data3;     /* structs to be passed to threads */

  /* initialize data to pass to thread 1 */
  data1.thread_no = 1;
  strcpy(data1.message, "Hello! Welcome to Practical 5 - Week 5 already!!!");

  /* initialize data to pass to thread 2 */
  data2.thread_no = 2;
  strcpy(data2.message, "Hi! Week 5 - Time flies by when programming in C");

  /* initialize data to pass to thread 3 */
  data3.thread_no = 3;
  // strcpy(data1.message, "Hey...");


  /* create threads
   *  function must take a parameter of void *(the second void *)
   *  return a value of void * (first void)
   */
  pthread_create(&thread1, NULL, print_message_function, &data1);
  pthread_create(&thread2, NULL, print_message_function, &data2);
  pthread_create(&thread3, NULL, sum_some_numbers, &data3);

  /* Main block now waits for both threads to terminate, before it exits
     If main block exits, both threads exit, even if the threads have not
     finished their work */
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);

  printf("All threads have finished\n");

  /* exit */
  return EXIT_SUCCESS;
} /* main() */

/**
 * print_message_function is used as the start routine for the threads used
 * it accepts a void pointer
 **/
void *print_message_function(void *ptr)
{
  thread_data *data;
  data = ptr; /* type cast to a pointer to thread_data */

  /* do the work */
  for (int x = 0; x < MESSAGE_REPEAT; x++)
  {
    printf("Thread %d says:  %s \n", data->thread_no, data->message);
  }
  return NULL;
}

void *sum_some_numbers(void *pointer)
{
  thread_data *data = pointer;
  int sum = 0;
  for (int i = 1; i <= 20; i++)
  {
    sum += i;
  }
  printf("Thread %d reports: The sum of the numbers from 1 to 20 is = %d\n", data->thread_no, sum);
  pthread_exit(0);
}