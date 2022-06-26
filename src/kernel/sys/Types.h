#ifndef TYPES_H
#define TYPES_H

typedef unsigned int   u32int;
typedef          int   s32int;
typedef unsigned short u16int;
typedef          short s16int;
typedef unsigned char  u8int;
typedef          char  s8int;

typedef s8int* string;

typedef enum {
    false = 0,
    true = 1
} bool;

#define u32int u32int
#define s32int s32int
#define u16int u16int
#define s16int s16int
#define u8int  u8int
#define s8int  s8int

#define string string
#define bool bool

#define false false
#define true true

#endif