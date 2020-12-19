#ifndef _TYPES_H_
#define _TYPES_H_

/* This header is subject to change. */

typedef long int blksize_t;
typedef int clockid_t;
typedef int dev_t;
typedef int gid_t;
typedef int id_t;
typedef unsigned long int ino_t;
typedef int key_t;
typedef int mode_t;
typedef long int nlink_t; /* Might be able to be unsigned. */
typedef int pid_t;
/* pthread typedefs here. */
typedef unsigned long int size_t;
typedef long int ssize_t; 
typedef int timer_t;
/* Obsolete trace typedefs here. */
typedef int uid_t;

#ifndef C89
typedef long long int blkcnt_t;
typedef long long int clock_t;
typedef unsigned long long int fsblkcnt_t;
typedef unsigned long long int fsfilcnt_t;
typedef long long int off_t;
typedef long long int suseconds_t;
typedef long long int time_t;
#else
typedef long int blkcnt_t;
typedef long int clock_t;
typedef unsigned long int fsblkcnt_t;
typedef unsigned long int fsfilcnt_t;
typedef long int off_t;
typedef long int suseconds_t;
typedef long int time_t;
#endif

#endif
