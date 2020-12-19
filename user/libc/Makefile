include config.mk

BASEDIR = ./

.SUFFIXES: .a

DIR =\
	errno\
	stdio\
	stdlib\
	string\
	sys/stat\
	sys/syscall

HDR = $(DIR:=.h)

LIB = $(DIR:=.a)

all: libc.a

libc.a:
	cd errno && $(MAKE)
	cd stdio && $(MAKE)
	cd stdlib && $(MAKE)
	cd string && $(MAKE)
	cd sys/stat && $(MAKE)
	cd sys/syscall && $(MAKE)
	$(AR) -rcs $@ build/*.o

$(LIB):
	cd $* && $(MAKE)

#all: libc.a $(OBJ)

#libc.a: $(OBJ)
#	$(AR) -rcs $@ $(OBJ)

clean:
	rm -f $(OBJ) libc.a build/*

