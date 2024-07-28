#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void enterValuesIntoArr(int *ptr, int length);
void printOutArray(int *ptr, int length);
int askUserToIncreaseArraySize(int *ptr, int length);
void enterValuesIntoExistingArray(int *ptr, int totalSize, int start);

int main(int argc, char *argv[])
{
  int numElements = 0;
  int *arrOnePtr;

  // ask user to determine the array size
  printf("\nEnter the number of elements you want to store in an array - ");
  scanf("%d", &numElements);

  // allocate sufficient memory and check memory allocation is successful
  arrOnePtr = malloc(numElements * sizeof(int));
  if (arrOnePtr == NULL)
  {
    printf("\nMemory has not been successfully allocate\n");
    return EXIT_FAILURE;
  }
  else
  {
    printf("\nMemory successfully allocated - %ld bytes\n", numElements * sizeof(int));
  }
  enterValuesIntoArr(arrOnePtr, numElements);
  printOutArray(arrOnePtr, numElements);
  int newSize = askUserToIncreaseArraySize(arrOnePtr, numElements);
  enterValuesIntoExistingArray(arrOnePtr, newSize, numElements);
  printOutArray(arrOnePtr, newSize);
  return 0;
}

void enterValuesIntoExistingArray(int *ptr, int totalSize, int start)
{
  int input = 0;
  for (int i = start; i < totalSize; i++)
  {
    printf("\nEnter new value to append to array - ");
    scanf("%d", &input);
    ptr[i] = input;
  }
}

int askUserToIncreaseArraySize(int *ptr, int length)
{
  int additionalElements = 0;
  printf("The array currently contains %d integers.\nHow many more elements do you need to store in array - ", length);
  scanf("%d", &additionalElements);

  // reallocate memory for the additional elements
  ptr = realloc(ptr, (length + additionalElements) * sizeof(int));
  if (ptr == NULL)
  {
    printf("\nMemory was not successfully reallocated\n");
    return EXIT_FAILURE;
  }
  else
  {
    printf("\n\nMemory successfully allocated - Original array contained %d integers.\n\nArray now has sufficient memory for %d integers\n\n",
           length, (length + additionalElements));
  }
  return length + additionalElements;
}

void enterValuesIntoArr(int *ptr, int length)
{
  int val = 0;
  for (int i = 0; i < length; i++)
  {
    printf("\nEnter a value to store in array - ");
    scanf("%d", &val);
    ptr[i] = val;
  }
}

void printOutArray(int *ptr, int length)
{
  printf("\n\n");
  for (int i = 0; i < length; i++)
  {
    printf("array[%d] = %d || ", i, ptr[i]);
  }
  printf("\n\n");
}
