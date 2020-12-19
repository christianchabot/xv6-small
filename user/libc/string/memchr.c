#include <string.h>

void *
memchr(const void *s, int c, size_t n)
{
	for (; n--; s = (const char *) s + 1)
		if (*(const unsigned char *) s == (unsigned char) c)
			return (void *) s;
	return NULL;
}
