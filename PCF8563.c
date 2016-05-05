/********************************************************************************************************
*********************************************************************************************************
*
* File                : PCF8563.c
* Hardware Environment:
* Build Environment   : AVR Studio 4.16 + Winavr 20090313
* Version             : V1.0
* By                  : Wu Ze
*
*                                  (c) Copyright 2005-2009, WaveShare
*                                       http://www.waveShare.net
*                                          All Rights Reserved
*
*********************************************************************************************************
********************************************************************************************************/

#define _DVK501_M128_EX_ 1
#include <avr/io.h>
#include <util/delay.h>
#include <ws_iic_port.h>
#include <ws_pcf8563_port.h>

int main(void)
{
	DDRA=0xFF;
	PORTA=0x00;

	uint8_t time[3];
	twi_init();	
	PCF8563_init();	
	PCF8563_setTime(0,0,0); 
	
	while(1)
	{	
		PCF8563_getTime(time);
		PORTA = time[0];
	}
}
