/**
 ******************************************************************************
 * @file           : CortexM4_Core_SysTick.c
 * @author         : Yazan Abd-Almajeed
 * @brief          : Contains the SysTick Control
 ******************************************************************************
 */

#include "CortexM4/CortexM4_Core_SysTick.h"

static volatile ptrFunction SysTick_CallBack = NULL;
static volatile uint8_t SysTick_Mode = SYSTICK_SINGLEINTERVAL;

uint8_t SysTick_Init(uint32_t SysTick_Ticks){
	uint8_t RetVal = 0;

	if(RetVal > SYSTICK_RVR_RELOAD_MSK){
		RetVal = 1;		/* Not OK */
	}
	else{
		/* Disable SysTick Counter */
		CLEAR_BIT(SYSTICK->SYST_CSR, SYSTICK_CSR_ENABLE_MSK);
		/* Set Reload Register to SysTick Ticks */
		SYSTICK->SYST_RVR = SysTick_Ticks; /* 1 000 000 for 1Sec */
		/* Reset the SysTick Counter Value */
		SYSTICK->SYST_CVR = 0;
		/* Select Processor Clock */
#if (SYSTICK_CLOCK_SOURCE == SYSTICK_CLOCK_SOURCE_DIV1)
		SET_BIT(SYSTICK->SYST_CSR, SYSTICK_CSR_CLKSOURCE_MSK);

#elif (SYSTICK_CLOCK_SOURCE == SYSTICK_CLOCK_SOURCE_DIV8)
		CLEAR_BIT(SYSTICK->SYST_CSR, SYSTICK_CSR_CLKSOURCE_MSK);
#else
#error "Invalid Clock Source"
#endif
		/* Disable SysTick IRQ */
		CLEAR_BIT(SYSTICK->SYST_CSR, SYSTICK_CSR_TICKINT_MSK);
	}

	return RetVal;
}

void SysTick_DeInit(void){
	/* Disable SysTick Counter */
	CLEAR_BIT(SYSTICK->SYST_CSR, SYSTICK_CSR_ENABLE_MSK);
	/* Reset the SysTick Reload Register */
	SYSTICK->SYST_RVR = 0;
	/* Reset the SysTick Counter Value */
	SYSTICK->SYST_CVR = 0;
	/* Disable SysTick IRQ */
	CLEAR_BIT(SYSTICK->SYST_CSR, SYSTICK_CSR_TICKINT_MSK);
}

void SysTick_WaitBlocking(uint32_t SysTick_Ticks){
	/* Set Reload Register to SysTick Ticks */
	SYSTICK->SYST_RVR = SysTick_Ticks; /* 1 000 000 for 1Sec */
	/* Enable the SysTick Counter */
	SET_BIT(SYSTICK->SYST_CSR, SYSTICK_CSR_ENABLE_MSK);
	/* Wait the COUNTFLAG Returns 1 */
	while(READ_BIT(SYSTICK->SYST_CSR, SYSTICK_CSR_COUNTFLAG_MSK) == 0);
	/* Disable SysTick Counter */
	CLEAR_BIT(SYSTICK->SYST_CSR, SYSTICK_CSR_ENABLE_MSK);
	/* Reset the SysTick Reload Register */
	SYSTICK->SYST_RVR = 0;
	/* Reset the SysTick Counter Value */
	SYSTICK->SYST_CVR = 0;
}

void SysTick_SingleInterval(uint32_t SysTick_Ticks, ptrFunction *CallBack){
	if(CallBack != NULL){
		/* Set Reload Register to SysTick Ticks */
		SYSTICK->SYST_RVR = SysTick_Ticks; 										/* 1 000 000 for 1Sec */
		/* Copy the User CallBack to a Local Function */
		SysTick_CallBack = CallBack;
		/* Set SysTick Timer to the Single Interval Mode */
		SysTick_Mode = SYSTICK_SINGLEINTERVAL;
		/* Enable SysTick IRQ NVIC Line */
		SET_BIT(SYSTICK->SYST_CSR, SYSTICK_CSR_TICKINT_MSK);
		/* Set the SysTick IRQ Priority Least Urgent : Highest Priority Number */

		/* Enable the SysTick Timer to Assert the SysTick Exception Request */
		SET_BIT(SYSTICK->SYST_CSR, SYSTICK_CSR_ENABLE_MSK);
	}
	else{/* Nothing */}
}

void SysTick_PeriodicInterval(uint32_t SysTick_Ticks, ptrFunction *CallBack){
	if(CallBack != NULL){
		/* Set Reload Register to SysTick Ticks */
		SYSTICK->SYST_RVR = SysTick_Ticks; 										/* 1 000 000 for 1Sec */
		/* Copy the User CallBack to a Local Function */
		SysTick_CallBack = CallBack;
		/* Set SysTick Timer to the Periodic Interval Mode */
		SysTick_Mode = SYSTICK_PERIODICINTERVAL;
		/* Enable SysTick IRQ NVIC Line */
		SET_BIT(SYSTICK->SYST_CSR, SYSTICK_CSR_TICKINT_MSK);
		/* Enable the SysTick Timer to Assert the SysTick Exception Request */
		SET_BIT(SYSTICK->SYST_CSR, SYSTICK_CSR_ENABLE_MSK);
		}
		else{/* Nothing */}
}

uint32_t SysTick_GetRemainingTicks(void){
	uint32_t RemainingTicks = 0;

	RemainingTicks = SYSTICK->SYST_CVR;

	return RemainingTicks;
}

void SysTick_Handler(void){
	if(SysTick_Mode == SYSTICK_SINGLEINTERVAL){
		/* Disable SysTick Counter */
		CLEAR_BIT(SYSTICK->SYST_CSR, SYSTICK_CSR_ENABLE_MSK);
		/* Reset the SysTick Reload Register */
		SYSTICK->SYST_RVR = 0;
		/* Reset the SysTick Counter Value */
		SYSTICK->SYST_CVR = 0;
		/* Disable SysTick IRQ */
		CLEAR_BIT(SYSTICK->SYST_CSR, SYSTICK_CSR_TICKINT_MSK);
	}

	if(SysTick_CallBack){
		SysTick_CallBack();
	}
	else{}
}
