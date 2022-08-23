#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <stdint.h>


#define RT	0
#define FT	1
#define RFT	3

#define A	0
#define B	1
#define C	2
#define D	3
#define E	4
#define F	5
#define G	6

#define  ENABLE 	1
#define  DISABLE    0


#define EXTI_BASE_ADD   0x40010400U
#define AFIO_BASE_ADD	0x40010000U
#define IPR_BASE_ADD	0xE000E400U


#define NVIC_ISER0_ADD	0xE000E100U
#define NVIC_ISER1_ADD	0xE000E104U

#define NVIC_ICER0_ADD	0XE000E180U
#define NVIC_ICER1_ADD	0XE000E184U

#define EXTI  ((EXTI_Regdef*)EXTI_BASE_ADD)
#define AFIO  ((AFIO_Regdef*)AFIO_BASE_ADD)
#define IPR   ((NVIC_IPR_Regdef*)IPR_BASE_ADD)

#define ISER0  (*(volatile uint32_t*)NVIC_ISER0_ADD)
#define ISER1  (*(volatile uint32_t*)NVIC_ISER1_ADD)
#define ICER0  (*(volatile uint32_t*)NVIC_ICER0_ADD)
#define ICER1  (*(volatile uint32_t*)NVIC_ICER1_ADD)


/* AFIO CLOCK ENABLE */
#define RCC_BASE_ADD			0x40021000U
#define APB2_CLK_OFFSET 		0x18U
#define CLK_REG					*(volatile uint32_t*)(RCC_BASE_ADD+APB2_CLK_OFFSET)
#define AFIO_CLK_ENABLE()		(CLK_REG |= (1<<0))


typedef struct
{
	volatile uint32_t	 IMR;
	volatile uint32_t	 EMR;
	volatile uint32_t 	 RTSR;
	volatile uint32_t	 FTSR;
	volatile uint32_t 	 SWIER;
	volatile uint32_t 	 PR;
}EXTI_Regdef;


typedef struct
{
	volatile uint32_t	EVCR;
	volatile uint32_t	MAPR;
	volatile uint32_t	EXTICRX[4];
	volatile uint32_t	MAPR2;
}AFIO_Regdef;


typedef struct
{
	volatile uint32_t	IPRx[60];

}NVIC_IPR_Regdef;


/* ----------------------Function prototype----------------------- */

/* Micro-controller side configuration APIs */

void GPIO_Interrupt_Set(uint8_t PORTx,uint8_t pin_number,uint8_t RT_FT_RFT);

/* Processor side configuration APIs */
void GPIO_Interrupt_Enable(uint8_t IRQ_number,uint8_t EN_DI);

/* Processor side configuration APIs */
void GPIO_Interrupt_Priority(uint8_t IRQ_number,uint32_t Priority);

/* Micro-controller side configuration APIs */
void GPIO_Interrupt_Handling(uint8_t pin_number);





#endif /* INTERRUPT_H_ */
