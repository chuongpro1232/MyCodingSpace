// -----------------------------------main.c -------------------------------------
#ifdef UART0
#include "./uart/uart0.h"
#define MSG "Hello World! This is UART0 !!!\n"
#else
#include "./uart/uart1.h"
#define MSG "Hello World! This is UART1 !!!\n"
#endif

void main()
{
    // intitialize UART
    uart_init();
    // say hello
    uart_puts(MSG);
    // echo everything back
    while (1)
    {
        // read each char
        char c = uart_getc();
        // send back twice
        if (c >= 'A' && c <= 'Z')
        {
            // uart_sendc(tolower(c));
            // uart_sendc(tolower(c));
            c = c - 'A' + 'a';
        }
        else if (c >= 'a' && c <= 'z')
        {
            // uart_sendc(toupper(c));
            // uart_sendc(toupper(c));
            c = c - 'a' + 'A';
            // uart_sendc(c);
            // uart_sendc(c);
        }
        uart_sendc(c);
    }
}