[BITS 32]

global _start
extern kernel_main
	
_start:
	call kernel_main

	;DEBUG
	; mov byte [0xB8000], 'O'
	;    mov byte [0xB8001], 0x0A   
	;    mov byte [0xB8002], 'K'
	;    mov byte [0xB8003], 0x0A

hang:
	cli
    hlt
	jmp hang

