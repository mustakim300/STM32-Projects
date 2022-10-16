#include <stdint.h>
#include <stdio.h>

/* Include section */
#include "GPIO.h"
#include "GPT.h"


/* LEDs PINs */
#define  LED1	5
#define  LED2	0

int main(void)
{
	GPIO_CLK(GPIOA,ENABLE);
	GPIO_MODE(GPIOA,OUTPUT,PUSH_PULL,LED1);
	GPIO_MODE(GPIOA,OUTPUT,PUSH_PULL,LED2);

	GPT_CLK_Enable(TIM2);
	TIM2->PSC =8000;
	TIM2->ARR =100;

	GPT_CLK_Enable(TIM3);
	TIM3->PSC =8000;
	TIM3->ARR =500;


	GPT_IT_Enable(TIM2,28, UIE);
	GPT_TIM_Enable(TIM2);

	GPT_IT_Enable(TIM3,29, UIE);
	GPT_TIM_Enable(TIM3);

}

void TIM2_IRQHandler (void)
{
	GPT_IT_Handler(TIM2, UIE);

	GPIO_TOGGLE(GPIOA, LED1);
}

void TIM3_IRQHandler (void)
{
	GPT_IT_Handler(TIM3, UIE);

	GPIO_TOGGLE(GPIOA, LED2);
}


