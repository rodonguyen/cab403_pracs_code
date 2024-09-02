// // void fun() {}    // bad
// void fun(void) {}   // good

// int main(void)
// {
//   fun(10, "Haha", "Halo");
//   return (0);
// }

//////////////////////////////////////
#include <stdio.h>

// int main()
int main(void)
{
    static int i = 5;
    if (--i){
        printf("%d ", i);
        main(10);
    }
    printf("\n");
}
