#ifndef _LL_H_
#define _LL_H_

#include <types.h>

uint8 portReadByte(uint16 port);
void portWriteByte(uint16 port, uint8 data);

uint16 portReadWord(uint16 port);
void portWriteWord(uint16 port, uint16 data);

#endif