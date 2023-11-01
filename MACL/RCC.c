/*
 * RCC.c
 *
 *  Created on: Nov 1, 2023
 *      Author: Nour
 */
#include "RCC.h"
#include"BitMath.h"
void RCC_Init(void)
{
#if RCC_CLK == RCC_CLK_HSI
	RCC_CR_REG->HSION =0b1;        //Enable HSI  (8MHz)
	RCC_CR_REG->HSITRIM = 0b10000; // No Trimming
	RCC_CFGR_REG->SW = 0b0;        //Internal CLock System

	while(RCC_CR_REG->HSIRDY == 0 );

#elif RCC_CLK == RCC_CLK_HSE_CRYSTAL
	  RCC_CR_REG->HSEON=0b1;    //Enable HSE
	  RCC_CR_REG->HSEBYP= 0b0;  //Enable Crystal
	  RCC_CFGR_REG->SW = 0b1;   // External Clock System
	  while(RCC_CR_REG->HSERDY ==0);


#elif RCC_CLK == RCC_CLK_HSE_RC
	  RCC_CR_REG->HSEON=0b1;    //Enable HSI
	  RCC_CR_REG->HSEBYP= 0b1;  //Enable RC
	  RCC_CFGR_REG->SW = 0b1;   // External Clock System

	  while(RCC_CR_REG->HSERDY ==0);
	  RCC_CR_REG->CSSON =0b1;


#elif RCC_CLK == RCC_CLK_PLL  // lazm t7ot m3 el pll ya HSE aw HSI

	 #if  RCC_PLL_INPUT ==RCC_PLL_INPUT_HSI_DIV_2
	  	   RCC_CR_REG->PLLON=0b0; //PLL Disabled
	  	   RCC_CFGR_REG->PLLMUL = 0b01;
	  	   RCC_CFGR_REG->PLLSRC = 0b0;
	  	   RCC_CR_REG->PLLON=0b0;  //PLL Enabled
	  	   while(RCC_CR_REG->PLLRDY ==0);

	 #elif   RCC_PLL_INPUT ==RCC_PLL_INPUT_HSE
		  RCC_CR_REG->PLLON=0b0; //PLL Disabled
		  RCC_CFGR_REG->PLLMUL = 0b01;
		  RCC_CFGR_REG->PLLSRC = 0b1;   //PLL Input : HSE
		  RCC_CFGR_REG->PLLXTPRE = 0b0; //PLL Input : HSE/1
		  RCC_CR_REG->PLLON=0b0;  //PLL Enabled
		  while(RCC_CR_REG->PLLRDY ==0);

	#elif  RCC_PLL_INPUT ==RCC_PLL_INPUT_HSE_DIV_2
		  RCC_CR_REG->PLLON=0b0; 		//PLL Disabled
		  RCC_CFGR_REG->PLLMUL = 0b01;
		  RCC_CFGR_REG->PLLSRC = 0b1;   //PLL Input : HSE
		  RCC_CFGR_REG->PLLXTPRE = 0b1; //PLL Input : HSE/2
		  RCC_CR_REG->PLLON=0b0;  //PLL Enabled
		 while(RCC_CR_REG->PLLRDY ==0);

	#endif

#elif RCC_CLK == RCC_CLK_PLL_2
	  RCC_CR_REG->PLL2ON=0b1;
	  while(RCC_CR_REG->PLL2RDY ==0);

#elif RCC_CLK == RCC_CLK_PLL_3
	  RCC_CR_REG->PLL3ON=0b1;
	  while(RCC_CR_REG->PLL3RDY ==0);


#endif
}





void RCC_EnableClock(u8 copyu8_BusID,u8 copyu8_PerID)
{
	if(copyu8_PerID <=31)
	{
		switch(copyu8_BusID)
		{
		case RCC_AHB:	SetBit(RCC_AHBENR_REG  , copyu8_PerID); break;
		case RCC_APB1:	SetBit(RCC_APB1ENR_REG , copyu8_PerID); break;
		case RCC_APB2:	SetBit(RCC_APB2ENR_REG , copyu8_PerID); break;
default :break;
		}
	}
	else
	{// Wrong input}
}





void RCC_DisableClock(u8 copyu8_BusID,u8 copyu8_PerID)
{
	if(copyu8_PerID <=31)
	{
		switch(copyu8_BusID)
		{
		case RCC_AHB:	ClearBit(RCC_AHBENR_REG  , copyu8_PerID); break;
		case RCC_APB1:	ClearBit(RCC_APB1ENR_REG , copyu8_PerID); break;
		case RCC_APB2:	ClearBit(RCC_APB2ENR_REG , copyu8_PerID); break;
		default :	break;
		}
	}
	else
	{// Wrong input}
}

