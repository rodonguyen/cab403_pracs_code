
#include <stdio.h>
#include <stdlib.h>
// #include <limits.h> // this is called header file
#include <float.h>


#define arrayLength(array) (sizeof((array)) / sizeof((array)[0]))

// Task 3
#define PI 3.14159
#define circleArea(radius) (PI * (radius) * (radius))

// Task 4
void * badFunction();

int main(int argc, char *argv[])
{
  //////////////////////// Task 1 /////////////////////////
  // printf("\nThe number of command line arguments is %d\n", argc);
  // printf("\nThe name of the program is %s\n", argv[0]);

  // int remainingArguments = argc - 1;
  // for (int index = 1; index <= remainingArguments; index++)
  // {
  //   printf("Argument %d is %s\n", index, argv[index]);
  // }

  //////////////////////// Task 3 /////////////////////////
  int arrayOne[] = {15, 22, 18, 34, 1, 10};                                                        // 6 elements
  float arrayTwo[] = {12.45, 18.34, 20.55, 13.12, 88.62, 100.12, 64.23, 99.99, 121.23};            // 9 elements
  char arrayThree[] = {'m', 'a', 'c', 'r', 'o', 'd', 'e', 'f', 'i', 'n', 'i', 't', 'i', 'o', 'n'}; // 15 elements
  int lengthArrayOne = arrayLength(arrayOne);
  int lengthArrayTwo = arrayLength(arrayTwo);
  int lengthArrayThree = arrayLength(arrayThree);
  printf("\nThe length of arrayOne = %d\nThe length of arrayTwo = %d\nThe length of arrayThree = %d\n\n", lengthArrayOne, lengthArrayTwo, lengthArrayThree);

  // exercise
  float radiuses[] = {2.4, 3.5, 1.2, 4, 5};
  for (int i=0; i < arrayLength(radiuses); i++) {
    printf("The area of the circle with radiuses %.2f is %.5f\n", radiuses[i], circleArea(radiuses[i]));
  }
  // // manual input
  // for (int i=0; i < 2; i++) {
  //   float radius;
  //   printf("Enter the radius of the circle number %d: ", i+1);
  //   scanf("%f", &radius);
  //   printf("The area of the circle with radius %.5f is %.6f\n", radius, circleArea(radius));
  // }
  
  ///////////////////// Task 4 /////////////////////
  // void *p = badFunction();
  // then run valgrind to check for memory leaks:
  // valgrind --tool=memcheck --leak-check=yes ./program 

  // 1. 
  int *pointer1 = malloc(sizeof(int) * 5);

  for (int i=0; i < 5; i++) {
    scanf("%d", &pointer1[i]);
  }

  // 2.
  printf("Enter the number of elements to be added to the array: ");
  int extraElementNum;
  scanf("%d", &extraElementNum);
  
  pointer1 = realloc(pointer1, sizeof(int) * (5 + extraElementNum));
  if (pointer1 == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }
  for (int i=5; i < 5+extraElementNum; i++) {
    printf("Enter the value of the element %d: ", i);
    scanf("%d", &pointer1[i]);
  }

  // 5. Done, free the memory allocation
  free(pointer1);

  // NOTE: Official Task 4 solution is prac02/dynamicMemory.c

  
  /////////////////////// Task 5 /////////////////////

  return 0;
}

void * badFunction() {
      void *p = malloc(100); // allocate 100 bytes 
      p = malloc(200); // allocate 200 bytes
      return p;
}