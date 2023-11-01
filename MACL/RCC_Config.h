/*
 * RCC_Config.h
 *
 *  Created on: Nov 1, 2023
 *      Author: Nour
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_
#include "RCC_Private.h"

/**************RCC Buses**********************/
#define RCC_AHB   0
#define RCC_APB1  1
#define RCC_APB2  2
/****************RCC CLK**********************/
#define RCC_CLK_HSI    		 0
#define RCC_CLK_HSE_CRYSTAL  1
#define RCC_CLK_HSE_RC    	 2
#define RCC_CLK_PLL    		 3
#define RCC_CLK_PLL_2  		 4
#define RCC_CLK_PLL_3  		 5

#define RCC_CLK RCC_CLK_PLL

/******************RCC PLL CLK Input**************/
#if RCC_CLK == RCC_CLK_PLL

#define RCC_PLL_INPUT_HSI_DIV_2   0
#define RCC_PLL_INPUT_HSE         1
#define RCC_PLL_INPUT_HSE_DIV_2   2

#define RCC_PLL_INPUT   RCC_PLL_INPUT_HSI_DIV_2
#endif


/*************************************/
#define RCC_AHB_NO_PRESCALAR       0b0000
#define RCC_AHB_PRESCALAR_DIV_2    0b1000
#define RCC_AHB_PRESCALAR_DIV_4    0b1001
#define RCC_AHB_PRESCALAR_DIV_8    0b1010
#define RCC_AHB_PRESCALAR_DIV_16   0b1011
#define RCC_AHB_PRESCALAR_DIV_64   0b1100
#define RCC_AHB_PRESCALAR_DIV_128  0b1101
#define RCC_AHB_PRESCALAR_DIV_256  0b1110
#define RCC_AHB_PRESCALAR_DIV_512  0b1111

#define RCC_AHB_PRESCALAR   RCC_AHB_NO_PRESCALAR
/************************************************/

#define RCC_APB1_NO_PRESCALAR       0b0000
#define RCC_APB1_PRESCALAR_DIV_2    0b100
#define RCC_APB1_PRESCALAR_DIV_4    0b101
#define RCC_APB1_PRESCALAR_DIV_8    0b110
#define RCC_APB1_PRESCALAR_DIV_16   0b111

#define RCC_APB1_PRESCALAR   RCC_APB1_NO_PRESCALAR

/****************************************************/

#define RCC_APB2_NO_PRESCALAR       0b0000
#define RCC_APB2_PRESCALAR_DIV_2    0b100
#define RCC_APB2_PRESCALAR_DIV_4    0b101
#define RCC_APB2_PRESCALAR_DIV_8    0b110
#define RCC_APB2_PRESCALAR_DIV_16   0b111

#define RCC_APB2_PRESCALAR   RCC_APB1_NO_PRESCALAR

/****************************************************/
/*****************PLL MUL  Options*******************/
#define PLL_INPUT_CLK_MUL_2  0b0000
#define PLL_INPUT_CLK_MUL_3  0b0001
#define PLL_INPUT_CLK_MUL_4  0b0010
#define PLL_INPUT_CLK_MUL_5  0b0011
#define PLL_INPUT_CLK_MUL_6  0b0100
#define PLL_INPUT_CLK_MUL_7  0b0101
#define PLL_INPUT_CLK_MUL_8  0b0110
#define PLL_INPUT_CLK_MUL_9  0b0111
#define PLL_INPUT_CLK_MUL_10 0b1000
#define PLL_INPUT_CLK_MUL_11 0b1001
#define PLL_INPUT_CLK_MUL_12 0b1010
#define PLL_INPUT_CLK_MUL_13 0b1011
#define PLL_INPUT_CLK_MUL_14 0b1100
#define PLL_INPUT_CLK_MUL_15 0b1101
#define PLL_INPUT_CLK_MUL_16 0b1110
#define PLL_INPUT_CLK_MUL_16 0b1111


#endif /* RCC_CONFIG_H_ */
