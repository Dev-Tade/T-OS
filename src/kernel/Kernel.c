#include "screen/Screen.h"

void KernelMain(void)
{
    VGA_INIT;
    Screen_Write("Hello, world\n");
}
