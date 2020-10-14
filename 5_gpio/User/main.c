#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"

#define GPIOB_ODR_Addr GPIOB_BASE+0X0C
#define PBout(n) *(unsigned int*)(( GPIOB_ODR_Addr & 0xF0000000)+0x02000000+(( GPIOB_ODR_Addr &0x00FFFFFF)<<5)+(n<<2))

int main()
{	
	int i;
	//ÅäÖÃLEDµÆ
	LED_G_GPIO_Config();
//	LED_R_GPIO_Config();
//	LED_B_GPIO_Config();
	
	
	//ÅäÖÃ°´Å¥
//	KEY1_GPIO_Config();
//	
//	while(1)
//	{
//		if(Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) ==KEY_ON)
//			LED_G_TOGGLE;
//	}
	while(1)
	{
		for(i = 0;i<2000000;i++);
		PBout(0) =0;
		for(i = 0;i<2000000;i++);
		PBout(0) =1;
		
	}
}

