#include <stdio.h>

int main(void)
{
  char input[5];
  (void)scanf("%5s", input);
  (void)printf("%s", input); /* Non-compliant */

  // Have to have some sorts of validation here
  // And becareful with how many chars you are getting from user

  return 0;
}
