#include "keyboard.h"

void keyboardInit(void) {
    portWrite(0x21, 0xFD);
}

void keyboardDisable(void) {
    u8int mask = portRead(0x21) | 0x02;
    portWrite(0x21, mask);
    return;
}

void keyboardMain(void) {
    u8int status;
    char keycode;
    
    portWrite(0x20, 0x20);
    
    status = portRead(KEYBOARD_STATUS_PORT);
    if (status & 0x01) {
        keycode = portRead(KEYBOARD_DATA_PORT);
        if (keycode < 0)
            return;
        if (keycode == KEYBOARD_ENTER_KEYCODE) {
            vgaPutc('\n');
            return;
        }
        
        if (keycode == KEYBOARD_ESCAPE_KEYCODE)
            keyboardDisable();
        
        vgaPutc(kbd_map[(u8int)keycode]);
    }
}