#include <string.h>

size_t
strspn(const char *s1, const char *s2)
{
	register const char *x1;
	for (x1 = s1; *x1; ++x1) {
		register const char *x2;
		for (x2 = s2; *x2 && *x1 != *x2; ++x2)
				;
		if (!*x2)
			goto done;
	}
done:
	return x1 - s1;
}
