.model small
.stack 100h
.data
a dw 5
b dw 60
c dw 50
d dw 7
.code
main:
	mov ax, @data
	mov ds, ax

	mov bx, c
	add bx, d
	jc else1
	mov ax, a
	xor ax, b
	cmp ax, bx
	jne else1
	mov ax, c
	and ax, a
	mov bx, b
	or bx, d
	add ax, bx
	jmp endOfIf

	else1:
		mov ax, a
		and ax, b
		jc else2
		cmp ax, bx
		jne else2
		mov ax, a
		xor ax, b
		xor ax, c
		xor ax, d
		jmp endOfIf2

		else2:
			mov ax, a
			or ax, b
			or ax, c
			or ax, d
		endOfIf2:
	endOfIf:

	mov ax, 4c00h
	int 21h
end main