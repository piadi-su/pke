all:
	nasm -f bin btloader.asm -o ./bin/bottom.bin
clean:
	rm -f ./bin/boot.bin
