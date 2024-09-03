#include <stdint.h>
#include <stdio.h>

void f1(void)
{
  uint16_t code[10];
  // code[0] = 109;
  // code[1] = 100;
  // code[2] = 052;
  // code[3] = 071;
  code[0] = 109U;
  code[1] = 100U;
  code[2] = 52U;
  code[3] = 71U;
  

  for (uint16_t i = 0; i < 4; i++)
  {
    printf("%d\n", code[i]);
  }
}

int main(void)
{
  f1();
  return 0;
}

// remove prefix 0 from octal number and add U suffix to the decimal number