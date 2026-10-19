#ifndef KERNEL_H 
#define KERNEL_H 

void kernel_main();

void vga_clear_screen();
void vga_putsc(char c, char color);
void vga_print(const char *str, char color);

void cmd_fetch();
void cmd_help();

#endif
