.model small
.stack 100h
.data
n dw ?
tmp dw ?
i dw ?
u dw ?
v dw ?
elem_size dw 2ы
array dw 10 dup (10 dup (1))
;array dw 1, 2, 3, 4, 5, 6, 7, 8, 9
n_eq db "n=$"
bad_input db "bad size input, try again", 0dh, 0ah, "$"
floyd_result db "resulted array", 0dh, 0ah, "$"
sss dw 10
.code
.386

output proc
	push dx
	push cx
	mov cx, 0

	cmp ax, 32767
	jc dividing
		push ax
		mov ah, 02h
		mov dl, '-'
		int 21h
		pop ax
		;dec ax
		neg ax

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
	push si
	xor cx, cx  
	xor si, si
	push 0

	inn:
		mov ah, 08h
		int 21h
		mov bl, al
		cmp bl, 13 ;enter
		je pressed_enter
		cmp bl, 9 ;tab
		je pressed_tab
		cmp bl, ' ' ;white_space
		je pressed_white_space

		cmp bl, 8 ;back_space
		je pressed_back_space
		
		cmp bl, '-';minus
		je pressed_minus

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
		push 0 ;чтобы pop в esq работал
		mul sss
		jc pressed_esq
		cmp ax, 32769
		jnc pressed_esq
		cmp ax, 32768
		jnz go_next
		cmp si, 1
		jne pressed_esq

		go_next:
		mov bh, 0
		add ax, bx
		jc pressed_esq
		cmp ax, 32769
		jnc pressed_esq
		cmp ax, 32768
		jnz go_go_next
		cmp si, 1
		jne pressed_esq
		go_go_next:
		pop dx ;убрали костыльный push
		push ax
		inc cx
		mov dl, bl
		add dl, '0'
		mov ah, 02h
		int 21h
		jmp inn
	
	pressed_esq: 
		xor si, si
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
		
		cmp cx, 1
		jne next_sol
		cmp si, 1
		jne next_sol
		xor si, si
		next_sol:

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
		
	pressed_minus: 
	    cmp cx, 1
	    jnc inn
	    mov ah, 02h
	    mov dl, '-'
	    int 21h
	    inc cx
	    mov si, 1
	    jmp inn

	pressed_enter:
		cmp cx, 0
		je inn
		cmp si, 1
		jne not_minus_enter
		cmp cx, 1
		je inn
		not_minus_enter:
		mov ah, 02h
		mov dl, 13
		int 21h
		mov dl, 10
		int 21h
		jmp end_input

	pressed_tab:
		cmp cx, 0
		je inn
		cmp si, 1
		jne not_minus_tab
		cmp cx, 1
		je inn
		not_minus_tab:
		mov ah, 02h
		mov dl, 9
		int 21h
		jmp end_input

	pressed_white_space:
		cmp cx, 0
		je inn
		cmp si, 1
		jne not_minus_space
		cmp cx, 1
		je inn
		not_minus_space:
		mov ah, 02h
		mov dl, ' '
		int 21h
		jmp end_input
          
	end_input:
	pop ax
	
	cmp si, 1
	jne continie
	neg ax
	
	continie:
	
	pop si
	pop dx
	pop cx
	pop bx
ret
input endp

main:
	mov ax, @data
	mov ds, ax   
	
	size_input:
		lea dx, n_eq
		mov ah, 09h
		int 21h
		call input
		mov n, ax
		cmp n, 11
		jnc less_than_one
		cmp n, 1
		jnc array_input
		less_than_one:
		lea dx, bad_input
		mov ah, 09h
		int 21h
		jmp size_input

	array_input:
	
	;xor si, si
	;xor bx, bx
	;mov ax, array[bx][si]
	;call output
	;add si, 2

	xor cx, cx
	external_input:
		cmp cx, n
		je end_array_input
		xor di, di
		internal_input:
			call input
			push ax
			mov ax, cx
			mul elem_size
			mul n
			mov bx, ax
			mov ax, di
			mul elem_size
			mov si, ax
			pop ax
			mov array[bx][si], ax
			add di, 1
			cmp di, n
			jne internal_input
			add cx, 1
			jmp external_input
			
	end_array_input:

	mov i, 0
	floyd:
		mov ax, i
		cmp ax, n
		je end_floyd
		mov u, 0
		external_floyd:
			;mov ax, u
			;cmp ax, n
			;je end_external_floyd
			mov v, 0
			internal_floyd:
				mov ax, i
				mul elem_size
				push ax
				mov ax, u
				mul elem_size
				mul n
				mov bx, ax
				pop si
				push array[bx][si]
				pop tmp
				mov ax, v
				mul elem_size
				push ax
				mov ax, i
				mul elem_size
				mul n
				mov bx, ax
				pop si
				mov ax, array[bx][si]
				add tmp, ax
				mov ax, v
				mul elem_size
				push ax
				mov ax, u
				mul elem_size
				mul n
				mov bx, ax
				pop si
				mov ax, array[bx][si]
				cmp tmp, ax
				jg floyd_next
				mov ax, tmp
				mov array[bx][si], ax
				floyd_next:
				add v, 1
				mov ax, v
				cmp ax, n
				jne internal_floyd
				add u, 1
				mov ax, u
				cmp ax, n
				jne external_floyd
				add i, 1
				jmp floyd

		end_external_floyd:

	end_floyd:

	lea dx, floyd_result
	mov ah, 09h
	int 21h

	xor cx, cx
	external_output:
		cmp cx, n
		je end_array_output
		xor di, di
		internal_output:
			mov ax, cx
			mul elem_size
			mul n
			mov bx, ax
			mov ax, di
			mul elem_size
			mov si, ax
			pop ax
			mov ax, array[bx][si]
			call output
			mov ah, 02h ;--вывод таба /*
			mov dl, 9
			int 21h ;--вывод таба */
			add di, 1
			cmp di, n
			jne internal_output
			add cx, 1
			mov ax, n ;-------------------можно отрефакторить??!
			mul elem_size
			add bx, ax
			mov ah, 02h ;--перевод на новую строку /*
			mov dl, 13
			int 21h
			mov dl, 10
			int 21h		;--перевод на новую строку */
			jmp external_output
			
	end_array_output:

	mov ax, 4c00h
	int 21h

end main