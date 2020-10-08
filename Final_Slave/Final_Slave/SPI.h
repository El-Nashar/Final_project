/*
 * SPI.h
 *
 * Created: 11/09/2020 06:46:15 م
 *  Author: Ali
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"

void SPI_MasterInit(void);

void SPI_SlaveInit(void);

void SPI_Trans(uint8 data);

uint8 SPI_Rec(void);

void SPI_InitTrans(void);

void SPI_TermTrans(void);


#endif /* SPI_H_ */