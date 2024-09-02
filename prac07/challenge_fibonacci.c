#include <stdio.h>

int Fibonacci(int);

int main()
{
  int n, i = 0, c;
  printf("Enter the number of elements: ");

  scanf("%d", &n);

  printf("Fibonacci series\n");

  for (c = 1; c <= n; c++)
  {
    printf("%d\n", Fibonacci(i));
    i++;
  }

  return 0;
}

int Fibonacci(int n)
{
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return (Fibonacci(n - 1) + Fibonacci(n - 2));
}





















////////////////////////
// There are multiple safety rule violations in the code.  
// The major problem is that you should not use recursion. 
// The other major thing is that you should validate the input.  The code does not check the scanf return value.  scanf returns the number of successfully read items, so in this case it must return 1 for valid values. If not, an invalid integer value was entered and the num variable did probably not get changed (i.e. still has an arbitrary value because you didn't initialize it).

// Hint 1: In safety-critical programming, do not use recursive functions. You should rewrite this function without using recursion. 
// Hint 2: Declare one variable each line. You need to split this line of code into multiple lines: “int n, i = 0, c;” 

// Hint 3: Functions with no arguments shall explicitly specify void: use “int main (void)” instead.  
// Hint 4: Validate received values – user input scanf in main(), also check the size of n > SIZE_MAX in Fibonacci(). 
// Hint 5: Initialise variables before using them: initialise n and i
// Hint 6: Minimize the scope of variables and functions: declare and initialise variable c within the for loop, not outside the for loop. 
// Hint 7: Potential Integer overflow issues (if n is a big number in Fibonacci()) – check the Secure programming practical for more information on integer overflow. 
// Hint 8: In safe programming, a function should have one entry and one exit. Fibonacci() function has multiple ‘returns’ so should be changed. 