/*
 * RCC_Private.h
 *
 *  Created on: Oct 31, 2023
 *      Author: Nour
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_



#define RCC_CIR_REG 	 *((volatile u32*)0X40021008)
#define RCC_APB2RSTR_REG *((volatile u32*)0X4002100C)
#define RCC_APB1RSTR_REG *((volatile u32*)0X40021010)
#define RCC_AHBENR_REG   *((volatile u32*)0X40021014)
#define RCC_APB2ENR_REG  *((volatile u32*)0X40021018)
#define RCC_APB1ENR_REG  *((volatile u32*)0X4002101C)
#define RCC_BDCR_REG     *((volatile u32*)0X40021020)
#define RCC_CSR_REG      *((volatile u32*)0X40021024)


typedef struct
{
	u32 HSION:1;
	u32 HSIRDY:1;
	u32 :1;
	u32 HSITRIM:5;
	u32 HSICAL:8;
	u32 HSEON:1;
	u32 HSERDY:1;
	u32 HSEBYP:1;
	u32 CSSON:1;
	u32 :4;
	u32 PLLON:1;
	u32 PLLRDY:1;
	u32 PLL2ON:1;
	u32 PLL2RDY:1;
	u32 PLL3ON:1;
	u32 PLL3RDY:1;
	u32 :2;
}RCC_CR;
#define RCC_CR_REG ((volatile RCC_CR*)0X40021000)


typedef struct
{
	u32 SW		:2;
	u32 SWS		:2;
	u32 HPRE 	:4;
	u32 PPRE1	:3;
	u32 PPRE2	:3;
	u32 ADCPRE	:2;
	u32 PLLSRC	:1;
	u32 PLLXTPRE:1;
	u32 PLLMUL	:4;
	u32 OTGFSPRE:1;
	u32 		:1;
	u32 MCO		:4;
	u32 		:4;
}RCC_CFGR;
#define RCC_CFGR_REG *((volatile RCC_CFGR*)0X40021004)




#endif /* RCC_PRIVATE_H_ */
