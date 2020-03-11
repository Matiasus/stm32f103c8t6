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
   *
   * @return  void
   */
  void SPI1_InitPins(void);

  /**
   * @desc    Init SS pin for SPI1
   *
   * @param   void
   *
   * @return  void
   */
  void SPI1_InitSS(void);

  /**
   * @desc    Init SPI1
   *
   * @param   void
   *
   * @return  void
   */
  void SPI1_Init(void);
  
  /**
   * @desc    Stop SPI1
   *
   * @param   void
   *
   * @return  void
   */
  void SPI1_Disable(void);

  /**
   * @desc    Send 8 bits
   *
   * @param   unit8_t
   *
   * @return  void
   */
  void SPI1_TX_8bits(uint8_t);

  /**
   * @desc    Receive 8 bits
   *
   * @param   void
   *
   * @return  uint8_t
   */
  uint8_t SPI1_RX_8bits(void);

  /**
   * @desc    Transmission / receive array of data
   *
   * @param   unit8_t *
   * @param   unit8_t
   *
   * @return  unit8_t *
   */
  uint8_t * SPI1_TRX_8bits(uint8_t *, uint8_t);

#endif