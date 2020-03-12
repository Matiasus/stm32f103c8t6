# STM32F103C8T6 SPI Library
Example of SPI1 communication. The serial peripheral interface (SPI) STM32f103C8T6 allows half / full-duplex, synchronous, serial
communication with external devices. It may be used for a variety of purposes, including simplex synchronous transfers on two
lines with a possible bidirectional data line or reliable communication using CRC checking. [RM0008 Reference manual](https://www.st.com/mwg-internal/de5fs23hu73ds/progress?id=4xg82YtTk42dgC33Uqaa4XQ5B_tXbY3NJjon9Bfhm7k,)

# Usage
Defined for microcontroller STM32f103C8T6. 

| PORT  | SPI1 | SPI1 remap | SPI2 |
| :---: | :---: | :---: | :---: |
| SS | PA4 | PA15 | PB12 |
| SCK | PA5 | PB3 | PB13 |
| MISO | PA6 | PB4 | PB14 |
| MOSI | PA7 | PB5 | PB15 |

## SPI1 Library
```c
  /**
   * @desc    Init pins for SPI1
   */
  void SPI1_InitPins(void);

  /**
   * @desc    Init SS pin for SPI1
   */
  void SPI1_InitSS(void);

  /**
   * @desc    Init SPI1
   */
  void SPI1_Init(void);
  
  /**
   * @desc    Stop SPI1
   */
  void SPI1_Disable(void);

  /**
   * @desc    Send 8 bits
   */
  void SPI1_TX_8bits(uint8_t);

  /**
   * @desc    Receive 8 bits
   */
  uint8_t SPI1_RX_8bits(void);

  /**
   * @desc    Transmission / receive array of data
   */
  uint8_t * SPI1_TRX_8bits(uint8_t *, uint8_t);
```
## Acknowledgement
- [Erwin Ouyang](http://www.handsonembedded.com/stm32f103-spl-tutorial-5/)
- [Manu NALEPA](https://github.com/nalepae/stm32_tutorial/blob/master/src/spi.c)
- [Learn, build, and share](https://learnbuildshare.wordpress.com/about/stm32/using-spi-as-master/)

## Links
- [RM0008 Reference manual](https://www.st.com/mwg-internal/de5fs23hu73ds/progress?id=4xg82YtTk42dgC33Uqaa4XQ5B_tXbY3NJjon9Bfhm7k,)
