/**
 ******************************************************************************
 * @file           : STM32F4xx_HAL_RCC.c
 * @author         : Yazan Abd-Almajeed
 * @brief          : Contains the RCC Control
 ******************************************************************************
 */

#include "HAL_Drivers/RCC/STM32F4xx_HAL_RCC.h"


HAL_StatusTypeDef RCC_OscConfig(RCC_Osc_InitTypeDef *RCC_Osc_InitStruct){
	HAL_StatusTypeDef RetStaus = HAL_OK;
	if(NULL == RCC_Osc_InitStruct){
		RetStaus = HAL_ERROR;
	}
	else{
		if(RCC_OSCILLATORTYPE_HSE == RCC_Osc_InitStruct->OscillatorType){
			if(RCC_HSE_ON == RCC_Osc_InitStruct->HSE_State){
				/* HSE Selected */
				CLEAR_BIT(RCC->RCC_CFGR, RCC_CFGR_SW0_MSK);
				SET_BIT(RCC->RCC_CFGR, RCC_CFGR_SW1_MSK);
				/* HSE ON */
				SET_BIT(RCC->RCC_CR, RCC_CR_HSEON_MSK);
			}
			else{
				CLEAR_BIT(RCC->RCC_CR, RCC_CR_HSEON_MSK);
			}
		}
		else if(RCC_OSCILLATORTYPE_HSI == RCC_Osc_InitStruct->OscillatorType){

		}
		else if(RCC_OSCILLATORTYPE_LSE == RCC_Osc_InitStruct->OscillatorType){

		}
		else if(RCC_OSCILLATORTYPE_LSI == RCC_Osc_InitStruct->OscillatorType){

		}
		else{
			/* Nothing */
		}
	}

	return RetStaus;
}

HAL_StatusTypeDef RCC_ClockConfig(RCC_CLK_InitTypeDef *RCC_CLK_InitStruct){
	HAL_StatusTypeDef RetStaus = HAL_OK;
		if(NULL == RCC_CLK_InitStruct){
			RetStaus = HAL_ERROR;
		}
		else{
			MODIFY_REG(RCC->RCC_CFGR, RCC_CFGR_HPRE_MSK, RCC_CLK_InitStruct->AHBCLKDivider);
			MODIFY_REG(RCC->RCC_CFGR, RCC_CFGR_PPRE1_MSK, RCC_CLK_InitStruct->APB1CLKDivider);
			MODIFY_REG(RCC->RCC_CFGR, RCC_CFGR_PPRE2_MSK, RCC_CLK_InitStruct->APB2CLKDivider);
		}

		return RetStaus;
}
