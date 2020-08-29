#make a 64mb file
dd if=/dev/zero of=./disk.img bs=1M count=64

cd bootloader
source ./build.sh
cd ..

dd if=./bootloader/bootloader.bin of=./disk.img conv=notrunc