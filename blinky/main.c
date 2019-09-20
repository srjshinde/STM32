#include "stm32f10x.h"                  // Device header
#include "RTE_Components.h"             // Component selection
#include "RTE_Device.h"                 // Keil::Device:Startup

void delay(int time_in_ms);

int main()
{
	RCC->APB2ENR |= (0x0010);
	GPIOC->CRH |= (0x02000000);
	
	while(1)
	{
		GPIOC->BSRR =(0x00004000);
		delay(200);
		GPIOC->BSRR =(0x40000000);
		delay(200);
	}
	
//  unrechable due to infinite while loop
//	return 0;
}

void delay(int time_in_ms)
{
	int i,j;
	for( i=0; i< time_in_ms; i++)
	{
		for( j=0; j< 0x2AFF; j++);
	}
}
