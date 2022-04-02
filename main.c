#include <stdio.h>
#include "charString.h"

int main()
{
    cstring_p p = cnew(NULL);

    cstring_p q = creverse(p);
    printf("%lu", q->buffer);
    return 0;
}