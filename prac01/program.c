#include <stdio.h>

int main()
{
  // printf("Hello world! This is captain speaking.\n");
  // return 0;

  // Type size discovery
  char *char_ptr;
  int *int_ptr;
  long *long_ptr;
  short *short_ptr;
  float *float_ptr;
  double *double_ptr;
  char *far_char_ptr;

  struct my_struct_name
  {
    char letter;
    int favorite_number;
  } test_struct;

  printf("\n Type             Size ");
  printf("\n==========================");
  printf("\n character         %zu ", sizeof(char));
  printf("\n integer           %zu ", sizeof(int));
  printf("\n short             %zu ", sizeof(short));
  printf("\n long              %zu ", sizeof(long));
  printf("\n float             %zu ", sizeof(float));
  printf("\n double            %zu ", sizeof(double));
  printf("\n char pointer      %zu ", sizeof(char_ptr));
  printf("\n int pointer       %zu ", sizeof(int_ptr));
  printf("\n short pointer     %zu ", sizeof(short_ptr));
  printf("\n long pointer      %zu ", sizeof(long_ptr));
  printf("\n float pointer     %zu ", sizeof(float_ptr));
  printf("\n double pointer    %zu ", sizeof(double_ptr));
  printf("\n far char pointer  %zu ", sizeof(far_char_ptr));
  printf("\n test_structure    %zu ", sizeof(test_struct));
  printf("\n==========================");

  // a bit about struct
  test_struct = (struct my_struct_name){'A', 10};
  printf("\n test_structure.letter = %c", test_struct.letter);
  printf("\n test_structure.favorite_number = %d", test_struct.favorite_number);





  printf("\n");
  return 0;
}