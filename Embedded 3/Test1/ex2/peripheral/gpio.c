#include "../header/gpio.h"
#include "../header/uart0.h"
#include "../header/uart1.h"
void delay()
{
    // Have some delay
    unsigned int count = 1000000;
    while (count--)
    {
        asm volatile("nop");
    } // waiting 1000000 cycles
}
void led_blink()
{
    uart_puts("Running LED blinking program....\n");
    // Configure GPIO Pin 38 as an output (set bit 24 in GPFSEL3)
    GPFSEL3 |= 1 << 24;
    while (1)
    {

        // Turn the LED at GPIO Pin 38 ON (set bit 6 in GPSET1)
        GPSET1 |= 1 << 6;
        // Have some delay
        delay();
        // Turn the LED at GPIO Pin 38 OFF (set bit 3 in GPCLR1)
        GPCLR1 |= 1 << 6;
        // Have some delay
        delay();
    }
}
