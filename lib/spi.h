/** 
 * SPI Library
 *
 * Copyright (C) 2020 Marian Hrinko.
 * Written by Marian Hrinko (mato.hrinko@gmail.com)
 *
 * @author      Marian Hrinko
 * @datum       08.03.2020
 * @file        spi.h
 * @tested      stm32f103c6t8
 * @inspiration https://github.com/nalepae/stm32_tutorial/blob/master/src/spi.c
 *              https://learnbuildshare.wordpress.com/about/stm32/using-spi-as-master/
 *              http://www.handsonembedded.com/stm32f103-spl-tutorial-5/
 * -------------------------------------------------
 */

#ifndef __SPI_H__
#define __SPI_H__

  /**
   * @desc    Init pins for SPI1
   *
   * @param   void
   * @return  void
   */
  void SPI1_InitPins(void);

  /**
   * @desc    Init SS pin for SPI1
   *
   * @param   void
   * @return  void
   */
  void SPI1_InitSS(void);

  /**
   * @desc    Init SPI1
   *
   * @param   void
   * @return  void
   */
  void SPI1_Init(void);

#endif
