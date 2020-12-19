#include <unistd.h>

extern ssize_t _read(int, void *, size_t);

ssize_t
read(int fd, void *buf, size_t n)
{
	ssize_t r;
	r = _read(fd, buf, n);
	return r;
}
