#include <string.h>

void *
memcpy(void *restrict s1, const void *restrict s2, size_t n)
{
	register char *restrict p1 = s1;
	register const char *restrict p2 = s2;
	for (; n; --n)
		*p1++ = *p2++;
	return s1;
}
