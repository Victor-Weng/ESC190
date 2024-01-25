#include <stdio.h>

// Q0 (not graded)
//===========
// Make sure that you can run and compile a Hello World program in VS Code.

// Q1
//===
// Write the function 

void print_arr(int *arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int linear_search(int *a, int sz, int elem)
{
    /*
    The function returns the index of the first occurrence of the element
    elem in a block of ints a of size sz. Assume elem occurs in a.
    */
    int i = 0;

    while (a[i] != elem)
    {
        i++;
    }

    return i;
}

// Q2
//====
// Write the following function

void reverse_arr(int *arr, int sz)
{
    /*
    which reverses the block of ints arr, which is of size sz.
    For example, if arr starts out as {5, 6, 7, 8}, it should become {8, 7, 6, 5}
    */

    int *temp = (int *)malloc(sz * sizeof(int));

    for (int i = sz - 1; i >= 0; i--)
    {
        temp[sz - 1 - i] = arr[i];
    }

    //print_arr(temp, sz);

    for (int j = 0; j < sz; j++)
    {
        arr[j] = temp[j];
    }
}

void main()
{
    int sz = 9;
    int arr[] = {0, 1, 2, 8, 4, 2, 6, 6, 8};

    /*
    printf("%d\n", linear_search(arr, sz, 5));

    printf("Before reverse:\n");
    print_arr(arr, sz);
    reverse_arr(arr, sz);

    printf("After reverse:\n");
    print_arr(arr, sz);
    printf("\n");
    */
}