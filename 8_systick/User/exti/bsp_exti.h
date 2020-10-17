#ifndef __BSP_EXTI_H
#define __BSP_EXTI_H

#include "stm32f10x.h"

#define KEY_INT_GPIO_PIN	GPIO_Pin_0
#define KEY_INT_GPIO_PORT		GPIOA
#define KEY_INT_GPIO_CLK		RCC_APB2Periph_GPIOA

static void EXTI_NVIC_Config(void);
void EXTI_Key_Config(void);

#endif /*__BSP_EXTI_H*/
