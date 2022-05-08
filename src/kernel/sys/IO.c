#include "IO.h"
#include "Types.h"

void outb(u16int port, u8int value)
{
    __asm __volatile__("outb %1, %0" : : "dN" (port), "a" (value));
}

s8int inb(u16int port)
{
    s8int ret;
    __asm __volatile__("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

u16int inw(u16int port)
{
    u16int ret;
    __asm __volatile__("inw %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}