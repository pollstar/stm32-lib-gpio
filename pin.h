/*
 * pin.h
 *
 *  Created on: 19 oct 2022
 *      Author: Pavel Starovoitov
 */

#ifndef PIN_H_
#define PIN_H_

#include "main.h"
#include "port.h"

namespace gpio
{
  enum state
  {
    LOW = 0, HIGH = 1
  };

  const uint32_t pin0 = LL_GPIO_PIN_0;
  const uint32_t pin1 = LL_GPIO_PIN_1;
  const uint32_t pin2 = LL_GPIO_PIN_2;
  const uint32_t pin3 = LL_GPIO_PIN_3;
  const uint32_t pin4 = LL_GPIO_PIN_4;
  const uint32_t pin5 = LL_GPIO_PIN_5;
  const uint32_t pin6 = LL_GPIO_PIN_6;
  const uint32_t pin7 = LL_GPIO_PIN_7;
  const uint32_t pin8 = LL_GPIO_PIN_8;
  const uint32_t pin9 = LL_GPIO_PIN_9;
  const uint32_t pin10 = LL_GPIO_PIN_10;
  const uint32_t pin11 = LL_GPIO_PIN_11;
  const uint32_t pin12 = LL_GPIO_PIN_12;
  const uint32_t pin13 = LL_GPIO_PIN_13;
  const uint32_t pin14 = LL_GPIO_PIN_14;
  const uint32_t pin15 = LL_GPIO_PIN_15;
  /*
   *
   */
  class pin
  {
  public:
    pin (gpio::port * const port, uint32_t pin);

    virtual ~pin ();

    void init (LL_GPIO_InitTypeDef *GPIO_InitStruct);
    virtual void set (void) const;
    void reset (void)const ;
    gpio::state get (void);
    inline port* getport (void) const
    {
      return _port;
    }
    inline uint32_t getpin () const
    {
      return _pin;
    }
    bool operator !=(gpio::pin& pin);

  protected:
    gpio::port *const _port;
    uint32_t _pin;

#ifdef STREAM_H_
    friend com::ostream& operator << (com::ostream& out, gpio::pin& pin);
#endif
  };

} /* namespace gpio */

#endif /* PIN_H_ */
