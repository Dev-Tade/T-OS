[BITS 32]
global _start
extern kernel

_start:
    call kernel
    jmp $