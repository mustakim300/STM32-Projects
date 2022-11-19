/* Include section */
#include "GPIO.h"
#include  "GPT.h"

#define LED1 0


int main(void)
{
	GPIO_CLK(GPIOA, ENABLE);
    GPIO_MODE(GPIOA, OUTPUT,AF_PUSH_PULL, LED1);

    while(1)
    {
    	for(int i=0;i<=100; i=i+20)
    	{

    	 	PWM(TIM2,CH1,1, i);
    	 	delay(1000);

    	}

    }

}

