#include "IO.h"

void portWrite(u16int port, u8int data) {
    __asm ("out %%al, %%dx" : : "a"(data), "d"(port));
}

u8int portRead(u16int port) {
    u8int result;
    __asm ("in %%dx, %%al" : "=a"(result) : "d"(port));
    return result;
}