#include <unistd.h>    /* Symbolic Constants */
#include <sys/types.h> /* Primitive System Data Types */
#include <errno.h>     /* Errors */
#include <stdio.h>     /* Input/Output */
#include <stdlib.h>    /* General Utilities */
#include <pthread.h>   /* POSIX Threads */
#include <string.h>    /* String handling */

void *print_message_function(void *ptr);

typedef struct thdata
{
  int thread_no;
  char message[20];
  int num1;
  int num2;
} thread_data;

int main(int argc, char *argv[])
{
  pthread_t thread1, thread2, thread3;
  // char message1[20] = "Hello 11!!!!";
  // char message2[20] = "Hello 22!!!!";
  // char message3[20] = "Hello 33!!!!";

  thread_data my_thread_data = {1, "Hello 1!!!!", 5, 8};

  pthread_create(&thread1, NULL, print_message_function, &my_thread_data);
  // pthread_create(&thread2, NULL, print_message_function, message2);
  // pthread_create(&thread3, NULL, print_message_function, message3);

  pthread_join(thread1, NULL);
  // pthread_join(thread2, NULL);
  // pthread_join(thread3, NULL);

  return 0;
}

void *print_message_function(void *ptr)
{
  thread_data *data = ptr; /* type cast to a pointer to thread_data */
  printf("Thread number:  %d \n", data->thread_no);
  printf("Thread says:  %s \n", data->message);
  printf("Sum of 2 numbers:  %d \n", data->num1 + data->num2);
  pthread_exit(0);
}

// void *print_message_function(void *ptr)
// {
//   char *data;
//   data = ptr; /* type cast to a pointer to thread_data */
//   for (int i = 0; i < 5; i++)
//   {
//     printf("Thread says:  %s \n", data);
//   }
//   pthread_exit(0);
// }