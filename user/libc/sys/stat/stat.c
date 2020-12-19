#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int
stat(const char *n, struct stat *st)
{
	int fd, r;
	fd = open(n, O_RDONLY);
	if (fd < 0)
		return -1;
	r = fstat(fd, st);
	return close(fd), r;
}
