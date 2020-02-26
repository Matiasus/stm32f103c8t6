/**
 * Simple Led blinking 
 *
 * Copyright (C) 2020 Marian Hrinko.
 * Written by Marian Hrinko (mato.hrinko@gmail.com)
 *
 * @author      Marian Hrinko
 * @datum       26.02.2020
 * @file        blink.c
 * @tested      stm32f103c8t6
 * @descript    Example led blinking for stm32f103c8t6
 * @usage       Education
 * 
 */
 
#include <stm32f10x.h>
#include <stm32f10x_conf.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>

/**
 * @desc    Delay
 *
 * @param   void
 * @return  void
 */
void wait(void);

/**
 * @desc    Led blinking on GPIOA Pin 2
 *
 * @param   void
 * @return  void
 */
void LedBlink_GPIOA_Pin2();

/**
 * @desc    main
 *
 * @param   void
 * @return  void
 */
void main(void)
{
  // call led  blink on GPIOA Pin 2
  LedBlink_GPIOA_Pin2();
}

/**
 * @desc    Delay
 *
 * @param   void
 * @return  void
 */
void wait(void)
{
  // must be defined
}
 
/**
 * @desc    Led blinking on GPIOA Pin 2
 *
 * @param   void
 * @return  void
 */
void LedBlink_GPIOA_Pin2() 
{
  // enable clock for corresponding GPIO
  RCC->APB2ENR |= RCC_APB2Periph_GPIOA;
 
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
  //
  // GPIOA.Pin_2 - Output push pull
  GPIOA->CRL = ~(GPIO_CRL_CNF2);
  
  // MODE[1:0] = 01 // 10 MHz
  // MODE[1:0] = 10 //  2 MHz
  // MODE[1:0] = 11 // 50 MHz
  // ----------------------------
  // 
  // speed - 50MHz
  GPIOA->CRL |= GPIO_CRL_MODE2;

  // loop for led blinking
  while (1) {
    // led ON
    GPIOA->BSRR |= GPIO_BSRR_BS2;
    // delay
    wait();
    // led OFF
    GPIOA->BRR |= GPIO_BSRR_BR2;
    // delay
    wait();      
  }
}

#ifdef USE_FULL_ASSERT
  void assert_failed(uint8_t* file, uint32_t line)
  {
    // Use GDB to find out why we're here
    while (1);
  }
#endif
