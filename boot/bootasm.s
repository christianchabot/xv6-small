
# Start the first CPU: switch to 32-bit protectied mode, jump into C.
# The BIOS loads this code from the first sector of the hard disk into
# memory at physical address 0x7c00 and starts executing in real mode
# with cs = 0 and ip = 7c00.
.code16
.global start
start:
	# Disable interrupts.
	cli

	# Zero data segment registers DS, ES, and SS.
	xor ax, ax
	mov ds, ax
	mov es, ax
	mov ss, ax

seta20.1:
	# Wait for not busy.
	in al, 0x64
	test al, 0x2
	jnz seta20.1

	# 0xd1 -> port 0x64
	mov al, 0xd1
	out 0x64, al

seta20.2:
	# Wait for not busy.
	in al, 0x64
	test al, 0x2
	jnz seta20.2

	# 0xdf -> port 0x60
	mov al, 0xdf
	out 0x60, al

	# Switch from real to protected mode. Use a bootstrap GDT that makes
	# virtual addresses map directly to physical addressses so that the
	# effective memory map doesn't change during the transition.
	lgdt gdtdesc

	# Protection Enable in cr0 register.
	mov eax, cr0
	or eax, 0x1
	mov cr0, eax

	# Complete the transtion to 32-bit protected mode by using a long jmp
	# to reload cs and eip. The segment descriptors are set up with no
	# translation, so that the mapping is still the identity mapping.
	# ljmp 0x8, start32
	.intel_syntax noprefix
	jmp 0x8:start32

.code32
start32:
	# Set up the protected-mode data segment registers
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov ss, ax

	# Zero the segments not ready for use.
	xor ax, ax
	mov fs, ax
	mov gs, ax

	# Set up the stack pointer and call into C.
	mov esp, start
	call bootmain

	# If bootmain returns spin.. ??
spin:
	hlt
	jmp spin

# Bootstrap GDT set up null segment, code segment, and data segment respectively.
# Force 4 byte alignment.
.p2align 2
gdt:
	.word 0x0000, 0x0000
	.byte 0, 0, 0, 0
	.word 0xffff, 0x0000
	.byte 0, 0x9a, 0xcf, 0
	.word 0xffff, 0x0000
	.byte 0, 0x92, 0xcf, 0

# sizeof(gdt) - 1 and address of gdt respectively.
gdtdesc:
	.word (gdtdesc - gdt - 1)
	.long gdt
