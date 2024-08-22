#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


void hello(void); /* Function to thread */

int main(int argc, char *argv[])
{
  int num_threads = 100;
  omp_set_num_threads(num_threads);

  #pragma omp parallel
  {
    hello();
  }
  return EXIT_SUCCESS;
}

void hello(void)
{
  int my_rank = omp_get_thread_num();
  int thread_count = omp_get_num_threads();
  printf("Hello from thread %d of %d\n", my_rank, thread_count);
}
