#include <stdio.h>
#include <stdint.h>
#include <limits.h>

unsigned long Fibonacci(int);
// int Fibonacci(int);

int main(void)
{
  int number;
  printf("Enter the number of elements: ");

  int error = scanf("%d", &number);

  // validate integer input
  if (error != 1)
  {
    printf("Error: Invalid input. Please enter an integer\n");
    return 1;
  }
  // Validate value
  // if (number < 0)
  // {
  //   printf("Error: The input must be greater than 0\n");
  //   return 1;
  // }
  if (number < 0)
  {
    printf("Error: input exceed INT_MAX value (%d)\n", INT_MAX);
    return 1;
  }
  if (number > 94)
  {
    printf("Error: The fibonacci number will exceed the max of the used type (unsigned long)\n");
    return 1;
  }

  printf("Fibonacci series:\n");
  for (int i = 1; i <= number; i++)
  {
    printf("fib %d = %lu\n", i, Fibonacci(i-1));
    // printf("fib %d = %d\n", i, Fibonacci(i-1));
  }

  return 0;
}

// int Fibonacci(int n)
// {
//   if (n == 0)
//     return 0;
  
//   if (n == 1)
//     return 1;
  
//   // dynamic programming
//   int previous_fib_number = 0;
//   int fib_number = 1;
//   int temp;

//   // next number = previous number + previous previous number
//   for (int i = 2; i <= n; i++)
//   {
//     temp = fib_number;
//     fib_number = fib_number + previous_fib_number;
//     previous_fib_number = temp;
//   }
//   return fib_number;
// }

/////////////////////////////////////////////////
// https://leetcode.com/problems/fibonacci-number/description/ 



unsigned long Fibonacci(int n)
{
  if (n >= 0 && n < 2)
    return n;
  
  unsigned long previous_fib_number = 0;
  unsigned long fib_number = 1;
  unsigned long temp;

  // next number = previous number + previous previous number
  for (int i = 2; i <= n; i++)
  {
    temp = fib_number;
    fib_number = fib_number + previous_fib_number;
    previous_fib_number = temp;
  }

  return fib_number;
}


// 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610

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