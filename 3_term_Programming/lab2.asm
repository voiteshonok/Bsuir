.model small
.stack 100h
.data
a dw ?
b dw ?
ost dw ?
a_eq db "a=$"
b_eq db "b=$"
sol_eq db "a/b=$"
ost_eq db "a%b=$"
sss dw 10
.code
.386

output proc
	push dx
	push cx
	mov cx, 0

	dividing:
		mov dx, 0
		div sss
		inc cx
		push dx
		cmp ax, 0
		jne dividing

	out1:
		pop dx
		add dl, '0'
		mov ah, 02h
		int 21h
		loop out1

	pop cx
	pop dx
ret
output endp

input proc
	push bx
	push cx
	push dx
	mov cx, 0
	push 0

	inn:
		mov ah, 08h
		int 21h
		mov bl, al
		cmp bl, 13 ;enter
		je pressed_enter

		cmp bl, 8 ;back_space
		je pressed_back_space

		cmp bl, 27 ;esq
		je pressed_esq

		sub bl, '0'
		jc inn
		cmp bl, 10
		jnc inn

		pop ax
		push ax
		cmp ax, 0
		jne next
		cmp bl, 0
		jne next
		cmp cx, 1
		je inn
		
		next:
		pop ax
		mul sss
		push 0 ;чтобы pop в esq работал
		jc pressed_esq
		mov bh, 0
		add ax, bx
		jc pressed_esq
		pop dx ;убрали костыльный push
		push ax
		inc cx
		mov dl, bl
		add dl, '0'
		mov ah, 02h
		int 21h
		jmp inn
	
	pressed_esq:
		pop ax
		push 0
		esq_loop:
			cmp cx, 0
			je inn
			mov dl, 8
			mov ah, 02h
			int 21h
			mov dl, ' '
			int 21h
			mov dl, 8
			int 21h
			dec cx
			jmp esq_loop

	pressed_back_space:
		cmp cx, 0
		je inn
		dec cx
		pop ax
		mov dx, 0
		div sss
		push ax
		mov dl, 8
		mov ah, 02h
		int 21h
		mov dl, ' '
		int 21h
		mov dl, 8
		int 21h
		jmp inn

	pressed_enter:
		cmp cx, 0
		je inn
		mov ah, 02h
		mov dl, 13
		int 21h
		mov dl, 10
		int 21h

	pop ax
	pop dx
	pop cx
	pop bx
ret
input endp

main:
	mov ax, @data
	mov ds, ax

	lea dx, a_eq
	mov ah, 09h
	int 21h
	call input
	mov a, ax

	try_again:
		lea dx, b_eq
		mov ah, 09h
		int 21h
		call input
		mov b, ax
		cmp b, 0
		je try_again

	lea dx, sol_eq
	mov ah, 09h
	int 21h
	mov dx, 0
	mov ax, a
	div b
	mov ost, dx
	call output

	mov dl, 10
	mov ah, 02h
	int 21h
	mov dl, 13
	int 21h

	lea dx, ost_eq
	mov ah, 09h
	int 21h
	mov ax, ost
	call output

	mov ax, 4c00h
	int 21h

end main