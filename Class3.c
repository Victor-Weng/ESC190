#include <stdio.h>

int main()
{ // K&R style: curly brace goes on the next line after the function head

    // before we use a variable, we need to declare it
    // optionally, you can also initialize it (assigning initial value)

    // int a = 5;
    int b; // integer, declared, but not initialized. Almost 100% of the time, you want to initialize it

    // double, char (e.g. '@'), int*, char*

    // printf("Hello, World!")

    char *s1 = "hi!"; // Puts "hi!", followed by '\0' in memory
                      // stores the address of "h" in s1

    // %s: string (i.e., the sequence of characters at the given address, up until '\0')
    // %d: integer (d stands for decimal)
    // %ld: long decimal (another type of integer, which stores more data than the usual integer)
    printf("%s\n", s1); // interpret s1 as a string, prints "hi!"

    printf("%ld\n", s1); // interpret s1 as a long decimal, prints the address (a number) of "hi!" e.g. 647372637383

    printf("Thr string is : %s, the address is : %ld\n", s1, s1);

    int a = 43;
    printf("The integer is : %d\n", a); // prints the number

    printf("The string is : %s\n", a); // treats a as an address so we print whatever value is at the memory address
    // 43 which is likely not available

    char c = '@';

    // error: char c1 = '28373738282922';

    // error: char c1 = "abc";

    ///////// Second Part ///////////

    int aa = 42;
    int bb;            // non-initialized
    char *c11 = "abc"; // string needs to be char* double quotes and char needs to be single quote and just a character
                       // difference between char* ans char:
                       // char* stores the address of where a is, char stores the value of the character

    char cc = '@';
    double dd = 3.14;

    printf("The itneger is : %d\n", aa);
    printf("The character is : %c\n", cc);
    printf("The double is : %f\n", dd);
    printd("The char is : %c\n", cc);

    int *p_a = &aa; // p_a is a variable of type int*
    // p_a stores an address of an int
    // &a; the address in the memory table where aa is stores
    // p_a stores the address of aa

    printf("The address of a is %ld\n", p_a); // e.g. 727263737288261

    // *p_a stores the value stored at the address p_a

    printf("The value of a is: %d\n", *p_a); // e.g. 42
    printf("The value of a: %d\n", a);

    // addresses of values are referred to as pointers

    double x = 12.34;
    double *address_of_var_x = &x;
    double y = 25 + *address_of_var_x; // y is 25 + 12.32

    // * is USED IN TWO DIFFERENT WAYS

    char *s1 = "hello!";
    // * is used part of thr type char *

    char c = *s1; // c is 'h'
    // * is used as a "dereferencing operator" to get the value at the given address

    // same thematically by referencing pointers and addresses, but completrly separate uses

    return 0;
}