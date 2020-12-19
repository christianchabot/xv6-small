#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#define RLIMIT_CORE  1
#define RLIMIT_CPU   2
#define RLIMIT_DATA  3
#define RLIMIT_FSIZE 4
#define RLIMIT_STACK 5
#define RLIMIT_AS    6

struct rlimit {
	unsigned long rlim_cur;
	unsigned long rlim_max;
};

#endif
