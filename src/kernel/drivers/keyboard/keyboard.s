[BITS 32]

global keyboardHandler
extern keyboardMain

keyboardHandler:
    call keyboardMain
    iretd