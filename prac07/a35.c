

/* In foo.h */
void foo();

/* In foo.c */
void foo() {
 int i = 3;
 printf("i value: %d\n", i);
}


/* In caller.c */
#include "foo.h"
foo(3);


////////////////////////////
// /* In foo.h */
// void foo(void);

// /* In foo.c */
// void foo(void)
// {
//   int i = 3;
//   printf("i value: %d\n", i);
// }