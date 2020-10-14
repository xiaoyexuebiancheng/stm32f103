#include "stm32f10x.h"
#include "bsp_led.h"


int main()
{
	int i = 0;
	
	LED_G_GPIO_Config();
	LED_R_GPIO_Config();
	LED_B_GPIO_Config();
	while(1)
	{
		for(i=0;i<2000000;i++);
		LED_G(OFF);
		LED_R(OFF);
		LED_B(OFF);
		for(i=0;i<2000000;i++);
		LED_G(ON);
		for(i=0;i<2000000;i++);
		LED_G(OFF);
		for(i=0;i<2000000;i++);
		LED_R(ON);
		for(i=0;i<2000000;i++);
		LED_R(OFF);
		for(i=0;i<2000000;i++);
		LED_B(ON);
		for(i=0;i<2000000;i++);
		LED_B(OFF);
		
		for(i=0;i<2000000;i++);
		LED_G(ON);
		LED_R(ON);
		for(i=0;i<2000000;i++);
		LED_G(OFF);
		LED_R(OFF);
		for(i=0;i<2000000;i++);
		LED_G(ON);
		LED_B(ON);
		for(i=0;i<2000000;i++);
		LED_G(OFF);
		LED_B(OFF);
		for(i=0;i<2000000;i++);
		LED_R(ON);
		LED_B(ON);
		for(i=0;i<2000000;i++);
		LED_R(OFF);
		LED_B(OFF);
		
		for(i=0;i<2000000;i++);
		LED_G(ON);
		LED_R(ON);
		LED_B(ON);
	}
}

