#include <LL.h>

uint8 portReadByte(uint16 port) {
    uint8 result;
    __asm__("in %%dx, %%al": "=a" (result) : "d" (port));
    return result;
}

void portWriteByte(uint16 port, uint8 data) {
    __asm__("out %%al, %%dx": :"a" (data), "d" (port));
}

uint16 portReadWord(uint16 port) {
    uint16 result;
	__asm__("in %%dx, %%ax": "=a" (result) : "d" (port));
	return result;
}

void portWriteWord(uint16 port, uint16 data) {
    __asm__("out %%ax, %%dx": :"a" (data), "d" (port));
}