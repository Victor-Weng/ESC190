#include <stdio.h>

void change_a(int *p_a)
{
    *p_a = 43; // changes the value at the address of a
}

void dont_change_a(int p_a)
{
    p_a = 44; // does not change the value at the address of a as
    // the funciton makes a local copy and changes the value, ignoring the original value
}

void swap(int* p_x, int* p_y)
{
    int temp = *p_x; // put the value of x into a temporary storage
    *p_x = *p_y; // make the value of x the value of y
    *p_y = temp; // make the value of y the initial value of x (from temporary storage)

    // Analogy
    /*
    office_swap9officenumber1, officenumber2):
        put the person in officenumber1 in the hallway
        put the person in officenumber2 in officenumber1
        put the person in the hallway in officenumber2

        BA2028       BA2030
        Michael      Morgan

        office_swap(&Michael, &Morgan)

    */

}

void set_arr0(int *arr)
{
    arr[0] = 44; // same as *arr = 44 b/c arr[j] is syntactic sugar for *(arr + j)
}

void set_arr1(int *arr)
{
    arr[1] = 42;
}

void set_arr2(int *arr)
{
    *(arr + 2) = 99; // sinze int takes up 2 slots. sizeof(int) doesnt return an integer, but an 
    // "unsigned integer value" so it doesn't work
}

int main()
{

    int arr[] = {5, 6, 7};
    set_arr0(arr); // arr[0] is now 44

    printf("After changing arr[0]: %d\n", arr[0]);

    set_arr1(arr); // arr[1] is now 42

    printf("After changing arr[1]: %d\n", arr[1]);

    set_arr2(arr); // arr[2] is now 99 with alternative method

    printf("After changing arr[2]: %d\n", arr[2]);

    int a = 42;
    // want to change a to 43
    change_a(&a); // the value is now 43
    printf("Changed a: %d\n", a);
    // do not want to change a to 43, pass-by-value instead of passes in the pointer
    dont_change_a(a);
    printf("Non-changed a: %d\n", a);

    int x = 43;
    int y = 44;
    //swap(x, y) // no way to make this work
    // instead:
    swap(&x, &y);
}

/*
Review: strings in C

C does not have strings
char s1[] = "abc"; // an array of type char, with the characters 'a', 'b','c', '\0'
// shorthand char s1[] = {'a', 'b', 'c', '\0'};

char *s2 = "abc"; // put the block 'a','b','c','\0' somewhere in memory
// s2 is the address where 'a' is stored

Difference: an array is generally a local variable, only exists while the funciton is running.
s2 stores the address of a memory block that will persist in memory.

=================================

const char*

the literal "abc" is actually of type const char *
The compiler will not let you modify values at adresses of type const char *
But it will let you convert const char* to char * and then try to modify the values at the memory address

char *s1 = "abc"; // warning: implicit conversion to char*
s1[0] = 'x'; // will compile, but might crash at runtime
const chhar *s2 = "xyz"; // compiles with no warnings
s2[0] = 'y'; // will not compile

=================================

const int a = 42;
a = 43; // error

const char c = 'x';
c = 'y'; // error

=================================

char *const

char *const str = "hello";
str = "world"; //errpr
str[0] = 'H'; // OK

=================================

Why are string literals constant?

May be more efficient: if you use the same literal in several different places, the compiler can choose 
to only store one copy

But now all the copies are aliases, so dangerous to modify one
Can unintentionally modify several strings at once

May be more cost-efficient: might like to store the string as an area of memory that is literally
"write-only"

*/