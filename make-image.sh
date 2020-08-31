#make an empty 256mb file
dd if=/dev/zero of=./disk.img bs=1M count=256

#setup the partitions
sfdisk ./disk.img < template.sfdisk

#build the bootloader
cd bootloader
source ./build.sh
cd ..

#put the first 512 bytes of the bootloader at the start of the disk
dd if=./bootloader/bootloader.bin of=./disk.img conv=notrunc bs=512 count=1

#put the rest of the bootloader starting a sector 2048
dd if=./bootloader/bootloader.bin of=./disk.img conv=notrunc bs=512 skip=1 seek=2048