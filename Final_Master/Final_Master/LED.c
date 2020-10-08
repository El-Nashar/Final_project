/*
 * LED.c
 *
 * Created: 07/08/2020 07:03:13 م
 *  Author: Ali
 */ 


#include "LED.h"



void LED0_Init(void)
{
	DIO_SetPinDirection(DIO_PORTA, DIO_PIN2 , DIO_PIN_OUT);
	
}

void LED0_ON(void)
{
	DIO_SetPinValue(DIO_PORTA, DIO_PIN2 ,  DIO_PIN_HIGH);
}

void LED0_OFF(void)
{
	DIO_SetPinValue(DIO_PORTA, DIO_PIN2 ,  DIO_PIN_LOW);
}

void LED0_Toggle(void)
{
	DIO_TogglePin(DIO_PORTA, DIO_PIN2);
}