/*
 * output.cpp
 *
 *  Created on: 19 окт. 2022 г.
 *      Author: Pavel Starovoitov
 */

#include <output.h>

namespace gpio
{

  output::output (gpio::port *const port, const uint32_t pin) : pin::pin(port, pin)
  {
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;

    init(&GPIO_InitStruct);

}

  output::~output ()
  {
  }

} /* namespace gpio */
