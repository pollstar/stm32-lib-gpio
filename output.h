/*
 * output.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Pavel Starovoitov
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "pin.h"

namespace gpio
{
  /*
   *
   */
  class output : public pin
  {
  public:
    output (gpio::port *const port, const uint32_t pin, const uint32_t speed = gpio::speed_low,
	    const uint32_t outputType = LL_GPIO_OUTPUT_PUSHPULL, const uint32_t pull = LL_GPIO_PULL_NO);
    virtual void set (void) const;
    virtual void reset (void) const;
    virtual gpio::state get (void);
    ~output ();
  };

} /* namespace gpio */

#endif /* OUTPUT_H_ */
