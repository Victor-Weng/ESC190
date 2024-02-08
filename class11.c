#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class11.h"

// a = "sadjfkdh"

// const char *str = "akjd";

void mystr_create(mystr *p_s, const char *str, int len)
{

    p_s->len = len; // same as (*p_s).len = len;

    // allocate p_s->str, and copy str to p_s->str
    // could instead say p_s->str = str, but then we would have to make sure that str is not deallocated
    // BUT: if str is a const char*, won't know that we're not
    // allowed to modify p_s->str (could crash program)
    // Also, don't know if need to free p_s->str later
    // p_s->str and str are now different pointers, but
    // with p_s->str = str, they are equal (so strings are aliases)

    p_s->str = (char *)malloc((len + 1) * sizeof(char)); // +1 for '\0'
    if (p_s->str == NULL)
    {
        printf("Malloc Failed\n");
        exit(1);
    }

    strcpy(p_s->str, str);
}

void mystr_cat(mystr *p_dest, const mystr *p_src)
{
    p_dest->str = (char *)realloc(p_dest->str,
                                  (p_dest->len + p_src->len + 1) * sizeof(char));
    if (p_dest->str == NULL)
    {
        printf("Realloc failed \n");
        exit(1);
    }
    p_dest->len += p_src->len;
    strcat(p_dest->str, p_src->str);
}

void mystr_destroy(mystr *p_s)
{
    free(p_s->str);
    p_s->str = NULL;
    p_s->len = 0;
}

int main()
{
    mystr s;
    mystr_create(&s, "EngSci", 6);
    // now s.str points to a block of memory that has "EngSci" in it, while s.len points to 6
    mystr praxis;
    mystr_create(&praxis, "PRAXIS!!!", 9);

    mystr_cat(&s, &praxis);
    printf("%s\n", s.str); // (&s)->str <=> (*(&s)).str

    // a->b is the same as (*a).b
    mystr_destroy(&s);
    mystr_destroy(&praxis);
}
