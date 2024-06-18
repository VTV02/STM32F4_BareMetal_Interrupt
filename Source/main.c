#include <stdio.h>
#include<stdint.h>
#include<stm32f411xe.h>
#include <uart.h>
#include <adc.h>
#include <systick.h>
#include <tim.h>
#include <exti.h>

#define GPIOAEN			(1U<<0)

void pc13_exti_init(void);
static void exti_callback(void);

int main(void)
{
	RCC->AHB1ENR|=(1U<<0);
	GPIOA->MODER|=(1U<<10);
	GPIOA->MODER&=~(1U<<11);

	pc13_exti_init();
	uart2_txrx_init();
	while(1)
	{


	}
}

void EXTI15_10_IRQHandler(void)
{
	if((EXTI->PR & LINE13)!=0)
	{
		/*Clear PR flag */
		EXTI->PR|=LINE13;
		exti_callback();
		/*Do something */
	}
}

static void exti_callback(void)
{
	write_string(17,"Button pressed...");

}

