#include "Screen.h"

u16int* VGA_Memory;
u32int VGA_Index;

void __INIT_VGA__()
{
    VGA_Memory=(unsigned short*)VGA_ADDRESS;
    VGA_Index=0;
    YCursor=0;
    XCursor=0;
    Move_Cursor(0, 0);
    Screen_Clear();
}

void Screen_Put(s8int c)
{
    if (c == '\n') {Move_Cursor(0, YCursor+1);}
    else
    {
        VGA_Memory[VGA_Index] = c | (unsigned)GRAY << 8;
        VGA_Index++;
        XCursor++;
    }
}

void Screen_Write(s8int* String)
{
    int strx = 0;
    while (String[strx] != '\0')
    {
        Screen_Put(String[strx]);
        strx++;
    }
}

void Screen_Clear()
{
    Move_Cursor(0, 0);
    while (VGA_Index < SCREEN_SIZE) {Screen_Put(' ');}
    Move_Cursor(0, 0);
}

void Screen_Set(s32int x, s32int y, s8int c)
{
    VGA_Memory[y * SCREEN_WIDTH + x] = c | (unsigned)GRAY << 8;
}

void Move_Cursor(s32int x, s32int y)
{
    if (x > 80) {x = 0; y += 1;}
    if (y > 25) {y = 0;}
    XCursor = x;
    YCursor = y;
    VGA_Index = XCursor + YCursor * 80;
}