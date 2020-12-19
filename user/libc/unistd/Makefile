include ../config.mk

BASEDIR = ../

BIN =\
	read

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

OBJ = $(BIN:=.o)

all: $(OBJ)

clean:
	rm -f $(OBJ) *.d
