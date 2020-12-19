#ifndef _CONFIG_H_
#define _CONFIG_H_

/* Only define directives are allowed here. */

/* Configure the library here. */
#define XSI
#define CX

/* #define C89 For C89 compatible library. */

#ifdef C89
#define restrict

/* Need to define some values to be long rather then long long (off_t, etc). */
#endif

#endif
