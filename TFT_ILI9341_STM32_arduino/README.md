# Adafruit_ILI9341_8bit_STM for STM32duino
8 bit parallel library for ILI9341 and STM32F103C8T6

### Working Example List

 - mygraphicstest.ino
 - mytouchscreendemo.ino
 - two_point_eight_LCD_STM32.ino
 
### Demo (YouTube)

 - https://www.youtube.com/watch?v=RKkBmD_i6sk


### How to use

#### 8 bit parallel interface
Port data |D7 |D6 |D5 |D4 |D3 |D2 |D1 |D0 |  
Pin stm32 |PA7|PA6|PA5|PA4|PA3|PA2|PA1|PA0|

#### Control Pins
Control pins |RD |WR |RS |CS |RST|  
Pin stm32    |PB4|PB5|PB0|PB1|PB8|

#### Changing Pins
If you want to change control pins, they can be modified in Adafruit_ILI9341_8bit_STM.h header file. You will also have to modify the setting of these pins as output in Adafruit_ILI9341_8bit_STM.cpp, lines 18-22.

If you want to change data bus pins, you will have to change the functions called write8(), setWriteDataBus() accordingly

#### Details
- This library works with the Adafruit 2.4" Touch Shield V2 (8 bit 8080 type interface)
  Link: https://www.banggood.in/2_8-Inch-TFT-LCD-Shield-Touch-Display-Module-For-Arduino-UNO-p-989697.html?cur_warehouse=CN
- It has modifications to support STM32. It has been tested with the STM32F103C8T6 (blue pill).		
- Check out the links above for wiring details.		
- These displays use 8080 type 8 bit parallel data bus (8 pins), and 		
- 5 control pins to interface (RST is optional).		

#### Usage		
 - Place the Adafruit_ILI9341_8bit_STM library folder your C:\Program Files (x86)\Arduino\hardware\Arduino_STM32\STM32F1\libraries folder. Restart the IDE	
 - Also requires the Adafruit_GFX library for Arduino.
 
##Another good library is available here:
https://github.com/stevstrong/Adafruit_TFTLCD_8bit_STM32
