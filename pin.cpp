/*
 * pin.cpp
 *
 *  Created on: 19 oct 2022
 *      Author: Pavel Starovoitov
 */

#include "pin.h"

namespace gpio
{
  pin::pin (gpio::port *const port, uint32_t pin) : _port(port), _pin(pin)
  {
    _port->init();
  }

  pin::~pin ()
  {
  }
  void pin::init(LL_GPIO_InitTypeDef *GPIO_InitStruct)
  {
    GPIO_InitStruct->Pin = _pin;
#ifdef USE_FULL_LL_DRIVER
    LL_GPIO_Init(_port->getPort(), GPIO_InitStruct);
#elif USE_HAL_DRIVER
    GPIO_Init(_port->getPort(), GPIO_InitStruct);
#else
  #error Need to implement the init method
#endif
  }

  void pin::set (void) const
  {
#ifdef USE_FULL_LL_DRIVER
#elif USE_HAL_DRIVER
    HAL_GPIO_WritePin(_port->getPort (), _pin, GPIO_PIN_SET);
#else
  #error Need to implement the init method
#endif
  }

  void pin::reset (void) const
  {
#ifdef USE_FULL_LL_DRIVER
#elif USE_HAL_DRIVER
    HAL_GPIO_WritePin(_port->getPort (), _pin, GPIO_PIN_RESET);
#else
  #error Need to implement the init method
#endif
  }

  gpio::state  pin::get (void)
  {
#ifdef USE_FULL_LL_DRIVER
    return LOW;
#elif USE_HAL_DRIVER
    GPIO_PinState state = HAL_GPIO_ReadPin (_port->getPort (), _pin);
    return state == GPIO_PIN_SET ? gpio::state::HIGH, gpio::state::LOW;
#else
  #error Need to implement the init method
#endif
  }

//#if defined(USE_STREAM)
  com::ostream& operator << (com::ostream& out, gpio::pin& pin)
  {
    int i = (int)pin.getpin();
    int n = 0;

    while(i)
    {
      i >>= 1;
      n++;
    }

    n--;
    out << (*pin.getport()) << "." << n;
    return out;
  }
//#endif

  bool
  pin::operator != (gpio::pin &pin)
  {
    return !((pin._pin == _pin) && (pin._port == _port));
  }

} /* namespace gpio */


