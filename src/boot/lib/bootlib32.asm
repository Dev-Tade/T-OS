[BITS 32]

printStr32:
    pusha                   ; Save all registers
    mov edx, VIDEO_MEMORY   ; Load VGA PTR
    PS32_loop:
        mov al, [ebx]       ; Load character
        mov ah, WONB        ; Set color

        cmp al, 0
        je PS32_done

        mov [edx], ax

        add ebx, 1
        add edx, 2

        jmp PS32_loop
PS32_done:
    popa
    ret

VIDEO_MEMORY: equ 0xB8000
WONB: equ 0x0F