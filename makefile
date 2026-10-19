FILES = ./build/kernel.asm.o ./build/kernel.o

CC = clang
LD = ld.lld
ASM = nasm

CFLAGS = --target=i686-elf -ffreestanding -fno-builtin -nostdlib -I./src -std=gnu99 -m32
LDFLAGS = -m elf_i386

all:
	$(ASM) -f bin ./src/btloader.asm -o ./bin/boot.bin
	
	$(ASM) -f elf32 -g ./src/kernel.asm -o ./build/kernel.asm.o
	
	$(CC) $(CFLAGS) -c ./src/kernel.c -o ./build/kernel.o
	
	$(LD) -T ./src/linker.ld $(FILES) -o ./bin/kernel.bin --oformat binary
	
	dd if=./bin/boot.bin of=./bin/pke.bin bs=512 count=1 conv=notrunc
	dd if=./bin/kernel.bin of=./bin/pke.bin bs=512 seek=1 conv=notrunc
	dd if=/dev/zero bs=512 count=8 >> ./bin/pke.bin

clean:
	rm -f ./bin/boot.bin ./bin/kernel.bin ./bin/pke.bin ./build/*.o
