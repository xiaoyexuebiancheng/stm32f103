


#define PERIPH_BASE				((unsigned int)0x40000000)
#define APB1_PERIPH_BASE	PERIPH_BASE
#define APB2_PERIPH_BASE	(PERIPH_BASE+0x10000)
#define AHB_PERIPH_BASE		(PERIPH_BASE+0x20000)

#define RCC_BASE			(AHB_PERIPH_BASE+0x1000)
#define GPIOB_BASE		(APB2_PERIPH_BASE+0x0C00)

#define RCC_APB2ENR		*(unsigned int*)(RCC_BASE+0x18)
	
#define GPIOB_CRL			*(unsigned int*)(GPIOB_BASE+0x00)
#define GPIOB_CRH			*(unsigned int*)(GPIOB_BASE+0x04)
#define GPIOB_ODR			*(unsigned int*)(GPIOB_BASE+0x0C)

