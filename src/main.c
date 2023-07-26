#include <avr/io.h>
#include <avr/delay.h>
#include <stdbool.h>
#include "utils.h"
#include "io.h"

#define BAUD_RATE 115200


static bool _stop = false;


int main(void)
{
  uart_init(RXEN0, TXEN0, BAUD_RATE);
  
  while (_stop != true) {
    uart_write("Hello, World\n", 13);
    _delay_ms((500)*3);
  }

  return 0;
}
