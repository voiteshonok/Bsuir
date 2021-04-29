.model small
.stack 100h
.data

mas_len dw 26
mas db 26 dup (0)
string db 100 dup ('$')

.code
.386

sort proc
	push si
	push dx
	push cx

	xor cx, cx

	begin:
		mov si, cx
		cmp mas[si], 0
		je next
		dec mas[si]
		mov dx, si
		add dl, 'a'
		mov ah, 02h
		int 21h
		jmp begin

		next:
			inc cx
			cmp cx, mas_len
			jne begin

	pop cx
	pop dx
	pop si
ret
sort endp

input proc
	push ax
	push dx
	push si

	start:
		mov ah, 1
		int 21h
		mov dl, al
		cmp dl, 13 ;enter
		je pressed_tab_or_enter
		cmp dl, 9 ;tab
		je pressed_tab_or_enter

		sub dl, 'a'
		mov dh, 0
		mov si, dx
		inc mas[si]
		jmp start

	pressed_tab_or_enter:

	pop si
	pop dx
	pop ax
ret
input endp

main:
	mov ax, @data
	mov ds, ax

	call input

	call sort

	mov ax, 4c00h
	int 21h

end main