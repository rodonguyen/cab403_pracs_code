// /*Multithreaded application to add numbers between 1 and input from terminal *usage e.g../ programName 20 * will sum the numbers between 1 and 20 inclusive */

// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>

// int sum; // shared data between threads
// void *runner(void *param); // threads call this function

// int main(int argc, char *argv[])
// {
//   pthread_t tid;       // thread identifier
//   pthread_attr_t attr; // set of thread attributes
//   if (argc != 2)
//   {
//     fprintf(stderr, "Usage a.out <integer value>\n");
//     return EXIT_FAILURE;
//   }

//   if (atoi(argv[1]) < 0)
//   {
//     fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
//     return EXIT_FAILURE;
//   }

//   /* get thread attributes */
//   pthread_attr_init(&attr);

//   /* create thread */
//   pthread_create(&tid, &attr, runner, argv[1]);

//   /* wait for thread to exit */
//   pthread_join(tid, NULL);
//   printf("\nApplication to demonstrate basic Multithreaded Application\n\n----------------------------------\n");
//   printf("The sum of the numbers from 1 to %d is = %d\n", atoi(argv[1]), sum);
//   printf("----------------------------------\n");
// }

// /* The thread will begin control in this function */
// void *runner(void *param)
// {
//   int upper = atoi(param);
//   sum = 0;
//   for (int i = 0; i <= upper; i++)
//   {
//     sum += i;
//   }
//   pthread_exit(0);
// }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>   /* standard I/O routines                 */
#include <pthread.h> /* pthread functions and data structures */
#include <stdlib.h>

void *PrintHello(void *data);

int main(int argc, char *argv[])
{
  int rc;              /* return value                           */
  pthread_t thread_id; /* thread's ID (just an integer)  */
  pthread_attr_t attr;
  if (argc != 2)
  {
    fprintf(stderr, "usage: ./programName <integer>\n");
    return EXIT_FAILURE;
  }
  pthread_attr_init(&attr);
  /* create a new thread that will execute 'PrintHello' */
  rc = pthread_create(&thread_id, &attr, PrintHello, argv[1]);
  if (rc)
  { /* could not create thread */
    printf("\n ERROR: return code from pthread_create is %d \n", rc);
    return EXIT_FAILURE;
  }
  printf("\nCreated new thread (%ld) ... \n", thread_id);
  pthread_exit(NULL); /* terminate the thread */
}

/* function to be executed by the new thread */
void *PrintHello(void *data)
{
  int my_data = atoi(data); /* data received by thread */
  pthread_detach(pthread_self());
  printf("Hello from new thread - got %d\n", my_data);
  pthread_exit(NULL); /* terminate the thread */
}
