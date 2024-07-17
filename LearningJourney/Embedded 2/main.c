#include <stdio.h>
#include "NUC100Series.h"

#define NUC140_CLOCK 1

#define HXT_STATUS 1 << 0  	// 12 MHz
#define LXT_STATUS 1 << 1  	// 32.768 kHz
#define PLL_STATUS 1 << 2 	 	// PLLCON
#define LIRC_STATUS 1 << 3 	// 10 kHz
#define HIRC_STATUS 1 << 4 	// 22.11 MHz


int main(void) {
	SYS_UnlockReg(); // Unlock protected registers

	 // START_SECTION: Enabling Clock Sources
	// Enable and wait until HXT 12 MHz clock source is stable
	CLK->PWRCON |= 1 << 0;
	while (!(CLK->CLKSTATUS & HXT_STATUS));

	// Enable and wait until LXT 32.7 kHz clock source is stable
	CLK->PWRCON |= 1 << 1;
	while (!(CLK->CLKSTATUS & LXT_STATUS));

	// Enable and wait until HIRC 22.11 MHz clock source is stable.
	// This is not required since this clock is enabled by default (after system reset)
	CLK->PWRCON |= 1 << 2;
	while (!(CLK->CLKSTATUS & HIRC_STATUS));

	// Enable and wait until LIRC 10 kHz clock source is stable
	CLK->PWRCON |= 1 << 3;
	while (!(CLK->CLKSTATUS & LIRC_STATUS));

	// END_SECTION: Enabling Clock Sources


	// START_SECTION: Decide Clock Frequency for CPU

	#if NUC140_CLOCK == 1
		// select the 22.1184 MHz clock as clock source (CLKSEL0[2:0] = 0b111)
		// and further divide it by 2 using the clock divider register (CLKDIV[3:0] = 1)
		CLK->CLKSEL0 &= (~(0x07 << 0));
		CLK->CLKSEL0 |= (0x07 << 0);        	// CLKSEL0[2:0] = 0b111
		CLK->CLKDIV &= (~(0x0F << 0));
		CLK->CLKDIV |= (0x01 << 0);		// CLKDIV[3:0] = 0b0001

	#elif NUC140_CLOCK == 2
		// select the 32.768 kHz clock as clock source (CLKSEL0[2:0] = 0b001)
		// and further divide it by 4 using the clock divider register (CLKDIV[3:0] = 3).
		CLK->CLKSEL0 &= (~(0x07 << 0));
		CLK->CLKSEL0 |= (0x01 << 0);        	// CLKSEL0[2:0] = 0b001
		CLK->CLKDIV &= (~(0x0F << 0));
		CLK->CLKDIV |= (0x03 << 0);		// CLKDIV[3:0] = 0b0011

	#else

		// PLLFOUT should be configured and selected.
		// We can select the 12 MHz clock as PLL input clock FIN (PLLCON[19] = 0)
		// NR = 3 (PLLCON[13:9] = 1 = 0b00001)
		// NO = 4 (PLLCON[15:14] = 3 = 0b11)
		// NF = 24 (PLLCON[8:0] = 24 = 0b0_0001_1000)

		// 1. Select PLL Clock Source
		CLK->PLLCON &= (~(1 << 19));    // Default select HXT 12 MHz [19] = 0
		CLK->PLLCON &= (~(1 << 16));    // Keep PLL in Normal Mode

										// 2. Calculate PLL output clock source
		CLK->PLLCON &= (~(0x0FFFF << 0));	// Clear the default/reset values of PLLCON[15:0]
		CLK->PLLCON |= 0x16 << 0;		// PLLCON[8:0] = 22  NF = 24
		CLK->PLLCON |= 0x1 << 9;		// PLLCON[13:9] = 1  NR = 3
		CLK->PLLCON |= 0x03 << 14;		// PLLCON[15:14] = 3  NO = 4

										// 3. Enable and wait until PLL is stable
		CLK->PLLCON &= (~(1 << 18));
		while (!(CLK->CLKSTATUS & PLL_STATUS));

		// 4. Select PLLFOUT for CPU
		CLK->CLKSEL0 &= (~(0x07 << 0));
		CLK->CLKSEL0 |= (0x02 << 0);        	// CLKSEL0[2:0] = 0b010

	#endif
	
	// END_SECTION: Decide Clock Frequency for CPU

	SYS_LockReg(); // Lock protected registers

	while (1) {}
}



