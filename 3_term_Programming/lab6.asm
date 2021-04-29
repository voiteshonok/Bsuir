.model small
.stack 100h
.data
old_handler dd ?
.code

handler:
	push es ds si di cx bx dx ax
		
	xor ax, ax
	in al, 60h
	cmp al, 12h	
	je end_handler
	cmp al, 15h	
	je end_handler
	cmp al, 16h	
	je end_handler
	cmp al, 17h	
	je end_handler
	cmp al, 18h	
	je end_handler
	cmp al, 1eh	
	je end_handler

	jmp standart_handler
end_handler:
        mov al,20h  
        out 20h,al  
        pop ax dx bx cx di si ds es
        iret
		
standart_handler:
	pop ax dx bx cx di si ds es
	jmp dword ptr cs:old_handler

main:
	mov ax, @data
	mov ds, ax

	push es;
	xor ax, ax
	mov es, ax

	mov ax, word ptr es:[09h*4]
	mov word ptr old_handler, ax	;сохранение селектора
	mov ax, word ptr es:[09h * 4 + 2]
	mov word ptr old_handler + 2, ax	;сохранение сегмента

	mov ax, cs
	mov word ptr es:[09h * 4 + 2], ax	;записываем сегмент
	mov ax, offset handler
	mov word ptr es:[09h * 4], ax	;записываем селетор
	pop es

	
inf_cycle:
	mov ah, 1
	int 21h
	mov dl, al
	cmp dl, 27
	jne inf_cycle

last:
	
	push es
	xor ax, ax
	mov es, ax
	mov ax, word ptr old_handler + 2
	mov word ptr es:[09h * 4 + 2], ax
	mov ax, word ptr old_handler
	mov word ptr es:[09h * 4], ax	
	pop es

	mov ax, 4c00h
	int 21h
end main