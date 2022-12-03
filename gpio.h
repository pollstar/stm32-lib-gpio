/*
 * gpio.h
 *
 *  Created on: 19 oct 2022
 *      Author: Pavel Starovoitov
 */

#ifndef GPIO_H_
#define GPIO_H_

#define CPP_LIB_STM32
#if defined (STM32F0xx)
  #include "stm32f0xx.h"
#elif defined (STM32H7xx)
  #include "stm32h7xx.h"
#endif

#include "output.h"

#endif /* GPIO_H_ */
