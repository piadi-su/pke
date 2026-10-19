#include "kernel.h"

// clear the screen
// puts prompt
// get input
// exec commnad
// 	-clear
// 	-fetch
// 	-help

#define VGA_COLOR_BLACK 0x0
#define VGA_COLOR_GREEN 0x2
#define VGA_COLOR_LIGHT_GREEN 0xA
#define VGA_COLOR_WHITE 0xF
#define VGA_COLOR_LIGHT_GREY 0x7

//pointer to the vga output 
volatile char *vga_buffer = (volatile char *) 0xB8000;
int cursor_row = 0; //form 0 to 24
int cursor_col = 0; //form 0 to 79


void
vga_clear_screen(){

	for(int i = 0 ;i < 80 * 25 *2; i += 2){
		vga_buffer[i] = ' ';
		vga_buffer[i + 1] = VGA_COLOR_LIGHT_GREY ;

	}

	cursor_row = 0;
	cursor_col = 0;
}

//prints just a sigle char + his color
void
vga_putsc(char c, char color){

	if (c == '\n'){
		cursor_row++;
		cursor_col=0;
		return;
	}

	int index = (cursor_row * 80 + cursor_col) * 2;
	vga_buffer[index] = c;
	vga_buffer[index + 1] = color;
	cursor_col++;

	if(cursor_col >= 80){
		cursor_col = 0;
		cursor_row++;
	}

}

void
vga_print(const char *str, char color){
	for(int i = 0; str[i] != '\0'; i++){
		vga_putsc(str[i], color);
	}

}

//--


void cmd_fetch() {
    vga_print("\n", VGA_COLOR_WHITE);
    vga_print("    ____  _  _______ \n", VGA_COLOR_LIGHT_GREEN);
    vga_print("   |  _ \\| |/ / ____|    OS: PKE Mini-Kernel (32-bit)\n", VGA_COLOR_LIGHT_GREEN);
    vga_print("   | |_) | ' /|  _|      Arch: i686 Bare-Metal\n", VGA_COLOR_LIGHT_GREEN);
    vga_print("   |  __/| . \\| |___\n", VGA_COLOR_LIGHT_GREEN);
    vga_print("   |_|   |_|\\_\\_____|    Boot: Custom x86 Bootloader\n", VGA_COLOR_LIGHT_GREEN);
    vga_print("\n", VGA_COLOR_WHITE);
}


void cmd_help(){

	vga_print("\ncommands:\n", VGA_COLOR_WHITE);
	vga_print("help display this\n", VGA_COLOR_GREEN);
	vga_print("clear clears the screen\n", VGA_COLOR_GREEN);
	vga_print("fetch show os logo + some infos\n", VGA_COLOR_GREEN);
	vga_print("\n", VGA_COLOR_WHITE);
}



void kernel_main(){
	//clear screen buffer
	vga_clear_screen();
	vga_clear_screen();

	char *vga_buffer = (char *) 0xB8000;

	vga_print("=== welcome to pke a simple kernel written in c ===\n", VGA_COLOR_LIGHT_GREEN);
	vga_print("=== creds: piadi-su ===\n\n", VGA_COLOR_LIGHT_GREY);

	cmd_fetch();
	cmd_help();



}
