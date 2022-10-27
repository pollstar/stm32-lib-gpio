/*
 * output.cpp
 *
 *  Created on: 19 oct 2022
 *      Author: Pavel Starovoitov
 */

#include "output.h"

namespace gpio
{

  output::output (gpio::port *const port, const uint32_t pin, const uint32_t speed,
	  const uint32_t outputType, const uint32_t pull)
    : pin::pin(port, pin)
  {
    LL_GPIO_InitTypeDef GPIO_InitStruct = {
	Pin: _pin,
	Mode: LL_GPIO_MODE_OUTPUT,
	Speed: speed,
	OutputType: outputType,
	Pull: pull
    };

    init(&GPIO_InitStruct);

  }

void output::set (void) const
  {
#ifdef USE_FULL_LL_DRIVER
    LL_GPIO_SetOutputPin (_port->getPort (), _pin);
#elif USE_HAL_DRIVER
    pin::set();
#else
  #error Need to implement the init method
#endif
  }

void output::reset (void) const
  {
#ifdef USE_FULL_LL_DRIVER
    LL_GPIO_ResetOutputPin (_port->getPort (), _pin);
#elif USE_HAL_DRIVER
    pin::reset();
#else
  #error Need to implement the init method
#endif
  }

gpio::state output::get (void)
{
#ifdef USE_FULL_LL_DRIVER
  return  LL_GPIO_IsOutputPinSet(_port->getPort (), _pin) ? gpio::state::HIGH : gpio::state::LOW;
#elif USE_HAL_DRIVER
  GPIO_PinState state = HAL_GPIO_ReadPin (_port->getPort (), _pin);
  return state == GPIO_PIN_SET ? gpio::state.HIGH : gpio::state.LOW;
#else
#error Need to implement the init method
#endif
}

  output::~output ()
  {
  }

} /* namespace gpio */
