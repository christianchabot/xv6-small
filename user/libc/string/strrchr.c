#include <string.h>

char *
strrchr(register const char *s, int c)
{
	register const char *p = NULL;
	do {
		if (*s == (char) c)
			p = s;
	} while (*s++);
	return (char *) p;
}
