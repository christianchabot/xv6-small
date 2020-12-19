#include <string.h>

char *
strncpy(char *restrict s1, const char *restrict s2, size_t n)
{
	register char *restrict x1;
	for (x1 = s1; n--; ++x1)
		if ((void) 0, *x1 = *s2) /* Leave (void) 0, for now. */
			++s2;
	return s1;
}
