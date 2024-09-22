/**
 ******************************************************************************
 * @file           : CortexM4_Core_NVIC.h
 * @author         : Yazan Abd-Almajeed
 * @brief          : Includes, Macros, Macro Functions, Data Types, APIs
 ******************************************************************************
 */

#ifndef CORTEXM4_CORE_NVIC_H_
#define CORTEXM4_CORE_NVIC_H_

/*----------------------------Includes------------------------------------------*/
#include "Common/Std_Types.h"

/*----------------------------Macro Declarations--------------------------------*/
#define NVIC_BASE (0xE000E100UL)
#define NVIC	  ((NVIC_Type *)NVIC_BASE)

#define NVIC_PRIO_BITS	4U

/*----------------------------Macro Function Declarations-----------------------*/


/*----------------------------Data Type Declarations----------------------------*/
typedef struct{
	volatile uint32_t ISER[8U];
	uint32_t RESERVED0[24U];
	volatile uint32_t ICER[8U];
	uint32_t RESERVED1[24U];
	volatile uint32_t ISPR[8U];
	uint32_t RESERVED2[24U];
	volatile uint32_t ICPR[8U];
	uint32_t RESERVED3[24U];
	volatile uint32_t IABR[8U];
	uint32_t RESERVED4[56U];
	volatile uint8_t IP[240U];
	uint32_t RESERVED5[644U];
	volatile uint32_t STIR;
}NVIC_Type;

typedef enum{
/*----------------------------Cortex-M4 Processor Exceptions Number-----------------------------*/
	NMI_IRQ						= -14,
	MemManage_IRQ				= -12,
	BusFault_IRQ				= -11,
	UsageFault_IRQ				= -10,
	SVCall_IRQ					= -5,
	DebugMonitor_IRQ			= -4,
	PendSV_IRQ					= -2,
	Systick_IRQ					= -1,
/*----------------------------STM32 Specific Interrupts Number-----------------------------*/
	WWDG_IRQ					= 0,
	EXTI16_PVD_IRQ				= 1,
	EXTI21_TAMP_STAMP_IRQ		= 2,
	EXTI22_RTC_WKUP_IRQ			= 3,
	FLASH_IRQ					= 4,
	RCC_IRQ						= 5,
	EXTI0_IRQ					= 6,
	EXTI1_IRQ					= 7,
	EXTI2_IRQ					= 8,
	EXTI3_IRQ					= 9,
	EXTI4_IRQ					= 10,
	DMA1_Stream0_IRQ			= 11,
	DMA1_Stream1_IRQ			= 12,
	DMA1_Stream2_IRQ			= 13,
	DMA1_Stream3_IRQ			= 14,
	DMA1_Stream4				= 15,
	DMA1_Stream5_IRQ			= 16,
	DMA1_Stream6_IRQ			= 17,
	ADC_IRQ						= 18,
	EXTI9_5_IRQ					= 23,
	TIM1_BRK_TIM9_IRQ			= 24,
	TIM1_UP_TIM10_IRQ			= 25,
	TIM1_TRG_COM_TIM11_IRQ		= 26,
	TIM1_CC_IRQ					= 27,
	TIM2_IRQ					= 28,
	TIM3_IRQ					= 29,
	TIM4_IRQ					= 30,
	I2C1_EV_IRQ					= 31,
	I2C1_ER_IRQ					= 32,
	I2C2_EV_IRQ					= 33,
	I2C2_ER_IRQ					= 34,
	SPI1_IRQ					= 35,
	SPI2_IRQ					= 36,
	USART1_IRQ					= 37,
	USART2_IRQ					= 38,
	EXTI15_10_IRQ				= 40,
	EXTI17_RTC_Alarm_IRQ		= 41,
	EXTI18_OTG_FS_WKUP_IRQ		= 42,
	DMA1_Stream7_IRQ			= 47,
	SDIO_IRQ					= 49,
	TIM5_IRQ					= 50,
	SPI3_IRQ					= 51,
	DMA2_Stream0_IRQ			= 56,
	DMA2_Stream1_IRQ			= 57,
	DMA2_Stream2_IRQ			= 58,
	DMA2_Stream3_IRQ			= 59,
	DMA2_Stream4_IRQ			= 60,
	OTG_FS_IRQ					= 67,
	DMA2_Stream5_IRQ			= 68,
	DMA2_Stream6_IRQ			= 69,
	DMA2_Stream7_IRQ			= 70,
	USART6_IRQ					= 71,
	I2C3_EV_IRQ					= 72,
	I2C3_ER_IRQ					= 73,
	FPU_IRQ						= 81,
	SPI4_IRQ					= 84,
}IRQn_Type;


/*----------------------------Software Interface Declarations-------------------*/
void NVIC_EnableIRQ(IRQn_Type IRQn);
void NVIC_DisableIRQ(IRQn_Type IRQn);
void NVIC_SetPendingIRQ(IRQn_Type IRQn);
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);
uint32_t NVIC_GetActive(IRQn_Type IRQn);
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t PriorityGroup);
uint32_t NVIC_GetPriority(IRQn_Type IRQn);


#endif /* CORTEXM4_CORE_NVIC_H_ */
