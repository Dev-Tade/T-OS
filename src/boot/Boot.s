bits 32
section .text
        align 4
        dd 0x1BADB002
        dd 0x00
        dd - (0x1BADB002 + 0x00)
global start
extern KernelMain
start:
        cli
        mov esp, stack_space
        call KernelMain
        hlt
section .bss
resb 8192
stack_space: