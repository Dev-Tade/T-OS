#include "idt.h"

struct _IDT_ENTRY_ IDT[IDT_SIZE];

void idtInit(void) {
    unsigned long kbdAddr;
    unsigned long idtAddr;
    unsigned long idtPtr[2];
    
    kbdAddr = (unsigned long) keyboardHandler;
    
    IDT[0x21].offsetLowerBits = kbdAddr & 0xFFFF;
    IDT[0x21].selector = KERNEL_CODE_SEGMENT_OFFSET;
    IDT[0x21].zero = 0;
    IDT[0x21].typeAttribute = INTERRUPT_GATE;
    IDT[0x21].offsetHigherBits = (kbdAddr & 0xFFFF0000) >> 16;
    
    /* ICW 1 */
    portWrite(0x20, 0x11);
    portWrite(0xA0, 0x11);
    /* ICW 2 */
    portWrite(0x21, 0x20);
    portWrite(0xA1, 0x28);
    /* ICW 3 */
    portWrite(0x21, 0x00);
    portWrite(0xA1, 0x00);
    /* ICW 4 */
    portWrite(0x21, 0x01);
    portWrite(0xA1, 0x01);
    /* MASK */
    portWrite(0x21, 0xFF);
    portWrite(0xA1, 0xFF);
    
    /* FILL IDT */
    idtAddr = (unsigned long) IDT;
    idtPtr[0] = (sizeof(struct _IDT_ENTRY_) * IDT_SIZE) + ((idtAddr & 0xFFFF) << 16);
    idtPtr[1] = idtAddr >> 16;
    
    idtLoad(idtPtr);
    return;
}

void idtLoad(unsigned long *ptr) {
    __asm__("lidt (%0)\n\t"
            "sti"
            :
            : "r"(ptr)
            : "memory");
    return;
}