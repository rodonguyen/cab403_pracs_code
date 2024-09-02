#include <stdint.h>
#include <stdio.h>

extern func2 (void *argument);

void func2 (void *argument){
    int i;
    int a[] = {1, 2, 3};  //predefine an array with three elements of type integer
    int n = sizeof (a) / sizeof (int); // variable n is assigned with the number of elements of array a, which is 3.
    for (i = 0; i<=n; i++){  // count from the first index of an array, 0, up to n, which is now 3. 
        argument = (void*) a[i];
    }
}


// void func2(void *argument)
// {
//   int i;
//   int a[] = {1, 2, 3};             // predefine an array with three elements of type integer
//   int n = sizeof(a) / sizeof(int); // variable n is assigned with the number of elements of array a, which is 3.
//   for (i = 0; i < n; i++)
//   { // count from the first index of an array, 0, up to n, which is now 3.
//     argument = (void *)a[i];
//   }
// }

// int main(void)
// {
//   func2(a);
//   return 0;
// }