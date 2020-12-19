#include <string.h>

void *
memset(void *s, int c, size_t n)
{
	register void *r = s;
	for (; n--; s = (char *) s + 1)
		*(unsigned char *) s = (unsigned char) c;
	return r;
}
