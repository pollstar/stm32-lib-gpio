/*
 * drivers_include.h
 *
 *  Created on: Dec 3, 2022
 *      Author: Pavel Starovoitov
 */

#ifndef GPIO_DRIVERS_INCLUDE_H_
#define GPIO_DRIVERS_INCLUDE_H_

#if defined (STM32H743xx) || defined (STM32H753xx)  || defined (STM32H750xx) || defined (STM32H742xx) || \
    defined (STM32H745xx) || defined (STM32H755xx)  || defined (STM32H747xx) || defined (STM32H757xx)
  #define STM32H7xx
  #if defined (STM32H743xx)
    #include "stm32h743xx.h"
  #endif
#endif

#if defined (USE_FULL_LL_DRIVER)
  #if defined (STM32H7xx)
    #include "stm32h7xx_ll_gpio.h"
    #include "stm32h7xx_ll_bus.h"
  #else
    #include "stm32f0xx_ll_gpio.h"
    #include "stm32f0xx_ll_bus.h"
  #endif
#elif defined (USE_HAL_DRIVER)
  #if defined (STM32H7xx)
    #include "stm32h7xx_hal_gpio.h"
  #else
    #include "stm32f0xx_hal_gpio.h"
  #endif
#endif




#endif /* GPIO_DRIVERS_INCLUDE_H_ */
