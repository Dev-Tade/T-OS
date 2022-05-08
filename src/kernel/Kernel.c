#include "screen/Screen.h"

void KernelMain(void)
{
    VGA_INIT;
    Screen_Write("Hello, world\n");
    Move_Cursor(2,4);
    Screen_Put('A');
}