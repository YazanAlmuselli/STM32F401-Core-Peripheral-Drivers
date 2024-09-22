/**
 ******************************************************************************
 * @file           : CortexM4_Core_NVIC.c
 * @author         : Yazan Abd-Almajeed
 * @brief          : Implementation of Functions
 ******************************************************************************
 */

#include "CortexM4/CortexM4_Core_NVIC.h"

void NVIC_EnableIRQ(IRQn_Type IRQn){
	if((uint32_t)IRQn >= 0){
		NVIC->ISER[((uint32_t)IRQn) >> 5] = (1UL << (((uint32_t)IRQn) & 0x1F));
	}
}

void NVIC_DisableIRQ(IRQn_Type IRQn){
	if((uint32_t)IRQn >= 0){
		NVIC->ICER[((uint32_t)IRQn) >> 5] = (1UL << (((uint32_t)IRQn) & 0x1F));
	}
}

void NVIC_SetPendingIRQ(IRQn_Type IRQn){
	if((uint32_t)IRQn >= 0){
		NVIC->ISPR[((uint32_t)IRQn) >> 5] = (1UL << (((uint32_t)IRQn) & 0x1F));
	}
}

void NVIC_ClearPendingIRQ(IRQn_Type IRQn){
	if((uint32_t)IRQn >= 0){
		NVIC->ICPR[((uint32_t)IRQn) >> 5] = (1UL << (((uint32_t)IRQn) & 0x1F));
	}
}

uint32_t NVIC_GetActive(IRQn_Type IRQn){
	return ((NVIC->ICPR[((uint32_t)IRQn) >> 5]) & (1UL << (((uint32_t)IRQn) & 0x1F))) != ((uint32_t)0) ? 1UL : 0UL;
}

void NVIC_SetPriority(IRQn_Type IRQn, uint32_t PriorityGroup){
	if((uint32_t)IRQn >= 0){
		NVIC->IP[(uint32_t)IRQn] = (uint8_t)((PriorityGroup << (8 - NVIC_PRIO_BITS)) & (uint32_t)0xFF);
	}
}

uint32_t NVIC_GetPriority(IRQn_Type IRQn){
	if((uint32_t)IRQn >= 0){
		return ((NVIC->IP[(uint32_t)IRQn]) >> (8 - NVIC_PRIO_BITS));
	}
}
