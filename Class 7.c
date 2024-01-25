#include <stdio.h>

int *f() // returns pointer
{
    int arr[20];
    arr[0] = 42;
    return arr;
}

int *make_block_int(int sz)
{
    int *p = (int *)malloc(sz * sizeof(int));
    if (p == NULL)
    { // malloc returns 0 if there is no memory / error
        // use malloc to create something in local then use it / keep it outside of it back in global
        // You can't change size of arrays, but you can change size of mallocs using re-alloc

        printf("out of memory\n");
        exit(1);
    }
    return p;
}

// Structs

typedef struct student
{
    char name[200];
    int age;
} student; 

/*

typedef is also commonly used with structures
to avoid having to use the struct keyword when declaring variables. For example:

Now you can declare a Student variable like this:

Student s1;

Instead of like this:

struct Student s1;

Remember, typedef does not create a new type. It only creates a new name for an existing type.
The compiler treats the new name exactly the same as the original name.

*/

// Sometimes, want to change the value of a pointer inside a function

void set_to_0(int **p_p_a)
{
    *p_p_a = 0; // set the value at address p_p_a to 0
                // p_p_a happens to be of type int **
                // so *p_p_a is of type int *
}

int main()
{
    int *p = f();
    p[0]; // undefined behavior
          // might crash, because no guarantee of memory
          // might sometimes print 42
          // AVOID
    int *q = make_block_int(20);
    q[7] = 50; // works

    //===========================//===========================//===========================

    // array:
    student students[500]; // type student
    student *students_block = (student *)malloc(sizeof(student) * 500);

    // Dealing with Strings
    char s1[] = "hi"; // same as char s1[] = {'h', 'i', '\0'};
    char *s2 = 0;

    // if "hi" is stored at addresses 1032, 1033, 1034
    // if the address of 'h' is 1032, and s1 gets converted to 1032 when used

    s2 = s1; // legal, but strings are now aliases. Make s2 equal to s1 (1032).
    // s2 and s1 store the same value, which is the address of the 'h' from "hi"

    strcpy(s2, s1); // not yet OK, since cannot copy to address s2
                    // same as s2[0] = s1[0], s2[1] = s1[1], ….
    s2 = (char *)malloc(sizeof(char) * (strlen(s1) + 1));
    strcpy(s2, s1); // copy the contents of s1 into s2

    //===========================//===========================//===========================

    int a = 42;
    int *p_a = &a;
    set_to_0(&p_a); // p_a is now 0. a is not affected!
}

/*
Free function

Good practice to free() memory blocks to you allocated
C cannot use a malloc-ed block for something new until its freed
For continuously running programs, you might run out of memory (if you keep mallocing and not freeing)
On a modern OS, everything will be freed fater the program terminates
On less modern OS (older operating systems), or on very light OSs, it might not be the case
Memory leak: a situation where memory is allocated but never freed

*/
