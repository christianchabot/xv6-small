#ifndef _STDARG_H_
#define _STDARG_H_

/*
Portable assumptions for using stdarg.h:
	- The variadic function must declare at least one fixed argument.
	- The function must call va_end before returning (for cleanup on
	some architectures)
	- va_arg can deal only with those types that become pointers by
	appending "*" to them. Thus register variables, functions, and
	arrays can't be returned by va_arg
	- If a type widens with default argument promotions, then va_arg
	should request the widened type (using int or double rather than
	char or float respectively)
*/

/*
This header is gross will need compiler builtins.
Look for portable alternatives or writing assembly for
each supported architecture.
*/

/*
Should use the compiler specific macros here.

GCC, clang, etc:
#define va_start(ap, argN) __builtin_va_start(ap, argN)
#define va_arg(ap, type) __builtin_va_arg(ap, type)
#define va_end(ap) __builtin_va_end(ap)
typedef __builtin_va_list va_list;

Others:
...

*/


#ifdef REQUIRE_ALIGNMENT_4_BYTE
/*
Some architectures have alignment requirements.
Tweaked macros for those architectures.
 */
#define __va_ceil(addr) (va_list) (((uintptr_t) (addr) & ~3) + ((uintptr_t) (addr) & 3) ? 4 : 0)
#define __va_floor(addr) (va_list) ((uintptr_t) (addr) & ~3)
#define va_start(ap, argN) (void) ((ap) = __va_ceil((char *) &param + sizeof(param)))
#define va_arg(ap, type) (*(type *) __va_floor(((ap) = __va_ceil((ap) + sizeof(type))) - sizeof(type)))
#else
/* Portable macros. */
#define va_start(ap, argN) (void) ((ap) = (char *) &(argN) + sizeof(argN))
#define va_arg(ap, type) (*(type *) (((ap) = (ap) + sizeof(type)) - sizeof(type)))
#endif

#define va_end(ap) (void) ((ap) = (void *) 0)

#ifdef C99
#define va_copy(dest, src) (void) ((dest) = (src))
#endif

typedef char *va_list;

#endif
