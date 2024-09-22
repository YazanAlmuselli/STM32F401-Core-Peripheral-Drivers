/**
 ******************************************************************************
 * @file           : Common_Macros.h
 * @author         : Yazan Abd-Almajeed
 * @brief          : Contains the Common Macros
 ******************************************************************************
 */

#ifndef COMMON_COMMON_MACROS_H_
#define COMMON_COMMON_MACROS_H_

/*----------------------------Includes------------------------------------------*/

/*----------------------------Macro Declarations--------------------------------*/

/*----------------------------Macro Function Declarations-----------------------*/
#define SET_BIT(REG, BIT)		(REG |= (BIT))
#define CLEAR_BIT(REG, BIT)		(REG &= ~(BIT))
#define READ_BIT(REG, BIT)		((REG) & (BIT))

#define READ_REG(REG)							(REG)
#define WRITE_REG(REG, VAL)						((REG) = (VAL))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)		WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/*----------------------------Data Type Declarations----------------------------*/

/*----------------------------Software Interface Declarations-------------------*/

#endif /* COMMON_COMMON_MACROS_H_ */
