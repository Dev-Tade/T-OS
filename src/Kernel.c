#include "TOS.h"

void main(void)
{
    Terminal_Buffer = (unsigned short*)VGA_ADDRESS;
    VGA_Index = 0;

    Clear();
    Println("T-OS", RED);
    Println("An experimental OS written in:", GREEN);
    Println("Assembly & C", PURPLE);
    Putchar('T', 0, YELLOW);
    while (1){}
}
