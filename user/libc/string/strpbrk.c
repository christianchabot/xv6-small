#include <string.h>

char *
strpbrk(const char *s1, const char *s2)
{
	for (; *s1; ++s1) {
		register const char *p;
		for (p = s2; *p; ++p)
			if (*p == *s1)
				return (char *) s1;
	}
	return NULL;
}
