CC = gcc
CF = -m32 -g -Wall -fno-pie -fno-stack-protector -Werror $(addprefix -I,$(wildcard include))

AS = nasm

EMU = qemu-system-i386
EMUFLAGS = -device isa-debug-exit,iobase=0xf4,iosize=0x04 -fda

C_SOURCES = src/kernel/kernel.c src/kernel/drivers/vga.c

all: TOS.img

kernel.bin: kernel_entry.o kernel.o vga.o
	$(LD) -m elf_i386 -o $@ -T src/Link.ld $^ --oformat binary

kernel_entry.o: src/kernel/kernel_entry.asm
	$(AS) -f elf $< -o $@

kernel.o: src/kernel/kernel.c
	$(CC) $(CF) -ffreestanding -c $< -o $@

boot.bin: src/boot/*.asm
	$(AS) -f bin $< -o $@

vga.o: src/kernel/drivers/vga.c
	$(CC) $(CF) -ffreestanding -c $< -o $@

TOS.img: boot.bin kernel.bin
	dd if=/dev/zero of=$@ bs=1024 count=1440
	dd if=boot.bin of=$@ conv=notrunc
	dd if=kernel.bin of=$@ seek=1 conv=notrunc

clean:
	rm -rf *.bin
	rm -rf *.o

run: all TOS.img
	$(EMU) $(EMUFLAGS) TOS.img
	make clean