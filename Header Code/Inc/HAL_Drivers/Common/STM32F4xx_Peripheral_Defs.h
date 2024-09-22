/**
 ******************************************************************************
 * @file           : STM32F4xx_Peripheral_Defs.h
 * @author         : Yazan Abd-Almajeed
 * @brief          : Contains the Data Structure and the Address Mapping of all Peripherals
 ******************************************************************************
 */

#ifndef HAL_DRIVERS_COMMON_STM32F4XX_PERIPHERAL_DEFS_H_
#define HAL_DRIVERS_COMMON_STM32F4XX_PERIPHERAL_DEFS_H_

/*----------------------------Includes------------------------------------------*/
#include "Common/Std_Types.h"

/*----------------------------Macro Declarations--------------------------------*/
#define PERIPH_BASE				 0x40000000UL
#define AHB1PERIPH_BASE 		(PERIPH_BASE + 0x00020000UL)
#define RCC_BASE				(AHB1PERIPH_BASE + 0x3800UL)
#define RCC						((RCC_TypeDef *)RCC_BASE)

#define RCC_AHB1ENR_GPIOAEN_POS		(0U)
#define RCC_AHB1ENR_GPIOAEN_MSK		(0x1UL << RCC_AHB1ENR_GPIOAEN_POS)
#define RCC_AHB1ENR_GPIOBEN_POS		(1U)
#define RCC_AHB1ENR_GPIOBEN_MSK		(0x1UL << RCC_AHB1ENR_GPIOBEN_POS)
#define RCC_AHB1ENR_GPIOCEN_POS		(2U)
#define RCC_AHB1ENR_GPIOCEN_MSK		(0x1UL << RCC_AHB1ENR_GPIOCEN_POS)
#define RCC_AHB1ENR_GPIODEN_POS		(3U)
#define RCC_AHB1ENR_GPIODEN_MSK		(0x1UL << RCC_AHB1ENR_GPIODEN_POS)
#define RCC_AHB1ENR_GPIOEEN_POS		(4U)
#define RCC_AHB1ENR_GPIOEEN_MSK		(0x1UL << RCC_AHB1ENR_GPIOEEN_POS)
#define RCC_AHB1ENR_GPIOHEN_POS		(7U)
#define RCC_AHB1ENR_GPIOHEN_MSK		(0x1UL << RCC_AHB1ENR_GPIOHEN_POS)

#define RCC_CR_HSEON_POS		(16U)
#define RCC_CR_HSEON_MSK		(0x1UL << RCC_CR_HSEON_POS)

#define RCC_OSCILLATORTYPE_NONE		0x00000000U
#define RCC_OSCILLATORTYPE_HSE		0x00000001U
#define RCC_OSCILLATORTYPE_HSI		0x00000002U
#define RCC_OSCILLATORTYPE_LSE		0x00000004U
#define RCC_OSCILLATORTYPE_LSI		0x00000008U

#define RCC_HSE_OFF					((uint8_t)0x00)
#define RCC_HSE_ON					((uint8_t)0x01)
#define RCC_LSE_OFF					((uint8_t)0x00)
#define RCC_LSE_ON					((uint8_t)0x01)
#define RCC_HSI_OFF					((uint8_t)0x00)
#define RCC_HSI_ON					((uint8_t)0x01)
#define RCC_LSI_OFF					((uint8_t)0x00)
#define RCC_LSI_ON					((uint8_t)0x01)

#define RCC_CFGR_SW0_POS		(0U)
#define RCC_CFGR_SW0_MSK		(0x1UL << RCC_CFGR_SW0_POS)
#define RCC_CFGR_SW1_POS		(1U)
#define RCC_CFGR_SW1_MSK		(0x1UL << RCC_CFGR_SW1_POS)

#define RCC_CFGR_HPRE_POS			4U
#define RCC_CFGR_HPRE_MSK			(0xFUL << RCC_CFGR_HPRE_POS)

#define RCC_CFGR_HPRE_DIV1			0x00000000U
#define RCC_CFGR_HPRE_DIV2			0x00000080U
#define RCC_CFGR_HPRE_DIV4			0x00000090U
#define RCC_CFGR_HPRE_DIV8			0x000000A0U
#define RCC_CFGR_HPRE_DIV16			0x000000B0U
#define RCC_CFGR_HPRE_DIV64			0x000000C0U
#define RCC_CFGR_HPRE_DIV128		0x000000D0U
#define RCC_CFGR_HPRE_DIV256		0x000000E0U
#define RCC_CFGR_HPRE_DIV512		0x000000F0U


#define RCC_CFGR_PPRE1_POS			10U
#define RCC_CFGR_PPRE1_MSK			(0x7UL << RCC_CFGR_PPRE1_POS)

#define RCC_CFGR_PPRE1_DIV1			0x00000000U
#define RCC_CFGR_PPRE1_DIV2			0x00001000U
#define RCC_CFGR_PPRE1_DIV4			0x00001400U
#define RCC_CFGR_PPRE1_DIV8			0x00001800U
#define RCC_CFGR_PPRE1_DIV16		0x00001C00U


#define RCC_CFGR_PPRE2_POS			13U
#define RCC_CFGR_PPRE2_MSK			(0x7UL << RCC_CFGR_PPRE2_POS)

#define RCC_CFGR_PPRE2_DIV1			0x00000000U
#define RCC_CFGR_PPRE2_DIV2			0x00008000U
#define RCC_CFGR_PPRE2_DIV4			0x0000A000U
#define RCC_CFGR_PPRE2_DIV8			0x0000C000U
#define RCC_CFGR_PPRE2_DIV16		0x0000E000U

/*----------------------------Macro Function Declarations-----------------------*/


/*----------------------------Data Type Declarations----------------------------*/
typedef struct{
	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_PLLCFGR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_AHB1RSTR;
	volatile uint32_t RCC_AHB2RSTR;
	uint32_t		  RESERVED0[2];
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_APB2RSTR;
	uint32_t		  RESERVED1[2];
	volatile uint32_t RCC_AHB1ENR;
	volatile uint32_t RCC_AHB2ENR;
	uint32_t		  RESERVED2[2];
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_APB2ENR;
	uint32_t		  RESERVED3[2];
	volatile uint32_t RCC_AHB1LPENR;
	volatile uint32_t RCC_AHB2LPENR;
	uint32_t		  RESERVED4[2];
	volatile uint32_t RCC_APB1LPENR;
	volatile uint32_t RCC_APB2LPENR;
	uint32_t		  RESERVED5[2];
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
	uint32_t		  RESERVED6[2];
	volatile uint32_t RCC_SSCGR;
	volatile uint32_t RCC_PLLI2SCFGR;
	uint32_t		  RESERVED7;
	volatile uint32_t RCC_DCKCFGR;
}RCC_TypeDef;

/*----------------------------Software Interface Declarations-------------------*/

#endif /* HAL_DRIVERS_COMMON_STM32F4XX_PERIPHERAL_DEFS_H_ */
