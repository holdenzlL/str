#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char *buffer;
    size_t size;
} str;

typedef str *str_p;

// destroy a string
void free_str(str_p p);
// create a new string
str_p new_str(const char *string);
// copy construction
str_p cpy_str(const str_p p);
// get the size
size_t sizeof_buff(const char *string);
// return the size
size_t size_str(const str_p p);
// create and initialize an str
str_p zero_str(size_t size);
// reverse
str_p revs_str(const str_p p);
// overwrite a string
str_p overwrite_str(str_p p, const char *string);
// swap
void swp_str(str_p p, str_p q);
// compare lexicographically
int cmp_str(const str_p p, str_p q);
// read a whole file into str
str_p readin_file_str(const char *filename);