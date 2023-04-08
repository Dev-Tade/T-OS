[BITS 16]

switchToPM:
    mov bx, MSG_KERNEL_READY
    call printStr16
    call printLn16
    call readChr16
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