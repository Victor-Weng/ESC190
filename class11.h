#if !defined(MYSTR_H)
#define MYSTR_H

typedef struct mystr
{
    char *str;
    int len;

} mystr;

void mystr_create(mystr *p_s, const char *str, int len);
void mystr_cat(mystr *p_dest, const mystr *p_src);
void mystr_destroy(mystr *p_s);

#endif