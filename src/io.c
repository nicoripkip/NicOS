#include "io.h"
#include "utils.h"
#include <stdio.h>
#include <math.h>
#include <avr/io.h>
#include <avr/delay.h>


#define m 16UL


/**
 * Function to setup the uart registers
 *
 * @param rx
 * @param tx
 * @param baud
 **/
void uart_init(u8 rx, u8 tx, u64 baud)
{
  u8 rate = ((F_CPU / (baud * m)) - 1) + 1;
  // u8 rate = FOSC/16/baud-1;
  
  UBRR0H = (rate >> 8);
  UBRR0L = rate;

  UCSR0B = (1 << rx) | (1 << tx);
  UCSR0C = (1 << USBS0) | (3 << UCSZ00);
}


/**
 * Function to read bytes from the uart buffer
 *
 * @return char
 **/
char uart_read()
{

}


/**
 * Function to write a char to the uart registers 
 *
 * @param c
 **/
void _uart_write_char(char c)
{
  while (!(UCSR0A & (1<<UDRE0)));

  UDR0 = c;
}


/**
 * Function to transmit a chunk of data over uart
 *
 * @param buffer
 * @param size
 **/
void uart_write(char *buffer, size_t size)
{
  for (u8 i = 0; i < size; i++) {
    _uart_write_char(buffer[i]);
  }
}
