#include "htif.h"

void htif_console_putchar(char ch)
{
	while (tohost)
		fromhost = 0;
	tohost = (0x0101000000000000 | (unsigned char)ch);
}

void htif_exit(uint8_t code)
{
	tohost = (code << 1) | 1;
	while (1)
		;
}