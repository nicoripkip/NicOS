#include <avr/io.h>
#include <stdbool.h>
#include "utils.h"
#include "io.h"

#define BAUD_RATE 115200


static bool _stop = false;


void _delay(u64 s)
{
  for (u64 i = 0; i < s; i++) {

  }
}


int main(void)
{
  uart_init(RXEN0, TXEN0, BAUD_RATE);
  
  while (_stop != true) {
    uart_write("Hello, World", 12);
    // _delay_ms(500);

    _delay(2 * F_CPU);
  }

  return 0;
}
