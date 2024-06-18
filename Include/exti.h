/*
 * exti.h
 *
 *  Created on: Jun 15, 2024
 *      Author: VOVAN
 */

#ifndef EXTI_H_
#define EXTI_H_
#include <stm32f411xe.h>
void pc13_exti_init(void);
#define LINE13 (1U<<13)

#endif /* EXTI_H_ */
