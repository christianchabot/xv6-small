#include <string.h>

char *
strstr(const char *s1, const char *s2)
{
	for (; *s1; ++s1) {
		register const char *p1, *p2;
		for (p1 = s1, p2 = s2; *p1 && *p1 == *p2; ++p1, ++p2)
			;
		if (*p2 == '\0')
			return (char *) s1;
	}
	return NULL;
}
