[BITS 16]

switchToPM:
    cli
    lgdt [GDT_DESCRIPTOR]

    mov eax, cr0
    or eax, 0x01
    mov cr0, eax

    jmp CODE_SEGMENT:INIT_PM

[BITS 32]

INIT_PM:
    mov ax, DATA_SEGMENT
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000
    mov esp, ebp

    call BEGIN_PM

printStrPM:
    pusha                   ; Save all registers
    mov edx, VIDEO_MEMORY   ; Load VGA PTR
    PSPM_loop:
        mov al, [ebx]       ; Load character
        mov ah, WONB        ; Set color

        cmp al, 0
        je PSPM_done

        mov [edx], ax

        add ebx, 1
        add edx, 2

        jmp PSPM_loop
PSPM_done:
    popa
    ret

VIDEO_MEMORY: equ 0xB8000
WONB: equ 0x0F