/* NOte :- In this Micro-controller(STM32f1038)
 *		GPT :- 			 TIM2,TIM3,TIM4
 * 		Advance Timer :- TIM1 is a advance Timer.
 */

/* Include section */
#include "GPT.h"



/* ------------------------Function Implementation-------------------------- */


/* This is a Timer delay using Polling method */
void Delay(GPT_Regdef *TIMx,uint16_t ms)
{
	GPT_CLK_Enable(TIMx);
	TIMx->PSC = 8000-1;	// 8MHz/8000=1000Hz & Time Period = 1ms(That is One tick)
	TIMx->ARR = ms-1;	// Auto reload register will take value for time
	GPT_TIM_Enable(TIMx);

	// It will wait for particular time
	while(!(GPT_Flag_Read(TIMx,UIF)));
	GPT_Flag_Clear(TIMx, UIF);

	TIMx->PSC = 0;
	TIMx->ARR = 0;
}


/* This function Enable the Clock for TIMx */
void GPT_CLK_Enable(GPT_Regdef *TIMx)
{
	if(TIMx==TIM2)
	{
		TIM2_CLK_ENABLE();
	}
	else if(TIMx==TIM3)
	{
		TIM3_CLK_ENABLE();
	}
	else if(TIMx==TIM4)
	{
		TIM4_CLK_ENABLE();
	}

}


/* This function Enable the TIMx Peripheral */
void GPT_TIM_Enable(GPT_Regdef *TIMx)
{

	TIMx->CR1 |= (1<<0);

}


/* This function will read Flag of SR register */
uint8_t GPT_Flag_Read(GPT_Regdef *TIMx,uint8_t flag)
{
	uint8_t value;
	value=(uint8_t)((TIMx->SR >> flag) & 0X00000001);
	return value;
	value=0;
}


/* This function will clear Flag of SR register */
void GPT_Flag_Clear(GPT_Regdef *TIMx,uint8_t flag)
{
	TIMx->SR &=~(1<<flag);
}


/* To Set the Interrupt of particular Bit */
void GPT_IT_Enable(GPT_Regdef *TIMx,uint8_t IRQ_number, uint8_t Bit)
{

	if(IRQ_number <=31)
	 {
		ISER0 |= (1<<IRQ_number);
	 }
	else if(IRQ_number >=32 && IRQ_number <=61)
	 {
			ISER1 |= (1<<IRQ_number%32);
	 }
	TIMx->DIER |= (1<< Bit);
}



void GPT_IT_Handler(GPT_Regdef *TIMx,uint8_t Bit)
{
	if(GPT_Flag_Read(TIMx, Bit))
	{

		GPT_Flag_Clear(TIMx, Bit);

	}
}














/*------------------------End of File ---------------------------*/
