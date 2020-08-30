BITS 16

global boot

extern boot_main


section .boot

boot:

    cli

    ;setup 16bit segment registers
    mov ax, 0x0000
    mov ds, ax
    mov es, ax
    mov fs, ax

    ;setup the stack to the memory below where we are loaded
    mov ax, 0x0000
    mov ss, ax
    mov sp, 0x7B00

    sti

    jmp start

vars:

    drive_num: db 0x00
    
    started_string: db "The Bootloader has started Running", 0
    stage2_loaded: db "The Bootloader has loaded stage 2", 0
    got_memory_map: db "Retrieved Bios Memory Map", 0
    got_all_memory_maps: db "Retrieved All Bios Memory Maps", 0
    a20_enabled: db "A20 address line enabled", 0
    boot2_hello: db "Boot 2 has successfully started running",0

    error_message: db "An Error has occured", 0

    gdt_start:
        dq 0x0
    gdt_code:
        dw 0xFFFF
        dw 0x0
        db 0x0
        db 10011010b
        db 11001111b
        db 0x0
    gdt_data:
        dw 0xFFFF
        dw 0x0
        db 0x0
        db 10010010b
        db 11001111b
        db 0x0
    gdt_end:

    gdt_pointer:
        dw gdt_end - gdt_start
        dd gdt_start

    CODE_SEG equ gdt_code - gdt_start
    DATA_SEG equ gdt_data - gdt_start

    dap: ;disk address packet (for loading stage2)
        db 0x10         ;size of dap
        db 0x00         ;unused padding
        dw 0x004F       ;sectors to read 63.5 kb
        dw 0x7E00       ;offset of memory address to read to  
        dw 0x0000       ;segment of memory address to read to
        dq 0x00000001   ;disk sector to start at
start:
    ;x86 cpu starts in 16bit mode
    ;this bootloader program is loaded at 0x7c00

    ;dl (should) start of with the drive index
    ;save that value in memory for later
    mov [drive_num], dl

    ;set video mode so that we know what we are writing to
    mov ah, 0x00
    mov al, 0x03
    int 0x10

    ;disable the cursor
    mov ah, 0x01
    mov ch, 0x3f
    int 0x10

    mov si, started_string
    call puts
    call newline

    call load_stage2

    mov si, stage2_loaded
    call puts
    call newline


    ;get a memory map from the bios
    call bios_mem_map

    mov si, got_all_memory_maps
    call puts
    call newline

    ;enable the a20 address line
    mov ax, 0x2401
    int 0x15

    mov si, a20_enabled
    call puts
    call newline

    ;load the gdt
    lgdt [gdt_pointer]
    mov eax, cr0
    or eax, 0x01
    mov cr0, eax

    ;reset all the segment registers
    mov eax, 0x10
    mov ds, eax
    mov es, eax
    mov fs, eax
    mov gs, eax
    mov ss, eax

    jmp 0x08:boot2

    cli
    hlt
    
    
;function that expects si to be a pointer to a null terminated string
puts:
    pusha
    mov ah, 0x0e    ;write character at cursor position

.loop:
    lodsb           ;load byte pointed to by ds:si into al
    or al,al        ;check for null byte
    jz .end         ;if there is a null byte then goto end
    int 0x10        ;bios interrupt 0x10 - video stuff
    jmp .loop

.end:
    popa
    ret

;moves the cursor onto a new line
newline:
   pusha
    
    ;get current cursor position
    mov ah, 0x03
    mov bh, 0x00
    int 0x10

    ;adjust cursor position to newline
    inc dh
    mov dl, 0

    ;set cursor position
    mov ah, 0x02
    int 0x10

    popa
    ret

load_stage2:

    pusha

    mov ah, 0x42        ;Extended read sectors from drive
    mov dl, [drive_num] ;set the drive number
    mov si, dap         ;point si at the disk address packet

    int 0x13

    jc error

    popa
    ret

;loads data from the bios memory map function into the start of the 30kb memory space starting at 0x0500
bios_mem_map:
    pusha

    mov di, 0x0500
    xor ebx, ebx

.loop:

    mov eax, 0x0000E820
    mov ecx, 24
    mov edx, 0x534D4150

    int 0x15
    jc error
    or ebx, ebx
    jz .end
    add di, 24

    mov si, got_memory_map
    call puts
    call newline

    jmp .loop
.end:

    mov ax, 0x0000
    mov es, ax

    popa
    ret
    
error:
    mov si, error_message
    call puts
    call newline

    cli
    hlt

;fill out to 512 bytes and add the signature bytes to identify this as a mbr
times 510-($-$$) db 0x00
dw 0xaa55

;this bit of the bootloader is now in 32bit mode

BITS 32

boot2:
    mov esi, boot2_hello
    mov ebx, 0xb8000
.loop:
    lodsb
    or al, al
    jz .end
    or eax, 0x0100
    mov word [ebx], ax
    add ebx, 2
    jmp .loop

.end:

    ;readjust the stack for the bootloader main call
    mov esp, kernel_stack_top
    call boot_main

bootloader_halt:
    cli
    hlt

section .bss

align 4

kernel_stack_bottom: equ $
    resb 16*1024
kernel_stack_top: