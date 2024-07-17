#include <stdio.h>
#include "SYS_init.h"
#include "NUC100Series.h"

int main(void)
{
	SYS_Init();
	GPIO_SetMode(PC,BIT12,GPIO_MODE_OUTPUT);
	GPIO_SetMode(PC,BIT13,GPIO_MODE_OUTPUT);
	GPIO_SetMode(PC,BIT14,GPIO_MODE_OUTPUT);
	GPIO_SetMode(PC,BIT15,GPIO_MODE_OUTPUT);
	
	while(1) {
		PC->DOUT ^= (1<<12);
		CLK_SysTickDelay(100000);
		PC->DOUT ^= (1<<13);
		CLK_SysTickDelay(100000);
		PC->DOUT ^= (1<<14);
		CLK_SysTickDelay(100000);
		PC->DOUT ^= (1<<15);	
	}
}
