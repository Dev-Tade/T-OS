cd src
nasm -f elf32 boot/Boot.s -o Boot.o
gcc -m32 -c kernel/Kernel.c -o Kernel.o
ld -m elf_i386 -T Link.ld -o Kernel.bin Boot.o Kernel.o
rm Kernel.o
rm Boot.o
mv Kernel.bin ../bin