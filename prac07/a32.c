#include <stdint.h>
#include <stdio.h>

void f1(void)
{
  uint16_t code[10];

  // code[0] = 70000;
  // code[1] = 70000U;
  // code[2] = 65000;
  // code[3] = 65000U;

  // code[0] = 109U;
  // code[1] = 100U;
  // code[2] = 052U;
  // code[3] = 071U;
  code[0] = 109U;
  code[1] = 100U;
  code[2] = 052U; // receive 052 as octal number with prefix 0
  code[3] = 071U;
  

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