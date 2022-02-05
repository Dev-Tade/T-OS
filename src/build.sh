nasm -f elf32 Boot.asm -o Boot.bin
gcc -ffreestanding -m32 -c Kernel.c -o Kernel.bin
ld -m elf_i386 -T Link.ld -o FullKernel.bin Boot.bin Kernel.bin

rm Kernel.bin
rm Boot.bin
mv FullKernel.bin Kernel.bin