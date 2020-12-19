# interrupt.s disable and enable interrupts.

.global sti
sti:
	push ebp
	mov ebp, esp
	sti
	nop
	pop ebp
	ret

.global cli
cli:
	push ebp
	mov ebp, esp
	cli
	nop
	pop ebp
	ret
