cd src

nasm -f elf32 Boot.asm -o Boot.o
gcc -ffreestanding -m32 -c Kernel.c -o Kernel.o
gcc -ffreestanding -m32 -c TOS.c -o TOS.o
ld -m elf_i386 -T Link.ld -o Kernel.bin Boot.o Kernel.o TOS.o

rm Kernel.o
rm Boot.o
rm TOS.o