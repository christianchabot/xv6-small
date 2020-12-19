// Per-CPU state
struct cpu {
  unsigned char apicid;          // Local APIC ID
  struct context *scheduler;     // swtch() here to enter scheduler
  struct taskstate ts;           // Used by x86 to find stack for interrupt
  struct segdesc gdt[NSEGS];     // x86 global descriptor table
  volatile unsigned int started; // Has the CPU started?
  int ncli;                      // Depth of pushcli nesting.
  int intena;                    // Were interrupts enabled before pushcli?
  struct proc *proc;             // The process running on this cpu or null
};

extern struct cpu cpus[NCPU];
extern int ncpu;

//PAGEBREAK: 17
// Saved registers for kernel context switches.
// Don't need to save all the segment registers (%cs, etc),
// because they are constant across kernel contexts.
// Don't need to save %eax, %ecx, %edx, because the
// x86 convention is that the caller has saved them.
// Contexts are stored at the bottom of the stack they
// describe; the stack pointer is the address of the context.
// The layout of the context matches the layout of the stack in swtch.S
// at the "Switch stacks" comment. Switch doesn't save eip explicitly,
// but it is on the stack and allocproc() manipulates it.
struct context {
  unsigned long edi;
  unsigned long esi;
  unsigned long ebx;
  unsigned long ebp;
  unsigned long eip;
};

struct segment {
	void *data_structure; // PLace holder but should point to a data_structure.
	unsigned long s_bytes;
};

/*
Process memory is laid out contiguously, low addresses first:
text
original data and bss
fixed-size stack
expandable heap
*/
struct vmspace {
	struct segment *text, *data, *stack, *heap;
};

enum procstate {UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE};

struct list;
struct user;

// Per-process state
struct proc {
	pde_t *pgdir;                // Page table
	char *kstack;                // Bottom of kernel stack for this process
	enum procstate state;        // Process state
	void *chan;                  // If non-zero, sleeping on chan
	struct proc *parent;         // Parent process
	struct vmspace *vmspace;     // Address space.
	struct user *user;           // User structure.
	struct trapframe *tf;        // Trap frame for current syscall
	struct context *context;     // swtch() here to run process
	struct inode *cwd;           // Current directory
	struct list *children;       // List of children.
	struct file *ofile[NOFILE];  // Open files
	unsigned int sz;             // Size of process memory (bytes)
	int pid;                     // Process ID
	int killed;                  // If non-zero, have been killed
	struct {
		unsigned int killed : 1;
	} flags;
	char name[16];               // Process name (debugging)
};

