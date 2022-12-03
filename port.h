/*
 * portgpio.h
 *
 *  Created on: 19 oct 2022
 *      Author: Pavel Starovoitov
 */

#ifndef PORT_H_
#define PORT_H_

#include "drivers_include.h"

#ifdef USE_STREAM
#include "stream.h"
#endif

#define gpioa porta
#define gpiob portb
#define gpioc portc
#define gpiod portd
#define gpioe porte
#define gpiof portf


namespace gpio
{
  /*
   *
   */
  class port
  {
  public:
    port(GPIO_TypeDef *GPIOx): _port(GPIOx){};
    void init(void) const;
    inline GPIO_TypeDef* getPort(void) const {return _port;};
  private:
    mutable GPIO_TypeDef *_port;
    mutable uint32_t _used = 0;

#ifdef USE_STREAM
    friend com::ostream& operator << (com::ostream& out, gpio::port& port);
#endif
  };

#ifdef GPIOA
  extern gpio::port *const porta;
#endif
#ifdef GPIOB
  extern gpio::port *const portb;
#endif
#ifdef GPIOC
  extern gpio::port *const portc;
#endif
#ifdef GPIOD
  extern gpio::port *const portd;
#endif
#ifdef GPIOE
  extern gpio::port *const porte;
#endif
#ifdef GPIOF
  extern gpio::port *const portf;
#endif
} /* namespace gpio */


#endif /* PORT_H_ */
