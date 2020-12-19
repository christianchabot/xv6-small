#include <string.h>

char *
strcat(char *restrict s1, const char *restrict s2)
{
	register char *restrict x1 = s1;
	while (*x1)
		++x1;
	return strcpy(x1, s2), s1;
}
