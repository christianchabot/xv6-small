
.SUFFIXES: .o .c

CFLAGS = -I ../libc/include -I ../libc
CFLAGS += -fno-pic -static -fno-builtin -fno-strict-aliasing -Wall -ggdb -m32 -Werror -fno-omit-frame-pointer -fno-stack-protector -fno-pie -no-pie -nostdinc -s
LDFLAGS = -m elf_i386 -N -e main -Ttext 0

TOOLPREFIX=~/bin/i386/bin/i386-elf-

CC = $(TOOLPREFIX)gcc
LD = $(TOOLPREFIX)ld

LIBC = ../libc/libc.a

BIN = \
	cat\
	echo\
	grep\
	init\
	kill\
	ln\
	ls\
	mkdir\
	printppid\
	rm\
	sh\
	wc\
	zombie

EXTRA = \
	forktest\
	stressfs\
	usertests

.o:
	$(LD) $(LDFLAGS) -o $@ $< $(LIBC)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

OBJ = $(BIN:=.o)

all: $(OBJ) $(BIN) mkfs fs.img

mkfs: mkfs.c 
	gcc -Werror -Wall -o mkfs mkfs.c

fs.img: mkfs $(BIN)
	./mkfs fs.img $(BIN)

clean:
	rm -f $(BIN) *.o mkfs fs.img
