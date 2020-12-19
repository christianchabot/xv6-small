include ../config.mk

BASEDIR = ../

BIN =\
     errno

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

OBJ = $(BIN:=.o)

all: $(OBJ)
	mv $(OBJ) $(BASEDIR)build

clean:
	rm -f $(OBJ) *.d
