#ifndef _HTIF_H
#define _HTIF_H

#include <stdint.h>
#define HTIF

// volatile uint64_t tohost __attribute__((section(".tohost"), aligned(64)));
// volatile uint64_t fromhost __attribute__((section(".tohost"), aligned(64)));
extern volatile uint64_t tohost;
extern volatile uint64_t fromhost;

void htif_console_putchar(char ch);

void htif_exit(uint8_t code);

#endif