#include "drivers/vga/vga.h"
#include "drivers/idt/idt.h"
#include "drivers/keyboard/keyboard.h"

void kernel(void)
{
    __VGA_INIT__();
    vgaWriteString("Hello Kernel\n");
    
    idtInit();
    keyboardInit();
}