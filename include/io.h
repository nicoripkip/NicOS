#include <stdio.h>
#include "utils.h"


#ifndef __NICOS__IO__
#define __NICOS__IO__


void uart_init(u8 rx, u8 tx, u64 baud);
char uart_read();
void uart_write(char *buffer, size_t size);


#endif
