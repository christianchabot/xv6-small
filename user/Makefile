
all: libc/libc.a fs.img

libc/libc.a:
	cd libc && make

bin/fs.img: libc/libc.a
	cd bin && make

fs.img: bin/fs.img
	cp bin/fs.img .

clean:
	cd libc && make clean
	cd bin && make clean
	rm -f fs.img
