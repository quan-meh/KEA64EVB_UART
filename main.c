/* main.c              (c) 2015 Freescale Semiconductor, Inc.
 * Descriptions: UART example code for KEA Series
 * 28 Sept 2015 Kushal Shah: Initial version
 */



#include "derivative.h" /* include peripheral declarations SKEAZ128M4 */
#include "UART.h"
#include "clocks.h"

int main(void)
{
  int counter = 0;

  init_clks_FEE_40MHz();    /* KEA128 clks FEE, 8MHz xtal: core 40 MHz, bus 20MHz */
  UART_init();				/* Initialize UART2 9600 baud, 1 stop, no parity no IRQ */
  transmit_string("Running UART example\n\r"); /* Transmit string, new line, return */
  for(;;) {
    transmit_char('>');       /* Transmit a "prompt" type character */
    recieve_and_echo_char();  /* Wait for an input char, read it & echo it back */
    counter++;                /* Loop counter */
  }
}
