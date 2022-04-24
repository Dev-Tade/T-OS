#ifndef SCREEN_H
#define SCREEN_H

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

unsigned short* VGA_Memory;
unsigned int VGA_Index;

unsigned int XCursor;
unsigned int YCursor;

void __INIT_VGA__();
#define VGA_INIT __INIT_VGA__()

void Screen_Put(char c);
void Screen_Set(int x, int y, char c);
void Screen_Write(char* str);
void Screen_Clear();

void Move_Cursor(int x, int y);

#endif