#include <stdio.h>
#include <stdlib.h>

void printarr(int *arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

// Q1. Define an integer variable a and initialize it to 42

int a = 42;

// Q2. Define a pointer to an integer variable p_a and initialize it to the address of a

int *p_a = &a;

// Q3. Using p_a and without directly using a, change the value of a to 43
// Answer:

*p_a = 43;

// Q4. Change the value of the pointer p_a to something else. Make sure that the value of a does not change
// Answer:

int b = 43;
p_a = &b;

// Q5. Define a function that takes in a pointer to an integer and changes the integer
// Answer:

void change_int(int *p_a)
{

    *p_a = 12;
}

// Q6. Call the function from Q5 and pass in the address of a. Make sure that the value of a changes
// Answer:

printf("%d\n", *p_a);
change_int(&a);
printf("%d\n", *p_a);

// Q7. Call the function named change_int without directly using a, but using p_a instead
// Answer:

change_int(p_a);

// Q8. Define a variable that would store the address of p_a
// Answer:

// Q9. Make p_p_a point to p_a
// Answer:

int **pp_a = &p_a;

// Q10. Write a function that takes in a pointer to a pointer to an integer and changes the value of the integer to 46
// Answer:

void q10(int **pp)
{
    **pp = 46;
}

// Q11. Write a function that takes in a pointer to a pointer to an integer and
// changes the value of the pointer to a new address where an integer can be stored.
// (You will need to use malloc)
// Answer:

void q11(int **pp)
{
    *pp = (int *)malloc(sizeof(int));
}

// Q12. Call the function from (10) in order to change the value of a to 46. Do this using p_p_a, and using p_a
// Answer:

q10(pp_a);
printf("%d\n", *p_a);

// Q13. Call the function from (11) in order to change the value of p_a to point to a new address. Don't use p_p_a
// Answer:

printf("%d\n", p_a);
q11(&p_a);
printf("%d\n", p_a);

// Q14. Call the function from (11) in order to change the value of p_a to point to a new address. Use p_p_a
// Answer:

printf("%d\n", p_a);
q11(pp_a);
printf("%d\n", p_a);

// Q15. Declare an array of integers and initialize it to {5, 6, 7}
// Answer:

int arr[] = {5, 6, 7};

// Q16. Write a function that takes in a pointer to the first element of an array of
// integers and modifies the element at index 2 to 8
// Answer:

void q16(int *thing)
{
    thing[2] = 8;
}

// Q17. Call the function from (16) in order to change the value of the array from (15)
// Answer:

printarr(arr, 3);
q16(arr);
printarr(arr, 3);

// Q18. Create a malloc-allocated block of memory that can store 3 integers.
// Store it in the variable p_block. Then use change_arr to change the value at index 2
// Answer:

int *p_block = (int *)malloc(3 * sizeof(int));
printarr(p_block, 3);
q16(p_block);
printarr(p_block, 3);

// Q19. Use change_int from (5) to change the value of the integer stored in the
// block of memory from (18)
// Answer:

change_int(p_block);
printarr(p_block, 3);

// Q20. Use change_int_ptr from (11) to change the value of p_block to point to a new address
// Answer:

printf("%d\n", p_block);
q11(&p_block);
printf("%d\n", p_block);

// Q21. Create a an object of type student and initialize it
// Answer:

typedef struct student
{
    char name[100];
    int age;

} student;


// Q22. Change the name of the student to "Jennifer"
// Answer:

student s1;

strcpy(s1.name, 'Jennifer'); // Need to use strcpy() because arrays in C are not assignable

// Q23. Change the age of the student to 21
// Answer:

s1.age = 21; // this is ok because integers are not arrays so are assignable

// Q24. Create a pointer p_s to the student and initialize it to the address of the student
// Answer:

student *p_s = &s1; // type student pointer

// Q25. Change the name of the student to "Jenny", using p_s
// Answer:

// need to use strcpy again because changing array

strcpy((*p_s).name, "Jenny");
// so p_s is a student* which is equal to &s1, which is why *p_s is equal to *&s1 which is s1

// Q26. Change the age of the student to 20, using p_s
// Answer:

(*p_s).age = 20;

// Q27. Create a function that takes in a pointer to a student and changes the name to "Jenny"
// Answer:

void toJenny(student *p_s)
{
    strcpy((*p_s).name, "Jenny");
}

// Q28. Create a function that takes in a pointer to a student and changes the age to 20
// Answer:

void to20(student *p_s)
{
    (*p_s).age = 20;
}

// Q29. Call the function from (27) in order to change the name of the student to "Jenny". Use p_s but not s
// Answer:

toJenny(p_s);

// Q30. Call the function from (28) in order to change the age of the student to 20. Use s but not p_s
// Answer:

to20(&s1);

// Q31. Create an array of 5 student objects
// Answer:

student arr[5];

// Q32. Use the functions from change_name and change_age on the element at index 2 of the array
// Answer:

toJenny(arr + 1);
toAge(arr + 1);

// Q33. Create a malloc-allocated block of memory that can store 5 students. Store it in the variable p_block_s
// Answer:

student *p_block_s = malloc(5 * sizeof(student));

// Q34. Make a function that takes in a pointer to an address of student, and sets that pointer
// to point to a new address where a student can be stored
// Answer:

void q34(student **p_s)
{
    *p_s = malloc(1 * sizeof(student));
}

// Q35. Call the function from (34) in order to change the value of p_block_s to point to a new address
// Answer:

q34(&p_block_s);

// Q36. Call the function from (27) in order to change the name of the student at index 2 of the block of memory
// from (33). Use p_block_s
// Answer:

q27(p_block_s + 2);

// Q37. Create a variable p_p_s to store the address of p_block_s
// Answer:

student **p_p_s = &p_block_s;

// Q38. Without calling any function except strcpy, and using only p_p_s, change the name of
// the student at index 2 to "Jennifer"
// Answer:

strcpy((*(*p_p_s + 2)).name, "Jennifer");
// or
strcpy((*p_p_s + 2)->name, "Jennifer");

// Q39. In the name of the second student in the block pointed to by p_p_s,
// change the first letter to 'j' Propose four valid to do that with one line that don't involve calling a function
// Answer:

((*p_p_s)[1]).name[0] = 'j';
(*p_p_s + 1)->name[0] = 'j';
(*(*p_p_s + 1)).name[0] = 'j';
p_p_s[0][1].name[0] = 'j';

// Q40. Write a function that takes in a pointer to the first element of a block of addresses
// of students, and changes the name of the student at index 2 to "Jenny"
// Answer:

void q40(student **pp)
{
    strcpy(*(*pp + 2).name, "Jenny");
    // or
    strcpy((*pp + 2)->name, "Jenny");
}

// Q41. Call the function from (40) in order to change the name of the student at index 2. Use p_block_s
// Answer:

q40(&p_block_s);

// Q42. Call the function from (40) in order to change the name of the student at index 2. Use p_p_s
// Answer:

q40(p_p_s);

// Q43. Write a function that takes in the first address
// of a student in a block of addresses of students, and changes the name of the student at index 2 to "Jenny"
// Answer:

void q43(student *p)
{
    strcpy((*p + 2).name, "Jenny");
    // or
    strcpy((p + 2)->name, "Jenny");
    // or
    strcpy(p[2].name, "Jenny");
}

// Q44. Call the function from (43) in order to change the name of the student at index 2. Use p_block_s
// Answer:

q43(p_block_s);

// Q45. Call the function from (43) in order to change the name of the student at index 2. Use p_p_s
// Answer:

q43(*p_p_s);

// ADDITIONAL QUESTIONS:

    // Q46. Create a pointer to a pointer to a student and initialize it to the address
    // of the first student in the block of students

    // Create a pointer to a pointer to a student and initialize it to the address
    // of the first student in the block of students solution: 
    student **pp = &p_block_s;

    // Q47. Change the name of the student at index 2 to "Jenny" using the pointer to 
    // a pointer to a student

    // Change the name of the student at index 2 to "Jenny" using the pointer to 
    // a pointer to a student solution:
    strcpy((*(*pp + 2)).name, "Jenny");


void main()
{
    // TESTING

    // Testing code for Q_1

    // Testing code for Q_2

    // Testing code for Q_3

    // Testing code for Q_4

    // Testing code for Q_5

    // Testing code for Q_6

    // Testing code for Q_7

    // Testing code for Q_8

    // Testing code for Q_9

    // Testing code for Q_10

    // Testing code for Q_11

    // Testing code for Q_12

    // Testing code for Q_13

    // Testing code for Q_14

    // Testing code for Q_15

    // Testing code for Q_16

    // Testing code for Q_17

    // Testing code for Q_18

    // Testing code for Q_19

    // Testing code for Q_20

    // Testing code for Q_21

    // Testing code for Q_22

    // Testing code for Q_23

    // Testing code for Q_24

    // Testing code for Q_25

    // Testing code for Q_26

    // Testing code for Q_27

    // Testing code for Q_28

    // Testing code for Q_29

    // Testing code for Q_30

    // Testing code for Q_31

    // Testing code for Q_32

    // Testing code for Q_33

    // Testing code for Q_34

    // Testing code for Q_35

    // Testing code for Q_36

    // Testing code for Q_37

    // Testing code for Q_38

    // Testing code for Q_39

    // Testing code for Q_40

    // Testing code for Q_41

    // Testing code for Q_42

    // Testing code for Q_43

    // Testing code for Q_44

    // Testing code for Q_45

    // Testing code for Q_46
    

}
