
# Assembly helper functions

#	void
#	waitdisk(void)
#	{
#		/* Wait for disk ready. */
#		while ((inb(0x1F7) & 0xC0) != 0x40)
#			;
#	}

# void waitdisk(void)
.global waitdisk
waitdisk:
	mov edx, 0x1f7
	in al, dx
	and eax, 0xc0
	cmp al, 0x40
	jne waitdisk + 0x5
	ret

# void x86out(unsigned int, unsigned int)
.global x86out
x86out:
	mov edx, [esp + 0x4]
	mov eax, [esp + 0x8]
	out dx, al
	ret

# void x86insw(void *, unsigned int, unsigned int)
.global x86insw
x86insw:
	push edi
	mov edi, [esp + 0x8]
	mov ecx, [esp + 0xc]
	mov edx, [esp + 0x10]
	cld
	rep insw
	pop edi
	ret
