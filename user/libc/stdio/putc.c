#include <unistd.h>

void
putc(int fd, char c)
{
  write(fd, &c, 1);
}
