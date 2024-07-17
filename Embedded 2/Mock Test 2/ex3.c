#include <stdio.h>
#include "NUC100Series.h"
volatile int beep_count = 0;
#define beep_time 6
#define TIMER0_COUNTS 16300
void System_Config(void);
void EINT1_IRQHandler(void);
int main(void)
{
    System_Config();
    // GPB.11 Push-Pull Output
    PB->PMD &= ~(0b11 << 22);
    PB->PMD |= (0b01 << 22);
    // GPB.15 Input
    PB->PMD &= ~(0b11 << 30);
    PB->IEN |= (1 << 15);
    // NVIC interrupt configuration for GPIO-B15 interrupt source
    NVIC->ISER[0] |= 1 << 3;
    NVIC->IP[0] &= (~(0b11 << 30));
    // Turn off Buzzer
    PB->DOUT |= (1 << 11);
    while (1)
    {
    }
}
void System_Config(void)
{
    SYS_UnlockReg(); // Unlock protected registers
    // enable clock sources
    CLK->PWRCON |= (1 << 0);
    while (!(CLK->CLKSTATUS & (1 << 0)))
        ;
    // PLL configuration starts
    CLK->PLLCON &= ~(1 << 19); // 0: PLL input is HXT
    CLK->PLLCON &= ~(1 << 16); // PLL in normal mode
    CLK->PLLCON &= (~(0x01FF << 0));
    CLK->PLLCON |= 48;
    CLK->PLLCON &= ~(1 << 18); // 0: enable PLLOUT
    while (!(CLK->CLKSTATUS & (1 << 2)))
        ;
    // PLL configuration ends
    CLK->PWRCON |= (1 << 1);
    while (!(CLK->CLKSTATUS & (1 << 1)))
        ;
    // CPU clock source selection
    CLK->CLKSEL0 &= (~(0b111 << 0));
    CLK->CLKSEL0 |= (0b010 << 0);
    // clock frequency division
    CLK->CLKDIV &= (~0x0F << 0);

    // Timer 0 initialization start--------------
    // TM0 Clock selection and configuration
    CLK->CLKSEL1 &= ~(0b111 << 8); // clear bit in clk source
    CLK->CLKSEL1 |= (0b001 << 8);  // choose 32.768 clock source
    CLK->APBCLK |= (1 << 2);       // enable clock source
    TIMER0->TCSR &= ~(0xFF << 0);
    // reset Timer 0
    TIMER0->TCSR |= (1 << 26);
    // define Timer 0 operation mode
    TIMER0->TCSR &= ~(0x03 << 27);
    TIMER0->TCSR |= (0x01 << 27);
    TIMER0->TCSR &= ~(1 << 24);
    // TimeOut = 0.5s
    TIMER0->TCMPR = TIMER0_COUNTS;
    // Enable interrupt in the Control Resigter of Timer istsle
    TIMER0->TCSR |= (1 << 29);
    // Set Timer0 in NVIC Set-Enable Control Register (NVIC_ISER)
    NVIC->ISER[0] |= 1 << 8;
    // Priority for Timer 0
    NVIC->IP[2] &= (~(0b11 << 6));
    SYS_LockReg(); // Lock protected registers
}
void EINT1_IRQHandler(void)
{
    PB->DOUT &= ~(1 << 11);
    TIMER0->TCSR |= (1 << 30); // start counting
    PB->ISRC |= (1 << 15);
}
void TMR0_IRQHandler(void)
{
    PB->DOUT ^= (1 << 11);
    beep_count++;
    if (beep_count == beep_time)
    {
        PB->DOUT |= (1 << 11);
        beep_count = 0;
        TIMER0->TCSR &= ~(1 << 30);
        TIMER0->TCSR |= (1 << 26);
    }
    TIMER0->TISR |= (1 << 0);
}
//------------------------------------------- main.c CODE ENDS