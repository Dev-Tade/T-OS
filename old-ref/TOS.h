#ifndef TOS_H
#define TOS_H

/* GRAPICHS */
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

unsigned short* Terminal_Buffer;
unsigned int VGA_Index;

void Putchar(char Chr, char Color); //DEPRECATED
void Println(char* String, char Color);
void Scr_Clear(void);

#endif