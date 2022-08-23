#include <stdint.h>
#include <String.h>

/* Include section */
#include "GPIO.h"
#include "delay.h"
#include "GPIO_Interrupt.h"


/* LED & Button PINs */
#define  LED		6	 	// A11
#define  BUTTON		15		// B15


int main(void)
{
	// Clock Enable for PORT A & B
	GPIO_CLK(GPIOB,ENABLE);
	GPIO_CLK(GPIOA,ENABLE);

	// Mode settings of Button & LED
	GPIO_MODE(GPIOB, INPUT, OPEN_DRAIN,BUTTON);
	GPIO_MODE(GPIOA, OUTPUT, PUSH_PULL,LED);

	// Interrupt setting at Button Pin
	GPIO_Interrupt_Set(B, BUTTON, RT);
	GPIO_Interrupt_Enable(40, ENABLE);

	while(1)
	{
		GPIO_WRITE(GPIOA, LOW,LED);
	}

}


/* This is ISR function for EXTI line 10-15(that is PIN 10-15) */
void EXTI15_10_IRQHandler(void)
{
	// For de-bounce purpose
	delay(50);

	//LED will off for 0.5 second when button will press.
	GPIO_WRITE(GPIOA,HIGH,LED);
	delay(1000);

	// Interrupt handling
	GPIO_Interrupt_Handling(BUTTON);

}



