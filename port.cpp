/*
 * portgpio.cpp
 *
 *  Created on: 19 oct 2022
 *      Author: Pavel Starovoitov
 */

#include <port.h>

namespace gpio
{
#ifdef GPIOA
  gpio::port *const gpioa = new gpio::port(GPIOA);
#endif
#ifdef GPIOB
  gpio::port *const gpiob = new gpio::port(GPIOB);
#endif
#ifdef GPIOC
  gpio::port *const gpioc = new gpio::port(GPIOC);
#endif
#ifdef GPIOD
  gpio::port *const gpiod = new gpio::port(GPIOD);
#endif
#ifdef GPIOE
  gpio::port *const gpioe = new gpio::port(GPIOE);
#endif
#ifdef GPIOF
  gpio::port *const gpiof = new gpio::port(GPIOF);
#endif

  void port::init(void) const
  {
    if (_used == 0)
    {
	if (_port == GPIOA) LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
      #ifdef GPIOB
	else if (_port == GPIOB) LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
      #endif
      #ifdef GPIOC
	else if (_port == GPIOC) LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
      #endif
      #ifdef GPIOD
	else if (_port == GPIOD) LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
      #endif
      #ifdef GPIOE
	else if (_port == GPIOE) LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);
      #endif
      #ifdef GPIOF
	else if (_port == GPIOF) LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);
      #endif
    }

    _used++;
  }

#ifdef STREAM_H_
  com::ostream& operator << (com::ostream& out, gpio::port& port)
  {
    out << "GPIO";

    char portname = ' ';

      if (port.getPort() == GPIOA) portname = 'A';
    #ifdef GPIOB
      else if (port.getPort() == GPIOB) portname = 'B';
    #endif
    #ifdef GPIOC
      else if (port.getPort() == GPIOC) portname = 'C';
    #endif
    #ifdef GPIOD
      else if (port.getPort() == GPIOD) portname = 'D';
    #endif
    #ifdef GPIOE
      else if (port.getPort() == GPIOE) portname = 'E';
    #endif
    #ifdef GPIOF
      else if (port.getPort() == GPIOF) portname = 'F';
    #endif

    out << portname;

    return out;
  }
#endif
} /* namespace gpio */


