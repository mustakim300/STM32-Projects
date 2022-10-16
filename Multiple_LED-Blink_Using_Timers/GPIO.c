#include "GPIO.h"


void GPIO_CLK(GPIO_Regdef *GPIOx,uint8_t EN_DI)
{
	if(EN_DI==ENABLE)
	{
		if(GPIOx==GPIOA)
		{
		 GPIOA_CLK_ENABLE();
		}
		else if(GPIOx==GPIOB)
		{
		 GPIOB_CLK_ENABLE();
		}
		else if(GPIOx==GPIOC)
		{
		 GPIOC_CLK_ENABLE();
		}
		else if(GPIOx==GPIOD)
		{
		 GPIOD_CLK_ENABLE();
		}
		else if(GPIOx==GPIOE)
		{
	   	 GPIOE_CLK_ENABLE();
		}
		else if(GPIOx==GPIOF)
		{
		 GPIOF_CLK_ENABLE();
		}
		else if(GPIOx==GPIOG)
		{
		 GPIOG_CLK_ENABLE();
		}

	}
	else
	{
		if(GPIOx==GPIOA)
		{
		 GPIOA_CLK_DISABLE();
		}
		else if(GPIOx==GPIOB)
		{
		 GPIOB_CLK_DISABLE();
		}
		else if(GPIOx==GPIOC)
		{
		 GPIOC_CLK_DISABLE();
		}
		else if(GPIOx==GPIOD)
		{
		 GPIOD_CLK_DISABLE();
		}
		else if(GPIOx==GPIOE)
		{
	   	 GPIOE_CLK_DISABLE();
		}
		else if(GPIOx==GPIOF)
		{
		 GPIOF_CLK_DISABLE();
		}
		else if(GPIOx==GPIOG)
		{
		 GPIOG_CLK_DISABLE();
		}
	}

}


void GPIO_MODE(GPIO_Regdef *GPIOx,uint8_t mode,uint8_t config,uint8_t pin_number)
{
	AFIO_CLK_ENABLE();
	if(pin_number>=8)
	{
		int x=(pin_number-8)*4;

		/* for GPIOA-OUTPUT */
		if(mode==OUTPUT)
		 {
			GPIOx->CRH |= (0X3 <<x);          //FOR OUTPUT MODE (MODE BIT[11])

			GPIOx->CRH &=~(3 <<(x+2));
			GPIOx->CRH |=(config <<(x+2));    //FOR CONFIG (CNF BIT)
		 }
		/* for GPIOA-INPUT */
		else if(mode==INPUT)
		 {
			GPIOx->CRH &=~(0X3 <<x);		  //FOR INPUT MODE (MODE BIT[00])

			GPIOx->CRH &=~(3 <<(x+2));
			GPIOx->CRH |= (config <<(x+2));      //FOR CONFIG (CNF BIT)
		 }
		 x=0;
	 }
	 else
		{
		 int x=(pin_number*4);

		/* for GPIOA-OUTPUT */
		if(mode==OUTPUT)
		 {
			GPIOx->CRL |= (0X3 <<x);          //FOR OUTPUT MODE (MODE BIT[11])

			GPIOx->CRL &=~(3 <<(x+2));
			GPIOx->CRL |=(config <<(x+2));    //FOR CONFIG (CNF BIT)
		 }
		/* for GPIOA-INPUT */
		else if(mode==INPUT)
		 {
			GPIOx->CRL &=~(0X3 <<x);		  //FOR INPUT MODE (MODE BIT[00])

			GPIOx->CRL &=~(3 <<(x+2));
			GPIOx->CRL |= (config <<(x+2));   //FOR CONFIG (CNF BIT)
		 }
		 x=0;
     }
}


void GPIO_WRITE(GPIO_Regdef *GPIOx,uint8_t state,uint8_t pin_number)
{
	if(state==HIGH)
	 {
		GPIOx->ODR |= (1<<pin_number);
	 }
	else
	 {
		GPIOx->ODR &=~(1<<pin_number);
	 }
}

void GPIO_TOGGLE(GPIO_Regdef *GPIOx,uint8_t pin_number)
{
	GPIOx->ODR ^= (1<<pin_number);
}



uint8_t GPIO_READ(GPIO_Regdef *GPIOx,uint8_t pin_number)
{
	uint8_t value;
	value=(uint8_t)((GPIOx->IDR >> pin_number) & 0X00000001);
	return value;
	value=0;
}




