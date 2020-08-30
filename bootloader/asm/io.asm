
section .text

BITS 32

;uint8_t io_in8(uint16_t portnum);
io_in8:
    push ebp
    mov ebp, esp

    mov dx, [ebp+8]

    xor eax, eax
    in al, dx

    mov esp, ebp
    pop ebp
    ret

;uint16_t io_in8(uint16_t portnum);
io_in16:
    push ebp
    mov ebp, esp

    mov dx, [ebp+8]

    xor eax, eax
    in ax, dx

    mov esp, ebp
    pop ebp
    ret

;uint32_t io_in8(uint16_t portnum);
io_in32:
    push ebp
    mov ebp, esp

    mov dx, [ebp+8]

    xor eax, eax
    in eax, dx

    mov esp, ebp
    pop ebp
    ret

;void io_out8(uint16_t portnum, uint8_t val)
io_out8:
    push ebp
    mov ebp, esp

    mov dx, [ebp+8]
    mov al, [ebp+12]

    out dx, al

    mov esp, ebp
    pop ebp
    ret

io_out16:
    push ebp
    mov ebp, esp

    mov dx, [ebp+8]
    mov ax, [ebp+12]

    out dx, ax

    mov esp, ebp
    pop ebp
    ret

io_out32:
    push ebp
    mov ebp, esp

    mov dx, [ebp+8]
    mov eax, [ebp+12]

    out dx, eax

    mov esp, ebp
    pop ebp
    ret