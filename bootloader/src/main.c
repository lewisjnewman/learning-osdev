


void boot_main(){
    
    const short color = 0x0F00;
    const char* hello = "Hello from C";
    short* vga = (short*)0xb8000;

    for (int i = 0; i < 12; i++){
        vga[i+80] = color | hello[i];
    }
}