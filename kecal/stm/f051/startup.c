#include <stdint.h>

#if defined (__cplusplus)
extern "C" {
#endif
extern void (*__init_array_start)();
extern void (*__init_array_end)  ();
void static_init() {
  void (**p)();
  for (p = &__init_array_start; p < &__init_array_end; p++) (*p)();
}
#define WEAK     __attribute__ ((weak))
#define ALIAS(f) __attribute__ ((weak, alias (#f)))

extern unsigned int _estack;
extern unsigned int _sidata;
extern unsigned int _sdata;
extern unsigned int _edata;
extern unsigned int _sbss;
extern unsigned int _ebss;

WEAK void Reset_Handler     (void);
WEAK void DefaultHandler    (void);
void NonMaskableInt_Handler                 (void) ALIAS(Default_Handler);
void HardFault_Handler                      (void) ALIAS(Default_Handler);
void MemoryManagement_Handler               (void) ALIAS(Default_Handler);
void BusFault_Handler                       (void) ALIAS(Default_Handler);
void UsageFault_Handler                     (void) ALIAS(Default_Handler);
void SVCall_Handler                         (void) ALIAS(Default_Handler);
void DebugMonitor_Handler                   (void) ALIAS(Default_Handler);
void PendSV_Handler                         (void) ALIAS(Default_Handler);
void SysTick_Handler                        (void) ALIAS(Default_Handler);

void WWDG_IRQHandler                        (void) ALIAS(Default_Handler);
void PVD_IRQHandler                         (void) ALIAS(Default_Handler);
void RTC_IRQHandler                         (void) ALIAS(Default_Handler);
void FLASH_IRQHandler                       (void) ALIAS(Default_Handler);
void RCC_CRS_IRQHandler                     (void) ALIAS(Default_Handler);
void EXTI0_1_IRQHandler                     (void) ALIAS(Default_Handler);
void EXTI2_3_IRQHandler                     (void) ALIAS(Default_Handler);
void EXTI4_15_IRQHandler                    (void) ALIAS(Default_Handler);
void TSC_IRQHandler                         (void) ALIAS(Default_Handler);
void DMA1_CH1_IRQHandler                    (void) ALIAS(Default_Handler);
void DMA1_CH2_3_DMA2_CH1_2_IRQHandler       (void) ALIAS(Default_Handler);
void DMA1_CH4_5_6_7_DMA2_CH3_4_5_IRQHandler (void) ALIAS(Default_Handler);
void ADC_COMP_IRQHandler                    (void) ALIAS(Default_Handler);
void TIM1_BRK_UP_TRG_COM_IRQHandler         (void) ALIAS(Default_Handler);
void TIM1_CC_IRQHandler                     (void) ALIAS(Default_Handler);
void TIM2_IRQHandler                        (void) ALIAS(Default_Handler);
void TIM3_IRQHandler                        (void) ALIAS(Default_Handler);
void TIM6_DAC_IRQHandler                    (void) ALIAS(Default_Handler);
void TIM7_IRQHandler                        (void) ALIAS(Default_Handler);
void TIM14_IRQHandler                       (void) ALIAS(Default_Handler);
void TIM15_IRQHandler                       (void) ALIAS(Default_Handler);
void TIM16_IRQHandler                       (void) ALIAS(Default_Handler);
void TIM17_IRQHandler                       (void) ALIAS(Default_Handler);
void I2C1_IRQHandler                        (void) ALIAS(Default_Handler);
void I2C2_IRQHandler                        (void) ALIAS(Default_Handler);
void SPI1_IRQHandler                        (void) ALIAS(Default_Handler);
void SPI2_IRQHandler                        (void) ALIAS(Default_Handler);
void USART1_IRQHandler                      (void) ALIAS(Default_Handler);
void USART2_IRQHandler                      (void) ALIAS(Default_Handler);
void USART3_4_5_6_7_8_IRQHandler            (void) ALIAS(Default_Handler);
void CEC_CAN_IRQHandler                     (void) ALIAS(Default_Handler);
void USB_IRQHandler                         (void) ALIAS(Default_Handler);

extern int  main (void);
extern void SystemInit (void);
extern void SystemCoreClockUpdate (void);

#if defined (__cplusplus)
}; // extern "C"
#endif
typedef void (*handler) (void);
__attribute__ ((section(".isr_vector")))
handler Vectors[] = {
  (handler) &_estack,
  Reset_Handler,
  NonMaskableInt_Handler,
  HardFault_Handler,
  MemoryManagement_Handler,
  BusFault_Handler,
  UsageFault_Handler,
  0,
  0,
  0,
  0,
  SVCall_Handler,
  DebugMonitor_Handler,
  0,
  PendSV_Handler,
  SysTick_Handler,

  WWDG_IRQHandler,
  PVD_IRQHandler,
  RTC_IRQHandler,
  FLASH_IRQHandler,
  RCC_CRS_IRQHandler,
  EXTI0_1_IRQHandler,
  EXTI2_3_IRQHandler,
  EXTI4_15_IRQHandler,
  TSC_IRQHandler,
  DMA1_CH1_IRQHandler,
  DMA1_CH2_3_DMA2_CH1_2_IRQHandler,
  DMA1_CH4_5_6_7_DMA2_CH3_4_5_IRQHandler,
  ADC_COMP_IRQHandler,
  TIM1_BRK_UP_TRG_COM_IRQHandler,
  TIM1_CC_IRQHandler,
  TIM2_IRQHandler,
  TIM3_IRQHandler,
  TIM6_DAC_IRQHandler,
  TIM7_IRQHandler,
  TIM14_IRQHandler,
  TIM15_IRQHandler,
  TIM16_IRQHandler,
  TIM17_IRQHandler,
  I2C1_IRQHandler,
  I2C2_IRQHandler,
  SPI1_IRQHandler,
  SPI2_IRQHandler,
  USART1_IRQHandler,
  USART2_IRQHandler,
  USART3_4_5_6_7_8_IRQHandler,
  CEC_CAN_IRQHandler,
  USB_IRQHandler,

};
void Reset_Handler(void) {
  register unsigned int *src, *dst, *end;
  /* Zero fill the bss section */
  dst = &_sbss;
  end = &_ebss;
  while (dst < end)  *dst++ = 0U;

  /* Copy data section from flash to RAM */
  src = &_sidata;
  dst = &_sdata;
  end = &_edata;
  while (dst < end) *dst++ = *src++;

  SystemInit();
  SystemCoreClockUpdate();          // Potřebné pro USART
  static_init();                    // Zde zavolám globální konstruktory

  main();

  for (;;);
}

void Default_Handler (void) {
  asm volatile ("bkpt 1");
}
