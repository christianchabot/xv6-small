include ../../config.mk

BASEDIR = ../../

BIN =\
	syscall

.s.o:
	$(AS) $(ASFLAGS) -o $@ $<

OBJ = $(BIN:=.o)

all: $(OBJ)
	mv $(OBJ) $(BASEDIR)build

clean:
	rm -f $(OBJ)
