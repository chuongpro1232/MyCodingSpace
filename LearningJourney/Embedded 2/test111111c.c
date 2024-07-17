#include <stdio.h>
#include "NUC100Series.h" 

// If more macros are required, please define them here 
#define HXT_STATUS 1 << 0  	// 12 MHz
#define LXT_STATUS 1 << 1  	// 32.768 kHz
#define PLL_STATUS 1 << 2 	// PLLCON
#define LIRC_STATUS 1 << 3 	// 10 kHz
#define HIRC_STATUS 1 << 4 	// 22.1184 MHz

int main(void){ 

// Insert your Question 1 code here 
// 1. Select PLL Clock Source
SYS_UnlockReg(); // Unlock protected registers
CLK->PLLCON |= (1 << 19);    // Default select HIRC 22.1184 MHz [19] = 1
CLK->PLLCON &= (~(1 << 16));    // Keep PLL in Normal Mode
// PLLFOUT should be configured and selected.
// We can select the 22.11 MHz clock as PLL input clock FIN (PLLCON[19] = 1)
		// NR = 2 (PLLCON[13:9] = 0 = 0b00000)
		// NO = 1 (PLLCON[15:14] = 0 = 0b00)
		// NF = 3 (PLLCON[8:0] = 1 = 0b0_0000_0001
		
// 2. Calculate PLL output clock source
CLK->PLLCON &= (~(0x0FFFF << 0));	// Clear the default/reset values of PLLCON[15:0]
CLK->PLLCON |= 0x01 << 0;		// PLLCON[8:0] = 1  NF = 3
CLK->PLLCON |= 0x00 << 9;		// PLLCON[13:9] = 0  NR = 2
CLK->PLLCON |= 0x00 << 14;		// PLLCON[15:14] = 0  NO = 1

// 3. Enable and wait until PLL is stable
CLK->PLLCON &= (~(1 << 18));
while (!(CLK->CLKSTATUS & PLL_STATUS));

// 4. Select PLLFOUT for CPU
CLK->CLKSEL0 &= (~(0x07 << 0));
CLK->CLKSEL0 |= (0x02 << 0);        // CLKSEL0[2:0] = 0b010

// END_SECTION: Decide Clock Frequency for CPU

SYS_LockReg(); // Lock protected registers

while(1) { }

}