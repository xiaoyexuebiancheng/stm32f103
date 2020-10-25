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
	
	//����LED��
	LED_G_GPIO_Config();
	SysTick_Delay_ms(300);
	LED_G(OFF);
	
	LED_R_GPIO_Config();
	SysTick_Delay_ms(300);
	LED_R(OFF);
	
	LED_B_GPIO_Config();
	SysTick_Delay_ms(300);
	LED_B(OFF);
		
	
//	//���ð�ť
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
	
//	 /* ���ڳ�ʼ�� */
//	USART_Config();
//	
//	printf("\r\n ����һ��I2C����(AT24C02)��д�������� \r\n");

//	/* I2C �����(AT24C02)ʼ�� */
//	I2C_EE_Init();
//	 	 
//  //EEPROM ��д����
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

		printf("eeprom ���ģ��i2c�������� \r\n");		
  
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

//	printf("д�������\n\r");
//    
//	for ( i=0; i<=255; i++ ) //��仺��
//  {   
//    I2c_Buf_Write[i] = i;

//    printf("0x%02X ", I2c_Buf_Write[i]);
//    if(i%16 == 15)    
//        printf("\n\r");    
//   }

//  //��I2c_Buf_Write��˳�����������д��EERPOM�� 
//	I2C_EE_BufferWrite( I2c_Buf_Write, EEP_Firstpage, 256);
//  
//  EEPROM_INFO("\n\rд�ɹ�\n\r");
//   
//   EEPROM_INFO("\n\r����������\n\r");
//  //��EEPROM��������˳�򱣳ֵ�I2c_Buf_Read��
//	I2C_EE_BufferRead(I2c_Buf_Read, EEP_Firstpage, 256); 
//   
//  //��I2c_Buf_Read�е�����ͨ�����ڴ�ӡ
//	for (i=0; i<256; i++)
//	{	
//		if(I2c_Buf_Read[i] != I2c_Buf_Write[i])
//		{
//			EEPROM_ERROR("0x%02X ", I2c_Buf_Read[i]);
//			EEPROM_ERROR("����:I2C EEPROMд������������ݲ�һ��\n\r");
//			return 0;
//		}
//    printf("0x%02X ", I2c_Buf_Read[i]);
//    if(i%16 == 15)    
//        printf("\n\r");
//    
//	}
//  EEPROM_INFO("I2C(AT24C02)��д���Գɹ�\n\r");
//  
//  return 1;
//}


