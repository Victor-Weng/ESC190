#include <stdio.h>

double sum(double x, double y)
{
    return x + y;
}

void change_a(int *p_a) // the function doesn't return anything
{
    *p_a = 44; // go to address p_a and change the value there to 44
}

int memoryexample()
{
    int a = 5;
    int *p_a = &a;
    printf("%d %ld %d %d\n", a, p_a, *p_a, *&p_a);
    // Output: 5 1032 5 2048
    // if at address 1032 there is the value 5, and at address 2048, the pointer to 1032 is stored
}

int changearr()
{
    int a[] = {5, 6, 7};
    a[0] = 6;
    int *p = a;
    print("%d %d", a[0], *p); // Output: 6 6
}

void f(int *aa)
{
    aa[0] = 7;
}

int main()
{
    int a[] = {5, 6, 7};
    a[0] = 6;
    int *p = a;
    f(a);                 // calls function that passes in pointer and changes the value
    printf("%d\n", a[0]); // Output: 7
}

int main()
{
    int a = 42;
    printf("%d\n", a); // Problems are found before running since it won't compile.

    int *b = &a;

    double s = sum(1.2, 3.4);
    printf("%f\n", s);

    printf("%ld\n", *b); // prints 42

    char *str = "hello";
    printf("%s is stored at address %ld\n", str, (long int)str);

    // casting: "converting" between types
    // in quotes, because it does the same thing as
    // printf with the wrong type: interpret the data
    // as if it were in the type I say
    // (int) 1.2 -> 1 (truncates)
    // (long int)str : just the address of the first element of str

    int arr[] = {5, 6, 7};
    printf("%d\n", arr[0]); // 5
    printf("%ld\n", arr);   // the address where the array starts
                            // the location of the 5

    printf("%d\n", *arr); // 5 (*arr is the same as arr[0] in a more elaborate way,)
                          // the same as *(arr + 0)

    char *str2 = "hello";
    printf("%c\n", str2[0]);     // h
    printf("%c\n", *str2);       // h
    printf("%c\n", *(str2 + 0)); // h   since it takes the pointer value at str2 and adds 0, which
    // is the same pointer value so it doesn't change anything

    // changing a:

    int aa = 43;
    int *p_aa = &aa; // p_aa is the address of aa
    change_a(p_aa);  // change the value at p_aa.
    // warning here because you need to declare the function change_a() before you call it
    // or else it is considered an implicit declaration. (I moved it above the main function)
    printf("%ld\n", *p_aa);

    memoryexample();
}
