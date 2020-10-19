#ifndef __RCCCLKCONFIG_H
#define __RCCCLKCONFIG_H

#include "stm32f10x.h"

#define MCO_GPIO_PIN	GPIO_Pin_8
#define MCO_GPIO_PORT	GPIOA
#define MCO_GPIO_CLK	RCC_APB2Periph_GPIOA

void HSE_SetSysClk(uint32_t RCC_PLLMul_x);
void MCO_GPIO_Config(void);

#endif /*__RCCCLKCONFIG_H*/
