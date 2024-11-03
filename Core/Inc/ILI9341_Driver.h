/*
 * @file			: ILI9341_Driver.h
 *
 * @source			: https://github.com/dtnghia2206/TFTLCD
 * @modified date	: 02 Nov 2024
 * @editor			: Tran Ba Thanh
 *
 */

#include "stm32f4xx_hal.h"
#include <stdlib.h>
#include "main.h"

// Define macro
#define  RESET_OFF 		HAL_GPIO_WritePin(RESET_GPIO_Port,RESET_Pin,GPIO_PIN_SET)
#define  RESET_ON 		HAL_GPIO_WritePin(RESET_GPIO_Port,RESET_Pin,GPIO_PIN_RESET)
#define  CS_OFF 		HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_SET)
#define  CS_ON 			HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_RESET)
#define  DC_DATA 		HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,GPIO_PIN_SET)
#define  DC_COMMAND 	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,GPIO_PIN_RESET)
#define swap(a,b) 		{int16_t t=a;a=b;b=t;}

// Define color in HEX
#define BLACK       	0x0000
#define NAVY        	0x000F
#define DARKGREEN   	0x03E0
#define DARKCYAN    	0x03EF
#define MAROON      	0x7800
#define PURPLE      	0x780F
#define OLIVE       	0x7BE0
#define LIGHTGREY   	0xC618
#define DARKGREY    	0x7BEF
#define BLUE        	0x001F
#define GREEN       	0x07E0
#define CYAN        	0x07FF
#define RED         	0xF800
#define MAGENTA     	0xF81F
#define YELLOW      	0xFFE0
#define WHITE       	0xFFFF
#define ORANGE      	0xFD20
#define GREENYELLOW 	0xAFE5
#define PINK        	0xF81F

// WTF is this????
#define BURST_MAX_SIZE 	500

// Define ILI9341 regulative commands
	//following ILI9341_DS_V1.09.pdf
#define NO_OPERATION								0x00
#define SOFTWARE_RESET 								0x01
#define READ_DISPLAY_IDENTIFICATION_INFO			0x04
#define READ_DISPLAY_STATUS							0x09
#define READ_DISPLAY_POWER_MODE						0x0A
#define READ_DISPLAY_MADCTL							0x0B
#define READ_DISPLAY_PIXEL_FORMAT					0x0C
#define READ_DISPLAY_IMAGE_FORMAT					0x0D
#define READ_DISPLAY_SIGNAL_MODE					0x0E
#define READ_DISPLAY_SELF_DIAGNOSTIC_RESULT			0x0F
#define ENTER_SLEEP_MODE							0x10
#define SLEEP_OUT									0x11
#define PARTIAL_MODE_ON								0x12
#define NORMAL_DISPLAY_MODE_ON						0x13
#define DISPLAY_INVERSION_OFF						0x20
#define DISPLAY_INVERSION_ON						0x21
#define GAMMA_SET									0x26
#define DISPLAY_OFF									0x28
#define DISPLAY_ON									0x29
#define COLUMN_ADDRESS_SET							0x2A
#define PAGE_ADDRESS_SET							0x2B
#define MEMORY_WRITE								0x2C
#define COLOR_SET									0x2D
#define MEMORY_READ									0x2E
#define PARTIAL_AREA								0x30
#define VERTICAL_SCROLLING_DEFINITION				0x33
#define TEARING_EFFECT_LINE_OFF						0x34
#define TEARING_EFFECT_LINE_ON						0x35
#define MEMORY_ACCESS_CONTROL						0x36
#define VERTICAL_SCROLLING_START_ADDRESS			0x37
#define IDLE_MODE_OFF								0x38
#define IDLE_MODE_ON								0x39
#define PIXEL_FORMAT_SET							0x3A
#define WRITE_MEMORY_CONTINUE						0x3C
#define READ_MEMORY_CONTINUE						0x3E
#define SET_TEAR_SCANLINE							0x44
#define GET_SCANLINE								0x45
#define WRITE_DISPLAY_BRIGHTNESS					0x51
#define READ_DISPLAY_BRIGHTNESS						0x52
#define WRITE_CTRL_DISPLAY							0x53
#define READ_CTRL_DISPLAY							0x54
#define WRITE_CONTENT_ADAPTIVE_BRIGHTNESS_CONTROL	0x55
#define READ_CONTENT_ADAPTIVE_BRIGHTNESS_CONTROL	0x56
#define WRITE_CABC_MINIMUM_BRIGHTNESS				0x5E
#define READ_CABC_MINIMUM_BRIGHTNESS				0x5F
#define READ_ID1									0xDA
#define READ_ID2									0xDB
#define READ_ID3									0xDC

// Define ILI9341 extended commands
	//following ILI9341_DS_V1.09.pdf
#define RGB_INTERFACE_SIGNAL_CONTROL				0xB0
#define FRAME_CONTROL_NORMAL_MODE     				0xB1
#define FRAME_CONTROL_IDLE_MODE       				0xB2
#define FRAME_CONTROL_PARTIAL_MODE    				0xB3
#define DISPLAY_INVERSION_CONTROL     				0xB4
#define BLANKING_PORCH_CONTROL        				0xB5
#define DISPLAY_FUNCTION_CONTROL      				0xB6
#define ENTRY_MODE_SET                				0xB7
#define BACKLIGHT_CONTROL_1           				0xB8
#define BACKLIGHT_CONTROL_2           				0xB9
#define BACKLIGHT_CONTROL_3           				0xBA
#define BACKLIGHT_CONTROL_4           				0xBB
#define BACKLIGHT_CONTROL_5           				0xBC
#define BACKLIGHT_CONTROL_7           				0xBE
#define BACKLIGHT_CONTROL_8           				0xBF
#define POWER_CONTROL_1               				0xC0
#define POWER_CONTROL_2               				0xC1
#define VCOM_CONTROL_1                				0xC5
#define VCOM_CONTROL_2                				0xC7
#define NV_MEMORY_WRITE               				0xD0
#define NV_MEMORY_PROTECTION_KEY      				0xD1
#define NV_MEMORY_STATUS_READ         				0xD2
#define READ_ID4                      				0xD3
#define POSITIVE_GAMMA_CORRECTION     				0xE0
#define NEGATIVE_GAMMA_CORRECTION     				0xE1
#define DIGITAL_GAMMA_CONTROL_1       				0xE2
#define DIGITAL_GAMMA_CONTROL_2       				0xE3
#define INTERFACE_CONTROL             				0xF6

void ILI9341_Init(void);
void ILI9341_Reset(void);
void ILI9341_Set_Rotation(unsigned char rotation);
void ILI9341_Fill_Screen(unsigned int color);

void ILI9341_Draw_Pixel(int x, int y, unsigned int color);
void ILI9341_Draw_Double_Pixel(int x, int y, unsigned int color1, unsigned int color2);
void ILI9341_Draw_Circle(unsigned int x0, unsigned int y0, int r, unsigned int color, unsigned char flood);
void ILI9341_Draw_Line(unsigned int color, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
void ILI9341_Draw_Filled_Rectangle(unsigned int color,unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
void ILI9341_Draw_Empty_Rectangle(unsigned int color,unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
void ILI9341_Draw_String(unsigned int x, unsigned int y, unsigned int color, unsigned int phone, char *str, unsigned char size);
