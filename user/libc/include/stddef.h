#ifndef _STDDEF_H_
#define _STDDEF_H_

#ifndef NULL
#define NULL ((void *) 0)
#endif
#ifndef offsetof
#define offsetof(st, m) ((size_t)((char *)&((st *)0)->m - (char *)0))
#endif

typedef long ptrdiff_t
typedef long wchar_t
typedef unsigned long size_t;

#endif
