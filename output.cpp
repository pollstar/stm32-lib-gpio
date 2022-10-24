/*
 * output.cpp
 *
 *  Created on: 19 oct 2022
 *      Author: Pavel Starovoitov
 */

#include <output.h>

namespace gpio
{

  output::output (gpio::port *const port, const uint32_t pin, const uint32_t speed,
	  const uint32_t outputType, const uint32_t pull) : pin::pin(port, pin)
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

  output::~output ()
  {
  }

} /* namespace gpio */
