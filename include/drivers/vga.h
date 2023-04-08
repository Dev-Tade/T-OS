#ifndef _VGA_H_
#define _VGA_H_

#include <types.h>

void vgaClearScreen(void);
void vgaPutChar(unsigned char c, int x, int y);

#endif