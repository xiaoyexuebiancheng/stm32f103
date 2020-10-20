#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_rccclkconfig.h"
#include "bsp_exti.h"
#include "bsp_systick.h"
#include "bsp_usart.h"
#include "bsp_dma_mtm.h"

extern const uint32_t aSRC_Const_Buffer[BUFFER_SIZE];
extern uint32_t aDST_Buffer[BUFFER_SIZE];

//void Delay(uint32_t count)
//{
//	for(;count!=0;count--);
//}

int main()
{	
//	uint8_t ch;
	//≈‰÷√LEDµ∆
	uint8_t status =0;
	
	LED_G_GPIO_Config();
	SysTick_Delay_ms(300);
	LED_G(OFF);
	
	LED_R_GPIO_Config();
	SysTick_Delay_ms(300);
	LED_R(OFF);
	
	LED_B_GPIO_Config();
	SysTick_Delay_ms(300);
	LED_B(OFF);
		
	
//	//≈‰÷√∞¥≈•
//	KEY1_GPIO_Config();
//	
//	while(1)
//	{
//		if(Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) ==KEY_ON)
//			LED_G_TOGGLE;
//	}
	
//	HSE_SetSysClk(RCC_PLLMul_9);
//	
//	while(1)
//	{
//		LED_G(OFF);
//		Delay(0xfffff);
//		
//		LED_G(ON);
//		Delay(0xfffff);
//	}
//	EXTI_Key_Config();


//	while(1)
//	{
//		LED_G(OFF);
//		SysTick_Delay_ms(1000);
//		LED_G(ON);
//		SysTick_Delay_ms(1000);	
//	}

//		USART_Config();
//		printf("test start:\n");
//		while(1)
//		{
//			ch = getchar();
//			printf("input: %c\n",ch);
//			
//			switch(ch)
//			{
//				case '1':	LED_G(ON);
//					break;
//				case '2':	LED_G(OFF);
//					break;
//				case '3':
//					break;
//				case '4':
//					break;
//				case '5':
//					break;
//				case '6':
//					break;
//				default:	printf("no this command");
//					break;
//			}
//		}

		MtM_DMA_Config();
		status =  Buffercmp(aSRC_Const_Buffer, aDST_Buffer, BUFFER_SIZE);
		if(status ==0)
		{
			LED_R(ON);
		}
		else
		{
			LED_G(ON);
		}
		
}



