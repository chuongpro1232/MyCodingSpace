/ -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -main.c CODE STARTS-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
#include <stdio.h>
#include "NUC100Series.h"
#define BUZZER_BEEP_TIME 3
#define BUZZER_BEEP_DELAY 2000000
                                                                  void
                                                                  System_Config(void);
void Buzzer_beep(int beep_time)
{
    int main(void)
    {
        System_Config();
        // GPB.11 Push-Pull Output
        PB->PMD &= ~(0b11 << 22);
        PB->PMD |= (0b01 << 22);
        // GPB.15 Input
        PB->PMD &= ~(0b11 << 30);
        // Turn off Buzzer before
        PB->DOUT |= (1 << 11) while (1)
        {
            if (!(PB->PIN & (1 << 15)))
            {
                Buzzer_beep(BUZZER_BEEP_TIME);
            }
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
        //  CPU clock source selection
        CLK->CLKSEL0 &= (~(0x07 << 0));
        CLK->CLKSEL0 |= (0x02 << 0);
        // clock frequency division
        CLK->CLKDIV &= (~0x0F << 0);
        SYS_LockReg(); // Lock protected registers
    }
    void Buzzer_beep(int beep_time)
    {
        int i;
        for (i = 0; i < (beep_time * 2); i++)
        {
            PB->DOUT ^= (1 << 11);
            CLK_SysTickDelay(BUZZER_BEEP_DELAY);
        }
    }
    //------------------------------------------- main.c CODE ENDS
    -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -