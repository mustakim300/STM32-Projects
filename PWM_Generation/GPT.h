/* NOte :- In this Micro-controller(STM32f1038)
 *		GPT :- 			 TIM2,TIM3,TIM4
 * 		Advance Timer :- TIM1 is a advance Timer.
 */

#ifndef GPT_H_
#define GPT_H_

/*Include Section */
#include <stdint.h>
#include <String.h>
#include <stdio.h>


/* Base Address Section */
#define TIM2_BASE_ADD		0x40000000U
#define TIM3_BASE_ADD		0x40000400U
#define TIM4_BASE_ADD		0x40000800U

#define NVIC_ISER0_ADD		0xE000E100U
#define NVIC_ISER1_ADD		0xE000E104U


/* Other Register Section */
#define TIM_CLK_REG		*(volatile uint32_t*)(0x4002101C)
#define ISER0  			(*(volatile uint32_t*)NVIC_ISER0_ADD)
#define ISER1  			(*(volatile uint32_t*)NVIC_ISER1_ADD)


/* Enable&Disable Macro Section */
#define TIM2_CLK_ENABLE()		TIM_CLK_REG	|= (1<<0)
#define TIM3_CLK_ENABLE()		TIM_CLK_REG	|= (1<<1)
#define TIM4_CLK_ENABLE()		TIM_CLK_REG	|= (1<<2)



/*--- Macros Section for PWM  --- */
#define CH1	1
#define CH2	2
#define CH3	3
#define CH4	4
#define TIM_PSC   1
#define TIMER_FREQUENCY 8

/* BaseTimers Register Structure */
typedef struct
{
	volatile uint32_t	CR1;
	volatile uint32_t	CR2;
	volatile uint32_t	SMCR;
	volatile uint32_t	DIER;
	volatile uint32_t	SR;
	volatile uint32_t	EGR;
	volatile uint32_t	CCMR1_InOut;
	volatile uint32_t	CCMR2_InOut;
	volatile uint32_t	CCER;
	volatile uint32_t	CNT;
	volatile uint32_t	PSC;
	volatile uint32_t	ARR;
	volatile uint32_t	Reserved1;
	volatile uint32_t	CCR1;
	volatile uint32_t	CCR2;
	volatile uint32_t	CCR3;
	volatile uint32_t	CCR4;
	volatile uint32_t	Reserved2;
	volatile uint32_t	DCR;
	volatile uint32_t	DMAR;
} GPT_Regdef;

#define TIM2	((GPT_Regdef*)TIM2_BASE_ADD)
#define TIM3	((GPT_Regdef*)TIM3_BASE_ADD)
#define TIM4	((GPT_Regdef*)TIM4_BASE_ADD)



/*  TIMx_DIER (Interrupt enable register) Bits */
#define UIE			0
#define CC1IE		1
#define CC2IE		2
#define CC3IE		3
#define CC4IE		4
#define TIE			6
#define UDE			8
#define CC1DE		9
#define CC2DE		10
#define CC3DE		11
#define CC4DE		12
#define	TDE			14


/* TIMx_SR (Status register) Flags */
#define UIF			0
#define CC1IF		1
#define CC2IF		2
#define CC3IF		3
#define CC4IF		4
#define TIF			6
#define CC1OF		9
#define CC2OF		10
#define CC3OF		11
#define CC4OF		12


/* --------------------------Function prototype--------------------------- */

void Delay_With_Timer(GPT_Regdef *TIMx,uint16_t ms);

void Delay_With_Timer_IT(GPT_Regdef *TIMx,uint16_t ms);

void GPT_CLK_Enable(GPT_Regdef *TIMx);

void GPT_TIM_Enable(GPT_Regdef *TIMx);

uint8_t GPT_Flag_Read(GPT_Regdef *TIMx,uint8_t flag);

void GPT_Flag_Clear(GPT_Regdef *TIMx,uint8_t flag);

void GPT_IT_Clear(GPT_Regdef *TIMx,uint8_t Bit);

void GPT_IT_Enable(GPT_Regdef *TIMx,uint8_t IRQ_number, uint8_t Bit);

void GPT_IT_Handler(GPT_Regdef *TIMx,uint8_t Bit);

void PWM(GPT_Regdef *TIMx,uint8_t Channel, uint32_t Frequency, uint32_t Duty_Cycle);




#endif /* GPT_H_ */
/*------------------------End of File ---------------------------*/
