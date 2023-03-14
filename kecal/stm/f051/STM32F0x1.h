#ifndef STM32F0x1_HDEF
#define STM32F0x1_HDEF
/** @brief STM32F0x1 */
/* STM32F0x1 */

/* IO definitions (access restrictions to peripheral registers) */
/** defines 'read only'    permissions */
#define __I volatile
/** defines 'write only'   permissions */
#define __O volatile
/** defines 'read / write' permissions */
#define __IO volatile
#include <stdint.h>
#define MERGE union
/*
  cpuName  = CM0
  revision = r0p0
  endian   = little
*/
#define __MPU_PRESENT             0
#define __NVIC_PRIO_BITS          3
#define __Vendor_SysTickConfig    0
#define __FPU_PRESENT             0
typedef uint32_t ONE_BIT;
enum _ONE_BIT : uint32_t { RESET = 0, SET = 1 };

// ////////////////////+++ CRC +-+//////////////////// //
struct CRC_Type         { /*!< cyclic redundancy check calculation unit */
  union DR_DEF   {  //!< Data register
    struct {
      __IO uint32_t   DR : 32; //!<[00] Data register bits
    } B;
    __IO uint32_t  R;
    explicit DR_DEF () noexcept { R = 0xffffffffu; }
    template<typename F> void setbit (F f) volatile {
      DR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IDR_DEF  {  //!< Independent data register
    struct {
      __IO uint32_t   IDR :  8; //!<[00] General-purpose 8-bit data register bits
    } B;
    __IO uint32_t  R;
    explicit IDR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IDR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IDR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CR_DEF   {  //!< Control register
    struct {
      __IO ONE_BIT    RESET    :  1; //!<[00] reset bit
           uint32_t   UNUSED0  :  2; //!<[01] 
      __IO uint32_t   POLYSIZE :  2; //!<[03] Polynomial size
      __IO uint32_t   REV_IN   :  2; //!<[05] Reverse input data
      __IO ONE_BIT    REV_OUT  :  1; //!<[07] Reverse output data
    } B;
    __IO uint32_t  R;
    explicit CR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union INIT_DEF {  //!< Initial CRC value
    struct {
      __IO uint32_t   INIT : 32; //!<[00] Programmable initial CRC value
    } B;
    __IO uint32_t  R;
    explicit INIT_DEF () noexcept { R = 0xffffffffu; }
    template<typename F> void setbit (F f) volatile {
      INIT_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      INIT_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL CRC REGISTERS INSTANCES
  __IO DR_DEF                DR ;  //!< [0000](04)[0xFFFFFFFF]
  __IO IDR_DEF              IDR ;  //!< [0004](04)[0x00000000]
  __IO CR_DEF                CR ;  //!< [0008](04)[0x00000000]
  __IO INIT_DEF            INIT ;  //!< [000c](04)[0xFFFFFFFF]
}; /* total size = 0x0400, struct size = 0x0010 */

// ////////////////////+++ GPIOF +-+//////////////////// //
struct GPIOF_Type       { /*!< General-purpose I/Os */
  union MODER_DEF   {  //!< GPIO port mode register
    struct {
      __IO uint32_t   MODER0  :  2; //!<[00] Port x configuration bits (y = 0..15)
      __IO uint32_t   MODER1  :  2; //!<[02] Port x configuration bits (y = 0..15)
      __IO uint32_t   MODER2  :  2; //!<[04] Port x configuration bits (y = 0..15)
      __IO uint32_t   MODER3  :  2; //!<[06] Port x configuration bits (y = 0..15)
      __IO uint32_t   MODER4  :  2; //!<[08] Port x configuration bits (y = 0..15)
      __IO uint32_t   MODER5  :  2; //!<[10] Port x configuration bits (y = 0..15)
      __IO uint32_t   MODER6  :  2; //!<[12] Port x configuration bits (y = 0..15)
      __IO uint32_t   MODER7  :  2; //!<[14] Port x configuration bits (y = 0..15)
      __IO uint32_t   MODER8  :  2; //!<[16] Port x configuration bits (y = 0..15)
      __IO uint32_t   MODER9  :  2; //!<[18] Port x configuration bits (y = 0..15)
      __IO uint32_t   MODER10 :  2; //!<[20] Port x configuration bits (y = 0..15)
      __IO uint32_t   MODER11 :  2; //!<[22] Port x configuration bits (y = 0..15)
      __IO uint32_t   MODER12 :  2; //!<[24] Port x configuration bits (y = 0..15)
      __IO uint32_t   MODER13 :  2; //!<[26] Port x configuration bits (y = 0..15)
      __IO uint32_t   MODER14 :  2; //!<[28] Port x configuration bits (y = 0..15)
      __IO uint32_t   MODER15 :  2; //!<[30] Port x configuration bits (y = 0..15)
    } B;
    __IO uint32_t  R;
    explicit MODER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      MODER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      MODER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union OTYPER_DEF  {  //!< GPIO port output type register
    struct {
      __IO ONE_BIT  OT0  :  1; //!<[00] Port x configuration bit 0
      __IO ONE_BIT  OT1  :  1; //!<[01] Port x configuration bit 1
      __IO ONE_BIT  OT2  :  1; //!<[02] Port x configuration bit 2
      __IO ONE_BIT  OT3  :  1; //!<[03] Port x configuration bit 3
      __IO ONE_BIT  OT4  :  1; //!<[04] Port x configuration bit 4
      __IO ONE_BIT  OT5  :  1; //!<[05] Port x configuration bit 5
      __IO ONE_BIT  OT6  :  1; //!<[06] Port x configuration bit 6
      __IO ONE_BIT  OT7  :  1; //!<[07] Port x configuration bit 7
      __IO ONE_BIT  OT8  :  1; //!<[08] Port x configuration bit 8
      __IO ONE_BIT  OT9  :  1; //!<[09] Port x configuration bit 9
      __IO ONE_BIT  OT10 :  1; //!<[10] Port x configuration bit 10
      __IO ONE_BIT  OT11 :  1; //!<[11] Port x configuration bit 11
      __IO ONE_BIT  OT12 :  1; //!<[12] Port x configuration bit 12
      __IO ONE_BIT  OT13 :  1; //!<[13] Port x configuration bit 13
      __IO ONE_BIT  OT14 :  1; //!<[14] Port x configuration bit 14
      __IO ONE_BIT  OT15 :  1; //!<[15] Port x configuration bit 15
    } B;
    __IO uint32_t  R;
    explicit OTYPER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      OTYPER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      OTYPER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union OSPEEDR_DEF {  //!< GPIO port output speed register
    struct {
      __IO uint32_t   OSPEEDR0  :  2; //!<[00] Port x configuration bits (y = 0..15)
      __IO uint32_t   OSPEEDR1  :  2; //!<[02] Port x configuration bits (y = 0..15)
      __IO uint32_t   OSPEEDR2  :  2; //!<[04] Port x configuration bits (y = 0..15)
      __IO uint32_t   OSPEEDR3  :  2; //!<[06] Port x configuration bits (y = 0..15)
      __IO uint32_t   OSPEEDR4  :  2; //!<[08] Port x configuration bits (y = 0..15)
      __IO uint32_t   OSPEEDR5  :  2; //!<[10] Port x configuration bits (y = 0..15)
      __IO uint32_t   OSPEEDR6  :  2; //!<[12] Port x configuration bits (y = 0..15)
      __IO uint32_t   OSPEEDR7  :  2; //!<[14] Port x configuration bits (y = 0..15)
      __IO uint32_t   OSPEEDR8  :  2; //!<[16] Port x configuration bits (y = 0..15)
      __IO uint32_t   OSPEEDR9  :  2; //!<[18] Port x configuration bits (y = 0..15)
      __IO uint32_t   OSPEEDR10 :  2; //!<[20] Port x configuration bits (y = 0..15)
      __IO uint32_t   OSPEEDR11 :  2; //!<[22] Port x configuration bits (y = 0..15)
      __IO uint32_t   OSPEEDR12 :  2; //!<[24] Port x configuration bits (y = 0..15)
      __IO uint32_t   OSPEEDR13 :  2; //!<[26] Port x configuration bits (y = 0..15)
      __IO uint32_t   OSPEEDR14 :  2; //!<[28] Port x configuration bits (y = 0..15)
      __IO uint32_t   OSPEEDR15 :  2; //!<[30] Port x configuration bits (y = 0..15)
    } B;
    __IO uint32_t  R;
    explicit OSPEEDR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      OSPEEDR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      OSPEEDR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union PUPDR_DEF   {  //!< GPIO port pull-up/pull-down register
    struct {
      __IO uint32_t   PUPDR0  :  2; //!<[00] Port x configuration bits (y = 0..15)
      __IO uint32_t   PUPDR1  :  2; //!<[02] Port x configuration bits (y = 0..15)
      __IO uint32_t   PUPDR2  :  2; //!<[04] Port x configuration bits (y = 0..15)
      __IO uint32_t   PUPDR3  :  2; //!<[06] Port x configuration bits (y = 0..15)
      __IO uint32_t   PUPDR4  :  2; //!<[08] Port x configuration bits (y = 0..15)
      __IO uint32_t   PUPDR5  :  2; //!<[10] Port x configuration bits (y = 0..15)
      __IO uint32_t   PUPDR6  :  2; //!<[12] Port x configuration bits (y = 0..15)
      __IO uint32_t   PUPDR7  :  2; //!<[14] Port x configuration bits (y = 0..15)
      __IO uint32_t   PUPDR8  :  2; //!<[16] Port x configuration bits (y = 0..15)
      __IO uint32_t   PUPDR9  :  2; //!<[18] Port x configuration bits (y = 0..15)
      __IO uint32_t   PUPDR10 :  2; //!<[20] Port x configuration bits (y = 0..15)
      __IO uint32_t   PUPDR11 :  2; //!<[22] Port x configuration bits (y = 0..15)
      __IO uint32_t   PUPDR12 :  2; //!<[24] Port x configuration bits (y = 0..15)
      __IO uint32_t   PUPDR13 :  2; //!<[26] Port x configuration bits (y = 0..15)
      __IO uint32_t   PUPDR14 :  2; //!<[28] Port x configuration bits (y = 0..15)
      __IO uint32_t   PUPDR15 :  2; //!<[30] Port x configuration bits (y = 0..15)
    } B;
    __IO uint32_t  R;
    explicit PUPDR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      PUPDR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      PUPDR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IDR_DEF     {  //!< GPIO port input data register
    struct {
      __I  ONE_BIT  IDR0  :  1; //!<[00] Port input data (y = 0..15)
      __I  ONE_BIT  IDR1  :  1; //!<[01] Port input data (y = 0..15)
      __I  ONE_BIT  IDR2  :  1; //!<[02] Port input data (y = 0..15)
      __I  ONE_BIT  IDR3  :  1; //!<[03] Port input data (y = 0..15)
      __I  ONE_BIT  IDR4  :  1; //!<[04] Port input data (y = 0..15)
      __I  ONE_BIT  IDR5  :  1; //!<[05] Port input data (y = 0..15)
      __I  ONE_BIT  IDR6  :  1; //!<[06] Port input data (y = 0..15)
      __I  ONE_BIT  IDR7  :  1; //!<[07] Port input data (y = 0..15)
      __I  ONE_BIT  IDR8  :  1; //!<[08] Port input data (y = 0..15)
      __I  ONE_BIT  IDR9  :  1; //!<[09] Port input data (y = 0..15)
      __I  ONE_BIT  IDR10 :  1; //!<[10] Port input data (y = 0..15)
      __I  ONE_BIT  IDR11 :  1; //!<[11] Port input data (y = 0..15)
      __I  ONE_BIT  IDR12 :  1; //!<[12] Port input data (y = 0..15)
      __I  ONE_BIT  IDR13 :  1; //!<[13] Port input data (y = 0..15)
      __I  ONE_BIT  IDR14 :  1; //!<[14] Port input data (y = 0..15)
      __I  ONE_BIT  IDR15 :  1; //!<[15] Port input data (y = 0..15)
    } B;
    __I  uint32_t  R;

    explicit IDR_DEF (volatile IDR_DEF & o) noexcept { R = o.R; };
  };
  union ODR_DEF     {  //!< GPIO port output data register
    struct {
      __IO ONE_BIT  ODR0  :  1; //!<[00] Port output data (y = 0..15)
      __IO ONE_BIT  ODR1  :  1; //!<[01] Port output data (y = 0..15)
      __IO ONE_BIT  ODR2  :  1; //!<[02] Port output data (y = 0..15)
      __IO ONE_BIT  ODR3  :  1; //!<[03] Port output data (y = 0..15)
      __IO ONE_BIT  ODR4  :  1; //!<[04] Port output data (y = 0..15)
      __IO ONE_BIT  ODR5  :  1; //!<[05] Port output data (y = 0..15)
      __IO ONE_BIT  ODR6  :  1; //!<[06] Port output data (y = 0..15)
      __IO ONE_BIT  ODR7  :  1; //!<[07] Port output data (y = 0..15)
      __IO ONE_BIT  ODR8  :  1; //!<[08] Port output data (y = 0..15)
      __IO ONE_BIT  ODR9  :  1; //!<[09] Port output data (y = 0..15)
      __IO ONE_BIT  ODR10 :  1; //!<[10] Port output data (y = 0..15)
      __IO ONE_BIT  ODR11 :  1; //!<[11] Port output data (y = 0..15)
      __IO ONE_BIT  ODR12 :  1; //!<[12] Port output data (y = 0..15)
      __IO ONE_BIT  ODR13 :  1; //!<[13] Port output data (y = 0..15)
      __IO ONE_BIT  ODR14 :  1; //!<[14] Port output data (y = 0..15)
      __IO ONE_BIT  ODR15 :  1; //!<[15] Port output data (y = 0..15)
    } B;
    __IO uint32_t  R;
    explicit ODR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ODR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ODR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union BSRR_DEF    {  //!< GPIO port bit set/reset register
    struct {
      __O  ONE_BIT  BS0  :  1; //!<[00] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BS1  :  1; //!<[01] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BS2  :  1; //!<[02] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BS3  :  1; //!<[03] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BS4  :  1; //!<[04] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BS5  :  1; //!<[05] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BS6  :  1; //!<[06] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BS7  :  1; //!<[07] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BS8  :  1; //!<[08] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BS9  :  1; //!<[09] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BS10 :  1; //!<[10] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BS11 :  1; //!<[11] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BS12 :  1; //!<[12] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BS13 :  1; //!<[13] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BS14 :  1; //!<[14] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BS15 :  1; //!<[15] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BR0  :  1; //!<[16] Port x set bit y (y= 0..15)
      __O  ONE_BIT  BR1  :  1; //!<[17] Port x reset bit y (y = 0..15)
      __O  ONE_BIT  BR2  :  1; //!<[18] Port x reset bit y (y = 0..15)
      __O  ONE_BIT  BR3  :  1; //!<[19] Port x reset bit y (y = 0..15)
      __O  ONE_BIT  BR4  :  1; //!<[20] Port x reset bit y (y = 0..15)
      __O  ONE_BIT  BR5  :  1; //!<[21] Port x reset bit y (y = 0..15)
      __O  ONE_BIT  BR6  :  1; //!<[22] Port x reset bit y (y = 0..15)
      __O  ONE_BIT  BR7  :  1; //!<[23] Port x reset bit y (y = 0..15)
      __O  ONE_BIT  BR8  :  1; //!<[24] Port x reset bit y (y = 0..15)
      __O  ONE_BIT  BR9  :  1; //!<[25] Port x reset bit y (y = 0..15)
      __O  ONE_BIT  BR10 :  1; //!<[26] Port x reset bit y (y = 0..15)
      __O  ONE_BIT  BR11 :  1; //!<[27] Port x reset bit y (y = 0..15)
      __O  ONE_BIT  BR12 :  1; //!<[28] Port x reset bit y (y = 0..15)
      __O  ONE_BIT  BR13 :  1; //!<[29] Port x reset bit y (y = 0..15)
      __O  ONE_BIT  BR14 :  1; //!<[30] Port x reset bit y (y = 0..15)
      __O  ONE_BIT  BR15 :  1; //!<[31] Port x reset bit y (y = 0..15)
    } B;
    __O  uint32_t  R;
    explicit BSRR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      BSRR_DEF r;
      R = f (r);
    }
  };
  union LCKR_DEF    {  //!< GPIO port configuration lock register
    struct {
      __IO ONE_BIT  LCK0  :  1; //!<[00] Port x lock bit y (y= 0..15)
      __IO ONE_BIT  LCK1  :  1; //!<[01] Port x lock bit y (y= 0..15)
      __IO ONE_BIT  LCK2  :  1; //!<[02] Port x lock bit y (y= 0..15)
      __IO ONE_BIT  LCK3  :  1; //!<[03] Port x lock bit y (y= 0..15)
      __IO ONE_BIT  LCK4  :  1; //!<[04] Port x lock bit y (y= 0..15)
      __IO ONE_BIT  LCK5  :  1; //!<[05] Port x lock bit y (y= 0..15)
      __IO ONE_BIT  LCK6  :  1; //!<[06] Port x lock bit y (y= 0..15)
      __IO ONE_BIT  LCK7  :  1; //!<[07] Port x lock bit y (y= 0..15)
      __IO ONE_BIT  LCK8  :  1; //!<[08] Port x lock bit y (y= 0..15)
      __IO ONE_BIT  LCK9  :  1; //!<[09] Port x lock bit y (y= 0..15)
      __IO ONE_BIT  LCK10 :  1; //!<[10] Port x lock bit y (y= 0..15)
      __IO ONE_BIT  LCK11 :  1; //!<[11] Port x lock bit y (y= 0..15)
      __IO ONE_BIT  LCK12 :  1; //!<[12] Port x lock bit y (y= 0..15)
      __IO ONE_BIT  LCK13 :  1; //!<[13] Port x lock bit y (y= 0..15)
      __IO ONE_BIT  LCK14 :  1; //!<[14] Port x lock bit y (y= 0..15)
      __IO ONE_BIT  LCK15 :  1; //!<[15] Port x lock bit y (y= 0..15)
      __IO ONE_BIT  LCKK  :  1; //!<[16] Port x lock bit y
    } B;
    __IO uint32_t  R;
    explicit LCKR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      LCKR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      LCKR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union AFRL_DEF    {  //!< GPIO alternate function low register
    struct {
      __IO uint32_t   AFRL0 :  4; //!<[00] Alternate function selection for port x bit y (y = 0..7)
      __IO uint32_t   AFRL1 :  4; //!<[04] Alternate function selection for port x bit y (y = 0..7)
      __IO uint32_t   AFRL2 :  4; //!<[08] Alternate function selection for port x bit y (y = 0..7)
      __IO uint32_t   AFRL3 :  4; //!<[12] Alternate function selection for port x bit y (y = 0..7)
      __IO uint32_t   AFRL4 :  4; //!<[16] Alternate function selection for port x bit y (y = 0..7)
      __IO uint32_t   AFRL5 :  4; //!<[20] Alternate function selection for port x bit y (y = 0..7)
      __IO uint32_t   AFRL6 :  4; //!<[24] Alternate function selection for port x bit y (y = 0..7)
      __IO uint32_t   AFRL7 :  4; //!<[28] Alternate function selection for port x bit y (y = 0..7)
    } B;
    __IO uint32_t  R;
    explicit AFRL_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      AFRL_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      AFRL_DEF r; r.R = R;
      R = f (r);
    }
  };
  union AFRH_DEF    {  //!< GPIO alternate function high register
    struct {
      __IO uint32_t   AFRH8  :  4; //!<[00] Alternate function selection for port x bit y (y = 8..15)
      __IO uint32_t   AFRH9  :  4; //!<[04] Alternate function selection for port x bit y (y = 8..15)
      __IO uint32_t   AFRH10 :  4; //!<[08] Alternate function selection for port x bit y (y = 8..15)
      __IO uint32_t   AFRH11 :  4; //!<[12] Alternate function selection for port x bit y (y = 8..15)
      __IO uint32_t   AFRH12 :  4; //!<[16] Alternate function selection for port x bit y (y = 8..15)
      __IO uint32_t   AFRH13 :  4; //!<[20] Alternate function selection for port x bit y (y = 8..15)
      __IO uint32_t   AFRH14 :  4; //!<[24] Alternate function selection for port x bit y (y = 8..15)
      __IO uint32_t   AFRH15 :  4; //!<[28] Alternate function selection for port x bit y (y = 8..15)
    } B;
    __IO uint32_t  R;
    explicit AFRH_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      AFRH_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      AFRH_DEF r; r.R = R;
      R = f (r);
    }
  };
  union BRR_DEF     {  //!< Port bit reset register
    struct {
      __O  ONE_BIT  BR0  :  1; //!<[00] Port x Reset bit y
      __O  ONE_BIT  BR1  :  1; //!<[01] Port x Reset bit y
      __O  ONE_BIT  BR2  :  1; //!<[02] Port x Reset bit y
      __O  ONE_BIT  BR3  :  1; //!<[03] Port x Reset bit y
      __O  ONE_BIT  BR4  :  1; //!<[04] Port x Reset bit y
      __O  ONE_BIT  BR5  :  1; //!<[05] Port x Reset bit y
      __O  ONE_BIT  BR6  :  1; //!<[06] Port x Reset bit y
      __O  ONE_BIT  BR7  :  1; //!<[07] Port x Reset bit y
      __O  ONE_BIT  BR8  :  1; //!<[08] Port x Reset bit y
      __O  ONE_BIT  BR9  :  1; //!<[09] Port x Reset bit y
      __O  ONE_BIT  BR10 :  1; //!<[10] Port x Reset bit y
      __O  ONE_BIT  BR11 :  1; //!<[11] Port x Reset bit y
      __O  ONE_BIT  BR12 :  1; //!<[12] Port x Reset bit y
      __O  ONE_BIT  BR13 :  1; //!<[13] Port x Reset bit y
      __O  ONE_BIT  BR14 :  1; //!<[14] Port x Reset bit y
      __O  ONE_BIT  BR15 :  1; //!<[15] Port x Reset bit y
    } B;
    __O  uint32_t  R;
    explicit BRR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      BRR_DEF r;
      R = f (r);
    }
  };
  // PERIPHERAL GPIOF REGISTERS INSTANCES
  __IO MODER_DEF             MODER ;  //!< [0000](04)[0x00000000]
  __IO OTYPER_DEF           OTYPER ;  //!< [0004](04)[0x00000000]
  __IO OSPEEDR_DEF         OSPEEDR ;  //!< [0008](04)[0x00000000]
  __IO PUPDR_DEF             PUPDR ;  //!< [000c](04)[0x00000000]
  __I  IDR_DEF                 IDR ;  //!< [0010](04)[0x00000000]
  __IO ODR_DEF                 ODR ;  //!< [0014](04)[0x00000000]
  __O  BSRR_DEF               BSRR ;  //!< [0018](04)[0x00000000]
  __IO LCKR_DEF               LCKR ;  //!< [001c](04)[0x00000000]
  __IO AFRL_DEF               AFRL ;  //!< [0020](04)[0x00000000]
  __IO AFRH_DEF               AFRH ;  //!< [0024](04)[0x00000000]
  __O  BRR_DEF                 BRR ;  //!< [0028](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x002C */

// ////////////////////+++ SPI1 +-+//////////////////// //
struct SPI1_Type        { /*!< Serial peripheral interface */
  union CR1_DEF     {  //!< control register 1
    struct {
      __IO ONE_BIT    CPHA     :  1; //!<[00] Clock phase
      __IO ONE_BIT    CPOL     :  1; //!<[01] Clock polarity
      __IO ONE_BIT    MSTR     :  1; //!<[02] Master selection
      __IO uint32_t   BR       :  3; //!<[03] Baud rate control
      __IO ONE_BIT    SPE      :  1; //!<[06] SPI enable
      __IO ONE_BIT    LSBFIRST :  1; //!<[07] Frame format
      __IO ONE_BIT    SSI      :  1; //!<[08] Internal slave select
      __IO ONE_BIT    SSM      :  1; //!<[09] Software slave management
      __IO ONE_BIT    RXONLY   :  1; //!<[10] Receive only
      __IO ONE_BIT    DFF      :  1; //!<[11] Data frame format
      __IO ONE_BIT    CRCNEXT  :  1; //!<[12] CRC transfer next
      __IO ONE_BIT    CRCEN    :  1; //!<[13] Hardware CRC calculation enable
      __IO ONE_BIT    BIDIOE   :  1; //!<[14] Output enable in bidirectional mode
      __IO ONE_BIT    BIDIMODE :  1; //!<[15] Bidirectional data mode enable
    } B;
    __IO uint32_t  R;
    explicit CR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CR2_DEF     {  //!< control register 2
    struct {
      __IO ONE_BIT    RXDMAEN :  1; //!<[00] Rx buffer DMA enable
      __IO ONE_BIT    TXDMAEN :  1; //!<[01] Tx buffer DMA enable
      __IO ONE_BIT    SSOE    :  1; //!<[02] SS output enable
      __IO ONE_BIT    NSSP    :  1; //!<[03] NSS pulse management
      __IO ONE_BIT    FRF     :  1; //!<[04] Frame format
      __IO ONE_BIT    ERRIE   :  1; //!<[05] Error interrupt enable
      __IO ONE_BIT    RXNEIE  :  1; //!<[06] RX buffer not empty interrupt enable
      __IO ONE_BIT    TXEIE   :  1; //!<[07] Tx buffer empty interrupt enable
      __IO uint32_t   DS      :  4; //!<[08] Data size
      __IO ONE_BIT    FRXTH   :  1; //!<[12] FIFO reception threshold
      __IO ONE_BIT    LDMA_RX :  1; //!<[13] Last DMA transfer for reception
      __IO ONE_BIT    LDMA_TX :  1; //!<[14] Last DMA transfer for transmission
    } B;
    __IO uint32_t  R;
    explicit CR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SR_DEF      {  //!< status register
    struct {
      __I  ONE_BIT    RXNE   :  1; //!<[00] Receive buffer not empty
      __I  ONE_BIT    TXE    :  1; //!<[01] Transmit buffer empty
      __I  ONE_BIT    CHSIDE :  1; //!<[02] Channel side
      __I  ONE_BIT    UDR    :  1; //!<[03] Underrun flag
      __IO ONE_BIT    CRCERR :  1; //!<[04] CRC error flag
      __I  ONE_BIT    MODF   :  1; //!<[05] Mode fault
      __I  ONE_BIT    OVR    :  1; //!<[06] Overrun flag
      __I  ONE_BIT    BSY    :  1; //!<[07] Busy flag
      __I  ONE_BIT    TIFRFE :  1; //!<[08] TI frame format error
      __I  uint32_t   FRLVL  :  2; //!<[09] FIFO reception level
      __I  uint32_t   FTLVL  :  2; //!<[11] FIFO transmission level
    } B;
    __IO uint32_t  R;
    explicit SR_DEF () noexcept { R = 0x00000002u; }
    template<typename F> void setbit (F f) volatile {
      SR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DR_DEF      {  //!< data register
    struct {
      __IO uint32_t   DR : 16; //!<[00] Data register
    } B;
    __IO uint32_t  R;
    explicit DR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CRCPR_DEF   {  //!< CRC polynomial register
    struct {
      __IO uint32_t   CRCPOLY : 16; //!<[00] CRC polynomial register
    } B;
    __IO uint32_t  R;
    explicit CRCPR_DEF () noexcept { R = 0x00000007u; }
    template<typename F> void setbit (F f) volatile {
      CRCPR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CRCPR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union RXCRCR_DEF  {  //!< RX CRC register
    struct {
      __I  uint32_t   RxCRC : 16; //!<[00] Rx CRC register
    } B;
    __I  uint32_t  R;

    explicit RXCRCR_DEF (volatile RXCRCR_DEF & o) noexcept { R = o.R; };
  };
  union TXCRCR_DEF  {  //!< TX CRC register
    struct {
      __I  uint32_t   TxCRC : 16; //!<[00] Tx CRC register
    } B;
    __I  uint32_t  R;

    explicit TXCRCR_DEF (volatile TXCRCR_DEF & o) noexcept { R = o.R; };
  };
  union I2SCFGR_DEF {  //!< I2S configuration register
    struct {
      __IO ONE_BIT    CHLEN   :  1; //!<[00] Channel length (number of bits per audio channel)
      __IO uint32_t   DATLEN  :  2; //!<[01] Data length to be transferred
      __IO ONE_BIT    CKPOL   :  1; //!<[03] Steady state clock polarity
      __IO uint32_t   I2SSTD  :  2; //!<[04] I2S standard selection
           ONE_BIT    UNUSED0 :  1; //!<[06] 
      __IO ONE_BIT    PCMSYNC :  1; //!<[07] PCM frame synchronization
      __IO uint32_t   I2SCFG  :  2; //!<[08] I2S configuration mode
      __IO ONE_BIT    I2SE    :  1; //!<[10] I2S Enable
      __IO ONE_BIT    I2SMOD  :  1; //!<[11] I2S mode selection
    } B;
    __IO uint32_t  R;
    explicit I2SCFGR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      I2SCFGR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      I2SCFGR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union I2SPR_DEF   {  //!< I2S prescaler register
    struct {
      __IO uint32_t   I2SDIV :  8; //!<[00] I2S Linear prescaler
      __IO ONE_BIT    ODD    :  1; //!<[08] Odd factor for the prescaler
      __IO ONE_BIT    MCKOE  :  1; //!<[09] Master clock output enable
    } B;
    __IO uint32_t  R;
    explicit I2SPR_DEF () noexcept { R = 0x00000010u; }
    template<typename F> void setbit (F f) volatile {
      I2SPR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      I2SPR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL SPI1 REGISTERS INSTANCES
  __IO CR1_DEF                 CR1 ;  //!< [0000](04)[0x00000000]
  __IO CR2_DEF                 CR2 ;  //!< [0004](04)[0x00000000]
  __IO SR_DEF                   SR ;  //!< [0008](04)[0x00000002]
  __IO DR_DEF                   DR ;  //!< [000c](04)[0x00000000]
  __IO CRCPR_DEF             CRCPR ;  //!< [0010](04)[0x00000007]
  __I  RXCRCR_DEF           RXCRCR ;  //!< [0014](04)[0x00000000]
  __I  TXCRCR_DEF           TXCRCR ;  //!< [0018](04)[0x00000000]
  __IO I2SCFGR_DEF         I2SCFGR ;  //!< [001c](04)[0x00000000]
  __IO I2SPR_DEF             I2SPR ;  //!< [0020](04)[0x00000010]
}; /* total size = 0x0400, struct size = 0x0024 */

// ////////////////////+++ PWR +-+//////////////////// //
struct PWR_Type         { /*!< Power control */
  union CR_DEF  {  //!< power control register
    struct {
      __IO ONE_BIT    LPDS :  1; //!<[00] Low-power deep sleep
      __IO ONE_BIT    PDDS :  1; //!<[01] Power down deepsleep
      __IO ONE_BIT    CWUF :  1; //!<[02] Clear wakeup flag
      __IO ONE_BIT    CSBF :  1; //!<[03] Clear standby flag
      __IO ONE_BIT    PVDE :  1; //!<[04] Power voltage detector enable
      __IO uint32_t   PLS  :  3; //!<[05] PVD level selection
      __IO ONE_BIT    DBP  :  1; //!<[08] Disable backup domain write protection
    } B;
    __IO uint32_t  R;
    explicit CR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CSR_DEF {  //!< power control/status register
    struct {
      __I  ONE_BIT    WUF        :  1; //!<[00] Wakeup flag
      __I  ONE_BIT    SBF        :  1; //!<[01] Standby flag
      __I  ONE_BIT    PVDO       :  1; //!<[02] PVD output
      __I  ONE_BIT    VREFINTRDY :  1; //!<[03] VREFINT reference voltage ready
           uint32_t   UNUSED0    :  4; //!<[04] 
      __IO ONE_BIT    EWUP1      :  1; //!<[08] Enable WKUP pin 1
      __IO ONE_BIT    EWUP2      :  1; //!<[09] Enable WKUP pin 2
      __IO ONE_BIT    EWUP3      :  1; //!<[10] Enable WKUP pin 3
      __IO ONE_BIT    EWUP4      :  1; //!<[11] Enable WKUP pin 4
      __IO ONE_BIT    EWUP5      :  1; //!<[12] Enable WKUP pin 5
      __IO ONE_BIT    EWUP6      :  1; //!<[13] Enable WKUP pin 6
      __IO ONE_BIT    EWUP7      :  1; //!<[14] Enable WKUP pin 7
      __IO ONE_BIT    EWUP8      :  1; //!<[15] Enable WKUP pin 8
    } B;
    __IO uint32_t  R;
    explicit CSR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CSR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CSR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL PWR REGISTERS INSTANCES
  __IO CR_DEF               CR ;  //!< [0000](04)[0x00000000]
  __IO CSR_DEF             CSR ;  //!< [0004](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x0008 */

// ////////////////////+++ I2C1 +-+//////////////////// //
struct I2C1_Type        { /*!< Inter-integrated circuit */
  union CR1_DEF      {  //!< Control register 1
    struct {
      __IO ONE_BIT    PE        :  1; //!<[00] Peripheral enable
      __IO ONE_BIT    TXIE      :  1; //!<[01] TX Interrupt enable
      __IO ONE_BIT    RXIE      :  1; //!<[02] RX Interrupt enable
      __IO ONE_BIT    ADDRIE    :  1; //!<[03] Address match interrupt enable (slave only)
      __IO ONE_BIT    NACKIE    :  1; //!<[04] Not acknowledge received interrupt enable
      __IO ONE_BIT    STOPIE    :  1; //!<[05] STOP detection Interrupt enable
      __IO ONE_BIT    TCIE      :  1; //!<[06] Transfer Complete interrupt enable
      __IO ONE_BIT    ERRIE     :  1; //!<[07] Error interrupts enable
      __IO uint32_t   DNF       :  4; //!<[08] Digital noise filter
      __IO ONE_BIT    ANFOFF    :  1; //!<[12] Analog noise filter OFF
      __O  ONE_BIT    SWRST     :  1; //!<[13] Software reset
      __IO ONE_BIT    TXDMAEN   :  1; //!<[14] DMA transmission requests enable
      __IO ONE_BIT    RXDMAEN   :  1; //!<[15] DMA reception requests enable
      __IO ONE_BIT    SBC       :  1; //!<[16] Slave byte control
      __IO ONE_BIT    NOSTRETCH :  1; //!<[17] Clock stretching disable
      __IO ONE_BIT    WUPEN     :  1; //!<[18] Wakeup from STOP enable
      __IO ONE_BIT    GCEN      :  1; //!<[19] General call enable
      __IO ONE_BIT    SMBHEN    :  1; //!<[20] SMBus Host address enable
      __IO ONE_BIT    SMBDEN    :  1; //!<[21] SMBus Device Default address enable
      __IO ONE_BIT    ALERTEN   :  1; //!<[22] SMBUS alert enable
      __IO ONE_BIT    PECEN     :  1; //!<[23] PEC enable
    } B;
    __IO uint32_t  R;
    explicit CR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CR2_DEF      {  //!< Control register 2
    struct {
      __IO ONE_BIT    SADD0   :  1; //!<[00] Slave address bit 0 (master mode)
      __IO uint32_t   SADD1   :  7; //!<[01] Slave address bit 7:1 (master mode)
      __IO uint32_t   SADD8   :  2; //!<[08] Slave address bit 9:8 (master mode)
      __IO ONE_BIT    RD_WRN  :  1; //!<[10] Transfer direction (master mode)
      __IO ONE_BIT    ADD10   :  1; //!<[11] 10-bit addressing mode (master mode)
      __IO ONE_BIT    HEAD10R :  1; //!<[12] 10-bit address header only read direction (master receiver mode)
      __IO ONE_BIT    START   :  1; //!<[13] Start generation
      __IO ONE_BIT    STOP    :  1; //!<[14] Stop generation (master mode)
      __IO ONE_BIT    NACK    :  1; //!<[15] NACK generation (slave mode)
      __IO uint32_t   NBYTES  :  8; //!<[16] Number of bytes
      __IO ONE_BIT    RELOAD  :  1; //!<[24] NBYTES reload mode
      __IO ONE_BIT    AUTOEND :  1; //!<[25] Automatic end mode (master mode)
      __IO ONE_BIT    PECBYTE :  1; //!<[26] Packet error checking byte
    } B;
    __IO uint32_t  R;
    explicit CR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union OAR1_DEF     {  //!< Own address register 1
    struct {
      __IO ONE_BIT    OA1_0   :  1; //!<[00] Interface address
      __IO uint32_t   OA1_1   :  7; //!<[01] Interface address
      __IO uint32_t   OA1_8   :  2; //!<[08] Interface address
      __IO ONE_BIT    OA1MODE :  1; //!<[10] Own Address 1 10-bit mode
           uint32_t   UNUSED0 :  4; //!<[11] 
      __IO ONE_BIT    OA1EN   :  1; //!<[15] Own Address 1 enable
    } B;
    __IO uint32_t  R;
    explicit OAR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      OAR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      OAR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union OAR2_DEF     {  //!< Own address register 2
    struct {
           ONE_BIT    UNUSED0 :  1; //!<[00] 
      __IO uint32_t   OA2     :  7; //!<[01] Interface address
      __IO uint32_t   OA2MSK  :  3; //!<[08] Own Address 2 masks
           uint32_t   UNUSED1 :  4; //!<[11] 
      __IO ONE_BIT    OA2EN   :  1; //!<[15] Own Address 2 enable
    } B;
    __IO uint32_t  R;
    explicit OAR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      OAR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      OAR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union TIMINGR_DEF  {  //!< Timing register
    struct {
      __IO uint32_t   SCLL    :  8; //!<[00] SCL low period (master mode)
      __IO uint32_t   SCLH    :  8; //!<[08] SCL high period (master mode)
      __IO uint32_t   SDADEL  :  4; //!<[16] Data hold time
      __IO uint32_t   SCLDEL  :  4; //!<[20] Data setup time
           uint32_t   UNUSED0 :  4; //!<[24] 
      __IO uint32_t   PRESC   :  4; //!<[28] Timing prescaler
    } B;
    __IO uint32_t  R;
    explicit TIMINGR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      TIMINGR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      TIMINGR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union TIMEOUTR_DEF {  //!< Status register 1
    struct {
      __IO uint32_t   TIMEOUTA : 12; //!<[00] Bus timeout A
      __IO ONE_BIT    TIDLE    :  1; //!<[12] Idle clock timeout detection
           uint32_t   UNUSED0  :  2; //!<[13] 
      __IO ONE_BIT    TIMOUTEN :  1; //!<[15] Clock timeout enable
      __IO uint32_t   TIMEOUTB : 12; //!<[16] Bus timeout B
           uint32_t   UNUSED1  :  3; //!<[28] 
      __IO ONE_BIT    TEXTEN   :  1; //!<[31] Extended clock timeout enable
    } B;
    __IO uint32_t  R;
    explicit TIMEOUTR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      TIMEOUTR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      TIMEOUTR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ISR_DEF      {  //!< Interrupt and Status register
    struct {
      __IO ONE_BIT    TXE     :  1; //!<[00] Transmit data register empty (transmitters)
      __IO ONE_BIT    TXIS    :  1; //!<[01] Transmit interrupt status (transmitters)
      __I  ONE_BIT    RXNE    :  1; //!<[02] Receive data register not empty (receivers)
      __I  ONE_BIT    ADDR    :  1; //!<[03] Address matched (slave mode)
      __I  ONE_BIT    NACKF   :  1; //!<[04] Not acknowledge received flag
      __I  ONE_BIT    STOPF   :  1; //!<[05] Stop detection flag
      __I  ONE_BIT    TC      :  1; //!<[06] Transfer Complete (master mode)
      __I  ONE_BIT    TCR     :  1; //!<[07] Transfer Complete Reload
      __I  ONE_BIT    BERR    :  1; //!<[08] Bus error
      __I  ONE_BIT    ARLO    :  1; //!<[09] Arbitration lost
      __I  ONE_BIT    OVR     :  1; //!<[10] Overrun/Underrun (slave mode)
      __I  ONE_BIT    PECERR  :  1; //!<[11] PEC Error in reception
      __I  ONE_BIT    TIMEOUT :  1; //!<[12] Timeout or t_low detection flag
      __I  ONE_BIT    ALERT   :  1; //!<[13] SMBus alert
           ONE_BIT    UNUSED0 :  1; //!<[14] 
      __I  ONE_BIT    BUSY    :  1; //!<[15] Bus busy
      __I  ONE_BIT    DIR     :  1; //!<[16] Transfer direction (Slave mode)
      __I  uint32_t   ADDCODE :  7; //!<[17] Address match code (Slave mode)
    } B;
    __IO uint32_t  R;
    explicit ISR_DEF () noexcept { R = 0x00000001u; }
    template<typename F> void setbit (F f) volatile {
      ISR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ISR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ICR_DEF      {  //!< Interrupt clear register
    struct {
           uint32_t   UNUSED0  :  3; //!<[00] 
      __O  ONE_BIT    ADDRCF   :  1; //!<[03] Address Matched flag clear
      __O  ONE_BIT    NACKCF   :  1; //!<[04] Not Acknowledge flag clear
      __O  ONE_BIT    STOPCF   :  1; //!<[05] Stop detection flag clear
           uint32_t   UNUSED1  :  2; //!<[06] 
      __O  ONE_BIT    BERRCF   :  1; //!<[08] Bus error flag clear
      __O  ONE_BIT    ARLOCF   :  1; //!<[09] Arbitration lost flag clear
      __O  ONE_BIT    OVRCF    :  1; //!<[10] Overrun/Underrun flag clear
      __O  ONE_BIT    PECCF    :  1; //!<[11] PEC Error flag clear
      __O  ONE_BIT    TIMOUTCF :  1; //!<[12] Timeout detection flag clear
      __O  ONE_BIT    ALERTCF  :  1; //!<[13] Alert flag clear
    } B;
    __O  uint32_t  R;
    explicit ICR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ICR_DEF r;
      R = f (r);
    }
  };
  union PECR_DEF     {  //!< PEC register
    struct {
      __I  uint32_t   PEC :  8; //!<[00] Packet error checking register
    } B;
    __I  uint32_t  R;

    explicit PECR_DEF (volatile PECR_DEF & o) noexcept { R = o.R; };
  };
  union RXDR_DEF     {  //!< Receive data register
    struct {
      __I  uint32_t   RXDATA :  8; //!<[00] 8-bit receive data
    } B;
    __I  uint32_t  R;

    explicit RXDR_DEF (volatile RXDR_DEF & o) noexcept { R = o.R; };
  };
  union TXDR_DEF     {  //!< Transmit data register
    struct {
      __IO uint32_t   TXDATA :  8; //!<[00] 8-bit transmit data
    } B;
    __IO uint32_t  R;
    explicit TXDR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      TXDR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      TXDR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL I2C1 REGISTERS INSTANCES
  __IO CR1_DEF                  CR1 ;  //!< [0000](04)[0x00000000]
  __IO CR2_DEF                  CR2 ;  //!< [0004](04)[0x00000000]
  __IO OAR1_DEF                OAR1 ;  //!< [0008](04)[0x00000000]
  __IO OAR2_DEF                OAR2 ;  //!< [000c](04)[0x00000000]
  __IO TIMINGR_DEF          TIMINGR ;  //!< [0010](04)[0x00000000]
  __IO TIMEOUTR_DEF        TIMEOUTR ;  //!< [0014](04)[0x00000000]
  __IO ISR_DEF                  ISR ;  //!< [0018](04)[0x00000001]
  __O  ICR_DEF                  ICR ;  //!< [001c](04)[0x00000000]
  __I  PECR_DEF                PECR ;  //!< [0020](04)[0x00000000]
  __I  RXDR_DEF                RXDR ;  //!< [0024](04)[0x00000000]
  __IO TXDR_DEF                TXDR ;  //!< [0028](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x002C */

// ////////////////////+++ IWDG +-+//////////////////// //
struct IWDG_Type        { /*!< Independent watchdog */
  union KR_DEF   {  //!< Key register
    struct {
      __O  uint32_t   KEY : 16; //!<[00] Key value
    } B;
    __O  uint32_t  R;
    explicit KR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      KR_DEF r;
      R = f (r);
    }
  };
  union PR_DEF   {  //!< Prescaler register
    struct {
      __IO uint32_t   PR :  3; //!<[00] Prescaler divider
    } B;
    __IO uint32_t  R;
    explicit PR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      PR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      PR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union RLR_DEF  {  //!< Reload register
    struct {
      __IO uint32_t   RL : 12; //!<[00] Watchdog counter reload value
    } B;
    __IO uint32_t  R;
    explicit RLR_DEF () noexcept { R = 0x00000fffu; }
    template<typename F> void setbit (F f) volatile {
      RLR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      RLR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SR_DEF   {  //!< Status register
    struct {
      __I  ONE_BIT  PVU :  1; //!<[00] Watchdog prescaler value update
      __I  ONE_BIT  RVU :  1; //!<[01] Watchdog counter reload value update
      __I  ONE_BIT  WVU :  1; //!<[02] Watchdog counter window value update
    } B;
    __I  uint32_t  R;

    explicit SR_DEF (volatile SR_DEF & o) noexcept { R = o.R; };
  };
  union WINR_DEF {  //!< Window register
    struct {
      __IO uint32_t   WIN : 12; //!<[00] Watchdog counter window value
    } B;
    __IO uint32_t  R;
    explicit WINR_DEF () noexcept { R = 0x00000fffu; }
    template<typename F> void setbit (F f) volatile {
      WINR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      WINR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL IWDG REGISTERS INSTANCES
  __O  KR_DEF                KR ;  //!< [0000](04)[0x00000000]
  __IO PR_DEF                PR ;  //!< [0004](04)[0x00000000]
  __IO RLR_DEF              RLR ;  //!< [0008](04)[0x00000FFF]
  __I  SR_DEF                SR ;  //!< [000c](04)[0x00000000]
  __IO WINR_DEF            WINR ;  //!< [0010](04)[0x00000FFF]
}; /* total size = 0x0400, struct size = 0x0014 */

// ////////////////////+++ WWDG +-+//////////////////// //
struct WWDG_Type        { /*!< Window watchdog */
  union CR_DEF  {  //!< Control register
    struct {
      __IO uint32_t   T    :  7; //!<[00] 7-bit counter
      __IO ONE_BIT    WDGA :  1; //!<[07] Activation bit
    } B;
    __IO uint32_t  R;
    explicit CR_DEF () noexcept { R = 0x0000007fu; }
    template<typename F> void setbit (F f) volatile {
      CR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CFR_DEF {  //!< Configuration register
    struct {
      __IO uint32_t   W     :  7; //!<[00] 7-bit window value
      __IO uint32_t   WDGTB :  2; //!<[07] Timer base
      __IO ONE_BIT    EWI   :  1; //!<[09] Early wakeup interrupt
    } B;
    __IO uint32_t  R;
    explicit CFR_DEF () noexcept { R = 0x0000007fu; }
    template<typename F> void setbit (F f) volatile {
      CFR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CFR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SR_DEF  {  //!< Status register
    struct {
      __IO ONE_BIT  EWIF :  1; //!<[00] Early wakeup interrupt flag
    } B;
    __IO uint32_t  R;
    explicit SR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL WWDG REGISTERS INSTANCES
  __IO CR_DEF               CR ;  //!< [0000](04)[0x0000007F]
  __IO CFR_DEF             CFR ;  //!< [0004](04)[0x0000007F]
  __IO SR_DEF               SR ;  //!< [0008](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x000C */

// ////////////////////+++ TIM1 +-+//////////////////// //
struct TIM1_Type        { /*!< Advanced-timers */
  union CR1_DEF         {  //!< control register 1
    struct {
      __IO ONE_BIT    CEN  :  1; //!<[00] Counter enable
      __IO ONE_BIT    UDIS :  1; //!<[01] Update disable
      __IO ONE_BIT    URS  :  1; //!<[02] Update request source
      __IO ONE_BIT    OPM  :  1; //!<[03] One-pulse mode
      __IO ONE_BIT    DIR  :  1; //!<[04] Direction
      __IO uint32_t   CMS  :  2; //!<[05] Center-aligned mode selection
      __IO ONE_BIT    ARPE :  1; //!<[07] Auto-reload preload enable
      __IO uint32_t   CKD  :  2; //!<[08] Clock division
    } B;
    __IO uint32_t  R;
    explicit CR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CR2_DEF         {  //!< control register 2
    struct {
      __IO ONE_BIT    CCPC    :  1; //!<[00] Capture/compare preloaded control
           ONE_BIT    UNUSED0 :  1; //!<[01] 
      __IO ONE_BIT    CCUS    :  1; //!<[02] Capture/compare control update selection
      __IO ONE_BIT    CCDS    :  1; //!<[03] Capture/compare DMA selection
      __IO uint32_t   MMS     :  3; //!<[04] Master mode selection
      __IO ONE_BIT    TI1S    :  1; //!<[07] TI1 selection
      __IO ONE_BIT    OIS1    :  1; //!<[08] Output Idle state 1
      __IO ONE_BIT    OIS1N   :  1; //!<[09] Output Idle state 1
      __IO ONE_BIT    OIS2    :  1; //!<[10] Output Idle state 2
      __IO ONE_BIT    OIS2N   :  1; //!<[11] Output Idle state 2
      __IO ONE_BIT    OIS3    :  1; //!<[12] Output Idle state 3
      __IO ONE_BIT    OIS3N   :  1; //!<[13] Output Idle state 3
      __IO ONE_BIT    OIS4    :  1; //!<[14] Output Idle state 4
    } B;
    __IO uint32_t  R;
    explicit CR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SMCR_DEF        {  //!< slave mode control register
    struct {
      __IO uint32_t   SMS     :  3; //!<[00] Slave mode selection
           ONE_BIT    UNUSED0 :  1; //!<[03] 
      __IO uint32_t   TS      :  3; //!<[04] Trigger selection
      __IO ONE_BIT    MSM     :  1; //!<[07] Master/Slave mode
      __IO uint32_t   ETF     :  4; //!<[08] External trigger filter
      __IO uint32_t   ETPS    :  2; //!<[12] External trigger prescaler
      __IO ONE_BIT    ECE     :  1; //!<[14] External clock enable
      __IO ONE_BIT    ETP     :  1; //!<[15] External trigger polarity
    } B;
    __IO uint32_t  R;
    explicit SMCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SMCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SMCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DIER_DEF        {  //!< DMA/Interrupt enable register
    struct {
      __IO ONE_BIT  UIE   :  1; //!<[00] Update interrupt enable
      __IO ONE_BIT  CC1IE :  1; //!<[01] Capture/Compare 1 interrupt enable
      __IO ONE_BIT  CC2IE :  1; //!<[02] Capture/Compare 2 interrupt enable
      __IO ONE_BIT  CC3IE :  1; //!<[03] Capture/Compare 3 interrupt enable
      __IO ONE_BIT  CC4IE :  1; //!<[04] Capture/Compare 4 interrupt enable
      __IO ONE_BIT  COMIE :  1; //!<[05] COM interrupt enable
      __IO ONE_BIT  TIE   :  1; //!<[06] Trigger interrupt enable
      __IO ONE_BIT  BIE   :  1; //!<[07] Break interrupt enable
      __IO ONE_BIT  UDE   :  1; //!<[08] Update DMA request enable
      __IO ONE_BIT  CC1DE :  1; //!<[09] Capture/Compare 1 DMA request enable
      __IO ONE_BIT  CC2DE :  1; //!<[10] Capture/Compare 2 DMA request enable
      __IO ONE_BIT  CC3DE :  1; //!<[11] Capture/Compare 3 DMA request enable
      __IO ONE_BIT  CC4DE :  1; //!<[12] Capture/Compare 4 DMA request enable
      __IO ONE_BIT  COMDE :  1; //!<[13] COM DMA request enable
      __IO ONE_BIT  TDE   :  1; //!<[14] Trigger DMA request enable
    } B;
    __IO uint32_t  R;
    explicit DIER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DIER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DIER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SR_DEF          {  //!< status register
    struct {
      __IO ONE_BIT  UIF     :  1; //!<[00] Update interrupt flag
      __IO ONE_BIT  CC1IF   :  1; //!<[01] Capture/compare 1 interrupt flag
      __IO ONE_BIT  CC2IF   :  1; //!<[02] Capture/Compare 2 interrupt flag
      __IO ONE_BIT  CC3IF   :  1; //!<[03] Capture/Compare 3 interrupt flag
      __IO ONE_BIT  CC4IF   :  1; //!<[04] Capture/Compare 4 interrupt flag
      __IO ONE_BIT  COMIF   :  1; //!<[05] COM interrupt flag
      __IO ONE_BIT  TIF     :  1; //!<[06] Trigger interrupt flag
      __IO ONE_BIT  BIF     :  1; //!<[07] Break interrupt flag
           ONE_BIT  UNUSED0 :  1; //!<[08] 
      __IO ONE_BIT  CC1OF   :  1; //!<[09] Capture/Compare 1 overcapture flag
      __IO ONE_BIT  CC2OF   :  1; //!<[10] Capture/compare 2 overcapture flag
      __IO ONE_BIT  CC3OF   :  1; //!<[11] Capture/Compare 3 overcapture flag
      __IO ONE_BIT  CC4OF   :  1; //!<[12] Capture/Compare 4 overcapture flag
    } B;
    __IO uint32_t  R;
    explicit SR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union EGR_DEF         {  //!< event generation register
    struct {
      __O  ONE_BIT  UG   :  1; //!<[00] Update generation
      __O  ONE_BIT  CC1G :  1; //!<[01] Capture/compare 1 generation
      __O  ONE_BIT  CC2G :  1; //!<[02] Capture/compare 2 generation
      __O  ONE_BIT  CC3G :  1; //!<[03] Capture/compare 3 generation
      __O  ONE_BIT  CC4G :  1; //!<[04] Capture/compare 4 generation
      __O  ONE_BIT  COMG :  1; //!<[05] Capture/Compare control update generation
      __O  ONE_BIT  TG   :  1; //!<[06] Trigger generation
      __O  ONE_BIT  BG   :  1; //!<[07] Break generation
    } B;
    __O  uint32_t  R;
    explicit EGR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      EGR_DEF r;
      R = f (r);
    }
  };
  union CCMR1_Input_DEF {  //!< capture/compare mode register 1 (input mode)
    struct {
      __IO uint32_t   CC1S   :  2; //!<[00] Capture/Compare 1 selection
      __IO uint32_t   IC1PCS :  2; //!<[02] Input capture 1 prescaler
      __IO uint32_t   IC1F   :  4; //!<[04] Input capture 1 filter
      __IO uint32_t   CC2S   :  2; //!<[08] Capture/Compare 2 selection
      __IO uint32_t   IC2PCS :  2; //!<[10] Input capture 2 prescaler
      __IO uint32_t   IC2F   :  4; //!<[12] Input capture 2 filter
    } B;
    __IO uint32_t  R;
    explicit CCMR1_Input_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCMR1_Input_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCMR1_Input_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCMR1_Output_DEF  {  //!< capture/compare mode register (output mode)
    struct {
      __IO uint32_t   CC1S  :  2; //!<[00] Capture/Compare 1 selection
      __IO ONE_BIT    OC1FE :  1; //!<[02] Output Compare 1 fast enable
      __IO ONE_BIT    OC1PE :  1; //!<[03] Output Compare 1 preload enable
      __IO uint32_t   OC1M  :  3; //!<[04] Output Compare 1 mode
      __IO ONE_BIT    OC1CE :  1; //!<[07] Output Compare 1 clear enable
      __IO uint32_t   CC2S  :  2; //!<[08] Capture/Compare 2 selection
      __IO ONE_BIT    OC2FE :  1; //!<[10] Output Compare 2 fast enable
      __IO ONE_BIT    OC2PE :  1; //!<[11] Output Compare 2 preload enable
      __IO uint32_t   OC2M  :  3; //!<[12] Output Compare 2 mode
      __IO ONE_BIT    OC2CE :  1; //!<[15] Output Compare 2 clear enable
    } B;
    __IO uint32_t  R;
    explicit CCMR1_Output_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCMR1_Output_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCMR1_Output_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCMR2_Input_DEF {  //!< capture/compare mode register 2 (input mode)
    struct {
      __IO uint32_t   CC3S   :  2; //!<[00] Capture/compare 3 selection
      __IO uint32_t   IC3PSC :  2; //!<[02] Input capture 3 prescaler
      __IO uint32_t   IC3F   :  4; //!<[04] Input capture 3 filter
      __IO uint32_t   CC4S   :  2; //!<[08] Capture/Compare 4 selection
      __IO uint32_t   IC4PSC :  2; //!<[10] Input capture 4 prescaler
      __IO uint32_t   IC4F   :  4; //!<[12] Input capture 4 filter
    } B;
    __IO uint32_t  R;
    explicit CCMR2_Input_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCMR2_Input_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCMR2_Input_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCMR2_Output_DEF  {  //!< capture/compare mode register (output mode)
    struct {
      __IO uint32_t   CC3S  :  2; //!<[00] Capture/Compare 3 selection
      __IO ONE_BIT    OC3FE :  1; //!<[02] Output compare 3 fast enable
      __IO ONE_BIT    OC3PE :  1; //!<[03] Output compare 3 preload enable
      __IO uint32_t   OC3M  :  3; //!<[04] Output compare 3 mode
      __IO ONE_BIT    OC3CE :  1; //!<[07] Output compare 3 clear enable
      __IO uint32_t   CC4S  :  2; //!<[08] Capture/Compare 4 selection
      __IO ONE_BIT    OC4FE :  1; //!<[10] Output compare 4 fast enable
      __IO ONE_BIT    OC4PE :  1; //!<[11] Output compare 4 preload enable
      __IO uint32_t   OC4M  :  3; //!<[12] Output compare 4 mode
      __IO ONE_BIT    OC4CE :  1; //!<[15] Output compare 4 clear enable
    } B;
    __IO uint32_t  R;
    explicit CCMR2_Output_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCMR2_Output_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCMR2_Output_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCER_DEF        {  //!< capture/compare enable register
    struct {
      __IO ONE_BIT  CC1E  :  1; //!<[00] Capture/Compare 1 output enable
      __IO ONE_BIT  CC1P  :  1; //!<[01] Capture/Compare 1 output Polarity
      __IO ONE_BIT  CC1NE :  1; //!<[02] Capture/Compare 1 complementary output enable
      __IO ONE_BIT  CC1NP :  1; //!<[03] Capture/Compare 1 output Polarity
      __IO ONE_BIT  CC2E  :  1; //!<[04] Capture/Compare 2 output enable
      __IO ONE_BIT  CC2P  :  1; //!<[05] Capture/Compare 2 output Polarity
      __IO ONE_BIT  CC2NE :  1; //!<[06] Capture/Compare 2 complementary output enable
      __IO ONE_BIT  CC2NP :  1; //!<[07] Capture/Compare 2 output Polarity
      __IO ONE_BIT  CC3E  :  1; //!<[08] Capture/Compare 3 output enable
      __IO ONE_BIT  CC3P  :  1; //!<[09] Capture/Compare 3 output Polarity
      __IO ONE_BIT  CC3NE :  1; //!<[10] Capture/Compare 3 complementary output enable
      __IO ONE_BIT  CC3NP :  1; //!<[11] Capture/Compare 3 output Polarity
      __IO ONE_BIT  CC4E  :  1; //!<[12] Capture/Compare 4 output enable
      __IO ONE_BIT  CC4P  :  1; //!<[13] Capture/Compare 3 output Polarity
    } B;
    __IO uint32_t  R;
    explicit CCER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CNT_DEF         {  //!< counter
    struct {
      __IO uint32_t   CNT : 16; //!<[00] counter value
    } B;
    __IO uint32_t  R;
    explicit CNT_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CNT_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CNT_DEF r; r.R = R;
      R = f (r);
    }
  };
  union PSC_DEF         {  //!< prescaler
    struct {
      __IO uint32_t   PSC : 16; //!<[00] Prescaler value
    } B;
    __IO uint32_t  R;
    explicit PSC_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      PSC_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      PSC_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ARR_DEF         {  //!< auto-reload register
    struct {
      __IO uint32_t   ARR : 16; //!<[00] Auto-reload value
    } B;
    __IO uint32_t  R;
    explicit ARR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ARR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ARR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union RCR_DEF         {  //!< repetition counter register
    struct {
      __IO uint32_t   REP :  8; //!<[00] Repetition counter value
    } B;
    __IO uint32_t  R;
    explicit RCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      RCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      RCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR1_DEF        {  //!< capture/compare register 1
    struct {
      __IO uint32_t   CCR1 : 16; //!<[00] Capture/Compare 1 value
    } B;
    __IO uint32_t  R;
    explicit CCR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR2_DEF        {  //!< capture/compare register 2
    struct {
      __IO uint32_t   CCR2 : 16; //!<[00] Capture/Compare 2 value
    } B;
    __IO uint32_t  R;
    explicit CCR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR3_DEF        {  //!< capture/compare register 3
    struct {
      __IO uint32_t   CCR3 : 16; //!<[00] Capture/Compare 3 value
    } B;
    __IO uint32_t  R;
    explicit CCR3_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR3_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR3_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR4_DEF        {  //!< capture/compare register 4
    struct {
      __IO uint32_t   CCR4 : 16; //!<[00] Capture/Compare 3 value
    } B;
    __IO uint32_t  R;
    explicit CCR4_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR4_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR4_DEF r; r.R = R;
      R = f (r);
    }
  };
  union BDTR_DEF        {  //!< break and dead-time register
    struct {
      __IO uint32_t   DTG  :  8; //!<[00] Dead-time generator setup
      __IO uint32_t   LOCK :  2; //!<[08] Lock configuration
      __IO ONE_BIT    OSSI :  1; //!<[10] Off-state selection for Idle mode
      __IO ONE_BIT    OSSR :  1; //!<[11] Off-state selection for Run mode
      __IO ONE_BIT    BKE  :  1; //!<[12] Break enable
      __IO ONE_BIT    BKP  :  1; //!<[13] Break polarity
      __IO ONE_BIT    AOE  :  1; //!<[14] Automatic output enable
      __IO ONE_BIT    MOE  :  1; //!<[15] Main output enable
    } B;
    __IO uint32_t  R;
    explicit BDTR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      BDTR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      BDTR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DCR_DEF         {  //!< DMA control register
    struct {
      __IO uint32_t   DBA     :  5; //!<[00] DMA base address
           uint32_t   UNUSED0 :  3; //!<[05] 
      __IO uint32_t   DBL     :  5; //!<[08] DMA burst length
    } B;
    __IO uint32_t  R;
    explicit DCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DMAR_DEF        {  //!< DMA address for full transfer
    struct {
      __IO uint32_t   DMAB : 16; //!<[00] DMA register for burst accesses
    } B;
    __IO uint32_t  R;
    explicit DMAR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DMAR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DMAR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL TIM1 REGISTERS INSTANCES
  __IO CR1_DEF                     CR1 ;  //!< [0000](04)[0x00000000]
  __IO CR2_DEF                     CR2 ;  //!< [0004](04)[0x00000000]
  __IO SMCR_DEF                   SMCR ;  //!< [0008](04)[0x00000000]
  __IO DIER_DEF                   DIER ;  //!< [000c](04)[0x00000000]
  __IO SR_DEF                       SR ;  //!< [0010](04)[0x00000000]
  __O  EGR_DEF                     EGR ;  //!< [0014](04)[0x00000000]
  MERGE {
  __IO CCMR1_Input_DEF     CCMR1_Input ;  //!< [0018](04)[0x00000000]
  __IO CCMR1_Output_DEF     CCMR1_Output ;  //!< [0018](04)[0x00000000]
  };
  MERGE {
  __IO CCMR2_Input_DEF     CCMR2_Input ;  //!< [001c](04)[0x00000000]
  __IO CCMR2_Output_DEF     CCMR2_Output ;  //!< [001c](04)[0x00000000]
  };
  __IO CCER_DEF                   CCER ;  //!< [0020](04)[0x00000000]
  __IO CNT_DEF                     CNT ;  //!< [0024](04)[0x00000000]
  __IO PSC_DEF                     PSC ;  //!< [0028](04)[0x00000000]
  __IO ARR_DEF                     ARR ;  //!< [002c](04)[0x00000000]
  __IO RCR_DEF                     RCR ;  //!< [0030](04)[0x00000000]
  __IO CCR1_DEF                   CCR1 ;  //!< [0034](04)[0x00000000]
  __IO CCR2_DEF                   CCR2 ;  //!< [0038](04)[0x00000000]
  __IO CCR3_DEF                   CCR3 ;  //!< [003c](04)[0x00000000]
  __IO CCR4_DEF                   CCR4 ;  //!< [0040](04)[0x00000000]
  __IO BDTR_DEF                   BDTR ;  //!< [0044](04)[0x00000000]
  __IO DCR_DEF                     DCR ;  //!< [0048](04)[0x00000000]
  __IO DMAR_DEF                   DMAR ;  //!< [004c](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x0050 */

// ////////////////////+++ TIM2 +-+//////////////////// //
struct TIM2_Type        { /*!< General-purpose-timers */
  union CR1_DEF         {  //!< control register 1
    struct {
      __IO ONE_BIT    CEN  :  1; //!<[00] Counter enable
      __IO ONE_BIT    UDIS :  1; //!<[01] Update disable
      __IO ONE_BIT    URS  :  1; //!<[02] Update request source
      __IO ONE_BIT    OPM  :  1; //!<[03] One-pulse mode
      __IO ONE_BIT    DIR  :  1; //!<[04] Direction
      __IO uint32_t   CMS  :  2; //!<[05] Center-aligned mode selection
      __IO ONE_BIT    ARPE :  1; //!<[07] Auto-reload preload enable
      __IO uint32_t   CKD  :  2; //!<[08] Clock division
    } B;
    __IO uint32_t  R;
    explicit CR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CR2_DEF         {  //!< control register 2
    struct {
           uint32_t   UNUSED0 :  3; //!<[00] 
      __IO ONE_BIT    CCDS    :  1; //!<[03] Capture/compare DMA selection
      __IO uint32_t   MMS     :  3; //!<[04] Master mode selection
      __IO ONE_BIT    TI1S    :  1; //!<[07] TI1 selection
    } B;
    __IO uint32_t  R;
    explicit CR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SMCR_DEF        {  //!< slave mode control register
    struct {
      __IO uint32_t   SMS     :  3; //!<[00] Slave mode selection
           ONE_BIT    UNUSED0 :  1; //!<[03] 
      __IO uint32_t   TS      :  3; //!<[04] Trigger selection
      __IO ONE_BIT    MSM     :  1; //!<[07] Master/Slave mode
      __IO uint32_t   ETF     :  4; //!<[08] External trigger filter
      __IO uint32_t   ETPS    :  2; //!<[12] External trigger prescaler
      __IO ONE_BIT    ECE     :  1; //!<[14] External clock enable
      __IO ONE_BIT    ETP     :  1; //!<[15] External trigger polarity
    } B;
    __IO uint32_t  R;
    explicit SMCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SMCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SMCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DIER_DEF        {  //!< DMA/Interrupt enable register
    struct {
      __IO ONE_BIT  UIE     :  1; //!<[00] Update interrupt enable
      __IO ONE_BIT  CC1IE   :  1; //!<[01] Capture/Compare 1 interrupt enable
      __IO ONE_BIT  CC2IE   :  1; //!<[02] Capture/Compare 2 interrupt enable
      __IO ONE_BIT  CC3IE   :  1; //!<[03] Capture/Compare 3 interrupt enable
      __IO ONE_BIT  CC4IE   :  1; //!<[04] Capture/Compare 4 interrupt enable
           ONE_BIT  UNUSED0 :  1; //!<[05] 
      __IO ONE_BIT  TIE     :  1; //!<[06] Trigger interrupt enable
           ONE_BIT  UNUSED1 :  1; //!<[07] 
      __IO ONE_BIT  UDE     :  1; //!<[08] Update DMA request enable
      __IO ONE_BIT  CC1DE   :  1; //!<[09] Capture/Compare 1 DMA request enable
      __IO ONE_BIT  CC2DE   :  1; //!<[10] Capture/Compare 2 DMA request enable
      __IO ONE_BIT  CC3DE   :  1; //!<[11] Capture/Compare 3 DMA request enable
      __IO ONE_BIT  CC4DE   :  1; //!<[12] Capture/Compare 4 DMA request enable
      __IO ONE_BIT  COMDE   :  1; //!<[13] COM DMA request enable
      __IO ONE_BIT  TDE     :  1; //!<[14] Trigger DMA request enable
    } B;
    __IO uint32_t  R;
    explicit DIER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DIER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DIER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SR_DEF          {  //!< status register
    struct {
      __IO ONE_BIT    UIF     :  1; //!<[00] Update interrupt flag
      __IO ONE_BIT    CC1IF   :  1; //!<[01] Capture/compare 1 interrupt flag
      __IO ONE_BIT    CC2IF   :  1; //!<[02] Capture/Compare 2 interrupt flag
      __IO ONE_BIT    CC3IF   :  1; //!<[03] Capture/Compare 3 interrupt flag
      __IO ONE_BIT    CC4IF   :  1; //!<[04] Capture/Compare 4 interrupt flag
           ONE_BIT    UNUSED0 :  1; //!<[05] 
      __IO ONE_BIT    TIF     :  1; //!<[06] Trigger interrupt flag
           uint32_t   UNUSED1 :  2; //!<[07] 
      __IO ONE_BIT    CC1OF   :  1; //!<[09] Capture/Compare 1 overcapture flag
      __IO ONE_BIT    CC2OF   :  1; //!<[10] Capture/compare 2 overcapture flag
      __IO ONE_BIT    CC3OF   :  1; //!<[11] Capture/Compare 3 overcapture flag
      __IO ONE_BIT    CC4OF   :  1; //!<[12] Capture/Compare 4 overcapture flag
    } B;
    __IO uint32_t  R;
    explicit SR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union EGR_DEF         {  //!< event generation register
    struct {
      __O  ONE_BIT  UG      :  1; //!<[00] Update generation
      __O  ONE_BIT  CC1G    :  1; //!<[01] Capture/compare 1 generation
      __O  ONE_BIT  CC2G    :  1; //!<[02] Capture/compare 2 generation
      __O  ONE_BIT  CC3G    :  1; //!<[03] Capture/compare 3 generation
      __O  ONE_BIT  CC4G    :  1; //!<[04] Capture/compare 4 generation
           ONE_BIT  UNUSED0 :  1; //!<[05] 
      __O  ONE_BIT  TG      :  1; //!<[06] Trigger generation
    } B;
    __O  uint32_t  R;
    explicit EGR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      EGR_DEF r;
      R = f (r);
    }
  };
  union CCMR1_Input_DEF {  //!< capture/compare mode register 1 (input mode)
    struct {
      __IO uint32_t   CC1S   :  2; //!<[00] Capture/Compare 1 selection
      __IO uint32_t   IC1PSC :  2; //!<[02] Input capture 1 prescaler
      __IO uint32_t   IC1F   :  4; //!<[04] Input capture 1 filter
      __IO uint32_t   CC2S   :  2; //!<[08] Capture/compare 2 selection
      __IO uint32_t   IC2PSC :  2; //!<[10] Input capture 2 prescaler
      __IO uint32_t   IC2F   :  4; //!<[12] Input capture 2 filter
    } B;
    __IO uint32_t  R;
    explicit CCMR1_Input_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCMR1_Input_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCMR1_Input_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCMR1_Output_DEF  {  //!< capture/compare mode register 1 (output mode)
    struct {
      __IO uint32_t   CC1S  :  2; //!<[00] Capture/Compare 1 selection
      __IO ONE_BIT    OC1FE :  1; //!<[02] Output compare 1 fast enable
      __IO ONE_BIT    OC1PE :  1; //!<[03] Output compare 1 preload enable
      __IO uint32_t   OC1M  :  3; //!<[04] Output compare 1 mode
      __IO ONE_BIT    OC1CE :  1; //!<[07] Output compare 1 clear enable
      __IO uint32_t   CC2S  :  2; //!<[08] Capture/Compare 2 selection
      __IO ONE_BIT    OC2FE :  1; //!<[10] Output compare 2 fast enable
      __IO ONE_BIT    OC2PE :  1; //!<[11] Output compare 2 preload enable
      __IO uint32_t   OC2M  :  3; //!<[12] Output compare 2 mode
      __IO ONE_BIT    OC2CE :  1; //!<[15] Output compare 2 clear enable
    } B;
    __IO uint32_t  R;
    explicit CCMR1_Output_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCMR1_Output_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCMR1_Output_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCMR2_Input_DEF {  //!< capture/compare mode register 2 (input mode)
    struct {
      __IO uint32_t   CC3S   :  2; //!<[00] Capture/Compare 3 selection
      __IO uint32_t   IC3PSC :  2; //!<[02] Input capture 3 prescaler
      __IO uint32_t   IC3F   :  4; //!<[04] Input capture 3 filter
      __IO uint32_t   CC4S   :  2; //!<[08] Capture/Compare 4 selection
      __IO uint32_t   IC4PSC :  2; //!<[10] Input capture 4 prescaler
      __IO uint32_t   IC4F   :  4; //!<[12] Input capture 4 filter
    } B;
    __IO uint32_t  R;
    explicit CCMR2_Input_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCMR2_Input_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCMR2_Input_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCMR2_Output_DEF  {  //!< capture/compare mode register 2 (output mode)
    struct {
      __IO uint32_t   CC3S  :  2; //!<[00] Capture/Compare 3 selection
      __IO ONE_BIT    OC3FE :  1; //!<[02] Output compare 3 fast enable
      __IO ONE_BIT    OC3PE :  1; //!<[03] Output compare 3 preload enable
      __IO uint32_t   OC3M  :  3; //!<[04] Output compare 3 mode
      __IO ONE_BIT    OC3CE :  1; //!<[07] Output compare 3 clear enable
      __IO uint32_t   CC4S  :  2; //!<[08] Capture/Compare 4 selection
      __IO ONE_BIT    OC4FE :  1; //!<[10] Output compare 4 fast enable
      __IO ONE_BIT    OC4PE :  1; //!<[11] Output compare 4 preload enable
      __IO uint32_t   OC4M  :  3; //!<[12] Output compare 4 mode
      __IO ONE_BIT    OC4CE :  1; //!<[15] Output compare 4 clear enable
    } B;
    __IO uint32_t  R;
    explicit CCMR2_Output_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCMR2_Output_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCMR2_Output_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCER_DEF        {  //!< capture/compare enable register
    struct {
      __IO ONE_BIT  CC1E    :  1; //!<[00] Capture/Compare 1 output enable
      __IO ONE_BIT  CC1P    :  1; //!<[01] Capture/Compare 1 output Polarity
           ONE_BIT  UNUSED0 :  1; //!<[02] 
      __IO ONE_BIT  CC1NP   :  1; //!<[03] Capture/Compare 1 output Polarity
      __IO ONE_BIT  CC2E    :  1; //!<[04] Capture/Compare 2 output enable
      __IO ONE_BIT  CC2P    :  1; //!<[05] Capture/Compare 2 output Polarity
           ONE_BIT  UNUSED1 :  1; //!<[06] 
      __IO ONE_BIT  CC2NP   :  1; //!<[07] Capture/Compare 2 output Polarity
      __IO ONE_BIT  CC3E    :  1; //!<[08] Capture/Compare 3 output enable
      __IO ONE_BIT  CC3P    :  1; //!<[09] Capture/Compare 3 output Polarity
           ONE_BIT  UNUSED2 :  1; //!<[10] 
      __IO ONE_BIT  CC3NP   :  1; //!<[11] Capture/Compare 3 output Polarity
      __IO ONE_BIT  CC4E    :  1; //!<[12] Capture/Compare 4 output enable
      __IO ONE_BIT  CC4P    :  1; //!<[13] Capture/Compare 3 output Polarity
           ONE_BIT  UNUSED3 :  1; //!<[14] 
      __IO ONE_BIT  CC4NP   :  1; //!<[15] Capture/Compare 4 output Polarity
    } B;
    __IO uint32_t  R;
    explicit CCER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CNT_DEF         {  //!< counter
    struct {
      __IO uint32_t   CNT_L : 16; //!<[00] Low counter value
      __IO uint32_t   CNT_H : 16; //!<[16] High counter value (TIM2 only)
    } B;
    __IO uint32_t  R;
    explicit CNT_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CNT_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CNT_DEF r; r.R = R;
      R = f (r);
    }
  };
  union PSC_DEF         {  //!< prescaler
    struct {
      __IO uint32_t   PSC : 16; //!<[00] Prescaler value
    } B;
    __IO uint32_t  R;
    explicit PSC_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      PSC_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      PSC_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ARR_DEF         {  //!< auto-reload register
    struct {
      __IO uint32_t   ARR_L : 16; //!<[00] Low Auto-reload value
      __IO uint32_t   ARR_H : 16; //!<[16] High Auto-reload value (TIM2 only)
    } B;
    __IO uint32_t  R;
    explicit ARR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ARR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ARR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR1_DEF        {  //!< capture/compare register 1
    struct {
      __IO uint32_t   CCR1_L : 16; //!<[00] Low Capture/Compare 1 value
      __IO uint32_t   CCR1_H : 16; //!<[16] High Capture/Compare 1 value (TIM2 only)
    } B;
    __IO uint32_t  R;
    explicit CCR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR2_DEF        {  //!< capture/compare register 2
    struct {
      __IO uint32_t   CCR2_L : 16; //!<[00] Low Capture/Compare 2 value
      __IO uint32_t   CCR2_H : 16; //!<[16] High Capture/Compare 2 value (TIM2 only)
    } B;
    __IO uint32_t  R;
    explicit CCR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR3_DEF        {  //!< capture/compare register 3
    struct {
      __IO uint32_t   CCR3_L : 16; //!<[00] Low Capture/Compare value
      __IO uint32_t   CCR3_H : 16; //!<[16] High Capture/Compare value (TIM2 only)
    } B;
    __IO uint32_t  R;
    explicit CCR3_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR3_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR3_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR4_DEF        {  //!< capture/compare register 4
    struct {
      __IO uint32_t   CCR4_L : 16; //!<[00] Low Capture/Compare value
      __IO uint32_t   CCR4_H : 16; //!<[16] High Capture/Compare value (TIM2 only)
    } B;
    __IO uint32_t  R;
    explicit CCR4_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR4_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR4_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DCR_DEF         {  //!< DMA control register
    struct {
      __IO uint32_t   DBA     :  5; //!<[00] DMA base address
           uint32_t   UNUSED0 :  3; //!<[05] 
      __IO uint32_t   DBL     :  5; //!<[08] DMA burst length
    } B;
    __IO uint32_t  R;
    explicit DCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DMAR_DEF        {  //!< DMA address for full transfer
    struct {
      __IO uint32_t   DMAR : 16; //!<[00] DMA register for burst accesses
    } B;
    __IO uint32_t  R;
    explicit DMAR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DMAR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DMAR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL TIM2 REGISTERS INSTANCES
  __IO CR1_DEF                     CR1 ;  //!< [0000](04)[0x00000000]
  __IO CR2_DEF                     CR2 ;  //!< [0004](04)[0x00000000]
  __IO SMCR_DEF                   SMCR ;  //!< [0008](04)[0x00000000]
  __IO DIER_DEF                   DIER ;  //!< [000c](04)[0x00000000]
  __IO SR_DEF                       SR ;  //!< [0010](04)[0x00000000]
  __O  EGR_DEF                     EGR ;  //!< [0014](04)[0x00000000]
  MERGE {
  __IO CCMR1_Input_DEF     CCMR1_Input ;  //!< [0018](04)[0x00000000]
  __IO CCMR1_Output_DEF     CCMR1_Output ;  //!< [0018](04)[0x00000000]
  };
  MERGE {
  __IO CCMR2_Input_DEF     CCMR2_Input ;  //!< [001c](04)[0x00000000]
  __IO CCMR2_Output_DEF     CCMR2_Output ;  //!< [001c](04)[0x00000000]
  };
  __IO CCER_DEF                   CCER ;  //!< [0020](04)[0x00000000]
  __IO CNT_DEF                     CNT ;  //!< [0024](04)[0x00000000]
  __IO PSC_DEF                     PSC ;  //!< [0028](04)[0x00000000]
  __IO ARR_DEF                     ARR ;  //!< [002c](04)[0x00000000]
       uint32_t              UNUSED0 ;  //!< [0030](04)[0xFFFFFFFF]
  __IO CCR1_DEF                   CCR1 ;  //!< [0034](04)[0x00000000]
  __IO CCR2_DEF                   CCR2 ;  //!< [0038](04)[0x00000000]
  __IO CCR3_DEF                   CCR3 ;  //!< [003c](04)[0x00000000]
  __IO CCR4_DEF                   CCR4 ;  //!< [0040](04)[0x00000000]
       uint32_t              UNUSED1 ;  //!< [0044](04)[0xFFFFFFFF]
  __IO DCR_DEF                     DCR ;  //!< [0048](04)[0x00000000]
  __IO DMAR_DEF                   DMAR ;  //!< [004c](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x0050 */

// ////////////////////+++ TIM14 +-+//////////////////// //
struct TIM14_Type       { /*!< General-purpose-timers */
  union CR1_DEF         {  //!< control register 1
    struct {
      __IO ONE_BIT    CEN     :  1; //!<[00] Counter enable
      __IO ONE_BIT    UDIS    :  1; //!<[01] Update disable
      __IO ONE_BIT    URS     :  1; //!<[02] Update request source
           uint32_t   UNUSED0 :  4; //!<[03] 
      __IO ONE_BIT    ARPE    :  1; //!<[07] Auto-reload preload enable
      __IO uint32_t   CKD     :  2; //!<[08] Clock division
    } B;
    __IO uint32_t  R;
    explicit CR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DIER_DEF        {  //!< DMA/Interrupt enable register
    struct {
      __IO ONE_BIT  UIE   :  1; //!<[00] Update interrupt enable
      __IO ONE_BIT  CC1IE :  1; //!<[01] Capture/Compare 1 interrupt enable
    } B;
    __IO uint32_t  R;
    explicit DIER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DIER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DIER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SR_DEF          {  //!< status register
    struct {
      __IO ONE_BIT    UIF     :  1; //!<[00] Update interrupt flag
      __IO ONE_BIT    CC1IF   :  1; //!<[01] Capture/compare 1 interrupt flag
           uint32_t   UNUSED0 :  7; //!<[02] 
      __IO ONE_BIT    CC1OF   :  1; //!<[09] Capture/Compare 1 overcapture flag
    } B;
    __IO uint32_t  R;
    explicit SR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union EGR_DEF         {  //!< event generation register
    struct {
      __O  ONE_BIT  UG   :  1; //!<[00] Update generation
      __O  ONE_BIT  CC1G :  1; //!<[01] Capture/compare 1 generation
    } B;
    __O  uint32_t  R;
    explicit EGR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      EGR_DEF r;
      R = f (r);
    }
  };
  union CCMR1_Input_DEF {  //!< capture/compare mode register (input mode)
    struct {
      __IO uint32_t   CC1S   :  2; //!<[00] Capture/Compare 1 selection
      __IO uint32_t   IC1PSC :  2; //!<[02] Input capture 1 prescaler
      __IO uint32_t   IC1F   :  4; //!<[04] Input capture 1 filter
    } B;
    __IO uint32_t  R;
    explicit CCMR1_Input_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCMR1_Input_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCMR1_Input_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCMR1_Output_DEF  {  //!< capture/compare mode register (output mode)
    struct {
      __IO uint32_t   CC1S  :  2; //!<[00] Capture/Compare 1 selection
      __IO ONE_BIT    OC1FE :  1; //!<[02] Output compare 1 fast enable
      __IO ONE_BIT    OC1PE :  1; //!<[03] Output Compare 1 preload enable
      __IO uint32_t   OC1M  :  3; //!<[04] Output Compare 1 mode
    } B;
    __IO uint32_t  R;
    explicit CCMR1_Output_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCMR1_Output_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCMR1_Output_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCER_DEF        {  //!< capture/compare enable register
    struct {
      __IO ONE_BIT  CC1E    :  1; //!<[00] Capture/Compare 1 output enable
      __IO ONE_BIT  CC1P    :  1; //!<[01] Capture/Compare 1 output Polarity
           ONE_BIT  UNUSED0 :  1; //!<[02] 
      __IO ONE_BIT  CC1NP   :  1; //!<[03] Capture/Compare 1 output Polarity
    } B;
    __IO uint32_t  R;
    explicit CCER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CNT_DEF         {  //!< counter
    struct {
      __IO uint32_t   CNT : 16; //!<[00] counter value
    } B;
    __IO uint32_t  R;
    explicit CNT_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CNT_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CNT_DEF r; r.R = R;
      R = f (r);
    }
  };
  union PSC_DEF         {  //!< prescaler
    struct {
      __IO uint32_t   PSC : 16; //!<[00] Prescaler value
    } B;
    __IO uint32_t  R;
    explicit PSC_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      PSC_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      PSC_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ARR_DEF         {  //!< auto-reload register
    struct {
      __IO uint32_t   ARR : 16; //!<[00] Auto-reload value
    } B;
    __IO uint32_t  R;
    explicit ARR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ARR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ARR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR1_DEF        {  //!< capture/compare register 1
    struct {
      __IO uint32_t   CCR1 : 16; //!<[00] Capture/Compare 1 value
    } B;
    __IO uint32_t  R;
    explicit CCR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union OR_DEF          {  //!< option register
    struct {
      __IO uint32_t   RMP :  2; //!<[00] Timer input 1 remap
    } B;
    __IO uint32_t  R;
    explicit OR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      OR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      OR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL TIM14 REGISTERS INSTANCES
  __IO CR1_DEF                     CR1 ;  //!< [0000](04)[0x00000000]
       uint32_t              UNUSED0 [2];  //!< [0004](08)[0xFFFFFFFF]
  __IO DIER_DEF                   DIER ;  //!< [000c](04)[0x00000000]
  __IO SR_DEF                       SR ;  //!< [0010](04)[0x00000000]
  __O  EGR_DEF                     EGR ;  //!< [0014](04)[0x00000000]
  MERGE {
  __IO CCMR1_Input_DEF     CCMR1_Input ;  //!< [0018](04)[0x00000000]
  __IO CCMR1_Output_DEF     CCMR1_Output ;  //!< [0018](04)[0x00000000]
  };
       uint32_t              UNUSED1 ;  //!< [001c](04)[0xFFFFFFFF]
  __IO CCER_DEF                   CCER ;  //!< [0020](04)[0x00000000]
  __IO CNT_DEF                     CNT ;  //!< [0024](04)[0x00000000]
  __IO PSC_DEF                     PSC ;  //!< [0028](04)[0x00000000]
  __IO ARR_DEF                     ARR ;  //!< [002c](04)[0x00000000]
       uint32_t              UNUSED2 ;  //!< [0030](04)[0xFFFFFFFF]
  __IO CCR1_DEF                   CCR1 ;  //!< [0034](04)[0x00000000]
       uint32_t              UNUSED3 [6];  //!< [0038](18)[0xFFFFFFFF]
  __IO OR_DEF                       OR ;  //!< [0050](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x0054 */

// ////////////////////+++ TIM6 +-+//////////////////// //
struct TIM6_Type        { /*!< Basic-timers */
  union CR1_DEF     {  //!< control register 1
    struct {
      __IO ONE_BIT    CEN     :  1; //!<[00] Counter enable
      __IO ONE_BIT    UDIS    :  1; //!<[01] Update disable
      __IO ONE_BIT    URS     :  1; //!<[02] Update request source
      __IO ONE_BIT    OPM     :  1; //!<[03] One-pulse mode
           uint32_t   UNUSED0 :  3; //!<[04] 
      __IO ONE_BIT    ARPE    :  1; //!<[07] Auto-reload preload enable
    } B;
    __IO uint32_t  R;
    explicit CR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CR2_DEF     {  //!< control register 2
    struct {
           uint32_t   UNUSED0 :  4; //!<[00] 
      __IO uint32_t   MMS     :  3; //!<[04] Master mode selection
    } B;
    __IO uint32_t  R;
    explicit CR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DIER_DEF    {  //!< DMA/Interrupt enable register
    struct {
      __IO ONE_BIT    UIE     :  1; //!<[00] Update interrupt enable
           uint32_t   UNUSED0 :  7; //!<[01] 
      __IO ONE_BIT    UDE     :  1; //!<[08] Update DMA request enable
    } B;
    __IO uint32_t  R;
    explicit DIER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DIER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DIER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SR_DEF      {  //!< status register
    struct {
      __IO ONE_BIT  UIF :  1; //!<[00] Update interrupt flag
    } B;
    __IO uint32_t  R;
    explicit SR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union EGR_DEF     {  //!< event generation register
    struct {
      __O  ONE_BIT  UG :  1; //!<[00] Update generation
    } B;
    __O  uint32_t  R;
    explicit EGR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      EGR_DEF r;
      R = f (r);
    }
  };
  union CNT_DEF     {  //!< counter
    struct {
      __IO uint32_t   CNT : 16; //!<[00] Low counter value
    } B;
    __IO uint32_t  R;
    explicit CNT_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CNT_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CNT_DEF r; r.R = R;
      R = f (r);
    }
  };
  union PSC_DEF     {  //!< prescaler
    struct {
      __IO uint32_t   PSC : 16; //!<[00] Prescaler value
    } B;
    __IO uint32_t  R;
    explicit PSC_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      PSC_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      PSC_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ARR_DEF     {  //!< auto-reload register
    struct {
      __IO uint32_t   ARR : 16; //!<[00] Low Auto-reload value
    } B;
    __IO uint32_t  R;
    explicit ARR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ARR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ARR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL TIM6 REGISTERS INSTANCES
  __IO CR1_DEF                 CR1 ;  //!< [0000](04)[0x00000000]
  __IO CR2_DEF                 CR2 ;  //!< [0004](04)[0x00000000]
       uint32_t          UNUSED0 ;  //!< [0008](04)[0xFFFFFFFF]
  __IO DIER_DEF               DIER ;  //!< [000c](04)[0x00000000]
  __IO SR_DEF                   SR ;  //!< [0010](04)[0x00000000]
  __O  EGR_DEF                 EGR ;  //!< [0014](04)[0x00000000]
       uint32_t          UNUSED1 [3];  //!< [0018](0c)[0xFFFFFFFF]
  __IO CNT_DEF                 CNT ;  //!< [0024](04)[0x00000000]
  __IO PSC_DEF                 PSC ;  //!< [0028](04)[0x00000000]
  __IO ARR_DEF                 ARR ;  //!< [002c](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x0030 */

// ////////////////////+++ EXTI +-+//////////////////// //
struct EXTI_Type        { /*!< External interrupt/event controller */
  union IMR_DEF   {  //!< Interrupt mask register (EXTI_IMR)
    struct {
      __IO ONE_BIT  MR0  :  1; //!<[00] Interrupt Mask on line 0
      __IO ONE_BIT  MR1  :  1; //!<[01] Interrupt Mask on line 1
      __IO ONE_BIT  MR2  :  1; //!<[02] Interrupt Mask on line 2
      __IO ONE_BIT  MR3  :  1; //!<[03] Interrupt Mask on line 3
      __IO ONE_BIT  MR4  :  1; //!<[04] Interrupt Mask on line 4
      __IO ONE_BIT  MR5  :  1; //!<[05] Interrupt Mask on line 5
      __IO ONE_BIT  MR6  :  1; //!<[06] Interrupt Mask on line 6
      __IO ONE_BIT  MR7  :  1; //!<[07] Interrupt Mask on line 7
      __IO ONE_BIT  MR8  :  1; //!<[08] Interrupt Mask on line 8
      __IO ONE_BIT  MR9  :  1; //!<[09] Interrupt Mask on line 9
      __IO ONE_BIT  MR10 :  1; //!<[10] Interrupt Mask on line 10
      __IO ONE_BIT  MR11 :  1; //!<[11] Interrupt Mask on line 11
      __IO ONE_BIT  MR12 :  1; //!<[12] Interrupt Mask on line 12
      __IO ONE_BIT  MR13 :  1; //!<[13] Interrupt Mask on line 13
      __IO ONE_BIT  MR14 :  1; //!<[14] Interrupt Mask on line 14
      __IO ONE_BIT  MR15 :  1; //!<[15] Interrupt Mask on line 15
      __IO ONE_BIT  MR16 :  1; //!<[16] Interrupt Mask on line 16
      __IO ONE_BIT  MR17 :  1; //!<[17] Interrupt Mask on line 17
      __IO ONE_BIT  MR18 :  1; //!<[18] Interrupt Mask on line 18
      __IO ONE_BIT  MR19 :  1; //!<[19] Interrupt Mask on line 19
      __IO ONE_BIT  MR20 :  1; //!<[20] Interrupt Mask on line 20
      __IO ONE_BIT  MR21 :  1; //!<[21] Interrupt Mask on line 21
      __IO ONE_BIT  MR22 :  1; //!<[22] Interrupt Mask on line 22
      __IO ONE_BIT  MR23 :  1; //!<[23] Interrupt Mask on line 23
      __IO ONE_BIT  MR24 :  1; //!<[24] Interrupt Mask on line 24
      __IO ONE_BIT  MR25 :  1; //!<[25] Interrupt Mask on line 25
      __IO ONE_BIT  MR26 :  1; //!<[26] Interrupt Mask on line 26
      __IO ONE_BIT  MR27 :  1; //!<[27] Interrupt Mask on line 27
    } B;
    __IO uint32_t  R;
    explicit IMR_DEF () noexcept { R = 0x0f940000u; }
    template<typename F> void setbit (F f) volatile {
      IMR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IMR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union EMR_DEF   {  //!< Event mask register (EXTI_EMR)
    struct {
      __IO ONE_BIT  MR0  :  1; //!<[00] Event Mask on line 0
      __IO ONE_BIT  MR1  :  1; //!<[01] Event Mask on line 1
      __IO ONE_BIT  MR2  :  1; //!<[02] Event Mask on line 2
      __IO ONE_BIT  MR3  :  1; //!<[03] Event Mask on line 3
      __IO ONE_BIT  MR4  :  1; //!<[04] Event Mask on line 4
      __IO ONE_BIT  MR5  :  1; //!<[05] Event Mask on line 5
      __IO ONE_BIT  MR6  :  1; //!<[06] Event Mask on line 6
      __IO ONE_BIT  MR7  :  1; //!<[07] Event Mask on line 7
      __IO ONE_BIT  MR8  :  1; //!<[08] Event Mask on line 8
      __IO ONE_BIT  MR9  :  1; //!<[09] Event Mask on line 9
      __IO ONE_BIT  MR10 :  1; //!<[10] Event Mask on line 10
      __IO ONE_BIT  MR11 :  1; //!<[11] Event Mask on line 11
      __IO ONE_BIT  MR12 :  1; //!<[12] Event Mask on line 12
      __IO ONE_BIT  MR13 :  1; //!<[13] Event Mask on line 13
      __IO ONE_BIT  MR14 :  1; //!<[14] Event Mask on line 14
      __IO ONE_BIT  MR15 :  1; //!<[15] Event Mask on line 15
      __IO ONE_BIT  MR16 :  1; //!<[16] Event Mask on line 16
      __IO ONE_BIT  MR17 :  1; //!<[17] Event Mask on line 17
      __IO ONE_BIT  MR18 :  1; //!<[18] Event Mask on line 18
      __IO ONE_BIT  MR19 :  1; //!<[19] Event Mask on line 19
      __IO ONE_BIT  MR20 :  1; //!<[20] Event Mask on line 20
      __IO ONE_BIT  MR21 :  1; //!<[21] Event Mask on line 21
      __IO ONE_BIT  MR22 :  1; //!<[22] Event Mask on line 22
      __IO ONE_BIT  MR23 :  1; //!<[23] Event Mask on line 23
      __IO ONE_BIT  MR24 :  1; //!<[24] Event Mask on line 24
      __IO ONE_BIT  MR25 :  1; //!<[25] Event Mask on line 25
      __IO ONE_BIT  MR26 :  1; //!<[26] Event Mask on line 26
      __IO ONE_BIT  MR27 :  1; //!<[27] Event Mask on line 27
    } B;
    __IO uint32_t  R;
    explicit EMR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      EMR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      EMR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union RTSR_DEF  {  //!< Rising Trigger selection register (EXTI_RTSR)
    struct {
      __IO ONE_BIT  TR0     :  1; //!<[00] Rising trigger event configuration of line 0
      __IO ONE_BIT  TR1     :  1; //!<[01] Rising trigger event configuration of line 1
      __IO ONE_BIT  TR2     :  1; //!<[02] Rising trigger event configuration of line 2
      __IO ONE_BIT  TR3     :  1; //!<[03] Rising trigger event configuration of line 3
      __IO ONE_BIT  TR4     :  1; //!<[04] Rising trigger event configuration of line 4
      __IO ONE_BIT  TR5     :  1; //!<[05] Rising trigger event configuration of line 5
      __IO ONE_BIT  TR6     :  1; //!<[06] Rising trigger event configuration of line 6
      __IO ONE_BIT  TR7     :  1; //!<[07] Rising trigger event configuration of line 7
      __IO ONE_BIT  TR8     :  1; //!<[08] Rising trigger event configuration of line 8
      __IO ONE_BIT  TR9     :  1; //!<[09] Rising trigger event configuration of line 9
      __IO ONE_BIT  TR10    :  1; //!<[10] Rising trigger event configuration of line 10
      __IO ONE_BIT  TR11    :  1; //!<[11] Rising trigger event configuration of line 11
      __IO ONE_BIT  TR12    :  1; //!<[12] Rising trigger event configuration of line 12
      __IO ONE_BIT  TR13    :  1; //!<[13] Rising trigger event configuration of line 13
      __IO ONE_BIT  TR14    :  1; //!<[14] Rising trigger event configuration of line 14
      __IO ONE_BIT  TR15    :  1; //!<[15] Rising trigger event configuration of line 15
      __IO ONE_BIT  TR16    :  1; //!<[16] Rising trigger event configuration of line 16
      __IO ONE_BIT  TR17    :  1; //!<[17] Rising trigger event configuration of line 17
           ONE_BIT  UNUSED0 :  1; //!<[18] 
      __IO ONE_BIT  TR19    :  1; //!<[19] Rising trigger event configuration of line 19
    } B;
    __IO uint32_t  R;
    explicit RTSR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      RTSR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      RTSR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union FTSR_DEF  {  //!< Falling Trigger selection register (EXTI_FTSR)
    struct {
      __IO ONE_BIT  TR0     :  1; //!<[00] Falling trigger event configuration of line 0
      __IO ONE_BIT  TR1     :  1; //!<[01] Falling trigger event configuration of line 1
      __IO ONE_BIT  TR2     :  1; //!<[02] Falling trigger event configuration of line 2
      __IO ONE_BIT  TR3     :  1; //!<[03] Falling trigger event configuration of line 3
      __IO ONE_BIT  TR4     :  1; //!<[04] Falling trigger event configuration of line 4
      __IO ONE_BIT  TR5     :  1; //!<[05] Falling trigger event configuration of line 5
      __IO ONE_BIT  TR6     :  1; //!<[06] Falling trigger event configuration of line 6
      __IO ONE_BIT  TR7     :  1; //!<[07] Falling trigger event configuration of line 7
      __IO ONE_BIT  TR8     :  1; //!<[08] Falling trigger event configuration of line 8
      __IO ONE_BIT  TR9     :  1; //!<[09] Falling trigger event configuration of line 9
      __IO ONE_BIT  TR10    :  1; //!<[10] Falling trigger event configuration of line 10
      __IO ONE_BIT  TR11    :  1; //!<[11] Falling trigger event configuration of line 11
      __IO ONE_BIT  TR12    :  1; //!<[12] Falling trigger event configuration of line 12
      __IO ONE_BIT  TR13    :  1; //!<[13] Falling trigger event configuration of line 13
      __IO ONE_BIT  TR14    :  1; //!<[14] Falling trigger event configuration of line 14
      __IO ONE_BIT  TR15    :  1; //!<[15] Falling trigger event configuration of line 15
      __IO ONE_BIT  TR16    :  1; //!<[16] Falling trigger event configuration of line 16
      __IO ONE_BIT  TR17    :  1; //!<[17] Falling trigger event configuration of line 17
           ONE_BIT  UNUSED0 :  1; //!<[18] 
      __IO ONE_BIT  TR19    :  1; //!<[19] Falling trigger event configuration of line 19
    } B;
    __IO uint32_t  R;
    explicit FTSR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      FTSR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      FTSR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SWIER_DEF {  //!< Software interrupt event register (EXTI_SWIER)
    struct {
      __IO ONE_BIT  SWIER0  :  1; //!<[00] Software Interrupt on line 0
      __IO ONE_BIT  SWIER1  :  1; //!<[01] Software Interrupt on line 1
      __IO ONE_BIT  SWIER2  :  1; //!<[02] Software Interrupt on line 2
      __IO ONE_BIT  SWIER3  :  1; //!<[03] Software Interrupt on line 3
      __IO ONE_BIT  SWIER4  :  1; //!<[04] Software Interrupt on line 4
      __IO ONE_BIT  SWIER5  :  1; //!<[05] Software Interrupt on line 5
      __IO ONE_BIT  SWIER6  :  1; //!<[06] Software Interrupt on line 6
      __IO ONE_BIT  SWIER7  :  1; //!<[07] Software Interrupt on line 7
      __IO ONE_BIT  SWIER8  :  1; //!<[08] Software Interrupt on line 8
      __IO ONE_BIT  SWIER9  :  1; //!<[09] Software Interrupt on line 9
      __IO ONE_BIT  SWIER10 :  1; //!<[10] Software Interrupt on line 10
      __IO ONE_BIT  SWIER11 :  1; //!<[11] Software Interrupt on line 11
      __IO ONE_BIT  SWIER12 :  1; //!<[12] Software Interrupt on line 12
      __IO ONE_BIT  SWIER13 :  1; //!<[13] Software Interrupt on line 13
      __IO ONE_BIT  SWIER14 :  1; //!<[14] Software Interrupt on line 14
      __IO ONE_BIT  SWIER15 :  1; //!<[15] Software Interrupt on line 15
      __IO ONE_BIT  SWIER16 :  1; //!<[16] Software Interrupt on line 16
      __IO ONE_BIT  SWIER17 :  1; //!<[17] Software Interrupt on line 17
           ONE_BIT  UNUSED0 :  1; //!<[18] 
      __IO ONE_BIT  SWIER19 :  1; //!<[19] Software Interrupt on line 19
    } B;
    __IO uint32_t  R;
    explicit SWIER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SWIER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SWIER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union PR_DEF    {  //!< Pending register (EXTI_PR)
    struct {
      __IO ONE_BIT  PR0     :  1; //!<[00] Pending bit 0
      __IO ONE_BIT  PR1     :  1; //!<[01] Pending bit 1
      __IO ONE_BIT  PR2     :  1; //!<[02] Pending bit 2
      __IO ONE_BIT  PR3     :  1; //!<[03] Pending bit 3
      __IO ONE_BIT  PR4     :  1; //!<[04] Pending bit 4
      __IO ONE_BIT  PR5     :  1; //!<[05] Pending bit 5
      __IO ONE_BIT  PR6     :  1; //!<[06] Pending bit 6
      __IO ONE_BIT  PR7     :  1; //!<[07] Pending bit 7
      __IO ONE_BIT  PR8     :  1; //!<[08] Pending bit 8
      __IO ONE_BIT  PR9     :  1; //!<[09] Pending bit 9
      __IO ONE_BIT  PR10    :  1; //!<[10] Pending bit 10
      __IO ONE_BIT  PR11    :  1; //!<[11] Pending bit 11
      __IO ONE_BIT  PR12    :  1; //!<[12] Pending bit 12
      __IO ONE_BIT  PR13    :  1; //!<[13] Pending bit 13
      __IO ONE_BIT  PR14    :  1; //!<[14] Pending bit 14
      __IO ONE_BIT  PR15    :  1; //!<[15] Pending bit 15
      __IO ONE_BIT  PR16    :  1; //!<[16] Pending bit 16
      __IO ONE_BIT  PR17    :  1; //!<[17] Pending bit 17
           ONE_BIT  UNUSED0 :  1; //!<[18] 
      __IO ONE_BIT  PR19    :  1; //!<[19] Pending bit 19
    } B;
    __IO uint32_t  R;
    explicit PR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      PR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      PR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL EXTI REGISTERS INSTANCES
  __IO IMR_DEF               IMR ;  //!< [0000](04)[0x0F940000]
  __IO EMR_DEF               EMR ;  //!< [0004](04)[0x00000000]
  __IO RTSR_DEF             RTSR ;  //!< [0008](04)[0x00000000]
  __IO FTSR_DEF             FTSR ;  //!< [000c](04)[0x00000000]
  __IO SWIER_DEF           SWIER ;  //!< [0010](04)[0x00000000]
  __IO PR_DEF                 PR ;  //!< [0014](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x0018 */

// ////////////////////+++ NVIC +-+//////////////////// //
struct NVIC_Type        { /*!< Nested Vectored Interrupt Controller */
  union ISER_DEF    {  //!< Interrupt Set Enable Register
    struct {
      __IO uint32_t   SETENA : 32; //!<[00] SETENA
    } B;
    __IO uint32_t  R;
    explicit ISER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ISER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ISER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ICER_DEF    {  //!< Interrupt Clear Enable Register
    struct {
      __IO uint32_t   CLRENA : 32; //!<[00] CLRENA
    } B;
    __IO uint32_t  R;
    explicit ICER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ICER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ICER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ISPR_DEF    {  //!< Interrupt Set-Pending Register
    struct {
      __IO uint32_t   SETPEND : 32; //!<[00] SETPEND
    } B;
    __IO uint32_t  R;
    explicit ISPR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ISPR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ISPR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ICPR_DEF    {  //!< Interrupt Clear-Pending Register
    struct {
      __IO uint32_t   CLRPEND : 32; //!<[00] CLRPEND
    } B;
    __IO uint32_t  R;
    explicit ICPR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ICPR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ICPR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IPR0_DEF    {  //!< Interrupt Priority Register 0
    struct {
           uint32_t   UNUSED0 :  6; //!<[00] 
      __IO uint32_t   PRI_00  :  2; //!<[06] PRI_00
           uint32_t   UNUSED1 :  6; //!<[08] 
      __IO uint32_t   PRI_01  :  2; //!<[14] PRI_01
           uint32_t   UNUSED2 :  6; //!<[16] 
      __IO uint32_t   PRI_02  :  2; //!<[22] PRI_02
           uint32_t   UNUSED3 :  6; //!<[24] 
      __IO uint32_t   PRI_03  :  2; //!<[30] PRI_03
    } B;
    __IO uint32_t  R;
    explicit IPR0_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IPR0_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IPR0_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IPR1_DEF    {  //!< Interrupt Priority Register 1
    struct {
           uint32_t   UNUSED0 :  6; //!<[00] 
      __IO uint32_t   PRI_40  :  2; //!<[06] PRI_40
           uint32_t   UNUSED1 :  6; //!<[08] 
      __IO uint32_t   PRI_41  :  2; //!<[14] PRI_41
           uint32_t   UNUSED2 :  6; //!<[16] 
      __IO uint32_t   PRI_42  :  2; //!<[22] PRI_42
           uint32_t   UNUSED3 :  6; //!<[24] 
      __IO uint32_t   PRI_43  :  2; //!<[30] PRI_43
    } B;
    __IO uint32_t  R;
    explicit IPR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IPR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IPR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IPR2_DEF    {  //!< Interrupt Priority Register 2
    struct {
           uint32_t   UNUSED0 :  6; //!<[00] 
      __IO uint32_t   PRI_80  :  2; //!<[06] PRI_80
           uint32_t   UNUSED1 :  6; //!<[08] 
      __IO uint32_t   PRI_81  :  2; //!<[14] PRI_81
           uint32_t   UNUSED2 :  6; //!<[16] 
      __IO uint32_t   PRI_82  :  2; //!<[22] PRI_82
           uint32_t   UNUSED3 :  6; //!<[24] 
      __IO uint32_t   PRI_83  :  2; //!<[30] PRI_83
    } B;
    __IO uint32_t  R;
    explicit IPR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IPR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IPR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IPR3_DEF    {  //!< Interrupt Priority Register 3
    struct {
           uint32_t   UNUSED0 :  6; //!<[00] 
      __IO uint32_t   PRI_120 :  2; //!<[06] PRI_120
           uint32_t   UNUSED1 :  6; //!<[08] 
      __IO uint32_t   PRI_121 :  2; //!<[14] PRI_121
           uint32_t   UNUSED2 :  6; //!<[16] 
      __IO uint32_t   PRI_122 :  2; //!<[22] PRI_122
           uint32_t   UNUSED3 :  6; //!<[24] 
      __IO uint32_t   PRI_123 :  2; //!<[30] PRI_123
    } B;
    __IO uint32_t  R;
    explicit IPR3_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IPR3_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IPR3_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IPR4_DEF    {  //!< Interrupt Priority Register 4
    struct {
           uint32_t   UNUSED0 :  6; //!<[00] 
      __IO uint32_t   PRI_160 :  2; //!<[06] PRI_160
           uint32_t   UNUSED1 :  6; //!<[08] 
      __IO uint32_t   PRI_161 :  2; //!<[14] PRI_161
           uint32_t   UNUSED2 :  6; //!<[16] 
      __IO uint32_t   PRI_162 :  2; //!<[22] PRI_162
           uint32_t   UNUSED3 :  6; //!<[24] 
      __IO uint32_t   PRI_163 :  2; //!<[30] PRI_163
    } B;
    __IO uint32_t  R;
    explicit IPR4_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IPR4_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IPR4_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IPR5_DEF    {  //!< Interrupt Priority Register 5
    struct {
           uint32_t   UNUSED0 :  6; //!<[00] 
      __IO uint32_t   PRI_200 :  2; //!<[06] PRI_200
           uint32_t   UNUSED1 :  6; //!<[08] 
      __IO uint32_t   PRI_201 :  2; //!<[14] PRI_201
           uint32_t   UNUSED2 :  6; //!<[16] 
      __IO uint32_t   PRI_202 :  2; //!<[22] PRI_202
           uint32_t   UNUSED3 :  6; //!<[24] 
      __IO uint32_t   PRI_203 :  2; //!<[30] PRI_203
    } B;
    __IO uint32_t  R;
    explicit IPR5_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IPR5_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IPR5_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IPR6_DEF    {  //!< Interrupt Priority Register 6
    struct {
           uint32_t   UNUSED0 :  6; //!<[00] 
      __IO uint32_t   PRI_240 :  2; //!<[06] PRI_240
           uint32_t   UNUSED1 :  6; //!<[08] 
      __IO uint32_t   PRI_241 :  2; //!<[14] PRI_241
           uint32_t   UNUSED2 :  6; //!<[16] 
      __IO uint32_t   PRI_242 :  2; //!<[22] PRI_242
           uint32_t   UNUSED3 :  6; //!<[24] 
      __IO uint32_t   PRI_243 :  2; //!<[30] PRI_243
    } B;
    __IO uint32_t  R;
    explicit IPR6_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IPR6_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IPR6_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IPR7_DEF    {  //!< Interrupt Priority Register 7
    struct {
           uint32_t   UNUSED0 :  6; //!<[00] 
      __IO uint32_t   PRI_280 :  2; //!<[06] PRI_280
           uint32_t   UNUSED1 :  6; //!<[08] 
      __IO uint32_t   PRI_281 :  2; //!<[14] PRI_281
           uint32_t   UNUSED2 :  6; //!<[16] 
      __IO uint32_t   PRI_282 :  2; //!<[22] PRI_282
           uint32_t   UNUSED3 :  6; //!<[24] 
      __IO uint32_t   PRI_283 :  2; //!<[30] PRI_283
    } B;
    __IO uint32_t  R;
    explicit IPR7_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IPR7_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IPR7_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL NVIC REGISTERS INSTANCES
  __IO ISER_DEF               ISER ;  //!< [0000](04)[0x00000000]
       uint32_t          UNUSED0 [31];  //!< [0004](7c)[0xFFFFFFFF]
  __IO ICER_DEF               ICER ;  //!< [0080](04)[0x00000000]
       uint32_t          UNUSED1 [31];  //!< [0084](7c)[0xFFFFFFFF]
  __IO ISPR_DEF               ISPR ;  //!< [0100](04)[0x00000000]
       uint32_t          UNUSED2 [31];  //!< [0104](7c)[0xFFFFFFFF]
  __IO ICPR_DEF               ICPR ;  //!< [0180](04)[0x00000000]
       uint32_t          UNUSED3 [95];  //!< [0184](17c)[0xFFFFFFFF]
  __IO IPR0_DEF               IPR0 ;  //!< [0300](04)[0x00000000]
  __IO IPR1_DEF               IPR1 ;  //!< [0304](04)[0x00000000]
  __IO IPR2_DEF               IPR2 ;  //!< [0308](04)[0x00000000]
  __IO IPR3_DEF               IPR3 ;  //!< [030c](04)[0x00000000]
  __IO IPR4_DEF               IPR4 ;  //!< [0310](04)[0x00000000]
  __IO IPR5_DEF               IPR5 ;  //!< [0314](04)[0x00000000]
  __IO IPR6_DEF               IPR6 ;  //!< [0318](04)[0x00000000]
  __IO IPR7_DEF               IPR7 ;  //!< [031c](04)[0x00000000]
}; /* total size = 0x033d, struct size = 0x0320 */

// ////////////////////+++ DMA1 +-+//////////////////// //
struct DMA1_Type        { /*!< DMA controller */
  union ISR_DEF     {  //!< DMA interrupt status register (DMA_ISR)
    struct {
      __I  ONE_BIT  GIF1  :  1; //!<[00] Channel 1 Global interrupt flag
      __I  ONE_BIT  TCIF1 :  1; //!<[01] Channel 1 Transfer Complete flag
      __I  ONE_BIT  HTIF1 :  1; //!<[02] Channel 1 Half Transfer Complete flag
      __I  ONE_BIT  TEIF1 :  1; //!<[03] Channel 1 Transfer Error flag
      __I  ONE_BIT  GIF2  :  1; //!<[04] Channel 2 Global interrupt flag
      __I  ONE_BIT  TCIF2 :  1; //!<[05] Channel 2 Transfer Complete flag
      __I  ONE_BIT  HTIF2 :  1; //!<[06] Channel 2 Half Transfer Complete flag
      __I  ONE_BIT  TEIF2 :  1; //!<[07] Channel 2 Transfer Error flag
      __I  ONE_BIT  GIF3  :  1; //!<[08] Channel 3 Global interrupt flag
      __I  ONE_BIT  TCIF3 :  1; //!<[09] Channel 3 Transfer Complete flag
      __I  ONE_BIT  HTIF3 :  1; //!<[10] Channel 3 Half Transfer Complete flag
      __I  ONE_BIT  TEIF3 :  1; //!<[11] Channel 3 Transfer Error flag
      __I  ONE_BIT  GIF4  :  1; //!<[12] Channel 4 Global interrupt flag
      __I  ONE_BIT  TCIF4 :  1; //!<[13] Channel 4 Transfer Complete flag
      __I  ONE_BIT  HTIF4 :  1; //!<[14] Channel 4 Half Transfer Complete flag
      __I  ONE_BIT  TEIF4 :  1; //!<[15] Channel 4 Transfer Error flag
      __I  ONE_BIT  GIF5  :  1; //!<[16] Channel 5 Global interrupt flag
      __I  ONE_BIT  TCIF5 :  1; //!<[17] Channel 5 Transfer Complete flag
      __I  ONE_BIT  HTIF5 :  1; //!<[18] Channel 5 Half Transfer Complete flag
      __I  ONE_BIT  TEIF5 :  1; //!<[19] Channel 5 Transfer Error flag
      __I  ONE_BIT  GIF6  :  1; //!<[20] Channel 6 Global interrupt flag
      __I  ONE_BIT  TCIF6 :  1; //!<[21] Channel 6 Transfer Complete flag
      __I  ONE_BIT  HTIF6 :  1; //!<[22] Channel 6 Half Transfer Complete flag
      __I  ONE_BIT  TEIF6 :  1; //!<[23] Channel 6 Transfer Error flag
      __I  ONE_BIT  GIF7  :  1; //!<[24] Channel 7 Global interrupt flag
      __I  ONE_BIT  TCIF7 :  1; //!<[25] Channel 7 Transfer Complete flag
      __I  ONE_BIT  HTIF7 :  1; //!<[26] Channel 7 Half Transfer Complete flag
      __I  ONE_BIT  TEIF7 :  1; //!<[27] Channel 7 Transfer Error flag
    } B;
    __I  uint32_t  R;

    explicit ISR_DEF (volatile ISR_DEF & o) noexcept { R = o.R; };
  };
  union IFCR_DEF    {  //!< DMA interrupt flag clear register (DMA_IFCR)
    struct {
      __O  ONE_BIT  CGIF1  :  1; //!<[00] Channel 1 Global interrupt clear
      __O  ONE_BIT  CTCIF1 :  1; //!<[01] Channel 1 Transfer Complete clear
      __O  ONE_BIT  CHTIF1 :  1; //!<[02] Channel 1 Half Transfer clear
      __O  ONE_BIT  CTEIF1 :  1; //!<[03] Channel 1 Transfer Error clear
      __O  ONE_BIT  CGIF2  :  1; //!<[04] Channel 2 Global interrupt clear
      __O  ONE_BIT  CTCIF2 :  1; //!<[05] Channel 2 Transfer Complete clear
      __O  ONE_BIT  CHTIF2 :  1; //!<[06] Channel 2 Half Transfer clear
      __O  ONE_BIT  CTEIF2 :  1; //!<[07] Channel 2 Transfer Error clear
      __O  ONE_BIT  CGIF3  :  1; //!<[08] Channel 3 Global interrupt clear
      __O  ONE_BIT  CTCIF3 :  1; //!<[09] Channel 3 Transfer Complete clear
      __O  ONE_BIT  CHTIF3 :  1; //!<[10] Channel 3 Half Transfer clear
      __O  ONE_BIT  CTEIF3 :  1; //!<[11] Channel 3 Transfer Error clear
      __O  ONE_BIT  CGIF4  :  1; //!<[12] Channel 4 Global interrupt clear
      __O  ONE_BIT  CTCIF4 :  1; //!<[13] Channel 4 Transfer Complete clear
      __O  ONE_BIT  CHTIF4 :  1; //!<[14] Channel 4 Half Transfer clear
      __O  ONE_BIT  CTEIF4 :  1; //!<[15] Channel 4 Transfer Error clear
      __O  ONE_BIT  CGIF5  :  1; //!<[16] Channel 5 Global interrupt clear
      __O  ONE_BIT  CTCIF5 :  1; //!<[17] Channel 5 Transfer Complete clear
      __O  ONE_BIT  CHTIF5 :  1; //!<[18] Channel 5 Half Transfer clear
      __O  ONE_BIT  CTEIF5 :  1; //!<[19] Channel 5 Transfer Error clear
      __O  ONE_BIT  CGIF6  :  1; //!<[20] Channel 6 Global interrupt clear
      __O  ONE_BIT  CTCIF6 :  1; //!<[21] Channel 6 Transfer Complete clear
      __O  ONE_BIT  CHTIF6 :  1; //!<[22] Channel 6 Half Transfer clear
      __O  ONE_BIT  CTEIF6 :  1; //!<[23] Channel 6 Transfer Error clear
      __O  ONE_BIT  CGIF7  :  1; //!<[24] Channel 7 Global interrupt clear
      __O  ONE_BIT  CTCIF7 :  1; //!<[25] Channel 7 Transfer Complete clear
      __O  ONE_BIT  CHTIF7 :  1; //!<[26] Channel 7 Half Transfer clear
      __O  ONE_BIT  CTEIF7 :  1; //!<[27] Channel 7 Transfer Error clear
    } B;
    __O  uint32_t  R;
    explicit IFCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IFCR_DEF r;
      R = f (r);
    }
  };
  union CCR1_DEF    {  //!< DMA channel configuration register (DMA_CCR)
    struct {
      __IO ONE_BIT    EN      :  1; //!<[00] Channel enable
      __IO ONE_BIT    TCIE    :  1; //!<[01] Transfer complete interrupt enable
      __IO ONE_BIT    HTIE    :  1; //!<[02] Half Transfer interrupt enable
      __IO ONE_BIT    TEIE    :  1; //!<[03] Transfer error interrupt enable
      __IO ONE_BIT    DIR     :  1; //!<[04] Data transfer direction
      __IO ONE_BIT    CIRC    :  1; //!<[05] Circular mode
      __IO ONE_BIT    PINC    :  1; //!<[06] Peripheral increment mode
      __IO ONE_BIT    MINC    :  1; //!<[07] Memory increment mode
      __IO uint32_t   PSIZE   :  2; //!<[08] Peripheral size
      __IO uint32_t   MSIZE   :  2; //!<[10] Memory size
      __IO uint32_t   PL      :  2; //!<[12] Channel Priority level
      __IO ONE_BIT    MEM2MEM :  1; //!<[14] Memory to memory mode
    } B;
    __IO uint32_t  R;
    explicit CCR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CNDTR1_DEF  {  //!< DMA channel 1 number of data register
    struct {
      __IO uint32_t   NDT : 16; //!<[00] Number of data to transfer
    } B;
    __IO uint32_t  R;
    explicit CNDTR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CNDTR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CNDTR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CPAR1_DEF   {  //!< DMA channel 1 peripheral address register
    struct {
      __IO uint32_t   PA : 32; //!<[00] Peripheral address
    } B;
    __IO uint32_t  R;
    explicit CPAR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CPAR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CPAR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CMAR1_DEF   {  //!< DMA channel 1 memory address register
    struct {
      __IO uint32_t   MA : 32; //!<[00] Memory address
    } B;
    __IO uint32_t  R;
    explicit CMAR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CMAR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CMAR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR2_DEF    {  //!< DMA channel configuration register (DMA_CCR)
    struct {
      __IO ONE_BIT    EN      :  1; //!<[00] Channel enable
      __IO ONE_BIT    TCIE    :  1; //!<[01] Transfer complete interrupt enable
      __IO ONE_BIT    HTIE    :  1; //!<[02] Half Transfer interrupt enable
      __IO ONE_BIT    TEIE    :  1; //!<[03] Transfer error interrupt enable
      __IO ONE_BIT    DIR     :  1; //!<[04] Data transfer direction
      __IO ONE_BIT    CIRC    :  1; //!<[05] Circular mode
      __IO ONE_BIT    PINC    :  1; //!<[06] Peripheral increment mode
      __IO ONE_BIT    MINC    :  1; //!<[07] Memory increment mode
      __IO uint32_t   PSIZE   :  2; //!<[08] Peripheral size
      __IO uint32_t   MSIZE   :  2; //!<[10] Memory size
      __IO uint32_t   PL      :  2; //!<[12] Channel Priority level
      __IO ONE_BIT    MEM2MEM :  1; //!<[14] Memory to memory mode
    } B;
    __IO uint32_t  R;
    explicit CCR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CNDTR2_DEF  {  //!< DMA channel 2 number of data register
    struct {
      __IO uint32_t   NDT : 16; //!<[00] Number of data to transfer
    } B;
    __IO uint32_t  R;
    explicit CNDTR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CNDTR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CNDTR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CPAR2_DEF   {  //!< DMA channel 2 peripheral address register
    struct {
      __IO uint32_t   PA : 32; //!<[00] Peripheral address
    } B;
    __IO uint32_t  R;
    explicit CPAR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CPAR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CPAR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CMAR2_DEF   {  //!< DMA channel 2 memory address register
    struct {
      __IO uint32_t   MA : 32; //!<[00] Memory address
    } B;
    __IO uint32_t  R;
    explicit CMAR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CMAR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CMAR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR3_DEF    {  //!< DMA channel configuration register (DMA_CCR)
    struct {
      __IO ONE_BIT    EN      :  1; //!<[00] Channel enable
      __IO ONE_BIT    TCIE    :  1; //!<[01] Transfer complete interrupt enable
      __IO ONE_BIT    HTIE    :  1; //!<[02] Half Transfer interrupt enable
      __IO ONE_BIT    TEIE    :  1; //!<[03] Transfer error interrupt enable
      __IO ONE_BIT    DIR     :  1; //!<[04] Data transfer direction
      __IO ONE_BIT    CIRC    :  1; //!<[05] Circular mode
      __IO ONE_BIT    PINC    :  1; //!<[06] Peripheral increment mode
      __IO ONE_BIT    MINC    :  1; //!<[07] Memory increment mode
      __IO uint32_t   PSIZE   :  2; //!<[08] Peripheral size
      __IO uint32_t   MSIZE   :  2; //!<[10] Memory size
      __IO uint32_t   PL      :  2; //!<[12] Channel Priority level
      __IO ONE_BIT    MEM2MEM :  1; //!<[14] Memory to memory mode
    } B;
    __IO uint32_t  R;
    explicit CCR3_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR3_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR3_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CNDTR3_DEF  {  //!< DMA channel 3 number of data register
    struct {
      __IO uint32_t   NDT : 16; //!<[00] Number of data to transfer
    } B;
    __IO uint32_t  R;
    explicit CNDTR3_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CNDTR3_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CNDTR3_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CPAR3_DEF   {  //!< DMA channel 3 peripheral address register
    struct {
      __IO uint32_t   PA : 32; //!<[00] Peripheral address
    } B;
    __IO uint32_t  R;
    explicit CPAR3_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CPAR3_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CPAR3_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CMAR3_DEF   {  //!< DMA channel 3 memory address register
    struct {
      __IO uint32_t   MA : 32; //!<[00] Memory address
    } B;
    __IO uint32_t  R;
    explicit CMAR3_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CMAR3_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CMAR3_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR4_DEF    {  //!< DMA channel configuration register (DMA_CCR)
    struct {
      __IO ONE_BIT    EN      :  1; //!<[00] Channel enable
      __IO ONE_BIT    TCIE    :  1; //!<[01] Transfer complete interrupt enable
      __IO ONE_BIT    HTIE    :  1; //!<[02] Half Transfer interrupt enable
      __IO ONE_BIT    TEIE    :  1; //!<[03] Transfer error interrupt enable
      __IO ONE_BIT    DIR     :  1; //!<[04] Data transfer direction
      __IO ONE_BIT    CIRC    :  1; //!<[05] Circular mode
      __IO ONE_BIT    PINC    :  1; //!<[06] Peripheral increment mode
      __IO ONE_BIT    MINC    :  1; //!<[07] Memory increment mode
      __IO uint32_t   PSIZE   :  2; //!<[08] Peripheral size
      __IO uint32_t   MSIZE   :  2; //!<[10] Memory size
      __IO uint32_t   PL      :  2; //!<[12] Channel Priority level
      __IO ONE_BIT    MEM2MEM :  1; //!<[14] Memory to memory mode
    } B;
    __IO uint32_t  R;
    explicit CCR4_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR4_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR4_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CNDTR4_DEF  {  //!< DMA channel 4 number of data register
    struct {
      __IO uint32_t   NDT : 16; //!<[00] Number of data to transfer
    } B;
    __IO uint32_t  R;
    explicit CNDTR4_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CNDTR4_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CNDTR4_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CPAR4_DEF   {  //!< DMA channel 4 peripheral address register
    struct {
      __IO uint32_t   PA : 32; //!<[00] Peripheral address
    } B;
    __IO uint32_t  R;
    explicit CPAR4_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CPAR4_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CPAR4_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CMAR4_DEF   {  //!< DMA channel 4 memory address register
    struct {
      __IO uint32_t   MA : 32; //!<[00] Memory address
    } B;
    __IO uint32_t  R;
    explicit CMAR4_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CMAR4_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CMAR4_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR5_DEF    {  //!< DMA channel configuration register (DMA_CCR)
    struct {
      __IO ONE_BIT    EN      :  1; //!<[00] Channel enable
      __IO ONE_BIT    TCIE    :  1; //!<[01] Transfer complete interrupt enable
      __IO ONE_BIT    HTIE    :  1; //!<[02] Half Transfer interrupt enable
      __IO ONE_BIT    TEIE    :  1; //!<[03] Transfer error interrupt enable
      __IO ONE_BIT    DIR     :  1; //!<[04] Data transfer direction
      __IO ONE_BIT    CIRC    :  1; //!<[05] Circular mode
      __IO ONE_BIT    PINC    :  1; //!<[06] Peripheral increment mode
      __IO ONE_BIT    MINC    :  1; //!<[07] Memory increment mode
      __IO uint32_t   PSIZE   :  2; //!<[08] Peripheral size
      __IO uint32_t   MSIZE   :  2; //!<[10] Memory size
      __IO uint32_t   PL      :  2; //!<[12] Channel Priority level
      __IO ONE_BIT    MEM2MEM :  1; //!<[14] Memory to memory mode
    } B;
    __IO uint32_t  R;
    explicit CCR5_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR5_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR5_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CNDTR5_DEF  {  //!< DMA channel 5 number of data register
    struct {
      __IO uint32_t   NDT : 16; //!<[00] Number of data to transfer
    } B;
    __IO uint32_t  R;
    explicit CNDTR5_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CNDTR5_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CNDTR5_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CPAR5_DEF   {  //!< DMA channel 5 peripheral address register
    struct {
      __IO uint32_t   PA : 32; //!<[00] Peripheral address
    } B;
    __IO uint32_t  R;
    explicit CPAR5_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CPAR5_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CPAR5_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CMAR5_DEF   {  //!< DMA channel 5 memory address register
    struct {
      __IO uint32_t   MA : 32; //!<[00] Memory address
    } B;
    __IO uint32_t  R;
    explicit CMAR5_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CMAR5_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CMAR5_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR6_DEF    {  //!< DMA channel configuration register (DMA_CCR)
    struct {
      __IO ONE_BIT    EN      :  1; //!<[00] Channel enable
      __IO ONE_BIT    TCIE    :  1; //!<[01] Transfer complete interrupt enable
      __IO ONE_BIT    HTIE    :  1; //!<[02] Half Transfer interrupt enable
      __IO ONE_BIT    TEIE    :  1; //!<[03] Transfer error interrupt enable
      __IO ONE_BIT    DIR     :  1; //!<[04] Data transfer direction
      __IO ONE_BIT    CIRC    :  1; //!<[05] Circular mode
      __IO ONE_BIT    PINC    :  1; //!<[06] Peripheral increment mode
      __IO ONE_BIT    MINC    :  1; //!<[07] Memory increment mode
      __IO uint32_t   PSIZE   :  2; //!<[08] Peripheral size
      __IO uint32_t   MSIZE   :  2; //!<[10] Memory size
      __IO uint32_t   PL      :  2; //!<[12] Channel Priority level
      __IO ONE_BIT    MEM2MEM :  1; //!<[14] Memory to memory mode
    } B;
    __IO uint32_t  R;
    explicit CCR6_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR6_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR6_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CNDTR6_DEF  {  //!< DMA channel 6 number of data register
    struct {
      __IO uint32_t   NDT : 16; //!<[00] Number of data to transfer
    } B;
    __IO uint32_t  R;
    explicit CNDTR6_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CNDTR6_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CNDTR6_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CPAR6_DEF   {  //!< DMA channel 6 peripheral address register
    struct {
      __IO uint32_t   PA : 32; //!<[00] Peripheral address
    } B;
    __IO uint32_t  R;
    explicit CPAR6_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CPAR6_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CPAR6_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CMAR6_DEF   {  //!< DMA channel 6 memory address register
    struct {
      __IO uint32_t   MA : 32; //!<[00] Memory address
    } B;
    __IO uint32_t  R;
    explicit CMAR6_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CMAR6_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CMAR6_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR7_DEF    {  //!< DMA channel configuration register (DMA_CCR)
    struct {
      __IO ONE_BIT    EN      :  1; //!<[00] Channel enable
      __IO ONE_BIT    TCIE    :  1; //!<[01] Transfer complete interrupt enable
      __IO ONE_BIT    HTIE    :  1; //!<[02] Half Transfer interrupt enable
      __IO ONE_BIT    TEIE    :  1; //!<[03] Transfer error interrupt enable
      __IO ONE_BIT    DIR     :  1; //!<[04] Data transfer direction
      __IO ONE_BIT    CIRC    :  1; //!<[05] Circular mode
      __IO ONE_BIT    PINC    :  1; //!<[06] Peripheral increment mode
      __IO ONE_BIT    MINC    :  1; //!<[07] Memory increment mode
      __IO uint32_t   PSIZE   :  2; //!<[08] Peripheral size
      __IO uint32_t   MSIZE   :  2; //!<[10] Memory size
      __IO uint32_t   PL      :  2; //!<[12] Channel Priority level
      __IO ONE_BIT    MEM2MEM :  1; //!<[14] Memory to memory mode
    } B;
    __IO uint32_t  R;
    explicit CCR7_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR7_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR7_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CNDTR7_DEF  {  //!< DMA channel 7 number of data register
    struct {
      __IO uint32_t   NDT : 16; //!<[00] Number of data to transfer
    } B;
    __IO uint32_t  R;
    explicit CNDTR7_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CNDTR7_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CNDTR7_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CPAR7_DEF   {  //!< DMA channel 7 peripheral address register
    struct {
      __IO uint32_t   PA : 32; //!<[00] Peripheral address
    } B;
    __IO uint32_t  R;
    explicit CPAR7_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CPAR7_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CPAR7_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CMAR7_DEF   {  //!< DMA channel 7 memory address register
    struct {
      __IO uint32_t   MA : 32; //!<[00] Memory address
    } B;
    __IO uint32_t  R;
    explicit CMAR7_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CMAR7_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CMAR7_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL DMA1 REGISTERS INSTANCES
  __I  ISR_DEF                 ISR ;  //!< [0000](04)[0x00000000]
  __O  IFCR_DEF               IFCR ;  //!< [0004](04)[0x00000000]
  __IO CCR1_DEF               CCR1 ;  //!< [0008](04)[0x00000000]
  __IO CNDTR1_DEF           CNDTR1 ;  //!< [000c](04)[0x00000000]
  __IO CPAR1_DEF             CPAR1 ;  //!< [0010](04)[0x00000000]
  __IO CMAR1_DEF             CMAR1 ;  //!< [0014](04)[0x00000000]
       uint32_t          UNUSED0 ;  //!< [0018](04)[0xFFFFFFFF]
  __IO CCR2_DEF               CCR2 ;  //!< [001c](04)[0x00000000]
  __IO CNDTR2_DEF           CNDTR2 ;  //!< [0020](04)[0x00000000]
  __IO CPAR2_DEF             CPAR2 ;  //!< [0024](04)[0x00000000]
  __IO CMAR2_DEF             CMAR2 ;  //!< [0028](04)[0x00000000]
       uint32_t          UNUSED1 ;  //!< [002c](04)[0xFFFFFFFF]
  __IO CCR3_DEF               CCR3 ;  //!< [0030](04)[0x00000000]
  __IO CNDTR3_DEF           CNDTR3 ;  //!< [0034](04)[0x00000000]
  __IO CPAR3_DEF             CPAR3 ;  //!< [0038](04)[0x00000000]
  __IO CMAR3_DEF             CMAR3 ;  //!< [003c](04)[0x00000000]
       uint32_t          UNUSED2 ;  //!< [0040](04)[0xFFFFFFFF]
  __IO CCR4_DEF               CCR4 ;  //!< [0044](04)[0x00000000]
  __IO CNDTR4_DEF           CNDTR4 ;  //!< [0048](04)[0x00000000]
  __IO CPAR4_DEF             CPAR4 ;  //!< [004c](04)[0x00000000]
  __IO CMAR4_DEF             CMAR4 ;  //!< [0050](04)[0x00000000]
       uint32_t          UNUSED3 ;  //!< [0054](04)[0xFFFFFFFF]
  __IO CCR5_DEF               CCR5 ;  //!< [0058](04)[0x00000000]
  __IO CNDTR5_DEF           CNDTR5 ;  //!< [005c](04)[0x00000000]
  __IO CPAR5_DEF             CPAR5 ;  //!< [0060](04)[0x00000000]
  __IO CMAR5_DEF             CMAR5 ;  //!< [0064](04)[0x00000000]
       uint32_t          UNUSED4 ;  //!< [0068](04)[0xFFFFFFFF]
  __IO CCR6_DEF               CCR6 ;  //!< [006c](04)[0x00000000]
  __IO CNDTR6_DEF           CNDTR6 ;  //!< [0070](04)[0x00000000]
  __IO CPAR6_DEF             CPAR6 ;  //!< [0074](04)[0x00000000]
  __IO CMAR6_DEF             CMAR6 ;  //!< [0078](04)[0x00000000]
       uint32_t          UNUSED5 ;  //!< [007c](04)[0xFFFFFFFF]
  __IO CCR7_DEF               CCR7 ;  //!< [0080](04)[0x00000000]
  __IO CNDTR7_DEF           CNDTR7 ;  //!< [0084](04)[0x00000000]
  __IO CPAR7_DEF             CPAR7 ;  //!< [0088](04)[0x00000000]
  __IO CMAR7_DEF             CMAR7 ;  //!< [008c](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x0090 */

// ////////////////////+++ RCC +-+//////////////////// //
struct RCC_Type         { /*!< Reset and clock control */
  union CR_DEF       {  //!< Clock control register
    struct {
      __IO ONE_BIT    HSION   :  1; //!<[00] Internal High Speed clock enable
      __I  ONE_BIT    HSIRDY  :  1; //!<[01] Internal High Speed clock ready flag
           ONE_BIT    UNUSED0 :  1; //!<[02] 
      __IO uint32_t   HSITRIM :  5; //!<[03] Internal High Speed clock trimming
      __I  uint32_t   HSICAL  :  8; //!<[08] Internal High Speed clock Calibration
      __IO ONE_BIT    HSEON   :  1; //!<[16] External High Speed clock enable
      __I  ONE_BIT    HSERDY  :  1; //!<[17] External High Speed clock ready flag
      __IO ONE_BIT    HSEBYP  :  1; //!<[18] External High Speed clock Bypass
      __IO ONE_BIT    CSSON   :  1; //!<[19] Clock Security System enable
           uint32_t   UNUSED1 :  4; //!<[20] 
      __IO ONE_BIT    PLLON   :  1; //!<[24] PLL enable
      __I  ONE_BIT    PLLRDY  :  1; //!<[25] PLL clock ready flag
    } B;
    __IO uint32_t  R;
    explicit CR_DEF () noexcept { R = 0x00000083u; }
    template<typename F> void setbit (F f) volatile {
      CR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CFGR_DEF     {  //!< Clock configuration register (RCC_CFGR)
    struct {
      __IO uint32_t   SW       :  2; //!<[00] System clock Switch
      __I  uint32_t   SWS      :  2; //!<[02] System Clock Switch Status
      __IO uint32_t   HPRE     :  4; //!<[04] AHB prescaler
      __IO uint32_t   PPRE     :  3; //!<[08] APB Low speed prescaler (APB1)
           uint32_t   UNUSED0  :  3; //!<[11] 
      __IO ONE_BIT    ADCPRE   :  1; //!<[14] ADC prescaler
      __IO uint32_t   PLLSRC   :  2; //!<[15] PLL input clock source
      __IO ONE_BIT    PLLXTPRE :  1; //!<[17] HSE divider for PLL entry
      __IO uint32_t   PLLMUL   :  4; //!<[18] PLL Multiplication Factor
           uint32_t   UNUSED1  :  2; //!<[22] 
      __IO uint32_t   MCO      :  3; //!<[24] Microcontroller clock output
           ONE_BIT    UNUSED2  :  1; //!<[27] 
      __IO uint32_t   MCOPRE   :  3; //!<[28] Microcontroller Clock Output Prescaler
      __IO ONE_BIT    PLLNODIV :  1; //!<[31] PLL clock not divided for MCO
    } B;
    __IO uint32_t  R;
    explicit CFGR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CFGR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CFGR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CIR_DEF      {  //!< Clock interrupt register (RCC_CIR)
    struct {
      __I  ONE_BIT  LSIRDYF    :  1; //!<[00] LSI Ready Interrupt flag
      __I  ONE_BIT  LSERDYF    :  1; //!<[01] LSE Ready Interrupt flag
      __I  ONE_BIT  HSIRDYF    :  1; //!<[02] HSI Ready Interrupt flag
      __I  ONE_BIT  HSERDYF    :  1; //!<[03] HSE Ready Interrupt flag
      __I  ONE_BIT  PLLRDYF    :  1; //!<[04] PLL Ready Interrupt flag
      __I  ONE_BIT  HSI14RDYF  :  1; //!<[05] HSI14 ready interrupt flag
      __I  ONE_BIT  HSI48RDYF  :  1; //!<[06] HSI48 ready interrupt flag
      __I  ONE_BIT  CSSF       :  1; //!<[07] Clock Security System Interrupt flag
      __IO ONE_BIT  LSIRDYIE   :  1; //!<[08] LSI Ready Interrupt Enable
      __IO ONE_BIT  LSERDYIE   :  1; //!<[09] LSE Ready Interrupt Enable
      __IO ONE_BIT  HSIRDYIE   :  1; //!<[10] HSI Ready Interrupt Enable
      __IO ONE_BIT  HSERDYIE   :  1; //!<[11] HSE Ready Interrupt Enable
      __IO ONE_BIT  PLLRDYIE   :  1; //!<[12] PLL Ready Interrupt Enable
      __IO ONE_BIT  HSI14RDYE  :  1; //!<[13] HSI14 ready interrupt enable
      __IO ONE_BIT  HSI48RDYIE :  1; //!<[14] HSI48 ready interrupt enable
           ONE_BIT  UNUSED0    :  1; //!<[15] 
      __O  ONE_BIT  LSIRDYC    :  1; //!<[16] LSI Ready Interrupt Clear
      __O  ONE_BIT  LSERDYC    :  1; //!<[17] LSE Ready Interrupt Clear
      __O  ONE_BIT  HSIRDYC    :  1; //!<[18] HSI Ready Interrupt Clear
      __O  ONE_BIT  HSERDYC    :  1; //!<[19] HSE Ready Interrupt Clear
      __O  ONE_BIT  PLLRDYC    :  1; //!<[20] PLL Ready Interrupt Clear
      __O  ONE_BIT  HSI14RDYC  :  1; //!<[21] HSI 14 MHz Ready Interrupt Clear
      __O  ONE_BIT  HSI48RDYC  :  1; //!<[22] HSI48 Ready Interrupt Clear
      __O  ONE_BIT  CSSC       :  1; //!<[23] Clock security system interrupt clear
    } B;
    __IO uint32_t  R;
    explicit CIR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CIR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CIR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union APB2RSTR_DEF {  //!< APB2 peripheral reset register (RCC_APB2RSTR)
    struct {
      __IO ONE_BIT    SYSCFGRST :  1; //!<[00] SYSCFG and COMP reset
           uint32_t   UNUSED0   :  8; //!<[01] 
      __IO ONE_BIT    ADCRST    :  1; //!<[09] ADC interface reset
           ONE_BIT    UNUSED1   :  1; //!<[10] 
      __IO ONE_BIT    TIM1RST   :  1; //!<[11] TIM1 timer reset
      __IO ONE_BIT    SPI1RST   :  1; //!<[12] SPI 1 reset
           ONE_BIT    UNUSED2   :  1; //!<[13] 
      __IO ONE_BIT    USART1RST :  1; //!<[14] USART1 reset
           ONE_BIT    UNUSED3   :  1; //!<[15] 
      __IO ONE_BIT    TIM15RST  :  1; //!<[16] TIM15 timer reset
      __IO ONE_BIT    TIM16RST  :  1; //!<[17] TIM16 timer reset
      __IO ONE_BIT    TIM17RST  :  1; //!<[18] TIM17 timer reset
           uint32_t   UNUSED4   :  3; //!<[19] 
      __IO ONE_BIT    DBGMCURST :  1; //!<[22] Debug MCU reset
    } B;
    __IO uint32_t  R;
    explicit APB2RSTR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      APB2RSTR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      APB2RSTR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union APB1RSTR_DEF {  //!< APB1 peripheral reset register (RCC_APB1RSTR)
    struct {
      __IO ONE_BIT    TIM2RST   :  1; //!<[00] Timer 2 reset
      __IO ONE_BIT    TIM3RST   :  1; //!<[01] Timer 3 reset
           uint32_t   UNUSED0   :  2; //!<[02] 
      __IO ONE_BIT    TIM6RST   :  1; //!<[04] Timer 6 reset
      __IO ONE_BIT    TIM7RST   :  1; //!<[05] TIM7 timer reset
           uint32_t   UNUSED1   :  2; //!<[06] 
      __IO ONE_BIT    TIM14RST  :  1; //!<[08] Timer 14 reset
           uint32_t   UNUSED2   :  2; //!<[09] 
      __IO ONE_BIT    WWDGRST   :  1; //!<[11] Window watchdog reset
           uint32_t   UNUSED3   :  2; //!<[12] 
      __IO ONE_BIT    SPI2RST   :  1; //!<[14] SPI2 reset
           uint32_t   UNUSED4   :  2; //!<[15] 
      __IO ONE_BIT    USART2RST :  1; //!<[17] USART 2 reset
      __IO ONE_BIT    USART3RST :  1; //!<[18] USART3 reset
      __IO ONE_BIT    USART4RST :  1; //!<[19] USART4 reset
      __IO ONE_BIT    USART5RST :  1; //!<[20] USART5 reset
      __IO ONE_BIT    I2C1RST   :  1; //!<[21] I2C1 reset
      __IO ONE_BIT    I2C2RST   :  1; //!<[22] I2C2 reset
      __IO ONE_BIT    USBRST    :  1; //!<[23] USB interface reset
           ONE_BIT    UNUSED5   :  1; //!<[24] 
      __IO ONE_BIT    CANRST    :  1; //!<[25] CAN interface reset
           ONE_BIT    UNUSED6   :  1; //!<[26] 
      __IO ONE_BIT    CRSRST    :  1; //!<[27] Clock Recovery System interface reset
      __IO ONE_BIT    PWRRST    :  1; //!<[28] Power interface reset
      __IO ONE_BIT    DACRST    :  1; //!<[29] DAC interface reset
      __IO ONE_BIT    CECRST    :  1; //!<[30] HDMI CEC reset
    } B;
    __IO uint32_t  R;
    explicit APB1RSTR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      APB1RSTR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      APB1RSTR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union AHBENR_DEF   {  //!< AHB Peripheral Clock enable register (RCC_AHBENR)
    struct {
      __IO ONE_BIT    DMA1EN  :  1; //!<[00] DMA1 clock enable
      __IO ONE_BIT    DMA2EN  :  1; //!<[01] DMA2 clock enable
      __IO ONE_BIT    SRAMEN  :  1; //!<[02] SRAM interface clock enable
           ONE_BIT    UNUSED0 :  1; //!<[03] 
      __IO ONE_BIT    FLITFEN :  1; //!<[04] FLITF clock enable
           ONE_BIT    UNUSED1 :  1; //!<[05] 
      __IO ONE_BIT    CRCEN   :  1; //!<[06] CRC clock enable
           uint32_t   UNUSED2 : 10; //!<[07] 
      __IO ONE_BIT    IOPAEN  :  1; //!<[17] I/O port A clock enable
      __IO ONE_BIT    IOPBEN  :  1; //!<[18] I/O port B clock enable
      __IO ONE_BIT    IOPCEN  :  1; //!<[19] I/O port C clock enable
      __IO ONE_BIT    IOPDEN  :  1; //!<[20] I/O port D clock enable
           ONE_BIT    UNUSED3 :  1; //!<[21] 
      __IO ONE_BIT    IOPFEN  :  1; //!<[22] I/O port F clock enable
           ONE_BIT    UNUSED4 :  1; //!<[23] 
      __IO ONE_BIT    TSCEN   :  1; //!<[24] Touch sensing controller clock enable
    } B;
    __IO uint32_t  R;
    explicit AHBENR_DEF () noexcept { R = 0x00000014u; }
    template<typename F> void setbit (F f) volatile {
      AHBENR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      AHBENR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union APB2ENR_DEF  {  //!< APB2 peripheral clock enable register (RCC_APB2ENR)
    struct {
      __IO ONE_BIT    SYSCFGEN :  1; //!<[00] SYSCFG clock enable
           uint32_t   UNUSED0  :  4; //!<[01] 
      __IO ONE_BIT    USART6EN :  1; //!<[05] USART6 clock enable
      __IO ONE_BIT    USART7EN :  1; //!<[06] USART7 clock enable
      __IO ONE_BIT    USART8EN :  1; //!<[07] USART8 clock enable
           ONE_BIT    UNUSED1  :  1; //!<[08] 
      __IO ONE_BIT    ADCEN    :  1; //!<[09] ADC 1 interface clock enable
           ONE_BIT    UNUSED2  :  1; //!<[10] 
      __IO ONE_BIT    TIM1EN   :  1; //!<[11] TIM1 Timer clock enable
      __IO ONE_BIT    SPI1EN   :  1; //!<[12] SPI 1 clock enable
           ONE_BIT    UNUSED3  :  1; //!<[13] 
      __IO ONE_BIT    USART1EN :  1; //!<[14] USART1 clock enable
           ONE_BIT    UNUSED4  :  1; //!<[15] 
      __IO ONE_BIT    TIM15EN  :  1; //!<[16] TIM15 timer clock enable
      __IO ONE_BIT    TIM16EN  :  1; //!<[17] TIM16 timer clock enable
      __IO ONE_BIT    TIM17EN  :  1; //!<[18] TIM17 timer clock enable
           uint32_t   UNUSED5  :  3; //!<[19] 
      __IO ONE_BIT    DBGMCUEN :  1; //!<[22] MCU debug module clock enable
    } B;
    __IO uint32_t  R;
    explicit APB2ENR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      APB2ENR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      APB2ENR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union APB1ENR_DEF  {  //!< APB1 peripheral clock enable register (RCC_APB1ENR)
    struct {
      __IO ONE_BIT    TIM2EN   :  1; //!<[00] Timer 2 clock enable
      __IO ONE_BIT    TIM3EN   :  1; //!<[01] Timer 3 clock enable
           uint32_t   UNUSED0  :  2; //!<[02] 
      __IO ONE_BIT    TIM6EN   :  1; //!<[04] Timer 6 clock enable
      __IO ONE_BIT    TIM7EN   :  1; //!<[05] TIM7 timer clock enable
           uint32_t   UNUSED1  :  2; //!<[06] 
      __IO ONE_BIT    TIM14EN  :  1; //!<[08] Timer 14 clock enable
           uint32_t   UNUSED2  :  2; //!<[09] 
      __IO ONE_BIT    WWDGEN   :  1; //!<[11] Window watchdog clock enable
           uint32_t   UNUSED3  :  2; //!<[12] 
      __IO ONE_BIT    SPI2EN   :  1; //!<[14] SPI 2 clock enable
           uint32_t   UNUSED4  :  2; //!<[15] 
      __IO ONE_BIT    USART2EN :  1; //!<[17] USART 2 clock enable
      __IO ONE_BIT    USART3EN :  1; //!<[18] USART3 clock enable
      __IO ONE_BIT    USART4EN :  1; //!<[19] USART4 clock enable
      __IO ONE_BIT    USART5EN :  1; //!<[20] USART5 clock enable
      __IO ONE_BIT    I2C1EN   :  1; //!<[21] I2C 1 clock enable
      __IO ONE_BIT    I2C2EN   :  1; //!<[22] I2C 2 clock enable
      __IO ONE_BIT    USBRST   :  1; //!<[23] USB interface clock enable
           ONE_BIT    UNUSED5  :  1; //!<[24] 
      __IO ONE_BIT    CANEN    :  1; //!<[25] CAN interface clock enable
           ONE_BIT    UNUSED6  :  1; //!<[26] 
      __IO ONE_BIT    CRSEN    :  1; //!<[27] Clock Recovery System interface clock enable
      __IO ONE_BIT    PWREN    :  1; //!<[28] Power interface clock enable
      __IO ONE_BIT    DACEN    :  1; //!<[29] DAC interface clock enable
      __IO ONE_BIT    CECEN    :  1; //!<[30] HDMI CEC interface clock enable
    } B;
    __IO uint32_t  R;
    explicit APB1ENR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      APB1ENR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      APB1ENR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union BDCR_DEF     {  //!< Backup domain control register (RCC_BDCR)
    struct {
      __IO ONE_BIT    LSEON   :  1; //!<[00] External Low Speed oscillator enable
      __I  ONE_BIT    LSERDY  :  1; //!<[01] External Low Speed oscillator ready
      __IO ONE_BIT    LSEBYP  :  1; //!<[02] External Low Speed oscillator bypass
      __IO uint32_t   LSEDRV  :  2; //!<[03] LSE oscillator drive capability
           uint32_t   UNUSED0 :  3; //!<[05] 
      __IO uint32_t   RTCSEL  :  2; //!<[08] RTC clock source selection
           uint32_t   UNUSED1 :  5; //!<[10] 
      __IO ONE_BIT    RTCEN   :  1; //!<[15] RTC clock enable
      __IO ONE_BIT    BDRST   :  1; //!<[16] Backup domain software reset
    } B;
    __IO uint32_t  R;
    explicit BDCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      BDCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      BDCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CSR_DEF      {  //!< Control/status register (RCC_CSR)
    struct {
      __IO ONE_BIT    LSION    :  1; //!<[00] Internal low speed oscillator enable
      __I  ONE_BIT    LSIRDY   :  1; //!<[01] Internal low speed oscillator ready
           uint32_t   UNUSED0  : 22; //!<[02] 
      __IO ONE_BIT    RMVF     :  1; //!<[24] Remove reset flag
      __IO ONE_BIT    OBLRSTF  :  1; //!<[25] Option byte loader reset flag
      __IO ONE_BIT    PINRSTF  :  1; //!<[26] PIN reset flag
      __IO ONE_BIT    PORRSTF  :  1; //!<[27] POR/PDR reset flag
      __IO ONE_BIT    SFTRSTF  :  1; //!<[28] Software reset flag
      __IO ONE_BIT    IWDGRSTF :  1; //!<[29] Independent watchdog reset flag
      __IO ONE_BIT    WWDGRSTF :  1; //!<[30] Window watchdog reset flag
      __IO ONE_BIT    LPWRRSTF :  1; //!<[31] Low-power reset flag
    } B;
    __IO uint32_t  R;
    explicit CSR_DEF () noexcept { R = 0x0c000000u; }
    template<typename F> void setbit (F f) volatile {
      CSR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CSR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union AHBRSTR_DEF  {  //!< AHB peripheral reset register
    struct {
           uint32_t   UNUSED0 : 17; //!<[00] 
      __IO ONE_BIT    IOPARST :  1; //!<[17] I/O port A reset
      __IO ONE_BIT    IOPBRST :  1; //!<[18] I/O port B reset
      __IO ONE_BIT    IOPCRST :  1; //!<[19] I/O port C reset
      __IO ONE_BIT    IOPDRST :  1; //!<[20] I/O port D reset
           ONE_BIT    UNUSED1 :  1; //!<[21] 
      __IO ONE_BIT    IOPFRST :  1; //!<[22] I/O port F reset
           ONE_BIT    UNUSED2 :  1; //!<[23] 
      __IO ONE_BIT    TSCRST  :  1; //!<[24] Touch sensing controller reset
    } B;
    __IO uint32_t  R;
    explicit AHBRSTR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      AHBRSTR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      AHBRSTR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CFGR2_DEF    {  //!< Clock configuration register 2
    struct {
      __IO uint32_t   PREDIV :  4; //!<[00] PREDIV division factor
    } B;
    __IO uint32_t  R;
    explicit CFGR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CFGR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CFGR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CFGR3_DEF    {  //!< Clock configuration register 3
    struct {
      __IO uint32_t   USART1SW :  2; //!<[00] USART1 clock source selection
           uint32_t   UNUSED0  :  2; //!<[02] 
      __IO ONE_BIT    I2C1SW   :  1; //!<[04] I2C1 clock source selection
           ONE_BIT    UNUSED1  :  1; //!<[05] 
      __IO ONE_BIT    CECSW    :  1; //!<[06] HDMI CEC clock source selection
      __IO ONE_BIT    USBSW    :  1; //!<[07] USB clock source selection
      __IO ONE_BIT    ADCSW    :  1; //!<[08] ADC clock source selection
           uint32_t   UNUSED2  :  7; //!<[09] 
      __IO uint32_t   USART2SW :  2; //!<[16] USART2 clock source selection
    } B;
    __IO uint32_t  R;
    explicit CFGR3_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CFGR3_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CFGR3_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CR2_DEF      {  //!< Clock control register 2
    struct {
      __IO ONE_BIT    HSI14ON   :  1; //!<[00] HSI14 clock enable
      __I  ONE_BIT    HSI14RDY  :  1; //!<[01] HR14 clock ready flag
      __IO ONE_BIT    HSI14DIS  :  1; //!<[02] HSI14 clock request from ADC disable
      __IO uint32_t   HSI14TRIM :  5; //!<[03] HSI14 clock trimming
      __I  uint32_t   HSI14CAL  :  8; //!<[08] HSI14 clock calibration
      __IO ONE_BIT    HSI48ON   :  1; //!<[16] HSI48 clock enable
      __I  ONE_BIT    HSI48RDY  :  1; //!<[17] HSI48 clock ready flag
           uint32_t   UNUSED0   :  6; //!<[18] 
      __I  ONE_BIT    HSI48CAL  :  1; //!<[24] HSI48 factory clock calibration
    } B;
    __IO uint32_t  R;
    explicit CR2_DEF () noexcept { R = 0x00000080u; }
    template<typename F> void setbit (F f) volatile {
      CR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL RCC REGISTERS INSTANCES
  __IO CR_DEF                    CR ;  //!< [0000](04)[0x00000083]
  __IO CFGR_DEF                CFGR ;  //!< [0004](04)[0x00000000]
  __IO CIR_DEF                  CIR ;  //!< [0008](04)[0x00000000]
  __IO APB2RSTR_DEF        APB2RSTR ;  //!< [000c](04)[0x00000000]
  __IO APB1RSTR_DEF        APB1RSTR ;  //!< [0010](04)[0x00000000]
  __IO AHBENR_DEF            AHBENR ;  //!< [0014](04)[0x00000014]
  __IO APB2ENR_DEF          APB2ENR ;  //!< [0018](04)[0x00000000]
  __IO APB1ENR_DEF          APB1ENR ;  //!< [001c](04)[0x00000000]
  __IO BDCR_DEF                BDCR ;  //!< [0020](04)[0x00000000]
  __IO CSR_DEF                  CSR ;  //!< [0024](04)[0x0C000000]
  __IO AHBRSTR_DEF          AHBRSTR ;  //!< [0028](04)[0x00000000]
  __IO CFGR2_DEF              CFGR2 ;  //!< [002c](04)[0x00000000]
  __IO CFGR3_DEF              CFGR3 ;  //!< [0030](04)[0x00000000]
  __IO CR2_DEF                  CR2 ;  //!< [0034](04)[0x00000080]
}; /* total size = 0x0400, struct size = 0x0038 */

// ////////////////////+++ SYSCFG_COMP +-+//////////////////// //
struct SYSCFG_COMP_Type { /*!< System configuration controller */
  union SYSCFG_CFGR1_DEF   {  //!< configuration register 1
    struct {
      __IO uint32_t   MEM_MODE          :  2; //!<[00] Memory mapping selection bits
           uint32_t   UNUSED0           :  6; //!<[02] 
      __IO ONE_BIT    ADC_DMA_RMP       :  1; //!<[08] ADC DMA remapping bit
      __IO ONE_BIT    USART1_TX_DMA_RMP :  1; //!<[09] USART1_TX DMA remapping bit
      __IO ONE_BIT    USART1_RX_DMA_RMP :  1; //!<[10] USART1_RX DMA request remapping bit
      __IO ONE_BIT    TIM16_DMA_RMP     :  1; //!<[11] TIM16 DMA request remapping bit
      __IO ONE_BIT    TIM17_DMA_RMP     :  1; //!<[12] TIM17 DMA request remapping bit
           uint32_t   UNUSED1           :  3; //!<[13] 
      __IO ONE_BIT    I2C_PB6_FM        :  1; //!<[16] Fast Mode Plus (FM plus) driving capability activation bits.
      __IO ONE_BIT    I2C_PB7_FM        :  1; //!<[17] Fast Mode Plus (FM+) driving capability activation bits.
      __IO ONE_BIT    I2C_PB8_FM        :  1; //!<[18] Fast Mode Plus (FM+) driving capability activation bits.
      __IO ONE_BIT    I2C_PB9_FM        :  1; //!<[19] Fast Mode Plus (FM+) driving capability activation bits.
      __IO ONE_BIT    I2C1_FM_plus      :  1; //!<[20] FM+ driving capability activation for I2C1
      __IO ONE_BIT    I2C2_FM_plus      :  1; //!<[21] FM+ driving capability activation for I2C2
           uint32_t   UNUSED2           :  2; //!<[22] 
      __IO ONE_BIT    SPI2_DMA_RMP      :  1; //!<[24] SPI2 DMA request remapping bit
      __IO ONE_BIT    USART2_DMA_RMP    :  1; //!<[25] USART2 DMA request remapping bit
      __IO ONE_BIT    USART3_DMA_RMP    :  1; //!<[26] USART3 DMA request remapping bit
      __IO ONE_BIT    I2C1_DMA_RMP      :  1; //!<[27] I2C1 DMA request remapping bit
      __IO ONE_BIT    TIM1_DMA_RMP      :  1; //!<[28] TIM1 DMA request remapping bit
      __IO ONE_BIT    TIM2_DMA_RMP      :  1; //!<[29] TIM2 DMA request remapping bit
      __IO ONE_BIT    TIM3_DMA_RMP      :  1; //!<[30] TIM3 DMA request remapping bit
    } B;
    __IO uint32_t  R;
    explicit SYSCFG_CFGR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SYSCFG_CFGR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SYSCFG_CFGR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SYSCFG_EXTICR1_DEF {  //!< external interrupt configuration register 1
    struct {
      __IO uint32_t   EXTI0 :  4; //!<[00] EXTI 0 configuration bits
      __IO uint32_t   EXTI1 :  4; //!<[04] EXTI 1 configuration bits
      __IO uint32_t   EXTI2 :  4; //!<[08] EXTI 2 configuration bits
      __IO uint32_t   EXTI3 :  4; //!<[12] EXTI 3 configuration bits
    } B;
    __IO uint32_t  R;
    explicit SYSCFG_EXTICR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SYSCFG_EXTICR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SYSCFG_EXTICR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SYSCFG_EXTICR2_DEF {  //!< external interrupt configuration register 2
    struct {
      __IO uint32_t   EXTI4 :  4; //!<[00] EXTI 4 configuration bits
      __IO uint32_t   EXTI5 :  4; //!<[04] EXTI 5 configuration bits
      __IO uint32_t   EXTI6 :  4; //!<[08] EXTI 6 configuration bits
      __IO uint32_t   EXTI7 :  4; //!<[12] EXTI 7 configuration bits
    } B;
    __IO uint32_t  R;
    explicit SYSCFG_EXTICR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SYSCFG_EXTICR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SYSCFG_EXTICR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SYSCFG_EXTICR3_DEF {  //!< external interrupt configuration register 3
    struct {
      __IO uint32_t   EXTI8  :  4; //!<[00] EXTI 8 configuration bits
      __IO uint32_t   EXTI9  :  4; //!<[04] EXTI 9 configuration bits
      __IO uint32_t   EXTI10 :  4; //!<[08] EXTI 10 configuration bits
      __IO uint32_t   EXTI11 :  4; //!<[12] EXTI 11 configuration bits
    } B;
    __IO uint32_t  R;
    explicit SYSCFG_EXTICR3_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SYSCFG_EXTICR3_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SYSCFG_EXTICR3_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SYSCFG_EXTICR4_DEF {  //!< external interrupt configuration register 4
    struct {
      __IO uint32_t   EXTI12 :  4; //!<[00] EXTI 12 configuration bits
      __IO uint32_t   EXTI13 :  4; //!<[04] EXTI 13 configuration bits
      __IO uint32_t   EXTI14 :  4; //!<[08] EXTI 14 configuration bits
      __IO uint32_t   EXTI15 :  4; //!<[12] EXTI 15 configuration bits
    } B;
    __IO uint32_t  R;
    explicit SYSCFG_EXTICR4_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SYSCFG_EXTICR4_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SYSCFG_EXTICR4_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SYSCFG_CFGR2_DEF   {  //!< configuration register 2
    struct {
      __IO ONE_BIT    LOCUP_LOCK       :  1; //!<[00] Cortex-M0 LOCKUP bit enable bit
      __IO ONE_BIT    SRAM_PARITY_LOCK :  1; //!<[01] SRAM parity lock bit
      __IO ONE_BIT    PVD_LOCK         :  1; //!<[02] PVD lock enable bit
           uint32_t   UNUSED0          :  5; //!<[03] 
      __IO ONE_BIT    SRAM_PEF         :  1; //!<[08] SRAM parity flag
    } B;
    __IO uint32_t  R;
    explicit SYSCFG_CFGR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SYSCFG_CFGR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SYSCFG_CFGR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union COMP_CSR_DEF       {  //!< control and status register
    struct {
      __IO ONE_BIT    COMP1EN       :  1; //!<[00] Comparator 1 enable
      __IO ONE_BIT    COMP1_INP_DAC :  1; //!<[01] COMP1_INP_DAC
      __IO uint32_t   COMP1MODE     :  2; //!<[02] Comparator 1 mode
      __IO uint32_t   COMP1INSEL    :  3; //!<[04] Comparator 1 inverting input selection
           ONE_BIT    UNUSED0       :  1; //!<[07] 
      __IO uint32_t   COMP1OUTSEL   :  3; //!<[08] Comparator 1 output selection
      __IO ONE_BIT    COMP1POL      :  1; //!<[11] Comparator 1 output polarity
      __IO uint32_t   COMP1HYST     :  2; //!<[12] Comparator 1 hysteresis
      __I  ONE_BIT    COMP1OUT      :  1; //!<[14] Comparator 1 output
      __IO ONE_BIT    COMP1LOCK     :  1; //!<[15] Comparator 1 lock
      __IO ONE_BIT    COMP2EN       :  1; //!<[16] Comparator 2 enable
           ONE_BIT    UNUSED1       :  1; //!<[17] 
      __IO uint32_t   COMP2MODE     :  2; //!<[18] Comparator 2 mode
      __IO uint32_t   COMP2INSEL    :  3; //!<[20] Comparator 2 inverting input selection
      __IO ONE_BIT    WNDWEN        :  1; //!<[23] Window mode enable
      __IO uint32_t   COMP2OUTSEL   :  3; //!<[24] Comparator 2 output selection
      __IO ONE_BIT    COMP2POL      :  1; //!<[27] Comparator 2 output polarity
      __IO uint32_t   COMP2HYST     :  2; //!<[28] Comparator 2 hysteresis
      __I  ONE_BIT    COMP2OUT      :  1; //!<[30] Comparator 2 output
      __IO ONE_BIT    COMP2LOCK     :  1; //!<[31] Comparator 2 lock
    } B;
    __IO uint32_t  R;
    explicit COMP_CSR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      COMP_CSR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      COMP_CSR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL SYSCFG_COMP REGISTERS INSTANCES
  __IO SYSCFG_CFGR1_DEF      SYSCFG_CFGR1 ;  //!< [0000](04)[0x00000000]
       uint32_t                 UNUSED0 ;  //!< [0004](04)[0xFFFFFFFF]
  __IO SYSCFG_EXTICR1_DEF  SYSCFG_EXTICR1 ;  //!< [0008](04)[0x00000000]
  __IO SYSCFG_EXTICR2_DEF  SYSCFG_EXTICR2 ;  //!< [000c](04)[0x00000000]
  __IO SYSCFG_EXTICR3_DEF  SYSCFG_EXTICR3 ;  //!< [0010](04)[0x00000000]
  __IO SYSCFG_EXTICR4_DEF  SYSCFG_EXTICR4 ;  //!< [0014](04)[0x00000000]
  __IO SYSCFG_CFGR2_DEF      SYSCFG_CFGR2 ;  //!< [0018](04)[0x00000000]
  __IO COMP_CSR_DEF              COMP_CSR ;  //!< [001c](04)[0x00000000]
}; /* total size = 0x0021, struct size = 0x0020 */

// ////////////////////+++ ADC +-+//////////////////// //
struct ADC_Type         { /*!< Analog-to-digital converter */
  union ISR_DEF     {  //!< interrupt and status register
    struct {
      __IO ONE_BIT    ADRDY   :  1; //!<[00] ADC ready
      __IO ONE_BIT    EOSMP   :  1; //!<[01] End of sampling flag
      __IO ONE_BIT    EOC     :  1; //!<[02] End of conversion flag
      __IO ONE_BIT    EOS     :  1; //!<[03] End of sequence flag
      __IO ONE_BIT    OVR     :  1; //!<[04] ADC overrun
           uint32_t   UNUSED0 :  2; //!<[05] 
      __IO ONE_BIT    AWD     :  1; //!<[07] Analog watchdog flag
    } B;
    __IO uint32_t  R;
    explicit ISR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ISR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ISR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IER_DEF     {  //!< interrupt enable register
    struct {
      __IO ONE_BIT    ADRDYIE :  1; //!<[00] ADC ready interrupt enable
      __IO ONE_BIT    EOSMPIE :  1; //!<[01] End of sampling flag interrupt enable
      __IO ONE_BIT    EOCIE   :  1; //!<[02] End of conversion interrupt enable
      __IO ONE_BIT    EOSIE   :  1; //!<[03] End of conversion sequence interrupt enable
      __IO ONE_BIT    OVRIE   :  1; //!<[04] Overrun interrupt enable
           uint32_t   UNUSED0 :  2; //!<[05] 
      __IO ONE_BIT    AWDIE   :  1; //!<[07] Analog watchdog interrupt enable
    } B;
    __IO uint32_t  R;
    explicit IER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CR_DEF      {  //!< control register
    struct {
      __IO ONE_BIT    ADEN    :  1; //!<[00] ADC enable command
      __IO ONE_BIT    ADDIS   :  1; //!<[01] ADC disable command
      __IO ONE_BIT    ADSTART :  1; //!<[02] ADC start conversion command
           ONE_BIT    UNUSED0 :  1; //!<[03] 
      __IO ONE_BIT    ADSTP   :  1; //!<[04] ADC stop conversion command
           uint32_t   UNUSED1 : 26; //!<[05] 
      __IO ONE_BIT    ADCAL   :  1; //!<[31] ADC calibration
    } B;
    __IO uint32_t  R;
    explicit CR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CFGR1_DEF   {  //!< configuration register 1
    struct {
      __IO ONE_BIT    DMAEN   :  1; //!<[00] Direct memory access enable
      __IO ONE_BIT    DMACFG  :  1; //!<[01] Direct memery access configuration
      __IO ONE_BIT    SCANDIR :  1; //!<[02] Scan sequence direction
      __IO uint32_t   RES     :  2; //!<[03] Data resolution
      __IO ONE_BIT    ALIGN   :  1; //!<[05] Data alignment
      __IO uint32_t   EXTSEL  :  3; //!<[06] External trigger selection
           ONE_BIT    UNUSED0 :  1; //!<[09] 
      __IO uint32_t   EXTEN   :  2; //!<[10] External trigger enable and polarity selection
      __IO ONE_BIT    OVRMOD  :  1; //!<[12] Overrun management mode
      __IO ONE_BIT    CONT    :  1; //!<[13] Single / continuous conversion mode
      __IO ONE_BIT    AUTDLY  :  1; //!<[14] Auto-delayed conversion mode
      __IO ONE_BIT    AUTOFF  :  1; //!<[15] Auto-off mode
      __IO ONE_BIT    DISCEN  :  1; //!<[16] Discontinuous mode
           uint32_t   UNUSED1 :  5; //!<[17] 
      __IO ONE_BIT    AWDSGL  :  1; //!<[22] Enable the watchdog on a single channel or on all channels
      __IO ONE_BIT    AWDEN   :  1; //!<[23] Analog watchdog enable
           uint32_t   UNUSED2 :  2; //!<[24] 
      __IO uint32_t   AWDCH   :  5; //!<[26] Analog watchdog channel selection
    } B;
    __IO uint32_t  R;
    explicit CFGR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CFGR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CFGR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CFGR2_DEF   {  //!< configuration register 2
    struct {
           uint32_t   UNUSED0   : 30; //!<[00] 
      __IO ONE_BIT    JITOFF_D2 :  1; //!<[30] JITOFF_D2
      __IO ONE_BIT    JITOFF_D4 :  1; //!<[31] JITOFF_D4
    } B;
    __IO uint32_t  R;
    explicit CFGR2_DEF () noexcept { R = 0x00008000u; }
    template<typename F> void setbit (F f) volatile {
      CFGR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CFGR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SMPR_DEF    {  //!< sampling time register
    struct {
      __IO uint32_t   SMPR :  3; //!<[00] Sampling time selection
    } B;
    __IO uint32_t  R;
    explicit SMPR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SMPR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SMPR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union TR_DEF      {  //!< watchdog threshold register
    struct {
      __IO uint32_t   LT      : 12; //!<[00] Analog watchdog lower threshold
           uint32_t   UNUSED0 :  4; //!<[12] 
      __IO uint32_t   HT      : 12; //!<[16] Analog watchdog higher threshold
    } B;
    __IO uint32_t  R;
    explicit TR_DEF () noexcept { R = 0x00000fffu; }
    template<typename F> void setbit (F f) volatile {
      TR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      TR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CHSELR_DEF  {  //!< channel selection register
    struct {
      __IO ONE_BIT  CHSEL0  :  1; //!<[00] Channel-x selection
      __IO ONE_BIT  CHSEL1  :  1; //!<[01] Channel-x selection
      __IO ONE_BIT  CHSEL2  :  1; //!<[02] Channel-x selection
      __IO ONE_BIT  CHSEL3  :  1; //!<[03] Channel-x selection
      __IO ONE_BIT  CHSEL4  :  1; //!<[04] Channel-x selection
      __IO ONE_BIT  CHSEL5  :  1; //!<[05] Channel-x selection
      __IO ONE_BIT  CHSEL6  :  1; //!<[06] Channel-x selection
      __IO ONE_BIT  CHSEL7  :  1; //!<[07] Channel-x selection
      __IO ONE_BIT  CHSEL8  :  1; //!<[08] Channel-x selection
      __IO ONE_BIT  CHSEL9  :  1; //!<[09] Channel-x selection
      __IO ONE_BIT  CHSEL10 :  1; //!<[10] Channel-x selection
      __IO ONE_BIT  CHSEL11 :  1; //!<[11] Channel-x selection
      __IO ONE_BIT  CHSEL12 :  1; //!<[12] Channel-x selection
      __IO ONE_BIT  CHSEL13 :  1; //!<[13] Channel-x selection
      __IO ONE_BIT  CHSEL14 :  1; //!<[14] Channel-x selection
      __IO ONE_BIT  CHSEL15 :  1; //!<[15] Channel-x selection
      __IO ONE_BIT  CHSEL16 :  1; //!<[16] Channel-x selection
      __IO ONE_BIT  CHSEL17 :  1; //!<[17] Channel-x selection
      __IO ONE_BIT  CHSEL18 :  1; //!<[18] Channel-x selection
    } B;
    __IO uint32_t  R;
    explicit CHSELR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CHSELR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CHSELR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DR_DEF      {  //!< data register
    struct {
      __I  uint32_t   DATA : 16; //!<[00] Converted data
    } B;
    __I  uint32_t  R;

    explicit DR_DEF (volatile DR_DEF & o) noexcept { R = o.R; };
  };
  union CCR_DEF     {  //!< common configuration register
    struct {
           uint32_t   UNUSED0 : 22; //!<[00] 
      __IO ONE_BIT    VREFEN  :  1; //!<[22] Temperature sensor and VREFINT enable
      __IO ONE_BIT    TSEN    :  1; //!<[23] Temperature sensor enable
      __IO ONE_BIT    VBATEN  :  1; //!<[24] VBAT enable
    } B;
    __IO uint32_t  R;
    explicit CCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL ADC REGISTERS INSTANCES
  __IO ISR_DEF                 ISR ;  //!< [0000](04)[0x00000000]
  __IO IER_DEF                 IER ;  //!< [0004](04)[0x00000000]
  __IO CR_DEF                   CR ;  //!< [0008](04)[0x00000000]
  __IO CFGR1_DEF             CFGR1 ;  //!< [000c](04)[0x00000000]
  __IO CFGR2_DEF             CFGR2 ;  //!< [0010](04)[0x00008000]
  __IO SMPR_DEF               SMPR ;  //!< [0014](04)[0x00000000]
       uint32_t          UNUSED0 [2];  //!< [0018](08)[0xFFFFFFFF]
  __IO TR_DEF                   TR ;  //!< [0020](04)[0x00000FFF]
       uint32_t          UNUSED1 ;  //!< [0024](04)[0xFFFFFFFF]
  __IO CHSELR_DEF           CHSELR ;  //!< [0028](04)[0x00000000]
       uint32_t          UNUSED2 [5];  //!< [002c](14)[0xFFFFFFFF]
  __I  DR_DEF                   DR ;  //!< [0040](04)[0x00000000]
       uint32_t          UNUSED3 [177];  //!< [0044](2c4)[0xFFFFFFFF]
  __IO CCR_DEF                 CCR ;  //!< [0308](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x030C */

// ////////////////////+++ USART1 +-+//////////////////// //
struct USART1_Type      { /*!< Universal synchronous asynchronous receiver transmitter */
  union CR1_DEF  {  //!< Control register 1
    struct {
      __IO ONE_BIT    UE     :  1; //!<[00] USART enable
      __IO ONE_BIT    UESM   :  1; //!<[01] USART enable in Stop mode
      __IO ONE_BIT    RE     :  1; //!<[02] Receiver enable
      __IO ONE_BIT    TE     :  1; //!<[03] Transmitter enable
      __IO ONE_BIT    IDLEIE :  1; //!<[04] IDLE interrupt enable
      __IO ONE_BIT    RXNEIE :  1; //!<[05] RXNE interrupt enable
      __IO ONE_BIT    TCIE   :  1; //!<[06] Transmission complete interrupt enable
      __IO ONE_BIT    TXEIE  :  1; //!<[07] interrupt enable
      __IO ONE_BIT    PEIE   :  1; //!<[08] PE interrupt enable
      __IO ONE_BIT    PS     :  1; //!<[09] Parity selection
      __IO ONE_BIT    PCE    :  1; //!<[10] Parity control enable
      __IO ONE_BIT    WAKE   :  1; //!<[11] Receiver wakeup method
      __IO ONE_BIT    M      :  1; //!<[12] Word length
      __IO ONE_BIT    MME    :  1; //!<[13] Mute mode enable
      __IO ONE_BIT    CMIE   :  1; //!<[14] Character match interrupt enable
      __IO ONE_BIT    OVER8  :  1; //!<[15] Oversampling mode
      __IO uint32_t   DEDT   :  5; //!<[16] Driver Enable deassertion time
      __IO uint32_t   DEAT   :  5; //!<[21] Driver Enable assertion time
      __IO ONE_BIT    RTOIE  :  1; //!<[26] Receiver timeout interrupt enable
      __IO ONE_BIT    EOBIE  :  1; //!<[27] End of Block interrupt enable
      __IO ONE_BIT    M1     :  1; //!<[28] Word length
    } B;
    __IO uint32_t  R;
    explicit CR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CR2_DEF  {  //!< Control register 2
    struct {
           uint32_t   UNUSED0  :  4; //!<[00] 
      __IO ONE_BIT    ADDM7    :  1; //!<[04] 7-bit Address Detection/4-bit Address Detection
      __IO ONE_BIT    LBDL     :  1; //!<[05] LIN break detection length
      __IO ONE_BIT    LBDIE    :  1; //!<[06] LIN break detection interrupt enable
           ONE_BIT    UNUSED1  :  1; //!<[07] 
      __IO ONE_BIT    LBCL     :  1; //!<[08] Last bit clock pulse
      __IO ONE_BIT    CPHA     :  1; //!<[09] Clock phase
      __IO ONE_BIT    CPOL     :  1; //!<[10] Clock polarity
      __IO ONE_BIT    CLKEN    :  1; //!<[11] Clock enable
      __IO uint32_t   STOP     :  2; //!<[12] STOP bits
      __IO ONE_BIT    LINEN    :  1; //!<[14] LIN mode enable
      __IO ONE_BIT    SWAP     :  1; //!<[15] Swap TX/RX pins
      __IO ONE_BIT    RXINV    :  1; //!<[16] RX pin active level inversion
      __IO ONE_BIT    TXINV    :  1; //!<[17] TX pin active level inversion
      __IO ONE_BIT    DATAINV  :  1; //!<[18] Binary data inversion
      __IO ONE_BIT    MSBFIRST :  1; //!<[19] Most significant bit first
      __IO ONE_BIT    ABREN    :  1; //!<[20] Auto baud rate enable
      __IO uint32_t   ABRMOD   :  2; //!<[21] Auto baud rate mode
      __IO ONE_BIT    RTOEN    :  1; //!<[23] Receiver timeout enable
      __IO uint32_t   ADD0     :  4; //!<[24] Address of the USART node
      __IO uint32_t   ADD4     :  4; //!<[28] Address of the USART node
    } B;
    __IO uint32_t  R;
    explicit CR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CR3_DEF  {  //!< Control register 3
    struct {
      __IO ONE_BIT    EIE     :  1; //!<[00] Error interrupt enable
      __IO ONE_BIT    IREN    :  1; //!<[01] IrDA mode enable
      __IO ONE_BIT    IRLP    :  1; //!<[02] IrDA low-power
      __IO ONE_BIT    HDSEL   :  1; //!<[03] Half-duplex selection
      __IO ONE_BIT    NACK    :  1; //!<[04] Smartcard NACK enable
      __IO ONE_BIT    SCEN    :  1; //!<[05] Smartcard mode enable
      __IO ONE_BIT    DMAR    :  1; //!<[06] DMA enable receiver
      __IO ONE_BIT    DMAT    :  1; //!<[07] DMA enable transmitter
      __IO ONE_BIT    RTSE    :  1; //!<[08] RTS enable
      __IO ONE_BIT    CTSE    :  1; //!<[09] CTS enable
      __IO ONE_BIT    CTSIE   :  1; //!<[10] CTS interrupt enable
      __IO ONE_BIT    ONEBIT  :  1; //!<[11] One sample bit method enable
      __IO ONE_BIT    OVRDIS  :  1; //!<[12] Overrun Disable
      __IO ONE_BIT    DDRE    :  1; //!<[13] DMA Disable on Reception Error
      __IO ONE_BIT    DEM     :  1; //!<[14] Driver enable mode
      __IO ONE_BIT    DEP     :  1; //!<[15] Driver enable polarity selection
           ONE_BIT    UNUSED0 :  1; //!<[16] 
      __IO uint32_t   SCARCNT :  3; //!<[17] Smartcard auto-retry count
      __IO uint32_t   WUS     :  2; //!<[20] Wakeup from Stop mode interrupt flag selection
      __IO ONE_BIT    WUFIE   :  1; //!<[22] Wakeup from Stop mode interrupt enable
    } B;
    __IO uint32_t  R;
    explicit CR3_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR3_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR3_DEF r; r.R = R;
      R = f (r);
    }
  };
  union BRR_DEF  {  //!< Baud rate register
    struct {
      __IO uint32_t   DIV_Fraction :  4; //!<[00] fraction of USARTDIV
      __IO uint32_t   DIV_Mantissa : 12; //!<[04] mantissa of USARTDIV
    } B;
    __IO uint32_t  R;
    explicit BRR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      BRR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      BRR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union GTPR_DEF {  //!< Guard time and prescaler register
    struct {
      __IO uint32_t   PSC :  8; //!<[00] Prescaler value
      __IO uint32_t   GT  :  8; //!<[08] Guard time value
    } B;
    __IO uint32_t  R;
    explicit GTPR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      GTPR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      GTPR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union RTOR_DEF {  //!< Receiver timeout register
    struct {
      __IO uint32_t   RTO  : 24; //!<[00] Receiver timeout value
      __IO uint32_t   BLEN :  8; //!<[24] Block Length
    } B;
    __IO uint32_t  R;
    explicit RTOR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      RTOR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      RTOR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union RQR_DEF  {  //!< Request register
    struct {
      __IO ONE_BIT  ABRRQ :  1; //!<[00] Auto baud rate request
      __IO ONE_BIT  SBKRQ :  1; //!<[01] Send break request
      __IO ONE_BIT  MMRQ  :  1; //!<[02] Mute mode request
      __IO ONE_BIT  RXFRQ :  1; //!<[03] Receive data flush request
      __IO ONE_BIT  TXFRQ :  1; //!<[04] Transmit data flush request
    } B;
    __IO uint32_t  R;
    explicit RQR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      RQR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      RQR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ISR_DEF  {  //!< Interrupt & status register
    struct {
      __I  ONE_BIT  PE      :  1; //!<[00] Parity error
      __I  ONE_BIT  FE      :  1; //!<[01] Framing error
      __I  ONE_BIT  NF      :  1; //!<[02] Noise detected flag
      __I  ONE_BIT  ORE     :  1; //!<[03] Overrun error
      __I  ONE_BIT  IDLE    :  1; //!<[04] Idle line detected
      __I  ONE_BIT  RXNE    :  1; //!<[05] Read data register not empty
      __I  ONE_BIT  TC      :  1; //!<[06] Transmission complete
      __I  ONE_BIT  TXE     :  1; //!<[07] Transmit data register empty
      __I  ONE_BIT  LBDF    :  1; //!<[08] LIN break detection flag
      __I  ONE_BIT  CTSIF   :  1; //!<[09] CTS interrupt flag
      __I  ONE_BIT  CTS     :  1; //!<[10] CTS flag
      __I  ONE_BIT  RTOF    :  1; //!<[11] Receiver timeout
      __I  ONE_BIT  EOBF    :  1; //!<[12] End of block flag
           ONE_BIT  UNUSED0 :  1; //!<[13] 
      __I  ONE_BIT  ABRE    :  1; //!<[14] Auto baud rate error
      __I  ONE_BIT  ABRF    :  1; //!<[15] Auto baud rate flag
      __I  ONE_BIT  BUSY    :  1; //!<[16] Busy flag
      __I  ONE_BIT  CMF     :  1; //!<[17] character match flag
      __I  ONE_BIT  SBKF    :  1; //!<[18] Send break flag
      __I  ONE_BIT  RWU     :  1; //!<[19] Receiver wakeup from Mute mode
      __I  ONE_BIT  WUF     :  1; //!<[20] Wakeup from Stop mode flag
      __I  ONE_BIT  TEACK   :  1; //!<[21] Transmit enable acknowledge flag
      __I  ONE_BIT  REACK   :  1; //!<[22] Receive enable acknowledge flag
    } B;
    __I  uint32_t  R;

    explicit ISR_DEF (volatile ISR_DEF & o) noexcept { R = o.R; };
  };
  union ICR_DEF  {  //!< Interrupt flag clear register
    struct {
      __IO ONE_BIT    PECF    :  1; //!<[00] Parity error clear flag
      __IO ONE_BIT    FECF    :  1; //!<[01] Framing error clear flag
      __IO ONE_BIT    NCF     :  1; //!<[02] Noise detected clear flag
      __IO ONE_BIT    ORECF   :  1; //!<[03] Overrun error clear flag
      __IO ONE_BIT    IDLECF  :  1; //!<[04] Idle line detected clear flag
           ONE_BIT    UNUSED0 :  1; //!<[05] 
      __IO ONE_BIT    TCCF    :  1; //!<[06] Transmission complete clear flag
           ONE_BIT    UNUSED1 :  1; //!<[07] 
      __IO ONE_BIT    LBDCF   :  1; //!<[08] LIN break detection clear flag
      __IO ONE_BIT    CTSCF   :  1; //!<[09] CTS clear flag
           ONE_BIT    UNUSED2 :  1; //!<[10] 
      __IO ONE_BIT    RTOCF   :  1; //!<[11] Receiver timeout clear flag
      __IO ONE_BIT    EOBCF   :  1; //!<[12] End of timeout clear flag
           uint32_t   UNUSED3 :  4; //!<[13] 
      __IO ONE_BIT    CMCF    :  1; //!<[17] Character match clear flag
           uint32_t   UNUSED4 :  2; //!<[18] 
      __IO ONE_BIT    WUCF    :  1; //!<[20] Wakeup from Stop mode clear flag
    } B;
    __IO uint32_t  R;
    explicit ICR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ICR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ICR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union RDR_DEF  {  //!< Receive data register
    struct {
      __I  uint32_t   RDR :  9; //!<[00] Receive data value
    } B;
    __I  uint32_t  R;

    explicit RDR_DEF (volatile RDR_DEF & o) noexcept { R = o.R; };
  };
  union TDR_DEF  {  //!< Transmit data register
    struct {
      __IO uint32_t   TDR :  9; //!<[00] Transmit data value
    } B;
    __IO uint32_t  R;
    explicit TDR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      TDR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      TDR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL USART1 REGISTERS INSTANCES
  __IO CR1_DEF              CR1 ;  //!< [0000](04)[0x00000000]
  __IO CR2_DEF              CR2 ;  //!< [0004](04)[0x00000000]
  __IO CR3_DEF              CR3 ;  //!< [0008](04)[0x00000000]
  __IO BRR_DEF              BRR ;  //!< [000c](04)[0x00000000]
  __IO GTPR_DEF            GTPR ;  //!< [0010](04)[0x00000000]
  __IO RTOR_DEF            RTOR ;  //!< [0014](04)[0x00000000]
  __IO RQR_DEF              RQR ;  //!< [0018](04)[0x00000000]
  __I  ISR_DEF              ISR ;  //!< [001c](04)[0x000000C0]
  __IO ICR_DEF              ICR ;  //!< [0020](04)[0x00000000]
  __I  RDR_DEF              RDR ;  //!< [0024](04)[0x00000000]
  __IO TDR_DEF              TDR ;  //!< [0028](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x002C */

// ////////////////////+++ RTC +-+//////////////////// //
struct RTC_Type         { /*!< Real-time clock */
  union TR_DEF       {  //!< time register
    struct {
      __IO uint32_t   SU      :  4; //!<[00] Second units in BCD format
      __IO uint32_t   ST      :  3; //!<[04] Second tens in BCD format
           ONE_BIT    UNUSED0 :  1; //!<[07] 
      __IO uint32_t   MNU     :  4; //!<[08] Minute units in BCD format
      __IO uint32_t   MNT     :  3; //!<[12] Minute tens in BCD format
           ONE_BIT    UNUSED1 :  1; //!<[15] 
      __IO uint32_t   HU      :  4; //!<[16] Hour units in BCD format
      __IO uint32_t   HT      :  2; //!<[20] Hour tens in BCD format
      __IO ONE_BIT    PM      :  1; //!<[22] AM/PM notation
    } B;
    __IO uint32_t  R;
    explicit TR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      TR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      TR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DR_DEF       {  //!< date register
    struct {
      __IO uint32_t   DU      :  4; //!<[00] Date units in BCD format
      __IO uint32_t   DT      :  2; //!<[04] Date tens in BCD format
           uint32_t   UNUSED0 :  2; //!<[06] 
      __IO uint32_t   MU      :  4; //!<[08] Month units in BCD format
      __IO ONE_BIT    MT      :  1; //!<[12] Month tens in BCD format
      __IO uint32_t   WDU     :  3; //!<[13] Week day units
      __IO uint32_t   YU      :  4; //!<[16] Year units in BCD format
      __IO uint32_t   YT      :  4; //!<[20] Year tens in BCD format
    } B;
    __IO uint32_t  R;
    explicit DR_DEF () noexcept { R = 0x00002101u; }
    template<typename F> void setbit (F f) volatile {
      DR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CR_DEF       {  //!< control register
    struct {
           uint32_t   UNUSED0 :  3; //!<[00] 
      __IO ONE_BIT    TSEDGE  :  1; //!<[03] Time-stamp event active edge
      __IO ONE_BIT    REFCKON :  1; //!<[04] RTC_REFIN reference clock detection enable (50 or 60 Hz)
      __IO ONE_BIT    BYPSHAD :  1; //!<[05] Bypass the shadow registers
      __IO ONE_BIT    FMT     :  1; //!<[06] Hour format
           ONE_BIT    UNUSED1 :  1; //!<[07] 
      __IO ONE_BIT    ALRAE   :  1; //!<[08] Alarm A enable
           uint32_t   UNUSED2 :  2; //!<[09] 
      __IO ONE_BIT    TSE     :  1; //!<[11] timestamp enable
      __IO ONE_BIT    ALRAIE  :  1; //!<[12] Alarm A interrupt enable
           uint32_t   UNUSED3 :  2; //!<[13] 
      __IO ONE_BIT    TSIE    :  1; //!<[15] Time-stamp interrupt enable
      __O  ONE_BIT    ADD1H   :  1; //!<[16] Add 1 hour (summer time change)
      __O  ONE_BIT    SUB1H   :  1; //!<[17] Subtract 1 hour (winter time change)
      __IO ONE_BIT    BKP     :  1; //!<[18] Backup
      __IO ONE_BIT    COSEL   :  1; //!<[19] Calibration output selection
      __IO ONE_BIT    POL     :  1; //!<[20] Output polarity
      __IO uint32_t   OSEL    :  2; //!<[21] Output selection
      __IO ONE_BIT    COE     :  1; //!<[23] Calibration output enable
    } B;
    __IO uint32_t  R;
    explicit CR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ISR_DEF      {  //!< initialization and status register
    struct {
      __I  ONE_BIT    ALRAWF  :  1; //!<[00] Alarm A write flag
           uint32_t   UNUSED0 :  2; //!<[01] 
      __IO ONE_BIT    SHPF    :  1; //!<[03] Shift operation pending
      __I  ONE_BIT    INITS   :  1; //!<[04] Initialization status flag
      __IO ONE_BIT    RSF     :  1; //!<[05] Registers synchronization flag
      __I  ONE_BIT    INITF   :  1; //!<[06] Initialization flag
      __IO ONE_BIT    INIT    :  1; //!<[07] Initialization mode
      __IO ONE_BIT    ALRAF   :  1; //!<[08] Alarm A flag
           uint32_t   UNUSED1 :  2; //!<[09] 
      __IO ONE_BIT    TSF     :  1; //!<[11] Time-stamp flag
      __IO ONE_BIT    TSOVF   :  1; //!<[12] Time-stamp overflow flag
      __IO ONE_BIT    TAMP1F  :  1; //!<[13] RTC_TAMP1 detection flag
      __IO ONE_BIT    TAMP2F  :  1; //!<[14] RTC_TAMP2 detection flag
           ONE_BIT    UNUSED2 :  1; //!<[15] 
      __I  ONE_BIT    RECALPF :  1; //!<[16] Recalibration pending Flag
    } B;
    __IO uint32_t  R;
    explicit ISR_DEF () noexcept { R = 0x00000007u; }
    template<typename F> void setbit (F f) volatile {
      ISR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ISR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union PRER_DEF     {  //!< prescaler register
    struct {
      __IO uint32_t   PREDIV_S : 15; //!<[00] Synchronous prescaler factor
           ONE_BIT    UNUSED0  :  1; //!<[15] 
      __IO uint32_t   PREDIV_A :  7; //!<[16] Asynchronous prescaler factor
    } B;
    __IO uint32_t  R;
    explicit PRER_DEF () noexcept { R = 0x007f00ffu; }
    template<typename F> void setbit (F f) volatile {
      PRER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      PRER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ALRMAR_DEF   {  //!< alarm A register
    struct {
      __IO uint32_t   SU    :  4; //!<[00] Second units in BCD format.
      __IO uint32_t   ST    :  3; //!<[04] Second tens in BCD format.
      __IO ONE_BIT    MSK1  :  1; //!<[07] Alarm A seconds mask
      __IO uint32_t   MNU   :  4; //!<[08] Minute units in BCD format.
      __IO uint32_t   MNT   :  3; //!<[12] Minute tens in BCD format.
      __IO ONE_BIT    MSK2  :  1; //!<[15] Alarm A minutes mask
      __IO uint32_t   HU    :  4; //!<[16] Hour units in BCD format.
      __IO uint32_t   HT    :  2; //!<[20] Hour tens in BCD format.
      __IO ONE_BIT    PM    :  1; //!<[22] AM/PM notation
      __IO ONE_BIT    MSK3  :  1; //!<[23] Alarm A hours mask
      __IO uint32_t   DU    :  4; //!<[24] Date units or day in BCD format.
      __IO uint32_t   DT    :  2; //!<[28] Date tens in BCD format.
      __IO ONE_BIT    WDSEL :  1; //!<[30] Week day selection
      __IO ONE_BIT    MSK4  :  1; //!<[31] Alarm A date mask
    } B;
    __IO uint32_t  R;
    explicit ALRMAR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ALRMAR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ALRMAR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union WPR_DEF      {  //!< write protection register
    struct {
      __O  uint32_t   KEY :  8; //!<[00] Write protection key
    } B;
    __O  uint32_t  R;
    explicit WPR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      WPR_DEF r;
      R = f (r);
    }
  };
  union SSR_DEF      {  //!< sub second register
    struct {
      __I  uint32_t   SS : 16; //!<[00] Sub second value
    } B;
    __I  uint32_t  R;

    explicit SSR_DEF (volatile SSR_DEF & o) noexcept { R = o.R; };
  };
  union SHIFTR_DEF   {  //!< shift control register
    struct {
      __O  uint32_t   SUBFS   : 15; //!<[00] Subtract a fraction of a second
           uint32_t   UNUSED0 : 16; //!<[15] 
      __O  ONE_BIT    ADD1S   :  1; //!<[31] Add one second
    } B;
    __O  uint32_t  R;
    explicit SHIFTR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SHIFTR_DEF r;
      R = f (r);
    }
  };
  union TSTR_DEF     {  //!< timestamp time register
    struct {
      __I  uint32_t   SU      :  4; //!<[00] Second units in BCD format.
      __I  uint32_t   ST      :  3; //!<[04] Second tens in BCD format.
           ONE_BIT    UNUSED0 :  1; //!<[07] 
      __I  uint32_t   MNU     :  4; //!<[08] Minute units in BCD format.
      __I  uint32_t   MNT     :  3; //!<[12] Minute tens in BCD format.
           ONE_BIT    UNUSED1 :  1; //!<[15] 
      __I  uint32_t   HU      :  4; //!<[16] Hour units in BCD format.
      __I  uint32_t   HT      :  2; //!<[20] Hour tens in BCD format.
      __I  ONE_BIT    PM      :  1; //!<[22] AM/PM notation
    } B;
    __I  uint32_t  R;

    explicit TSTR_DEF (volatile TSTR_DEF & o) noexcept { R = o.R; };
  };
  union TSDR_DEF     {  //!< timestamp date register
    struct {
      __I  uint32_t   DU      :  4; //!<[00] Date units in BCD format
      __I  uint32_t   DT      :  2; //!<[04] Date tens in BCD format
           uint32_t   UNUSED0 :  2; //!<[06] 
      __I  uint32_t   MU      :  4; //!<[08] Month units in BCD format
      __I  ONE_BIT    MT      :  1; //!<[12] Month tens in BCD format
      __I  uint32_t   WDU     :  3; //!<[13] Week day units
    } B;
    __I  uint32_t  R;

    explicit TSDR_DEF (volatile TSDR_DEF & o) noexcept { R = o.R; };
  };
  union TSSSR_DEF    {  //!< time-stamp sub second register
    struct {
      __I  uint32_t   SS : 16; //!<[00] Sub second value
    } B;
    __I  uint32_t  R;

    explicit TSSSR_DEF (volatile TSSSR_DEF & o) noexcept { R = o.R; };
  };
  union CALR_DEF     {  //!< calibration register
    struct {
      __IO uint32_t   CALM    :  9; //!<[00] Calibration minus
           uint32_t   UNUSED0 :  4; //!<[09] 
      __IO ONE_BIT    CALW16  :  1; //!<[13] Use a 16-second calibration cycle period
      __IO ONE_BIT    CALW8   :  1; //!<[14] Use an 8-second calibration cycle period
      __IO ONE_BIT    CALP    :  1; //!<[15] Increase frequency of RTC by 488.5 ppm
    } B;
    __IO uint32_t  R;
    explicit CALR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CALR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CALR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union TAFCR_DEF    {  //!< tamper and alternate function configuration register
    struct {
      __IO ONE_BIT    TAMP1E     :  1; //!<[00] RTC_TAMP1 input detection enable
      __IO ONE_BIT    TAMP1TRG   :  1; //!<[01] Active level for RTC_TAMP1 input
      __IO ONE_BIT    TAMPIE     :  1; //!<[02] Tamper interrupt enable
      __IO ONE_BIT    TAMP2E     :  1; //!<[03] RTC_TAMP2 input detection enable
      __IO ONE_BIT    TAMP2_TRG  :  1; //!<[04] Active level for RTC_TAMP2 input
           uint32_t   UNUSED0    :  2; //!<[05] 
      __IO ONE_BIT    TAMPTS     :  1; //!<[07] Activate timestamp on tamper detection event
      __IO uint32_t   TAMPFREQ   :  3; //!<[08] Tamper sampling frequency
      __IO uint32_t   TAMPFLT    :  2; //!<[11] RTC_TAMPx filter count
      __IO uint32_t   TAMP_PRCH  :  2; //!<[13] RTC_TAMPx precharge duration
      __IO ONE_BIT    TAMP_PUDIS :  1; //!<[15] RTC_TAMPx pull-up disable
           uint32_t   UNUSED1    :  2; //!<[16] 
      __IO ONE_BIT    PC13VALUE  :  1; //!<[18] RTC_ALARM output type/PC13 value
      __IO ONE_BIT    PC13MODE   :  1; //!<[19] PC13 mode
      __IO ONE_BIT    PC14VALUE  :  1; //!<[20] PC14 value
      __IO ONE_BIT    PC14MODE   :  1; //!<[21] PC14 mode
      __IO ONE_BIT    PC15VALUE  :  1; //!<[22] PC15 value
      __IO ONE_BIT    PC15MODE   :  1; //!<[23] PC15 mode
    } B;
    __IO uint32_t  R;
    explicit TAFCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      TAFCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      TAFCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ALRMASSR_DEF {  //!< alarm A sub second register
    struct {
      __IO uint32_t   SS      : 15; //!<[00] Sub seconds value
           uint32_t   UNUSED0 :  9; //!<[15] 
      __IO uint32_t   MASKSS  :  4; //!<[24] Mask the most-significant bits starting at this bit
    } B;
    __IO uint32_t  R;
    explicit ALRMASSR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ALRMASSR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ALRMASSR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union BKP0R_DEF    {  //!< backup register
    struct {
      __IO uint32_t   BKP : 32; //!<[00] BKP
    } B;
    __IO uint32_t  R;
    explicit BKP0R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      BKP0R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      BKP0R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union BKP1R_DEF    {  //!< backup register
    struct {
      __IO uint32_t   BKP : 32; //!<[00] BKP
    } B;
    __IO uint32_t  R;
    explicit BKP1R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      BKP1R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      BKP1R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union BKP2R_DEF    {  //!< backup register
    struct {
      __IO uint32_t   BKP : 32; //!<[00] BKP
    } B;
    __IO uint32_t  R;
    explicit BKP2R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      BKP2R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      BKP2R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union BKP3R_DEF    {  //!< backup register
    struct {
      __IO uint32_t   BKP : 32; //!<[00] BKP
    } B;
    __IO uint32_t  R;
    explicit BKP3R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      BKP3R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      BKP3R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union BKP4R_DEF    {  //!< backup register
    struct {
      __IO uint32_t   BKP : 32; //!<[00] BKP
    } B;
    __IO uint32_t  R;
    explicit BKP4R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      BKP4R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      BKP4R_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL RTC REGISTERS INSTANCES
  __IO TR_DEF                    TR ;  //!< [0000](04)[0x00000000]
  __IO DR_DEF                    DR ;  //!< [0004](04)[0x00002101]
  __IO CR_DEF                    CR ;  //!< [0008](04)[0x00000000]
  __IO ISR_DEF                  ISR ;  //!< [000c](04)[0x00000007]
  __IO PRER_DEF                PRER ;  //!< [0010](04)[0x007F00FF]
       uint32_t           UNUSED0 [2];  //!< [0014](08)[0xFFFFFFFF]
  __IO ALRMAR_DEF            ALRMAR ;  //!< [001c](04)[0x00000000]
       uint32_t           UNUSED1 ;  //!< [0020](04)[0xFFFFFFFF]
  __O  WPR_DEF                  WPR ;  //!< [0024](04)[0x00000000]
  __I  SSR_DEF                  SSR ;  //!< [0028](04)[0x00000000]
  __O  SHIFTR_DEF            SHIFTR ;  //!< [002c](04)[0x00000000]
  __I  TSTR_DEF                TSTR ;  //!< [0030](04)[0x00000000]
  __I  TSDR_DEF                TSDR ;  //!< [0034](04)[0x00000000]
  __I  TSSSR_DEF              TSSSR ;  //!< [0038](04)[0x00000000]
  __IO CALR_DEF                CALR ;  //!< [003c](04)[0x00000000]
  __IO TAFCR_DEF              TAFCR ;  //!< [0040](04)[0x00000000]
  __IO ALRMASSR_DEF        ALRMASSR ;  //!< [0044](04)[0x00000000]
       uint32_t           UNUSED2 [2];  //!< [0048](08)[0xFFFFFFFF]
  __IO BKP0R_DEF              BKP0R ;  //!< [0050](04)[0x00000000]
  __IO BKP1R_DEF              BKP1R ;  //!< [0054](04)[0x00000000]
  __IO BKP2R_DEF              BKP2R ;  //!< [0058](04)[0x00000000]
  __IO BKP3R_DEF              BKP3R ;  //!< [005c](04)[0x00000000]
  __IO BKP4R_DEF              BKP4R ;  //!< [0060](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x0064 */

// ////////////////////+++ TIM15 +-+//////////////////// //
struct TIM15_Type       { /*!< General-purpose-timers */
  union CR1_DEF         {  //!< control register 1
    struct {
      __IO ONE_BIT    CEN     :  1; //!<[00] Counter enable
      __IO ONE_BIT    UDIS    :  1; //!<[01] Update disable
      __IO ONE_BIT    URS     :  1; //!<[02] Update request source
      __IO ONE_BIT    OPM     :  1; //!<[03] One-pulse mode
           uint32_t   UNUSED0 :  3; //!<[04] 
      __IO ONE_BIT    ARPE    :  1; //!<[07] Auto-reload preload enable
      __IO uint32_t   CKD     :  2; //!<[08] Clock division
    } B;
    __IO uint32_t  R;
    explicit CR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CR2_DEF         {  //!< control register 2
    struct {
      __IO ONE_BIT    CCPC    :  1; //!<[00] Capture/compare preloaded control
           ONE_BIT    UNUSED0 :  1; //!<[01] 
      __IO ONE_BIT    CCUS    :  1; //!<[02] Capture/compare control update selection
      __IO ONE_BIT    CCDS    :  1; //!<[03] Capture/compare DMA selection
      __IO uint32_t   MMS     :  3; //!<[04] Master mode selection
           ONE_BIT    UNUSED1 :  1; //!<[07] 
      __IO ONE_BIT    OIS1    :  1; //!<[08] Output Idle state 1
      __IO ONE_BIT    OIS1N   :  1; //!<[09] Output Idle state 1
      __IO ONE_BIT    OIS2    :  1; //!<[10] Output Idle state 2
    } B;
    __IO uint32_t  R;
    explicit CR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SMCR_DEF        {  //!< slave mode control register
    struct {
      __IO uint32_t   SMS     :  3; //!<[00] Slave mode selection
           ONE_BIT    UNUSED0 :  1; //!<[03] 
      __IO uint32_t   TS      :  3; //!<[04] Trigger selection
      __IO ONE_BIT    MSM     :  1; //!<[07] Master/Slave mode
    } B;
    __IO uint32_t  R;
    explicit SMCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SMCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SMCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DIER_DEF        {  //!< DMA/Interrupt enable register
    struct {
      __IO ONE_BIT    UIE     :  1; //!<[00] Update interrupt enable
      __IO ONE_BIT    CC1IE   :  1; //!<[01] Capture/Compare 1 interrupt enable
      __IO ONE_BIT    CC2IE   :  1; //!<[02] Capture/Compare 2 interrupt enable
           uint32_t   UNUSED0 :  2; //!<[03] 
      __IO ONE_BIT    COMIE   :  1; //!<[05] COM interrupt enable
      __IO ONE_BIT    TIE     :  1; //!<[06] Trigger interrupt enable
      __IO ONE_BIT    BIE     :  1; //!<[07] Break interrupt enable
      __IO ONE_BIT    UDE     :  1; //!<[08] Update DMA request enable
      __IO ONE_BIT    CC1DE   :  1; //!<[09] Capture/Compare 1 DMA request enable
      __IO ONE_BIT    CC2DE   :  1; //!<[10] Capture/Compare 2 DMA request enable
           uint32_t   UNUSED1 :  3; //!<[11] 
      __IO ONE_BIT    TDE     :  1; //!<[14] Trigger DMA request enable
    } B;
    __IO uint32_t  R;
    explicit DIER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DIER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DIER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SR_DEF          {  //!< status register
    struct {
      __IO ONE_BIT    UIF     :  1; //!<[00] Update interrupt flag
      __IO ONE_BIT    CC1IF   :  1; //!<[01] Capture/compare 1 interrupt flag
      __IO ONE_BIT    CC2IF   :  1; //!<[02] Capture/Compare 2 interrupt flag
           uint32_t   UNUSED0 :  2; //!<[03] 
      __IO ONE_BIT    COMIF   :  1; //!<[05] COM interrupt flag
      __IO ONE_BIT    TIF     :  1; //!<[06] Trigger interrupt flag
      __IO ONE_BIT    BIF     :  1; //!<[07] Break interrupt flag
           ONE_BIT    UNUSED1 :  1; //!<[08] 
      __IO ONE_BIT    CC1OF   :  1; //!<[09] Capture/Compare 1 overcapture flag
      __IO ONE_BIT    CC2OF   :  1; //!<[10] Capture/compare 2 overcapture flag
    } B;
    __IO uint32_t  R;
    explicit SR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union EGR_DEF         {  //!< event generation register
    struct {
      __O  ONE_BIT    UG      :  1; //!<[00] Update generation
      __O  ONE_BIT    CC1G    :  1; //!<[01] Capture/compare 1 generation
      __O  ONE_BIT    CC2G    :  1; //!<[02] Capture/compare 2 generation
           uint32_t   UNUSED0 :  2; //!<[03] 
      __O  ONE_BIT    COMG    :  1; //!<[05] Capture/Compare control update generation
      __O  ONE_BIT    TG      :  1; //!<[06] Trigger generation
      __O  ONE_BIT    BG      :  1; //!<[07] Break generation
    } B;
    __O  uint32_t  R;
    explicit EGR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      EGR_DEF r;
      R = f (r);
    }
  };
  union CCMR1_Input_DEF {  //!< capture/compare mode register 1 (input mode)
    struct {
      __IO uint32_t   CC1S   :  2; //!<[00] Capture/Compare 1 selection
      __IO uint32_t   IC1PSC :  2; //!<[02] Input capture 1 prescaler
      __IO uint32_t   IC1F   :  4; //!<[04] Input capture 1 filter
      __IO uint32_t   CC2S   :  2; //!<[08] Capture/Compare 2 selection
      __IO uint32_t   IC2PSC :  2; //!<[10] Input capture 2 prescaler
      __IO uint32_t   IC2F   :  4; //!<[12] Input capture 2 filter
    } B;
    __IO uint32_t  R;
    explicit CCMR1_Input_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCMR1_Input_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCMR1_Input_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCMR1_Output_DEF  {  //!< capture/compare mode register (output mode)
    struct {
      __IO uint32_t   CC1S    :  2; //!<[00] Capture/Compare 1 selection
      __IO ONE_BIT    OC1FE   :  1; //!<[02] Output Compare 1 fast enable
      __IO ONE_BIT    OC1PE   :  1; //!<[03] Output Compare 1 preload enable
      __IO uint32_t   OC1M    :  3; //!<[04] Output Compare 1 mode
           ONE_BIT    UNUSED0 :  1; //!<[07] 
      __IO uint32_t   CC2S    :  2; //!<[08] Capture/Compare 2 selection
      __IO ONE_BIT    OC2FE   :  1; //!<[10] Output Compare 2 fast enable
      __IO ONE_BIT    OC2PE   :  1; //!<[11] Output Compare 2 preload enable
      __IO uint32_t   OC2M    :  3; //!<[12] Output Compare 2 mode
    } B;
    __IO uint32_t  R;
    explicit CCMR1_Output_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCMR1_Output_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCMR1_Output_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCER_DEF        {  //!< capture/compare enable register
    struct {
      __IO ONE_BIT  CC1E    :  1; //!<[00] Capture/Compare 1 output enable
      __IO ONE_BIT  CC1P    :  1; //!<[01] Capture/Compare 1 output Polarity
      __IO ONE_BIT  CC1NE   :  1; //!<[02] Capture/Compare 1 complementary output enable
      __IO ONE_BIT  CC1NP   :  1; //!<[03] Capture/Compare 1 output Polarity
      __IO ONE_BIT  CC2E    :  1; //!<[04] Capture/Compare 2 output enable
      __IO ONE_BIT  CC2P    :  1; //!<[05] Capture/Compare 2 output Polarity
           ONE_BIT  UNUSED0 :  1; //!<[06] 
      __IO ONE_BIT  CC2NP   :  1; //!<[07] Capture/Compare 2 output Polarity
    } B;
    __IO uint32_t  R;
    explicit CCER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CNT_DEF         {  //!< counter
    struct {
      __IO uint32_t   CNT : 16; //!<[00] counter value
    } B;
    __IO uint32_t  R;
    explicit CNT_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CNT_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CNT_DEF r; r.R = R;
      R = f (r);
    }
  };
  union PSC_DEF         {  //!< prescaler
    struct {
      __IO uint32_t   PSC : 16; //!<[00] Prescaler value
    } B;
    __IO uint32_t  R;
    explicit PSC_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      PSC_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      PSC_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ARR_DEF         {  //!< auto-reload register
    struct {
      __IO uint32_t   ARR : 16; //!<[00] Auto-reload value
    } B;
    __IO uint32_t  R;
    explicit ARR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ARR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ARR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union RCR_DEF         {  //!< repetition counter register
    struct {
      __IO uint32_t   REP :  8; //!<[00] Repetition counter value
    } B;
    __IO uint32_t  R;
    explicit RCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      RCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      RCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR1_DEF        {  //!< capture/compare register 1
    struct {
      __IO uint32_t   CCR1 : 16; //!<[00] Capture/Compare 1 value
    } B;
    __IO uint32_t  R;
    explicit CCR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR2_DEF        {  //!< capture/compare register 2
    struct {
      __IO uint32_t   CCR2 : 16; //!<[00] Capture/Compare 2 value
    } B;
    __IO uint32_t  R;
    explicit CCR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union BDTR_DEF        {  //!< break and dead-time register
    struct {
      __IO uint32_t   DTG  :  8; //!<[00] Dead-time generator setup
      __IO uint32_t   LOCK :  2; //!<[08] Lock configuration
      __IO ONE_BIT    OSSI :  1; //!<[10] Off-state selection for Idle mode
      __IO ONE_BIT    OSSR :  1; //!<[11] Off-state selection for Run mode
      __IO ONE_BIT    BKE  :  1; //!<[12] Break enable
      __IO ONE_BIT    BKP  :  1; //!<[13] Break polarity
      __IO ONE_BIT    AOE  :  1; //!<[14] Automatic output enable
      __IO ONE_BIT    MOE  :  1; //!<[15] Main output enable
    } B;
    __IO uint32_t  R;
    explicit BDTR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      BDTR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      BDTR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DCR_DEF         {  //!< DMA control register
    struct {
      __IO uint32_t   DBA     :  5; //!<[00] DMA base address
           uint32_t   UNUSED0 :  3; //!<[05] 
      __IO uint32_t   DBL     :  5; //!<[08] DMA burst length
    } B;
    __IO uint32_t  R;
    explicit DCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DMAR_DEF        {  //!< DMA address for full transfer
    struct {
      __IO uint32_t   DMAB : 16; //!<[00] DMA register for burst accesses
    } B;
    __IO uint32_t  R;
    explicit DMAR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DMAR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DMAR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL TIM15 REGISTERS INSTANCES
  __IO CR1_DEF                     CR1 ;  //!< [0000](04)[0x00000000]
  __IO CR2_DEF                     CR2 ;  //!< [0004](04)[0x00000000]
  __IO SMCR_DEF                   SMCR ;  //!< [0008](04)[0x00000000]
  __IO DIER_DEF                   DIER ;  //!< [000c](04)[0x00000000]
  __IO SR_DEF                       SR ;  //!< [0010](04)[0x00000000]
  __O  EGR_DEF                     EGR ;  //!< [0014](04)[0x00000000]
  MERGE {
  __IO CCMR1_Input_DEF     CCMR1_Input ;  //!< [0018](04)[0x00000000]
  __IO CCMR1_Output_DEF     CCMR1_Output ;  //!< [0018](04)[0x00000000]
  };
       uint32_t              UNUSED0 ;  //!< [001c](04)[0xFFFFFFFF]
  __IO CCER_DEF                   CCER ;  //!< [0020](04)[0x00000000]
  __IO CNT_DEF                     CNT ;  //!< [0024](04)[0x00000000]
  __IO PSC_DEF                     PSC ;  //!< [0028](04)[0x00000000]
  __IO ARR_DEF                     ARR ;  //!< [002c](04)[0x00000000]
  __IO RCR_DEF                     RCR ;  //!< [0030](04)[0x00000000]
  __IO CCR1_DEF                   CCR1 ;  //!< [0034](04)[0x00000000]
  __IO CCR2_DEF                   CCR2 ;  //!< [0038](04)[0x00000000]
       uint32_t              UNUSED1 [2];  //!< [003c](08)[0xFFFFFFFF]
  __IO BDTR_DEF                   BDTR ;  //!< [0044](04)[0x00000000]
  __IO DCR_DEF                     DCR ;  //!< [0048](04)[0x00000000]
  __IO DMAR_DEF                   DMAR ;  //!< [004c](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x0050 */

// ////////////////////+++ TIM16 +-+//////////////////// //
struct TIM16_Type       { /*!< General-purpose-timers */
  union CR1_DEF         {  //!< control register 1
    struct {
      __IO ONE_BIT    CEN     :  1; //!<[00] Counter enable
      __IO ONE_BIT    UDIS    :  1; //!<[01] Update disable
      __IO ONE_BIT    URS     :  1; //!<[02] Update request source
      __IO ONE_BIT    OPM     :  1; //!<[03] One-pulse mode
           uint32_t   UNUSED0 :  3; //!<[04] 
      __IO ONE_BIT    ARPE    :  1; //!<[07] Auto-reload preload enable
      __IO uint32_t   CKD     :  2; //!<[08] Clock division
    } B;
    __IO uint32_t  R;
    explicit CR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CR2_DEF         {  //!< control register 2
    struct {
      __IO ONE_BIT    CCPC    :  1; //!<[00] Capture/compare preloaded control
           ONE_BIT    UNUSED0 :  1; //!<[01] 
      __IO ONE_BIT    CCUS    :  1; //!<[02] Capture/compare control update selection
      __IO ONE_BIT    CCDS    :  1; //!<[03] Capture/compare DMA selection
           uint32_t   UNUSED1 :  4; //!<[04] 
      __IO ONE_BIT    OIS1    :  1; //!<[08] Output Idle state 1
      __IO ONE_BIT    OIS1N   :  1; //!<[09] Output Idle state 1
    } B;
    __IO uint32_t  R;
    explicit CR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DIER_DEF        {  //!< DMA/Interrupt enable register
    struct {
      __IO ONE_BIT    UIE     :  1; //!<[00] Update interrupt enable
      __IO ONE_BIT    CC1IE   :  1; //!<[01] Capture/Compare 1 interrupt enable
           uint32_t   UNUSED0 :  3; //!<[02] 
      __IO ONE_BIT    COMIE   :  1; //!<[05] COM interrupt enable
      __IO ONE_BIT    TIE     :  1; //!<[06] Trigger interrupt enable
      __IO ONE_BIT    BIE     :  1; //!<[07] Break interrupt enable
      __IO ONE_BIT    UDE     :  1; //!<[08] Update DMA request enable
      __IO ONE_BIT    CC1DE   :  1; //!<[09] Capture/Compare 1 DMA request enable
           uint32_t   UNUSED1 :  4; //!<[10] 
      __IO ONE_BIT    TDE     :  1; //!<[14] Trigger DMA request enable
    } B;
    __IO uint32_t  R;
    explicit DIER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DIER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DIER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SR_DEF          {  //!< status register
    struct {
      __IO ONE_BIT    UIF     :  1; //!<[00] Update interrupt flag
      __IO ONE_BIT    CC1IF   :  1; //!<[01] Capture/compare 1 interrupt flag
           uint32_t   UNUSED0 :  3; //!<[02] 
      __IO ONE_BIT    COMIF   :  1; //!<[05] COM interrupt flag
      __IO ONE_BIT    TIF     :  1; //!<[06] Trigger interrupt flag
      __IO ONE_BIT    BIF     :  1; //!<[07] Break interrupt flag
           ONE_BIT    UNUSED1 :  1; //!<[08] 
      __IO ONE_BIT    CC1OF   :  1; //!<[09] Capture/Compare 1 overcapture flag
    } B;
    __IO uint32_t  R;
    explicit SR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union EGR_DEF         {  //!< event generation register
    struct {
      __O  ONE_BIT    UG      :  1; //!<[00] Update generation
      __O  ONE_BIT    CC1G    :  1; //!<[01] Capture/compare 1 generation
           uint32_t   UNUSED0 :  3; //!<[02] 
      __O  ONE_BIT    COMG    :  1; //!<[05] Capture/Compare control update generation
      __O  ONE_BIT    TG      :  1; //!<[06] Trigger generation
      __O  ONE_BIT    BG      :  1; //!<[07] Break generation
    } B;
    __O  uint32_t  R;
    explicit EGR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      EGR_DEF r;
      R = f (r);
    }
  };
  union CCMR1_Input_DEF {  //!< capture/compare mode register 1 (input mode)
    struct {
      __IO uint32_t   CC1S   :  2; //!<[00] Capture/Compare 1 selection
      __IO uint32_t   IC1PSC :  2; //!<[02] Input capture 1 prescaler
      __IO uint32_t   IC1F   :  4; //!<[04] Input capture 1 filter
    } B;
    __IO uint32_t  R;
    explicit CCMR1_Input_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCMR1_Input_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCMR1_Input_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCMR1_Output_DEF  {  //!< capture/compare mode register (output mode)
    struct {
      __IO uint32_t   CC1S  :  2; //!<[00] Capture/Compare 1 selection
      __IO ONE_BIT    OC1FE :  1; //!<[02] Output Compare 1 fast enable
      __IO ONE_BIT    OC1PE :  1; //!<[03] Output Compare 1 preload enable
      __IO uint32_t   OC1M  :  3; //!<[04] Output Compare 1 mode
    } B;
    __IO uint32_t  R;
    explicit CCMR1_Output_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCMR1_Output_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCMR1_Output_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCER_DEF        {  //!< capture/compare enable register
    struct {
      __IO ONE_BIT  CC1E  :  1; //!<[00] Capture/Compare 1 output enable
      __IO ONE_BIT  CC1P  :  1; //!<[01] Capture/Compare 1 output Polarity
      __IO ONE_BIT  CC1NE :  1; //!<[02] Capture/Compare 1 complementary output enable
      __IO ONE_BIT  CC1NP :  1; //!<[03] Capture/Compare 1 output Polarity
    } B;
    __IO uint32_t  R;
    explicit CCER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CNT_DEF         {  //!< counter
    struct {
      __IO uint32_t   CNT : 16; //!<[00] counter value
    } B;
    __IO uint32_t  R;
    explicit CNT_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CNT_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CNT_DEF r; r.R = R;
      R = f (r);
    }
  };
  union PSC_DEF         {  //!< prescaler
    struct {
      __IO uint32_t   PSC : 16; //!<[00] Prescaler value
    } B;
    __IO uint32_t  R;
    explicit PSC_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      PSC_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      PSC_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ARR_DEF         {  //!< auto-reload register
    struct {
      __IO uint32_t   ARR : 16; //!<[00] Auto-reload value
    } B;
    __IO uint32_t  R;
    explicit ARR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ARR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ARR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union RCR_DEF         {  //!< repetition counter register
    struct {
      __IO uint32_t   REP :  8; //!<[00] Repetition counter value
    } B;
    __IO uint32_t  R;
    explicit RCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      RCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      RCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR1_DEF        {  //!< capture/compare register 1
    struct {
      __IO uint32_t   CCR1 : 16; //!<[00] Capture/Compare 1 value
    } B;
    __IO uint32_t  R;
    explicit CCR1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union BDTR_DEF        {  //!< break and dead-time register
    struct {
      __IO uint32_t   DTG  :  8; //!<[00] Dead-time generator setup
      __IO uint32_t   LOCK :  2; //!<[08] Lock configuration
      __IO ONE_BIT    OSSI :  1; //!<[10] Off-state selection for Idle mode
      __IO ONE_BIT    OSSR :  1; //!<[11] Off-state selection for Run mode
      __IO ONE_BIT    BKE  :  1; //!<[12] Break enable
      __IO ONE_BIT    BKP  :  1; //!<[13] Break polarity
      __IO ONE_BIT    AOE  :  1; //!<[14] Automatic output enable
      __IO ONE_BIT    MOE  :  1; //!<[15] Main output enable
    } B;
    __IO uint32_t  R;
    explicit BDTR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      BDTR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      BDTR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DCR_DEF         {  //!< DMA control register
    struct {
      __IO uint32_t   DBA     :  5; //!<[00] DMA base address
           uint32_t   UNUSED0 :  3; //!<[05] 
      __IO uint32_t   DBL     :  5; //!<[08] DMA burst length
    } B;
    __IO uint32_t  R;
    explicit DCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DMAR_DEF        {  //!< DMA address for full transfer
    struct {
      __IO uint32_t   DMAB : 16; //!<[00] DMA register for burst accesses
    } B;
    __IO uint32_t  R;
    explicit DMAR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DMAR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DMAR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL TIM16 REGISTERS INSTANCES
  __IO CR1_DEF                     CR1 ;  //!< [0000](04)[0x00000000]
  __IO CR2_DEF                     CR2 ;  //!< [0004](04)[0x00000000]
       uint32_t              UNUSED0 ;  //!< [0008](04)[0xFFFFFFFF]
  __IO DIER_DEF                   DIER ;  //!< [000c](04)[0x00000000]
  __IO SR_DEF                       SR ;  //!< [0010](04)[0x00000000]
  __O  EGR_DEF                     EGR ;  //!< [0014](04)[0x00000000]
  MERGE {
  __IO CCMR1_Input_DEF     CCMR1_Input ;  //!< [0018](04)[0x00000000]
  __IO CCMR1_Output_DEF     CCMR1_Output ;  //!< [0018](04)[0x00000000]
  };
       uint32_t              UNUSED1 ;  //!< [001c](04)[0xFFFFFFFF]
  __IO CCER_DEF                   CCER ;  //!< [0020](04)[0x00000000]
  __IO CNT_DEF                     CNT ;  //!< [0024](04)[0x00000000]
  __IO PSC_DEF                     PSC ;  //!< [0028](04)[0x00000000]
  __IO ARR_DEF                     ARR ;  //!< [002c](04)[0x00000000]
  __IO RCR_DEF                     RCR ;  //!< [0030](04)[0x00000000]
  __IO CCR1_DEF                   CCR1 ;  //!< [0034](04)[0x00000000]
       uint32_t              UNUSED2 [3];  //!< [0038](0c)[0xFFFFFFFF]
  __IO BDTR_DEF                   BDTR ;  //!< [0044](04)[0x00000000]
  __IO DCR_DEF                     DCR ;  //!< [0048](04)[0x00000000]
  __IO DMAR_DEF                   DMAR ;  //!< [004c](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x0050 */

// ////////////////////+++ TSC +-+//////////////////// //
struct TSC_Type         { /*!< Touch sensing controller */
  union CR_DEF      {  //!< control register
    struct {
      __IO ONE_BIT    TSCE    :  1; //!<[00] Touch sensing controller enable
      __IO ONE_BIT    START   :  1; //!<[01] Start a new acquisition
      __IO ONE_BIT    AM      :  1; //!<[02] Acquisition mode
      __IO ONE_BIT    SYNCPOL :  1; //!<[03] Synchronization pin polarity
      __IO ONE_BIT    IODEF   :  1; //!<[04] I/O Default mode
      __IO uint32_t   MCV     :  3; //!<[05] Max count value
           uint32_t   UNUSED0 :  4; //!<[08] 
      __IO uint32_t   PGPSC   :  3; //!<[12] pulse generator prescaler
      __IO ONE_BIT    SSPSC   :  1; //!<[15] Spread spectrum prescaler
      __IO ONE_BIT    SSE     :  1; //!<[16] Spread spectrum enable
      __IO uint32_t   SSD     :  7; //!<[17] Spread spectrum deviation
      __IO uint32_t   CTPL    :  4; //!<[24] Charge transfer pulse low
      __IO uint32_t   CTPH    :  4; //!<[28] Charge transfer pulse high
    } B;
    __IO uint32_t  R;
    explicit CR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IER_DEF     {  //!< interrupt enable register
    struct {
      __IO ONE_BIT  EOAIE :  1; //!<[00] End of acquisition interrupt enable
      __IO ONE_BIT  MCEIE :  1; //!<[01] Max count error interrupt enable
    } B;
    __IO uint32_t  R;
    explicit IER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ICR_DEF     {  //!< interrupt clear register
    struct {
      __IO ONE_BIT  EOAIC :  1; //!<[00] End of acquisition interrupt clear
      __IO ONE_BIT  MCEIC :  1; //!<[01] Max count error interrupt clear
    } B;
    __IO uint32_t  R;
    explicit ICR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ICR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ICR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ISR_DEF     {  //!< interrupt status register
    struct {
      __IO ONE_BIT  EOAF :  1; //!<[00] End of acquisition flag
      __IO ONE_BIT  MCEF :  1; //!<[01] Max count error flag
    } B;
    __IO uint32_t  R;
    explicit ISR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ISR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ISR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IOHCR_DEF   {  //!< I/O hysteresis control register
    struct {
      __IO ONE_BIT  G1_IO1 :  1; //!<[00] G1_IO1 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G1_IO2 :  1; //!<[01] G1_IO2 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G1_IO3 :  1; //!<[02] G1_IO3 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G1_IO4 :  1; //!<[03] G1_IO4 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G2_IO1 :  1; //!<[04] G2_IO1 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G2_IO2 :  1; //!<[05] G2_IO2 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G2_IO3 :  1; //!<[06] G2_IO3 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G2_IO4 :  1; //!<[07] G2_IO4 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G3_IO1 :  1; //!<[08] G3_IO1 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G3_IO2 :  1; //!<[09] G3_IO2 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G3_IO3 :  1; //!<[10] G3_IO3 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G3_IO4 :  1; //!<[11] G3_IO4 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G4_IO1 :  1; //!<[12] G4_IO1 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G4_IO2 :  1; //!<[13] G4_IO2 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G4_IO3 :  1; //!<[14] G4_IO3 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G4_IO4 :  1; //!<[15] G4_IO4 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G5_IO1 :  1; //!<[16] G5_IO1 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G5_IO2 :  1; //!<[17] G5_IO2 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G5_IO3 :  1; //!<[18] G5_IO3 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G5_IO4 :  1; //!<[19] G5_IO4 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G6_IO1 :  1; //!<[20] G6_IO1 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G6_IO2 :  1; //!<[21] G6_IO2 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G6_IO3 :  1; //!<[22] G6_IO3 Schmitt trigger hysteresis mode
      __IO ONE_BIT  G6_IO4 :  1; //!<[23] G6_IO4 Schmitt trigger hysteresis mode
    } B;
    __IO uint32_t  R;
    explicit IOHCR_DEF () noexcept { R = 0xffffffffu; }
    template<typename F> void setbit (F f) volatile {
      IOHCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IOHCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IOASCR_DEF  {  //!< I/O analog switch control register
    struct {
      __IO ONE_BIT  G1_IO1 :  1; //!<[00] G1_IO1 analog switch enable
      __IO ONE_BIT  G1_IO2 :  1; //!<[01] G1_IO2 analog switch enable
      __IO ONE_BIT  G1_IO3 :  1; //!<[02] G1_IO3 analog switch enable
      __IO ONE_BIT  G1_IO4 :  1; //!<[03] G1_IO4 analog switch enable
      __IO ONE_BIT  G2_IO1 :  1; //!<[04] G2_IO1 analog switch enable
      __IO ONE_BIT  G2_IO2 :  1; //!<[05] G2_IO2 analog switch enable
      __IO ONE_BIT  G2_IO3 :  1; //!<[06] G2_IO3 analog switch enable
      __IO ONE_BIT  G2_IO4 :  1; //!<[07] G2_IO4 analog switch enable
      __IO ONE_BIT  G3_IO1 :  1; //!<[08] G3_IO1 analog switch enable
      __IO ONE_BIT  G3_IO2 :  1; //!<[09] G3_IO2 analog switch enable
      __IO ONE_BIT  G3_IO3 :  1; //!<[10] G3_IO3 analog switch enable
      __IO ONE_BIT  G3_IO4 :  1; //!<[11] G3_IO4 analog switch enable
      __IO ONE_BIT  G4_IO1 :  1; //!<[12] G4_IO1 analog switch enable
      __IO ONE_BIT  G4_IO2 :  1; //!<[13] G4_IO2 analog switch enable
      __IO ONE_BIT  G4_IO3 :  1; //!<[14] G4_IO3 analog switch enable
      __IO ONE_BIT  G4_IO4 :  1; //!<[15] G4_IO4 analog switch enable
      __IO ONE_BIT  G5_IO1 :  1; //!<[16] G5_IO1 analog switch enable
      __IO ONE_BIT  G5_IO2 :  1; //!<[17] G5_IO2 analog switch enable
      __IO ONE_BIT  G5_IO3 :  1; //!<[18] G5_IO3 analog switch enable
      __IO ONE_BIT  G5_IO4 :  1; //!<[19] G5_IO4 analog switch enable
      __IO ONE_BIT  G6_IO1 :  1; //!<[20] G6_IO1 analog switch enable
      __IO ONE_BIT  G6_IO2 :  1; //!<[21] G6_IO2 analog switch enable
      __IO ONE_BIT  G6_IO3 :  1; //!<[22] G6_IO3 analog switch enable
      __IO ONE_BIT  G6_IO4 :  1; //!<[23] G6_IO4 analog switch enable
    } B;
    __IO uint32_t  R;
    explicit IOASCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IOASCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IOASCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IOSCR_DEF   {  //!< I/O sampling control register
    struct {
      __IO ONE_BIT  G1_IO1 :  1; //!<[00] G1_IO1 sampling mode
      __IO ONE_BIT  G1_IO2 :  1; //!<[01] G1_IO2 sampling mode
      __IO ONE_BIT  G1_IO3 :  1; //!<[02] G1_IO3 sampling mode
      __IO ONE_BIT  G1_IO4 :  1; //!<[03] G1_IO4 sampling mode
      __IO ONE_BIT  G2_IO1 :  1; //!<[04] G2_IO1 sampling mode
      __IO ONE_BIT  G2_IO2 :  1; //!<[05] G2_IO2 sampling mode
      __IO ONE_BIT  G2_IO3 :  1; //!<[06] G2_IO3 sampling mode
      __IO ONE_BIT  G2_IO4 :  1; //!<[07] G2_IO4 sampling mode
      __IO ONE_BIT  G3_IO1 :  1; //!<[08] G3_IO1 sampling mode
      __IO ONE_BIT  G3_IO2 :  1; //!<[09] G3_IO2 sampling mode
      __IO ONE_BIT  G3_IO3 :  1; //!<[10] G3_IO3 sampling mode
      __IO ONE_BIT  G3_IO4 :  1; //!<[11] G3_IO4 sampling mode
      __IO ONE_BIT  G4_IO1 :  1; //!<[12] G4_IO1 sampling mode
      __IO ONE_BIT  G4_IO2 :  1; //!<[13] G4_IO2 sampling mode
      __IO ONE_BIT  G4_IO3 :  1; //!<[14] G4_IO3 sampling mode
      __IO ONE_BIT  G4_IO4 :  1; //!<[15] G4_IO4 sampling mode
      __IO ONE_BIT  G5_IO1 :  1; //!<[16] G5_IO1 sampling mode
      __IO ONE_BIT  G5_IO2 :  1; //!<[17] G5_IO2 sampling mode
      __IO ONE_BIT  G5_IO3 :  1; //!<[18] G5_IO3 sampling mode
      __IO ONE_BIT  G5_IO4 :  1; //!<[19] G5_IO4 sampling mode
      __IO ONE_BIT  G6_IO1 :  1; //!<[20] G6_IO1 sampling mode
      __IO ONE_BIT  G6_IO2 :  1; //!<[21] G6_IO2 sampling mode
      __IO ONE_BIT  G6_IO3 :  1; //!<[22] G6_IO3 sampling mode
      __IO ONE_BIT  G6_IO4 :  1; //!<[23] G6_IO4 sampling mode
    } B;
    __IO uint32_t  R;
    explicit IOSCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IOSCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IOSCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IOCCR_DEF   {  //!< I/O channel control register
    struct {
      __IO ONE_BIT  G1_IO1 :  1; //!<[00] G1_IO1 channel mode
      __IO ONE_BIT  G1_IO2 :  1; //!<[01] G1_IO2 channel mode
      __IO ONE_BIT  G1_IO3 :  1; //!<[02] G1_IO3 channel mode
      __IO ONE_BIT  G1_IO4 :  1; //!<[03] G1_IO4 channel mode
      __IO ONE_BIT  G2_IO1 :  1; //!<[04] G2_IO1 channel mode
      __IO ONE_BIT  G2_IO2 :  1; //!<[05] G2_IO2 channel mode
      __IO ONE_BIT  G2_IO3 :  1; //!<[06] G2_IO3 channel mode
      __IO ONE_BIT  G2_IO4 :  1; //!<[07] G2_IO4 channel mode
      __IO ONE_BIT  G3_IO1 :  1; //!<[08] G3_IO1 channel mode
      __IO ONE_BIT  G3_IO2 :  1; //!<[09] G3_IO2 channel mode
      __IO ONE_BIT  G3_IO3 :  1; //!<[10] G3_IO3 channel mode
      __IO ONE_BIT  G3_IO4 :  1; //!<[11] G3_IO4 channel mode
      __IO ONE_BIT  G4_IO1 :  1; //!<[12] G4_IO1 channel mode
      __IO ONE_BIT  G4_IO2 :  1; //!<[13] G4_IO2 channel mode
      __IO ONE_BIT  G4_IO3 :  1; //!<[14] G4_IO3 channel mode
      __IO ONE_BIT  G4_IO4 :  1; //!<[15] G4_IO4 channel mode
      __IO ONE_BIT  G5_IO1 :  1; //!<[16] G5_IO1 channel mode
      __IO ONE_BIT  G5_IO2 :  1; //!<[17] G5_IO2 channel mode
      __IO ONE_BIT  G5_IO3 :  1; //!<[18] G5_IO3 channel mode
      __IO ONE_BIT  G5_IO4 :  1; //!<[19] G5_IO4 channel mode
      __IO ONE_BIT  G6_IO1 :  1; //!<[20] G6_IO1 channel mode
      __IO ONE_BIT  G6_IO2 :  1; //!<[21] G6_IO2 channel mode
      __IO ONE_BIT  G6_IO3 :  1; //!<[22] G6_IO3 channel mode
      __IO ONE_BIT  G6_IO4 :  1; //!<[23] G6_IO4 channel mode
    } B;
    __IO uint32_t  R;
    explicit IOCCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IOCCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IOCCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IOGCSR_DEF  {  //!< I/O group control status register
    struct {
      __IO ONE_BIT    G1E     :  1; //!<[00] Analog I/O group x enable
      __IO ONE_BIT    G2E     :  1; //!<[01] Analog I/O group x enable
      __IO ONE_BIT    G3E     :  1; //!<[02] Analog I/O group x enable
      __IO ONE_BIT    G4E     :  1; //!<[03] Analog I/O group x enable
      __IO ONE_BIT    G5E     :  1; //!<[04] Analog I/O group x enable
      __IO ONE_BIT    G6E     :  1; //!<[05] Analog I/O group x enable
      __IO ONE_BIT    G7E     :  1; //!<[06] Analog I/O group x enable
      __IO ONE_BIT    G8E     :  1; //!<[07] Analog I/O group x enable
           uint32_t   UNUSED0 :  8; //!<[08] 
      __I  ONE_BIT    G1S     :  1; //!<[16] Analog I/O group x status
      __I  ONE_BIT    G2S     :  1; //!<[17] Analog I/O group x status
      __I  ONE_BIT    G3S     :  1; //!<[18] Analog I/O group x status
      __I  ONE_BIT    G4S     :  1; //!<[19] Analog I/O group x status
      __I  ONE_BIT    G5S     :  1; //!<[20] Analog I/O group x status
      __I  ONE_BIT    G6S     :  1; //!<[21] Analog I/O group x status
      __IO ONE_BIT    G7S     :  1; //!<[22] Analog I/O group x status
      __IO ONE_BIT    G8S     :  1; //!<[23] Analog I/O group x status
    } B;
    __IO uint32_t  R;
    explicit IOGCSR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IOGCSR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IOGCSR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IOG1CR_DEF  {  //!< I/O group x counter register
    struct {
      __I  uint32_t   CNT : 14; //!<[00] Counter value
    } B;
    __I  uint32_t  R;

    explicit IOG1CR_DEF (volatile IOG1CR_DEF & o) noexcept { R = o.R; };
  };
  union IOG2CR_DEF  {  //!< I/O group x counter register
    struct {
      __I  uint32_t   CNT : 14; //!<[00] Counter value
    } B;
    __I  uint32_t  R;

    explicit IOG2CR_DEF (volatile IOG2CR_DEF & o) noexcept { R = o.R; };
  };
  union IOG3CR_DEF  {  //!< I/O group x counter register
    struct {
      __I  uint32_t   CNT : 14; //!<[00] Counter value
    } B;
    __I  uint32_t  R;

    explicit IOG3CR_DEF (volatile IOG3CR_DEF & o) noexcept { R = o.R; };
  };
  union IOG4CR_DEF  {  //!< I/O group x counter register
    struct {
      __I  uint32_t   CNT : 14; //!<[00] Counter value
    } B;
    __I  uint32_t  R;

    explicit IOG4CR_DEF (volatile IOG4CR_DEF & o) noexcept { R = o.R; };
  };
  union IOG5CR_DEF  {  //!< I/O group x counter register
    struct {
      __I  uint32_t   CNT : 14; //!<[00] Counter value
    } B;
    __I  uint32_t  R;

    explicit IOG5CR_DEF (volatile IOG5CR_DEF & o) noexcept { R = o.R; };
  };
  union IOG6CR_DEF  {  //!< I/O group x counter register
    struct {
      __I  uint32_t   CNT : 14; //!<[00] Counter value
    } B;
    __I  uint32_t  R;

    explicit IOG6CR_DEF (volatile IOG6CR_DEF & o) noexcept { R = o.R; };
  };
  // PERIPHERAL TSC REGISTERS INSTANCES
  __IO CR_DEF                   CR ;  //!< [0000](04)[0x00000000]
  __IO IER_DEF                 IER ;  //!< [0004](04)[0x00000000]
  __IO ICR_DEF                 ICR ;  //!< [0008](04)[0x00000000]
  __IO ISR_DEF                 ISR ;  //!< [000c](04)[0x00000000]
  __IO IOHCR_DEF             IOHCR ;  //!< [0010](04)[0xFFFFFFFF]
       uint32_t          UNUSED0 ;  //!< [0014](04)[0xFFFFFFFF]
  __IO IOASCR_DEF           IOASCR ;  //!< [0018](04)[0x00000000]
       uint32_t          UNUSED1 ;  //!< [001c](04)[0xFFFFFFFF]
  __IO IOSCR_DEF             IOSCR ;  //!< [0020](04)[0x00000000]
       uint32_t          UNUSED2 ;  //!< [0024](04)[0xFFFFFFFF]
  __IO IOCCR_DEF             IOCCR ;  //!< [0028](04)[0x00000000]
       uint32_t          UNUSED3 ;  //!< [002c](04)[0xFFFFFFFF]
  __IO IOGCSR_DEF           IOGCSR ;  //!< [0030](04)[0x00000000]
  __I  IOG1CR_DEF           IOG1CR ;  //!< [0034](04)[0x00000000]
  __I  IOG2CR_DEF           IOG2CR ;  //!< [0038](04)[0x00000000]
  __I  IOG3CR_DEF           IOG3CR ;  //!< [003c](04)[0x00000000]
  __I  IOG4CR_DEF           IOG4CR ;  //!< [0040](04)[0x00000000]
  __I  IOG5CR_DEF           IOG5CR ;  //!< [0044](04)[0x00000000]
  __I  IOG6CR_DEF           IOG6CR ;  //!< [0048](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x004C */

// ////////////////////+++ CEC +-+//////////////////// //
struct CEC_Type         { /*!< HDMI-CEC controller */
  union CR_DEF   {  //!< control register
    struct {
      __IO ONE_BIT  CECEN :  1; //!<[00] CEC Enable
      __IO ONE_BIT  TXSOM :  1; //!<[01] Tx start of message
      __IO ONE_BIT  TXEOM :  1; //!<[02] Tx End Of Message
    } B;
    __IO uint32_t  R;
    explicit CR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CFGR_DEF {  //!< configuration register
    struct {
      __IO uint32_t   OAR     :  4; //!<[00] Own Address
      __IO ONE_BIT    LSTN    :  1; //!<[04] Listen mode
      __IO uint32_t   SFT     :  3; //!<[05] Signal Free Time
      __IO ONE_BIT    RXTOL   :  1; //!<[08] Rx-Tolerance
      __IO ONE_BIT    BRESTP  :  1; //!<[09] Rx-stop on bit rising error
      __IO ONE_BIT    BREGEN  :  1; //!<[10] Generate error-bit on bit rising error
      __IO ONE_BIT    LBPEGEN :  1; //!<[11] Generate Error-Bit on Long Bit Period Error
    } B;
    __IO uint32_t  R;
    explicit CFGR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CFGR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CFGR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union TXDR_DEF {  //!< Tx data register
    struct {
      __O  uint32_t   TXD :  8; //!<[00] Tx Data register
    } B;
    __O  uint32_t  R;
    explicit TXDR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      TXDR_DEF r;
      R = f (r);
    }
  };
  union RXDR_DEF {  //!< Rx Data Register
    struct {
      __I  uint32_t   RXDR :  8; //!<[00] CEC Rx Data Register
    } B;
    __I  uint32_t  R;

    explicit RXDR_DEF (volatile RXDR_DEF & o) noexcept { R = o.R; };
  };
  union ISR_DEF  {  //!< Interrupt and Status Register
    struct {
      __IO ONE_BIT  RXBR   :  1; //!<[00] Rx-Byte Received
      __IO ONE_BIT  RXEND  :  1; //!<[01] End Of Reception
      __IO ONE_BIT  RXOVR  :  1; //!<[02] Rx-Overrun
      __IO ONE_BIT  BRE    :  1; //!<[03] Rx-Bit rising error
      __IO ONE_BIT  SBPE   :  1; //!<[04] Rx-Short Bit period error
      __IO ONE_BIT  LBPE   :  1; //!<[05] Rx-Long Bit Period Error
      __IO ONE_BIT  RXACKE :  1; //!<[06] Rx-Missing Acknowledge
      __IO ONE_BIT  ARBLST :  1; //!<[07] Arbitration Lost
      __IO ONE_BIT  TXBR   :  1; //!<[08] Tx-Byte Request
      __IO ONE_BIT  TXEND  :  1; //!<[09] End of Transmission
      __IO ONE_BIT  TXUDR  :  1; //!<[10] Tx-Buffer Underrun
      __IO ONE_BIT  TXERR  :  1; //!<[11] Tx-Error
      __IO ONE_BIT  TXACKE :  1; //!<[12] Tx-Missing acknowledge error
    } B;
    __IO uint32_t  R;
    explicit ISR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ISR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ISR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union IER_DEF  {  //!< interrupt enable register
    struct {
      __IO ONE_BIT  RXBRIE   :  1; //!<[00] Rx-Byte Received Interrupt Enable
      __IO ONE_BIT  RXENDIE  :  1; //!<[01] End Of Reception Interrupt Enable
      __IO ONE_BIT  RXOVRIE  :  1; //!<[02] Rx-Buffer Overrun Interrupt Enable
      __IO ONE_BIT  BREIE    :  1; //!<[03] Bit Rising Error Interrupt Enable
      __IO ONE_BIT  SBPEIE   :  1; //!<[04] Short Bit Period Error Interrupt Enable
      __IO ONE_BIT  LBPEIE   :  1; //!<[05] Long Bit Period Error Interrupt Enable
      __IO ONE_BIT  RXACKIE  :  1; //!<[06] Rx-Missing Acknowledge Error Interrupt Enable
      __IO ONE_BIT  ARBLSTIE :  1; //!<[07] Arbitration Lost Interrupt Enable
      __IO ONE_BIT  TXBRIE   :  1; //!<[08] Tx-Byte Request Interrupt Enable
      __IO ONE_BIT  TXENDIE  :  1; //!<[09] Tx-End of message interrupt enable
      __IO ONE_BIT  TXUDRIE  :  1; //!<[10] Tx-Underrun interrupt enable
      __IO ONE_BIT  TXERRIE  :  1; //!<[11] Tx-Error Interrupt Enable
      __IO ONE_BIT  TXACKIE  :  1; //!<[12] Tx-Missing Acknowledge Error Interrupt Enable
    } B;
    __IO uint32_t  R;
    explicit IER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      IER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      IER_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL CEC REGISTERS INSTANCES
  __IO CR_DEF                CR ;  //!< [0000](04)[0x00000000]
  __IO CFGR_DEF            CFGR ;  //!< [0004](04)[0x00000000]
  __O  TXDR_DEF            TXDR ;  //!< [0008](04)[0x00000000]
  __I  RXDR_DEF            RXDR ;  //!< [000c](04)[0x00000000]
  __IO ISR_DEF              ISR ;  //!< [0010](04)[0x00000000]
  __IO IER_DEF              IER ;  //!< [0014](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x0018 */

// ////////////////////+++ Flash +-+//////////////////// //
struct Flash_Type       { /*!< Flash */
  union ACR_DEF     {  //!< Flash access control register
    struct {
      __IO uint32_t   LATENCY :  3; //!<[00] LATENCY
           ONE_BIT    UNUSED0 :  1; //!<[03] 
      __IO ONE_BIT    PRFTBE  :  1; //!<[04] PRFTBE
      __I  ONE_BIT    PRFTBS  :  1; //!<[05] PRFTBS
    } B;
    __IO uint32_t  R;
    explicit ACR_DEF () noexcept { R = 0x00000030u; }
    template<typename F> void setbit (F f) volatile {
      ACR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ACR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union KEYR_DEF    {  //!< Flash key register
    struct {
      __O  uint32_t   FKEYR : 32; //!<[00] Flash Key
    } B;
    __O  uint32_t  R;
    explicit KEYR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      KEYR_DEF r;
      R = f (r);
    }
  };
  union OPTKEYR_DEF {  //!< Flash option key register
    struct {
      __O  uint32_t   OPTKEYR : 32; //!<[00] Option byte key
    } B;
    __O  uint32_t  R;
    explicit OPTKEYR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      OPTKEYR_DEF r;
      R = f (r);
    }
  };
  union SR_DEF      {  //!< Flash status register
    struct {
      __I  ONE_BIT  BSY     :  1; //!<[00] Busy
           ONE_BIT  UNUSED0 :  1; //!<[01] 
      __IO ONE_BIT  PGERR   :  1; //!<[02] Programming error
           ONE_BIT  UNUSED1 :  1; //!<[03] 
      __IO ONE_BIT  WRPRT   :  1; //!<[04] Write protection error
      __IO ONE_BIT  EOP     :  1; //!<[05] End of operation
    } B;
    __IO uint32_t  R;
    explicit SR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CR_DEF      {  //!< Flash control register
    struct {
      __IO ONE_BIT  PG            :  1; //!<[00] Programming
      __IO ONE_BIT  PER           :  1; //!<[01] Page erase
      __IO ONE_BIT  MER           :  1; //!<[02] Mass erase
           ONE_BIT  UNUSED0       :  1; //!<[03] 
      __IO ONE_BIT  OPTPG         :  1; //!<[04] Option byte programming
      __IO ONE_BIT  OPTER         :  1; //!<[05] Option byte erase
      __IO ONE_BIT  STRT          :  1; //!<[06] Start
      __IO ONE_BIT  LOCK          :  1; //!<[07] Lock
           ONE_BIT  UNUSED1       :  1; //!<[08] 
      __IO ONE_BIT  OPTWRE        :  1; //!<[09] Option bytes write enable
      __IO ONE_BIT  ERRIE         :  1; //!<[10] Error interrupt enable
           ONE_BIT  UNUSED2       :  1; //!<[11] 
      __IO ONE_BIT  EOPIE         :  1; //!<[12] End of operation interrupt enable
      __IO ONE_BIT  FORCE_OPTLOAD :  1; //!<[13] Force option byte loading
    } B;
    __IO uint32_t  R;
    explicit CR_DEF () noexcept { R = 0x00000080u; }
    template<typename F> void setbit (F f) volatile {
      CR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union AR_DEF      {  //!< Flash address register
    struct {
      __O  uint32_t   FAR : 32; //!<[00] Flash address
    } B;
    __O  uint32_t  R;
    explicit AR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      AR_DEF r;
      R = f (r);
    }
  };
  union OBR_DEF     {  //!< Option byte register
    struct {
      __I  ONE_BIT    OPTERR           :  1; //!<[00] Option byte error
      __I  uint32_t   RDPRT            :  2; //!<[01] Read protection level status
           uint32_t   UNUSED0          :  5; //!<[03] 
      __I  ONE_BIT    WDG_SW           :  1; //!<[08] WDG_SW
      __I  ONE_BIT    nRST_STOP        :  1; //!<[09] nRST_STOP
      __I  ONE_BIT    nRST_STDBY       :  1; //!<[10] nRST_STDBY
      __I  ONE_BIT    nBOOT0           :  1; //!<[11] nBOOT0
      __I  ONE_BIT    nBOOT1           :  1; //!<[12] BOOT1
      __I  ONE_BIT    VDDA_MONITOR     :  1; //!<[13] VDDA_MONITOR
      __I  ONE_BIT    RAM_PARITY_CHECK :  1; //!<[14] RAM_PARITY_CHECK
      __I  ONE_BIT    BOOT_SEL         :  1; //!<[15] BOOT_SEL
      __I  uint32_t   Data0            :  8; //!<[16] Data0
      __I  uint32_t   Data1            :  8; //!<[24] Data1
    } B;
    __I  uint32_t  R;

    explicit OBR_DEF (volatile OBR_DEF & o) noexcept { R = o.R; };
  };
  union WRPR_DEF    {  //!< Write protection register
    struct {
      __I  uint32_t   WRP : 32; //!<[00] Write protect
    } B;
    __I  uint32_t  R;

    explicit WRPR_DEF (volatile WRPR_DEF & o) noexcept { R = o.R; };
  };
  // PERIPHERAL Flash REGISTERS INSTANCES
  __IO ACR_DEF                 ACR ;  //!< [0000](04)[0x00000030]
  __O  KEYR_DEF               KEYR ;  //!< [0004](04)[0x00000000]
  __O  OPTKEYR_DEF         OPTKEYR ;  //!< [0008](04)[0x00000000]
  __IO SR_DEF                   SR ;  //!< [000c](04)[0x00000000]
  __IO CR_DEF                   CR ;  //!< [0010](04)[0x00000080]
  __O  AR_DEF                   AR ;  //!< [0014](04)[0x00000000]
       uint32_t          UNUSED0 ;  //!< [0018](04)[0xFFFFFFFF]
  __I  OBR_DEF                 OBR ;  //!< [001c](04)[0x03FFFFF2]
  __I  WRPR_DEF               WRPR ;  //!< [0020](04)[0xFFFFFFFF]
}; /* total size = 0x0400, struct size = 0x0024 */

// ////////////////////+++ DBGMCU +-+//////////////////// //
struct DBGMCU_Type      { /*!< Debug support */
  union IDCODE_DEF  {  //!< MCU Device ID Code Register
    struct {
      __I  uint32_t   DEV_ID : 12; //!<[00] Device Identifier
      __I  uint32_t   DIV_ID :  4; //!<[12] Division Identifier
      __I  uint32_t   REV_ID : 16; //!<[16] Revision Identifier
    } B;
    __I  uint32_t  R;

    explicit IDCODE_DEF (volatile IDCODE_DEF & o) noexcept { R = o.R; };
  };
  union CR_DEF      {  //!< Debug MCU Configuration Register
    struct {
           ONE_BIT  UNUSED0     :  1; //!<[00] 
      __IO ONE_BIT  DBG_STOP    :  1; //!<[01] Debug Stop Mode
      __IO ONE_BIT  DBG_STANDBY :  1; //!<[02] Debug Standby Mode
    } B;
    __IO uint32_t  R;
    explicit CR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union APB1_FZ_DEF {  //!< Debug MCU APB1 freeze register
    struct {
      __IO ONE_BIT    DBG_TIM2_STOP                            :  1; //!<[00] TIM2 counter stopped when core is halted
      __IO ONE_BIT    DBG_TIM3_STOP                            :  1; //!<[01] TIM3 counter stopped when core is halted
           uint32_t   UNUSED0                                  :  2; //!<[02] 
      __IO ONE_BIT    TIM3_counter_stopped_when_core_is_halted :  1; //!<[04] TIM6 counter stopped when core is halted
      __IO ONE_BIT    DBG_TIM7_STOP                            :  1; //!<[05] TIM7 counter stopped when core is halted
           uint32_t   UNUSED1                                  :  2; //!<[06] 
      __IO ONE_BIT    DBG_TIM14_STOP                           :  1; //!<[08] TIM14 counter stopped when core is halted
           ONE_BIT    UNUSED2                                  :  1; //!<[09] 
      __IO ONE_BIT    DBG_RTC_STOP                             :  1; //!<[10] Debug RTC stopped when core is halted
      __IO ONE_BIT    DBG_WWDG_STOP                            :  1; //!<[11] Debug window watchdog stopped when core is halted
      __IO ONE_BIT    DBG_IWDG_STOP                            :  1; //!<[12] Debug independent watchdog stopped when core is halted
           uint32_t   UNUSED3                                  :  8; //!<[13] 
      __IO ONE_BIT    DBG_I2C1_SMBUS_TIMEOUT                   :  1; //!<[21] SMBUS timeout mode stopped when core is halted
           uint32_t   UNUSED4                                  :  3; //!<[22] 
      __IO ONE_BIT    DBG_CAN_STOP                             :  1; //!<[25] CAN stopped when core is halted
    } B;
    __IO uint32_t  R;
    explicit APB1_FZ_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      APB1_FZ_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      APB1_FZ_DEF r; r.R = R;
      R = f (r);
    }
  };
  union APB2_FZ_DEF {  //!< Debug MCU APB2 freeze register
    struct {
           uint32_t   UNUSED0        : 11; //!<[00] 
      __IO ONE_BIT    DBG_TIM1_STOP  :  1; //!<[11] TIM1 counter stopped when core is halted
           uint32_t   UNUSED1        :  4; //!<[12] 
      __IO ONE_BIT    DBG_TIM15_STOP :  1; //!<[16] TIM15 counter stopped when core is halted
      __IO ONE_BIT    DBG_TIM16_STOP :  1; //!<[17] TIM16 counter stopped when core is halted
      __IO ONE_BIT    DBG_TIM17_STOP :  1; //!<[18] TIM17 counter stopped when core is halted
    } B;
    __IO uint32_t  R;
    explicit APB2_FZ_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      APB2_FZ_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      APB2_FZ_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL DBGMCU REGISTERS INSTANCES
  __I  IDCODE_DEF           IDCODE ;  //!< [0000](04)[0x00000000]
  __IO CR_DEF                   CR ;  //!< [0004](04)[0x00000000]
  __IO APB1_FZ_DEF         APB1_FZ ;  //!< [0008](04)[0x00000000]
  __IO APB2_FZ_DEF         APB2_FZ ;  //!< [000c](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x0010 */

// ////////////////////+++ USB +-+//////////////////// //
struct USB_Type         { /*!< Universal serial bus full-speed device interface */
  union EP0R_DEF    {  //!< endpoint 0 register
    struct {
      __IO uint32_t   EA      :  4; //!<[00] Endpoint address
      __IO uint32_t   STAT_TX :  2; //!<[04] Status bits, for transmission transfers
      __IO ONE_BIT    DTOG_TX :  1; //!<[06] Data Toggle, for transmission transfers
      __IO ONE_BIT    CTR_TX  :  1; //!<[07] Correct Transfer for transmission
      __IO ONE_BIT    EP_KIND :  1; //!<[08] Endpoint kind
      __IO uint32_t   EP_TYPE :  2; //!<[09] Endpoint type
      __IO ONE_BIT    SETUP   :  1; //!<[11] Setup transaction completed
      __IO uint32_t   STAT_RX :  2; //!<[12] Status bits, for reception transfers
      __IO ONE_BIT    DTOG_RX :  1; //!<[14] Data Toggle, for reception transfers
      __IO ONE_BIT    CTR_RX  :  1; //!<[15] Correct transfer for reception
    } B;
    __IO uint32_t  R;
    explicit EP0R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      EP0R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      EP0R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union EP1R_DEF    {  //!< endpoint 1 register
    struct {
      __IO uint32_t   EA      :  4; //!<[00] Endpoint address
      __IO uint32_t   STAT_TX :  2; //!<[04] Status bits, for transmission transfers
      __IO ONE_BIT    DTOG_TX :  1; //!<[06] Data Toggle, for transmission transfers
      __IO ONE_BIT    CTR_TX  :  1; //!<[07] Correct Transfer for transmission
      __IO ONE_BIT    EP_KIND :  1; //!<[08] Endpoint kind
      __IO uint32_t   EP_TYPE :  2; //!<[09] Endpoint type
      __IO ONE_BIT    SETUP   :  1; //!<[11] Setup transaction completed
      __IO uint32_t   STAT_RX :  2; //!<[12] Status bits, for reception transfers
      __IO ONE_BIT    DTOG_RX :  1; //!<[14] Data Toggle, for reception transfers
      __IO ONE_BIT    CTR_RX  :  1; //!<[15] Correct transfer for reception
    } B;
    __IO uint32_t  R;
    explicit EP1R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      EP1R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      EP1R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union EP2R_DEF    {  //!< endpoint 2 register
    struct {
      __IO uint32_t   EA      :  4; //!<[00] Endpoint address
      __IO uint32_t   STAT_TX :  2; //!<[04] Status bits, for transmission transfers
      __IO ONE_BIT    DTOG_TX :  1; //!<[06] Data Toggle, for transmission transfers
      __IO ONE_BIT    CTR_TX  :  1; //!<[07] Correct Transfer for transmission
      __IO ONE_BIT    EP_KIND :  1; //!<[08] Endpoint kind
      __IO uint32_t   EP_TYPE :  2; //!<[09] Endpoint type
      __IO ONE_BIT    SETUP   :  1; //!<[11] Setup transaction completed
      __IO uint32_t   STAT_RX :  2; //!<[12] Status bits, for reception transfers
      __IO ONE_BIT    DTOG_RX :  1; //!<[14] Data Toggle, for reception transfers
      __IO ONE_BIT    CTR_RX  :  1; //!<[15] Correct transfer for reception
    } B;
    __IO uint32_t  R;
    explicit EP2R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      EP2R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      EP2R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union EP3R_DEF    {  //!< endpoint 3 register
    struct {
      __IO uint32_t   EA      :  4; //!<[00] Endpoint address
      __IO uint32_t   STAT_TX :  2; //!<[04] Status bits, for transmission transfers
      __IO ONE_BIT    DTOG_TX :  1; //!<[06] Data Toggle, for transmission transfers
      __IO ONE_BIT    CTR_TX  :  1; //!<[07] Correct Transfer for transmission
      __IO ONE_BIT    EP_KIND :  1; //!<[08] Endpoint kind
      __IO uint32_t   EP_TYPE :  2; //!<[09] Endpoint type
      __IO ONE_BIT    SETUP   :  1; //!<[11] Setup transaction completed
      __IO uint32_t   STAT_RX :  2; //!<[12] Status bits, for reception transfers
      __IO ONE_BIT    DTOG_RX :  1; //!<[14] Data Toggle, for reception transfers
      __IO ONE_BIT    CTR_RX  :  1; //!<[15] Correct transfer for reception
    } B;
    __IO uint32_t  R;
    explicit EP3R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      EP3R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      EP3R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union EP4R_DEF    {  //!< endpoint 4 register
    struct {
      __IO uint32_t   EA      :  4; //!<[00] Endpoint address
      __IO uint32_t   STAT_TX :  2; //!<[04] Status bits, for transmission transfers
      __IO ONE_BIT    DTOG_TX :  1; //!<[06] Data Toggle, for transmission transfers
      __IO ONE_BIT    CTR_TX  :  1; //!<[07] Correct Transfer for transmission
      __IO ONE_BIT    EP_KIND :  1; //!<[08] Endpoint kind
      __IO uint32_t   EP_TYPE :  2; //!<[09] Endpoint type
      __IO ONE_BIT    SETUP   :  1; //!<[11] Setup transaction completed
      __IO uint32_t   STAT_RX :  2; //!<[12] Status bits, for reception transfers
      __IO ONE_BIT    DTOG_RX :  1; //!<[14] Data Toggle, for reception transfers
      __IO ONE_BIT    CTR_RX  :  1; //!<[15] Correct transfer for reception
    } B;
    __IO uint32_t  R;
    explicit EP4R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      EP4R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      EP4R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union EP5R_DEF    {  //!< endpoint 5 register
    struct {
      __IO uint32_t   EA      :  4; //!<[00] Endpoint address
      __IO uint32_t   STAT_TX :  2; //!<[04] Status bits, for transmission transfers
      __IO ONE_BIT    DTOG_TX :  1; //!<[06] Data Toggle, for transmission transfers
      __IO ONE_BIT    CTR_TX  :  1; //!<[07] Correct Transfer for transmission
      __IO ONE_BIT    EP_KIND :  1; //!<[08] Endpoint kind
      __IO uint32_t   EP_TYPE :  2; //!<[09] Endpoint type
      __IO ONE_BIT    SETUP   :  1; //!<[11] Setup transaction completed
      __IO uint32_t   STAT_RX :  2; //!<[12] Status bits, for reception transfers
      __IO ONE_BIT    DTOG_RX :  1; //!<[14] Data Toggle, for reception transfers
      __IO ONE_BIT    CTR_RX  :  1; //!<[15] Correct transfer for reception
    } B;
    __IO uint32_t  R;
    explicit EP5R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      EP5R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      EP5R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union EP6R_DEF    {  //!< endpoint 6 register
    struct {
      __IO uint32_t   EA      :  4; //!<[00] Endpoint address
      __IO uint32_t   STAT_TX :  2; //!<[04] Status bits, for transmission transfers
      __IO ONE_BIT    DTOG_TX :  1; //!<[06] Data Toggle, for transmission transfers
      __IO ONE_BIT    CTR_TX  :  1; //!<[07] Correct Transfer for transmission
      __IO ONE_BIT    EP_KIND :  1; //!<[08] Endpoint kind
      __IO uint32_t   EP_TYPE :  2; //!<[09] Endpoint type
      __IO ONE_BIT    SETUP   :  1; //!<[11] Setup transaction completed
      __IO uint32_t   STAT_RX :  2; //!<[12] Status bits, for reception transfers
      __IO ONE_BIT    DTOG_RX :  1; //!<[14] Data Toggle, for reception transfers
      __IO ONE_BIT    CTR_RX  :  1; //!<[15] Correct transfer for reception
    } B;
    __IO uint32_t  R;
    explicit EP6R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      EP6R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      EP6R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union EP7R_DEF    {  //!< endpoint 7 register
    struct {
      __IO uint32_t   EA      :  4; //!<[00] Endpoint address
      __IO uint32_t   STAT_TX :  2; //!<[04] Status bits, for transmission transfers
      __IO ONE_BIT    DTOG_TX :  1; //!<[06] Data Toggle, for transmission transfers
      __IO ONE_BIT    CTR_TX  :  1; //!<[07] Correct Transfer for transmission
      __IO ONE_BIT    EP_KIND :  1; //!<[08] Endpoint kind
      __IO uint32_t   EP_TYPE :  2; //!<[09] Endpoint type
      __IO ONE_BIT    SETUP   :  1; //!<[11] Setup transaction completed
      __IO uint32_t   STAT_RX :  2; //!<[12] Status bits, for reception transfers
      __IO ONE_BIT    DTOG_RX :  1; //!<[14] Data Toggle, for reception transfers
      __IO ONE_BIT    CTR_RX  :  1; //!<[15] Correct transfer for reception
    } B;
    __IO uint32_t  R;
    explicit EP7R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      EP7R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      EP7R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CNTR_DEF    {  //!< control register
    struct {
      __IO ONE_BIT  FRES     :  1; //!<[00] Force USB Reset
      __IO ONE_BIT  PDWN     :  1; //!<[01] Power down
      __IO ONE_BIT  LPMODE   :  1; //!<[02] Low-power mode
      __IO ONE_BIT  FSUSP    :  1; //!<[03] Force suspend
      __IO ONE_BIT  RESUME   :  1; //!<[04] Resume request
      __IO ONE_BIT  L1RESUME :  1; //!<[05] LPM L1 Resume request
           ONE_BIT  UNUSED0  :  1; //!<[06] 
      __IO ONE_BIT  L1REQM   :  1; //!<[07] LPM L1 state request interrupt mask
      __IO ONE_BIT  ESOFM    :  1; //!<[08] Expected start of frame interrupt mask
      __IO ONE_BIT  SOFM     :  1; //!<[09] Start of frame interrupt mask
      __IO ONE_BIT  RESETM   :  1; //!<[10] USB reset interrupt mask
      __IO ONE_BIT  SUSPM    :  1; //!<[11] Suspend mode interrupt mask
      __IO ONE_BIT  WKUPM    :  1; //!<[12] Wakeup interrupt mask
      __IO ONE_BIT  ERRM     :  1; //!<[13] Error interrupt mask
      __IO ONE_BIT  PMAOVRM  :  1; //!<[14] Packet memory area over / underrun interrupt mask
      __IO ONE_BIT  CTRM     :  1; //!<[15] Correct transfer interrupt mask
    } B;
    __IO uint32_t  R;
    explicit CNTR_DEF () noexcept { R = 0x00000003u; }
    template<typename F> void setbit (F f) volatile {
      CNTR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CNTR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ISTR_DEF    {  //!< interrupt status register
    struct {
      __I  uint32_t   EP_ID   :  4; //!<[00] Endpoint Identifier
      __I  ONE_BIT    DIR     :  1; //!<[04] Direction of transaction
           uint32_t   UNUSED0 :  2; //!<[05] 
      __IO ONE_BIT    L1REQ   :  1; //!<[07] LPM L1 state request
      __IO ONE_BIT    ESOF    :  1; //!<[08] Expected start frame
      __IO ONE_BIT    SOF     :  1; //!<[09] start of frame
      __IO ONE_BIT    RESET   :  1; //!<[10] reset request
      __IO ONE_BIT    SUSP    :  1; //!<[11] Suspend mode request
      __IO ONE_BIT    WKUP    :  1; //!<[12] Wakeup
      __IO ONE_BIT    ERR     :  1; //!<[13] Error
      __IO ONE_BIT    PMAOVR  :  1; //!<[14] Packet memory area over / underrun
      __I  ONE_BIT    CTR     :  1; //!<[15] Correct transfer
    } B;
    __IO uint32_t  R;
    explicit ISTR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ISTR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ISTR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union FNR_DEF     {  //!< frame number register
    struct {
      __I  uint32_t   FN   : 11; //!<[00] Frame number
      __I  uint32_t   LSOF :  2; //!<[11] Lost SOF
      __I  ONE_BIT    LCK  :  1; //!<[13] Locked
      __I  ONE_BIT    RXDM :  1; //!<[14] Receive data - line status
      __I  ONE_BIT    RXDP :  1; //!<[15] Receive data + line status
    } B;
    __I  uint32_t  R;

    explicit FNR_DEF (volatile FNR_DEF & o) noexcept { R = o.R; };
  };
  union DADDR_DEF   {  //!< device address
    struct {
      __IO uint32_t   ADD :  7; //!<[00] Device address
      __IO ONE_BIT    EF  :  1; //!<[07] Enable function
    } B;
    __IO uint32_t  R;
    explicit DADDR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DADDR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DADDR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union BTABLE_DEF  {  //!< Buffer table address
    struct {
           uint32_t   UNUSED0 :  3; //!<[00] 
      __IO uint32_t   BTABLE  : 13; //!<[03] Buffer table
    } B;
    __IO uint32_t  R;
    explicit BTABLE_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      BTABLE_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      BTABLE_DEF r; r.R = R;
      R = f (r);
    }
  };
  union LPMCSR_DEF  {  //!< LPM control and status register
    struct {
      __IO ONE_BIT    LPMEN   :  1; //!<[00] LPM support enable
      __IO ONE_BIT    LPMACK  :  1; //!<[01] LPM Token acknowledge enable
           ONE_BIT    UNUSED0 :  1; //!<[02] 
      __I  ONE_BIT    REMWAKE :  1; //!<[03] bRemoteWake value
      __I  uint32_t   BESL    :  4; //!<[04] BESL value
    } B;
    __IO uint32_t  R;
    explicit LPMCSR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      LPMCSR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      LPMCSR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union BCDR_DEF    {  //!< Battery charging detector
    struct {
      __IO ONE_BIT    BCDEN   :  1; //!<[00] Battery charging detector (BCD) enable
      __IO ONE_BIT    DCDEN   :  1; //!<[01] Data contact detection (DCD) mode enable
      __IO ONE_BIT    PDEN    :  1; //!<[02] Primary detection (PD) mode enable
      __IO ONE_BIT    SDEN    :  1; //!<[03] Secondary detection (SD) mode enable
      __I  ONE_BIT    DCDET   :  1; //!<[04] Data contact detection (DCD) status
      __I  ONE_BIT    PDET    :  1; //!<[05] Primary detection (PD) status
      __I  ONE_BIT    SDET    :  1; //!<[06] Secondary detection (SD) status
      __I  ONE_BIT    PS2DET  :  1; //!<[07] DM pull-up detection status
           uint32_t   UNUSED0 :  7; //!<[08] 
      __IO ONE_BIT    DPPU    :  1; //!<[15] DP pull-up control
    } B;
    __IO uint32_t  R;
    explicit BCDR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      BCDR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      BCDR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL USB REGISTERS INSTANCES
  __IO EP0R_DEF               EP0R ;  //!< [0000](04)[0x00000000]
  __IO EP1R_DEF               EP1R ;  //!< [0004](04)[0x00000000]
  __IO EP2R_DEF               EP2R ;  //!< [0008](04)[0x00000000]
  __IO EP3R_DEF               EP3R ;  //!< [000c](04)[0x00000000]
  __IO EP4R_DEF               EP4R ;  //!< [0010](04)[0x00000000]
  __IO EP5R_DEF               EP5R ;  //!< [0014](04)[0x00000000]
  __IO EP6R_DEF               EP6R ;  //!< [0018](04)[0x00000000]
  __IO EP7R_DEF               EP7R ;  //!< [001c](04)[0x00000000]
       uint32_t          UNUSED0 [8];  //!< [0020](20)[0xFFFFFFFF]
  __IO CNTR_DEF               CNTR ;  //!< [0040](04)[0x00000003]
  __IO ISTR_DEF               ISTR ;  //!< [0044](04)[0x00000000]
  __I  FNR_DEF                 FNR ;  //!< [0048](04)[0x00000000]
  __IO DADDR_DEF             DADDR ;  //!< [004c](04)[0x00000000]
  __IO BTABLE_DEF           BTABLE ;  //!< [0050](04)[0x00000000]
  __IO LPMCSR_DEF           LPMCSR ;  //!< [0054](04)[0x00000000]
  __IO BCDR_DEF               BCDR ;  //!< [0058](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x005C */

// ////////////////////+++ CRS +-+//////////////////// //
struct CRS_Type         { /*!< Clock recovery system */
  union CR_DEF   {  //!< control register
    struct {
      __IO ONE_BIT    SYNCOKIE   :  1; //!<[00] SYNC event OK interrupt enable
      __IO ONE_BIT    SYNCWARNIE :  1; //!<[01] SYNC warning interrupt enable
      __IO ONE_BIT    ERRIE      :  1; //!<[02] Synchronization or trimming error interrupt enable
      __IO ONE_BIT    ESYNCIE    :  1; //!<[03] Expected SYNC interrupt enable
           ONE_BIT    UNUSED0    :  1; //!<[04] 
      __IO ONE_BIT    CEN        :  1; //!<[05] Frequency error counter enable
      __IO ONE_BIT    AUTOTRIMEN :  1; //!<[06] Automatic trimming enable
      __IO ONE_BIT    SWSYNC     :  1; //!<[07] Generate software SYNC event
      __IO uint32_t   TRIM       :  6; //!<[08] HSI48 oscillator smooth trimming
    } B;
    __IO uint32_t  R;
    explicit CR_DEF () noexcept { R = 0x00002000u; }
    template<typename F> void setbit (F f) volatile {
      CR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CFGR_DEF {  //!< configuration register
    struct {
      __IO uint32_t   RELOAD  : 16; //!<[00] Counter reload value
      __IO uint32_t   FELIM   :  8; //!<[16] Frequency error limit
      __IO uint32_t   SYNCDIV :  3; //!<[24] SYNC divider
           ONE_BIT    UNUSED0 :  1; //!<[27] 
      __IO uint32_t   SYNCSRC :  2; //!<[28] SYNC signal source selection
           ONE_BIT    UNUSED1 :  1; //!<[30] 
      __IO ONE_BIT    SYNCPOL :  1; //!<[31] SYNC polarity selection
    } B;
    __IO uint32_t  R;
    explicit CFGR_DEF () noexcept { R = 0x2022bb7fu; }
    template<typename F> void setbit (F f) volatile {
      CFGR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CFGR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union ISR_DEF  {  //!< interrupt and status register
    struct {
      __I  ONE_BIT    SYNCOKF   :  1; //!<[00] SYNC event OK flag
      __I  ONE_BIT    SYNCWARNF :  1; //!<[01] SYNC warning flag
      __I  ONE_BIT    ERRF      :  1; //!<[02] Error flag
      __I  ONE_BIT    ESYNCF    :  1; //!<[03] Expected SYNC flag
           uint32_t   UNUSED0   :  4; //!<[04] 
      __I  ONE_BIT    SYNCERR   :  1; //!<[08] SYNC error
      __I  ONE_BIT    SYNCMISS  :  1; //!<[09] SYNC missed
      __I  ONE_BIT    TRIMOVF   :  1; //!<[10] Trimming overflow or underflow
           uint32_t   UNUSED1   :  4; //!<[11] 
      __I  ONE_BIT    FEDIR     :  1; //!<[15] Frequency error direction
      __I  uint32_t   FECAP     : 16; //!<[16] Frequency error capture
    } B;
    __I  uint32_t  R;

    explicit ISR_DEF (volatile ISR_DEF & o) noexcept { R = o.R; };
  };
  union ICR_DEF  {  //!< interrupt flag clear register
    struct {
      __IO ONE_BIT  SYNCOKC   :  1; //!<[00] SYNC event OK clear flag
      __IO ONE_BIT  SYNCWARNC :  1; //!<[01] SYNC warning clear flag
      __IO ONE_BIT  ERRC      :  1; //!<[02] Error clear flag
      __IO ONE_BIT  ESYNCC    :  1; //!<[03] Expected SYNC clear flag
    } B;
    __IO uint32_t  R;
    explicit ICR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ICR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ICR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL CRS REGISTERS INSTANCES
  __IO CR_DEF                CR ;  //!< [0000](04)[0x00002000]
  __IO CFGR_DEF            CFGR ;  //!< [0004](04)[0x2022BB7F]
  __I  ISR_DEF              ISR ;  //!< [0008](04)[0x00000000]
  __IO ICR_DEF              ICR ;  //!< [000c](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x0010 */

// ////////////////////+++ CAN +-+//////////////////// //
struct CAN_Type         { /*!< Controller area network */
  union CAN_MCR_DEF   {  //!< CAN_MCR
    struct {
      __IO ONE_BIT    INRQ    :  1; //!<[00] INRQ
      __IO ONE_BIT    SLEEP   :  1; //!<[01] SLEEP
      __IO ONE_BIT    TXFP    :  1; //!<[02] TXFP
      __IO ONE_BIT    RFLM    :  1; //!<[03] RFLM
      __IO ONE_BIT    NART    :  1; //!<[04] NART
      __IO ONE_BIT    AWUM    :  1; //!<[05] AWUM
      __IO ONE_BIT    ABOM    :  1; //!<[06] ABOM
      __IO ONE_BIT    TTCM    :  1; //!<[07] TTCM
           uint32_t   UNUSED0 :  7; //!<[08] 
      __IO ONE_BIT    RESET   :  1; //!<[15] RESET
      __IO ONE_BIT    DBF     :  1; //!<[16] DBF
    } B;
    __IO uint32_t  R;
    explicit CAN_MCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_MCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_MCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_MSR_DEF   {  //!< CAN_MSR
    struct {
      __I  ONE_BIT    INAK    :  1; //!<[00] INAK
      __I  ONE_BIT    SLAK    :  1; //!<[01] SLAK
      __IO ONE_BIT    ERRI    :  1; //!<[02] ERRI
      __IO ONE_BIT    WKUI    :  1; //!<[03] WKUI
      __IO ONE_BIT    SLAKI   :  1; //!<[04] SLAKI
           uint32_t   UNUSED0 :  3; //!<[05] 
      __I  ONE_BIT    TXM     :  1; //!<[08] TXM
      __I  ONE_BIT    RXM     :  1; //!<[09] RXM
      __I  ONE_BIT    SAMP    :  1; //!<[10] SAMP
      __I  ONE_BIT    RX      :  1; //!<[11] RX
    } B;
    __IO uint32_t  R;
    explicit CAN_MSR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_MSR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_MSR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_TSR_DEF   {  //!< CAN_TSR
    struct {
      __IO ONE_BIT    RQCP0   :  1; //!<[00] RQCP0
      __IO ONE_BIT    TXOK0   :  1; //!<[01] TXOK0
      __IO ONE_BIT    ALST0   :  1; //!<[02] ALST0
      __IO ONE_BIT    TERR0   :  1; //!<[03] TERR0
           uint32_t   UNUSED0 :  3; //!<[04] 
      __IO ONE_BIT    ABRQ0   :  1; //!<[07] ABRQ0
      __IO ONE_BIT    RQCP1   :  1; //!<[08] RQCP1
      __IO ONE_BIT    TXOK1   :  1; //!<[09] TXOK1
      __IO ONE_BIT    ALST1   :  1; //!<[10] ALST1
      __IO ONE_BIT    TERR1   :  1; //!<[11] TERR1
           uint32_t   UNUSED1 :  3; //!<[12] 
      __IO ONE_BIT    ABRQ1   :  1; //!<[15] ABRQ1
      __IO ONE_BIT    RQCP2   :  1; //!<[16] RQCP2
      __IO ONE_BIT    TXOK2   :  1; //!<[17] TXOK2
      __IO ONE_BIT    ALST2   :  1; //!<[18] ALST2
      __IO ONE_BIT    TERR2   :  1; //!<[19] TERR2
           uint32_t   UNUSED2 :  3; //!<[20] 
      __IO ONE_BIT    ABRQ2   :  1; //!<[23] ABRQ2
      __I  uint32_t   CODE    :  2; //!<[24] CODE
      __I  ONE_BIT    TME0    :  1; //!<[26] Lowest priority flag for mailbox 0
      __I  ONE_BIT    TME1    :  1; //!<[27] Lowest priority flag for mailbox 1
      __I  ONE_BIT    TME2    :  1; //!<[28] Lowest priority flag for mailbox 2
      __I  ONE_BIT    LOW0    :  1; //!<[29] Lowest priority flag for mailbox 0
      __I  ONE_BIT    LOW1    :  1; //!<[30] Lowest priority flag for mailbox 1
      __I  ONE_BIT    LOW2    :  1; //!<[31] Lowest priority flag for mailbox 2
    } B;
    __IO uint32_t  R;
    explicit CAN_TSR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_TSR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_TSR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_RF0R_DEF  {  //!< CAN_RF0R
    struct {
      __I  uint32_t   FMP0    :  2; //!<[00] FMP0
           ONE_BIT    UNUSED0 :  1; //!<[02] 
      __IO ONE_BIT    FULL0   :  1; //!<[03] FULL0
      __IO ONE_BIT    FOVR0   :  1; //!<[04] FOVR0
      __IO ONE_BIT    RFOM0   :  1; //!<[05] RFOM0
    } B;
    __IO uint32_t  R;
    explicit CAN_RF0R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_RF0R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_RF0R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_RF1R_DEF  {  //!< CAN_RF1R
    struct {
      __I  uint32_t   FMP1    :  2; //!<[00] FMP1
           ONE_BIT    UNUSED0 :  1; //!<[02] 
      __IO ONE_BIT    FULL1   :  1; //!<[03] FULL1
      __IO ONE_BIT    FOVR1   :  1; //!<[04] FOVR1
      __IO ONE_BIT    RFOM1   :  1; //!<[05] RFOM1
    } B;
    __IO uint32_t  R;
    explicit CAN_RF1R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_RF1R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_RF1R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_IER_DEF   {  //!< CAN_IER
    struct {
      __IO ONE_BIT    TMEIE   :  1; //!<[00] TMEIE
      __IO ONE_BIT    FMPIE0  :  1; //!<[01] FMPIE0
      __IO ONE_BIT    FFIE0   :  1; //!<[02] FFIE0
      __IO ONE_BIT    FOVIE0  :  1; //!<[03] FOVIE0
      __IO ONE_BIT    FMPIE1  :  1; //!<[04] FMPIE1
      __IO ONE_BIT    FFIE1   :  1; //!<[05] FFIE1
      __IO ONE_BIT    FOVIE1  :  1; //!<[06] FOVIE1
           ONE_BIT    UNUSED0 :  1; //!<[07] 
      __IO ONE_BIT    EWGIE   :  1; //!<[08] EWGIE
      __IO ONE_BIT    EPVIE   :  1; //!<[09] EPVIE
      __IO ONE_BIT    BOFIE   :  1; //!<[10] BOFIE
      __IO ONE_BIT    LECIE   :  1; //!<[11] LECIE
           uint32_t   UNUSED1 :  3; //!<[12] 
      __IO ONE_BIT    ERRIE   :  1; //!<[15] ERRIE
      __IO ONE_BIT    WKUIE   :  1; //!<[16] WKUIE
      __IO ONE_BIT    SLKIE   :  1; //!<[17] SLKIE
    } B;
    __IO uint32_t  R;
    explicit CAN_IER_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_IER_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_IER_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_ESR_DEF   {  //!< CAN_ESR
    struct {
      __I  ONE_BIT    EWGF    :  1; //!<[00] EWGF
      __I  ONE_BIT    EPVF    :  1; //!<[01] EPVF
      __I  ONE_BIT    BOFF    :  1; //!<[02] BOFF
           ONE_BIT    UNUSED0 :  1; //!<[03] 
      __IO uint32_t   LEC     :  3; //!<[04] LEC
           uint32_t   UNUSED1 :  9; //!<[07] 
      __I  uint32_t   TEC     :  8; //!<[16] TEC
      __I  uint32_t   REC     :  8; //!<[24] REC
    } B;
    __IO uint32_t  R;
    explicit CAN_ESR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_ESR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_ESR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_BTR_DEF   {  //!< CAN BTR
    struct {
      __IO uint32_t   BRP     : 10; //!<[00] BRP
           uint32_t   UNUSED0 :  6; //!<[10] 
      __IO uint32_t   TS1     :  4; //!<[16] TS1
      __IO uint32_t   TS2     :  3; //!<[20] TS2
           ONE_BIT    UNUSED1 :  1; //!<[23] 
      __IO uint32_t   SJW     :  2; //!<[24] SJW
           uint32_t   UNUSED2 :  4; //!<[26] 
      __IO ONE_BIT    LBKM    :  1; //!<[30] LBKM
      __IO ONE_BIT    SILM    :  1; //!<[31] SILM
    } B;
    __IO uint32_t  R;
    explicit CAN_BTR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_BTR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_BTR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_TI0R_DEF  {  //!< CAN_TI0R
    struct {
      __IO ONE_BIT    TXRQ :  1; //!<[00] TXRQ
      __IO ONE_BIT    RTR  :  1; //!<[01] RTR
      __IO ONE_BIT    IDE  :  1; //!<[02] IDE
      __IO uint32_t   EXID : 18; //!<[03] EXID
      __IO uint32_t   STID : 11; //!<[21] STID
    } B;
    __IO uint32_t  R;
    explicit CAN_TI0R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_TI0R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_TI0R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_TDT0R_DEF {  //!< CAN_TDT0R
    struct {
      __IO uint32_t   DLC     :  4; //!<[00] DLC
           uint32_t   UNUSED0 :  4; //!<[04] 
      __IO ONE_BIT    TGT     :  1; //!<[08] TGT
           uint32_t   UNUSED1 :  7; //!<[09] 
      __IO uint32_t   TIME    : 16; //!<[16] TIME
    } B;
    __IO uint32_t  R;
    explicit CAN_TDT0R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_TDT0R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_TDT0R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_TDL0R_DEF {  //!< CAN_TDL0R
    struct {
      __IO uint32_t   DATA0 :  8; //!<[00] DATA0
      __IO uint32_t   DATA1 :  8; //!<[08] DATA1
      __IO uint32_t   DATA2 :  8; //!<[16] DATA2
      __IO uint32_t   DATA3 :  8; //!<[24] DATA3
    } B;
    __IO uint32_t  R;
    explicit CAN_TDL0R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_TDL0R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_TDL0R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_TDH0R_DEF {  //!< CAN_TDH0R
    struct {
      __IO uint32_t   DATA4 :  8; //!<[00] DATA4
      __IO uint32_t   DATA5 :  8; //!<[08] DATA5
      __IO uint32_t   DATA6 :  8; //!<[16] DATA6
      __IO uint32_t   DATA7 :  8; //!<[24] DATA7
    } B;
    __IO uint32_t  R;
    explicit CAN_TDH0R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_TDH0R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_TDH0R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_TI1R_DEF  {  //!< CAN_TI1R
    struct {
      __IO ONE_BIT    TXRQ :  1; //!<[00] TXRQ
      __IO ONE_BIT    RTR  :  1; //!<[01] RTR
      __IO ONE_BIT    IDE  :  1; //!<[02] IDE
      __IO uint32_t   EXID : 18; //!<[03] EXID
      __IO uint32_t   STID : 11; //!<[21] STID
    } B;
    __IO uint32_t  R;
    explicit CAN_TI1R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_TI1R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_TI1R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_TDT1R_DEF {  //!< CAN_TDT1R
    struct {
      __IO uint32_t   DLC     :  4; //!<[00] DLC
           uint32_t   UNUSED0 :  4; //!<[04] 
      __IO ONE_BIT    TGT     :  1; //!<[08] TGT
           uint32_t   UNUSED1 :  7; //!<[09] 
      __IO uint32_t   TIME    : 16; //!<[16] TIME
    } B;
    __IO uint32_t  R;
    explicit CAN_TDT1R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_TDT1R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_TDT1R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_TDL1R_DEF {  //!< CAN_TDL1R
    struct {
      __IO uint32_t   DATA0 :  8; //!<[00] DATA0
      __IO uint32_t   DATA1 :  8; //!<[08] DATA1
      __IO uint32_t   DATA2 :  8; //!<[16] DATA2
      __IO uint32_t   DATA3 :  8; //!<[24] DATA3
    } B;
    __IO uint32_t  R;
    explicit CAN_TDL1R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_TDL1R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_TDL1R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_TDH1R_DEF {  //!< CAN_TDH1R
    struct {
      __IO uint32_t   DATA4 :  8; //!<[00] DATA4
      __IO uint32_t   DATA5 :  8; //!<[08] DATA5
      __IO uint32_t   DATA6 :  8; //!<[16] DATA6
      __IO uint32_t   DATA7 :  8; //!<[24] DATA7
    } B;
    __IO uint32_t  R;
    explicit CAN_TDH1R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_TDH1R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_TDH1R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_TI2R_DEF  {  //!< CAN_TI2R
    struct {
      __IO ONE_BIT    TXRQ :  1; //!<[00] TXRQ
      __IO ONE_BIT    RTR  :  1; //!<[01] RTR
      __IO ONE_BIT    IDE  :  1; //!<[02] IDE
      __IO uint32_t   EXID : 18; //!<[03] EXID
      __IO uint32_t   STID : 11; //!<[21] STID
    } B;
    __IO uint32_t  R;
    explicit CAN_TI2R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_TI2R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_TI2R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_TDT2R_DEF {  //!< CAN_TDT2R
    struct {
      __IO uint32_t   DLC     :  4; //!<[00] DLC
           uint32_t   UNUSED0 :  4; //!<[04] 
      __IO ONE_BIT    TGT     :  1; //!<[08] TGT
           uint32_t   UNUSED1 :  7; //!<[09] 
      __IO uint32_t   TIME    : 16; //!<[16] TIME
    } B;
    __IO uint32_t  R;
    explicit CAN_TDT2R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_TDT2R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_TDT2R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_TDL2R_DEF {  //!< CAN_TDL2R
    struct {
      __IO uint32_t   DATA0 :  8; //!<[00] DATA0
      __IO uint32_t   DATA1 :  8; //!<[08] DATA1
      __IO uint32_t   DATA2 :  8; //!<[16] DATA2
      __IO uint32_t   DATA3 :  8; //!<[24] DATA3
    } B;
    __IO uint32_t  R;
    explicit CAN_TDL2R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_TDL2R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_TDL2R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_TDH2R_DEF {  //!< CAN_TDH2R
    struct {
      __IO uint32_t   DATA4 :  8; //!<[00] DATA4
      __IO uint32_t   DATA5 :  8; //!<[08] DATA5
      __IO uint32_t   DATA6 :  8; //!<[16] DATA6
      __IO uint32_t   DATA7 :  8; //!<[24] DATA7
    } B;
    __IO uint32_t  R;
    explicit CAN_TDH2R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_TDH2R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_TDH2R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_RI0R_DEF  {  //!< CAN_RI0R
    struct {
           ONE_BIT    UNUSED0 :  1; //!<[00] 
      __I  ONE_BIT    RTR     :  1; //!<[01] RTR
      __I  ONE_BIT    IDE     :  1; //!<[02] IDE
      __I  uint32_t   EXID    : 18; //!<[03] EXID
      __I  uint32_t   STID    : 11; //!<[21] STID
    } B;
    __I  uint32_t  R;

    explicit CAN_RI0R_DEF (volatile CAN_RI0R_DEF & o) noexcept { R = o.R; };
  };
  union CAN_RDT0R_DEF {  //!< CAN_RDT0R
    struct {
      __I  uint32_t   DLC     :  4; //!<[00] DLC
           uint32_t   UNUSED0 :  4; //!<[04] 
      __I  uint32_t   FMI     :  8; //!<[08] FMI
      __I  uint32_t   TIME    : 16; //!<[16] TIME
    } B;
    __I  uint32_t  R;

    explicit CAN_RDT0R_DEF (volatile CAN_RDT0R_DEF & o) noexcept { R = o.R; };
  };
  union CAN_RDL0R_DEF {  //!< CAN_RDL0R
    struct {
      __I  uint32_t   DATA0 :  8; //!<[00] DATA0
      __I  uint32_t   DATA1 :  8; //!<[08] DATA1
      __I  uint32_t   DATA2 :  8; //!<[16] DATA2
      __I  uint32_t   DATA3 :  8; //!<[24] DATA3
    } B;
    __I  uint32_t  R;

    explicit CAN_RDL0R_DEF (volatile CAN_RDL0R_DEF & o) noexcept { R = o.R; };
  };
  union CAN_RDH0R_DEF {  //!< CAN_RDH0R
    struct {
      __I  uint32_t   DATA4 :  8; //!<[00] DATA4
      __I  uint32_t   DATA5 :  8; //!<[08] DATA5
      __I  uint32_t   DATA6 :  8; //!<[16] DATA6
      __I  uint32_t   DATA7 :  8; //!<[24] DATA7
    } B;
    __I  uint32_t  R;

    explicit CAN_RDH0R_DEF (volatile CAN_RDH0R_DEF & o) noexcept { R = o.R; };
  };
  union CAN_RI1R_DEF  {  //!< CAN_RI1R
    struct {
           ONE_BIT    UNUSED0 :  1; //!<[00] 
      __I  ONE_BIT    RTR     :  1; //!<[01] RTR
      __I  ONE_BIT    IDE     :  1; //!<[02] IDE
      __I  uint32_t   EXID    : 18; //!<[03] EXID
      __I  uint32_t   STID    : 11; //!<[21] STID
    } B;
    __I  uint32_t  R;

    explicit CAN_RI1R_DEF (volatile CAN_RI1R_DEF & o) noexcept { R = o.R; };
  };
  union CAN_RDT1R_DEF {  //!< CAN_RDT1R
    struct {
      __I  uint32_t   DLC     :  4; //!<[00] DLC
           uint32_t   UNUSED0 :  4; //!<[04] 
      __I  uint32_t   FMI     :  8; //!<[08] FMI
      __I  uint32_t   TIME    : 16; //!<[16] TIME
    } B;
    __I  uint32_t  R;

    explicit CAN_RDT1R_DEF (volatile CAN_RDT1R_DEF & o) noexcept { R = o.R; };
  };
  union CAN_RDL1R_DEF {  //!< CAN_RDL1R
    struct {
      __I  uint32_t   DATA0 :  8; //!<[00] DATA0
      __I  uint32_t   DATA1 :  8; //!<[08] DATA1
      __I  uint32_t   DATA2 :  8; //!<[16] DATA2
      __I  uint32_t   DATA3 :  8; //!<[24] DATA3
    } B;
    __I  uint32_t  R;

    explicit CAN_RDL1R_DEF (volatile CAN_RDL1R_DEF & o) noexcept { R = o.R; };
  };
  union CAN_RDH1R_DEF {  //!< CAN_RDH1R
    struct {
      __I  uint32_t   DATA4 :  8; //!<[00] DATA4
      __I  uint32_t   DATA5 :  8; //!<[08] DATA5
      __I  uint32_t   DATA6 :  8; //!<[16] DATA6
      __I  uint32_t   DATA7 :  8; //!<[24] DATA7
    } B;
    __I  uint32_t  R;

    explicit CAN_RDH1R_DEF (volatile CAN_RDH1R_DEF & o) noexcept { R = o.R; };
  };
  union CAN_FMR_DEF   {  //!< CAN_FMR
    struct {
      __IO ONE_BIT    FINIT   :  1; //!<[00] FINIT
           uint32_t   UNUSED0 :  7; //!<[01] 
      __IO uint32_t   CAN2SB  :  6; //!<[08] CAN2SB
    } B;
    __IO uint32_t  R;
    explicit CAN_FMR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_FMR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_FMR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_FM1R_DEF  {  //!< CAN_FM1R
    struct {
      __IO ONE_BIT  FBM0  :  1; //!<[00] Filter mode
      __IO ONE_BIT  FBM1  :  1; //!<[01] Filter mode
      __IO ONE_BIT  FBM2  :  1; //!<[02] Filter mode
      __IO ONE_BIT  FBM3  :  1; //!<[03] Filter mode
      __IO ONE_BIT  FBM4  :  1; //!<[04] Filter mode
      __IO ONE_BIT  FBM5  :  1; //!<[05] Filter mode
      __IO ONE_BIT  FBM6  :  1; //!<[06] Filter mode
      __IO ONE_BIT  FBM7  :  1; //!<[07] Filter mode
      __IO ONE_BIT  FBM8  :  1; //!<[08] Filter mode
      __IO ONE_BIT  FBM9  :  1; //!<[09] Filter mode
      __IO ONE_BIT  FBM10 :  1; //!<[10] Filter mode
      __IO ONE_BIT  FBM11 :  1; //!<[11] Filter mode
      __IO ONE_BIT  FBM12 :  1; //!<[12] Filter mode
      __IO ONE_BIT  FBM13 :  1; //!<[13] Filter mode
      __IO ONE_BIT  FBM14 :  1; //!<[14] Filter mode
      __IO ONE_BIT  FBM15 :  1; //!<[15] Filter mode
      __IO ONE_BIT  FBM16 :  1; //!<[16] Filter mode
      __IO ONE_BIT  FBM17 :  1; //!<[17] Filter mode
      __IO ONE_BIT  FBM18 :  1; //!<[18] Filter mode
      __IO ONE_BIT  FBM19 :  1; //!<[19] Filter mode
      __IO ONE_BIT  FBM20 :  1; //!<[20] Filter mode
      __IO ONE_BIT  FBM21 :  1; //!<[21] Filter mode
      __IO ONE_BIT  FBM22 :  1; //!<[22] Filter mode
      __IO ONE_BIT  FBM23 :  1; //!<[23] Filter mode
      __IO ONE_BIT  FBM24 :  1; //!<[24] Filter mode
      __IO ONE_BIT  FBM25 :  1; //!<[25] Filter mode
      __IO ONE_BIT  FBM26 :  1; //!<[26] Filter mode
      __IO ONE_BIT  FBM27 :  1; //!<[27] Filter mode
    } B;
    __IO uint32_t  R;
    explicit CAN_FM1R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_FM1R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_FM1R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_FS1R_DEF  {  //!< CAN_FS1R
    struct {
      __IO ONE_BIT  FSC0  :  1; //!<[00] Filter scale configuration
      __IO ONE_BIT  FSC1  :  1; //!<[01] Filter scale configuration
      __IO ONE_BIT  FSC2  :  1; //!<[02] Filter scale configuration
      __IO ONE_BIT  FSC3  :  1; //!<[03] Filter scale configuration
      __IO ONE_BIT  FSC4  :  1; //!<[04] Filter scale configuration
      __IO ONE_BIT  FSC5  :  1; //!<[05] Filter scale configuration
      __IO ONE_BIT  FSC6  :  1; //!<[06] Filter scale configuration
      __IO ONE_BIT  FSC7  :  1; //!<[07] Filter scale configuration
      __IO ONE_BIT  FSC8  :  1; //!<[08] Filter scale configuration
      __IO ONE_BIT  FSC9  :  1; //!<[09] Filter scale configuration
      __IO ONE_BIT  FSC10 :  1; //!<[10] Filter scale configuration
      __IO ONE_BIT  FSC11 :  1; //!<[11] Filter scale configuration
      __IO ONE_BIT  FSC12 :  1; //!<[12] Filter scale configuration
      __IO ONE_BIT  FSC13 :  1; //!<[13] Filter scale configuration
      __IO ONE_BIT  FSC14 :  1; //!<[14] Filter scale configuration
      __IO ONE_BIT  FSC15 :  1; //!<[15] Filter scale configuration
      __IO ONE_BIT  FSC16 :  1; //!<[16] Filter scale configuration
      __IO ONE_BIT  FSC17 :  1; //!<[17] Filter scale configuration
      __IO ONE_BIT  FSC18 :  1; //!<[18] Filter scale configuration
      __IO ONE_BIT  FSC19 :  1; //!<[19] Filter scale configuration
      __IO ONE_BIT  FSC20 :  1; //!<[20] Filter scale configuration
      __IO ONE_BIT  FSC21 :  1; //!<[21] Filter scale configuration
      __IO ONE_BIT  FSC22 :  1; //!<[22] Filter scale configuration
      __IO ONE_BIT  FSC23 :  1; //!<[23] Filter scale configuration
      __IO ONE_BIT  FSC24 :  1; //!<[24] Filter scale configuration
      __IO ONE_BIT  FSC25 :  1; //!<[25] Filter scale configuration
      __IO ONE_BIT  FSC26 :  1; //!<[26] Filter scale configuration
      __IO ONE_BIT  FSC27 :  1; //!<[27] Filter scale configuration
    } B;
    __IO uint32_t  R;
    explicit CAN_FS1R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_FS1R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_FS1R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_FFA1R_DEF {  //!< CAN_FFA1R
    struct {
      __IO ONE_BIT  FFA0  :  1; //!<[00] Filter FIFO assignment for filter 0
      __IO ONE_BIT  FFA1  :  1; //!<[01] Filter FIFO assignment for filter 1
      __IO ONE_BIT  FFA2  :  1; //!<[02] Filter FIFO assignment for filter 2
      __IO ONE_BIT  FFA3  :  1; //!<[03] Filter FIFO assignment for filter 3
      __IO ONE_BIT  FFA4  :  1; //!<[04] Filter FIFO assignment for filter 4
      __IO ONE_BIT  FFA5  :  1; //!<[05] Filter FIFO assignment for filter 5
      __IO ONE_BIT  FFA6  :  1; //!<[06] Filter FIFO assignment for filter 6
      __IO ONE_BIT  FFA7  :  1; //!<[07] Filter FIFO assignment for filter 7
      __IO ONE_BIT  FFA8  :  1; //!<[08] Filter FIFO assignment for filter 8
      __IO ONE_BIT  FFA9  :  1; //!<[09] Filter FIFO assignment for filter 9
      __IO ONE_BIT  FFA10 :  1; //!<[10] Filter FIFO assignment for filter 10
      __IO ONE_BIT  FFA11 :  1; //!<[11] Filter FIFO assignment for filter 11
      __IO ONE_BIT  FFA12 :  1; //!<[12] Filter FIFO assignment for filter 12
      __IO ONE_BIT  FFA13 :  1; //!<[13] Filter FIFO assignment for filter 13
      __IO ONE_BIT  FFA14 :  1; //!<[14] Filter FIFO assignment for filter 14
      __IO ONE_BIT  FFA15 :  1; //!<[15] Filter FIFO assignment for filter 15
      __IO ONE_BIT  FFA16 :  1; //!<[16] Filter FIFO assignment for filter 16
      __IO ONE_BIT  FFA17 :  1; //!<[17] Filter FIFO assignment for filter 17
      __IO ONE_BIT  FFA18 :  1; //!<[18] Filter FIFO assignment for filter 18
      __IO ONE_BIT  FFA19 :  1; //!<[19] Filter FIFO assignment for filter 19
      __IO ONE_BIT  FFA20 :  1; //!<[20] Filter FIFO assignment for filter 20
      __IO ONE_BIT  FFA21 :  1; //!<[21] Filter FIFO assignment for filter 21
      __IO ONE_BIT  FFA22 :  1; //!<[22] Filter FIFO assignment for filter 22
      __IO ONE_BIT  FFA23 :  1; //!<[23] Filter FIFO assignment for filter 23
      __IO ONE_BIT  FFA24 :  1; //!<[24] Filter FIFO assignment for filter 24
      __IO ONE_BIT  FFA25 :  1; //!<[25] Filter FIFO assignment for filter 25
      __IO ONE_BIT  FFA26 :  1; //!<[26] Filter FIFO assignment for filter 26
      __IO ONE_BIT  FFA27 :  1; //!<[27] Filter FIFO assignment for filter 27
    } B;
    __IO uint32_t  R;
    explicit CAN_FFA1R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_FFA1R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_FFA1R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CAN_FA1R_DEF  {  //!< CAN_FA1R
    struct {
      __IO ONE_BIT  FACT0  :  1; //!<[00] Filter active
      __IO ONE_BIT  FACT1  :  1; //!<[01] Filter active
      __IO ONE_BIT  FACT2  :  1; //!<[02] Filter active
      __IO ONE_BIT  FACT3  :  1; //!<[03] Filter active
      __IO ONE_BIT  FACT4  :  1; //!<[04] Filter active
      __IO ONE_BIT  FACT5  :  1; //!<[05] Filter active
      __IO ONE_BIT  FACT6  :  1; //!<[06] Filter active
      __IO ONE_BIT  FACT7  :  1; //!<[07] Filter active
      __IO ONE_BIT  FACT8  :  1; //!<[08] Filter active
      __IO ONE_BIT  FACT9  :  1; //!<[09] Filter active
      __IO ONE_BIT  FACT10 :  1; //!<[10] Filter active
      __IO ONE_BIT  FACT11 :  1; //!<[11] Filter active
      __IO ONE_BIT  FACT12 :  1; //!<[12] Filter active
      __IO ONE_BIT  FACT13 :  1; //!<[13] Filter active
      __IO ONE_BIT  FACT14 :  1; //!<[14] Filter active
      __IO ONE_BIT  FACT15 :  1; //!<[15] Filter active
      __IO ONE_BIT  FACT16 :  1; //!<[16] Filter active
      __IO ONE_BIT  FACT17 :  1; //!<[17] Filter active
      __IO ONE_BIT  FACT18 :  1; //!<[18] Filter active
      __IO ONE_BIT  FACT19 :  1; //!<[19] Filter active
      __IO ONE_BIT  FACT20 :  1; //!<[20] Filter active
      __IO ONE_BIT  FACT21 :  1; //!<[21] Filter active
      __IO ONE_BIT  FACT22 :  1; //!<[22] Filter active
      __IO ONE_BIT  FACT23 :  1; //!<[23] Filter active
      __IO ONE_BIT  FACT24 :  1; //!<[24] Filter active
      __IO ONE_BIT  FACT25 :  1; //!<[25] Filter active
      __IO ONE_BIT  FACT26 :  1; //!<[26] Filter active
      __IO ONE_BIT  FACT27 :  1; //!<[27] Filter active
    } B;
    __IO uint32_t  R;
    explicit CAN_FA1R_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CAN_FA1R_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CAN_FA1R_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F0R1_DEF      {  //!< Filter bank 0 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F0R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F0R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F0R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F0R2_DEF      {  //!< Filter bank 0 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F0R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F0R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F0R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F1R1_DEF      {  //!< Filter bank 1 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F1R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F1R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F1R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F1R2_DEF      {  //!< Filter bank 1 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F1R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F1R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F1R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F2R1_DEF      {  //!< Filter bank 2 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F2R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F2R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F2R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F2R2_DEF      {  //!< Filter bank 2 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F2R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F2R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F2R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F3R1_DEF      {  //!< Filter bank 3 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F3R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F3R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F3R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F3R2_DEF      {  //!< Filter bank 3 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F3R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F3R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F3R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F4R1_DEF      {  //!< Filter bank 4 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F4R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F4R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F4R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F4R2_DEF      {  //!< Filter bank 4 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F4R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F4R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F4R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F5R1_DEF      {  //!< Filter bank 5 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F5R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F5R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F5R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F5R2_DEF      {  //!< Filter bank 5 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F5R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F5R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F5R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F6R1_DEF      {  //!< Filter bank 6 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F6R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F6R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F6R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F6R2_DEF      {  //!< Filter bank 6 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F6R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F6R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F6R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F7R1_DEF      {  //!< Filter bank 7 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F7R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F7R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F7R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F7R2_DEF      {  //!< Filter bank 7 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F7R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F7R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F7R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F8R1_DEF      {  //!< Filter bank 8 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F8R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F8R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F8R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F8R2_DEF      {  //!< Filter bank 8 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F8R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F8R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F8R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F9R1_DEF      {  //!< Filter bank 9 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F9R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F9R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F9R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F9R2_DEF      {  //!< Filter bank 9 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F9R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F9R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F9R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F10R1_DEF     {  //!< Filter bank 10 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F10R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F10R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F10R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F10R2_DEF     {  //!< Filter bank 10 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F10R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F10R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F10R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F11R1_DEF     {  //!< Filter bank 11 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F11R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F11R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F11R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F11R2_DEF     {  //!< Filter bank 11 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F11R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F11R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F11R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F12R1_DEF     {  //!< Filter bank 4 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F12R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F12R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F12R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F12R2_DEF     {  //!< Filter bank 12 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F12R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F12R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F12R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F13R1_DEF     {  //!< Filter bank 13 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F13R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F13R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F13R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F13R2_DEF     {  //!< Filter bank 13 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F13R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F13R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F13R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F14R1_DEF     {  //!< Filter bank 14 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F14R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F14R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F14R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F14R2_DEF     {  //!< Filter bank 14 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F14R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F14R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F14R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F15R1_DEF     {  //!< Filter bank 15 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F15R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F15R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F15R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F15R2_DEF     {  //!< Filter bank 15 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F15R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F15R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F15R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F16R1_DEF     {  //!< Filter bank 16 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F16R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F16R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F16R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F16R2_DEF     {  //!< Filter bank 16 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F16R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F16R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F16R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F17R1_DEF     {  //!< Filter bank 17 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F17R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F17R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F17R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F17R2_DEF     {  //!< Filter bank 17 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F17R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F17R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F17R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F18R1_DEF     {  //!< Filter bank 18 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F18R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F18R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F18R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F18R2_DEF     {  //!< Filter bank 18 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F18R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F18R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F18R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F19R1_DEF     {  //!< Filter bank 19 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F19R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F19R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F19R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F19R2_DEF     {  //!< Filter bank 19 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F19R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F19R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F19R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F20R1_DEF     {  //!< Filter bank 20 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F20R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F20R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F20R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F20R2_DEF     {  //!< Filter bank 20 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F20R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F20R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F20R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F21R1_DEF     {  //!< Filter bank 21 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F21R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F21R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F21R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F21R2_DEF     {  //!< Filter bank 21 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F21R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F21R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F21R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F22R1_DEF     {  //!< Filter bank 22 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F22R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F22R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F22R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F22R2_DEF     {  //!< Filter bank 22 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F22R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F22R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F22R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F23R1_DEF     {  //!< Filter bank 23 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F23R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F23R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F23R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F23R2_DEF     {  //!< Filter bank 23 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F23R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F23R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F23R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F24R1_DEF     {  //!< Filter bank 24 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F24R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F24R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F24R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F24R2_DEF     {  //!< Filter bank 24 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F24R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F24R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F24R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F25R1_DEF     {  //!< Filter bank 25 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F25R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F25R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F25R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F25R2_DEF     {  //!< Filter bank 25 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F25R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F25R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F25R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F26R1_DEF     {  //!< Filter bank 26 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F26R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F26R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F26R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F26R2_DEF     {  //!< Filter bank 26 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F26R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F26R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F26R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F27R1_DEF     {  //!< Filter bank 27 register 1
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F27R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F27R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F27R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union F27R2_DEF     {  //!< Filter bank 27 register 2
    struct {
      __IO ONE_BIT  FB0  :  1; //!<[00] Filter bits
      __IO ONE_BIT  FB1  :  1; //!<[01] Filter bits
      __IO ONE_BIT  FB2  :  1; //!<[02] Filter bits
      __IO ONE_BIT  FB3  :  1; //!<[03] Filter bits
      __IO ONE_BIT  FB4  :  1; //!<[04] Filter bits
      __IO ONE_BIT  FB5  :  1; //!<[05] Filter bits
      __IO ONE_BIT  FB6  :  1; //!<[06] Filter bits
      __IO ONE_BIT  FB7  :  1; //!<[07] Filter bits
      __IO ONE_BIT  FB8  :  1; //!<[08] Filter bits
      __IO ONE_BIT  FB9  :  1; //!<[09] Filter bits
      __IO ONE_BIT  FB10 :  1; //!<[10] Filter bits
      __IO ONE_BIT  FB11 :  1; //!<[11] Filter bits
      __IO ONE_BIT  FB12 :  1; //!<[12] Filter bits
      __IO ONE_BIT  FB13 :  1; //!<[13] Filter bits
      __IO ONE_BIT  FB14 :  1; //!<[14] Filter bits
      __IO ONE_BIT  FB15 :  1; //!<[15] Filter bits
      __IO ONE_BIT  FB16 :  1; //!<[16] Filter bits
      __IO ONE_BIT  FB17 :  1; //!<[17] Filter bits
      __IO ONE_BIT  FB18 :  1; //!<[18] Filter bits
      __IO ONE_BIT  FB19 :  1; //!<[19] Filter bits
      __IO ONE_BIT  FB20 :  1; //!<[20] Filter bits
      __IO ONE_BIT  FB21 :  1; //!<[21] Filter bits
      __IO ONE_BIT  FB22 :  1; //!<[22] Filter bits
      __IO ONE_BIT  FB23 :  1; //!<[23] Filter bits
      __IO ONE_BIT  FB24 :  1; //!<[24] Filter bits
      __IO ONE_BIT  FB25 :  1; //!<[25] Filter bits
      __IO ONE_BIT  FB26 :  1; //!<[26] Filter bits
      __IO ONE_BIT  FB27 :  1; //!<[27] Filter bits
      __IO ONE_BIT  FB28 :  1; //!<[28] Filter bits
      __IO ONE_BIT  FB29 :  1; //!<[29] Filter bits
      __IO ONE_BIT  FB30 :  1; //!<[30] Filter bits
      __IO ONE_BIT  FB31 :  1; //!<[31] Filter bits
    } B;
    __IO uint32_t  R;
    explicit F27R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      F27R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      F27R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL CAN REGISTERS INSTANCES
  __IO CAN_MCR_DEF           CAN_MCR ;  //!< [0000](04)[0x00000000]
  __IO CAN_MSR_DEF           CAN_MSR ;  //!< [0004](04)[0x00000000]
  __IO CAN_TSR_DEF           CAN_TSR ;  //!< [0008](04)[0x00000000]
  __IO CAN_RF0R_DEF         CAN_RF0R ;  //!< [000c](04)[0x00000000]
  __IO CAN_RF1R_DEF         CAN_RF1R ;  //!< [0010](04)[0x00000000]
  __IO CAN_IER_DEF           CAN_IER ;  //!< [0014](04)[0x00000000]
  __IO CAN_ESR_DEF           CAN_ESR ;  //!< [0018](04)[0x00000000]
  __IO CAN_BTR_DEF           CAN_BTR ;  //!< [001c](04)[0x00000000]
       uint32_t            UNUSED0 [88];  //!< [0020](160)[0xFFFFFFFF]
  __IO CAN_TI0R_DEF         CAN_TI0R ;  //!< [0180](04)[0x00000000]
  __IO CAN_TDT0R_DEF       CAN_TDT0R ;  //!< [0184](04)[0x00000000]
  __IO CAN_TDL0R_DEF       CAN_TDL0R ;  //!< [0188](04)[0x00000000]
  __IO CAN_TDH0R_DEF       CAN_TDH0R ;  //!< [018c](04)[0x00000000]
  __IO CAN_TI1R_DEF         CAN_TI1R ;  //!< [0190](04)[0x00000000]
  __IO CAN_TDT1R_DEF       CAN_TDT1R ;  //!< [0194](04)[0x00000000]
  __IO CAN_TDL1R_DEF       CAN_TDL1R ;  //!< [0198](04)[0x00000000]
  __IO CAN_TDH1R_DEF       CAN_TDH1R ;  //!< [019c](04)[0x00000000]
  __IO CAN_TI2R_DEF         CAN_TI2R ;  //!< [01a0](04)[0x00000000]
  __IO CAN_TDT2R_DEF       CAN_TDT2R ;  //!< [01a4](04)[0x00000000]
  __IO CAN_TDL2R_DEF       CAN_TDL2R ;  //!< [01a8](04)[0x00000000]
  __IO CAN_TDH2R_DEF       CAN_TDH2R ;  //!< [01ac](04)[0x00000000]
  __I  CAN_RI0R_DEF         CAN_RI0R ;  //!< [01b0](04)[0x00000000]
  __I  CAN_RDT0R_DEF       CAN_RDT0R ;  //!< [01b4](04)[0x00000000]
  __I  CAN_RDL0R_DEF       CAN_RDL0R ;  //!< [01b8](04)[0x00000000]
  __I  CAN_RDH0R_DEF       CAN_RDH0R ;  //!< [01bc](04)[0x00000000]
  __I  CAN_RI1R_DEF         CAN_RI1R ;  //!< [01c0](04)[0x00000000]
  __I  CAN_RDT1R_DEF       CAN_RDT1R ;  //!< [01c4](04)[0x00000000]
  __I  CAN_RDL1R_DEF       CAN_RDL1R ;  //!< [01c8](04)[0x00000000]
  __I  CAN_RDH1R_DEF       CAN_RDH1R ;  //!< [01cc](04)[0x00000000]
       uint32_t            UNUSED1 [12];  //!< [01d0](30)[0xFFFFFFFF]
  __IO CAN_FMR_DEF           CAN_FMR ;  //!< [0200](04)[0x00000000]
  __IO CAN_FM1R_DEF         CAN_FM1R ;  //!< [0204](04)[0x00000000]
       uint32_t            UNUSED2 ;  //!< [0208](04)[0xFFFFFFFF]
  __IO CAN_FS1R_DEF         CAN_FS1R ;  //!< [020c](04)[0x00000000]
       uint32_t            UNUSED3 ;  //!< [0210](04)[0xFFFFFFFF]
  __IO CAN_FFA1R_DEF       CAN_FFA1R ;  //!< [0214](04)[0x00000000]
       uint32_t            UNUSED4 ;  //!< [0218](04)[0xFFFFFFFF]
  __IO CAN_FA1R_DEF         CAN_FA1R ;  //!< [021c](04)[0x00000000]
       uint32_t            UNUSED5 [8];  //!< [0220](20)[0xFFFFFFFF]
  __IO F0R1_DEF                 F0R1 ;  //!< [0240](04)[0x00000000]
  __IO F0R2_DEF                 F0R2 ;  //!< [0244](04)[0x00000000]
  __IO F1R1_DEF                 F1R1 ;  //!< [0248](04)[0x00000000]
  __IO F1R2_DEF                 F1R2 ;  //!< [024c](04)[0x00000000]
  __IO F2R1_DEF                 F2R1 ;  //!< [0250](04)[0x00000000]
  __IO F2R2_DEF                 F2R2 ;  //!< [0254](04)[0x00000000]
  __IO F3R1_DEF                 F3R1 ;  //!< [0258](04)[0x00000000]
  __IO F3R2_DEF                 F3R2 ;  //!< [025c](04)[0x00000000]
  __IO F4R1_DEF                 F4R1 ;  //!< [0260](04)[0x00000000]
  __IO F4R2_DEF                 F4R2 ;  //!< [0264](04)[0x00000000]
  __IO F5R1_DEF                 F5R1 ;  //!< [0268](04)[0x00000000]
  __IO F5R2_DEF                 F5R2 ;  //!< [026c](04)[0x00000000]
  __IO F6R1_DEF                 F6R1 ;  //!< [0270](04)[0x00000000]
  __IO F6R2_DEF                 F6R2 ;  //!< [0274](04)[0x00000000]
  __IO F7R1_DEF                 F7R1 ;  //!< [0278](04)[0x00000000]
  __IO F7R2_DEF                 F7R2 ;  //!< [027c](04)[0x00000000]
  __IO F8R1_DEF                 F8R1 ;  //!< [0280](04)[0x00000000]
  __IO F8R2_DEF                 F8R2 ;  //!< [0284](04)[0x00000000]
  __IO F9R1_DEF                 F9R1 ;  //!< [0288](04)[0x00000000]
  __IO F9R2_DEF                 F9R2 ;  //!< [028c](04)[0x00000000]
  __IO F10R1_DEF               F10R1 ;  //!< [0290](04)[0x00000000]
  __IO F10R2_DEF               F10R2 ;  //!< [0294](04)[0x00000000]
  __IO F11R1_DEF               F11R1 ;  //!< [0298](04)[0x00000000]
  __IO F11R2_DEF               F11R2 ;  //!< [029c](04)[0x00000000]
  __IO F12R1_DEF               F12R1 ;  //!< [02a0](04)[0x00000000]
  __IO F12R2_DEF               F12R2 ;  //!< [02a4](04)[0x00000000]
  __IO F13R1_DEF               F13R1 ;  //!< [02a8](04)[0x00000000]
  __IO F13R2_DEF               F13R2 ;  //!< [02ac](04)[0x00000000]
  __IO F14R1_DEF               F14R1 ;  //!< [02b0](04)[0x00000000]
  __IO F14R2_DEF               F14R2 ;  //!< [02b4](04)[0x00000000]
  __IO F15R1_DEF               F15R1 ;  //!< [02b8](04)[0x00000000]
  __IO F15R2_DEF               F15R2 ;  //!< [02bc](04)[0x00000000]
  __IO F16R1_DEF               F16R1 ;  //!< [02c0](04)[0x00000000]
  __IO F16R2_DEF               F16R2 ;  //!< [02c4](04)[0x00000000]
  __IO F17R1_DEF               F17R1 ;  //!< [02c8](04)[0x00000000]
  __IO F17R2_DEF               F17R2 ;  //!< [02cc](04)[0x00000000]
  __IO F18R1_DEF               F18R1 ;  //!< [02d0](04)[0x00000000]
  __IO F18R2_DEF               F18R2 ;  //!< [02d4](04)[0x00000000]
  __IO F19R1_DEF               F19R1 ;  //!< [02d8](04)[0x00000000]
  __IO F19R2_DEF               F19R2 ;  //!< [02dc](04)[0x00000000]
  __IO F20R1_DEF               F20R1 ;  //!< [02e0](04)[0x00000000]
  __IO F20R2_DEF               F20R2 ;  //!< [02e4](04)[0x00000000]
  __IO F21R1_DEF               F21R1 ;  //!< [02e8](04)[0x00000000]
  __IO F21R2_DEF               F21R2 ;  //!< [02ec](04)[0x00000000]
  __IO F22R1_DEF               F22R1 ;  //!< [02f0](04)[0x00000000]
  __IO F22R2_DEF               F22R2 ;  //!< [02f4](04)[0x00000000]
  __IO F23R1_DEF               F23R1 ;  //!< [02f8](04)[0x00000000]
  __IO F23R2_DEF               F23R2 ;  //!< [02fc](04)[0x00000000]
  __IO F24R1_DEF               F24R1 ;  //!< [0300](04)[0x00000000]
  __IO F24R2_DEF               F24R2 ;  //!< [0304](04)[0x00000000]
  __IO F25R1_DEF               F25R1 ;  //!< [0308](04)[0x00000000]
  __IO F25R2_DEF               F25R2 ;  //!< [030c](04)[0x00000000]
  __IO F26R1_DEF               F26R1 ;  //!< [0310](04)[0x00000000]
  __IO F26R2_DEF               F26R2 ;  //!< [0314](04)[0x00000000]
  __IO F27R1_DEF               F27R1 ;  //!< [0318](04)[0x00000000]
  __IO F27R2_DEF               F27R2 ;  //!< [031c](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x0320 */

// ////////////////////+++ DAC +-+//////////////////// //
struct DAC_Type         { /*!< Digital-to-analog converter */
  union CR_DEF      {  //!< control register
    struct {
      __IO ONE_BIT    EN1       :  1; //!<[00] DAC channel1 enable
      __IO ONE_BIT    BOFF1     :  1; //!<[01] DAC channel1 output buffer disable
      __IO ONE_BIT    TEN1      :  1; //!<[02] DAC channel1 trigger enable
      __IO uint32_t   TSEL1     :  3; //!<[03] DAC channel1 trigger selection
      __IO uint32_t   WAVE1     :  2; //!<[06] DAC channel1 noise/triangle wave generation enable
      __IO uint32_t   MAMP1     :  4; //!<[08] DAC channel1 mask/amplitude selector
      __IO ONE_BIT    DMAEN1    :  1; //!<[12] DAC channel1 DMA enable
      __IO ONE_BIT    DMAUDRIE1 :  1; //!<[13] DAC channel1 DMA Underrun Interrupt enable
           uint32_t   UNUSED0   :  2; //!<[14] 
      __IO ONE_BIT    EN2       :  1; //!<[16] DAC channel2 enable
      __IO ONE_BIT    BOFF2     :  1; //!<[17] DAC channel2 output buffer disable
      __IO ONE_BIT    TEN2      :  1; //!<[18] DAC channel2 trigger enable
      __IO uint32_t   TSEL2     :  3; //!<[19] DAC channel2 trigger selection
      __IO uint32_t   WAVE2     :  2; //!<[22] DAC channel2 noise/triangle wave generation enable
      __IO uint32_t   MAMP2     :  4; //!<[24] DAC channel2 mask/amplitude selector
      __IO ONE_BIT    DMAEN2    :  1; //!<[28] DAC channel2 DMA enable
      __IO ONE_BIT    DMAUDRIE2 :  1; //!<[29] DAC channel2 DMA underrun interrupt enable
    } B;
    __IO uint32_t  R;
    explicit CR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SWTRIGR_DEF {  //!< software trigger register
    struct {
      __O  ONE_BIT  SWTRIG1 :  1; //!<[00] DAC channel1 software trigger
      __O  ONE_BIT  SWTRIG2 :  1; //!<[01] DAC channel2 software trigger
    } B;
    __O  uint32_t  R;
    explicit SWTRIGR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SWTRIGR_DEF r;
      R = f (r);
    }
  };
  union DHR12R1_DEF {  //!< channel1 12-bit right-aligned data holding register
    struct {
      __IO uint32_t   DACC1DHR : 12; //!<[00] DAC channel1 12-bit right-aligned data
    } B;
    __IO uint32_t  R;
    explicit DHR12R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DHR12R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DHR12R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DHR12L1_DEF {  //!< channel1 12-bit left aligned data holding register
    struct {
           uint32_t   UNUSED0  :  4; //!<[00] 
      __IO uint32_t   DACC1DHR : 12; //!<[04] DAC channel1 12-bit left-aligned data
    } B;
    __IO uint32_t  R;
    explicit DHR12L1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DHR12L1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DHR12L1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DHR8R1_DEF  {  //!< channel1 8-bit right aligned data holding register
    struct {
      __IO uint32_t   DACC1DHR :  8; //!<[00] DAC channel1 8-bit right-aligned data
    } B;
    __IO uint32_t  R;
    explicit DHR8R1_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DHR8R1_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DHR8R1_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DHR12R2_DEF {  //!< DAC channel2 12-bit right-aligned data holding register
    struct {
      __IO uint32_t   DACC2DHR : 12; //!<[00] DAC channel2 12-bit right-aligned data
    } B;
    __IO uint32_t  R;
    explicit DHR12R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DHR12R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DHR12R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DHR12L2_DEF {  //!< DAC channel2 12-bit left-aligned data holding register
    struct {
           uint32_t   UNUSED0  :  4; //!<[00] 
      __IO uint32_t   DACC2DHR : 12; //!<[04] DAC channel2 12-bit left-aligned data
    } B;
    __IO uint32_t  R;
    explicit DHR12L2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DHR12L2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DHR12L2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DHR8R2_DEF  {  //!< DAC channel2 8-bit right-aligned data holding register
    struct {
      __IO uint32_t   DACC2DHR :  8; //!<[00] DAC channel2 8-bit right-aligned data
    } B;
    __IO uint32_t  R;
    explicit DHR8R2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DHR8R2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DHR8R2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DHR12RD_DEF {  //!< DHR12RD
    struct {
      __IO uint32_t   DACC1DHR : 12; //!<[00] DAC channel1 12-bit right-aligned data
           uint32_t   UNUSED0  :  4; //!<[12] 
      __IO uint32_t   DACC2DHR : 12; //!<[16] DAC channel2 12-bit right-aligned data
    } B;
    __IO uint32_t  R;
    explicit DHR12RD_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DHR12RD_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DHR12RD_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DHR12LD_DEF {  //!< Dual DAC 12-bit left-aligned data holding register
    struct {
           uint32_t   UNUSED0  :  4; //!<[00] 
      __IO uint32_t   DACC1DHR : 12; //!<[04] DAC channel1 12-bit left-aligned data
           uint32_t   UNUSED1  :  4; //!<[16] 
      __IO uint32_t   DACC2DHR : 12; //!<[20] DAC channel2 12-bit left-aligned data
    } B;
    __IO uint32_t  R;
    explicit DHR12LD_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DHR12LD_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DHR12LD_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DHR8RD_DEF  {  //!< Dual DAC 8-bit right-aligned data holding register
    struct {
      __IO uint32_t   DACC1DHR :  8; //!<[00] DAC channel1 8-bit right-aligned data
      __IO uint32_t   DACC2DHR :  8; //!<[08] DAC channel2 8-bit right-aligned data
    } B;
    __IO uint32_t  R;
    explicit DHR8RD_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      DHR8RD_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      DHR8RD_DEF r; r.R = R;
      R = f (r);
    }
  };
  union DOR1_DEF    {  //!< channel1 data output register
    struct {
      __I  uint32_t   DACC1DOR : 12; //!<[00] DAC channel1 data output
    } B;
    __I  uint32_t  R;

    explicit DOR1_DEF (volatile DOR1_DEF & o) noexcept { R = o.R; };
  };
  union DOR2_DEF    {  //!< DAC channel2 data output register
    struct {
      __I  uint32_t   DACC2DOR : 12; //!<[00] DAC channel2 data output
    } B;
    __I  uint32_t  R;

    explicit DOR2_DEF (volatile DOR2_DEF & o) noexcept { R = o.R; };
  };
  union SR_DEF      {  //!< status register
    struct {
           uint32_t   UNUSED0 : 13; //!<[00] 
      __IO ONE_BIT    DMAUDR1 :  1; //!<[13] DAC channel1 DMA underrun flag
           uint32_t   UNUSED1 : 15; //!<[14] 
      __IO ONE_BIT    DMAUDR2 :  1; //!<[29] DAC channel2 DMA underrun flag
    } B;
    __IO uint32_t  R;
    explicit SR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SR_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL DAC REGISTERS INSTANCES
  __IO CR_DEF                   CR ;  //!< [0000](04)[0x00000000]
  __O  SWTRIGR_DEF         SWTRIGR ;  //!< [0004](04)[0x00000000]
  __IO DHR12R1_DEF         DHR12R1 ;  //!< [0008](04)[0x00000000]
  __IO DHR12L1_DEF         DHR12L1 ;  //!< [000c](04)[0x00000000]
  __IO DHR8R1_DEF           DHR8R1 ;  //!< [0010](04)[0x00000000]
  __IO DHR12R2_DEF         DHR12R2 ;  //!< [0014](04)[0x00000000]
  __IO DHR12L2_DEF         DHR12L2 ;  //!< [0018](04)[0x00000000]
  __IO DHR8R2_DEF           DHR8R2 ;  //!< [001c](04)[0x00000000]
  __IO DHR12RD_DEF         DHR12RD ;  //!< [0020](04)[0x00000000]
  __IO DHR12LD_DEF         DHR12LD ;  //!< [0024](04)[0x00000000]
  __IO DHR8RD_DEF           DHR8RD ;  //!< [0028](04)[0x00000000]
  __I  DOR1_DEF               DOR1 ;  //!< [002c](04)[0x00000000]
  __I  DOR2_DEF               DOR2 ;  //!< [0030](04)[0x00000000]
  __IO SR_DEF                   SR ;  //!< [0034](04)[0x00000000]
}; /* total size = 0x0400, struct size = 0x0038 */

// ////////////////////+++ SCB +-+//////////////////// //
struct SCB_Type         { /*!< System control block */
  union CPUID_DEF   {  //!< CPUID base register
    struct {
      __I  uint32_t   Revision    :  4; //!<[00] Revision number
      __I  uint32_t   PartNo      : 12; //!<[04] Part number of the processor
      __I  uint32_t   Constant    :  4; //!<[16] Reads as 0xF
      __I  uint32_t   Variant     :  4; //!<[20] Variant number
      __I  uint32_t   Implementer :  8; //!<[24] Implementer code
    } B;
    __I  uint32_t  R;

    explicit CPUID_DEF (volatile CPUID_DEF & o) noexcept { R = o.R; };
  };
  union ICSR_DEF    {  //!< Interrupt control and state register
    struct {
      __IO uint32_t   VECTACTIVE  :  6; //!<[00] Active vector
           uint32_t   UNUSED0     :  6; //!<[06] 
      __IO uint32_t   VECTPENDING :  6; //!<[12] Pending vector
           uint32_t   UNUSED1     :  4; //!<[18] 
      __IO ONE_BIT    ISRPENDING  :  1; //!<[22] Interrupt pending flag
           uint32_t   UNUSED2     :  2; //!<[23] 
      __IO ONE_BIT    PENDSTCLR   :  1; //!<[25] SysTick exception clear-pending bit
      __IO ONE_BIT    PENDSTSET   :  1; //!<[26] SysTick exception set-pending bit
      __IO ONE_BIT    PENDSVCLR   :  1; //!<[27] PendSV clear-pending bit
      __IO ONE_BIT    PENDSVSET   :  1; //!<[28] PendSV set-pending bit
           uint32_t   UNUSED3     :  2; //!<[29] 
      __IO ONE_BIT    NMIPENDSET  :  1; //!<[31] NMI set-pending bit.
    } B;
    __IO uint32_t  R;
    explicit ICSR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      ICSR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      ICSR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union AIRCR_DEF   {  //!< Application interrupt and reset control register
    struct {
           ONE_BIT    UNUSED0       :  1; //!<[00] 
      __IO ONE_BIT    VECTCLRACTIVE :  1; //!<[01] VECTCLRACTIVE
      __IO ONE_BIT    SYSRESETREQ   :  1; //!<[02] SYSRESETREQ
           uint32_t   UNUSED1       : 12; //!<[03] 
      __IO ONE_BIT    ENDIANESS     :  1; //!<[15] ENDIANESS
      __IO uint32_t   VECTKEYSTAT   : 16; //!<[16] Register key
    } B;
    __IO uint32_t  R;
    explicit AIRCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      AIRCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      AIRCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SCR_DEF     {  //!< System control register
    struct {
           ONE_BIT  UNUSED0     :  1; //!<[00] 
      __IO ONE_BIT  SLEEPONEXIT :  1; //!<[01] SLEEPONEXIT
      __IO ONE_BIT  SLEEPDEEP   :  1; //!<[02] SLEEPDEEP
           ONE_BIT  UNUSED1     :  1; //!<[03] 
      __IO ONE_BIT  SEVEONPEND  :  1; //!<[04] Send Event on Pending bit
    } B;
    __IO uint32_t  R;
    explicit SCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CCR_DEF     {  //!< Configuration and control register
    struct {
           uint32_t   UNUSED0      :  3; //!<[00] 
      __IO ONE_BIT    UNALIGN__TRP :  1; //!<[03] UNALIGN_ TRP
           uint32_t   UNUSED1      :  5; //!<[04] 
      __IO ONE_BIT    STKALIGN     :  1; //!<[09] STKALIGN
    } B;
    __IO uint32_t  R;
    explicit CCR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CCR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CCR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SHPR2_DEF   {  //!< System handler priority registers
    struct {
           uint32_t   UNUSED0 : 24; //!<[00] 
      __IO uint32_t   PRI_11  :  8; //!<[24] Priority of system handler 11
    } B;
    __IO uint32_t  R;
    explicit SHPR2_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SHPR2_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SHPR2_DEF r; r.R = R;
      R = f (r);
    }
  };
  union SHPR3_DEF   {  //!< System handler priority registers
    struct {
           uint32_t   UNUSED0 : 16; //!<[00] 
      __IO uint32_t   PRI_14  :  8; //!<[16] Priority of system handler 14
      __IO uint32_t   PRI_15  :  8; //!<[24] Priority of system handler 15
    } B;
    __IO uint32_t  R;
    explicit SHPR3_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      SHPR3_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      SHPR3_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL SCB REGISTERS INSTANCES
  __I  CPUID_DEF             CPUID ;  //!< [0000](04)[0x410FC241]
  __IO ICSR_DEF               ICSR ;  //!< [0004](04)[0x00000000]
       uint32_t          UNUSED0 ;  //!< [0008](04)[0xFFFFFFFF]
  __IO AIRCR_DEF             AIRCR ;  //!< [000c](04)[0x00000000]
  __IO SCR_DEF                 SCR ;  //!< [0010](04)[0x00000000]
  __IO CCR_DEF                 CCR ;  //!< [0014](04)[0x00000000]
       uint32_t          UNUSED1 ;  //!< [0018](04)[0xFFFFFFFF]
  __IO SHPR2_DEF             SHPR2 ;  //!< [001c](04)[0x00000000]
  __IO SHPR3_DEF             SHPR3 ;  //!< [0020](04)[0x00000000]
}; /* total size = 0x0041, struct size = 0x0024 */

// ////////////////////+++ STK +-+//////////////////// //
struct STK_Type         { /*!< SysTick timer */
  union CSR_DEF   {  //!< SysTick control and status register
    struct {
      __IO ONE_BIT    ENABLE    :  1; //!<[00] Counter enable
      __IO ONE_BIT    TICKINT   :  1; //!<[01] SysTick exception request enable
      __IO ONE_BIT    CLKSOURCE :  1; //!<[02] Clock source selection
           uint32_t   UNUSED0   : 13; //!<[03] 
      __IO ONE_BIT    COUNTFLAG :  1; //!<[16] COUNTFLAG
    } B;
    __IO uint32_t  R;
    explicit CSR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CSR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CSR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union RVR_DEF   {  //!< SysTick reload value register
    struct {
      __IO uint32_t   RELOAD : 24; //!<[00] RELOAD value
    } B;
    __IO uint32_t  R;
    explicit RVR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      RVR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      RVR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CVR_DEF   {  //!< SysTick current value register
    struct {
      __IO uint32_t   CURRENT : 24; //!<[00] Current counter value
    } B;
    __IO uint32_t  R;
    explicit CVR_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CVR_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CVR_DEF r; r.R = R;
      R = f (r);
    }
  };
  union CALIB_DEF {  //!< SysTick calibration value register
    struct {
      __IO uint32_t   TENMS   : 24; //!<[00] Calibration value
           uint32_t   UNUSED0 :  6; //!<[24] 
      __IO ONE_BIT    SKEW    :  1; //!<[30] SKEW flag: Indicates whether the TENMS value is exact
      __IO ONE_BIT    NOREF   :  1; //!<[31] NOREF flag. Reads as zero
    } B;
    __IO uint32_t  R;
    explicit CALIB_DEF () noexcept { R = 0x00000000u; }
    template<typename F> void setbit (F f) volatile {
      CALIB_DEF r;
      R = f (r);
    }
    template<typename F> void modify (F f) volatile {
      CALIB_DEF r; r.R = R;
      R = f (r);
    }
  };
  // PERIPHERAL STK REGISTERS INSTANCES
  __IO CSR_DEF               CSR ;  //!< [0000](04)[0x00000000]
  __IO RVR_DEF               RVR ;  //!< [0004](04)[0x00000000]
  __IO CVR_DEF               CVR ;  //!< [0008](04)[0x00000000]
  __IO CALIB_DEF           CALIB ;  //!< [000c](04)[0x00000000]
}; /* total size = 0x0011, struct size = 0x0010 */
static TIM2_Type        & TIM2        = * reinterpret_cast<TIM2_Type        *> (0x40000000);
static TIM2_Type        & TIM3        = * reinterpret_cast<TIM2_Type        *> (0x40000400);
static TIM6_Type        & TIM6        = * reinterpret_cast<TIM6_Type        *> (0x40001000);
static TIM6_Type        & TIM7        = * reinterpret_cast<TIM6_Type        *> (0x40001400);
static TIM14_Type       & TIM14       = * reinterpret_cast<TIM14_Type       *> (0x40002000);
static RTC_Type         & RTC         = * reinterpret_cast<RTC_Type         *> (0x40002800);
static WWDG_Type        & WWDG        = * reinterpret_cast<WWDG_Type        *> (0x40002c00);
static IWDG_Type        & IWDG        = * reinterpret_cast<IWDG_Type        *> (0x40003000);
static SPI1_Type        & SPI2        = * reinterpret_cast<SPI1_Type        *> (0x40003800);
static USART1_Type      & USART2      = * reinterpret_cast<USART1_Type      *> (0x40004400);
static USART1_Type      & USART3      = * reinterpret_cast<USART1_Type      *> (0x40004800);
static USART1_Type      & USART4      = * reinterpret_cast<USART1_Type      *> (0x40004c00);
static USART1_Type      & USART5      = * reinterpret_cast<USART1_Type      *> (0x40005000);
static I2C1_Type        & I2C1        = * reinterpret_cast<I2C1_Type        *> (0x40005400);
static I2C1_Type        & I2C2        = * reinterpret_cast<I2C1_Type        *> (0x40005800);
static USB_Type         & USB         = * reinterpret_cast<USB_Type         *> (0x40005c00);
static CAN_Type         & CAN         = * reinterpret_cast<CAN_Type         *> (0x40006400);
static CRS_Type         & CRS         = * reinterpret_cast<CRS_Type         *> (0x40006c00);
static PWR_Type         & PWR         = * reinterpret_cast<PWR_Type         *> (0x40007000);
static DAC_Type         & DAC         = * reinterpret_cast<DAC_Type         *> (0x40007400);
static CEC_Type         & CEC         = * reinterpret_cast<CEC_Type         *> (0x40007800);
static SYSCFG_COMP_Type & SYSCFG_COMP = * reinterpret_cast<SYSCFG_COMP_Type *> (0x40010000);
static EXTI_Type        & EXTI        = * reinterpret_cast<EXTI_Type        *> (0x40010400);
static USART1_Type      & USART6      = * reinterpret_cast<USART1_Type      *> (0x40011400);
static USART1_Type      & USART7      = * reinterpret_cast<USART1_Type      *> (0x40011800);
static USART1_Type      & USART8      = * reinterpret_cast<USART1_Type      *> (0x40011c00);
static ADC_Type         & ADC         = * reinterpret_cast<ADC_Type         *> (0x40012400);
static TIM1_Type        & TIM1        = * reinterpret_cast<TIM1_Type        *> (0x40012c00);
static SPI1_Type        & SPI1        = * reinterpret_cast<SPI1_Type        *> (0x40013000);
static USART1_Type      & USART1      = * reinterpret_cast<USART1_Type      *> (0x40013800);
static TIM15_Type       & TIM15       = * reinterpret_cast<TIM15_Type       *> (0x40014000);
static TIM16_Type       & TIM16       = * reinterpret_cast<TIM16_Type       *> (0x40014400);
static TIM16_Type       & TIM17       = * reinterpret_cast<TIM16_Type       *> (0x40014800);
static DBGMCU_Type      & DBGMCU      = * reinterpret_cast<DBGMCU_Type      *> (0x40015800);
static DMA1_Type        & DMA1        = * reinterpret_cast<DMA1_Type        *> (0x40020000);
static DMA1_Type        & DMA2        = * reinterpret_cast<DMA1_Type        *> (0x40020400);
static RCC_Type         & RCC         = * reinterpret_cast<RCC_Type         *> (0x40021000);
static Flash_Type       & Flash       = * reinterpret_cast<Flash_Type       *> (0x40022000);
static CRC_Type         & CRC         = * reinterpret_cast<CRC_Type         *> (0x40023000);
static TSC_Type         & TSC         = * reinterpret_cast<TSC_Type         *> (0x40024000);
static GPIOF_Type       & GPIOA       = * reinterpret_cast<GPIOF_Type       *> (0x48000000);
static GPIOF_Type       & GPIOB       = * reinterpret_cast<GPIOF_Type       *> (0x48000400);
static GPIOF_Type       & GPIOC       = * reinterpret_cast<GPIOF_Type       *> (0x48000800);
static GPIOF_Type       & GPIOD       = * reinterpret_cast<GPIOF_Type       *> (0x48000c00);
static GPIOF_Type       & GPIOE       = * reinterpret_cast<GPIOF_Type       *> (0x48001000);
static GPIOF_Type       & GPIOF       = * reinterpret_cast<GPIOF_Type       *> (0x48001400);
static STK_Type         & STK         = * reinterpret_cast<STK_Type         *> (0xe000e010);
static NVIC_Type        & NVIC        = * reinterpret_cast<NVIC_Type        *> (0xe000e100);
static SCB_Type         & SCB         = * reinterpret_cast<SCB_Type         *> (0xe000ed00);

static_assert (sizeof(struct TIM2_Type) == 80, "size error TIM2");
static_assert (sizeof(struct TIM6_Type) == 48, "size error TIM6");
static_assert (sizeof(struct TIM14_Type) == 84, "size error TIM14");
static_assert (sizeof(struct RTC_Type) == 100, "size error RTC");
static_assert (sizeof(struct WWDG_Type) == 12, "size error WWDG");
static_assert (sizeof(struct IWDG_Type) == 20, "size error IWDG");
static_assert (sizeof(struct I2C1_Type) == 44, "size error I2C1");
static_assert (sizeof(struct USB_Type) == 92, "size error USB");
static_assert (sizeof(struct CAN_Type) == 800, "size error CAN");
static_assert (sizeof(struct CRS_Type) == 16, "size error CRS");
static_assert (sizeof(struct PWR_Type) == 8, "size error PWR");
static_assert (sizeof(struct DAC_Type) == 56, "size error DAC");
static_assert (sizeof(struct CEC_Type) == 24, "size error CEC");
static_assert (sizeof(struct SYSCFG_COMP_Type) == 32, "size error SYSCFG_COMP");
static_assert (sizeof(struct EXTI_Type) == 24, "size error EXTI");
static_assert (sizeof(struct ADC_Type) == 780, "size error ADC");
static_assert (sizeof(struct TIM1_Type) == 80, "size error TIM1");
static_assert (sizeof(struct SPI1_Type) == 36, "size error SPI1");
static_assert (sizeof(struct USART1_Type) == 44, "size error USART1");
static_assert (sizeof(struct TIM15_Type) == 80, "size error TIM15");
static_assert (sizeof(struct TIM16_Type) == 80, "size error TIM16");
static_assert (sizeof(struct DBGMCU_Type) == 16, "size error DBGMCU");
static_assert (sizeof(struct DMA1_Type) == 144, "size error DMA1");
static_assert (sizeof(struct RCC_Type) == 56, "size error RCC");
static_assert (sizeof(struct Flash_Type) == 36, "size error Flash");
static_assert (sizeof(struct CRC_Type) == 16, "size error CRC");
static_assert (sizeof(struct TSC_Type) == 76, "size error TSC");
static_assert (sizeof(struct GPIOF_Type) == 44, "size error GPIOF");
static_assert (sizeof(struct STK_Type) == 16, "size error STK");
static_assert (sizeof(struct NVIC_Type) == 800, "size error NVIC");
static_assert (sizeof(struct SCB_Type) == 36, "size error SCB");

/* Interrupts : conflicts cmsis part - use copy / paste */
enum IRQn {
  NonMaskableInt_IRQn              = -14, //!< 2 Non Maskable Interrupt
  HardFault_IRQn                   = -13, //!< 3 HardFault
  MemoryManagement_IRQn            = -12, //!< 4 Cortex-M4 Memory Management Interrupt
  BusFault_IRQn                    = -11, //!< 5 Cortex-M4 Bus Fault Interrupt
  UsageFault_IRQn                  = -10, //!< 6 Cortex-M4 Usage Fault Interrupt
  SVCall_IRQn                      =  -5, //!< 11 Cortex-Mx SV Call Interrupt
  DebugMonitor_IRQn                =  -4, //!< 12 Cortex-M4 Debug Monitor Interrupt
  PendSV_IRQn                      =  -2, //!< 14 Cortex-Mx Pend SV Interrupt
  SysTick_IRQn                     =  -1, //!< 15 Cortex-Mx System Tick Interrupt

  WWDG_IRQn                        =   0, //!< Window Watchdog interrupt
  PVD_IRQn                         =   1, //!< PVD and VDDIO2 supply comparator interrupt
  RTC_IRQn                         =   2, //!< RTC interrupts
  FLASH_IRQn                       =   3, //!< Flash global interrupt
  RCC_CRS_IRQn                     =   4, //!< RCC and CRS global interrupts
  EXTI0_1_IRQn                     =   5, //!< EXTI Line[1:0] interrupts
  EXTI2_3_IRQn                     =   6, //!< EXTI Line[3:2] interrupts
  EXTI4_15_IRQn                    =   7, //!< EXTI Line15 and EXTI4 interrupts
  TSC_IRQn                         =   8, //!< Touch sensing interrupt
  DMA1_CH1_IRQn                    =   9, //!< DMA1 channel 1 interrupt
  DMA1_CH2_3_DMA2_CH1_2_IRQn       =  10, //!< DMA1 channel 2 and 3 and DMA2 channel 1 and 2 interrupt
  DMA1_CH4_5_6_7_DMA2_CH3_4_5_IRQn =  11, //!< DMA1 channel 4, 5, 6 and 7 and DMA2 channel 3, 4 and 5 interrupts
  ADC_COMP_IRQn                    =  12, //!< ADC and comparator interrupts
  TIM1_BRK_UP_TRG_COM_IRQn         =  13, //!< TIM1 break, update, trigger and commutation interrupt
  TIM1_CC_IRQn                     =  14, //!< TIM1 Capture Compare interrupt
  TIM2_IRQn                        =  15, //!< TIM2 global interrupt
  TIM3_IRQn                        =  16, //!< TIM3 global interrupt
  TIM6_DAC_IRQn                    =  17, //!< TIM6 global interrupt and DAC underrun interrupt
  TIM7_IRQn                        =  18, //!< TIM7 global interrupt
  TIM14_IRQn                       =  19, //!< TIM14 global interrupt
  TIM15_IRQn                       =  20, //!< TIM15 global interrupt
  TIM16_IRQn                       =  21, //!< TIM16 global interrupt
  TIM17_IRQn                       =  22, //!< TIM17 global interrupt
  I2C1_IRQn                        =  23, //!< I2C1 global interrupt
  I2C2_IRQn                        =  24, //!< I2C2 global interrupt
  SPI1_IRQn                        =  25, //!< SPI1_global_interrupt
  SPI2_IRQn                        =  26, //!< SPI2 global interrupt
  USART1_IRQn                      =  27, //!< USART1 global interrupt
  USART2_IRQn                      =  28, //!< USART2 global interrupt
  USART3_4_5_6_7_8_IRQn            =  29, //!< USART3, USART4, USART5, USART6, USART7, USART8 global interrupt
  CEC_CAN_IRQn                     =  30, //!< CEC and CAN global interrupt
  USB_IRQn                         =  31, //!< USB global interrupt
};
#endif
