#include "keyboard.h"

void keyboardEnable(void) {
    portWrite(0x21, 0xFD);
    return;
}

void keyboardDisable(void) {
    u8int mask = portRead(0x21) | 0x02;
    portWrite(0x21, mask);
    return;
}

void keyboardMain(void) {
    u8int status;
    char keycode;
    char ignored;
    
    portWrite(0x20, 0x20);
    
    status = portRead(KEYBOARD_STATUS_PORT);
    if (status & 0x01) {
        keycode = portRead(KEYBOARD_DATA_PORT);
        
        if (keycode < 0)
            return;
            
        if (keycode == KEYBOARD_ENTER_KEYCODE)
            vgaPutc('!');
            
        if (keycode == KEYBOARD_ESCAPE_KEYCODE)
            keyboardDisable();
            
        if (keycode == KEYBOARD_ARROW_UP_KEYCODE) {
            vgaMoveCursor(__vgaX, __vgaY-1);
        } else if (keycode == KEYBOARD_ARROW_DOWN_KEYCODE) {
            vgaMoveCursor(__vgaX, __vgaY+1);// handle down arrow
        } else if (keycode == KEYBOARD_ARROW_LEFT_KEYCODE) {
            vgaMoveCursor(__vgaX-1, __vgaY);// handle left arrow
        } else if (keycode == KEYBOARD_ARROW_RIGHT_KEYCODE) {
            vgaMoveCursor(__vgaX+1, __vgaY);// handle right arrow
        } else {
            vgaPutc(keybardMap[(u8int)keycode]);
        }
    }
}