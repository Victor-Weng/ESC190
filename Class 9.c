#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Realloc:
//can resize blocks of memory using realloc

/*
char*str = (char *)malloc(100* sizeof(char)); // want to make more space
str = (char *)realloc(str, 200 * sizeof(char));
// when making malloc space smaller, it might free up the memory
// that was removed (depending on the operating system)    

// Error Checking: malloc and realloc might not be able to find the amount of space you need


char *block = malloc(100000000);  if (block == NULL);

printf("Out of memory\n"); exit(1); 
*/ 

/*
exit terminates the program. The 1 is sent to the operating system.
Why exit()? Unclear what to do otherwise: trying to access a NULL pointer will lead to
a crash without an error message
But e.g. MS Word might just display an error message, refuse to do what you asked it to
(e.g. open a huge document), and continue running
-> The programs we are writing don't have the get input-> do what the user
asks -> get more input loop, so we just crash as gracefully as we can
*/ 

/*
SHOULD YOU DO ERROR CHECKING?

No error checking -> program may crash without a specific error message
Program crashing may take down the whole computer with it
For software that's intended to be used by others, the answer is YES
But if the point is to demonstrate a language feature in C, or to 
demonstrate a proof-of-concept implementation of an algorithm, error checking
might just obfuscate the code

Final note on pointers: Make sure the types (units) match 
e.g. int matches to an int
int* matches to an int*

A pointer is a variable that stores a memory address
*/



void create_str(char **p_str, int sz) // declaration, p_str is a pointer to a pointer of a char type
{
    *p_str = (char*)malloc(sz*sizeof(char)); 
    // declaration: *p_str is type char*. set pointer to the char* pointer to be a malloc block

    if (*p_str == NULL) // if malloc could not find memory space, set to NULL
    {
        printf("Could not create malloc space");
        exit(1);
    }

    (*p_str)[0] = '\0'; // Set the first address of char* pointer to '\0'
}


// str: of type char* in main
// p_str: address of str, of type char**
// &str == p_str of type char**


void change_int(int *p_int)
{
    *p_int = 5;
}

void change_int_p(int **p_p_int)
{
    *p_p_int = malloc(sizeof(int));
    // ptr[0] is the same as *ptr
}

void safer_strcat(char **p_str1, char *str2)
{
    // Need enough space at *p_str1 to hold both str1 and str2
    // Need strlen(*p_str1) + strlen(str2) + 1 bytes for the '\0' char

    //strlen() does not count the null character at the end

    *p_str1 = (char *)realloc(*p_str1, strlen(*p_str1) + strlen(str2) + 1);
    if(*p_str1 == NULL)
    {
        printf("Safer strcat failed to allocate memory\n");
        exit(1);
    }
}

int main()
{
    char *str = 0; // declaration: the pointer to string (variable storing adress) is 0
    create_str(&str, 100); // str is char*   &str is address of (char* type str). 
    // a.k.a. address of a pointer variable
    return 0;
}


/*
strcat(str1, str2) concatenates str1 and str2, assuming that str1 has enough
space to accomodate extra characters from str2
Will crash if not enough space: it does not check
Again: C prioritizes efficiency

*/