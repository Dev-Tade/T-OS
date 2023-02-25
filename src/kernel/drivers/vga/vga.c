#include "vga.h"

u16int* __vgaMem;
u32int __vgaIdx;
u16int __vgaX;
u16int __vgaY;

void __VGA_INIT__(void) {
    __vgaMem = (u16int*)VGA_ADDRESS;
    __vgaIdx = 0;
    __vgaX = 0;
    __vgaY = 0;
    
    vgaClear();
    
    return;
}

void vgaClear(void) {
    vgaMoveCursor(0, 0);
    
    while (__vgaIdx < VGA_BUFFER_SIZE)
        vgaPutc(' ');
        
    vgaMoveCursor(0, 0);
    return;
}

void vgaPutc(char c) {
    if (c == '\n')
        vgaMoveCursor(0, __vgaY + 1);
    else if (c == '\t') {
        vgaPutc(' '); vgaPutc(' ');
    } else if (c == '\b') {
        vgaMoveCursor(__vgaX-1, __vgaY);
        vgaPutc(' ');
        vgaMoveCursor(__vgaX-1, __vgaY);
    } else {
        __vgaMem[__vgaIdx] = c | (unsigned)WHITE << 8;
        __vgaIdx++;
        __vgaX++;
    }
    
    return;
}

void vgaWriteString(string str) {
    u16int cntr = 0;
    while (str[cntr] != '\0') {
        vgaPutc(str[cntr]);
        cntr++;
    }
    return;
}


void vgaMoveCursor(u16int x, u16int y) {
    if (x > 80) { x = 0; y += 1; }
    if (y > 25) y = 0;
    
    __vgaX = x;
    __vgaY = y;
    __vgaIdx = __vgaX + __vgaY * 80;
}