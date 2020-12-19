/* System call numbers */

/*
#define SYS_syscall     0
#define SYS_exit        1
#define SYS_fork        2
#define SYS_preadv      3
#define SYS_pwritev     4
#define SYS_openat      5
#define SYS_closeat     6
#define SYS_wait4       7
#define SYS_linkat      8
#define SYS_unlinkat    9
#define SYS_execve      10
#define SYS_fexecve     11
#define SYS_chdir       12
#define SYS_fchdir      13
#define SYS_mknodat     14
#define SYS_fchmodat    15
#define SYS_fchownat    16
#define SYS_getpid      17
#define SYS_mount       18
#define SYS_unmount     19
#define SYS_setuid      20
#define SYS_getuid      21
#define SYS_geteuid     22

#define SYS_pipe2       ...
#define SYS_dup3        ...
#define SYS_faccessat   ...
#define SYS_fstatat     ...
#define SYS_readlinkat  ...
#define SYS_renameat    ... // Might not need this one.
#define SYS_symlinkat   ...

#define SYS_sbrk      69

// Honourable mentions.
#define SYS_execve
*/

#define SYS_syscall 0
#define SYS_exit    1
#define SYS_fork    2
#define SYS_read    3
#define SYS_write   4
#define SYS_open    5
#define SYS_close   6
#define SYS_wait    7
#define SYS_link    8
#define SYS_unlink  9
#define SYS_chdir   10
#define SYS_mknod   11
#define SYS_getpid  12
#define SYS_getppid 13
#define SYS_kill    14
#define SYS_dup     15
#define SYS_pipe    16
#define SYS_fstat   17
#define SYS_exec    18
#define SYS_sbrk    19
#define SYS_uptime  20
#define SYS_mkdir   21
#define SYS_sleep   22
