
nasm ./asm/boot.asm -f elf32 -o boot.o

clang \
    --target=i686-pc-none-elf -march=i686 \
    -ffreestanding -fno-builtin -nostdlib \
    -Wall -Werror \
     -T linker.ld \
     -I ./include/ \
     -o bootloader.bin \
     ./src/*.c ./*.o

rm ./*.o