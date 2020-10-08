/*
 * UART.c
 *
 * Created: 9/14/2020 11:05:32 PM
 *  Author: Ahmed Atef
 */ 


#include "UART.h"


volatile uint8* str = 0;

void UART_Init (void)
{
	
	uint32 BR_value = 0 ;
	
	DIO_SetPinDirection(DIO_PORTD, DIO_PIN0 , DIO_PIN_IN); //set RX pin as input
	DIO_SetPinDirection(DIO_PORTD, DIO_PIN1 , DIO_PIN_OUT); // set TX pin as output 
	
	
	UCSRB |= 0x18; // receiver enable & Transmit enable 
	
	UCSRC |=0x86; // select UCSRC reg , select 8-bit mode to transmit and receiver 
	
	
	BR_value=((80000)/(16 * (96)))-1;
	
	UBRRL= BR_value ; // set boad rate 
	
}


void UART_Transmit_Byte(uint8 data)
{
	UDR = data ; // write in UDR req 
	
	while(GET_BIT(UCSRA , 5)==0); // while flag not fire stuck here polling method 
	
}


uint8 UART_Recive_Byte(void) // return value void UART_Recive_Byte(uint8*); => by value
{
	uint8 data = 0  ; 
	
	while(GET_BIT(UCSRA , 7)==0);
	
	data = UDR ; 
	
	return data ; 
	
}



void UART_Transmit_String(uint8 * str)
{
	uint8 i=0;
	
	while (str[i] != '\0')
	{
		UART_Transmit_Byte(str[i]);
		i++;
	}
}



uint8* UART_Recive_String(void)
{
	uint8 i= 0;
	
	while (str[i] == '\0')
	{
		UART_Recive_Byte();
		i++;
	}

	
}
