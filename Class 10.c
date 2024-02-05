#include <stdio.h>
#include <stdlib.h>

// Valgrind: runs Python interpreter in C

int main()
{
    char *p = (char *)malloc(10000); // calloc() fills everything up with 0s
    free(p);                         // free memory
    printf("Value: %c\n", p[1000]);  // = *(p+1000)

    printf("%s\n", p + 10000 - 3); // in princilpe, if p[9997]
    // is not '\0\' and p[9998] is not '\0\',
    // will try to access p[9999] and p[10000], ...
    // will eventually access memory it's not supposed to access

    // block of int *
    // <address1> (of type int *), <address2> <- stored at address p_p_int

    // *p_p_int <- address1

    int **p_p_int;
    p_p_int = (int **)malloc(2 * sizeof(int *));
    // p_p_int is a block of int int *
    int *p_int = *p_p_int; // p_p_int[0] // *(p_p_int + 0) which is a type int*
    int my_int = *p_int;   // p_int[0] // *(p_int + 0)

    // segmentation fault: error trying to access memory that it cannot access
}