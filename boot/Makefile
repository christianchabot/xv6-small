
TOOLPREFIX=~/bin/i386/bin/i386-elf-

CC = $(TOOLPREFIX)gcc
AS = $(TOOLPREFIX)as
LD = $(TOOLPREFIX)ld
OBJCOPY = $(TOOLPREFIX)objcopy
OBJDUMP = $(TOOLPREFIX)objdump

CFLAGS = -I sys -O #-ggdb
CFLAGS += -fno-pic -static -fno-builtin -fno-strict-aliasing -Wall -m32 -Werror -fno-omit-frame-pointer
CFLAGS += $(shell $(CC) -fno-stack-protector -E -x c /dev/null >/dev/null 2>&1 && echo -fno-stack-protector)

ASFLAGS = -I sys #-ggdb
ASFLAGS += -msyntax=intel -mnaked-reg -fno-builtin -fno-pic -fno-omit-frame-pointer
ASFLAGS += $(shell $(CC) -fno-stack-protector -E -x c /dev/null >/dev/null 2>&1 && echo -fno-stack-protector)

# FreeBSD ld wants ``elf_i386_fbsd''
LDFLAGS += -m $(shell $(LD) -V | grep elf_i386 2>/dev/null | head -n 1)

# Disable PIE when possible (for Ubuntu 16.10 toolchain)
ifneq ($(shell $(CC) -dumpspecs 2>/dev/null | grep -e '[^f]no-pie'),)
CFLAGS += -fno-pie -no-pie
endif
ifneq ($(shell $(CC) -dumpspecs 2>/dev/null | grep -e '[^f]nopie'),)
CFLAGS += -fno-pie -nopie
endif

bootblock: bootasm.S bootmain.c
	$(CC) $(CFLAGS) -fno-pic -nostdinc -c bootmain.c
	$(CC) -Isys -c bootasm.S #$(CFLAGS) -fno-pic -nostdinc -I. -c bootasm.S
	#$(AS) $(ASFLAGS) -o bootasm.o -c bootasm.s
	#$(AS) $(ASFLAGS) -o x86asm.o -c x86asm.s
	#$(LD) $(LDFLAGS) -N -e start -Ttext 0x7C00 -o bootblock.o bootasm.o x86asm.o bootmain.o
	$(LD) $(LDFLAGS) -N -e start -Ttext 0x7C00 -o bootblock.o bootasm.o bootmain.o
	$(OBJCOPY) -S -O binary -j .text bootblock.o bootblock
	./sign.pl bootblock

clean: 
	rm -f *.o bootblock
