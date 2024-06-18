#include <exti.h>

#define GPIOCEN		(1U<<2)
#define SYSCFGEN      (1U<<14)


void pc13_exti_init(void)
{
	/*Disable global interrupt*/
	__disable_irq();
	/*Enable clock access to GPIOC*/
	RCC->AHB1ENR|=GPIOCEN;
	/*Set PC13 as input*/
	GPIOC->MODER&=~(1<<26);
	GPIOC->MODER&=~(1<<27);
	/*Enable clock access to SYSCFG*/
	RCC->APB2ENR|=SYSCFGEN;
	/*Select PORTC for EXTI13 */
	/*Vì có 4 thanh ghi này từ 1 đến 4 và thật ra là chỉ có 1 thanh ghi
	 * và nó được sắp xếp theo kiểu mảng nên ta có thê khai báo*/
	 SYSCFG->EXTICR[3]|=(1<<5);
	/*Unmask EXTI13*/
	EXTI->IMR|=(1<<13);
	/*Select falling edge trigger*/
	EXTI->FTSR|=(1<<13);
	/*Enable EXTI13 line in NVIC*/
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	//NVIC->IP[40]|=47<<4;
	/*Enable global interrupt*/
	__enable_irq();
}
