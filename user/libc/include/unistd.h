#ifndef _UNISTD_H_
#define _UNISTD_H_

/*
typedef unsigned long int size_t;
typedef long int ssize_t;
typedef int uid_t;
typedef int gid_t;
typedef int pid_t;

#ifndef C89
typedef long long int off_t;
typedef long long int intptr_t;
#else
typedef long int off_t;
typedef long int intptr_t;
#endif
*/

/* Syscalls for now. */
int chdir(const char *);
int close(int);
int dup(int);
int exec(char *, char **);
int exit(void) __attribute__((noreturn));
int fork(void);
int getpid(void);
int getppid(void);
int link(const char *, const char *);
int pipe(int *);
int read(int, void *, int);
char *sbrk(int);
int sleep(int);
int write(int, const void *, int);
int unlink(const char *);
int uptime(void);

int getopt(int, char *const [], const char *);
extern char *optarg;
extern int optind, opterr, optopt;

#endif
