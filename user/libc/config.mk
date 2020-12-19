TOOLPREFIX=~/bin/i386/bin/i386-elf-

AS = $(TOOLPREFIX)as # Switch to more generic as when kernel is more mature.
CC = $(TOOLPREFIX)gcc # Switch to more generic cc when kernel is more mature.
LD = $(TOOLPREFIX)ld # Should not need ld later, when the kernel is more mature.

# CFLAGS: Omitted -Werror -O2
OMITTED = -Werror # -O2
INCLUDES = -I $(BASEDIR)include -I .
CFLAGS = $(INCLUDES) $(OMITTED) -fno-pic -static -fno-builtin -fno-strict-aliasing -Wall -ggdb -m32 -fno-omit-frame-pointer -fno-pie -no-pie -fno-stack-protector -nostdinc -s
#CFLAGS += -MD # Creates the *.d files.

LDFLAGS = -m elf_i386 -N -Ttext 0 # -e main

#ASFLAGS += -m32 -gdwarf-2 -Wa,-divide $(INCLUDES)
ASFLAGS = -march=i386 -32 -msyntax=intel -mnaked-reg
