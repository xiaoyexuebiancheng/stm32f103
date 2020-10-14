#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"


int main()
{	
	//≈‰÷√LEDµ∆
	LED_G_GPIO_Config();
//	LED_R_GPIO_Config();
//	LED_B_GPIO_Config();
	
	//≈‰÷√∞¥≈•
	KEY1_GPIO_Config();
	
	while(1)
	{
		if(Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) ==KEY_ON)
			LED_G_TOGGLE;
	}
	
}

