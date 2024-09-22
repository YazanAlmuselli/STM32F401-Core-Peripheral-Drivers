/**
 ******************************************************************************
 * @file           : CortexM4_Core_SCB.h
 * @author         : Yazan Abd-Almajeed
 * @brief          : Contains the SCB Control
 ******************************************************************************
 */

#ifndef CORTEXM4_CORE_SCB_H_
#define CORTEXM4_CORE_SCB_H_

/*----------------------------Includes------------------------------------------*/
#include "Common/Std_Types.h"

/*----------------------------Macro Declarations--------------------------------*/
#define SCB_BASE	(0xE000ED00UL)
#define SCB			((SCB_Type *)0xE000ED00UL)

#define SCB_PRIPRITYGROUP_0		0x00000007U  // => 0 bits for pre-emtion Priority, 4 bits for Sub-priority
#define SCB_PRIPRITYGROUP_1		0x00000006U  // => 1 bits for pre-emtion Priority, 3 bits for Sub-priority
#define SCB_PRIPRITYGROUP_2		0x00000005U  // => 2 bits for pre-emtion Priority, 2 bits for Sub-priority
#define SCB_PRIPRITYGROUP_3		0x00000004U  // => 3 bits for pre-emtion Priority, 1 bits for Sub-priority
#define SCB_PRIPRITYGROUP_4		0x00000003U  // => 4 bits for pre-emtion Priority, 0 bits for Sub-priority

#define SCB_AIRCR_PRIGROUP_POS		8U
#define SCB_AIRCR_PRIGROUP_MSK		(7UL << SCB_AIRCR_PRIGROUP_POS)

#define SCB_AIRCR_VECTKEYSTAT_POS	16U
#define SCB_AIRCR_VECTKEYSTAT_MSK	(0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_POS)

/*----------------------------Macro Function Declarations-----------------------*/


/*----------------------------Data Type Declarations----------------------------*/
typedef struct{
	volatile uint32_t ACTLR;
	volatile uint32_t CPUID;
	volatile uint32_t ICSR;
	volatile uint32_t VTOR;
	volatile uint32_t AIRCR;
	volatile uint32_t SCR;
	volatile uint32_t CCR;
	volatile uint32_t SHPR1;
	volatile uint32_t SHPR2;
	volatile uint32_t SHPR3;
	volatile uint32_t SHCRS;
	volatile uint32_t CFSR;
}SCB_Type;


/*----------------------------Software Interface Declarations-------------------*/
void SCB_SetPriorityGrouping(uint32_t PriorityGroup);
uint32_t SCB_GetPriorityGrouping(void);


#endif /* CORTEXM4_CORE_SCB_H_ */
