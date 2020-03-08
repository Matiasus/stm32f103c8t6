/** 
 * SPI Library
 *
 * Copyright (C) 2020 Marian Hrinko.
 * Written by Marian Hrinko (mato.hrinko@gmail.com)
 *
 * @author      Marian Hrinko
 * @datum       08.03.2020
 * @file        spi.c
 * @tested      stm32f103c6t8
 * @inspiration https://github.com/nalepae/stm32_tutorial/blob/master/src/spi.c
 *              https://learnbuildshare.wordpress.com/about/stm32/using-spi-as-master/
 *              http://www.handsonembedded.com/stm32f103-spl-tutorial-5/
 * -------------------------------------------------
 */

#include <stm32f10x.h>
#include "spi.h"

/**
 * @desc    Init MOSI, MISO, SCK pins for SPI1
 *
 * @param   void
 * @return  void
 */
void SPI1_InitPins()
{
  // enable clock for corresponding GPIOA
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_SPI1EN;

  // ----------------------------
  // CNF[1:0] = 00 -> Push pull  / GENERAL PURPOSE OUTPUT - MODE[1:0] = 01; 10; 11
  // CNF[1:0] = 01 -> Open drain / GENERAL PURPOSE OUTPUT - MODE[1:0] = 01; 10; 11
  // CNF[1:0] = 10 -> Push pull  / ALTERNATE FUNCTION OUTPUT - MODE[1:0] = 01; 10; 11
  // CNF[1:0] = 01 -> Open drain / ALTERNATE FUNCTION OUTPUT - MODE[1:0] = 01; 10; 11
  // CNF[1:0] = 00 -> Analog     / INPUT - MODE[1:0] = 00
  // CNF[1:0] = 01 -> Floating   / INPUT - MODE[1:0] = 00
  // CNF[1:0] = 10 -> Pull down  / INPUT - MODE[1:0] = 00
  // CNF[1:0] = 11 -> Pull up    / INPUT - MODE[1:0] = 00
  // ----------------------------
  // MODE[1:0] = 01 // 10 MHz
  // MODE[1:0] = 10 //  2 MHz
  // MODE[1:0] = 11 // 50 MHz
  // ----------------------------

  // SCK  - GPIOA.5 - Alternate PUSH PULL 
  // MOSI - GPIOA.7 - Alternate PUSH PULL
  GPIOA->CRL |= GPIO_CRL_CNF5_1 | GPIO_CRL_CNF7_1;
  // MISO - GPIOA.6 - Input PULL UP
  GPIOA->CRL |= GPIO_CRL_CNF6;

  // 50MHz
  GPIOA->CRL |= GPIO_CRL_MODE5 | GPIO_CRL_MODE7 | GPIO_CRL_MODE6;
}

/**
 * @desc    Init SS pin for SPI1
 *
 * @param   void
 * @return  void
 */
void SPI1_InitSS()
{
  // enable clock for corresponding GPIOA
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

  // ----------------------------
  // CNF[1:0] = 00 -> Push pull  / GENERAL PURPOSE OUTPUT - MODE[1:0] = 01; 10; 11
  // CNF[1:0] = 01 -> Open drain / GENERAL PURPOSE OUTPUT - MODE[1:0] = 01; 10; 11
  // CNF[1:0] = 10 -> Push pull  / ALTERNATE FUNCTION OUTPUT - MODE[1:0] = 01; 10; 11
  // CNF[1:0] = 01 -> Open drain / ALTERNATE FUNCTION OUTPUT - MODE[1:0] = 01; 10; 11
  // CNF[1:0] = 00 -> Analog     / INPUT - MODE[1:0] = 00
  // CNF[1:0] = 01 -> Floating   / INPUT - MODE[1:0] = 00
  // CNF[1:0] = 10 -> Pull down  / INPUT - MODE[1:0] = 00
  // CNF[1:0] = 11 -> Pull up    / INPUT - MODE[1:0] = 00
  // ----------------------------
  // MODE[1:0] = 01 // 10 MHz
  // MODE[1:0] = 10 //  2 MHz
  // MODE[1:0] = 11 // 50 MHz
  // ----------------------------

  // SS  - GPIOA.3 - Output PUSH PULL 
  GPIOA->CRL &= ~GPIO_CRL_CNF3;

  // 50MHz
  GPIOA->CRL |= GPIO_CRL_MODE3;
}

/**
 * @desc    Init pins for SPI1
 *
 * @param   void
 * @return  void
 */
