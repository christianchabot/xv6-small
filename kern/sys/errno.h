#ifndef _ERRNO_H_
#define _ERRNO_H_

/* freebsd and netbsd errno values. */

#define ESUCCES         0 /* Unused. */
#define EPERM           1
#define ENOENT          2
#define ESRCH           3
#define EINTR           4
#define EIO             5
#define ENXIO           6
#define E2BIG           7
#define ENOEXEC         8
#define EBADF           9
#define ECHILD          10
#define EDEADLK         11

#define ENOMEM          12
#define EACCES          13
#define EFAULT          14
#define ENOTBLK         15 /* Block device required. */
#define EBUSY           16
#define EEXIST          17
#define EXDEV           18
#define ENODEV          19
#define ENOTDIR         20
#define EISDIR          21
#define EINVAL          22
#define ENFILE          23
#define EMFILE          24
#define ENOTTY          25
#define ETXTBSY         26
#define EFBIG           27
#define ENOSPC          28
#define ESPIPE          29
#define EROFS           30
#define EMLINK          31
#define EPIPE           32

/* math software */
#define EDOM            33
#define ERANGE          34

/* non-blocking and interrupt i/o */
#define EAGAIN          35
#define EWOULDBLOCK     EAGAIN
#define EINPROGRESS     36
#define EALREADY        37

/* ipc/network software -- argument errors */
#define ENOTSOCK        38
#define EDESTADDRREQ    39
#define EMSGSIZE        40
#define EPROTOTYPE      41
#define ENOPROTOOPT     42
#define EPROTONOSUPPORT 43
#define ESOCKTNOSUPPORT 44 /* Socket type not supported. */
#define EOPNOTSUPP      45
#define EPFNOSUPPORT    46 /* Protocol family not supported. */
#define EAFNOSUPPORT    47
#define EADDRINUSE      48
#define EADDRNOTAVAIL   49

/* ipc/network software -- operational errors */
#define ENETDOWN        50
#define ENETUNREACH     51
#define ENETRESET       52
#define ECONNABORTED    53
#define ECONNRESET      54
#define ENOBUFS         55
#define EISCONN         56
#define ENOTCONN        57
#define ESHUTDOWN       58 /* Can't send after socket shutdown. */
#define ETOOMANYREFS    59 /* Too many references: can't splice */
#define ETIMEDOUT       60
#define ECONNREFUSED    61

#define ELOOP           62
#define ENAMETOOLONG    63

/* should be rearranged */
#define EHOSTDOWN       64 /* Host is down. */
#define EHOSTUNREACH    65
#define ENOTEMPTY       66

/* quotas & mush */
#define EPROCLIM        67 /* Too many processes. */
#define EUSERS          68 /* Too many users. */
#define EDQUOT          69 /* Disc quota exceeded. */

/* Network File System */
#define ESTALE          70 /* Stale NFS file handle. */
#define EREMOTE         71 /* Too many levels of remote in path. */
#define EBADRPC         72 /* RPC struct is bad. */
#define ERPCMISMATCH    73 /* RPC version wrong. */
#define EPROGUNAVAIL    74 /* RPC prog. not avail. */
#define EPROGMISMATCH   75 /* Program version wrong. */
#define EPROCUNAVAIL    76 /* Bad procedure for program. */

#define ENOLCK          77
#define ENOSYS          78
#define EFTYPE          79 /* Inappropriate file type or format. */
#define EAUTH           80 /* Authentication error. */
#define ENEEDAUTH       81 /* Need authenticator. */

/* SystemV IPC */
#define EIDRM           82
#define ENOMSG          83
#define EOVERFLOW       84

/* NetBSD values behond. FreeBSD adds weird error values like EDOOFUS */

/* Wide/multibyte-character handling, ISO/IEC 9899/AMD1:1995. */
#define EILSEQ          85

/* From IEEE Std 1003.1-2001. */
/* Base, Realtime, Threads or Thread Priority Scheduling option errors. */
#define ENOTSUP         86

/* Realtime option errors. */
#define ECANCELED       87

/* Realtime, XSI STREAMS option erors. */
#define EBADMSG         88

/* XSI STREAMS option errors. */
#define ENODATA         89
#define ENOSR           90
#define ENOSTR          91
#define ETIME           92

/* File system extended attribute errors. */
#define ENOATTR         93 /* Attribute not found. */

/* Realtime, XSI STREAMS option errors. */
#define EMULTIHOP       94
#define ENOLINK         95
#define EPROTO          96

/* Robust mutexes. */
#define EOWNERDEAD      97
#define ENOTRECOVERABLE 98
#define ESIZ            99

/* POSIX */

/*
#define E2BIG           // Argument list too long.
#define EACCESS         // Permission denied.
#define EADDRINUSE      // Address in use.
#define EADDRNOTAVAIL   // Address not available.
#define EAFNOSUPPORT    // Address family not supported.
#define EAGAIN          // Resource unavailable, try again (same as EWOULDBLOCK).
#define EALREADY        // Connection already in progress.
#define EBADF           // Bad file descriptor.
#define EBADMSG         // Bad message.
#define EBUSY           // Device or resource busy.
#define ECANCELED       // Operation cancelled.
#define ECHILD          // No child processes.
#define ECONNABORTED    // Connection aborted.
#define ECONNREFUSED    // Connection refused.
#define ECONNRESET      // Connection reset.
#define EDEADLK         // Resource deadlock would occur.
#define EDESTADDRREQ    // Destination address required.
#define EDOM            // Mathematics argument out of domain of function.
#define EDQUOT          // Reserved.
#define EEXIST          // File exists.
#define EFAULT          // Bad address.
#define EFBIG           // File too large.
#define EHOSTUNREACH    // Host is unreachable.
#define EIDRM           // Identifier removed.
#define EILSEQ          // Illegal byte sequence.
#define EINPROGRESS     // Operation in progress.
#define EINTR           // Interrupted function.
#define EINVAL          // Invalid argument.
#define EIO             // I/O error.
#define EISCONN         // Socket is connected.
#define EISDIR          // Is a directory.
#define ELOOP           // Too many levels of symbolic links.
#define EMFILE          // File descriptor value too large.
#define EMLINK          // Too many links.
#define EMSGSIZE        // Message too large.
#define EMULTIHOP       // Reserved.
#define ENAMETOOLONG    // Filename too long.
#define ENETDOWN        // Network is down.
#define ENETRESET       // Connection aborted by network.
#define ENETUNREACH     // Network unreachable.
#define ENFILE          // Too many files open in system.
#define ENOBUFS         // No buffer space available.
#define ENODATA         //OB No message is available on the STREAM head read queue.
#define ENODEV          // No such device.
#define ENOENT          // No such file or directory.
#define ENOEXEC         // Executable file format error.
#define ENOLCK          // No locks available.
#define ENOLINK         // Reserved.
#define ENOMEM          // Not enough space.
#define ENOMSG          // No message of the desired type.
#define ENOPROTOOPT     // Protocol not available.
#define ENOSPC          // No space left on device.
#define ENOSR           // [OB] No STREAM resources.
#define ENOSTR          // [OB] Not a STREAM.
#define ENOSYS          // Functionality not supported.
#define ENOTCONN        // The socket is not connected.
#define ENOTDIR         // Not a directory or a symbolic link to a directory.
#define ENOTEMPTY       // Directory not empty.
#define ENOTRECOVERABLE // State not recoverable.
#define ENOTSOCK        // Not a socket.
#define ENOTSUP         // Not supported.
#define ENOTTY          // Inappropriate I/O control operation.
#define ENXIO           // No such device or address.
#define EOPNOTSUPP      // Operation not supported on socket (maybe same ENOTSUP)
#define EOVERFLOW       // Value too large to be stored in data type.
#define EOWNERDEAD      // Previous owner died.
#define EPERM           // Operation not permitted.
#define EPIPE           // Broken pipe.
#define EPROTO          // Protocol error.
#define EPROTONOSUPPORT // Protocol not supported.
#define EPROTOTYPE      // Protocol wrong type for socket.
#define ERANGE          // Result too large.
#define EROFS           // Read-only file system.
#define ESPIPE          // Invalid seek.
#define ESRCH           // No such process.
#define ESTALE          // Reserved.
#define ETIME           // [OB] Stream ioctl timeout.
#define ETIMEDOUT       // Connection timed out.
#define ETXTBSY         // Text file busy.
#define EWOULDBLOCK     // Operation would block (may be same as EAGAIN)
#define EXDEV           // Cross-device link.

*/

#endif
