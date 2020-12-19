
HDRDIR = sys

BIN =\
	bio\
	console\
	exec\
	file\
	fs\
	ide\
	ioapic\
	kalloc\
	kbd\
	lapic\
	log\
	main\
	mp\
	picirq\
	pipe\
	proc\
	sleeplock\
	spinlock\
	string\
	swtch\
	syscall\
	sysfile\
	sysproc\
	trapasm\
	trap\
	uart\
	vectors\
	inout\
	vm
	#interrupt\

OBJS = $(BIN:=.o)

# Cross-compiling (e.g., on Mac OS X)
# TOOLPREFIX = i386-jos-elf

# Using native tools (e.g., on X86 Linux)
#TOOLPREFIX = 

TOOLPREFIX=~/bin/i386/bin/i386-elf-

CC = $(TOOLPREFIX)gcc
AS = $(TOOLPREFIX)as
LD = $(TOOLPREFIX)ld
OBJCOPY = $(TOOLPREFIX)objcopy
OBJDUMP = $(TOOLPREFIX)objdump

#CFLAGS += -MD # Removed because it creates .d files.
CFLAGS = -I sys -O2 # -g
CFLAGS += -fno-pic -static -fno-builtin -fno-strict-aliasing -Wall -ggdb -m32 -Werror -fno-omit-frame-pointer
CFLAGS += $(shell $(CC) -fno-stack-protector -E -x c /dev/null >/dev/null 2>&1 && echo -fno-stack-protector)

ASFLAGS += -march=i386 -32 -msyntax=intel -mnaked-reg

# FreeBSD ld wants ``elf_i386_fbsd''
LDFLAGS += -m $(shell $(LD) -V | grep elf_i386 2>/dev/null | head -n 1)

# Disable PIE when possible (for Ubuntu 16.10 toolchain)
ifneq ($(shell $(CC) -dumpspecs 2>/dev/null | grep -e '[^f]no-pie'),)
CFLAGS += -fno-pie -no-pie
endif
ifneq ($(shell $(CC) -dumpspecs 2>/dev/null | grep -e '[^f]nopie'),)
CFLAGS += -fno-pie -nopie
endif

.s.o:
	$(AS) $(ASFLAGS) -o $@ $<

.S.o:
	$(CC) $(CFLAGS) -c -o $@ $<

kernel: $(OBJS) entry.o initcode kernel.ld entryother
	$(LD) $(LDFLAGS) -T kernel.ld -o kernel entry.o $(OBJS) -b binary initcode entryother
	#$(OBJDUMP) -t kernel | sed '1,/SYMBOL TABLE/d; s/ .* / /; /^$$/d' > kernel.sym

entryother: entryother.S
	$(CC) $(CFLAGS) -fno-pic -nostdinc -I sys -c entryother.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0x7000 -o bootblockother.o entryother.o
	$(OBJCOPY) -S -O binary -j .text bootblockother.o entryother

initcode:
	#$(AS) $(ASFLAGS) $(ASFLAGS) -c -o initcode.o initcode.s
	$(CC) $(CFLAGS) -nostdinc -I sys -c initcode.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0 -o initcode.out initcode.o
	$(OBJCOPY) -S -O binary initcode.out initcode

vectors.s: vectors.sh
	sh vectors.sh

clean: 
	rm -f *.o vectors.s bootblock entryother initcode initcode.out kernel xv6.img .gdbinit
