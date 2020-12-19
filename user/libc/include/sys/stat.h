#ifndef _STAT_H_
#define _STAT_H_

struct stat {
	short type;
	int dev;
	unsigned int ino;
	short nlink;
	unsigned int size;
};

int stat(const char *, struct stat *);
int fstat(int fd, struct stat *);
int mkdir(const char *);
int mknod(const char *, short, short);

#endif
