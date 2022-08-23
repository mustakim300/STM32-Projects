#include "GPIO_Interrupt.h"

void GPIO_Interrupt_Set(uint8_t PORTx,uint8_t pin_number,uint8_t RT_FT_RFT)
{
	AFIO_CLK_ENABLE();    /* Alternate function IO CloclK enable */

	if(RT_FT_RFT==RT)
	{
		EXTI->RTSR |= (1<<pin_number);
		EXTI->FTSR &=~(1<<pin_number);
	}
	else if(RT_FT_RFT==FT)
	{
		EXTI->FTSR |= (1<<pin_number);
		EXTI->RTSR &=~(1<<pin_number);
	}
	else if(RT_FT_RFT==RFT)
	{
		EXTI->FTSR |= (1<<pin_number);
		EXTI->RTSR |= (1<<pin_number);
	}

	/*                           */
	uint8_t CRx = pin_number/4;
	uint8_t shift = (pin_number%4)*4;
	AFIO->EXTICRX[CRx] |= (PORTx << shift);

	EXTI->IMR |= (1 << pin_number);

}

void GPIO_Interrupt_Enable(uint8_t IRQ_number,uint8_t EN_DI)
{
	if(EN_DI==ENABLE)
	{
		if(IRQ_number <=31)
		{

			ISER0 |= (1<<IRQ_number);

		}
		else if(IRQ_number >=32 && IRQ_number <=61)
		{

			ISER1 |= (1<<IRQ_number%32);

		}
	}
	else
	{
		if(IRQ_number <=31)
		{
			ICER0 |= (1<<IRQ_number);
		}
		else if(IRQ_number >=32 && IRQ_number <=61)
		{
			ICER1 |= (1<<IRQ_number);
		}

	}

}


void GPIO_Interrupt_Priority(uint8_t IRQ_number,uint32_t Priority)
 {
	uint8_t iprx	= IRQ_number/4;
	uint8_t section = IRQ_number%4;
	uint8_t shift   = (8*section)+4;
	IPR->IPRx[iprx] |= (Priority << shift);
}

void GPIO_Interrupt_Handling(uint8_t pin_number)
 {
	if(EXTI->PR & (1<< pin_number))
	{
		EXTI->PR |= (1<< pin_number);
	}
}


