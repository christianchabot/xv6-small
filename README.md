Currently I split xv6 into it's different parts (boot/, kern/, user/libc/, and user/bin/).

I am using the xv6 code as a bootstrap to create something bigger.
Right now I just want to segment xv6 into its proper parts so I can use it to tinker on.
I want to make a small OS that is maximally portable (can compile with any C compiler such as Tiny C Compiler (TCC)), right now it can only be compiled with GNU cc and Clang like compilers.

TODO:

- Move all .S files to .s files.
- Remove any inline assembly.
- Separate all the different parts of the OS properly and have them be independent of one another (boot/ should be separate from user/libc/).
- Make it easier to build the project with a top level Makefile and config.mk (right now the Makefiles are kind of a mess).
- Have a couple architectures such as i386 (only one CPU core, no apic, and no SIMD instructions), i686 (more than one CPU core, apic, SIMD instructions, CPUID), etc that can be built with a top level Makefile ARCH=i386 or ARCH=i686, etc.
- Primary focus should be on the kernel and adding features.
- Create a minimal fully featured (as it can be, networking would come much later) C library.
- Create more userspace programs.
