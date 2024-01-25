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

// Q5. Define a function that takes in a pointer to an integer and changes the integer
// Answer:

void change_int(int *p_a)
{

    *p_a = 12;
}

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

// Q16. Write a function that takes in a pointer to the first element of an array of
// integers and modifies the element at index 2 to 8
// Answer:

void q16(int *thing)
{
    thing[2] = 8;
}

void main()
{
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
    q11(p_block);
    printf("%d\n", p_block);
}

// Q21. Create a an object of type student and initialize it
// Answer:

// Q22. Change the name of the student to "Jennifer"
// Answer:

// Q23. Change the age of the student to 21
// Answer:

// Q24. Create a pointer p_s to the student and initialize it to the address of the student
// Answer:

// Q25. Change the name of the student to "Jenny", using p_s
// Answer:

// Q26. Change the age of the student to 20, using p_s
// Answer:

// Q27. Create a function that takes in a pointer to a student and changes the name to "Jenny"
// Answer:

// Q28. Create a function that takes in a pointer to a student and changes the age to 20
// Answer:

// Q29. Call the function from (27) in order to change the name of the student to "Jenny". Use p_s but not s
// Answer:

// Q30. Call the function from (28) in order to change the age of the student to 20. Use s but not p_s
// Answer:

// Q31. Create an array of 5 student objects
// Answer:

// Q32. User the functions from change_name and change_age on the element at index 2 of the array
// Answer:

// Q33. Create a malloc-allocated block of memory that can store 5 students. Store it in the variable p_block_s
// Answer:

// Q34. Make a function that takes in a pointer to an address of student, and sets that pointer to point to a new address where a student can be stored
// Answer:

// Q35. Call the function from (34) in order to change the value of p_block_s to point to a new address
// Answer:

// Q36. Call the function from (27) in order to change the name of the student at index 2 of the block of memory from (33). Use p_block_s
// Answer:

// Q37. Create a variable p_p_s to store the address of p_block_s
// Answer:

// Q38. Without calling any function except strcpy, and using only p_p_s, change the name of the student at index 2 to "Jennifer"
// Answer:

// Q39. In the name of the second student in the block pointed to by p_p_s, change the first letter to 'j' Propose four valid to do that with one line that don't involve calling a function
// Answer:

// Q40. Write a function that takes in a pointer to the first element of a block of addresses of students, and changes the name of the student at index 2 to "Jenny"
// Answer:

// Q41. Call the function from (40) in order to change the name of the student at index 2. Use p_block_s
// Answer:

// Q42. Call the function from (40) in order to change the name of the student at index 2. Use p_p_s
// Answer:

// Q43. Write a function that takes in the first address of a student in a block of addresses of students, and changes the name of the student at index 2 to "Jenny"
// Answer:

// Q44. Call the function from (43) in order to change the name of the student at index 2. Use p_block_s
// Answer:

// Q45. Call the function from (43) in order to change the name of the student at index 2. Use p_p_s
// Answer:
