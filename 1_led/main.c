#include "stm32f10x.h"

int main(void)
{
	//��GPIOB�˿�ʱ��
	*(unsigned int * ) 0x40021018 |= ((1)<<3);
	//����IO��Ϊ���ģʽ
	*(unsigned int * ) 0x40010C00 &= ~(0x0F<<(4*0));
	*(unsigned int * ) 0x40010C00 |= ((1)<<(4*0));
	//����PB0��ODR
	*(unsigned int * ) 0x40010C0C &= ~(0x0F<<(0*4));	//ODR����
	*(unsigned int * ) 0x40010C0C |= ((0)<<0);				//0�� 1��

}

void SystemInit()
{
	
}