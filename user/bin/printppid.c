#include <stdio.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	printf(1, "parent pid: %d\n", getppid());
	exit();
}
