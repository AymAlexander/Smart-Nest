#ifndef __OLED_H__
#define __OLED_H__

#include "STC8.H"

#define u8 unsigned char
#define u16 unsigned int
#define u32 unsigned int

#define OLED_CMD  0	//Ð´ÃüÁî
#define OLED_DATA 1	//Ð´Êý¾Ý

//#define OLED_SCL_Clr() OLED_SCL=0
//#define OLED_SCL_Set() OLED_SCL=1

//#define OLED_SDA_Clr() OLED_SDA=0
//#define OLED_SDA_Set() OLED_SDA=1

//#define OLED_RES_Clr() OLED_RES=0
//#define OLED_RES_Set() OLED_RES=1

void delay_ms(unsigned int ms);
void OLED_WR_Byte(u8 dat,u8 mode);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void OLED_Set_Pos(u8 x, u8 y);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Clear(void) ;
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 sizey);
u32 oled_pow(u8 m,u8 n);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 sizey);
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 sizey);
void OLED_DrawBMP(u8 x,u8 y,u8 sizex, u8 sizey,u8 BMP[]);
void OLED_Init(void);

#endif