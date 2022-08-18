#include <stdint.h>
#include <String.h>


/* Include section */
#include "GPIO.h"
#include "delay.h"


#define LED			0
#define BUTTON		15

int main(void)
{

	// Enable Clock PORTB
	GPIO_CLK(GPIOB, ENABLE);
	// Set PORT-B0 as Output
	GPIO_MODE(GPIOB, OUTPUT, PUSH_PULL, LED);
	// Set PORT-B15 as Input
	GPIO_MODE(GPIOB, INPUT, PULL_UP_DOWN, BUTTON);


while(1)
{
	// Read PORT-B15 value
	while((GPIO_READ(GPIOB, BUTTON)))

	{
		GPIO_WRITE(GPIOB, HIGH, LED);
		delay(1000);	// Delay of 1 second
		GPIO_WRITE(GPIOB, LOW, LED);
	}
}





}



