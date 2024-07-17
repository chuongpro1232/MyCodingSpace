#include <stdio.h>
#include "NUC100Series.h"

// If more macros are required, please define them here
#define HXT_STATUS 1 << 0  // 12 MHz
#define LXT_STATUS 1 << 1  // 32.768 kHz
#define PLL_STATUS 1 << 2  // PLLCON
#define LIRC_STATUS 1 << 3 // 10 kHz
#define HIRC_STATUS 1 << 4 // 22.1184 MHz
int main(void)
{
    SYS_UnlockReg();
    PB->PMD &= (~(0x03<<30));
    PC->PMD &=(~(0xFF<<24));
    PC->PMD |= (0xFF<<24);
    // Insert your Question 1 code here
    CLK->PLLCON != (1 << 19);
    CLK->PLLCON &= (~(1 << 16));

    CLK->PLLCON &= (~(0x0FFFF << 0));
    CLK->PLLCON |= 0xA << 0;
    CLK->PLLCON |= 0x2 << 9;
    CLK->PLLCON |= 0x01 << 14;

    CLK->PLLCON &= (~(1 << 18));
    while (!(CLK->CLKSTATUS & PLL_STATUS))
        ;
CLK->CLKSEL0 &= (~(0x07 << 0));
CLK->CLKSEL0 |= (0x02 << 0);  


SYS_LockReg(); // Lock protected registers

    while (1)
    {
        if (!PB->PIN&(1<<15)){
            PC->DOUT|= (1<<24| 1<<25| 1<<26|1<<2)
        }
        else{

        }
    }
}
