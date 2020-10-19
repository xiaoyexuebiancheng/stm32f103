#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_rccclkconfig.h"

void Delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main()
{	
	//≈‰÷√LEDµ∆
	LED_G_GPIO_Config();
//	LED_R_GPIO_Config();
//	LED_B_GPIO_Config();
	
//	//≈‰÷√∞¥≈•
//	KEY1_GPIO_Config();
//	
//	while(1)
//	{
//		if(Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) ==KEY_ON)
//			LED_G_TOGGLE;
//	}
	HSE_SetSysClk(RCC_PLLMul_9);
	
	MCO_GPIO_Config();
	RCC_MCOConfig(RCC_MCO_SYSCLK);
	while(1)
	{
		LED_G(OFF);
		Delay(0xfffff);
		
		LED_G(ON);
		Delay(0xfffff);
	}
	
}

