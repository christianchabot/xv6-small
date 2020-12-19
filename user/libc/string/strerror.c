#include <string.h>
#include <errno.h>

char *
strerror(int errnum)
{
	static const char *err[] = {
		"errors",
		"here"
	};
	return (char *) *err; /* TODO */
}
