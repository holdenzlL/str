#include <stdio.h>
#include "str.h"

int main()
{
    str_p p = readin_file_str("testfile");
    printf("%s", p->buffer);
    return 0;
}