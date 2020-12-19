.global exit
.global fork
.global read
.global write
.global open
.global close
.global wait
.global link
.global unlink
.global chdir
.global mknod
.global getpid
.global getppid
.global kill
.global dup
.global pipe
.global fstat
.global exec
.global sbrk
.global uptime
.global mkdir
.global sleep

exit:
	mov eax, 1
	int 128
	ret

fork:
	mov eax, 2
	int 128
	ret

read:
	mov eax, 3
	int 128
	ret

write:
	mov eax, 4
	int 128
	ret

open:
	mov eax, 5
	int 128
	ret

close:
	mov eax, 6
	int 128
	ret

wait:
	mov eax, 7
	int 128
	ret

link:
	mov eax, 8
	int 128
	ret

unlink:
	mov eax, 9
	int 128
	ret

chdir:
	mov eax, 10
	int 128
	ret

mknod:
	mov eax, 11
	int 128
	ret

getpid:
	mov eax, 12
	int 128
	ret

getppid:
	mov eax, 13
	int 128
	ret

kill:
	mov eax, 14
	int 128
	ret

dup:
	mov eax, 15
	int 128
	ret

pipe:
	mov eax, 16
	int 128
	ret

fstat:
	mov eax, 17
	int 128
	ret

exec:
	mov eax, 18
	int 128
	ret

sbrk:
	mov eax, 19
	int 128
	ret

uptime:
	mov eax, 20
	int 128
	ret

mkdir:
	mov eax, 21
	int 128
	ret

sleep:
	mov eax, 22
	int 128
	ret
