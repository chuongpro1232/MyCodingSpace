#include <stdio.h>
#include "NUC100Series.h"

int main(void)
{
    System_Config();

    // out put here
}
void System_Config(void)
{
    SYS_UnlockReg();
    CLK->PWRCON |= (1 << 0);
    while (!(CLK->CLKSTATUS & (1 << 0)))
        ;
    CLK->CLKSEL0 &= (~(0b111 << 0));
    CLK->PWRCON &= ~(1 << 7);
}