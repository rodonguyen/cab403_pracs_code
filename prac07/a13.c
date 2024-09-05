// // void fun() {}    // bad
// void fun(void) {}   // good

// int main(void)
// {
//   fun(10, "Haha", "Halo");
//   return (0);
// }

//////////////////////////////////////
#include <stdio.h>

int func1(int hi){}
int func2(void){}


int main(void)
{
    static int i = 5;
    if (--i){
        printf("%d ", i);
        func2(10);
    }
    printf("\n");
}
