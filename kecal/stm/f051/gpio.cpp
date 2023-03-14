#include "gpio.h"

static constexpr uint32_t RCC_AHBENR_GPIOAEN = 1u << 17;        /*!< GPIOA clock enable */
static constexpr uint32_t RCC_AHBENR_GPIOBEN = 1u << 18;        /*!< GPIOB clock enable */
static constexpr uint32_t RCC_AHBENR_GPIOCEN = 1u << 19;        /*!< GPIOC clock enable */
static constexpr uint32_t RCC_AHBENR_GPIODEN = 1u << 20;        /*!< GPIOD clock enable */
static constexpr uint32_t RCC_AHBENR_GPIOFEN = 1u << 22;        /*!< GPIOF clock enable */

static const GpioAssocPort cPortTab[] = {
  {0x48000000, RCC_AHBENR_GPIOAEN},
  {0x48000400, RCC_AHBENR_GPIOBEN},
  {0x48000800, RCC_AHBENR_GPIOCEN},
  {0x48000c00, RCC_AHBENR_GPIODEN},
  {0x48001400, RCC_AHBENR_GPIOFEN},
}; 
GpioClass::GpioClass (GpioPortNum const port, const uint32_t no, const GPIOMode_TypeDef type) :
  io((GPIOF_Type*)cPortTab[port].portAdr), pos(1UL << no), num(no) {
  // Povol hodiny
  RCC.AHBENR.R |= cPortTab[port].clkMask;
  // A nastav pin (pořadí dle ST knihovny).
  setSpeed (GPIO_Speed_Level_3);
  setOType (GPIO_OType_PP);
  setMode  (type);
  setPuPd  (GPIO_PuPd_NOPULL);
}

