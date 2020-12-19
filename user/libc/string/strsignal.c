#include <string.h>

char *
strsignal(int signum)
{
	static const char *esig[] = {
		"error",
		"sigs",
		"here"
	};
	return (char *) *esig; /* TODO */
}
