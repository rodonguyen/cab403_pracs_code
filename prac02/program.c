
#include <stdio.h>
#include <stdlib.h> // contains "atoi"

// #include <limits.h> // this is called header file
// #include <float.h>

#define arrayLength(array) (sizeof((array)) / sizeof((array)[0]))

// Task 3
#define PI 3.14159
#define circleArea(radius) (PI * radius * radius)

// Task 4
void *badFunction();

int main(int argc, char *argv[])
{
  //////////////////////// Task 2 /////////////////////////
  // printf("\nThe number of command line arguments is %d\n", argc);
  // printf("\nThe name of the program is %s\n", argv[0]);

  // // for (int index = 1; index < argc; index++)
  // // {
  // //   printf("Argument %d is %s\n", index, argv[index]);
  // // }

  // int sum = 0;
  // for (int index = 1; index < argc; index++)
  // {
  //   // parse string into integer
  //   sum += atoi(argv[index]);
  //   printf("Argument %d is %s\n", index, argv[index]);
  // }
  // printf("\nThe sum of the command line arguments is %d\n", sum);

  //////////////////////// Task 3 /////////////////////////
  // int arrayOne[] = {15, 22, 18, 34, 10};
  // int emptyArray[] = {};
  // printf("Length of array %ld", sizeof(emptyArray) / sizeof(emptyArray[0]));
  // printf("\nLength of array %ld", arrayLength(emptyArray));

  // float arrayTwo[] = {12.45, 18.34, 20.55, 13.12, 88.62, 100.12, 64.23, 99.99, 121.23};            // 9 elements
  // char arrayThree[] = {'m', 'a', 'c', 'r', 'o', 'd', 'e', 'f', 'i', 'n', 'i', 't', 'i', 'o', 'n'}; // 15 elements
  // int lengthArrayOne = arrayLength(arrayOne);
  // int lengthArrayTwo = arrayLength(arrayTwo);
  // int lengthArrayThree = arrayLength(arrayThree);
  // printf("\nThe length of arrayOne = %d\nThe length of arrayTwo = %d\nThe length of arrayThree = %d\n\n", lengthArrayOne, lengthArrayTwo, lengthArrayThree);

  // // exercise
  // float radiuses[] = {2.4, 3.5, 1.2, 4, 5};
  // for (int i = 0; i < arrayLength(radiuses); i++)
  // {
  //   printf("The area of the circle with radiuses %.2f is %.5f\n", radiuses[i], circleArea(radiuses[i]));
  // }

  // // manual input
  // for (int i=0; i < 3; i++) {
  //   float radius;
  //   printf("Enter the radius of the circle number %d: ", i+1);
  //   scanf("%f", &radius);
  //   printf("The area of the circle with radius %.5f is %.6f\n", radius, circleArea(radius));
  // }

  // Calculate the area of a circle with radius from command line argument
  // printf("The area of the circle with radius %.2f is %.5f\n", atof(argv[1]), circleArea(atof(argv[1])));

  ///////////////////// Task 4 /////////////////////
  // void *p = malloc(1000);
  // // have some code to do something here
  // p = malloc(1000);
  // // and it's very long so I forget to free the memory
  // p = malloc(1000);
  // free(p); // free the memory

  // then run valgrind to check for memory leaks:
  // valgrind --tool=memcheck --leak-check=yes ./program

  // // 1. Input the initial number of elements
  // int initialArrayLength;
  // printf("1. Enter the initial number of elements: ");
  // scanf("%d", &initialArrayLength);

  // int *pointer1 = malloc(sizeof(int) * initialArrayLength);

  // // 2. Input initial elements
  // printf("2. Enter the elements of the array, enter to confirm each element: \n");
  // for (int i = 0; i < initialArrayLength; i++)
  // {
  //   scanf("%d", &pointer1[i]);
  // }

  // // 3. Input the number of extra elements
  // printf("3. How many more slots you want to expand? ");
  // int extraArrayLength;
  // scanf("%d", &extraArrayLength);

  // // 4. Reallocate memory for the extra elements
  // int newLength = initialArrayLength + extraArrayLength;
  // pointer1 = realloc(pointer1, sizeof(int) * newLength); // realloc to keep the existing values that we already assigned

  // // NULL means failed memory allocation, could be due to insufficient memory
  // if (pointer1 == NULL)
  // {
  //   printf("Memory allocation failed\n");
  //   return 1;
  // }

  // // 5. Input extra elements
  // for (int i = initialArrayLength; i < newLength; i++)
  // {
  //   printf("Enter the value of the element at index %d: ", i);
  //   scanf("%d", &pointer1[i]);
  // }

  // // 6. Print the array
  // printf("The array is: ");
  // for (int i = 0; i < newLength; i++)
  // {
  //   printf("%d ", pointer1[i]);
  // }

  // // 7. Done, free the memory allocation. HAVE TO DO THIS TO AVOID MEMORY LEAKS.
  // free(pointer1);

  // // NOTE: Official Task 4 solution is prac02/dynamicMemory.c
  // // Obviously, the functions written in that file are not super well-written
  // // but they do the jobs. I would make the functions more atomic if I were to write them :)

  // /////////////////////// Task 5 /////////////////////
  // char word[6] = "Hello";
  // for (int i = 0; i < 10; i++)
  // {
  //   if (word[i] == '\0')
  //   {
  //     printf("\nThe null character is at index %d\n", i);
  //     break;
  //   }
  //   printf("%c", word[i]);
  // }

  // putchar('\n');
  // for (int i = 0; i < 6; i++)
  // {
  //   printf("%p ", &word[i]);
  // }

  char *cityPointer[4] = {"Toowong", "Chermside", "Taringa", "Indooroopilly"};
  // printf("%c\n", *cityPointer[1]);
  // printf("%p", cityPointer[1]);

  // // // temporary variable
  // int i, charIndex;
  // // print cities
  // for (i = 0; i < 4; i++)
  // {
  //   charIndex = 0;
  //   while (*(cityPointer[i] + charIndex) != '\0')
  //   {
  //     printf("%c at address ", *(cityPointer[i] + charIndex));
  //     printf("%p\n", cityPointer[i] + charIndex);
  //     charIndex++;
  //   }
  //   printf("Found the Null terminator at address %p\n", cityPointer[i] + charIndex);
  //   printf("\n");
  // }

  for (int i = 0; i < 45; i++)
  {
    if (*(cityPointer+i) == '\0')
    {
      printf("Found the null terminator at address %p\n", (cityPointer+i));
    }
    else
    {
      printf("%c at address %p\n", *(cityPointer+i), (cityPointer+i));
    }
  }

  putchar('\n');
  return 0;
}

void *badFunction()
{
  void *p = malloc(100); // allocate 100 bytes
  // free(p);              // free the memory
  p = malloc(200); // allocate 200 bytes
  return p;
}