include ../config.mk

BASEDIR = ../

BIN =\
     atoi\
     printf\
     putc\
     gets

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

OBJ = $(BIN:=.o)

all: $(OBJ)
	mv $(OBJ) $(BASEDIR)build

clean:
	rm -f $(OBJ) *.d
