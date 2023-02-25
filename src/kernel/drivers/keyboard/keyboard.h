#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include "../../types.h"
#include "../../drivers/vga/vga.h"
#include "../../sys/IO.h"

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

#define KEYBOARD_ENTER_KEYCODE 0x1C
#define KEYBOARD_BACKSPACE_KEYCODE 0x0E
#define KEYBOARD_ESCAPE_KEYCODE 0x01

#define KEYBOARD_ARROW_UP_KEYCODE    0x48
#define KEYBOARD_ARROW_DOWN_KEYCODE  0x50
#define KEYBOARD_ARROW_LEFT_KEYCODE  0x4B
#define KEYBOARD_ARROW_RIGHT_KEYCODE 0x4D

extern void keyboardHandler(void);

void keyboardMain(void);
void keyboardEnable(void);
void keuyboardDisable(void);

static u8int keybardMap[128] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};

static u8int specialKeysMap[28] = {
  0x01, 0x1C, 0x0E, // ESC, ENTER, BACKSPACE
  0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, // F1 - F6
  0x41, 0x42, 0x43, 0x44, 0x57, 0x58, // F7 - F12
  0x4B, 0x48, 0x4D, 0x50, // LEFT, UP, RIGHT, DOWN Arrows
  0x52, 0x53, 0x47, 0x4F, // INSERT, DELETE, HOME, END
  0x49, 0x51, 0x37, // PG UP, PG DOWN, PRINT SCREEN
  0x45, 0x46, // PAUSE/BREAK / NUM-LOCK, SCROLL-LOCK
};

#endif