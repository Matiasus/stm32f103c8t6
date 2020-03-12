# STM32F103C8T6 SPI Library
Example of SPI1 communication with peripheral LCD display. Detailed information how to drive SPI on microcontroller STM32f103C8T6 is described in [RM0008 Reference manual](https://www.st.com/mwg-internal/de5fs23hu73ds/progress?id=4xg82YtTk42dgC33Uqaa4XQ5B_tXbY3NJjon9Bfhm7k,) and information about how to drive LCD with ST7735 driver is described in [ST7735 Manual](http://www.displayfuture.com/Display/datasheet/controller/ST7735.pdf).

## Library
C library is aimed for driving ST7735 1.8 TFT LCD display 162x132 through SPI's STM32f103C8T6.

### Usage
Prior defined for microcontroller STM32f103C8T6. 

### Tested
Library was tested and proved on a ST7735 1.8″ TFT Dispay with STM32f103C8T6.

### Pinout
SPI1 alternate function remapping according to [RM0008 Reference manual](https://www.st.com/mwg-internal/de5fs23hu73ds/progress?id=4xg82YtTk42dgC33Uqaa4XQ5B_tXbY3NJjon9Bfhm7k,) (9.3.10, page 181).

| PORT  | SPI1 | SPI1 remap | SPI2 |
| :---: | :---: | :---: | :---: |
| SS | PA4 | PA15 | PB12 |
| SCK | PA5 | PB3 | PB13 |
| MISO | PA6 | PB4 | PB14 |
| MOSI | PA7 | PB5 | PB15 |

### Functions
- [void **SPI1_InitPins** ( void )]() - init SPI1 pins SCK, MISO, MOSI
- [void SPI1_InitSS ( void )]() - init SPI1 pin SS (CS)
- [void SPI1_Init ( void )]() - init SPI1 communication
- [void SPI1_Disable ( void )]() - disable spi communication
- [void SPI1_TX_8bits ( uint8_t )]() - transmit 8 bits
- [uint8_t SPI1_RX_8bits ( void )]() - receive 8 bits
- [uint8_t * SPI1_TRX_8bits ( uint8_t \* , uint8_t )]() - transmit and receive 8 bits
  
## Acknowledgement
- [Erwin Ouyang](http://www.handsonembedded.com/stm32f103-spl-tutorial-5/)
- [Manu NALEPA](https://github.com/nalepae/stm32_tutorial/blob/master/src/spi.c)
- [Learn, build, and share](https://learnbuildshare.wordpress.com/about/stm32/using-spi-as-master/)

## Links
- [RM0008 Reference manual](https://www.st.com/mwg-internal/de5fs23hu73ds/progress?id=4xg82YtTk42dgC33Uqaa4XQ5B_tXbY3NJjon9Bfhm7k,)
- [ST7735 Manual](http://www.displayfuture.com/Display/datasheet/controller/ST7735.pdf)
