#include <types.h>
#include <drivers/vga.h>

static uint16* const VGA_MEM = (uint16*)0xB8000;

void vgaClearScreen(void) {
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            const int index = y * 80 + x;
            VGA_MEM[index] = ' ' | 0x0F << 8;
        }
    }
}

void vgaPutChar(unsigned char c, int x, int y) {
    VGA_MEM[y * 80 + x] = c | (0xF0 << 8);
}