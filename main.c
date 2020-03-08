/**
 * SPI example
 *
 * Copyright (C) 2020 Marian Hrinko.
 * Written by Marian Hrinko (mato.hrinko@gmail.com)
 *
 * @author      Marian Hrinko
 * @datum       08.03.2020
 * @file        main.c
 * @tested      stm32f103c8t6
 * @descript    Example spi communication for stm32f103c8t6
 * @usage       Education
 * --------------------------------------------------------
 */
 
// libraries
#include <stm32f10x.h>
#include "lib/spi.h"

/**
 * @desc    Main
 *
 * @param   void
 * @return  void
 */
void main(void)
{
  // init pins MOSI, MISO, SCK
  SPI1_InitPins();
  // init pin SS
  SPI1_InitSS();
  // init SPI1
  SPI1_Init();
}
 
#ifdef USE_FULL_ASSERT
  void assert_failed(uint8_t* file, uint32_t line)
  {
    // Use GDB to find out why we're here
    while (1);
  }
#endif
