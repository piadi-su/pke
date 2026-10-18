[BITS 16]
[ORG 0x7c00]

start:
	cli ;change focus/interrupt | disable interrupts
	mov ax, 0x00
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7c00
    sti ;enable cpu interrupts back
    mov si, msg

    
print:
    lodsb
    cmp al,0
    je done
    mov ah, 0x0E
    ; int 0x18
    int 0x10
    jmp print

done:
    cli
    hlt


msg: db 'test bt ', 0

times 510 - ($ - $$) db 0
dw 0xAA55

