#ifndef _STDIO_H_
#define _STDIO_H_

#define O_RDONLY 0x000

int atoi(const char *);
char *gets(char *, int);
void printf(int, const char *, ...);
void putc(int, char);

#endif
