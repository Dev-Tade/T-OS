#ifndef SCREEN_H
#define SCREEN_H

#include "../sys/Types.h"

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define SCREEN_SIZE SCREEN_WIDTH * SCREEN_HEIGHT * 2

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

u16int* VGA_Memory;
u32int VGA_Index;

u32int XCursor;
u32int YCursor;

void __INIT_VGA__();
#define VGA_INIT __INIT_VGA__()

void Screen_Put(s8int c);
void Screen_Set(s32int x, s32int y, s8int c);
void Screen_Write(s8int* str);
void Screen_Clear();

void Move_Cursor(s32int x, s32int y);

#endif