
#include <stdio.h>
#include "str.h"

int main()
{
	str_p p = new_str(" world!");
	write2_file_str("D:/Documents/GitHub/cstring/str/str/testfile", p);
	printf("%s", readin_file_str("D:/Documents/GitHub/cstring/str/str/testfile")->buffer);
	return 0;
}