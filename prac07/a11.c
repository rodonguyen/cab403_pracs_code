#include <stdio.h>

int main()
{
  int num;
  int sum = 0;

  do
  {
    printf("Sum so far: %d\n", sum);
    printf("Enter number: ");
    
    /* Read in an integer from the user
    
    If you enter a character instead of a number, the scanf function will fail to read the input as an integer. This failure causes the num variable to retain its previous value, which means it will not be equal to 0, and the loop will continue indefinitely. */
    scanf("%d", &num);
    
    /* Add num to sum */
    sum = sum + num;
  } while (num != 0);
  
  printf("FINAL TOTAL: %d\n", sum);

  return 0;
}
