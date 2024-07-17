// -----------------------------------main.c -------------------------------------

#include "../header/uart0.h"
#include "../header/uart1.h"
#include "../peripheral/uart0.c"
#include "../peripheral/gpio.c"

#include "../peripheral/uart1.c"
void main()
{
    // intitialize UART
    uart_init();

    // say hello
    uart_puts("Hello World! This is UART0\n");
    led_blink();
    // echo everything back
    while (1)
    {
        // read each char
        char c = uart_getc();

        // send back twice
        uart_sendc(c);
        uart_sendc(c);
    }
}
