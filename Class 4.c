#include <stdio.h> // so you are able to print
// Variable declaration in C (review)

int main()
{
    int a = 42;
    long int la = 2109827234234231L;
    char c = '@';

    char s = "abs";
    char *p_a = &p_a;

    // Arrays in C

    int arr[] = {5, 10, 2}; // can use braces in initialization but not elsewhere
    arr[0] = 3;

    //cannot say: arr = {1, 2, 3}; can only use {} notation for initialization

    return 0;
}


// Functions

int add(int a, int b) // input prameters
{
    return a + b;
}

// Functions and pointers

int f(int *p_a)
{
    *p_a = 43;
    return 0;
}
// the function f takes an address, and puts 43 there

// analogous to passing a list in Python


// Arrays and pointers
// When used, arrays are generally converted to the pointer to the first element
// a[0] is the same as *(a+0), the first element of a