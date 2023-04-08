#include <types.h>
#include <drivers/vga.h>

void kernel(void) {
	vgaClearScreen();
	vgaPutChar('H', 1, 1);
	vgaPutChar('i', 2, 1);
}