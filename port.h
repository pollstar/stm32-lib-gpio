/*
 * portgpio.h
 *
 *  Created on: 19 oct 2022
 *      Author: Pavel Starovoitov
 */

#ifndef PORT_H_
#define PORT_H_

#ifdef USE_FULL_LL_DRIVER
#include "stm32f0xx_ll_gpio.h"
#include "stm32f0xx_ll_bus.h"
#elif USE_HAL_DRIVER
#include "stm32f0xx_hal_gpio.h"
#endif

#ifdef USE_STREAM
#include "stream.h"
#endif


namespace gpio
{
  /*
   *
   */
  class port
  {
  public:
    port(GPIO_TypeDef *GPIOx): _port(GPIOx){};
    void init(void) const;
    inline GPIO_TypeDef *getPort(void) const {return _port;};
  private:
    mutable GPIO_TypeDef *_port;
    mutable uint32_t _used = 0;

#ifdef USE_STREAM
    friend com::ostream& operator << (com::ostream& out, gpio::port& port);
#endif
  };

#ifdef GPIOA
  extern gpio::port *const gpioa;
#endif
#ifdef GPIOB
  extern gpio::port *const gpiob;
#endif
#ifdef GPIOC
  extern gpio::port *const gpioc;
#endif
#ifdef GPIOD
  extern gpio::port *const gpiod;
#endif
#ifdef GPIOE
  extern gpio::port *const gpioe;
#endif
#ifdef GPIOF
  extern gpio::port *const gpiof;
#endif
} /* namespace gpio */


#endif /* PORT_H_ */
