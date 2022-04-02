#include <stdlib.h>
#include <stdio.h>
typedef struct
{
    char *buffer;
    size_t size;
} cstring_t;

typedef cstring_t *cstring_p;

// destroy a string
void cdelete(cstring_p p);
// create a new string
cstring_p cnew(const char *string);
// copy construction
cstring_p ccopy(const cstring_p p);
// get the size
size_t csizeof(const char *string);
// return the size
size_t csize(const cstring_p p);
// initialization
cstring_p cinit(size_t size);
// reverse
cstring_p creverse(const cstring_p p);
