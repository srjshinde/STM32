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
#include "sw_delay.h"
#include "stm32_uid.h"

char buff[256];

int main()
{

	usart_1_enable();
	delay(1000);
		
	uint32_t idPart1 = STM32_UUID[0];
  uint32_t idPart2 = STM32_UUID[1];
  uint32_t idPart3 = STM32_UUID[2];
	
	printMsg("unique ID: %X %X %X\n", idPart1, idPart2, idPart3);
	
}
