#ifndef TYPES_H
#define TYPES_H

typedef unsigned int   u32int;
typedef          int   s32int;
typedef unsigned short u16int;
typedef          short s16int;
typedef unsigned char  u8int;
typedef          char  s8int;

typedef s8int* string;

typedef enum state_e
{
    on = 1,
    off = 0
} state_t;


#endif