#include "screen/Screen.h"
#include "keyboard/Keyboard.h"

void Kernel(void)
{
    VGA_INIT
    Screen_Write("Hello, world\n");
    Move_Cursor(3,5);
    Screen_Put('\t');
    ReadStr(false);
}