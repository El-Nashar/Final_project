/*
 * Final_Slave.c
 *
 * Created: 2020-10-07 6:19:15 PM
 * Author : Ahmed El-Nashar
 */ 

#include "SPI.h"
#include "LED.h"
#define F_CPU 8000000
#include <util/delay.h>

int main(void)
{
	SPI_SlaveInit();
	LED0_Init();
	LED1_Init();
	
	uint8 Received_Data;
	
	while (1)
	{
		
		Received_Data = SPI_Rec();
		
		switch(Received_Data)
		{
			case '1':
			LED0_ON();
		    break;
			
			case '2':
			LED0_OFF();
			break;
			
			case '3':
			LED1_ON();
			break;
			
			case '4':
			LED1_OFF();
			break;
		}
		
	
	}
}

