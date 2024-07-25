#include <stdio.h>
// #include <stdlib.h>
#include <limits.h>   // this is called header file
// #include <float.h>

#define PI 3.14159

int sumNumbers(int x, int y)
{
  return x + y;
}
// float calculateCylinderVolume(float radius, float height);
// void swapVariables(int *pnt1, int *pnt2);

int main()
{
  // // ====================================================================================
  //   Task 1
  //   printf("Hello world! This is captain speaking.\n");
  //   return 0;  // Ctrl + ` => Open the terminal

  // // ====================================================================================
  // Task 2
  // Type size discovery
  //   char *char_ptr;
  //   int *int_ptr;
  //   long *long_ptr;
  //   short *short_ptr;
  //   float *float_ptr;   // 0.21312
  //   double *double_ptr; // 0.21312

  //   struct my_struct_name
  //   {
  //     char letter;
  //     int favorite_number;
  //     int not_my_favorite_number;
  //   } test_struct;

  //   printf("\n Type             Size (byte) ");
  //   printf("\n==========================");
  //   printf("\n character         %zu ", sizeof(char));
  //   printf("\n integer           %zu ", sizeof(int));
  //   printf("\n short             %zu ", sizeof(short));
  //   printf("\n long              %zu ", sizeof(long));
  //   printf("\n float             %zu ", sizeof(float));
  //   printf("\n double            %zu ", sizeof(double));
  //   printf("\n char pointer      %zu ", sizeof(char_ptr));
  //   printf("\n int pointer       %zu ", sizeof(int_ptr));
  //   printf("\n short pointer     %zu ", sizeof(short_ptr));
  //   printf("\n long pointer      %zu ", sizeof(long_ptr));
  //   printf("\n float pointer     %zu ", sizeof(float_ptr));
  //   printf("\n double pointer    %zu ", sizeof(double_ptr));
  //   printf("\n test_structure    %zu ", sizeof(test_struct));
  //   printf("\n==========================");

  // // int *p1;
  // // p1 = (int *) 1;

  // // print the addresses of char_ptr, int_ptr, long_ptr
  // char my_char = 'A';
  // int my_int = 10;
  // long my_long = 1000000;

  // printf("\n\n my_char address: %p", &my_char);
  // printf("\n my_int address: %p", &my_int);
  // printf("\n my_long address: %p", &my_long);

  // // a bit about struct
  // test_struct = (struct my_struct_name){'A', 10};
  // printf("\n test_structure.letter = %c", test_struct.letter);
  // printf("\n test_structure.favorite_number = %d", test_struct.favorite_number);

  // printf("\n The minimum possible value for an int is %d and max is %d", INT_MIN, INT_MAX);
  // Try to figure out the maths behind the min/max of int. Hint: look at the sizeof int.
  // 4 bytes = 32 bits = 2^32 = 4294967296 (half positive, number 0 is in the positive gang, half negative)
  // 4294967296 / 2 = 2147483648

  // 59b + 1 = 59c + 4 = 5a0 (hexadecimal)
  // CIIIILLLLLLLL


  // // ====================================================================================
  // Task 3
  // By the way, what does that <limits.h> really do?

  /* Declares an integer variable to hold the number read in */
  int num;
  /* Declares an integer variable to hold the sum */
  int sum;
  /* Initialise the sum */
  sum = 0;
  do
  {
    printf("Sum so far: %d\n", sum);
    printf("Enter number: ");
    /* Read in an integer from the user */
    scanf("%d", &num);
    /* Add num to sum */
    sum = sum + num;
  } while (num != 0);

  printf("FINAL TOTAL: %d\n\n", sum);

  // // ====================================================================================
  // Task 5
  // printf("Maximum integer positive value: %d\n", INT_MAX);
  // printf("Maximum unsigned integer value: %u\n", UINT_MAX);
  // printf("Maximum short signed integer value: %hi\n", SHRT_MAX);
  // printf("Minimum short signed integer value: %hi\n", SHRT_MIN);
  // printf("Maximum signed long value: %li\n", LONG_MAX);
  // printf("Maximum unsigned long value: %lu\n", ULONG_MAX);

  // printf("Storage size for float : %zu \n", sizeof(float));
  // printf("Minimum float positive value: %E\n", FLT_MIN);
  // printf("Maximum float positive value: %E\n", FLT_MAX);
  // printf("Precision value: %d\n", FLT_DIG);

  // printf("Max value for char : %d \n", CHAR_MAX);
  // printf("Min value for char : %d \n", CHAR_MIN);

  // // https://www.asciitable.com/
  // printf("\n\n");

  // char myChar = 'r';
  // int num = 72; /* 65 is the ASCII encoding for 'A' */
  // printf("The value printed is %c\n", num);
  // printf("The value printed is %d\n", num + 3);
  // printf("The value printed is %c\n", num + 3);

  // printf("The value printed is %c\n", myChar + 5);
  // printf("The value printed is %c\n", 224); // this char is in extended ASCII table so maybe... we need to install something to help terminal to display it
  // printf("\n\n");

  // // ====================================================================================
  // Task 6
  // int a, b, result;
  // printf("Enter two integers separated by a space: ");
  // scanf("%d%d", &a, &b);
  // result = sumNumbers(a, b);
  // printf("\nThe sum of %d and %d is %d\n", a, b, result);

  // // solve challenge
  // // const float PI = 3.14159;  i switch to using pre-processor definition so that the outside function (i.e. calculateCylinderVolume) can access it
  // float radius, height;
  // printf("Enter the radius and height of the cylinder separated by a space: ");
  // scanf("%f%f", &radius, &height);
  // printf("The volume of the cylinder: %.5f\n", calculateCylinderVolume(radius, height));
  printf("\n\n");

  // // ====================================================================================
  // Task 7

  // //     variable name => storing              value
  // //   * variable name => storing address of a value
  // //  ** variable name => value stored in the address of a value
  // int a = 45;
  // int b = 22;
  // int *p1;
  // int *p2;

  // /* & symbol tells p1 and p2 to point to the memory address where a and b is stored respectively */
  // p1 = &a; // we are getting address of a in the memory and store it in p1
  // p2 = &b;
  // /*
  // To print the value in the memory location that pointer is pointing to we need to use the dereferencing operator *
  // */

  // //                         decimal                               pointer
  // printf("The value of p1 is %d and the memory address location is %p\n", *p1, p1);
  // printf("The value of p2 is %d and the memory address location is %p\n", *p2, p2);
  // printf("The value of a is %d and the memory address location is %p\n", a, &a);

  // // Task 7 continue
  //   int a = 45;
  //   int b = 22;
  //   int *p1 = 0;
  //   int *p2 = 0;

  //   /* & symbol tells p1 and p2 to point to the memory address where a and b is stored respectively */
  //   p1 = &a;
  //   p2 = &b;
  //   // To print the value in the memory location that pointer is pointing to we need to use the dereferencing operator
  //   printf("The value of p1 is %d and the memory address location is %p\n", *p1, p1);
  //   printf("The value of p2 is %d and the memory address location is %p\n", *p2, p2);
  //   swapVariables(&a, &b);
  //   printf("The value of p1 is %d and the memory address location is %p\n", *p1, p1);
  //   printf("The value of p2 is %d and the memory address location is %p\n", *p2, p2);

  // Q: What has been swapped? Have the memory addresses of the pointers been swapped
  // or the values held in the memory addresses been swapped. => the latter

  // void *ptr;
  // char g = 'A';
  // int h = 2;
  // float j = 3;
  // ptr = &g;
  // printf("\nThe value of g = %c\n", *((char *)ptr));
  // ptr = &h;
  // printf("\nThe value of h = %d\n", *((int *)ptr));
  // ptr = &j;
  // printf("\nThe value of j = %f\n", *((float *)ptr));
  // printf("\n\n");

  return 0;
}

void swapVariables(int *pnt1, int *pnt2)
{
  int temp = 0;
  temp = *pnt1;
  *pnt1 = *pnt2;
  *pnt2 = temp;
}

/**
 * Calculates the volume of a cylinder.
 * @param radius The radius of the cylinder.
 * @param height The height of the cylinder.
 * @return The volume of the cylinder. */
float calculateCylinderVolume(float radius, float height)
{
  return PI * radius * radius * height;
}