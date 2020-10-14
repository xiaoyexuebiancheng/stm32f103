#include "stm32f10x.h"

int main(void)
{
	//打开GPIOB端口时钟
	*(unsigned int * ) 0x40021018 |= ((1)<<3);
	//配置IO口为输出模式
	*(unsigned int * ) 0x40010C00 &= ~(0x0F<<(4*0));
	*(unsigned int * ) 0x40010C00 |= ((1)<<(4*0));
	//配置PB0的ODR
	*(unsigned int * ) 0x40010C0C &= ~(0x0F<<(0*4));	//ODR置零
	*(unsigned int * ) 0x40010C0C |= ((0)<<0);				//0开 1关

}

void SystemInit()
{
	
}