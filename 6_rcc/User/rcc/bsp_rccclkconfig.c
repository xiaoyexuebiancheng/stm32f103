#include "bsp_rccclkconfig.h"

void HSE_SetSysClk(uint32_t RCC_PLLMul_x)
{
	
	ErrorStatus HSEStatus;
	//RCC寄存器复位
	RCC_DeInit();
	//使能HSE
	RCC_HSEConfig(RCC_HSE_ON);
	
	HSEStatus = RCC_WaitForHSEStartUp();
	
	if(HSEStatus == SUCCESS)
	{
		//使能取指
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		FLASH_SetLatency(FLASH_Latency_2);
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK1Config(RCC_SYSCLK_Div2);
		RCC_PCLK2Config(RCC_SYSCLK_Div1);
		
		//配置 PLLCLK = HSE
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_x);
		
		//使能PLL
		RCC_PLLCmd(ENABLE);
		
		//等待PLL稳定
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
		
		//选择系统时钟
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while(RCC_GetSYSCLKSource() != 0x08);
			
	}
	else
	{	//HSE调用失败，失败代码
		
	}
}

void MCO_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(MCO_GPIO_CLK, ENABLE);

	GPIO_InitStruct.GPIO_Pin = MCO_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(MCO_GPIO_PORT,&GPIO_InitStruct);
}
