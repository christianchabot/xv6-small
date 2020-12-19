// Routines to let C code use special x86 instructions.

unsigned char inb(unsigned int);

void outb(unsigned int, unsigned int);
void outw(unsigned int, unsigned int);

unsigned int readeflags(void);

unsigned int rcr2(void);
void lcr3(unsigned int);

unsigned int xchg(volatile unsigned int *, unsigned int);

void ltr(unsigned int);

/* Unused. */
void loadgs(unsigned int);


/* Need to figure these out. */
static inline void
insl(int port, void *addr, int cnt)
{
  asm volatile("cld; rep insl" :
               "=D" (addr), "=c" (cnt) :
               "d" (port), "0" (addr), "1" (cnt) :
               "memory", "cc");
}

static inline void
outsl(int port, const void *addr, int cnt)
{
  asm volatile("cld; rep outsl" :
               "=S" (addr), "=c" (cnt) :
               "d" (port), "0" (addr), "1" (cnt) :
               "cc");
}

static inline void
stosb(void *addr, int data, int cnt)
{
  asm volatile("cld; rep stosb" :
               "=D" (addr), "=c" (cnt) :
               "0" (addr), "1" (cnt), "a" (data) :
               "memory", "cc");
}

static inline void
stosl(void *addr, int data, int cnt)
{
  asm volatile("cld; rep stosl" :
               "=D" (addr), "=c" (cnt) :
               "0" (addr), "1" (cnt), "a" (data) :
               "memory", "cc");
}

struct segdesc;

static inline void
lgdt(struct segdesc *p, int size)
{
  volatile ushort pd[3];

  pd[0] = size-1;
  pd[1] = (uint)p;
  pd[2] = (uint)p >> 16;

  asm volatile("lgdt (%0)" : : "r" (pd));
}

struct gatedesc;

static inline void
lidt(struct gatedesc *p, int size)
{
  volatile ushort pd[3];

  pd[0] = size-1;
  pd[1] = (uint)p;
  pd[2] = (uint)p >> 16;

  asm volatile("lidt (%0)" : : "r" (pd));
}

/* Need to figure out cli and sti. */
static inline void
cli(void)
{
  asm volatile("cli");
}

static inline void
sti(void)
{
  asm volatile("sti");
}

/*
PAGEBREAK: 36
Layout of the trap frame built on the stack by the
hardware and by trapasm.S, and passed to trap().
*/
struct trapframe {
	// registers as pushed by pusha
	unsigned int edi;
	unsigned int esi;
	unsigned int ebp;
	unsigned int oesp; // useless & ignored
	unsigned int ebx;
	unsigned int edx;
	unsigned int ecx;
	unsigned int eax;

	// rest of trap frame
	unsigned short gs;
	unsigned short padding1;
	unsigned short fs;
	unsigned short padding2;
	unsigned short es;
	unsigned short padding3;
	unsigned short ds;
	unsigned short padding4;
	unsigned int trapno;

	// below here defined by x86 hardware
	unsigned int err;
	unsigned int eip;
	unsigned short cs;
	unsigned short padding5;
	unsigned int eflags;

	// below here only when crossing rings, such as from user to kernel
	unsigned int esp;
	unsigned short ss;
	unsigned short padding6;
};
