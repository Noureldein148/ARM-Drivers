/*
 * BitMath.h
 *
 *  Created on: Nov 1, 2023
 *      Author: admin
 */

#ifndef BITMATH_H_
#define BITMATH_H_

#define SetBit(REG,bit)    REG|=(1<<bit)
#define ClearBit(REG,bit)  REG&=(~(1<<bit))
#define ToggleBit(REG,bit) REG^= (1<<bit)
#define GetBit(REG,bit)   (REG>>bit)&1

#endif /* BITMATH_H_ */
