#include "source.h"
#include "keyboard.h"

void OS(void);

void main(void)
{
    terminal_buffer = (unsigned short*)VGA_ADDRESS;
    vga_index = 0;

    clear_screen();
    print_string("Welcome to cOS", RED);
    vga_index = 50;
    print_string("an experimental OS written in:", YELLOW);
    vga_index = 100;
    print_char('C', RED);
    vga_index = 640;
    while (1)
    {
        keyboard_handler();
    }

    return;
}