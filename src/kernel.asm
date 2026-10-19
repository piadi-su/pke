[BITS 32]

global _start
extern kernel_main
	
_start:
	call kernel_main

	cli
    hlt

times 510 - ($ - $$) db 0
dw 0xAA55
