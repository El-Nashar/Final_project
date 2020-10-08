/*
 * SPI.c
 *
 * Created: 11/09/2020 06:46:04 م
 *  Author: Ali
 */ 

#include  "SPI.h"



void SPI_MasterInit(void)
{
	 DIO_SetPinDirection(DIO_PORTB ,DIO_PIN4 , DIO_PIN_OUT);
	 DIO_SetPinDirection(DIO_PORTB ,DIO_PIN5 , DIO_PIN_OUT);
	 DIO_SetPinDirection(DIO_PORTB ,DIO_PIN6 , DIO_PIN_IN);
	 DIO_SetPinDirection(DIO_PORTB ,DIO_PIN7 , DIO_PIN_OUT);
	 
	SPI->SPCR.SPR0 = 1;
	SPI->SPCR.SPR1 = 1;
	SPI->SPCR.CPHA = 0;
	SPI->SPCR.CPOL = 0;
	SPI->SPCR.MSTR = 1;
	SPI->SPCR.DORD = 0;
	SPI->SPCR.SPE  = 1;	 
}

void SPI_SlaveInit(void)
{
		 DIO_SetPinDirection(DIO_PORTB ,DIO_PIN4 , DIO_PIN_IN);
		 DIO_SetPinDirection(DIO_PORTB ,DIO_PIN5 , DIO_PIN_IN);
		 DIO_SetPinDirection(DIO_PORTB ,DIO_PIN6 , DIO_PIN_OUT);
		 DIO_SetPinDirection(DIO_PORTB ,DIO_PIN7 , DIO_PIN_IN);
		 
		SPI->SPCR.SPR0 = 0;
		SPI->SPCR.SPR1 = 0;
		SPI->SPCR.CPHA = 0;
		SPI->SPCR.CPOL = 0;
		SPI->SPCR.MSTR = 0;
		SPI->SPCR.DORD = 0;
		SPI->SPCR.SPE  = 1;
		 
}

void SPI_Trans(uint8 tx_data)
{	
	SPI->SPDR = tx_data ;
	
	while(GET_BIT(SPI->SPSR , 7)  ==  0);
}

uint8 SPI_Rec(void)
{
	while(GET_BIT(SPI->SPSR , 7)  ==  0);
	
	return SPI->SPDR;
}

void SPI_InitTrans(void)
{
	DIO_SetPinValue(DIO_PORTB ,DIO_PIN4 ,DIO_PIN_LOW);
}

void SPI_TermTrans(void)
{
	DIO_SetPinValue(DIO_PORTB ,DIO_PIN4 ,DIO_PIN_HIGH);
}