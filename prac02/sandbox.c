
#include <stdio.h>
// #include <stdlib.h>
// #include <limits.h> // this is called header file
// #include <float.h>
#include <string.h>

int main()
{

  int *p = (int*) 1000; // 0x3e8
  printf("%p", p);

  // struct person
  // {
  //   char *name;
  //   int id;
  // };

  // int favNum;
  // struct person student = {"John", 105};

  // struct node {
  //   int data;
  //   struct node* next; // ok, here I want an address (of the next node)
  // };

  
  

  // // copy an array
  // int arrayOne[5] = {1, 2, 3, 4, 5};
  // int arrayTwo[5];
  // // Method 1
  // // for (int index = 0; index < 5; index++)
  // //   arrayTwo[index] = arrayOne[index];

  // // Method 2
  // memcpy(arrayTwo, arrayOne, sizeof(int) * 5);
  // for (int index = 0; index < 5; index++)
  //   printf("%d ", arrayTwo[index]);

  // putchar('\n');

  // /////////////////////////////////////////////////
  // // copy a string
  // char stringOne[] = "Hello";
  // char stringTwo[6];
  // strcpy(stringTwo, stringOne);
  // for (int index = 0; index < 6; index++)
  //   printf("%c", stringTwo[index]);

  // /////////////////////////////////////////////////
  // // try to access 3rd by +3 to the pointer with char[]. When adding 3 to the pointer,
  // // it knows the size of the data type and it will add to the address by
  // // the according size of 1 items multiplied by 3.
  // char greeting[] = "Hello";
  // char *ptr = greeting;
  // printf("\n%c", *(ptr + 3));

  // int nums[] = {1, 2, 3, 4, 5};
  // int *ptr2 = nums;
  // printf("\n%d", *(ptr2 + 3));

  // putchar('\n');
  return 0;
}