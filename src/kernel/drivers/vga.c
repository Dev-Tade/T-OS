#include <types.h>
#include <drivers/vga.h>

static uint16* const VGA_MEM = (uint16*)0xB8000;

void vgaClearScreen(void) {
    const uint8 color = vgaEntryColor(VGA_COLOR_BLACK, VGA_COLOR_LIGHT_GREY);
    const uint16 blank = vgaEntry(' ', color);

    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            const int index = y * 80 + x;
            VGA_MEM[index] = blank;
        }
    }
}

void vgaPutChar(unsigned char c, int x, int y) {
    const uint8 color = (VGA_COLOR_BLACK << 4) | VGA_COLOR_WHITE;
    VGA_MEM[y * 80 + x] = ((uint16)color << 8) | c;
}