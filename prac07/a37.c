#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#define MAX_COUNT 10

// unsigned int count = 0;

// void counter()
// {
//   if (count++ > MAX_COUNT)
//     return;
//   /* ... */
// }

///////////////////////////////////////////

bool exceed_max()
{
  static unsigned int count = 0;  // try removing static keyword
  if (count++ > MAX_COUNT)
  {
    printf("Count is greater than MAX_COUNT\n");
    return true;
  }

  return false;
}

int main(void)
{
  // printf("count = %d\n", count); // try uncommenting this line

  while (!exceed_max())
  {
    printf("Count is less than MAX_COUNT\n");
  }
  return 0;
}