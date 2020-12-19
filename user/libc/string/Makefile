include ../config.mk

BASEDIR = ../

BIN =\
	memccpy\
	memchr\
	memcmp\
	memcpy\
	memmove\
	memset\
	stpcpy\
	stpncpy\
	strcat\
	strchr\
	strcmp\
	strcoll\
	strcoll_l\
	strcpy\
	strcspn\
	strdup\
	strerror\
	strerror_l\
	strerror_r\
	string\
	strlen\
	strncat\
	strncmp\
	strncpy\
	strndup\
	strnlen\
	strpbrk\
	strrchr\
	strsignal\
	strspn\
	strstr\
	strtok\
	strtok_r\
	strxfrm\
	strxfrm_l

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

OBJ = $(BIN:=.o)

all: $(OBJ)
	mv $(OBJ) $(BASEDIR)build

clean:
	rm -f $(OBJ) *.d
