cd src
nasm -f elf32 boot/Boot.s -o Boot.o
gcc -m32 -c kernel/Kernel.c -o Kernel.o
gcc -m32 -c kernel/screen/Screen.c -o Screen.o
gcc -m32 -c kernel/sys/IO.c -o IO.o
ld -m elf_i386 -T Link.ld -o Kernel.bin Boot.o Kernel.o Screen.o IO.o
rm Kernel.o
rm Screen.o
rm IO.o
rm Boot.o
mv Kernel.bin ../bin