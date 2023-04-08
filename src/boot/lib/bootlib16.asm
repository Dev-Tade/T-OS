[BITS 16]

clearScr16:
    mov ah, 0x06
    mov al, 0x00
    mov bh, 0x07
    mov cx, 0x00
    mov dx, 0x184f
    int 0x10

printStr16:
    pusha
    mov ah, 0x0E
    PS16_loop:
        mov al, [bx]
        int 0x10
        add bx, 0x01
        mov cx, [bx]
        cmp cl, 0
        jne PS16_loop
    
    popa
    ret

printLn16:
    mov ah, 02h
    mov bh, 0
    mov dl, 0
    inc dh
    int 10h
    ret

readChr16:
    mov ah, 00h
    int 16h
    ret
