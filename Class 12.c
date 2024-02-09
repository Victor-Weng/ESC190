#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pyint.h"
void create_oyint(pyint *p, int length)
{
    p->buffer = (int *)malloc(length * sizeof(int)); // buffer is a pointer to an array of integers

    p->length = length;

    //initialize all the digits to 0

    int i;
    for (i = 0; i < length; i++)
    {
        p->buffer[i] = 0;
    }
    // or: use calloc
    // p->buffer = (int *)calloc(length, sizeof(int));
    // or: use memset
    // memset(p->buffer, 0, length * sizeof(int));
}

void set_pyint(pyint *p, int value)
{
    // value: 190
    // buffer: 0 9 1
    int i;
    // assume that the length is enough?
    while(value > 0)
    {
        if (i >= p->length)
        {
            printf("Error: buffer overflow\n");
            exit(1);
        }
        p->buffer[i] = value % 10; // get me the last digit in value 
        // and put it in the current position in the buffer
        value /= 10; // divide value by 10
        i++; // increment i
    }
}