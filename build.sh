cd src
nasm -felf32 boot/boot.s -o boot.o
gcc -m32 -c kernel/kernel.c -o kernel.o
gcc -m32 -c kernel/drivers/vga/vga.c -o vga.o
gcc -m32 -c kernel/sys/IO.c -o IO.o
gcc -m32 -c kernel/drivers/idt/idt.c -o idt.o
gcc -m32 -c kernel/drivers/keyboard/keyboard.c -o keyboardc.o
nasm -felf32 kernel/drivers/keyboard/keyboard.s -o keyboards.o
ld -m elf_i386 -T Link.ld -o kernel.bin boot.o kernel.o vga.o IO.o keyboardc.o keyboards.o idt.o
rm kernel.o
rm vga.o
rm idt.o
rm keyboards.o
rm keyboardc.o
rm IO.o
rm boot.o
mv kernel.bin ../bin