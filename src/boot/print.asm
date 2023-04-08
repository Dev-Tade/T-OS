printStrRM:
    pusha
    mov ah, 0x0E
    PSRM_loop:
        mov al, [bx]
        int 0x10
        add bx, 0x01
        mov cx, [bx]
        cmp cl, 0
        jne PSRM_loop
    
    popa
    ret
