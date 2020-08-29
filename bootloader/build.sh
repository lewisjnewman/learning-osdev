nasm ./asm/boot.asm -f elf32 -o boot.o
clang --target=i686-pc-none-elf -march=i686 -ffreestanding -fno-builtin -nostdlib -nostdinc -T linker.ld src/*.c *.o -o bootloader.bin