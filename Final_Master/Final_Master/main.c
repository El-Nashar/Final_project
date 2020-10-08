/*
 * Final_Master.c
 *
 * Created: 2020-10-07 2:35:28 PM
 * Author : Ahmed El-Nashar
 */ 

#include "SPI.h"
#include "LED.h"
#include "UART.h"
#define  F_CPU  8000000
#include <util/delay.h>

int main(void)
{
	uint8 Udata;
	
	UART_Init();
	LED0_Init();
	SPI_MasterInit();
	SPI_InitTrans();
	
	while (1)
	{
		Udata = UART_Recive_Byte();
		
		if (Udata)
		{
			SPI_Trans(Udata);
			LED0_Toggle();
		}			
	}
}

