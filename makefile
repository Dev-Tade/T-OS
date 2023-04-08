CC = gcc
CF = -m32 -g -Wall -fno-pie -fno-stack-protector -Werror $(addprefix -I,$(wildcard include))

AS = nasm

EMU = qemu-system-i386
EMUFLAGS = -device isa-debug-exit,iobase=0xf4,iosize=0x04 -fda

all: TOS.img

O_FILES = kernel_entry.o kernel.o ll.o vga.o

kernel.bin: ${O_FILES}
	$(LD) -m elf_i386 -o $@ -T src/Link.ld $^ --oformat binary

kernel_entry.o: src/kernel/kernel_entry.asm
	$(AS) -f elf $< -o $@

kernel.o: src/kernel/kernel.c
	$(CC) $(CF) -ffreestanding -c $< -o $@

boot.bin: src/boot/*.asm
	$(AS) -f bin $< -o $@

vga.o: src/kernel/drivers/vga.c
	$(CC) $(CF) -ffreestanding -c $< -o $@

ll.o: src/kernel/ll.c
	$(CC) $(CF) -ffreestanding -c $< -o $@

TOS.img: boot.bin kernel.bin
	dd if=/dev/zero of=$@ bs=1024 count=1440
	dd if=boot.bin of=$@ conv=notrunc
	dd if=kernel.bin of=$@ seek=1 conv=notrunc

clean:
	rm -rf *.bin
	rm -rf *.o
	rm TOS.img

run: all TOS.img
	$(EMU) $(EMUFLAGS) TOS.img
	make clean