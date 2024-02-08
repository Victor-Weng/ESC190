#include <stdio.h>
#include "class11.h"

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