# No movzx?

# Optimize later.
.global inb
inb:
	push ebp
	mov ebp, esp
	sub esp, 0x14
	mov eax, [ebp] + 0x8
	mov [ebp] - 0x14, ax

	# movzx eax, [ebp] - 0x14
	xor eax, eax
	mov eax, [ebp] - 0x14
	mov edx, eax
	in al, dx
	mov [ebp] - 0x1, al

	# movzx eax, [ebp] - 0x1
	xor eax, eax
	mov eax, [ebp] - 0x1
	leave
	ret

# Optimize later.
.global outb
outb:
	push ebp
	mov ebp, esp
	sub esp, 0x8
	mov edx, [ebp] + 0x8
	mov eax, [ebp] + 0xc
	mov [ebp] - 0x4, dx
	mov [ebp] - 0x8, al

	# movzx eax, [ebp] - 0x8
	xor eax, eax
	mov eax, [ebp] - 0x8

	# movzx edx, [ebp] - 0x4
	xor edx, edx
	mov edx, [ebp] - 0x4
	out dx, al
	nop

	# leave
	mov esp, ebp
	pop ebp
	ret

# Optimize later.
.global outw
outw:
	push ebp
	mov ebp, esp
	sub esp, 0x8 # align the stack to 2 dwords?
	mov edx, [ebp] + 0x8
	mov eax, [ebp] + 0xc
	mov [ebp] - 0x8, dx

	# movzx edx, [ebp] - 0x4
	xor edx, edx
	mov edx, [ebp] - 0x8
	out dx, eax
	nop

	# leave
	mov esp, ebp
	pop ebp
	ret

.global readeflags
readeflags:
	pushfd
	pop eax
	ret

.global rcr2
rcr2:
	mov eax, cr2
	ret

.global lcr3
lcr3:
	mov eax, [esp] + 0x4
	mov cr3, eax
	ret

# Optimize later.
.global xchg
xchg:
	mov edx, [esp] + 0x4
	mov eax, [esp] + 0x8
	lock xchg eax, [edx]
	ret

# Optimize later.
.global ltr
ltr:
	#ltr [esp + 0x4]
	mov eax, [esp] + 0x4
	ltr ax
	ret

# Optimize later.
.global loadgs
loadgs:
	mov eax, [esp] + 0x4
	mov gs, ax
	ret
