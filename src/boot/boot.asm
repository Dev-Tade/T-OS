[ORG 0x7C00]

mov ax, 0x0000
mov ds, ax

KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl
mov bp, 0x9000
mov sp, bp

mov ah, 0x02   ; Set AH register to 0x02 (set cursor position)
mov bh, 0x00   ; Set BH register to 0x00 (video page number)
mov dh, 0x00   ; Set DH register to 0x00 (row)
mov dl, 0x00   ; Set DL register to 0x00 (column)
int 0x10       ; Call BIOS interrupt 0x10 to set cursor position

mov bx, MSG_REAL_MODE
call printStr16
call printLn16

call loadKernel
call switchToPM

%include "src/boot/lib/messages.asm"
%include "src/boot/lib/bootlib16.asm"
%include "src/boot/lib/bootlib32.asm"
%include "src/boot/disk.asm"
%include "src/boot/protected/gdt.asm"
%include "src/boot/protected/pm.asm"

[BITS 16]

loadKernel:
    mov bx, MSG_LOAD_KERNEL
    call printStr16
    call printLn16

    mov bx, KERNEL_OFFSET
    mov dh, 50
    mov dl, [BOOT_DRIVE]
    call diskLoad

    ret

[bits 32]
BEGIN_PM:
    mov ebx, MSG_PROT_MODE
    call printStr32

    call KERNEL_OFFSET
    
    mov ebx, MSG_STOP_KERNEL
    call printStr32

    jmp $

BOOT_DRIVE: db 0

times 510-($-$$) db 0
dw 0xAA55