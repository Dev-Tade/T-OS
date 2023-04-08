GDT_START:
GDT_NULL:
    dd 0x00
    dd 0x00
GDT_CODE:
    dw 0xFFFF
    dw 0x00
    db 0x00
    db 10011010b
    db 11001111b
    db 0x00
GDT_DATA:
    dw 0xFFFF
    dw 0x00
    db 0x00
    db 10010010b
    db 11001111b
    db 0x00
GDT_END:
GDT_DESCRIPTOR:
    dw GDT_END - GDT_START - 1
    dd GDT_START

CODE_SEGMENT: equ GDT_CODE - GDT_START
DATA_SEGMENT: equ GDT_DATA - GDT_START