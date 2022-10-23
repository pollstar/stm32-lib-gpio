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

  /*
   *
   */
  class output : public pin
  {
  public:
    output (gpio::port *const port, const uint32_t pin);
    virtual
    ~output ();
  };

} /* namespace gpio */

#endif /* OUTPUT_H_ */
