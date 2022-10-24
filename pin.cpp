/*
 * pin.cpp
 *
 *  Created on: 19 oct 2022
 *      Author: Pavel Starovoitov
 */

#include <pin.h>

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
    LL_GPIO_Init(_port->getPort(), GPIO_InitStruct);
  }

  void pin::set (void) const
  {
    LL_GPIO_SetOutputPin (_port->getPort (), _pin);
  }

  void pin::reset (void) const
  {
    LL_GPIO_ResetOutputPin (_port->getPort (), _pin);
  }

  gpio::state  pin::get (void)
  {
    return LOW;
  }

#ifdef STREAM_H_
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
#endif
} /* namespace gpio */


