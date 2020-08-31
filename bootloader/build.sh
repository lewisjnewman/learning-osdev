
nasm ./asm/boot.asm -f elf32 -o boot.o
nasm ./asm/utils.asm -f elf32 -o utils.o


clang \
    --target=i686-pc-none-elf -march=i686 \
    -ffreestanding -fno-builtin -nostdlib \
    -Wall -Werror \
     -T linker.ld \
     -I ./include/ \
     -o bootloader.bin \
     $(find ./src -type f -name '*.c' -print) \
     $(find . -type f -name '*.o' -print)

rm ./*.o