/*
 * rcc.h
 *
 *  Created on: Nov 1, 2023
 *      Author: admin
 */

#ifndef RCC_H_
#define RCC_H_
#include"RCC_Config.h"
void RCC_Init(void);
void RCC_EnableClock(u8 copyu8_BusID,u8 copyu8_PerID);
void RCC_DisableClock(u8 copyu8_BusID,u8 copyu8_PerID);


#endif /* RCC_H_ */
