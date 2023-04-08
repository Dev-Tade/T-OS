diskLoad:
    push dx         ; Save DX register
    
    mov ah, 0x02    ; Operation: Read Sectors
    mov al, dh      ; N of sectors to read, passed as argument before call
    
    mov ch, 0x00    ; Cylinder 0
    mov dh, 0x00    ; Head 0
    mov cl, 0x02    ; Sector 2
    int 0x13        ; BIOS interrupt

    jc diskError    ; Raise error if carry

    pop dx          ; Recover DX register
    cmp dh, al      ; Check for READED_SECTORS == N_SECTORS
    jne diskError   ; Raise error if READED_SECTORS != N_SECTORS
    
    ret

diskError:
    mov bx, DISK_ERROR_MSG
    call printStr16
    call printLn16
    jmp $

DISK_ERROR_MSG: db "Disk read error! ",0