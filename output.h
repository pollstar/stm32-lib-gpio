/*
 * output.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Pavel Starovoitov
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <pin.h>

namespace gpio
{

  const uint32_t speed_low = LL_GPIO_SPEED_FREQ_LOW;
  const uint32_t speed_medium = LL_GPIO_SPEED_FREQ_MEDIUM;
  const uint32_t speed_high = LL_GPIO_SPEED_FREQ_HIGH;
  /*
   *
   */
  class output : public pin
  {
  public:
    output (gpio::port *const port, const uint32_t pin, const uint32_t speed = gpio::speed_low,
	    const uint32_t outputType = LL_GPIO_OUTPUT_PUSHPULL, const uint32_t pull = LL_GPIO_PULL_NO);
    virtual
    ~output ();
  };

} /* namespace gpio */

#endif /* OUTPUT_H_ */