void SPI1_Init()
{
  // SPI1_CR1 register
  // ----------------------------------------------------------------------------------
  // [15] BIDIMODE: Bidirectional data mode enable
  //   0: 2-line unidirectional data mode selected
  //   1: 1-line bidirectional data mode selected
  // 
  // [14] BIDIOE: Output enable in bidirectional mode
  // This bit combined with the BIDImode bit selects the direction of transfer in bidirectional mode
  //    0: Output disabled (receive-only mode)
  //    1: Output enabled (transmit-only mode)
  // In master mode, the MOSI pin is used while the MISO pin is used in slave mode.
  //
  // [13] CRCEN: Hardware CRC calculation enable
  //    0: CRC calculation disabled
  //    1: CRC calculation enabled
  // Note: This bit should be written only when SPI is disabled (SPE = ‘0’) for correct operation.
  //
  // [12] CRCNEXT: CRC transfer next
  //    0: Data phase (no CRC phase)
  //    1: Next transfer is CRC (CRC phase)
  // Note: When the SPI is configured in full duplex or transmitter only modes, CRCNEXT must be
  // written as soon as the last data is written to the SPI_DR register.
  // When the SPI is configured in receiver only mode, CRCNEXT must be set after the
  // second last data reception.
  // This bit should be kept cleared when the transfers are managed by DMA.
  //
  // [11] DFF: Data frame format
  //    0: 8-bit data frame format is selected for transmission/reception
  //    1: 16-bit data frame format is selected for transmission/reception
  // Note: This bit should be written only when SPI is disabled (SPE = ‘0’) for correct operation.
  //
  // [10] RXONLY: Receive only
  //  This bit combined with the BIDImode bit selects the direction of transfer in 2-line
  //  unidirectional mode. This bit is also useful in a multislave system in which this particular
  //  slave is not accessed, the output from the accessed slave is not corrupted.
  //    0: Full duplex (Transmit and receive)
  //    1: Output disabled (Receive-only mode)
  //
  // [9] SSM: Software slave management
  // When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
  //    0: Software slave management disabled
  //    1: Software slave management enabled
  //
  // [8] SSI: Internal slave select
  // This bit has an effect only when the SSM bit is set. The value of this bit is forced onto the
  // NSS pin and the IO value of the NSS pin is ignored.
  //
  // [7] LSBFIRST: Frame format
  //    0: MSB transmitted first
  //    1: LSB transmitted first
  // Note: This bit should not be changed when communication is ongoing.
  //
  // [6] SPE: SPI enable
  //    0: Peripheral disabled
  //    1: Peripheral enabled
  // When disabling the SPI, follow the procedure described in Section 25.3.8.
  //
  // [5:3] BR[2:0]: Baud rate control
  //    000: f PCLK /2
  //    001: f PCLK /4
  //    010: f PCLK /8
  //    011: f PCLK /16
  //    100: f PCLK /32
  //    101: f PCLK /64
  //    110: f PCLK /128
  //    111: f PCLK /256
  // Note: These bits should not be changed when communication is ongoing.
  //
  // [2] MSTR: Master selection
  //    0: Slave configuration
  //    1: Master configuration
  // Note: This bit should not be changed when communication is ongoing.
  //
  // [1] CPOL: Clock polarity
  //    0: CK to 0 when idle
  //    1: CK to 1 when idle
  // Note: This bit should not be changed when communication is ongoing.
  //
  // [0] CPHA: Clock phase
  //    0: The first clock transition is the first data capture edge
  //    1: The second clock transition is the first data capture edge
  // Note: This bit should not be changed when communication is ongoing.
  // ----------------------------------------------------------------------------------
  // BIDIMODE: 0 - 2-line unidirectional data mode selected
  // BIDIOE:   0 - Output disabled (receive-only mode)
  // CRCEN:    0 - CRC calculation disabled
  // CRCNEXT:  0 - Data phase (no CRC phase)
  // DFF:      0 - 8-bit data frame format is selected for transmission/reception
  // RXONLY:   0 - Full duplex (Transmit and receive)
  // SSM:      1 - Software slave management enabled
  // SSI:
  // LSBFIRST: 0 - MSB transmitted first
  // SPE:      0 - Peripheral disabled
  // BR[2:0]:  100 - f PCLK/32
  // MSTR:     1 - Master configuration
  // CPOL:     0 - CK to 0 when idle
  // CPHA:     0 - The first clock transition is the first data capture edge
  // ----------------------------------------------------------------------------------
  SPI1->CR1 = SPI_CR1_SSM | SPI_CR1_BR_2 | SPI_CR1_MSTR;
  // enable SPI1
  SPI1->CR1 |= SPI_CR1_SPE;
}
