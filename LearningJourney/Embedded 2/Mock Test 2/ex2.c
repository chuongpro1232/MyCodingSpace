#include <stdio.h>
#include "NUC100Series.h"
#define HXT_STATUS 1 << 0
#define PLL_STATUS 1 << 2
#define TIMER2_COUNTS 125000
int main(void)
{
    // System initialization start-------------------
    SYS_UnlockReg();
    CLK->PWRCON |= (1 << 0);
    while (!(CLK->CLKSTATUS & HXT_STATUS))
        ;
    // Configure PLL = 40 MHz
    CLK->PLLCON &= ~(1 << 19);     // 0: PLL source clock from external 4-24MHz
    CLK->PLLCON &= ~(1 << 18);     // 0: enable PLL clock out
    CLK->PLLCON &= ~(1 << 16);     // 0: PLL in normal mode
    CLK->PLLCON &= ~(0x01FF << 0); // Set FB_DV_Mask to 0
    // Frequency = 1Mhz * (FB_DV_Value + 2)
    CLK->PLLCON |= 38;
    while (!(CLK->CLKSTATUS & PLL_STATUS))
        ;
    // SELECT CPU clock = PLL
    CLK->CLKSEL0 &= ~(0b111 << 0);
    CLK->CLKSEL0 |= 0b010 << 0;
    CLK->CLKDIV &= ~(0x0F);
    CLK->CLKDIV |= 0;
    // System initialization end---------------------

    // GPIO initialization start --------------------
    // GPIOC.15/ LED8: output push-pull
    PC->PMD &= ~(0b11 << 30);
    PC->PMD |= (0b01 << 30);
    // GPIO initialization end ----------------------
    // Timer 2 initialization start--------------
    // TM2 Clock selection and configuration
    CLK->CLKSEL1 &= ~(0b111 << 16);
    CLK->CLKSEL1 |= (0b010 << 16); // Set the clock source is PLL
    CLK->APBCLK |= (1 << 4);       // Enable the clock supply

    // setup timer
    // TIMER_SET_PRESCALE_VALUE(TIMER2, 0x27); // 39
    TIMER2->TCSR &= ~(0xFF << 0);
    TIMER2->TCSR |= (0x27 << 0);
    // reset counter
    TIMER2->TCSR |= (1 << 26);
    // define Timer 2 operation mode
    TIMER2->TCSR &= ~(0b11 << 27);
    TIMER2->TCSR |= (0b01 << 27); // Periodic
    TIMER2->TCSR &= ~(1 << 24);   // Disable the timer counter mode (input/event)
    // TDR to be updated continuously while timer counter is counting
    TIMER2->TCSR |= (1 << 16); // Enable the Data Load
    // Enable TE bit (bit 29) of TCSR
    // The bit will enable the timer interrupt flag TIF
    TIMER2->TCSR |= (1 << 29);
    // Define TimeOut
    TIMER2->TCMPR = TIMER2_COUNTS;
    // start counting
    TIMER2->TCSR |= 1 << 30;
    // Timer 2 initialization end----------------
    SYS_LockReg(); // Lock protected registers
    while (1)
    {
        if (TIMER2->TISR & (1 << 0)) // Wait for the Overflow flag (TIF) to be
            set
            {
                PC->DOUT ^= 1 << 14;      // Toggle
                TIMER2->TISR |= (1 << 0); // Clear the flag by writing 1 to it
            }
    }
}