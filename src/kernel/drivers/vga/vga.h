#ifndef _VGA_H_
#define _VGA_H_

#include "../../types.h"

#define VGA_BUFFER_WIDTH 80
#define VGA_BUFFER_HEIGHT 25
#define VGA_BUFFER_SIZE (VGA_BUFFER_WIDTH * VGA_BUFFER_HEIGHT * 2)

#define VGA_ADDRESS 0xB8000

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define PURPLE 5
#define BROWN 6
#define GRAY 7
#define DARK_GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define YELLOW 14
#define WHITE 15

extern u16int* __vgaMem;
extern u32int __vgaIdx;
extern u16int __vgaX;
extern u16int __vgaY;

void __VGA_INIT__(void);

void vgaClear(void);
void vgaPutc(char c);
void vgaWriteString(string str);
void vgaMoveCursor(u16int x, u16int y);

#endif