#include <string.h>

int
memcmp(const void *s1, const void *s2, size_t n)
{
	register const char *e = s1 + n, *p1 = s1, *p2 = s2;
	for (; p1 < e; ++p1, ++p2)
		if (*(unsigned char *) p1 != *(unsigned char *) p2)
			return *(unsigned char *) p1 - *(unsigned char *) p2;
	return 0;
}
