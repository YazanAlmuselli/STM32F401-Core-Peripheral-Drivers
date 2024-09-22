/**
 ******************************************************************************
 * @file           : main.c
 * @author         :إYazan Abd-Almajeed
 * @brief          : Main program body
 ******************************************************************************
 */

#include "CortexM4/CortexM4_Interface.h"
#include "HAL_Drivers/RCC/STM32F4xx_HAL_RCC.h"

uint8_t RetVal = 0;
volatile uint32_t MainAppCounter = 0;

void SystemClock_Config(void);

void SysTick_Func_1(void){
	MainAppCounter++;
}

int main(void)
{

	SystemClock_Config();

	RetVal = SysTick_Init(2000000);
	SysTick_PeriodicInterval(2000000, SysTick_Func_1);

	//SysTick_PeriodicInterval(1000000, SysTick_Func_1);

	while(1){
		//SysTick_WaitBlocking(1000000);
	}
}

void SystemClock_Config(void){
	HAL_StatusTypeDef RetStatus = HAL_OK;
	RCC_Osc_InitTypeDef RCC_Osc_InitStruct = {0};
	RCC_CLK_InitTypeDef RCC_CLK_InitStruct = {0};

	RCC_Osc_InitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_Osc_InitStruct.HSE_State = RCC_HSE_ON;

	RCC_CLK_InitStruct.AHBCLKDivider  = RCC_SYSCLK_AHB_DIV1;
	RCC_CLK_InitStruct.APB1CLKDivider = RCC_SYSCLK_APB1_DIV1;
	RCC_CLK_InitStruct.APB2CLKDivider = RCC_SYSCLK_APB2_DIV1;

	RetStatus = RCC_OscConfig(&RCC_Osc_InitStruct);
	RetStatus = RCC_OscConfig(NULL);
	RetStatus = RCC_ClockConfig(&RCC_CLK_InitStruct);
}

