/**
 ******************************************************************************
 * @file           : CortexM4_Core_SysTick.h
 * @author         : Yazan Abd-Almajeed
 * @brief          : Contains the SysTick Control
 ******************************************************************************
 */

#ifndef CORTEXM4_CORTEXM4_CORE_SYSTICK_H_
#define CORTEXM4_CORTEXM4_CORE_SYSTICK_H_

/*----------------------------Includes------------------------------------------*/
#include "HAL_Drivers/RCC/STM32F4xx_HAL_RCC.h"
#include "Common/Std_Types.h"
#include "CortexM4_Core_SysTick_Cfg.h"

/*----------------------------Macro Declarations--------------------------------*/
#define SYSTICK_BASE	(0xE000E010UL)
#define SYSTICK			((SysTick_Type *)0xE000E010UL)

/* CSR Register Bits Defines */
#define SYSTICK_CSR_ENABLE_POS		(0U)
#define SYSTICK_CSR_ENABLE_MSK		(1UL << SYSTICK_CSR_ENABLE_POS)

#define SYSTICK_CSR_TICKINT_POS		(1U)
#define SYSTICK_CSR_TICKINT_MSK		(1UL << SYSTICK_CSR_TICKINT_POS)

#define SYSTICK_CSR_CLKSOURCE_POS	(2U)
#define SYSTICK_CSR_CLKSOURCE_MSK	(1UL << SYSTICK_CSR_CLKSOURCE_POS)

#define SYSTICK_CSR_COUNTFLAG_POS	(16U)
#define SYSTICK_CSR_COUNTFLAG_MSK	(1UL << SYSTICK_CSR_COUNTFLAG_POS)

/* RVR Register Bits Defines */
#define SYSTICK_RVR_RELOAD_POS		(0U)
#define SYSTICK_RVR_RELOAD_MSK		(0xFFFFFFUL << SYSTICK_RVR_RELOAD_POS)

#define SYSTICK_SINGLEINTERVAL		0
#define SYSTICK_PERIODICINTERVAL	1

/*----------------------------Macro Function Declarations-----------------------*/

/*----------------------------Data Type Declarations----------------------------*/
typedef struct{
	volatile uint32_t SYST_CSR;
	volatile uint32_t SYST_RVR;
	volatile uint32_t SYST_CVR;
	volatile uint32_t SYST_CALIB;
}SysTick_Type;

typedef void(* ptrFunction)(void);

/*----------------------------Software Interface Declarations-------------------*/
uint8_t SysTick_Init(uint32_t SysTick_Ticks);
void SysTick_DeInit(void);
void SysTick_WaitBlocking(uint32_t SysTick_Ticks);
void SysTick_SingleInterval(uint32_t SysTick_Ticks, ptrFunction *CallBack);
void SysTick_PeriodicInterval(uint32_t SysTick_Ticks, ptrFunction *CallBack);
uint32_t SysTick_GetRemainingTicks(void);

#endif /* CORTEXM4_CORTEXM4_CORE_SYSTICK_H_ */
