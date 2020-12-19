#include <string.h>

char *
strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	register char *restrict x1 = s1;
	while (*x1)
		++x1;
	return strncpy(x1, s2, n), s1;
}
