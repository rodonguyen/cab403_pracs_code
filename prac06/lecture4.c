#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

#define THREADS 32
#define START 0
#define END 100000

/* a global variable */
unsigned long sum = 0;

/* the function called for each thread */
void *sum_part(void *idp)
{
  /* get our thread id */
  int id = *(int *)idp;

  /* calculate the start and end points by evenly dividing the range */
  unsigned long start = ((END - START) / THREADS) * id;
  unsigned long end = start + ((END - START) / THREADS) - 1;

  /* the last thread needs to do all remaining ones */
  if (id == (THREADS - 1))
  {
    end = END;
  }

  /* do the calculation */
  unsigned long i;
  for (i = start; i <= end; i++)
  {
    sum += i;
  }

  return NULL;
}

int main(int argc, char *argv[])
{
  /* an array of threads */
  pthread_t threads[THREADS];
  int ids[THREADS];
  int i;

  /* spawn all threads */
  for (i = 0; i < THREADS; i++)
  {
    ids[i] = i;
    pthread_create(&threads[i], NULL, sum_part, &ids[i]);
  }

  /* join all threads collecting answer */
  for (i = 0; i < THREADS; i++)
  {
    pthread_join(threads[i], NULL);
  }

  /* now all results are in */
  printf("Final answer = %lu.\n", sum);
  pthread_exit(NULL);
}