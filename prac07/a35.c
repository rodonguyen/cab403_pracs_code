/*
 * D.4.4
 *
 * Sections of code should not be 'commented out'
 */
#include <stdio.h>
#include <stdint.h>

int main ( void ) {
   int32_t a;
   /* a = 3; Non-compliant */
    a = 1;
   // a = 4; Non-compliant
    printf ( "%d \n", a );
}
/* end of D_04_04.c */