/**
 ******************************************************************************
 * @file           : STM32F4xx_HAL_RCC.h
 * @author         : Yazan Abd-Almajeed
 * @brief          : Contains the RCC Control
 ******************************************************************************
 */

#ifndef HAL_DRIVERS_RCC_STM32F4XX_HAL_RCC_H_
#define HAL_DRIVERS_RCC_STM32F4XX_HAL_RCC_H_

/*----------------------------Includes------------------------------------------*/
#include "Common/Common_Macros.h"
#include "HAL_Drivers/Common/STM32F4xx_HAL_Def.h"
#include "HAL_Drivers/Common/STM32F4xx_Peripheral_Defs.h"

/*----------------------------Macro Declarations--------------------------------*/
#define RCC_SYSCLK_AHB_DIV1			RCC_CFGR_HPRE_DIV1
#define RCC_SYSCLK_AHB_DIV2			RCC_CFGR_HPRE_DIV2
#define RCC_SYSCLK_AHB_DIV4			RCC_CFGR_HPRE_DIV4
#define RCC_SYSCLK_AHB_DIV8			RCC_CFGR_HPRE_DIV8
#define RCC_SYSCLK_AHB_DIV16		RCC_CFGR_HPRE_DIV16
#define RCC_SYSCLK_AHB_DIV64		RCC_CFGR_HPRE_DIV64
#define RCC_SYSCLK_AHB_DIV128		RCC_CFGR_HPRE_DIV128
#define RCC_SYSCLK_AHB_DIV256		RCC_CFGR_HPRE_DIV256
#define RCC_SYSCLK_AHB_DIV512		RCC_CFGR_HPRE_DIV512

#define RCC_SYSCLK_APB1_DIV1		RCC_CFGR_PPRE1_DIV1
#define RCC_SYSCLK_APB1_DIV2		RCC_CFGR_PPRE1_DIV2
#define RCC_SYSCLK_APB1_DIV4		RCC_CFGR_PPRE1_DIV4
#define RCC_SYSCLK_APB1_DIV8		RCC_CFGR_PPRE1_DIV8
#define RCC_SYSCLK_APB1_DIV16		RCC_CFGR_PPRE1_DIV16

#define RCC_SYSCLK_APB2_DIV1		RCC_CFGR_PPRE2_DIV1
#define RCC_SYSCLK_APB2_DIV2		RCC_CFGR_PPRE2_DIV2
#define RCC_SYSCLK_APB2_DIV4		RCC_CFGR_PPRE2_DIV4
#define RCC_SYSCLK_APB2_DIV8		RCC_CFGR_PPRE2_DIV8
#define RCC_SYSCLK_APB2_DIV16		RCC_CFGR_PPRE2_DIV16

/*----------------------------Macro Function Declarations-----------------------*/

#define HAL_RCC_GPIOA_CLK_ENABLE()		(SET_BIT(RCC->RCC_AHB1ENR, RCC_AHB1ENR_GPIOAEN_MSK))
#define HAL_RCC_GPIOB_CLK_ENABLE()		(SET_BIT(RCC->RCC_AHB1ENR, RCC_AHB1ENR_GPIOBEN_MSK))
#define HAL_RCC_GPIOC_CLK_ENABLE()		(SET_BIT(RCC->RCC_AHB1ENR, RCC_AHB1ENR_GPIOCEN_MSK))
#define HAL_RCC_GPIOD_CLK_ENABLE()		(SET_BIT(RCC->RCC_AHB1ENR, RCC_AHB1ENR_GPIODEN_MSK))
#define HAL_RCC_GPIOE_CLK_ENABLE()		(SET_BIT(RCC->RCC_AHB1ENR, RCC_AHB1ENR_GPIOEEN_MSK))
#define HAL_RCC_GPIOH_CLK_ENABLE()		(SET_BIT(RCC->RCC_AHB1ENR, RCC_AHB1ENR_GPIOHEN_MSK))

#define HAL_RCC_GPIOA_CLK_DISABLE()		(CLEAR_BIT(RCC->RCC_AHB1ENR, RCC_AHB1ENR_GPIOAEN_MSK))
#define HAL_RCC_GPIOB_CLK_DISABLE()		(CLEAR_BIT(RCC->RCC_AHB1ENR, RCC_AHB1ENR_GPIOBEN_MSK))
#define HAL_RCC_GPIOC_CLK_DISABLE()		(CLEAR_BIT(RCC->RCC_AHB1ENR, RCC_AHB1ENR_GPIOCEN_MSK))
#define HAL_RCC_GPIOD_CLK_DISABLE()		(CLEAR_BIT(RCC->RCC_AHB1ENR, RCC_AHB1ENR_GPIODEN_MSK))
#define HAL_RCC_GPIOE_CLK_DISABLE()		(CLEAR_BIT(RCC->RCC_AHB1ENR, RCC_AHB1ENR_GPIOEEN_MSK))
#define HAL_RCC_GPIOH_CLK_DISABLE()		(CLEAR_BIT(RCC->RCC_AHB1ENR, RCC_AHB1ENR_GPIOHEN_MSK))

/*----------------------------Data Type Declarations----------------------------*/


typedef struct{
	uint32_t OscillatorType; 	 //CLK Source : HSE, HSI, LSE, LSI
	uint32_t HSE_State;			 // ON or OFF
	uint32_t LSE_State;			 // ON or OFF
	uint32_t HSI_State;	    	 // ON or OFF
	uint32_t LSI_State;			 // ON or OFF
}RCC_Osc_InitTypeDef;

typedef struct{
	uint32_t AHBCLKDivider;
	uint32_t APB1CLKDivider;
	uint32_t APB2CLKDivider;
}RCC_CLK_InitTypeDef;

/*----------------------------Software Interface Declarations-------------------*/
HAL_StatusTypeDef RCC_OscConfig(RCC_Osc_InitTypeDef *RCC_Osc_InitStruct);
HAL_StatusTypeDef RCC_ClockConfig(RCC_CLK_InitTypeDef *RCC_CLK_InitStruct);



#endif /* HAL_DRIVERS_RCC_STM32F4XX_HAL_RCC_H_ */
