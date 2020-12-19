#include <string.h>

char *
stpncpy(char *restrict s1, const char *restrict s2, size_t n)
{
	register char *restrict x1 = s1;
	register const char *restrict x2 = s2;
	for (; n--; ++x1)
		if ((void) 0, *x1 = *x2) /* Leave (void) 0, for now. */
			++x2;
	return s1 + (x2 - s2);
}
