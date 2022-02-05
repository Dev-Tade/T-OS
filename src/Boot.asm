bits 32

section .multiboot
        dd 0x1BADB002

        dd 0x0
        dd - (0x1BADB002 + 0x0)

section .text
global start
extern main     ;Kernel from Kernel.C

start:
        cli                     ;Block Interrupts
        mov esp, stack_space    ;Set Stack Pointer
        call main
        hlt                     ;Halt the CPU

section .bss
resb 8192   ;8KB For Stack
stack_space: