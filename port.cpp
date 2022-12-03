/*
 * portgpio.cpp
 *
 *  Created on: 19 oct 2022
 *      Author: Pavel Starovoitov
 */

#include "port.h"

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
#ifdef USE_FULL_LL_DRIVER
    if (_port == GPIOA)
  #if defined (STM32H7xx)
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOA);
  #else
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
  #endif

#ifdef GPIOB
      else if (_port == GPIOB)
  #if defined (STM32H7xx)
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOB);
  #else
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
  #endif
#endif

#ifdef GPIOC
    else if (_port == GPIOC)
  #if defined (STM32H7xx)
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOC);
  #else
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
  #endif
#endif

#ifdef GPIOD
    else if (_port == GPIOD)
  #if defined (STM32H7xx)
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOD);
  #else
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
  #endif
#endif

#ifdef GPIOE
    else if (_port == GPIOE)
  #if defined (STM32H7xx)
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOE);
  #else
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);
  #endif
#endif

#ifdef GPIOF
    else if (_port == GPIOF)
  #if defined (STM32H7xx)
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOF);
  #else
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);
  #endif
#endif

#elif USE_HAL_DRIVER
  #error Need to implement the init method
#else
  #error Need to implement the init method
#endif
    }

    _used++;
  }

#ifdef USE_STREAM
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


