# vectors.s sends all traps here.

# Build trap frame.
.global alltraps
alltraps:
	push ds
	push es
	push fs
	push gs
	pusha

	# Set up data segments.
	mov ax, 16 # $(SEG_KDATA<<3) $(2<<3)
	mov ds, ax
	mov es, ax

	# Call trap(tf), where tf=%esp
	push esp
	call trap
	add esp, 4

	# Return falls through to trapret...
.global trapret
trapret:
	popa
	pop gs
	pop fs
	pop es
	pop ds
	add esp, 8  # trapno and errcode
	iret
