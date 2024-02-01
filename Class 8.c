#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Option: store everything inside the struct

typedef struct student1
{
    char name[50]; // analoguous to char name0, char name1, char name 2, ..., char name 49
    double gpa;
} student1;

// Option: store a pointer to name inside the struct
// Student2 takes up less space than student1, because
// storing char * takes up less space than storing char name[50]

typedef struct student2
{
    char *name;
    double gpa;
} student2;

int main()
{
    // array of student1's:
    student1 s1[150]; // 150 cells, store the info about the student in the cell

    // malloc-ed block of student1's
    student1 *s1_block = (student1 *)malloc(150 * sizeof(student1));
    // unlike s1, can return s1_block, because the address s1_block is valid until
    // we explicitly free it

    // array of student2's:
    student2 s2[150]; // 150 cells, store the info about the student in the cell
    // cannot say right now print("%s\n", s2[0].name), because s2[0].name is not
    // can say printf("%f\n", s2[0].gpa), because s2[0].gpa is valid

    s2[0].name = "John"; // fine but not allowed to modify s2[0].name[0] to 'j' because const* type

    // or

    s2[0].name = (char *)malloc(50 * sizeof(char));
    strcpy(s2[0].name, "John"); // fine
    // same as:
    // s2[0].name[0] = 'J';
    // s2[0].name[1] = 'o';
    // s2[0].name[2] = 'h';
    // s2[0].name[3] = 'n';
    // s2[0].name[4] = '\0';

    // malloc a block of pointers to student2's
    student2 **p_s2_block; // the address of the first element of the block of
                           // objects that are of type student2*
    int i;
    for(i = 0; i < 150; i++)
    {
        p_s2_block[i] = (student2 *)malloc(sizeof(student2));
        p_s2_block[i]->gpa = 4.0;

        p_s2_block[i]->name = (char *)malloc(50 * sizeof(char));
        strcpy(p_s2_block[i]->name, "John");

        // p_s2_block[i]->name = "John"; // fine (but weird, how do you know it's "John")

    }

    // What we did:
    // *Allocated space to store

    /*

    PYTHONNN equivalant:
    
    L = [ {"name":"Alice", "gpa":3.5} ,
          {"name":"Bob", "gpa":3.7} ]

    L is stored at address 10000
    L[0] is at 2000, L[1] is at 3000

    "Alice" is stored at 5000
    3.9 is stored at 6000
    "Bob" is stored at 7000
    3.7 is stored at 8000

    2000 {"name":@5000, "gpa":@6000}
    3000 {"name":@7000, "gpa":@8000}

    10000 L = [@2000,@3000]
    
    */

}