#include <stdio.h>
#include "NUC100Series.h"

#define HXT_STATUS 1 << 0
#define TIMER1_COUNTS 1500000 - 1
int main(void)
{
    SYS_UnlockReg(); // Unlock protected regs

    CLK->PWRCON |= (1 << 0);
    while (!(CLK->CLKSTATUS & HXT_STATUS))
        ;
    CLK->PLLCON &= ~(1 << 19); // 0: PLL input is HXT
    CLK->PLLCON &= ~(1 << 16); // PLL in normal mode
    CLK->PLLCON &= (~(0x01FF << 0));
    CLK->PLLCON |= 22;
    CLK->PLLCON &= ~(1 << 18); // 0: enable PLLOUT

    CLK->CLKSEL0 &= (~(0b111 << 0));
    CLK->PWRCON &= ~(1 << 7);

    CLK->CLKDIV &= (~(0xF << 0));

    PB->PMD &= (~(0b11 << 18));
    PB->PMD |= (0b01 << 18);

    SYS->GPB_MFP |= (1 << 9);
    SYS->ALT_MFP &= ~(1 << 1);

    CLK->CLKSEL1 &= ~(0b111 << 12);
    CLK->CLKSEL1 |= (0b010 << 12);
    CLK->APBCLK |= (1 << 3);

    SYS->GPB_MFP |= (1 << 9);
    SYS->ALT_MFP &= ~(1 << 1);

    TIMER1->TCSR &= ~(0xFF << 0);
    TIMER1->TCSR |= (1 << 0);

    TIMER1->TCSR |= (1 << 26);

    TIMER1->TCSR &= ~(0b11 << 27);
    TIMER1->TCSR |= (0b10 << 27);
    TIMER1->TCSR &= ~(1 << 24);

    TIMER1->TCSR |= (1 << 16);

    TIMER1->TCSR |= (1 << 29);

    TIMER1->TCMPR = TIMER1_COUNTS;

    TIMER1->TCSR |= (1 << 30);

    SYS_LockReg();

    while (1)
    {
    }
}
