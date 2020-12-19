#include <string.h>

size_t
strnlen(const char *s, size_t maxlen)
{
	register const char *p;
	for (p = s; maxlen && *p; ++p)
		--maxlen;
	return p - s;
}
