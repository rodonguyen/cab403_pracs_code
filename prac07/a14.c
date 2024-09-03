#include <stdio.h>
#include <stdint.h>
#include <string.h>

static void f_15(uint8_t s1[8], uint16_t s2[8])
{
  (void)memcpy(s1, s2, 8); /* Non-compliant */
  // display the content of s1
  for (int loop = 0; loop < 8; loop++)
    printf("%d \t ", s1[loop]);
  printf("\n");
}

/** Correct way */
static void f_16(uint16_t s1[8], uint16_t s2[8])
{
  (void)memcpy(s1, s2, 16); /* Non-compliant */
  // display the content of s1
  for (int loop = 0; loop < 8; loop++)
    printf("%d \t ", s1[loop]);
  printf("\n");
}

int main(void)
{
  uint16_t loc_s1[8];
  uint16_t loc_s2[8] = {1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U};
  f_16(loc_s1, loc_s2);
}

// uint16 is 2 bytes

/* end of R_21_15.c */
