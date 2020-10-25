#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_rccclkconfig.h"
#include "bsp_exti.h"
#include "bsp_systick.h"
#include "bsp_usart.h"
#include "bsp_dma_mtm.h"
#include "bsp_dma_mtp.h"
#include "./i2c/bsp_i2c_ee.h"
#include "./i2c/bsp_i2c_gpio.h"


#define  EEP_Firstpage      0x00
uint8_t I2c_Buf_Write[256];
uint8_t I2c_Buf_Read[256];
uint8_t I2C_Test(void);

//void Delay(uint32_t count)
//{
//	for(;count!=0;count--);
//}

int main()
{	
//	uint8_t ch;
//	uint16_t i=0;
//	extern uint8_t SendBuff[SENDBUFF_SIZE];
//	uint8_t status =0;
	
	//配置LED灯
	LED_G_GPIO_Config();
	SysTick_Delay_ms(300);
	LED_G(OFF);
	
	LED_R_GPIO_Config();
	SysTick_Delay_ms(300);
	LED_R(OFF);
	
	LED_B_GPIO_Config();
	SysTick_Delay_ms(300);
	LED_B(OFF);
		
	
//	//配置按钮
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
//	for(i=0;i<SENDBUFF_SIZE;i++)
//	{
//		SendBuff[i] = 'p';
//	}
//	
//	USART_Config();
//	USARTx_DMA_Config();
//	USART_DMACmd(DEBUG_USARTx, USART_DMAReq_Tx, ENABLE);
//	
//	LED_G(ON);
	
//	 /* 串口初始化 */
//	USART_Config();
//	
//	printf("\r\n 这是一个I2C外设(AT24C02)读写测试例程 \r\n");

//	/* I2C 外设初(AT24C02)始化 */
//	I2C_EE_Init();
//	 	 
//  //EEPROM 读写测试
//	if(I2C_Test() ==1)
//	{
//			LED_G(ON);
//	}
//	else
//	{
//			LED_R(ON);
//	}
//  
//  while (1)
//  {      
//  }
			USART_Config();

		printf("eeprom 软件模拟i2c测试例程 \r\n");		
  
    if(ee_Test() == 1)
  	{
			LED_G(ON);
    }
    else
    {
        LED_R(ON);
    }
    while(1);
}


//uint8_t I2C_Test(void)
//{
//	uint16_t i;

//	printf("写入的数据\n\r");
//    
//	for ( i=0; i<=255; i++ ) //填充缓冲
//  {   
//    I2c_Buf_Write[i] = i;

//    printf("0x%02X ", I2c_Buf_Write[i]);
//    if(i%16 == 15)    
//        printf("\n\r");    
//   }

//  //将I2c_Buf_Write中顺序递增的数据写入EERPOM中 
//	I2C_EE_BufferWrite( I2c_Buf_Write, EEP_Firstpage, 256);
//  
//  EEPROM_INFO("\n\r写成功\n\r");
//   
//   EEPROM_INFO("\n\r读出的数据\n\r");
//  //将EEPROM读出数据顺序保持到I2c_Buf_Read中
//	I2C_EE_BufferRead(I2c_Buf_Read, EEP_Firstpage, 256); 
//   
//  //将I2c_Buf_Read中的数据通过串口打印
//	for (i=0; i<256; i++)
//	{	
//		if(I2c_Buf_Read[i] != I2c_Buf_Write[i])
//		{
//			EEPROM_ERROR("0x%02X ", I2c_Buf_Read[i]);
//			EEPROM_ERROR("错误:I2C EEPROM写入与读出的数据不一致\n\r");
//			return 0;
//		}
//    printf("0x%02X ", I2c_Buf_Read[i]);
//    if(i%16 == 15)    
//        printf("\n\r");
//    
//	}
//  EEPROM_INFO("I2C(AT24C02)读写测试成功\n\r");
//  
//  return 1;
//}


