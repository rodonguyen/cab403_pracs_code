#include <stdio.h>
#include <time.h>

int main()
{
  fprintf(stderr, "Creating a file that is 10MB\n");

  FILE *fp_out = fopen("a_10MB_file.txt", "w");

  clock_t before = clock();

  int random_char = 75;
  for (int i=0; i<10485760; i++)
  {
    fputc(random_char, fp_out);
  }

  clock_t after = clock();
  fclose(fp_out);
  clock_t duration = after - before;
  int s = duration / CLOCKS_PER_SEC;
  int ms = (duration % CLOCKS_PER_SEC) * 1000 / CLOCKS_PER_SEC;
  fprintf(stderr, "Creation took %ds %dms\n", s, ms);

  return 0;
}
