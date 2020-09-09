#include "STC8.h"
#include "intrins.h"
#include "i2c.h"
#include "OLED.H"
#include "BMP.H"

#define u8 unsigned char
#define u16 unsigned int

void main()
{
	bit i=1;
	int temp;
	int temperature;
	
	I2Cinit();
	OLED_Init();//初始化OLED
	OLED_ColorTurn(0);//0正常显示，1 反色显示
  OLED_DisplayTurn(0);//0正常显示 1 屏幕翻转显示
	while(1)
	{
		if(i) OLED_ShowString(0,0,"/ / / / / / / / / / /",8);
		else  OLED_ShowString(0,0," / / / / / / / / / / ",8);
		OLED_DrawBMP(0,2,24,24,BMP1);
		OLED_ShowString(28,2,"Temp: N/A",16);
		OLED_ShowString(28,4,"Humi: N/A",16);
		OLED_ShowString(66,7,"Aym Design",8);
		OLED_ShowString(0,7,"TLimit:30C",8);
		i = ~i;
		delay_ms(200);
		//temp = ReadTemperature();
		//temperature = temp*0x0625;
		//OLED_ShowNum(0,5,temperature,8,8);
		
	}
}