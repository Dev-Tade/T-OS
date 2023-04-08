[ORG 0x7C00]

mov ax, 0x0000
mov ds, ax

KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl
mov bp, 0x9000
mov sp, bp

mov bx, MSG_REAL_MODE
call printStrRM

call loadKernel
call switchToPM

%include "src/boot/print.asm"
%include "src/boot/disk.asm"
%include "src/boot/pm/gdt.asm"
%include "src/boot/pm/pm.asm"

[BITS 16]

loadKernel:
    mov bx, MSG_LOAD_KERNEL
    call printStrRM

    mov bx, KERNEL_OFFSET
    mov dh, 50
    mov dl, [BOOT_DRIVE]
    call diskLoad

    ret

[bits 32]
BEGIN_PM:
    mov ebx, MSG_PROT_MODE
    call printStrPM

    call KERNEL_OFFSET
    mov ebx, MSG_STOP_KERNEL
    call printStrPM
    jmp $

BOOT_DRIVE: db 0

MSG_REAL_MODE: db "Started 16-Bit: Real Mode ",0
MSG_PROT_MODE: db "Successfully loaded 32-Bit: Protected Mode ",0
MSG_LOAD_KERNEL: db "Loading Kernel into memory ",0
MSG_STOP_KERNEL: db "Kernel stopped. Please try again ",0

times 510-($-$$) db 0
dw 0xAA55