#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"
#include "syscall.h"

// User code makes a system call with INT T_SYSCALL.
// System call number in %eax.
// Arguments on the stack, from the user call to the C
// library system call function. The saved user %esp points
// to a saved program counter, and then the first argument.

// Fetch the int at addr from the current process.
int
fetchint(unsigned int addr, int *ip)
{
	struct proc *curproc = myproc();

	//cprintf("fetchint(addr, ...): %d\n", addr);
	if(addr >= curproc->sz || addr+4 > curproc->sz) {
		//cprintf("fetchint() failed: -1\n");
		return -1;
	}
	*ip = *(int*)(addr);
	return 0;
}

// Fetch the nul-terminated string at addr from the current process.
// Doesn't actually copy the string - just sets *pp to point at it.
// Returns length of string, not including nul.
int
fetchstr(unsigned int addr, char **pp)
{
	char *s, *ep;
	struct proc *curproc = myproc();

	//cprintf("addr: %d, curproc->sz: %d\n", addr, curproc->sz);
	if(addr >= curproc->sz) {
		//cprintf("fetch str failed addr >= curproc->sz\n");
		return -1;
	}
	*pp = (char*)addr;
	ep = (char*)curproc->sz;
	for (s = *pp; s < ep; s++) {
		if(*s == 0)
			return s - *pp;
	}
	//cprintf("fetch int failed -1\n");
	return -1;
}

// Fetch the nth 32-bit system call argument.
int
argint(int n, int *ip)
{
  return fetchint((myproc()->tf->esp) + 4 + 4*n, ip);
}

// Fetch the nth word-sized system call argument as a pointer
// to a block of memory of size bytes.  Check that the pointer
// lies within the process address space.
int
argptr(int n, char **pp, int size)
{
  int i;
  struct proc *curproc = myproc();
 
  if(argint(n, &i) < 0)
    return -1;
  if(size < 0 || (uint)i >= curproc->sz || (uint)i+size > curproc->sz)
    return -1;
  *pp = (char*)i;
  return 0;
}

// Fetch the nth word-sized system call argument as a string pointer.
// Check that the pointer is valid and the string is nul-terminated.
// (There is no shared writable memory, so the string can't change
// between this check and being used by the kernel.)
int
argstr(int n, char **pp)
{
	int addr;
	if(argint(n, &addr) < 0) {
		cprintf("argint: -1\n");
		return -1;
	}
	
	//cprintf("argint(%d, %d)\n", n, addr);
	return fetchstr(addr, pp);
}

extern int sys_chdir(void);
extern int sys_close(void);
extern int sys_dup(void);
extern int sys_exec(void);
extern int sys_exit(void);
extern int sys_fork(void);
extern int sys_fstat(void);
extern int sys_getpid(void);
extern int sys_getppid(void);
extern int sys_kill(void);
extern int sys_link(void);
extern int sys_mkdir(void);
extern int sys_mknod(void);
extern int sys_open(void);
extern int sys_pipe(void);
extern int sys_read(void);
extern int sys_sbrk(void);
extern int sys_sleep(void);
extern int sys_unlink(void);
extern int sys_wait(void);
extern int sys_write(void);
extern int sys_uptime(void);

/* syscall value should match table index. */
static int (*syscalls[])(void) = {
	0,
	sys_exit,
	sys_fork,
	sys_read,
	sys_write,
	sys_open,
	sys_close,
	sys_wait,
	sys_link,
	sys_unlink,
	sys_chdir,
	sys_mknod,
	sys_getpid,
	sys_getppid,
	sys_kill,
	sys_dup,
	sys_pipe,
	sys_fstat,
	sys_exec,
	sys_sbrk,
	sys_uptime,
	sys_mkdir,
	sys_sleep
};

void
syscall(void)
{
	int num;
	struct proc *curproc = myproc();

	num = curproc->tf->eax;
	//cprintf("syscall #: %d\n", num);
	if(num > 0 && num < NELEM(syscalls) && syscalls[num]) {
		curproc->tf->eax = syscalls[num]();
	} else {
		//cprintf("%d %s: unknown sys call %d\n", curproc->pid, curproc->name, num);
		curproc->tf->eax = -1;
	}
}
