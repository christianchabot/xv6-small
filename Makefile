
all: user/fs.img boot/bootblock kern/kernel xv6.img qemu

user/fs.img:
	cd user && make

boot/bootblock:
	cd boot && make

kern/kernel:
	cd kern && make

xv6.img:
	dd if=/dev/zero of=xv6.img count=10000
	dd if=boot/bootblock of=xv6.img conv=notrunc
	dd if=kern/kernel of=xv6.img seek=1 conv=notrunc

ifndef QEMU
QEMU = $(shell if which qemu > /dev/null; \
        then echo qemu; exit; \
        elif which qemu-system-i386 > /dev/null; \
        then echo qemu-system-i386; exit; \
        elif which qemu-system-x86_64 > /dev/null; \
        then echo qemu-system-x86_64; exit; \
        else \
        qemu=/Applications/Q.app/Contents/MacOS/i386-softmmu.app/Contents/MacOS/i386-softmmu; \
        if test -x $$qemu; then echo $$qemu; exit; fi; fi; \
        echo "***" 1>&2; \
        echo "*** Error: Couldn't find a working QEMU executable." 1>&2; \
        echo "*** Is the directory containing the qemu binary in your PATH" 1>&2; \
        echo "*** or have you tried setting the QEMU variable in Makefile?" 1>&2; \
        echo "***" 1>&2; exit 1)
endif

# try to generate a unique GDB port
GDBPORT = $(shell expr `id -u` % 5000 + 25000)
# QEMU's gdb stub command line changed in 0.11
QEMUGDB = $(shell if $(QEMU) -help | grep -q '^-gdb'; \
	then echo "-gdb tcp::$(GDBPORT)"; \
	else echo "-s -p $(GDBPORT)"; fi)
CPUS = 2

QEMUOPTS = -enable-kvm # -vga qxl
QEMUOPTS += -drive file=user/fs.img,index=1,media=disk,format=raw -drive file=xv6.img,index=0,media=disk,format=raw -smp $(CPUS) -m 512 $(QEMUEXTRA)

qemu: user/fs.img xv6.img
	$(QEMU) $(QEMUOPTS)

#$(QEMU) -serial mon:stdio $(QEMUOPTS)

qemu-nox: fs.img xv6.img
	$(QEMU) -nographic $(QEMUOPTS)

.gdbinit: #.gdbinit.tmpl
	sed "s/localhost:1234/localhost:$(GDBPORT)/" < .gdbinit.tmpl > $@

qemu-gdb: user/fs.img xv6.img .gdbinit
	@echo "*** Now run 'gdb'." 1>&2
	$(QEMU) $(QEMUOPTS) $(QEMUGDB) -S
	#-serial mon:stdio $(QEMUOPTS) -S $(QEMUGDB)

qemu-nox-gdb: user/fs.img xv6.img .gdbinit
	@echo "*** Now run 'gdb'." 1>&2
	$(QEMU) -nographic $(QEMUOPTS) -S $(QEMUGDB)

clean:
	cd kern && make clean
	cd user && make clean
	cd boot && make clean
	rm -f xv6.img
