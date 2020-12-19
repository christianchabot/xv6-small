#include <string.h>

void *
memccpy(void *__restrict s1, const void *restrict s2, int c, size_t n)
{
	register unsigned char *restrict x1 = s1;
	register const unsigned char *restrict x2 = s2;
	while (n-- && (*x1 = *x2) != (unsigned char) c)
		++x1, ++x2;
	return *x1 == (unsigned char) c ? ++x1 : NULL;
}
