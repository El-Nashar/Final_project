/*
 * UART.h
 *
 * Created: 9/14/2020 11:05:56 PM
 *  Author: Ahmed Atef
 */ 


#ifndef UART_H_
#define UART_H_

#include "DIO.h"


void UART_Init (void);


void UART_Transmit_Byte(uint8);


uint8 UART_Recive_Byte(void); // return value void UART_Recive_Byte(uint8*); => by value 




void UART_Transmit_String(uint8 * str);



uint8* UART_Recive_String(void);






#endif /* UART_H_ */