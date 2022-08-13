#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>
#include "delay.h"

#define  ENABLE 	1
#define  DISABLE    0

#define RCC_BASE_ADD		0x40021000U
#define APB2_CLK_OFFSET 	0x18U
#define CLK_REG				*(volatile uint32_t*)(RCC_BASE_ADD+APB2_CLK_OFFSET)

/* GPIO BASE ADDRESS */
#define GPIOA_BASE_ADD		0x40010800U
#define GPIOB_BASE_ADD		0x40010C00U
#define GPIOC_BASE_ADD		0x40011000U
#define GPIOD_BASE_ADD		0x40011400U
#define GPIOE_BASE_ADD		0x40011800U
#define GPIOF_BASE_ADD		0x40011C00U
#define GPIOG_BASE_ADD		0x40012000U


typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_Regdef;

/* GPIO A-G*/
#define GPIOA     ((GPIO_Regdef*)GPIOA_BASE_ADD)
#define GPIOB     ((GPIO_Regdef*)GPIOB_BASE_ADD)
#define GPIOC     ((GPIO_Regdef*)GPIOC_BASE_ADD)
#define GPIOD     ((GPIO_Regdef*)GPIOD_BASE_ADD)
#define GPIOE     ((GPIO_Regdef*)GPIOE_BASE_ADD)
#define GPIOF     ((GPIO_Regdef*)GPIOF_BASE_ADD)
#define GPIOG     ((GPIO_Regdef*)GPIOG_BASE_ADD)


/* GPIO CLOCK ENABLE */
#define AFIO_CLK_ENABLE()		(CLK_REG |= (1<<0))

/* GPIO CLOCK ENABLE */
#define GPIOA_CLK_ENABLE()		(CLK_REG |= (1<<2))
#define GPIOB_CLK_ENABLE()		(CLK_REG |= (1<<3))
#define GPIOC_CLK_ENABLE()	    (CLK_REG |= (1<<4))
#define GPIOD_CLK_ENABLE()		(CLK_REG |= (1<<5))
#define GPIOE_CLK_ENABLE()		(CLK_REG |= (1<<6))
#define GPIOF_CLK_ENABLE()		(CLK_REG |= (1<<7))
#define GPIOG_CLK_ENABLE()		(CLK_REG |= (1<<8))

/* GPIO CLOCK DISABLE */
#define GPIOA_CLK_DISABLE()		(CLK_REG &= ~(1<<2))
#define GPIOB_CLK_DISABLE()		(CLK_REG &= ~(1<<3))
#define GPIOC_CLK_DISABLE()	    (CLK_REG &= ~(1<<4))
#define GPIOD_CLK_DISABLE()		(CLK_REG &= ~(1<<5))
#define GPIOE_CLK_DISABLE()		(CLK_REG &= ~(1<<6))
#define GPIOF_CLK_DISABLE()		(CLK_REG &= ~(1<<7))
#define GPIOG_CLK_DISABLE()		(CLK_REG &= ~(1<<8))


/* GPIO STATE*/
#define LOW					0
#define HIGH	    		1

/* GPIO MODE*/
#define INPUT				0
#define OUTPUT				1

/* GPIO MODE CONFIGURATION FOR OUTPUT*/
#define PUSH_PULL			0
#define OPEN_DRAIN			1
#define AF_PUSH_PULL		2
#define AF_OPEN_DRAIN		3

/* GPIO MODE CONFIGURATION FOR INPUT*/
#define ANLOG				0
#define FLOAT				1
#define PULL_UP_DOWN		2


/************************************************
 *@fn					- GPIO_CLK
 *@brief				-
 *@param[in]			-
 *@param[in]			-
 *@return				-
 *@note
 *
 */
void GPIO_CLK(GPIO_Regdef *GPIOx,uint8_t EN_DI);


/** \brief Input or Output Mode
 *\param Port
 *\param Mode
 *\param Pin_Number
 *\return None
 */
void GPIO_MODE(GPIO_Regdef *GPIOx,uint8_t mode,uint8_t config,uint8_t pin_number);


/** \brief GPIO State HIGH/LOW
 *\param Port
 *\param State
 *\param Pin_Number
 *\return None
 */
void GPIO_WRITE(GPIO_Regdef *GPIOx,uint8_t state,uint8_t pin_number);


/** \brief GPIO TOGGLE
 *\param Port
 *\param Pin_Number
 *\return None
 */
void GPIO_TOGGLE(GPIO_Regdef *GPIOx,uint8_t pin_number);


/** \brief GPIO Read
 *\param Port
 *\param Pin_Number
 *\return Pin Value
 */
uint8_t GPIO_READ(GPIO_Regdef *GPIOx,uint8_t pin_number);





#endif //GPIO_H_
