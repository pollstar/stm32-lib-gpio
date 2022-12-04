/*
 * portgpio.cpp
 *
 *  Created on: 19 oct 2022
 *      Author: Pavel Starovoitov
 */

#include "port.h"

namespace gpio
{
#if defined(GPIOA)
  gpio::port *const gpioa = new gpio::port(GPIOA);
#endif
#if defined(GPIOB)
  gpio::port *const gpiob = new gpio::port(GPIOB);
#endif
#if defined(GPIOC)
  gpio::port *const gpioc = new gpio::port(GPIOC);
#endif
#if defined(GPIOD)
  gpio::port *const gpiod = new gpio::port(GPIOD);
#endif
#if defined(GPIOE)
  gpio::port *const gpioe = new gpio::port(GPIOE);
#endif
#if defined(GPIOF)
  gpio::port *const gpiof = new gpio::port(GPIOF);
#endif

  void port::init(void) const
  {
    if (_used == 0)
    {
#if defined (USE_FULL_LL_DRIVER)
    if (_port == GPIOA)
  #if defined (STM32H7xx)
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOA);
  #else
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
  #endif

#if defined (GPIOB)
      else if (_port == GPIOB)
  #if defined (STM32H7xx)
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOB);
  #else
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
  #endif
#endif

#if defined(GPIOC)
    else if (_port == GPIOC)
  #if defined (STM32H7xx)
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOC);
  #else
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
  #endif
#endif

#if defined (GPIOD)
    else if (_port == GPIOD)
  #if defined (STM32H7xx)
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOD);
  #else
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
  #endif
#endif

#if defined (GPIOE)
    else if (_port == GPIOE)
  #if defined (STM32H7xx)
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOE);
  #else
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);
  #endif
#endif

#if defined (GPIOF)
    else if (_port == GPIOF)
  #if defined (STM32H7xx)
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOF);
  #else
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);
  #endif
#endif

#elif  defined (USE_HAL_DRIVER)
  #error Need to implement the init method
#else
  #error Need to implement the init method
#endif
    }

    _used++;
  }

#if defined (USE_STREAM)
  com::ostream& operator << (com::ostream& out, gpio::port& port)
  {
    out << "GPIO";

    char portname = ' ';

      if (port.getPort() == GPIOA) portname = 'A';
    #if defined (GPIOB)
      else if (port.getPort() == GPIOB) portname = 'B';
    #endif
    #if defined (GPIOC)
      else if (port.getPort() == GPIOC) portname = 'C';
    #endif
    #if defined (GPIOD)
      else if (port.getPort() == GPIOD) portname = 'D';
    #endif
    #if defined (GPIOE)
      else if (port.getPort() == GPIOE) portname = 'E';
    #endif
    #if defined (GPIOF)
      else if (port.getPort() == GPIOF) portname = 'F';
    #endif

    out << portname;

    return out;
  }
#endif
} /* namespace gpio */


