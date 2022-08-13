#include <stdint.h>
#include <String.h>

/* Include section */
#include "delay.h"
#include "GPIO.h"


int main(void)

{
	GPIO_CLK(GPIOB,ENABLE);
	GPIO_MODE(GPIOB, OUTPUT, PUSH_PULL,0);

	while(1)
	{
		GPIO_WRITE(GPIOB, HIGH, 0);
		delay(500);
		GPIO_WRITE(GPIOB, LOW, 0);
		delay(500);
	}

}





