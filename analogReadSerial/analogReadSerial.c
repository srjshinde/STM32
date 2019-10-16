/*********************************************
 USART1 TX on STM32 is at pin A9, RX is at pin
 A10. Use pinout, or CubeMX to find those two
 pins. 
==========STM32===========FTDI================
           GND------------GND pin
   pin A9  TX-------------RX  pin
   pin A10 RX-------------TX  pin
 *********************************************/

#include "stm32f10x.h"
#include "printMsg.h"
#include "adc.h"
#include "sw_delay.h"

int len=0;
char buff[256];
float voltage = 0;
float max_sys_voltage = 3.330;
int max_adc_value = 4095;

int main()
{
	ADCenable();
	usart_1_enable();
	
	printMsg("Value		Voltage\n");
	
	while(1)
	{
		
		adc_value = adc();
		voltage = (max_sys_voltage/max_adc_value)* adc_value;
		
		printMsg("%d  		%f\n", adc_value, voltage);
		delay(500);
	}
}
