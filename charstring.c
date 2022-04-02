#include "charString.h"

cstring_p cnew(const char *string)
{
    cstring_p p = (cstring_p)malloc(sizeof(cstring_t));
    if (!p)
        ;
    p->size = csizeof(string);
    p->buffer = (char *)malloc(p->size);
    if (!p->buffer)
        ;
    for (size_t i = 0; i < p->size; i++)
    {
        p->buffer[i] = string[i];
    }
    return p;
}

void cdelete(cstring_p p)
{
    if (p->buffer)
        free(p->buffer);
    if (p)
        free(p);
    p->buffer = NULL;
    p = NULL;
    return;
}

cstring_p ccopy(const cstring_p p)
{
    return cnew(p->buffer);
}

size_t csize(const cstring_p p)
{
    return p->size;
}

cstring_p cinit(size_t size)
{
    cstring_p p = (cstring_p)malloc(sizeof(cstring_t));
    if (!p)
        ;
    p->size = size;
    p->buffer = (char *)calloc(size, sizeof(char));
    return p;
}

cstring_p creverse(const cstring_p p)
{
    cstring_p q = cinit(p->size);
    if (p->size)
    {
        for (size_t i = 0; i < p->size - 1; i++)
        {
            q->buffer[i] = p->buffer[p->size - 2 - i];
        }
        q->buffer[p->size - 1] = '\0';
    }
    return q;
}

size_t csizeof(const char *string)
{
    if (!string)
        return 0;
    size_t i = 1;
    while (*string != '\0')
    {
        i++;
        string++;
    }
    return i;
}