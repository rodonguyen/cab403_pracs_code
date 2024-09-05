#include <stdio.h>
#include <stdint.h>
#include <string.h>

static void f_17(const char *input_string)
{
  char string[6] = "Short";

  printf("Before: %s \n", string); /* we directly use stdio here. you should define your own IO. */

  /* Non-compliant use of strcpy as it
   *  results in writes beyond the end of 'string'*/
  (void)strcpy(string, "Too long to fit ");
  printf("%s \n", string);

  // Compliant use of strcpy as 'string' is only mocified if 'input_string' will fit.
  
  // if input_string is less than the size of string, then copy input_string to string
  if (strlen(input_string) < (sizeof(string) - 1U)) /* Checking if string can contain whatever input_string is having / size of string can fit input_string. Compliant */
  {
    (void)strcpy(string, input_string);
  }

  printf("After: %s \n", string);
}

static void g_17(void)
{
  size_t sz;
  size_t sz1;
  char text[5] = "Token"; /* Non-compliant, change the array length to 10 to make it compliant */
  char text1[10] = {'T', 'o', 'k', 'e', 'n', '\0'};
  /*
   * The following is non-compliant as it results in
   * Reads beyond the end of 'text' as there is no null terminator.
   * NOTE: the strlen() function doesn't count the null character \0
   * while calculating the length.
   */
  sz = strlen(text); /* Non-compliant */
  sz1 = strlen(text1);

  if (sz > 1U)
  {
    /* use “%zu” to print the variables of size_t length. */
    printf("size of text: %zu \n", sz);
  }

  if (sz1 > 1U)
  {
    /* use “%zu” to print the variables of size_t length. */
    printf("size of text1: %zu \n", sz1);
  }
}

int main(void)
{
  printf("f_17:\n");
  f_17("Tiny");
  f_17("Small");

  printf("\ng_17:\n");
  g_17();
}