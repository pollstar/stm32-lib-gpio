/*
 * pin.h
 *
 *  Created on: 19 oct 2022
 *      Author: Pavel Starovoitov
 */

#ifndef PIN_H_
#define PIN_H_

#include "port.h"

namespace gpio
{
  enum state
  {
    LOW = 0, HIGH = 1
  };

  const uint32_t pin0 = ((uint16_t)0x0001U);
  const uint32_t pin1 = ((uint16_t)0x0002U);
  const uint32_t pin2 = ((uint16_t)0x0004U);
  const uint32_t pin3 = ((uint16_t)0x0008U);
  const uint32_t pin4 = ((uint16_t)0x0010U);
  const uint32_t pin5 = ((uint16_t)0x0020U);
  const uint32_t pin6 = ((uint16_t)0x0040U);
  const uint32_t pin7 = ((uint16_t)0x0080U);
  const uint32_t pin8 = ((uint16_t)0x0100U);
  const uint32_t pin9 = ((uint16_t)0x0200U);
  const uint32_t pin10 = ((uint16_t)0x0400U);
  const uint32_t pin11 = ((uint16_t)0x0800U);
  const uint32_t pin12 = ((uint16_t)0x1000U);
  const uint32_t pin13 = ((uint16_t)0x2000U);
  const uint32_t pin14 = ((uint16_t)0x4000U);
  const uint32_t pin15 = ((uint16_t)0x8000U);

#ifdef USE_FULL_LL_DRIVER
  const uint32_t speed_low = LL_GPIO_SPEED_FREQ_LOW;
  const uint32_t speed_medium = LL_GPIO_SPEED_FREQ_MEDIUM;
  const uint32_t speed_high = LL_GPIO_SPEED_FREQ_HIGH;
#elif USE_HAL_DRIVER
  const uint32_t speed_low = GPIO_SPEED_FREQ_LOW;
  const uint32_t speed_medium = GPIO_SPEED_FREQ_MEDIUM;
  const uint32_t speed_high = GPIO_SPEED_FREQ_HIGH;
#else
  const uint32_t speed_low = (0x00000000U);
  const uint32_t speed_medium = (0x00000001U);
  const uint32_t speed_high = (0x00000003U);
#endif
  /*
   *
   */
  class pin
  {
  public:
    pin (gpio::port * const port, uint32_t pin);

    virtual ~pin ();
#ifdef USE_FULL_LL_DRIVER
    void init (LL_GPIO_InitTypeDef *GPIO_InitStruct);
#elif USE_HAL_DRIVER
    void init (GPIO_InitTypeDef *GPIO_InitStruct);
#else
  #error Need to implement the init method
#endif

    virtual void set (void) const;
    virtual void reset (void)const ;
    virtual gpio::state get (void);
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

#ifdef USE_STREAM
    friend com::ostream& operator << (com::ostream& out, gpio::pin& pin);
#endif
  };

} /* namespace gpio */

#endif /* PIN_H_ */
