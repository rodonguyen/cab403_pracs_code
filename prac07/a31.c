#include <stdio.h>
int main()
{
  int m, error;
  printf("Please specify the board height: \n");
  
  error = scanf("%d", &m);
  // validate input is an integer
  if (error != 1)
  {
    printf("Error: Invalid input. Please enter an integer\n");
    return 1;
  }

  // validate value
  if (m < 0)
  {
    printf("Error: The board height must be greater than 0\n");
    return 1;
  }


  printf("The board height is %d\n", m);
  return 0;
}



// int main()
// {
//   int m, error;
//   printf("Please specify the board height: \n");
//   error = scanf("%d", &m);

//   // validate integer input
//   if (error != 1)
//   {
//     printf("Error: Invalid input. Please enter an integer\n");
//     return 1;
//   }
//   // Validate value
//   if (m < 0)
//   {
//     printf("Error: The board height must be greater than 0\n");
//     return 1;
//   }

//   printf("The board height is %d\n", m);
  
// }
