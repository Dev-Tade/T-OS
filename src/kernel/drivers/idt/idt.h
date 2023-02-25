#ifndef _IDT_H_
#define _IDT_H_

#include "../../sys/IO.h"
#include "../../types.h"
#include "../../drivers/keyboard/keyboard.h"

#define IDT_SIZE 256

#define INTERRUPT_GATE 0x8e
#define KERNEL_CODE_SEGMENT_OFFSET 0x08

struct _IDT_ENTRY_ {
    u16int offsetLowerBits;
    
    u16int selector;
    u8int zero;
    u8int typeAttribute;
    
    u16int offsetHigherBits
};

void idtLoad(unsigned long *ptr);
void idtInit(void);

#endif