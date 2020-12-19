#include <string.h>

void *
memmove(void *s1, const void *s2, size_t n)
{
	register char *x1 = s1;
	register const char *x2 = s2;
	if (x2 >= x1)
		for (; n--; ++x1, ++x2)
			*x1 = *x2;
	else
		for (x1 += n, x2 += n; n--;)
			*--x1 = *--x2;
	return s1;
}
