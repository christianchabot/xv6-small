#include <string.h>

int
strncmp(const char *s1, const char *s2, size_t n)
{
	register const char *e = s1 + n;
	for (; s1 < e && *s1; ++s1, ++s2)
		if (*(unsigned char *) s1 != *(unsigned char *) s2)
			return *(unsigned char *) s1 - *(unsigned char *) s2;
	return s1 < e ? *(unsigned char *) s1 - *(unsigned char *) s2 : 0;
}
