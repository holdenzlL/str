#include "str.h"

str_p new_str(const char *string)
{
    str_p p = (str_p)malloc(sizeof(str));
    if (!p)
        return NULL;
    p->size = sizeof_buff(string);
    p->buffer = (char *)malloc(p->size);
    if (!p->buffer)
    {
        p->size = 0;
        free(p);
        return NULL;
    }
    for (size_t i = 0; i < p->size; i++)
    {
        p->buffer[i] = string[i];
    }
    return p;
}

void free_str(str_p p)
{
    if (p->buffer)
        free(p->buffer);
    if (p)
        free(p);
    p->size = 0;
    p->buffer = NULL;
    p = NULL;
    return;
}

str_p cpy_str(const str_p p)
{
    return new_str(p->buffer);
}

size_t size_str(const str_p p)
{
    return p->size;
}

str_p zero_str(size_t size)
{
    str_p p = (str_p)malloc(sizeof(str));
    if (!p)
        return NULL;
    p->size = size;
    p->buffer = (char *)calloc(size, sizeof(char));
    if (!p->buffer)
    {
        p->size = 0;
        free(p);
        return NULL;
    }
    return p;
}

str_p revs_str(const str_p p)
{
    str_p q = zero_str(p->size);
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

size_t sizeof_buff(const char *string)
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

str_p overwrite_str(str_p p, const char *string)
{
    free_str(p);
    return new_str(string);
}

void swp_str(str_p p, str_p q)
{
    const str_p tmp = p;
    *p = *q;
    *q = *tmp;
    return;
}

int cmp_str(const str_p p, str_p q)
{
    const int n = memcmp(p->buffer, q->buffer, (p->size < q->size) ? p->size : q->size);

    if (n != 0 || p->size == q->size)
        return n;

    return (p->size < q->size) ? -1 : 1;
}

str_p readin_file_str(const char *filename)
{
    FILE *fp;
    long size;

    fp = fopen(filename, "rb");
    if (!fp)
    {
        perror("Error opening file");
        return NULL;
    }
    size = ftell(fp);
    fseek(fp, 0, SEEK_END);
    str_p p = zero_str((size_t)size);

    if (size != fread(p->buffer, 1, size, fp))
    {
        perror("Error reading file");
        free_str(p);
        return NULL;
    }
    fclose(fp);
    return p;
}