#include <string.h>

size_t
strlen(const char *s)
{
	register const char *p = s;
	while (*p)
		++p;
	return p - s;
}
