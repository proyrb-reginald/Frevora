/**
******************************************************************************
* @file    SC32F12XX.h
* @author  SOC SA Team
* @brief   CMSIS Cortex-M0+ Device Peripheral Access Layer Header File.
*          This file contains all the peripheral register's definitions, bits
*          definitions and memory mapping for SC32F12XX devices.
*
*          This file contains:
*           - Data structures and the address mapping for all peripherals
*           - Peripheral's registers declarations and bits definition
*           - Macros to access peripheral's registers hardware
*
******************************************************************************
* @attention
*
*1.This software is supplied by SinOne Microelectronics Co.,Ltd. and is only 
*intended for use with SinOne products. No other uses are authorized. This 
*software is owned by SinOne Microelectronics Co.,Ltd. and is protected under 
*all applicable laws, including copyright laws. 
*2.The software which is for guidance only aims at providing customers with 
*coding information regarding their products in order for them to save time. 
*As a result, SinOne shall not be held liable for any direct, indirect or 
*consequential damages with respect to any claims arising from the content of 
*such software and/or the use made by customers of the coding information 
*contained herein in connection with their products.
*
*  COPYRIGHT 2024 SinOne Microelectronics
*/




/** @addtogroup CMSIS_Device
  * @{
  */

/** @addtogroup sc32f12xx
  * @{
  */

#ifndef SC32F12XX_H
#define SC32F12XX_H



#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
  * @brief Configuration of the Cortex-M0+ Processor and Core Peripherals
   */
#define __CM0PLUS_REV             0U /*!< Core Revision r0p0                            */
#define __MPU_PRESENT             1U /*!< Coretex Mo+  provides an MPU                  */
#define __VTOR_PRESENT            1U /*!< Vector  Table  Register supported             */
#define __NVIC_PRIO_BITS          2U /*!< SC32F12XX uses 2 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0U /*!< Set to 1 if different SysTick Config is used  */

/**
  * @}
  */

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */
#if !defined  (LXT_VALUE) 
  #define LXT_VALUE    ((uint32_t)32768) /*!< Default value of the External oscillator in Hz */
#endif /* LXT_VALUE */
#if !defined  (HXT_VALUE) 
  #define HXT_VALUE    ((uint32_t)16000000) /*!< Default value of the External oscillator in Hz */
#endif /* HXT_VALUE */
#if !defined  (HIRC_VALUE) 
  #define HIRC_VALUE    ((uint32_t)64000000) /*!< Default value of the External oscillator in Hz */
#endif /* HIRC_VALUE */
#if !defined  (LIRC_VALUE) 
  #define LIRC_VALUE    ((uint32_t)32000) /*!< Default value of the External oscillator in Hz */
#endif /* LIRC_VALUE */
/**
 * @brief SC32F12XX Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */

/*!< Interrupt Number Definition */
typedef enum
{
/******  Cortex-M0+ Processor Exceptions Numbers ***************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                          */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M Hard Fault Interrupt                                   */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M SV Call Interrupt                                     */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M Pend SV Interrupt                                     */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M System Tick Interrupt                                 */
/******  SC32F12xxxx specific Interrupt Numbers ****************************************************************/
  INT0_IRQn                  = 0,      /*!< INT  0 Interrupt                                                 */
  INT1_7_IRQn                = 1,      /*!< INT Line from 1 to 7  Interrupt                                  */
  INT8_11_IRQn               = 2,      /*!< INT Line from 8 to 11  Interrupt                                 */
  INT12_15_IRQn              = 3,      /*!< INT Line from 12 to 15  Interrupt                                */
  RCC_IRQn                    = 4,      /*!< RCC shut down Interrupts                                          */
  BTM_IRQn                    = 6,      /*!< BTM  Interrupts                                                   */
  UART0_2_4_IRQn              = 7,      /*!< UART0 and UART2 Interrupts                                        */
  UART1_3_5_IRQn              = 8,      /*!< UART1 and UART3 Interrupts                                        */
  SPI0_IRQn                   = 9,      /*!< SPI0 Interrupts                                                   */
  SPI1_2_IRQn                 = 10,     /*!< SPI1 and SPI2  Interrupts                                         */
  DMA0_IRQn                   = 11,     /*!< DMA0 Interrupts                                                   */
  DMA1_IRQn                   = 12,     /*!< DMA1 Interrupts                                                   */
  TIMER0_IRQn                 = 15,     /*!< TIMER0 global Interrupts                                          */
  TIMER1_IRQn                 = 16,     /*!< TIMER1 global Interrupt                                           */
  TIMER2_IRQn                 = 17,     /*!< TIMER2 global Interrupt                                           */
  TIMER3_IRQn                 = 18,     /*!< TIMER3 global Interrupt                                           */
  TIMER4_5_IRQn               = 19,     /*!< TIMER4 and TIMER5 global Interrupt                                */
  TIMER6_7_IRQn               = 20,     /*!< TIMER6 and TIMER7 global Interrupt                                */
  PWM0_IRQn                   = 21,     /*!< PWM0 Interrupt                                                    */
  LEDPWM_IRQn                 = 22,     /*!< LEDPWM Interrupt                                                  */
  TWI0_IRQn                   = 23,     /*!< TWI0 Interrupt                                                    */
  TWI1_IRQn                   = 24,     /*!< TWI1 Interrupt                                                    */
  ADC_IRQn                    = 29,     /*!< ADC  Interrupt                                                    */
  CMP_IRQn                    = 30,     /*!< CMP  Interrupt                                                    */
  TK_IRQn                     = 31,     /*!< TouchKey  Interrupt                                               */
} IRQn_Type;

/**
  * @}
  */

#include "core_cm0plus.h"               /* Cortex-M0+ processor and core peripherals */
#include "system_sc32f1xxx.h"
#include <stdint.h>


/** @addtogroup Exported_types
  * @{
  */
typedef enum
{
  RESET = 0,
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
  DISABLE = 0,
  ENABLE = !DISABLE
} FunctionalState;

#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum
{
  SUCCESS = 0,
  ERROR = !SUCCESS
} ErrorStatus;

typedef enum
{
  FALSE = 0,
  TRUE = !FALSE
} boolType;


/** @addtogroup Exported_macros
  * @{
  */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define REG_SET(REG, BIT)     ((REG) &= ~(BIT));((REG) |= (BIT))

#define REG_SETn(REG, BITs, BIT)     ((REG) &= ~(BITs));((REG) |= (BIT))

/* Peripheral for APB0=0x40020000
   Peripheral for APB1=0x40021000
   Peripheral for APB2=0x40022000
*/
/**
  * @brief RCCAPB0 for APB0,Peripheral offset =0x00
  */
typedef struct
{
 __IO uint32_t APB0_CFG;         /*!< APB0 Config register,      Address offset: 0x00 */
 __IO uint32_t APB0_RST;          /*!< APB0 Reset register,       Address offset: 0x04 */
} RCCAPB0_TypeDef; 

/**
  * @brief RCCAPB1 for APB1,Peripheral offset =0x00
  */
typedef struct
{
 __IO uint32_t APB1_CFG;         /*!< APB1 Config register,      Address offset: 0x00 */
 __IO uint32_t APB1_RST;         /*!< APB1 Reset register,       Address offset: 0x04 */
} RCCAPB1_TypeDef; 

/**
  * @brief RCCAPB2 for APB2,Peripheral offset =0x00
  */
typedef struct
{
 __IO uint32_t APB2_CFG;         /*!< APB2 Config register,      Address offset: 0x00 */
 __IO uint32_t APB2_RST;         /*!< APB2 Reset register,       Address offset: 0x04 */
} RCCAPB2_TypeDef; 


/** @addtogroup Peripheral_registers_structures
  * @{
  */
/**
  * @brief UART0-1 for APB0,UART2 for APB1,UART3 for APB2,UART0/2/3 Peripheral offset =0x20,UART1 Peripheral offset=0x80
  */
typedef struct
{
 __IO uint32_t UART_CON;         /*!< UART Config register,                  Address offset: 0x00 */
 __IO uint32_t UART_STS;         /*!< UART Status register,                  Address offset: 0x04 */
 __IO uint32_t UART_BAUD;        /*!< UART BaudRate register,                Address offset: 0x08 */
 __IO uint32_t UART_DATA;        /*!< UART Data register,                    Address offset: 0x0C */
 __IO uint32_t UART_IDE;         /*!< UART Interrupt /Dma Enable register,   Address offset: 0x10 */
} UART_TypeDef; 

/**
  * @brief SPI0 for APB0,SPI1 for APB1 ,Peripheral offset =0x40
  */
typedef struct
{
 __IO uint32_t SPI_CON;          /*!< SPI Control register,                 Address offset: 0x00 */
 __IO uint32_t SPI_STS;          /*!< SPI Status register,                  Address offset: 0x04 */
 __IO uint32_t RESERVED;         /*!< Reserved,                             Address offset: 0x08 */
 __IO uint32_t SPI_DATA;         /*!< SPI Data register,                    Address offset: 0x0C */
 __IO uint32_t SPI_IDE;          /*!< SPI Interrupt /Dma Enable register,   Address offset: 0x10 */
 __IO uint32_t RESERVED2;
 __IO uint32_t RESERVED3;
 __IO uint32_t SPI_REV;
} SPI_TypeDef; 

/**
  * @brief TWI0 for APB0,TWI1 for APB1 ,Peripheral offset =0x60
  */
typedef struct
{
 __IO uint32_t TWI_CON;          /*!< TWI Config register,                  Address offset: 0x00 */
 __IO uint32_t TWI_STS;          /*!< TWI Status register,                  Address offset: 0x04 */
 __IO uint32_t TWI_ADD;          /*!< TWI Adress register,                  Address offset: 0x08 */
 __IO uint32_t TWI_DATA;         /*!< TWI Data register,                    Address offset: 0x0C */
 __IO uint32_t TWI_IDE;          /*!< TWI Interrupt /Dma Enable register,   Address offset: 0x10 */
} TWI_TypeDef; 

/**
  * @brief TIEMR0123 for APB0,TIEMR4567 for APB1, Peripheral offset=0x100+0x40*n(n=0,1,2,3)
  */
typedef struct
{
 __IO uint32_t TIM_CON;          /*!< TCON register,                         Address offset: 0x00 */
 __IO uint32_t TIM_CNT;          /*!< TCNT register,                         Address offset: 0x04 */
 __IO uint32_t TIM_RLD;          /*!< TIMER ReLoad register,                 Address offset: 0x08 */
 __IO uint32_t TIM_STS;          /*!< TIMER Status register,                 Address offset: 0x0C */
 __IO uint32_t TIM_PDTA_RCAP;    /*!< TIMER Rise Caputre Key register,       Address offset: 0x10 */
 __IO uint32_t TIM_PDTB_FCAP;    /*!< TIMER fall Caputre register,           Address offset: 0x14 */
 __IO uint32_t TIM_IDE;          /*!< TIMER Interrupt /Dma Enable register,  Address offset: 0x18 */
} TIM_TypeDef;

/**
  * @brief PWM0 for APB0, PWM0 Peripheral offset=0x200
  */
typedef struct
{
 __IO uint32_t PWM_CON;         /*!< Pwm Control register,                          Address offset: 0x00 */
 __IO uint32_t PWM_CHN;          /*!< PWM Channel register,                         Address offset: 0x04 */
 __IO uint32_t PWM_STS;          /*!< PWM Status register,                          Address offset: 0x08 */
 __IO uint32_t PWM_INV;          /*!< PWM Inverse register,                         Address offset: 0x0C */
 __IO uint32_t PWM_DFR;          /*!< PWM Dead space register,                      Address offset: 0x10 */
 __IO uint32_t PWM_FLT;          /*!< PWM FaiLure detection register,               Address offset: 0x14 */
 __IO uint32_t PWM_CYCLE;        /*!< PWM Cycles register,                          Address offset: 0x18 */
 __IO uint32_t RESERVED[5];       /*!< Reserved,                                     Address offset: 0x1C */
 __IO uint32_t PWM_DT[8];        /*!< PWM Duty register,@PWM0 PWM_DT[8] is Valied,  Address offset: 0x30 */
} PWM_TypeDef;
/**
  * @brief LEDPWM for APB2,LEDPWM Peripheral offset=0x300,
  */
typedef struct
{
 __IO uint32_t LEDPWM_CON;          /*!< LEDPWM Control register,                               Address offset: 0x00 */
 __IO uint32_t LEDPWM_CHN;         /*!< LEDPWM Channel register,                              Address offset: 0x04 */
 __IO uint32_t LEDPWM_STS;          /*!< LEDPWM Status register,                                Address offset: 0x08 */
 __IO uint32_t LEDPWM_INV;         /*!< LEDPWM Inverse register,                              Address offset: 0x0C */
 __IO uint32_t LEDPWM_DFR;          /*!< LEDPWM Dead space register,                            Address offset: 0x10 */
 __IO uint32_t LEDPWM_FLT;          /*!< LEDPWM FaiLure detection register,                     Address offset: 0x14 */
 __IO uint32_t LEDPWM_CYCLE;        /*!< LEDPWM Cycles register,                                Address offset: 0x18 */
 __IO uint32_t RESERVED[5];         /*!< Reserved,                                           Address offset: 0x1C~0x2C */
 __IO uint32_t LEDPWM_DT[32];       /*!< LEDPWM Duty register,@LEDPWM LEDPWM_DT[31] is Valied,  Address offset: 0x30 */
} LEDPWM_TypeDef;
/**
  * @brief BTM for APB2,Peripheral offset=0x100
  */
typedef struct
{
  __IO uint32_t BTM_CON;          /*!< ADC Control register,      Address offset: 0x00 */
  __IO uint32_t BTM_STS;          /*!< ADC Status register,       Address offset: 0x04 */
} BTM_TypeDef; 

/**
  * @brief ADC for APB2,Peripheral offset=0x110
  */
typedef struct
{
 __IO uint32_t ADC_CON;        /*!< ADC Control register,      Address offset: 0x00 */
 __IO uint32_t ADC_STS;        /*!< ADC Status register,       Address offset: 0x04 */
 __IO uint32_t ADC_VALUE;      /*!< ADC Value register,        Address offset: 0x08 */
 __IO uint32_t ADC_CFG;        /*!< ADC Config register,       Address offset: 0x0C */
} ADC_TypeDef; 

/**
  * @brief CMP for APB2,Peripheral offset=0x130
  */
typedef struct
{
 __IO uint32_t CMP_STS;          /*!< CMP Status register,     Address offset: 0x00 */
 __IO uint32_t CMP_CFG;          /*!< CMP Config register,     Address offset: 0x04 */
} CMP_TypeDef; 

/**
  * @brief 0P for APB2,Peripheral offset=0x140
  */
typedef struct
{
 __IO uint32_t OP_CON;          /*!< OP Control register,       Address offset: 0x00 */
} OP_TypeDef; 

/**
  * @brief TK for APB2,Peripheral offset=0x200
  */
typedef struct
{
 __IO uint32_t TK_CHN0;           /*!< TK Channel register0,        Address offset: 0x00 */
 __IO uint32_t TK_CHN1;           /*!< TK Channel register1,        Address offset: 0x04 */ 
 __IO uint32_t RESERVED0;         /*!< Reserved0,                   Address offset: 0x08 */ 
 __IO uint32_t TK_CON;            /*!< TK Control register,         Address offset: 0x0C */
 __IO uint32_t TK_CFG;            /*!< TK Config register,          Address offset: 0x10 */
 __IO uint32_t RESERVED1;         /*!< Reserved1,                   Address offset: 0x14 */
 __IO uint32_t TK_CNT;            /*!< TK RawData register,         Address offset: 0x18 */
 __IO uint32_t TK_TM;             /*!< TK TM register,              Address offset: 0x1C */
} TK_TypeDef;

/**
  * @brief LCD/LED for APB2,Peripheral offset=0x280
  */
typedef struct
{
 __IO uint32_t DDR_CON;          /*!< Display Drive Control register,    Address offset: 0x00 */
 __IO uint32_t DDR_CFG;          /*!< Display Drive Config register,    Address offset: 0x04 */
 __IO uint32_t SEG_EN;          /*!< Segment IO Enable register,        Address offset: 0x08 */
 __IO uint32_t RESERVED0;        /*!< Reserved0,                         Address offset: 0x0C */ 
 __IO uint32_t COM_EN;           /*!< COM IO Enable register register,   Address offset: 0x10 */
 __IO uint32_t RESERVED1[39];  /*!< Reserved,                                            Address offset: 0x14 */
 __IO uint32_t SEGRn[28];
} LCD_LED_TypeDef;


/*
  Peripheral for IOPORT=0x40011000
*/
/**
  * @brief GPIO for IOPORT,Peripheral offset=0x100*n(n=0,1,2)
  */
typedef struct
{
 __IO uint32_t PIN;            /*!< GPIOA,B,C register,                   Address offset: 0x00 */
 __IO uint32_t RESERVED0[7];   /*!< Reserved,                             Address offset: 0x04 */
 __IO uint32_t PXCON;          /*!< GPIO port Control register,           Address offset: 0x20 */
 __IO uint32_t RESERVED1[7];   /*!< Reserved,                             Address offset: 0x24 */
 __IO uint32_t PXPH;          /*!< GPIO port pull-up/pull-down register, Address offset: 0x40 */
 __IO uint32_t RESERVED2[7];   /*!< Reserved,                             Address offset: 0x44 */
 __IO uint32_t PXLEV;          /*!< GPIO port Level register,             Address offset: 0x60 */
} GPIO_TypeDef;


/**
  * @brief GPIO for IOPORT BIT,Peripheral offset=0x100*n(n=0,1,2)
  */
typedef struct
{
 __IO uint8_t PIN_BIT[16];       /*!< GPIOA,B,C Bit register,              Address offset: 0x00 */
 __IO uint8_t PIN_XR[16];        /*!< GPIOA,B,C Bit register,              Address offset: 0x20 */
} GPIO_BIT_TypeDef;


/**
  * @brief INT for IOPORT,Peripheral offset=0x300
  */
typedef struct
{
 __IO uint32_t INTF_IE;        /*!< INT Fall edge Enable register,           Address offset: 0x00 */
 __IO uint32_t RESERVED0[7];   /*!< Reserved,                                 Address offset: 0x04 */
 __IO uint32_t INTR_IE;        /*!< INT Rise edge Enable register register,  Address offset: 0x20 */
 __IO uint32_t RESERVED1[7];   /*!< Reserved,                                 Address offset: 0x24 */
 __IO uint32_t INT_SEL0;       /*!< INT0-7 Port Select register,             Address offset: 0x40 */
 __IO uint32_t RESERVED2[7];   /*!< Reserved,                                 Address offset: 0x44 */
 __IO uint32_t INT_SEL1;       /*!< INT8-15 Port Select register,            Address offset: 0x60 */
 __IO uint32_t RESERVED3[7];   /*!< Reserved,                                 Address offset: 0x64 */
 __IO uint32_t INTF_CON;       /*!< INT Fall Control  register,              Address offset: 0x80 */
 __IO uint32_t RESERVED4[7];   /*!< Reserved,                                 Address offset: 0x84 */
 __IO uint32_t INTR_CON;       /*!< INT Rise Control register,               Address offset: 0xA0 */
 __IO uint32_t RESERVED5[7];   /*!< Reserved,                                 Address offset: 0xA4 */
 __IO uint32_t INTF_STS;       /*!< INT Fall Status  register,               Address offset: 0xC0 */
 __IO uint32_t RESERVED6[7];   /*!< Reserved,                                 Address offset: 0xC4 */
 __IO uint32_t INTR_STS;       /*!< INT Rise status register,                Address offset: 0xE0 */
 __IO uint32_t RESERVED7[7];   /*!< Reserved,                                 Address offset: 0xE4 */
} INT_TypeDef;

/*
  Peripheral for AHB=0x40000000
*/
/**
  * @brief WDT for AHB,Peripheral offset=0x330
  */
typedef struct
{
 __IO uint32_t RESERVED0[3];   /*!< Reserved,                     Address offset: 0x00 */
 __IO uint32_t WDT_CON;        /*!< WDT Control register,         Address offset: 0x0C */
 __IO uint32_t WDT_CFG;        /*!< WDT Config register,          Address offset: 0x10 */
} WDT_TypeDef;

/**
  * @brief IAP for AHB,Peripheral offset=0x3C0
  */
typedef struct
{
 __IO uint32_t IAPKEY;          /*!< IAP KEY register,            Address offset: 0x00 */
 __IO uint32_t IAP_SNB;         /*!< IAP Sector Number register,  Address offset: 0x04 */
 __IO uint32_t RESERVED0;       /*!< Reserved,                    Address offset: 0x08 */
 __IO uint32_t IAP_CON;         /*!< IAP Control register,        Address offset: 0x0C */
} IAP_TypeDef;


/**
  * @brief OPT for AHB,Peripheral offset=0x3F8
  */
typedef struct
{
 __IO uint32_t OPINX;            /*!< OPINX register,        Address offset: 0x00 */
 __IO uint32_t OPREG;            /*!< OPREG register,        Address offset: 0x04 */
} OPT_TypeDef;

/**
  * @brief CRC for AHB,Peripheral offset=0x2000
  */
typedef struct
{
 __IO uint32_t CRC_DR;           /*!< CRC Data register,        Address offset: 0x00 */
 __IO uint32_t CRC_CON;          /*!< CRC Config register,      Address offset: 0x04 */
 __IO uint32_t CRC_INT;          /*!< CRC Inital register,      Address offset: 0x08 */
 __IO uint32_t CRC_POL;          /*!< CRC Poly  register,       Address offset: 0x0C */
} CRC_TypeDef;


/**
  * @brief RCCAHB for AHB,Peripheral offset =0x3000
  */
typedef struct
{
  __IO uint32_t AHB_CFG;          /*!< AHB Config register,      Address offset: 0x00 */
  __IO uint32_t AHB_RST;          /*!< AHB Reset register,       Address offset: 0x04 */
} RCCAHB_TypeDef; 

/**
  * @brief RCC for AHB,Peripheral offset=0x3014
  */
typedef struct
{
 __IO uint32_t RCC_KEY;          /*!< RCC KEY register,          Address offset: 0x0C */
 __IO uint32_t RESERVED0;        /*!< Reserved0,                 Address offset: 0x10 */
 __IO uint32_t RCC_CFG0;         /*!< RCC Config0 register,      Address offset: 0x14 */
 __IO uint32_t RCC_CFG1;         /*!< RCC Config1 register,      Address offset: 0x18 */
 __IO uint32_t RESERVED1;        /*!< Reserved1,                 Address offset: 0x1C */
 __IO uint32_t RCC_STS;          /*!< RCC Status  register,      Address offset: 0x20 */
 __IO uint32_t RESERVED2;        /*!< Reserved2,                 Address offset: 0x24 */
 __IO uint32_t SYST_CALIB;       /*!< RCC Calib  register,       Address offset: 0x28 */
 __IO uint32_t NMI_CFG;          /*!< NMI register,              Address offset: 0x2C */
} RCC_TypeDef;


/*
  Peripheral for DMA=AHB+0x10800
*/
/**
  * @brief DMA0..DMA1 Peripheral offset=0x40*n(n=0,1)
  */
typedef struct
{
 __IO uint32_t DMA_SADR;         /*!< DMA Source Adress register,            Address offset: 0x00 */
 __IO uint32_t DMA_DADR;         /*!< DMA Destination Adress register,       Address offset: 0x04 */
 __IO uint32_t DMA_CFG;          /*!< DMA Config register,                   Address offset: 0x08 */
 __IO uint32_t DMA_CNT;          /*!< DMA Count  register,                   Address offset: 0x0C */
 __IO uint32_t DMA_STS;          /*!< DMA Status register,                   Address offset: 0x10 */
} DMA_TypeDef;


/*--------------------------------------------------------------------------
  IFB[400H]~IFB[5FFH] for DesignOption
*/
/**
* @brief must to OPINX and OPREG operate and  AHB_CFG.2(FIBEN)=1&&PASSWORD=Decode
  */
typedef struct
{
 __IO uint8_t Bg;               /*!< OPINX=0x81>*/
 __IO uint8_t Vref;             /*!< OPINX=0x82>*/
 __IO uint8_t Hrcr;             /*!< OPINX=0x83>*/
 __IO uint8_t Lrc;              /*!< OPINX=0x84>*/
 __IO uint8_t Hrcc;             /*!< OPINX=0x85>*/
 __IO uint8_t RomSize;          /*!< OPINX=0x86>*/
 __IO uint8_t Tk;               /*!< OPINX=0x87>*/
 __IO uint8_t Ldo;              /*!< OPINX=0x88>*/
 __IO uint8_t Adcmp;            /*!< OPINX=0x89>*/
 __IO uint8_t Rcc;              /*!< OPINX=0x8A>*/
} DesignOption_TypeDef;

/** @addtogroup Peripheral_memory_map
  * @{
  */
#define FLASH_BASE            (0x08000000UL)  /*!< FLASH base address  */
#define EEPROM_BASE           (0X08E00000UL)  /*!< EEPROM base address */
#define SRAM_BASE             (0x20000000UL)  /*!< SRAM base address   */
#define PERIPH_BASE           (0x40000000UL)  /*!< Peripheral base address */
#define IOPORT_BASE           (0x40011000UL)  /*!< IOPORT base address */
#define SRAM_SIZE_MAX         (0x00004000UL)  /*!< maximum SRAM size (up to 16 KBytes) */

//Prviate Peripheral_memory_map 
#define IFB_BASE              (0x08C00000UL)   /*!<Ifb>*/
#define PASSWORD_BASE         (IFB_BASE+0x00000)
#define CODEOPTION_BASE       (IFB_BASE+0x00200)
#define DESIGNOPTION_BASE     (IFB_BASE+0x00400)
#define LDROM_BASE            (IFB_BASE+0x100000)
//===============================================
#define SECTOR_SIZE           512
#define FLASH_SIZE            (SECTOR_SIZE*1024)
#define LDROM_SIZE            (SECTOR_SIZE*8)

/*!< Peripheral memory map */
#define AHBPERIPH_BASE         (PERIPH_BASE)
#define APB0PERIPH_BASE        (PERIPH_BASE+0x20000)
#define APB1PERIPH_BASE        (PERIPH_BASE+0x21000)
#define APB2PERIPH_BASE        (PERIPH_BASE+0x22000)
#define DMAPERIPH_BASE         (PERIPH_BASE+0x10800)
#define IOPORTPERIPH_BASE      (PERIPH_BASE+0x11000)

/*!< AHB peripherals */
#define WDT_BASE               (AHBPERIPH_BASE +(0x00000330UL))
#define IAP_BASE               (AHBPERIPH_BASE +(0x000003C0UL))
#define OPT_BASE               (AHBPERIPH_BASE +(0x000003F8UL))
#define CRC_BASE               (AHBPERIPH_BASE +(0x00002000UL))
#define RCCAHB_BASE            (AHBPERIPH_BASE +(0x00003000UL))
#define RCC_BASE               (AHBPERIPH_BASE +(0x0000300CUL))
/*!< APB0 peripherals */
#define RCCAPB0_BASE           (APB0PERIPH_BASE +(0x00000000UL))
#define UART0_BASE             (APB0PERIPH_BASE +(0x00000020UL))
#define UART1_BASE             (APB0PERIPH_BASE +(0x00000080UL))
#define SPI0_BASE              (APB0PERIPH_BASE +(0x00000040UL))
#define TWI0_BASE              (APB0PERIPH_BASE +(0x00000060UL))
#define UART5_BASE             (APB0PERIPH_BASE +(0x000000A0UL))
#define TIM0_BASE              (APB0PERIPH_BASE +(0x00000100UL))
#define TIM1_BASE              (APB0PERIPH_BASE +(0x00000140UL))
#define TIM2_BASE              (APB0PERIPH_BASE +(0x00000180UL))
#define TIM3_BASE              (APB0PERIPH_BASE +(0x000001C0UL))
#define PWM0_BASE              (APB0PERIPH_BASE +(0x00000200UL))
/*!< APB1 peripherals */
#define RCCAPB1_BASE           (APB1PERIPH_BASE +(0x00000000UL))
#define UART2_BASE             (APB1PERIPH_BASE +(0x00000020UL))
#define SPI1_BASE              (APB1PERIPH_BASE +(0x00000040UL))
#define TWI1_BASE              (APB1PERIPH_BASE +(0x00000060UL))
#define UART4_BASE             (APB1PERIPH_BASE +(0x00000080UL))
#define SPI2_BASE              (APB1PERIPH_BASE +(0x000000A0UL))
#define TIM4_BASE              (APB1PERIPH_BASE +(0x00000100UL))
#define TIM5_BASE              (APB1PERIPH_BASE +(0x00000140UL))
#define TIM6_BASE              (APB1PERIPH_BASE +(0x00000180UL))
#define TIM7_BASE              (APB1PERIPH_BASE +(0x000001C0UL))

/*!< APB2 peripherals */
#define RCCAPB2_BASE           (APB2PERIPH_BASE +(0x00000000UL))
#define UART3_BASE             (APB2PERIPH_BASE +(0x00000020UL))
#define LEDPWM_BASE            (APB2PERIPH_BASE +(0x00000300UL))
#define BTM_BASE               (APB2PERIPH_BASE +(0x00000100UL))
#define ADC_BASE               (APB2PERIPH_BASE +(0x00000110UL))
#define CMP_BASE               (APB2PERIPH_BASE +(0x00000130UL))
#define OP_BASE                (APB2PERIPH_BASE +(0x00000140UL))
#define TK_BASE                (APB2PERIPH_BASE +(0x00000200UL))
#define LCD_LED_BASE           (APB2PERIPH_BASE +(0x00000280UL))
/*!< DMA */
#define DMA0_BASE              (DMAPERIPH_BASE +(0x00000000UL))
#define DMA1_BASE              (DMAPERIPH_BASE +(0x00000040UL))
/*!< IOPORT */
#define GPIOA_BASE             (IOPORTPERIPH_BASE +(0x00000000UL))
#define GPIOB_BASE             (IOPORTPERIPH_BASE +(0x00000100UL))
#define GPIOC_BASE             (IOPORTPERIPH_BASE +(0x00000200UL))
#define INT_BASE              (IOPORTPERIPH_BASE +(0x00000800UL))
#define FT_BIT_BASE            (IOPORTPERIPH_BASE +(0x000008C0UL))
#define RT_BIT_BASE            (IOPORTPERIPH_BASE +(0x000008E0UL))
/*!< IOPORT-Bit */
#define GPIOA_BIT_BASE         (GPIOA_BASE+(0x00000000UL)) 
#define GPIOB_BIT_BASE         (GPIOB_BASE+(0x00000000UL))
#define GPIOC_BIT_BASE         (GPIOC_BASE+(0x00000000UL))
/*!< IOPORT-OverTurn */
#define GPIOA_OT_BASE          (GPIOA_BASE+(0x00000010UL)) 
#define GPIOB_OT_BASE          (GPIOB_BASE+(0x00000010UL))
#define GPIOC_OT_BASE          (GPIOC_BASE+(0x00000010UL))
/*<PA.SetBit:n=0...15>*/
#define PA_BIT(n)              (*((uint8_t*)((GPIOA_BIT_BASE + (n)))))
#define PB_BIT(n)              (*((uint8_t*)((GPIOB_BIT_BASE + (n)))))
#define PC_BIT(n)              (*((uint8_t*)((GPIOC_BIT_BASE + (n)))))
/*<PA.OverTurn:n=0...15>*/
#define PA_OT(n)               (*((uint8_t*)((GPIOA_OT_BASE + (n)))))=1
#define PB_OT(n)               (*((uint8_t*)((GPIOB_OT_BASE + (n)))))=1
#define PC_OT(n)               (*((uint8_t*)((GPIOC_OT_BASE + (n)))))=1
/*<INTF/INTR.SetBit:n=0...15>*/
#define FT_BIT(n)              (*((uint8_t*)((FT_BIT_BASE + (n)))))
#define RT_BIT(n)              (*((uint8_t*)((RT_BIT_BASE + (n)))))

/** @addtogroup Peripheral_declaration
  * @{
  */
#define RCC                 ((RCC_TypeDef *) RCC_BASE)
#define RCCAHB              ((RCCAHB_TypeDef *) RCCAHB_BASE)
#define RCCAPB0             ((RCCAPB0_TypeDef *) RCCAPB0_BASE)
#define RCCAPB1             ((RCCAPB1_TypeDef *) RCCAPB1_BASE)
#define RCCAPB2             ((RCCAPB2_TypeDef *) RCCAPB2_BASE)
#define UART0               ((UART_TypeDef *) UART0_BASE)
#define UART1               ((UART_TypeDef *) UART1_BASE)
#define UART2               ((UART_TypeDef *) UART2_BASE)
#define UART3               ((UART_TypeDef *) UART3_BASE)
#define UART4               ((UART_TypeDef *) UART4_BASE)
#define UART5               ((UART_TypeDef *) UART5_BASE)
#define SPI0                ((SPI_TypeDef *) SPI0_BASE)
#define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#define SPI2                ((SPI_TypeDef *) SPI2_BASE)
#define TWI0                ((TWI_TypeDef *) TWI0_BASE)
#define TWI1                ((TWI_TypeDef *) TWI1_BASE)
#define TIM0                ((TIM_TypeDef *) TIM0_BASE)
#define TIM1                ((TIM_TypeDef *) TIM1_BASE)
#define TIM2                ((TIM_TypeDef *) TIM2_BASE)
#define TIM3                ((TIM_TypeDef *) TIM3_BASE)
#define TIM4                ((TIM_TypeDef *) TIM4_BASE)
#define TIM5                ((TIM_TypeDef *) TIM5_BASE)
#define TIM6                ((TIM_TypeDef *) TIM6_BASE)
#define TIM7                ((TIM_TypeDef *) TIM7_BASE)
#define PWM0                ((PWM_TypeDef *) PWM0_BASE)
#define LEDPWM              ((LEDPWM_TypeDef *) LEDPWM_BASE)
#define BTM                 ((BTM_TypeDef *) BTM_BASE)
#define ADC                 ((ADC_TypeDef *) ADC_BASE)
#define CMP                 ((CMP_TypeDef *) CMP_BASE)
#define OP                  ((OP_TypeDef *) OP_BASE)
#define TK                  ((TK_TypeDef *) TK_BASE)
#define LCD_LED             ((LCD_LED_TypeDef *) LCD_LED_BASE)
#define INT                ((INT_TypeDef *) INT_BASE)
#define WDT                 ((WDT_TypeDef *) WDT_BASE)
#define IAP                 ((IAP_TypeDef *) IAP_BASE)
#define CRC                 ((CRC_TypeDef *) CRC_BASE)
#define DMA0                ((DMA_TypeDef *) DMA0_BASE)
#define DMA1                ((DMA_TypeDef *) DMA1_BASE)
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOA_BIT           ((GPIO_BIT_TypeDef *) GPIOA_BIT_BASE)
#define GPIOB_BIT           ((GPIO_BIT_TypeDef *) GPIOB_BIT_BASE)
#define GPIOC_BIT           ((GPIO_BIT_TypeDef *) GPIOC_BIT_BASE)

//----------------------------------------------------------
#define OPT                 ((OPT_TypeDef *) OPT_BASE)
//----------------------------------------------------------
/** @addtogroup Peripheral_Registers_Bits_Definition
* @{
*/

/******************************************************************************/
/*                         Peripheral Registers Bits Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                               RCC                                          */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for RCC_CFG0 register  ******************/
#define RCC_CFG0_LXTEN_Pos                (0U)
#define RCC_CFG0_LXTEN_Msk                (0x1UL << RCC_CFG0_LXTEN_Pos)          
#define RCC_CFG0_LXTEN                    RCC_CFG0_LXTEN_Msk
                                       
#define RCC_CFG0_LIRCEN_Pos               (1U)
#define RCC_CFG0_LIRCEN_Msk               (0x1UL << RCC_CFG0_LIRCEN_Pos)          
#define RCC_CFG0_LIRCEN                   RCC_CFG0_LIRCEN_Msk
                                       
#define RCC_CFG0_CRYHF_Pos                (4U)
#define RCC_CFG0_CRYHF_Msk                (0x1UL << RCC_CFG0_CRYHF_Pos)          
#define RCC_CFG0_CRYHF                    RCC_CFG0_CRYHF_Msk
                                       
#define RCC_CFG0_HXTEN_Pos                (5U)
#define RCC_CFG0_HXTEN_Msk                (0x1UL << RCC_CFG0_HXTEN_Pos)          
#define RCC_CFG0_HXTEN                    RCC_CFG0_HXTEN_Msk
                                       
#define RCC_CFG0_HIRCEN_Pos               (6U)
#define RCC_CFG0_HIRCEN_Msk               (0x1UL << RCC_CFG0_HIRCEN_Pos)          
#define RCC_CFG0_HIRCEN                   RCC_CFG0_HIRCEN_Msk
                                                                             
#define RCC_CFG0_SYSCLKSW_Pos             (7U)
#define RCC_CFG0_SYSCLKSW_Msk             (0x1UL << RCC_CFG0_SYSCLKSW_Pos)          
#define RCC_CFG0_SYSCLKSW                 RCC_CFG0_SYSCLKSW_Msk
                                       
#define RCC_CFG0_SYSCLKSEL_Pos            (8U)
#define RCC_CFG0_SYSCLKSEL_Msk            (0x3UL << RCC_CFG0_SYSCLKSEL_Pos)          
#define RCC_CFG0_SYSCLKSEL                RCC_CFG0_SYSCLKSEL_Msk

#define RCC_CFG0_HPLDODP_Pos              (11U)
#define RCC_CFG0_HPLDODP_Msk              (0x1UL << RCC_CFG0_HPLDODP_Pos)         
#define RCC_CFG0_HPLDODP                  RCC_CFG0_HPLDODP_Msk

#define RCC_CFG0_WAIT_Pos                 (12U)
#define RCC_CFG0_WAIT_Msk                 (0x3UL << RCC_CFG0_WAIT_Pos)          
#define RCC_CFG0_WAIT                     RCC_CFG0_WAIT_Msk

#define RCC_CFG0_HIRCDIV1_Pos             (14U)
#define RCC_CFG0_HIRCDIV1_Msk             (0x1UL << RCC_CFG0_HIRCDIV1_Pos)         
#define RCC_CFG0_HIRCDIV1                 RCC_CFG0_HIRCDIV1_Msk

#define RCC_CFG0_INTEN_Pos                (15U)
#define RCC_CFG0_INTEN_Msk                (0x1UL << RCC_CFG0_INTEN_Pos)          
#define RCC_CFG0_INTEN                    RCC_CFG0_INTEN_Msk

/********************  Bit definition for RCC_CFG1 register  ********************/
#define RCC_CFG1_BTMCLKSEL_Pos            (0U)
#define RCC_CFG1_BTMCLKSEL_Msk            (0x1UL << RCC_CFG1_BTMCLKSEL_Pos)          
#define RCC_CFG1_BTMCLKSEL                RCC_CFG1_BTMCLKSEL_Msk
                                       
#define RCC_CFG1_LCDCLKSEL_Pos            (1U)
#define RCC_CFG1_LCDCLKSEL_Msk            (0x1UL << RCC_CFG1_LCDCLKSEL_Pos)          
#define RCC_CFG1_LCDCLKSEL                RCC_CFG1_LCDCLKSEL_Msk

#define RCC_CFG1_PWM0CLKSEL_Pos           (2U)
#define RCC_CFG1_PWM0CLKSEL_Msk           (0x1UL << RCC_CFG1_PWM0CLKSEL_Pos)          
#define RCC_CFG1_PWM0CLKSEL               RCC_CFG1_PWM0CLKSEL_Msk
                                       
#define RCC_CFG1_STCLKSEL_Pos             (5U)
#define RCC_CFG1_STCLKSEL_Msk             (0x7UL << RCC_CFG1_STCLKSEL_Pos)          
#define RCC_CFG1_STCLKSEL                 RCC_CFG1_STCLKSEL_Msk

/********************  Bit definition for RCC_STS register  ********************/ 
#define RCC_STS_CLKFIF_Pos                (0U)
#define RCC_STS_CLKFIF_Msk                (0x1UL << RCC_STS_CLKFIF_Pos)          
#define RCC_STS_CLKFIF                    RCC_STS_CLKFIF_Msk

#define RCC_STS_SRAMPEIF_Pos              (3U)
#define RCC_STS_SRAMPEIF_Msk              (0x1UL << RCC_STS_SRAMPEIF_Pos)          
#define RCC_STS_SRAMPEIF                  RCC_STS_SRAMPEIF_Msk

/********************  Bit definition for NMI_CFG register  ********************/ 
#define NMI_CFG_CSSEN_Pos                 (0U)
#define NMI_CFG_CSSEN_Msk                 (0x1UL << NMI_CFG_CSSEN_Pos)          
#define NMI_CFG_CSSEN                     NMI_CFG_CSSEN_Msk

#define NMI_CFG_CMPEN_Pos                 (1U)
#define NMI_CFG_CMPEN_Msk                 (0x1UL << NMI_CFG_CMPEN_Pos)
#define NMI_CFG_CMPEN                     NMI_CFG_CMPEN_Msk

#define NMI_CFG_INT0EN_Pos                (2U)
#define NMI_CFG_INT0EN_Msk                (0x1UL << NMI_CFG_INT0EN_Pos)
#define NMI_CFG_INT0EN                    NMI_CFG_INT0EN_Msk

#define NMI_CFG_SRAMPEEN_Pos              (3U)
#define NMI_CFG_SRAMPEEN_Msk              (0x1UL << NMI_CFG_SRAMPEEN_Pos)
#define NMI_CFG_SRAMPEEN                  NMI_CFG_SRAMPEEN_Msk

/********************  Bit definition for AHB_CFG register  ********************/
#define AHB_CFG_DMAEN_Pos                 (0U)
#define AHB_CFG_DMAEN_Msk                 (0x1UL << AHB_CFG_DMAEN_Pos)
#define AHB_CFG_DMAEN                     AHB_CFG_DMAEN_Msk

#define AHB_CFG_CRCEN_Pos                 (1U)
#define AHB_CFG_CRCEN_Msk                 (0x1UL << AHB_CFG_CRCEN_Pos)
#define AHB_CFG_CRCEN                     AHB_CFG_CRCEN_Msk

#define AHB_CFG_IFBEN_Pos                 (2U)
#define AHB_CFG_IFBEN_Msk                 (0x1UL << AHB_CFG_IFBEN_Pos)
#define AHB_CFG_IFBEN                    AHB_CFG_IFBEN_Msk

#define AHB_CFG_CLKDIV_Pos                (20U)
#define AHB_CFG_CLKDIV_Msk                (0x7UL << AHB_CFG_CLKDIV_Pos)
#define AHB_CFG_CLKDIV                    AHB_CFG_CLKDIV_Msk

/********************  Bit definition for AHB_RST register  ********************/
#define AHB_RST_DMARST_Pos                (0U)
#define AHB_RST_DMARST_Msk                (0x1UL << AHB_RST_DMARST_Pos)
#define AHB_RST_DMARST                    AHB_RST_DMARST_Msk

#define AHB_RST_CRCRST_Pos                (1U)
#define AHB_RST_CRCRST_Msk                (0x1UL << AHB_RST_CRCRST_Pos)
#define AHB_RST_CRCRST                    AHB_RST_CRCRST_Msk

/********************  Bit definition for APB0_CFG register  ********************/
#define APB0_CFG_TIM0EN_Pos               (0U)
#define APB0_CFG_TIM0EN_Msk               (0x1UL << APB0_CFG_TIM0EN_Pos)
#define APB0_CFG_TIM0EN                   APB0_CFG_TIM0EN_Msk

#define APB0_CFG_TIM1EN_Pos               (1U)
#define APB0_CFG_TIM1EN_Msk               (0x1UL << APB0_CFG_TIM1EN_Pos)
#define APB0_CFG_TIM1EN                   APB0_CFG_TIM1EN_Msk

#define APB0_CFG_TIM2EN_Pos               (2U)
#define APB0_CFG_TIM2EN_Msk               (0x1UL << APB0_CFG_TIM2EN_Pos)          
#define APB0_CFG_TIM2EN                   APB0_CFG_TIM2EN_Msk

#define APB0_CFG_TIM3EN_Pos               (3U)
#define APB0_CFG_TIM3EN_Msk               (0x1UL << APB0_CFG_TIM3EN_Pos)          
#define APB0_CFG_TIM3EN                   APB0_CFG_TIM3EN_Msk

#define APB0_CFG_TWI0EN_Pos               (4U)
#define APB0_CFG_TWI0EN_Msk               (0x1UL << APB0_CFG_TWI0EN_Pos)          
#define APB0_CFG_TWI0EN                   APB0_CFG_TWI0EN_Msk

#define APB0_CFG_SPI0EN_Pos               (5U)
#define APB0_CFG_SPI0EN_Msk               (0x1UL << APB0_CFG_SPI0EN_Pos)          
#define APB0_CFG_SPI0EN                   APB0_CFG_SPI0EN_Msk

#define APB0_CFG_UART0EN_Pos              (6U)
#define APB0_CFG_UART0EN_Msk              (0x1UL << APB0_CFG_UART0EN_Pos)          
#define APB0_CFG_UART0EN                  APB0_CFG_UART0EN_Msk

#define APB0_CFG_UART1EN_Pos              (7U)
#define APB0_CFG_UART1EN_Msk              (0x1UL << APB0_CFG_UART1EN_Pos)          
#define APB0_CFG_UART1EN                  APB0_CFG_UART1EN_Msk

#define APB0_CFG_PWM0EN_Pos               (8U)
#define APB0_CFG_PWM0EN_Msk               (0x1UL << APB0_CFG_PWM0EN_Pos)          
#define APB0_CFG_PWM0EN                   APB0_CFG_PWM0EN_Msk

#define APB0_CFG_UART5EN_Pos              (9U)
#define APB0_CFG_UART5EN_Msk              (0x1UL << APB0_CFG_UART5EN_Pos)          
#define APB0_CFG_UART5EN                  APB0_CFG_UART5EN_Msk

#define APB0_CFG_CLKDIV_Pos               (20U)
#define APB0_CFG_CLKDIV_Msk               (0x7UL << APB0_CFG_CLKDIV_Pos)          
#define APB0_CFG_CLKDIV                   APB0_CFG_CLKDIV_Msk

#define APB0_CFG_ENAPB_Pos                (23U)
#define APB0_CFG_ENAPB_Msk                (0x1UL << APB0_CFG_ENAPB_Pos)          
#define APB0_CFG_ENAPB                    APB0_CFG_ENAPB_Msk

/********************  Bit definition for APB0_RST register  ********************/ 
#define APB0_RST_TIM0RST_Pos              (0U)
#define APB0_RST_TIM0RST_Msk              (0x1UL << APB0_RST_TIM0RST_Pos)          
#define APB0_RST_TIM0RST                  APB0_RST_TIM0RST_Msk

#define APB0_RST_TIM1RST_Pos              (1U)
#define APB0_RST_TIM1RST_Msk              (0x1UL << APB0_RST_TIM1RST_Pos)          
#define APB0_RST_TIM1RST                  APB0_RST_TIM1RST_Msk

#define APB0_RST_TIM2RST_Pos              (2U)
#define APB0_RST_TIM2RST_Msk              (0x1UL << APB0_RST_TIM2RST_Pos)          
#define APB0_RST_TIM2RST                  APB0_RST_TIM2RST_Msk

#define APB0_RST_TIM3RST_Pos              (3U)
#define APB0_RST_TIM3RST_Msk              (0x1UL << APB0_RST_TIM3RST_Pos)          
#define APB0_RST_TIM3RST                  APB0_RST_TIM3RST_Msk

#define APB0_RST_TWI0RST_Pos              (4U)
#define APB0_RST_TWI0RST_Msk              (0x1UL << APB0_RST_TWI0RST_Pos)          
#define APB0_RST_TWI0RST                  APB0_RST_TWI0RST_Msk

#define APB0_RST_SPI0RST_Pos              (5U)
#define APB0_RST_SPI0RST_Msk              (0x1UL << APB0_RST_SPI0RST_Pos)          
#define APB0_RST_SPI0RST                  APB0_RST_SPI0RST_Msk

#define APB0_RST_UART0RST_Pos             (6U)
#define APB0_RST_UART0RST_Msk             (0x1UL << APB0_RST_UART0RST_Pos)          
#define APB0_RST_UART0RST                 APB0_RST_UART0RST_Msk

#define APB0_RST_UART1RST_Pos             (7U)
#define APB0_RST_UART1RST_Msk             (0x1UL << APB0_RST_UART1RST_Pos)          
#define APB0_RST_UART1RST                 APB0_RST_UART1RST_Msk

#define APB0_RST_PWM0RST_Pos              (8U)
#define APB0_RST_PWM0RST_Msk              (0x1UL << APB0_RST_PWM0RST_Pos)          
#define APB0_RST_PWM0RST                  APB0_RST_PWM0RST_Msk

#define APB0_RST_UART5RST_Pos             (9U)
#define APB0_RST_UART5RST_Msk             (0x1UL << APB0_RST_UART5RST_Pos)          
#define APB0_RST_UART5RST                 APB0_RST_UART5RST_Msk

/********************  Bit definition for APB1_CFG register  ********************/ 
#define APB1_CFG_TIM4EN_Pos               (0U)
#define APB1_CFG_TIM4EN_Msk               (0x1UL << APB1_CFG_TIM4EN_Pos)          
#define APB1_CFG_TIM4EN                   APB1_CFG_TIM4EN_Msk

#define APB1_CFG_TIM5EN_Pos               (1U)
#define APB1_CFG_TIM5EN_Msk               (0x1UL << APB1_CFG_TIM5EN_Pos)          
#define APB1_CFG_TIM5EN                   APB1_CFG_TIM5EN_Msk

#define APB1_CFG_TIM6EN_Pos               (2U)
#define APB1_CFG_TIM6EN_Msk               (0x1UL << APB1_CFG_TIM6EN_Pos)          
#define APB1_CFG_TIM6EN                   APB1_CFG_TIM6EN_Msk

#define APB1_CFG_TIM7EN_Pos               (3U)
#define APB1_CFG_TIM7EN_Msk               (0x1UL << APB1_CFG_TIM7EN_Pos)          
#define APB1_CFG_TIM7EN                   APB1_CFG_TIM7EN_Msk

#define APB1_CFG_TWI1EN_Pos               (4U)
#define APB1_CFG_TWI1EN_Msk               (0x1UL << APB1_CFG_TWI1EN_Pos)          
#define APB1_CFG_TWI1EN                   APB1_CFG_TWI1EN_Msk

#define APB1_CFG_SPI1EN_Pos               (5U)
#define APB1_CFG_SPI1EN_Msk               (0x1UL << APB1_CFG_SPI1EN_Pos)          
#define APB1_CFG_SPI1EN                   APB1_CFG_SPI1EN_Msk

#define APB1_CFG_UART4EN_Pos              (6U)
#define APB1_CFG_UART4EN_Msk              (0x1UL << APB1_CFG_UART4EN_Pos)          
#define APB1_CFG_UART4EN                  APB1_CFG_UART4EN_Msk

#define APB1_CFG_UART2EN_Pos              (7U)
#define APB1_CFG_UART2EN_Msk              (0x1UL << APB1_CFG_UART2EN_Pos)          
#define APB1_CFG_UART2EN                  APB1_CFG_UART2EN_Msk

#define APB1_CFG_SPI2EN_Pos               (8U)
#define APB1_CFG_SPI2EN_Msk               (0x1UL << APB1_CFG_SPI2EN_Pos)          
#define APB1_CFG_SPI2EN                   APB1_CFG_SPI2EN_Msk

#define APB1_CFG_CLKDIV_Pos               (20U)
#define APB1_CFG_CLKDIV_Msk               (0x7UL << APB1_CFG_CLKDIV_Pos)          
#define APB1_CFG_CLKDIV                   APB1_CFG_CLKDIV_Msk

#define APB1_CFG_ENAPB_Pos               (23U)
#define APB1_CFG_ENAPB_Msk               (0x1UL << APB1_CFG_ENAPB_Pos)          
#define APB1_CFG_ENAPB                   APB1_CFG_ENAPB_Msk

/********************  Bit definition for APB1_RST register  ********************/ 
#define APB1_RST_TIM4RST_Pos            (0U)
#define APB1_RST_TIM4RST_Msk      (0x1UL << APB1_RST_TIM4RST_Pos)          
#define APB1_RST_TIM4RST               APB1_RST_TIM4RST_Msk

#define APB1_RST_TIM5RST_Pos            (1U)
#define APB1_RST_TIM5RST_Msk      (0x1UL << APB1_RST_TIM5RST_Pos)          
#define APB1_RST_TIM5RST               APB1_RST_TIM5RST_Msk

#define APB1_RST_TIM6RST_Pos            (2U)
#define APB1_RST_TIM6RST_Msk      (0x1UL << APB1_RST_TIM6RST_Pos)          
#define APB1_RST_TIM6RST               APB1_RST_TIM6RST_Msk

#define APB1_RST_TIM7RST_Pos            (3U)
#define APB1_RST_TIM7RST_Msk      (0x1UL << APB1_RST_TIM7RST_Pos)          
#define APB1_RST_TIM7RST               APB1_RST_TIM7RST_Msk

#define APB1_RST_TWI1RST_Pos            (4U)
#define APB1_RST_TWI1RST_Msk      (0x1UL << APB1_RST_TWI1RST_Pos)          
#define APB1_RST_TWI1RST               APB1_RST_TWI1RST_Msk

#define APB1_RST_UART4RST_Pos             (6U)
#define APB1_RST_UART4RST_Msk             (0x1UL << APB1_RST_UART4RST_Pos)          
#define APB1_RST_UART4RST                 APB1_RST_UART4RST_Msk

#define APB1_RST_UART2RST_Pos            (7U)
#define APB1_RST_UART2RST_Msk     (0x1UL << APB1_RST_UART2RST_Pos)          
#define APB1_RST_UART2RST               APB1_RST_UART2RST_Msk

#define APB1_RST_SPI2RST_Pos            (8U)
#define APB1_RST_SPI2RST_Msk         (0x1UL << APB1_RST_SPI2RST_Pos)          
#define APB1_RST_SPI2RST               APB1_RST_SPI2RST_Msk

/********************  Bit definition for APB2_CFG register  ********************/ 
#define APB2_CFG_LEDPWMEN_Pos            (0U)
#define APB2_CFG_LEDPWMEN_Msk      (0x1UL << APB2_CFG_LEDPWMEN_Pos)          
#define APB2_CFG_LEDPWMEN               APB2_CFG_LEDPWMEN_Msk

#define APB2_CFG_LCDEN_Pos             (1U)
#define APB2_CFG_LCDEN_Msk      (0x1UL << APB2_CFG_LCDEN_Pos)          
#define APB2_CFG_LCDEN                  APB2_CFG_LCDEN_Msk

#define APB2_CFG_UART3EN_Pos            (2U)
#define APB2_CFG_UART3EN_Msk     (0x1UL << APB2_CFG_UART3EN_Pos)          
#define APB2_CFG_UART3EN               APB2_CFG_UART3EN_Msk

#define APB2_CFG_CLKDIV_Pos            (20U)
#define APB2_CFG_CLKDIV_Msk      (0x7UL << APB2_CFG_CLKDIV_Pos)          
#define APB2_CFG_CLKDIV               APB2_CFG_CLKDIV_Msk

#define APB2_CFG_ENAPB_Pos             (23U)
#define APB2_CFG_ENAPB_Msk      (0x1UL << APB2_CFG_ENAPB_Pos)          
#define APB2_CFG_ENAPB               APB2_CFG_ENAPB_Msk

/********************  Bit definition for APB2_RST register  ********************/ 
#define APB2_RST_LEDPWMRST_Pos            (0U)
#define APB2_RST_LEDPWMRST_Msk     (0x1UL << APB2_RST_LEDPWMRST_Pos)          
#define APB2_RST_LEDPWMRST              APB2_RST_LEDPWMRST_Msk

#define APB2_RST_LCDRST_Pos            (1U)
#define APB2_RST_LCDRST_Msk      (0x1UL << APB2_RST_LCDRST_Pos)          
#define APB2_RST_LCDRST               APB2_RST_LCDRST_Msk

#define APB2_RST_UART3RST_Pos               (2U)
#define APB2_RST_UART3RST_Msk     (0x1UL << APB2_RST_UART3RST_Pos)          
#define APB2_RST_UART3RST              APB2_RST_UART3RST_Msk

/************private bit *************************************/
#define APB0_CFG_RDMODE_Pos            (31U)
#define APB0_CFG_RDMODE_Msk      (0x1UL << APB0_CFG_RDMODE_Pos)          
#define APB0_CFG_RDMODE               APB0_CFG_RDMODE_Msk

#define APB1_CFG_RDMODE_Pos            (31U)
#define APB1_CFG_RDMODE_Msk      (0x1UL << APB1_CFG_RDMODE_Pos)          
#define APB1_CFG_RDMODE               APB1_CFG_RDMODE_Msk

#define APB2_CFG_RDMODE_Pos            (31U)
#define APB2_CFG_RDMODE_Msk      (0x1UL << APB2_CFG_RDMODE_Pos)          
#define APB2_CFG_RDMODE               APB2_CFG_RDMODE_Msk
/******************************************************************************/
/*                                                                            */
/*                      ADC                                                   */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for ADC_CON register  *******************/ 
#define ADC_CON_ADCIS_Pos                 (0U)
#define ADC_CON_ADCIS_Msk                 (0x1FUL << ADC_CON_ADCIS_Pos)          
#define ADC_CON_ADCIS                     ADC_CON_ADCIS_Msk

#define ADC_CON_ADCS_Pos                  (7U)
#define ADC_CON_ADCS_Msk                  (0x1UL << ADC_CON_ADCS_Pos)          
#define ADC_CON_ADCS                      ADC_CON_ADCS_Msk

#define ADC_CON_INTEN_Pos                 (8U)
#define ADC_CON_INTEN_Msk                 (0x1UL << ADC_CON_INTEN_Pos)          
#define ADC_CON_INTEN                     ADC_CON_INTEN_Msk

#define ADC_CON_CONT_Pos                  (11U)
#define ADC_CON_CONT_Msk                  (0x1UL << ADC_CON_CONT_Pos)          
#define ADC_CON_CONT                      ADC_CON_CONT_Msk

#define ADC_CON_DMAEN_Pos                 (12U)
#define ADC_CON_DMAEN_Msk                 (0x1UL << ADC_CON_DMAEN_Pos)          
#define ADC_CON_DMAEN                     ADC_CON_DMAEN_Msk

#define ADC_CON_ADCEN_Pos                 (15U)
#define ADC_CON_ADCEN_Msk                 (0x1UL << ADC_CON_ADCEN_Pos)          
#define ADC_CON_ADCEN                     ADC_CON_ADCEN_Msk

#define ADC_CON_LOWSP_Pos                 (16U)
#define ADC_CON_LOWSP_Msk                 (0x7UL << ADC_CON_LOWSP_Pos)          
#define ADC_CON_LOWSP                     ADC_CON_LOWSP_Msk

#define ADC_CON_VREFS_Pos                 (20U)
#define ADC_CON_VREFS_Msk                 (0x3UL << ADC_CON_VREFS_Pos)          
#define ADC_CON_VREFS                     ADC_CON_VREFS_Msk
/********************  Bit definition for ADC_STS register  ********************/ 
#define ADC_STS_EOC_Pos                   (0U)
#define ADC_STS_EOC_Msk                   (0x01UL << ADC_STS_EOC_Pos)          
#define ADC_STS_EOC                       ADC_STS_EOC_Msk

/********************  Bit definition for ADC_CFG register  ********************/ 
#define ADC_CFG_AIN0_Pos                  (0U)
#define ADC_CFG_AIN0_Msk                  (0x1L << ADC_CFG_AIN0_Pos)          
#define ADC_CFG_AIN0                      ADC_CFG_AIN0_Msk

#define ADC_CFG_AIN1_Pos                  (1U)
#define ADC_CFG_AIN1_Msk                  (0x1L << ADC_CFG_AIN1_Pos)          
#define ADC_CFG_AIN1                      ADC_CFG_AIN1_Msk

#define ADC_CFG_AIN2_Pos                  (2U)
#define ADC_CFG_AIN2_Msk                  (0x1L << ADC_CFG_AIN2_Pos)          
#define ADC_CFG_AIN2                      ADC_CFG_AIN2_Msk

#define ADC_CFG_AIN3_Pos                  (3U)
#define ADC_CFG_AIN3_Msk                  (0x1L << ADC_CFG_AIN3_Pos)          
#define ADC_CFG_AIN3                      ADC_CFG_AIN3_Msk

#define ADC_CFG_AIN4_Pos                  (4U)
#define ADC_CFG_AIN4_Msk                  (0x1L << ADC_CFG_AIN4_Pos)          
#define ADC_CFG_AIN4                      ADC_CFG_AIN4_Msk

#define ADC_CFG_AIN5_Pos                  (5U)
#define ADC_CFG_AIN5_Msk                  (0x1L << ADC_CFG_AIN5_Pos)          
#define ADC_CFG_AIN5                      ADC_CFG_AIN5_Msk

#define ADC_CFG_AIN6_Pos                  (6U)
#define ADC_CFG_AIN6_Msk                  (0x1L << ADC_CFG_AIN6_Pos)          
#define ADC_CFG_AIN6                      ADC_CFG_AIN6_Msk

#define ADC_CFG_AIN7_Pos                  (7U)
#define ADC_CFG_AIN7_Msk                  (0x1L << ADC_CFG_AIN7_Pos)          
#define ADC_CFG_AIN7                      ADC_CFG_AIN7_Msk

#define ADC_CFG_AIN8_Pos                  (8U)
#define ADC_CFG_AIN8_Msk                  (0x1L << ADC_CFG_AIN8_Pos)          
#define ADC_CFG_AIN8                      ADC_CFG_AIN8_Msk

#define ADC_CFG_AIN9_Pos                  (9U)
#define ADC_CFG_AIN9_Msk                  (0x1L << ADC_CFG_AIN9_Pos)          
#define ADC_CFG_AIN9                      ADC_CFG_AIN9_Msk

#define ADC_CFG_AIN10_Pos                 (10U)
#define ADC_CFG_AIN10_Msk                 (0x1L << ADC_CFG_AIN10_Pos)          
#define ADC_CFG_AIN10                     ADC_CFG_AIN10_Msk

#define ADC_CFG_AIN11_Pos                 (11U)
#define ADC_CFG_AIN11_Msk                 (0x1L << ADC_CFG_AIN11_Pos)          
#define ADC_CFG_AIN11                     ADC_CFG_AIN11_Msk

#define ADC_CFG_AIN12_Pos                 (12U)
#define ADC_CFG_AIN12_Msk                 (0x1L << ADC_CFG_AIN12_Pos)          
#define ADC_CFG_AIN12                     ADC_CFG_AIN12_Msk

#define ADC_CFG_AIN13_Pos                 (13U)
#define ADC_CFG_AIN13_Msk                 (0x1L << ADC_CFG_AIN13_Pos)          
#define ADC_CFG_AIN13                     ADC_CFG_AIN13_Msk

#define ADC_CFG_AIN14_Pos                 (14U)
#define ADC_CFG_AIN14_Msk                 (0x1L << ADC_CFG_AIN14_Pos)          
#define ADC_CFG_AIN14                     ADC_CFG_AIN14_Msk

#define ADC_CFG_AIN15_Pos                 (15U)
#define ADC_CFG_AIN15_Msk                 (0x1L << ADC_CFG_AIN15_Pos)          
#define ADC_CFG_AIN15                     ADC_CFG_AIN15_Msk

#define ADC_CFG_AIN16_Pos                 (16U)
#define ADC_CFG_AIN16_Msk                 (0x1L << ADC_CFG_AIN16_Pos)          
#define ADC_CFG_AIN16                     ADC_CFG_AIN16_Msk

/********************  Bit definition for ADC_ADCV register  ********************/ 
#define ADC_ADCV_OVERRUN_Pos              (31U)
#define ADC_ADCV_OVERRUN_Msk              (0x1L << ADC_ADCV_OVERRUN_Pos)          
#define ADC_ADCV_OVERRUN                  ADC_ADCV_OVERRUN_Msk

#define ADC_ADCV_ADCV_Pos                 (0U)
#define	ADC_ADCV_ADCV_Msk                 (0x3FFFL << ADC_ADCV_ADCV_Pos)          
#define ADC_ADCV_ADCV          			  		ADC_ADCV_ADCV_Msk

/******************************************************************************/
/*                                                                            */
/*                                BTM                                         */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for BTM_CON register  *******************/
#define BTM_CON_BTMFS_Pos                 (0U)
#define BTM_CON_BTMFS_Msk                 (0x0FL << BTM_CON_BTMFS_Pos)          
#define BTM_CON_BTMFS                     BTM_CON_BTMFS_Msk

#define BTM_CON_INTEN_Pos                 (6U)
#define BTM_CON_INTEN_Msk                 (0x1L << BTM_CON_INTEN_Pos)          
#define BTM_CON_INTEN                     BTM_CON_INTEN_Msk

#define BTM_CON_BTMEN_Pos                 (7U)
#define BTM_CON_BTMEN_Msk                 (0x1L << BTM_CON_BTMEN_Pos)          
#define BTM_CON_BTMEN                     BTM_CON_BTMEN_Msk

/********************  Bit definition for BTM_STS register  ********************/
#define BTM_STS_BTMIF_Pos                 (0U)
#define BTM_STS_BTMIF_Msk                 (0x1L << BTM_STS_BTMIF_Pos)          
#define BTM_STS_BTMIF                     BTM_STS_BTMIF_Msk

/******************************************************************************/
/*                                                                            */
/*                                  CMP                                       */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for CMP_CFG register  *******************/
#define CMP_CFG_CMPIS_Pos                 (0U)
#define CMP_CFG_CMPIS_Msk                 (0x7L << CMP_CFG_CMPIS_Pos)          
#define CMP_CFG_CMPIS                     CMP_CFG_CMPIS_Msk

#define CMP_CFG_CMPP_Pos                  (4U)
#define CMP_CFG_CMPP_Msk                  (0x1L << CMP_CFG_CMPP_Pos)          
#define CMP_CFG_CMPP                      CMP_CFG_CMPP_Msk

#define CMP_CFG_CMPIM_Pos                 (5U)
#define CMP_CFG_CMPIM_Msk                 (0x3L << CMP_CFG_CMPIM_Pos)          
#define CMP_CFG_CMPIM                     CMP_CFG_CMPIM_Msk

#define CMP_CFG_CMPEN_Pos                 (7U)
#define CMP_CFG_CMPEN_Msk                 (0x1L << CMP_CFG_CMPEN_Pos)          
#define CMP_CFG_CMPEN                     CMP_CFG_CMPEN_Msk

#define CMP_CFG_CMPRF_Pos                 (8U)
#define CMP_CFG_CMPRF_Msk                 (0x0FL << CMP_CFG_CMPRF_Pos)          
#define CMP_CFG_CMPRF                     CMP_CFG_CMPRF_Msk
/********************  Bit definition for CMP_STS register  ********************/
#define CMP_STS_CMPIF_Pos                 (0U)
#define CMP_STS_CMPIF_Msk                 (0x1L << CMP_STS_CMPIF_Pos)          
#define CMP_STS_CMPIF                     CMP_STS_CMPIF_Msk

#define CMP_STS_CMPSTA_Pos                (1U)
#define CMP_STS_CMPSTA_Msk                (0x1L << CMP_STS_CMPSTA_Pos)          
#define CMP_STS_CMPSTA                    CMP_STS_CMPSTA_Msk
/******************************************************************************/
/*                                                                            */
/*                                 CRC                                        */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for CRC_CON register  *******************/
#define CRC_CON_CRCRST_Pos                (0U)
#define CRC_CON_CRCRST_Msk                (0x1L << CRC_CON_CRCRST_Pos)          
#define CRC_CON_CRCRST                    CRC_CON_CRCRST_Msk

#define CRC_CON_POLYSIZE_Pos              (6U)
#define CRC_CON_POLYSIZE_Msk              (0x3L << CRC_CON_POLYSIZE_Pos)          
#define CRC_CON_POLYSIZE                  CRC_CON_POLYSIZE_Msk
/********************  Bit definition for CRC_INT register  *******************/
#define CRC_INT_INIT_Pos                  (0U)
#define CRC_INT_INIT_Msk                  (0xFFFFFFFFL << CRC_INT_INIT_Pos)          
#define CRC_INT_INIT                      CRC_INT_INIT_Msk

/******************************************************************************/
/*                                                                            */
/*                                DMA                                         */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DMA_CFG register  *******************/
#define DMA_CFG_PL_Pos              (0U)
#define DMA_CFG_PL_Msk       (0x3L << DMA_CFG_PL_Pos)          
#define DMA_CFG_PL               DMA_CFG_PL_Msk

#define DMA_CFG_TXWIDTH_Pos            (2U)
#define DMA_CFG_TXWIDTH_Msk      (0x3L << DMA_CFG_TXWIDTH_Pos)          
#define DMA_CFG_TXWIDTH              DMA_CFG_TXWIDTH_Msk

#define DMA_CFG_CIRC_Pos             (4U)
#define DMA_CFG_CIRC_Msk      (0x1L << DMA_CFG_CIRC_Pos)          
#define DMA_CFG_CIRC               DMA_CFG_CIRC_Msk

#define DMA_CFG_PAUSE_Pos             (5U)
#define DMA_CFG_PAUSE_Msk      (0x1L << DMA_CFG_PAUSE_Pos)          
#define DMA_CFG_PAUSE               DMA_CFG_PAUSE_Msk

#define DMA_CFG_CHRST_Pos             (6U)
#define DMA_CFG_CHRST_Msk      (0x1L << DMA_CFG_CHRST_Pos)          
#define DMA_CFG_CHRST               DMA_CFG_CHRST_Msk

#define DMA_CFG_CHEN_Pos             (7U)
#define DMA_CFG_CHEN_Msk      (0x1L << DMA_CFG_CHEN_Pos)          
#define DMA_CFG_CHEN               DMA_CFG_CHEN_Msk

#define DMA_CFG_DAINC_Pos             (8U)
#define DMA_CFG_DAINC_Msk      (0x3L << DMA_CFG_DAINC_Pos)          
#define DMA_CFG_DAINC              DMA_CFG_DAINC_Msk

#define DMA_CFG_SAINC_Pos             (10U)
#define DMA_CFG_SAINC_Msk      (0x3L << DMA_CFG_SAINC_Pos)          
#define DMA_CFG_SAINC              DMA_CFG_SAINC_Msk

#define DMA_CFG_BURSIZE_Pos            (12U)
#define DMA_CFG_BURSIZE_Msk      (0x7L << DMA_CFG_BURSIZE_Pos)          
#define DMA_CFG_BURSIZE             DMA_CFG_BURSIZE_Msk

#define DMA_CFG_TPTYPE_Pos             (15U)
#define DMA_CFG_TPTYPE_Msk      (0x1L << DMA_CFG_TPTYPE_Pos)          
#define DMA_CFG_TPTYPE             DMA_CFG_TPTYPE_Msk

#define DMA_CFG_INTEN_Pos             (16U)
#define DMA_CFG_INTEN_Msk      (0x1L << DMA_CFG_INTEN_Pos)          
#define DMA_CFG_INTEN             DMA_CFG_INTEN_Msk

#define DMA_CFG_TCIE_Pos             (17U)
#define DMA_CFG_TCIE_Msk      (0x1L << DMA_CFG_TCIE_Pos)          
#define DMA_CFG_TCIE             DMA_CFG_TCIE_Msk

#define DMA_CFG_HTIE_Pos             (18U)
#define DMA_CFG_HTIE_Msk      (0x1L << DMA_CFG_HTIE_Pos)          
#define DMA_CFG_HTIE             DMA_CFG_HTIE_Msk

#define DMA_CFG_TEIE_Pos             (19U)
#define DMA_CFG_TEIE_Msk      (0x1L << DMA_CFG_TEIE_Pos)          
#define DMA_CFG_TEIE             DMA_CFG_TEIE_Msk

#define DMA_CFG_CHRQ_Pos             (23U)
#define DMA_CFG_CHRQ_Msk      (0x1L << DMA_CFG_CHRQ_Pos)          
#define DMA_CFG_CHRQ             DMA_CFG_CHRQ_Msk


#define DMA_CFG_REQSRC_Pos             (24U)
#define DMA_CFG_REQSRC_Msk      (0x3FL << DMA_CFG_REQSRC_Pos)          
#define DMA_CFG_REQSRC             DMA_CFG_REQSRC_Msk

/********************  Bit definition for DMA_STS register  ********************/
#define DMA_STS_GIF_Pos             (0U)
#define DMA_STS_GIF_Msk       (0x1L << DMA_STS_GIF_Pos)          
#define DMA_STS_GIF              DMA_STS_GIF_Msk

#define DMA_STS_TCIF_Pos             (1U)
#define DMA_STS_TCIF_Msk      (0x1L << DMA_STS_TCIF_Pos)          
#define DMA_STS_TCIF             DMA_STS_TCIF_Msk

#define DMA_STS_HTIF_Pos             (2U)
#define DMA_STS_HTIF_Msk      (0x1L << DMA_STS_HTIF_Pos)          
#define DMA_STS_HTIF             DMA_STS_HTIF_Msk

#define DMA_STS_TEIF_Pos             (3U)
#define DMA_STS_TEIF_Msk      (0x1L << DMA_STS_TEIF_Pos)          
#define DMA_STS_TEIF             DMA_STS_TEIF_Msk

#define DMA_STS_STATUS_Pos             (4U)
#define DMA_STS_STATUS_Msk      (0x0FL << DMA_STS_STATUS_Pos)          
#define DMA_STS_STATUS             DMA_STS_STATUS_Msk

#define DMA_STS_SWREQ_Pos             (8U)
#define DMA_STS_SWREQ_Msk      (0x1L << DMA_STS_SWREQ_Pos)          
#define DMA_STS_SWREQ            DMA_STS_SWREQ_Msk

/******************************************************************************/
/*                                                                            */
/*                      IAP                                                   */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for IAP_CON register  *******************/
#define IAP_CON_CMD_Pos                   (0U)
#define IAP_CON_CMD_Msk                   (0x3L << IAP_CON_CMD_Pos)          
#define IAP_CON_CMD                       IAP_CON_CMD_Msk

#define IAP_CON_PRG_Pos                   (4U)
#define IAP_CON_PRG_Msk                   (0x1L << IAP_CON_PRG_Pos)          
#define IAP_CON_PRG                       IAP_CON_PRG_Msk

#define IAP_CON_SERASE_Pos                (5U)
#define IAP_CON_SERASE_Msk                (0x1L << IAP_CON_SERASE_Pos)          
#define IAP_CON_SERASE                    IAP_CON_SERASE_Msk

#define IAP_CON_ERASE_Pos                 (7U)
#define IAP_CON_ERASE_Msk                 (0x1L << IAP_CON_ERASE_Pos)          
#define IAP_CON_ERASE                     IAP_CON_ERASE_Msk

#define IAP_CON_RST_Pos                   (8U)
#define IAP_CON_RST_Msk                   (0x1L << IAP_CON_RST_Pos)          
#define IAP_CON_RST                       IAP_CON_RST_Msk

#define IAP_CON_BTLD_Pos                  (9U)
#define IAP_CON_BTLD_Msk                  (0x3L << IAP_CON_BTLD_Pos)          
#define IAP_CON_BTLD                      IAP_CON_BTLD_Msk

#define IAP_CON_LOCK_Pos         					(31)
#define	IAP_CON_LOCK_Msk									(0x1UL << IAP_CON_LOCK_Pos)        
#define IAP_CON_LOCK         							IAP_CON_LOCK_Msk
/******************************************************************************/
/*                                                                            */
/*                      INT                                                  */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for INT_FIE register  ******************/
#define INT_FIE_ENF0_Pos             (0U)
#define INT_FIE_ENF0_Msk      (0x1L << INT_FIE_ENF0_Pos)          
#define INT_FIE_ENF0               INT_FIE_ENF0_Msk

#define INT_FIE_ENF1_Pos             (1U)
#define INT_FIE_ENF1_Msk      (0x1L << INT_FIE_ENF1_Pos)          
#define INT_FIE_ENF1               INT_FIE_ENF1_Msk

#define INT_FIE_ENF2_Pos             (2U)
#define INT_FIE_ENF2_Msk      (0x1L << INT_FIE_ENF2_Pos)          
#define INT_FIE_ENF2               INT_FIE_ENF2_Msk

#define INT_FIE_ENF3_Pos             (3U)
#define INT_FIE_ENF3_Msk      (0x1L << INT_FIE_ENF3_Pos)          
#define INT_FIE_ENF3               INT_FIE_ENF3_Msk

#define INT_FIE_ENF4_Pos             (4U)
#define INT_FIE_ENF4_Msk      (0x1L << INT_FIE_ENF4_Pos)          
#define INT_FIE_ENF4               INT_FIE_ENF4_Msk

#define INT_FIE_ENF5_Pos             (5U)
#define INT_FIE_ENF5_Msk      (0x1L << INT_FIE_ENF5_Pos)          
#define INT_FIE_ENF5               INT_FIE_ENF5_Msk

#define INT_FIE_ENF6_Pos             (6U)
#define INT_FIE_ENF6_Msk      (0x1L << INT_FIE_ENF6_Pos)          
#define INT_FIE_ENF6               INT_FIE_ENF6_Msk

#define INT_FIE_ENF7_Pos             (7U)
#define INT_FIE_ENF7_Msk      (0x1L << INT_FIE_ENF7_Pos)          
#define INT_FIE_ENF7               INT_FIE_ENF7_Msk

#define INT_FIE_ENF8_Pos             (8U)
#define INT_FIE_ENF8_Msk      (0x1L << INT_FIE_ENF8_Pos)          
#define INT_FIE_ENF8               INT_FIE_ENF8_Msk

#define INT_FIE_ENF9_Pos             (9U)
#define INT_FIE_ENF9_Msk      (0x1L << INT_FIE_ENF9_Pos)          
#define INT_FIE_ENF9               INT_FIE_ENF9_Msk

#define INT_FIE_ENF10_Pos             (10U)
#define INT_FIE_ENF10_Msk      (0x1L << INT_FIE_ENF10_Pos)          
#define INT_FIE_ENF10              INT_FIE_ENF10_Msk

#define INT_FIE_ENF11_Pos             (11U)
#define INT_FIE_ENF11_Msk      (0x1L << INT_FIE_ENF11_Pos)          
#define INT_FIE_ENF11              INT_FIE_ENF11_Msk

#define INT_FIE_ENF12_Pos             (12U)
#define INT_FIE_ENF12_Msk      (0x1L << INT_FIE_ENF12_Pos)          
#define INT_FIE_ENF12              INT_FIE_ENF12_Msk

#define INT_FIE_ENF13_Pos             (13U)
#define INT_FIE_ENF13_Msk      (0x1L << INT_FIE_ENF13_Pos)          
#define INT_FIE_ENF13              INT_FIE_ENF13_Msk

#define INT_FIE_ENF14_Pos             (14U)
#define INT_FIE_ENF14_Msk      (0x1L << INT_FIE_ENF14_Pos)          
#define INT_FIE_ENF14              INT_FIE_ENF14_Msk

#define INT_FIE_ENF15_Pos             (15U)
#define INT_FIE_ENF15_Msk      (0x1L << INT_FIE_ENF15_Pos)          
#define INT_FIE_ENF15              INT_FIE_ENF15_Msk
/********************  Bit definition for INT_RIE register  ********************/
#define INT_RIE_ENR0_Pos             (0U)
#define INT_RIE_ENR0_Msk      (0x1L << INT_RIE_ENR0_Pos)          
#define INT_RIE_ENR0               INT_RIE_ENR0_Msk

#define INT_RIE_ENR1_Pos             (1U)
#define INT_RIE_ENR1_Msk      (0x1L << INT_RIE_ENR1_Pos)          
#define INT_RIE_ENR1               INT_RIE_ENR1_Msk

#define INT_RIE_ENR2_Pos             (2U)
#define INT_RIE_ENR2_Msk      (0x1L << INT_RIE_ENR2_Pos)          
#define INT_RIE_ENR2               INT_RIE_ENR2_Msk

#define INT_RIE_ENR3_Pos             (3U)
#define INT_RIE_ENR3_Msk      (0x1L << INT_RIE_ENR3_Pos)          
#define INT_RIE_ENR3               INT_RIE_ENR3_Msk

#define INT_RIE_ENR4_Pos             (4U)
#define INT_RIE_ENR4_Msk      (0x1L << INT_RIE_ENR4_Pos)          
#define INT_RIE_ENR4               INT_RIE_ENR4_Msk

#define INT_RIE_ENR5_Pos                 (5U)
#define INT_RIE_ENR5_Msk                 (0x1L << INT_RIE_ENR5_Pos)          
#define INT_RIE_ENR5                  INT_RIE_ENR5_Msk

#define INT_RIE_ENR6_Pos             (6U)
#define INT_RIE_ENR6_Msk      (0x1L << INT_RIE_ENR6_Pos)          
#define INT_RIE_ENR6               INT_RIE_ENR6_Msk

#define INT_RIE_ENR7_Pos             (7U)
#define INT_RIE_ENR7_Msk      (0x1L << INT_RIE_ENR7_Pos)          
#define INT_RIE_ENR7               INT_RIE_ENR7_Msk

#define INT_RIE_ENR8_Pos             (8U)
#define INT_RIE_ENR8_Msk      (0x1L << INT_RIE_ENR8_Pos)          
#define INT_RIE_ENR8               INT_RIE_ENR8_Msk

#define INT_RIE_ENR9_Pos             (9U)
#define INT_RIE_ENR9_Msk      (0x1L << INT_RIE_ENR9_Pos)          
#define INT_RIE_ENR9               INT_RIE_ENR9_Msk

#define INT_RIE_ENR10_Pos             (10U)
#define INT_RIE_ENR10_Msk      (0x1L << INT_RIE_ENR10_Pos)          
#define INT_RIE_ENR10              INT_RIE_ENR10_Msk

#define INT_RIE_ENR11_Pos             (11U)
#define INT_RIE_ENR11_Msk      (0x1L << INT_RIE_ENR11_Pos)          
#define INT_RIE_ENR11              INT_RIE_ENR11_Msk

#define INT_RIE_ENR12_Pos             (12U)
#define INT_RIE_ENR12_Msk      (0x1L << INT_RIE_ENR12_Pos)          
#define INT_RIE_ENR12              INT_RIE_ENR12_Msk

#define INT_RIE_ENR13_Pos             (13U)
#define INT_RIE_ENR13_Msk      (0x1L << INT_RIE_ENR13_Pos)          
#define INT_RIE_ENR13              INT_RIE_ENR13_Msk

#define INT_RIE_ENR14_Pos             (14U)
#define INT_RIE_ENR14_Msk      (0x1L << INT_RIE_ENR14_Pos)          
#define INT_RIE_ENR14              INT_RIE_ENR14_Msk

#define INT_RIE_ENR15_Pos             (15U)
#define INT_RIE_ENR15_Msk      (0x1L << INT_RIE_ENR15_Pos)          
#define INT_RIE_ENR15              INT_RIE_ENR15_Msk

/********************  Bit definition for INT_SEL0 register  ********************/
#define INT_SEL0_INT0SEL_Pos               (0U)
#define INT_SEL0_INT0SEL_Msk     (0x0FL << INT_SEL0_INT0SEL_Pos)          
#define INT_SEL0_INT0SEL              INT_SEL0_INT0SEL_Msk

#define INT_SEL0_INT1SEL_Pos                   (4U)
#define INT_SEL0_INT1SEL_Msk     (0x0FL << INT_SEL0_INT1SEL_Pos)          
#define INT_SEL0_INT1SEL              INT_SEL0_INT1SEL_Msk

#define INT_SEL0_INT2SEL_Pos               (8U)
#define INT_SEL0_INT2SEL_Msk               (0x0FL << INT_SEL0_INT2SEL_Pos)          
#define INT_SEL0_INT2SEL              INT_SEL0_INT2SEL_Msk

#define INT_SEL0_INT3SEL_Pos               (12U)
#define INT_SEL0_INT3SEL_Msk               (0x0FL << INT_SEL0_INT3SEL_Pos)          
#define INT_SEL0_INT3SEL              INT_SEL0_INT3SEL_Msk

#define INT_SEL0_INT4SEL_Pos               (16U)
#define INT_SEL0_INT4SEL_Msk               (0x0FL << INT_SEL0_INT4SEL_Pos)          
#define INT_SEL0_INT4SEL              INT_SEL0_INT4SEL_Msk

#define INT_SEL0_INT5SEL_Pos               (20U)
#define INT_SEL0_INT5SEL_Msk               (0x0FL << INT_SEL0_INT5SEL_Pos)          
#define INT_SEL0_INT5SEL              INT_SEL0_INT5SEL_Msk

#define INT_SEL0_INT6SEL_Pos               (24U)
#define INT_SEL0_INT6SEL_Msk               (0x0FL << INT_SEL0_INT6SEL_Pos)          
#define INT_SEL0_INT6SEL              INT_SEL0_INT6SEL_Msk

#define INT_SEL0_INT7SEL_Pos               (28U)
#define INT_SEL0_INT7SEL_Msk               (0x0FL << INT_SEL0_INT7SEL_Pos)          
#define INT_SEL0_INT7SEL              INT_SEL0_INT7SEL_Msk

/********************  Bit definition for INT_SEL1 register  ********************/
#define INT_SEL1_INT8SEL_Pos               (0U)
#define INT_SEL1_INT8SEL_Msk               (0x0FL << INT_SEL1_INT8SEL_Pos)          
#define INT_SEL1_INT8SEL              INT_SEL1_INT8SEL_Msk

#define INT_SEL1_INT9SEL_Pos               (4U)
#define INT_SEL1_INT9SEL_Msk               (0x0FL << INT_SEL1_INT9SEL_Pos)          
#define INT_SEL1_INT9SEL              INT_SEL1_INT9SEL_Msk

#define INT_SEL1_INT10SEL_Pos               (8U)
#define INT_SEL1_INT10SEL_Msk               (0x0FL << INT_SEL1_INT10SEL_Pos)          
#define INT_SEL1_INT10SEL             INT_SEL1_INT10SEL_Msk

#define INT_SEL1_INT11SEL_Pos               (12U)
#define INT_SEL1_INT11SEL_Msk               (0x0FL << INT_SEL1_INT11SEL_Pos)          
#define INT_SEL1_INT11SEL             INT_SEL1_INT11SEL_Msk

#define INT_SEL1_INT12SEL_Pos               (16U)
#define INT_SEL1_INT12SEL_Msk               (0x0FL << INT_SEL1_INT12SEL_Pos)          
#define INT_SEL1_INT12SEL             INT_SEL1_INT12SEL_Msk

#define INT_SEL1_INT13SEL_Pos               (20U)
#define INT_SEL1_INT13SEL_Msk               (0x0FL << INT_SEL1_INT13SEL_Pos)          
#define INT_SEL1_INT13SEL             INT_SEL1_INT13SEL_Msk

#define INT_SEL1_INT14SEL_Pos               (24U)
#define INT_SEL1_INT14SEL_Msk               (0x0FL << INT_SEL1_INT14SEL_Pos)          
#define INT_SEL1_INT14SEL             INT_SEL1_INT14SEL_Msk

#define INT_SEL1_INT15SEL_Pos               (28U)
#define INT_SEL1_INT15SEL_Msk               (0x0FL << INT_SEL1_INT15SEL_Pos)          
#define INT_SEL1_INT15SEL             INT_SEL1_INT15SEL_Msk


/********************  Bit definition for INT_FCON register  ********************/
#define INT_FCON_FT0_Pos                 (0U)
#define INT_FCON_FT0_Msk                 (0x1L << INT_FCON_FT0_Pos)          
#define INT_FCON_FT0                     INT_FCON_FT0_Msk

#define INT_FCON_FT1_Pos                 (1U)
#define INT_FCON_FT1_Msk                 (0x1L << INT_FCON_FT1_Pos)          
#define INT_FCON_FT1                     INT_FCON_FT1_Msk

#define INT_FCON_FT2_Pos                 (2U)
#define INT_FCON_FT2_Msk                 (0x1L << INT_FCON_FT2_Pos)          
#define INT_FCON_FT2                INT_FCON_FT2_Msk

#define INT_FCON_FT3_Pos                 (3U)
#define INT_FCON_FT3_Msk                 (0x1L << INT_FCON_FT3_Pos)          
#define INT_FCON_FT3                INT_FCON_FT3_Msk

#define INT_FCON_FT4_Pos             (4U)
#define INT_FCON_FT4_Msk                       (0x1L << INT_FCON_FT4_Pos)          
#define INT_FCON_FT4                INT_FCON_FT4_Msk

#define INT_FCON_FT5_Pos             (5U)
#define INT_FCON_FT5_Msk                       (0x1L << INT_FCON_FT5_Pos)          
#define INT_FCON_FT5                INT_FCON_FT5_Msk

#define INT_FCON_FT6_Pos             (6U)
#define INT_FCON_FT6_Msk                       (0x1L << INT_FCON_FT6_Pos)          
#define INT_FCON_FT6                INT_FCON_FT6_Msk

#define INT_FCON_FT7_Pos             (7U)
#define INT_FCON_FT7_Msk                       (0x1L << INT_FCON_FT7_Pos)          
#define INT_FCON_FT                INT_FCON_FT7_Msk

#define INT_FCON_FT8_Pos             (8U)
#define INT_FCON_FT8_Msk                       (0x1L << INT_FCON_FT8_Pos)          
#define INT_FCON_FT8                INT_FCON_FT8_Msk

#define INT_FCON_FT9_Pos             (9U)
#define INT_FCON_FT9_Msk                       (0x1L << INT_FCON_FT9_Pos)          
#define INT_FCON_FT9                INT_FCON_FT9_Msk

#define INT_FCON_FT10_Pos             (10U)
#define INT_FCON_FT10_Msk                      (0x1L << INT_FCON_FT10_Pos)          
#define INT_FCON_FT10               INT_FCON_FT10_Msk

#define INT_FCON_FT11_Pos             (11U)
#define INT_FCON_FT11_Msk                      (0x1L << INT_FCON_FT11_Pos)          
#define INT_FCON_FT11               INT_FCON_FT11_Msk

#define INT_FCON_FT12_Pos             (12U)
#define INT_FCON_FT12_Msk                      (0x1L << INT_FCON_FT12_Pos)          
#define INT_FCON_FT12               INT_FCON_FT12_Msk

#define INT_FCON_FT13_Pos             (13U)
#define INT_FCON_FT13_Msk                      (0x1L << INT_FCON_FT13_Pos)          
#define INT_FCON_FT13               INT_FCON_FT13_Msk

#define INT_FCON_FT14_Pos             (14U)
#define INT_FCON_FT14_Msk                      (0x1L << INT_FCON_FT14_Pos)          
#define INT_FCON_FT14               INT_FCON_FT14_Msk

#define INT_FCON_FT15_Pos             (15U)
#define INT_FCON_FT15_Msk                      (0x1L << INT_FCON_FT15_Pos)          
#define INT_FCON_FT15               INT_FCON_FT15_Msk

/********************  Bit definition for INT_RCON register  ********************/
#define INT_RCON_RT0_Pos             (0U)
#define INT_RCON_RT0_Msk             (0x1L << INT_RCON_RT0_Pos)          
#define INT_RCON_RT0               INT_RCON_RT0_Msk

#define INT_RCON_RT1_Pos             (1U)
#define INT_RCON_RT1_Msk                       (0x1L << INT_RCON_RT1_Pos)          
#define INT_RCON_RT1                           INT_RCON_RT1_Msk

#define INT_RCON_RT2_Pos             (2U)
#define INT_RCON_RT2_Msk             (0x1L << INT_RCON_RT2_Pos)          
#define INT_RCON_RT2                 INT_RCON_RT2_Msk

#define INT_RCON_RT3_Pos             (3U)
#define INT_RCON_RT3_Msk             (0x1L << INT_RCON_RT3_Pos)          
#define INT_RCON_RT3                INT_RCON_RT3_Msk

#define INT_RCON_RT4_Pos             (4U)
#define INT_RCON_RT4_Msk             (0x1L << INT_RCON_RT4_Pos)          
#define INT_RCON_RT4                INT_RCON_RT4_Msk

#define INT_RCON_RT5_Pos             (5U)
#define INT_RCON_RT5_Msk             (0x1L << INT_RCON_RT5_Pos)          
#define INT_RCON_RT5                INT_RCON_RT5_Msk

#define INT_RCON_RT6_Pos             (6U)
#define INT_RCON_RT6_Msk             (0x1L << INT_RCON_RT6_Pos)          
#define INT_RCON_RT6                INT_RCON_RT6_Msk

#define INT_RCON_RT7_Pos             (7U)
#define INT_RCON_RT7_Msk             (0x1L << INT_RCON_RT7_Pos)          
#define INT_RCON_RT                INT_RCON_RT7_Msk

#define INT_RCON_RT8_Pos             (8U)
#define INT_RCON_RT8_Msk             (0x1L << INT_RCON_RT8_Pos)          
#define INT_RCON_RT8                INT_RCON_RT8_Msk

#define INT_RCON_RT9_Pos             (9U)
#define INT_RCON_RT9_Msk         (0x1L << INT_RCON_RT9_Pos)          
#define INT_RCON_RT9                INT_RCON_RT9_Msk

#define INT_RCON_RT10_Pos             (10U)
#define INT_RCON_RT10_Msk        (0x1L << INT_RCON_RT10_Pos)          
#define INT_RCON_RT10               INT_RCON_RT10_Msk

#define INT_RCON_RT11_Pos             (11U)
#define INT_RCON_RT11_Msk        (0x1L << INT_RCON_RT11_Pos)          
#define INT_RCON_RT11               INT_RCON_RT11_Msk

#define INT_RCON_RT12_Pos             (12U)
#define INT_RCON_RT12_Msk        (0x1L << INT_RCON_RT12_Pos)          
#define INT_RCON_RT12               INT_RCON_RT12_Msk

#define INT_RCON_RT13_Pos             (13U)
#define INT_RCON_RT13_Msk        (0x1L << INT_RCON_RT13_Pos)          
#define INT_RCON_RT13               INT_RCON_RT13_Msk

#define INT_RCON_RT14_Pos             (14U)
#define INT_RCON_RT14_Msk      (0x1L << INT_RCON_RT14_Pos)          
#define INT_RCON_RT14               INT_RCON_RT14_Msk

#define INT_RCON_RT15_Pos             (15U)
#define INT_RCON_RT15_Msk        (0x1L << INT_RCON_RT15_Pos)          
#define INT_RCON_RT15               INT_RCON_RT15_Msk

/********************  Bit definition for INT_FSTS register  ********************/
#define INT_FSTS_FIF0_Pos             (0U)
#define INT_FSTS_FIF0_Msk      (0x1L << INT_FSTS_FIF0_Pos)          
#define INT_FSTS_FIF0              INT_FSTS_FIF0_Msk

#define INT_FSTS_FIF1_Pos             (1U)
#define INT_FSTS_FIF1_Msk      (0x1L << INT_FSTS_FIF1_Pos)          
#define INT_FSTS_FIF1              INT_FSTS_FIF1_Msk

#define INT_FSTS_FIF2_Pos             (2U)
#define INT_FSTS_FIF2_Msk      (0x1L << INT_FSTS_FIF2_Pos)          
#define INT_FSTS_FIF2              INT_FSTS_FIF2_Msk

#define INT_FSTS_FIF3_Pos             (3U)
#define INT_FSTS_FIF3_Msk      (0x1L << INT_FSTS_FIF3_Pos)          
#define INT_FSTS_FIF3              INT_FSTS_FIF3_Msk

#define INT_FSTS_FIF4_Pos             (4U)
#define INT_FSTS_FIF4_Msk      (0x1L << INT_FSTS_FIF4_Pos)          
#define INT_FSTS_FIF4              INT_FSTS_FIF4_Msk

#define INT_FSTS_FIF5_Pos             (5U)
#define INT_FSTS_FIF5_Msk      (0x1L << INT_FSTS_FIF5_Pos)          
#define INT_FSTS_FIF5              INT_FSTS_FIF5_Msk

#define INT_FSTS_FIF6_Pos             (6U)
#define INT_FSTS_FIF6_Msk      (0x1L << INT_FSTS_FIF6_Pos)          
#define INT_FSTS_FIF6              INT_FSTS_FIF6_Msk

#define INT_FSTS_FIF7_Pos             (7U)
#define INT_FSTS_FIF7_Msk      (0x1L << INT_FSTS_FIF7_Pos)          
#define INT_FSTS_FIF               INT_FSTS_FIF7_Msk

#define INT_FSTS_FIF8_Pos             (8U)
#define INT_FSTS_FIF8_Msk        (0x1L << INT_FSTS_FIF8_Pos)          
#define INT_FSTS_FIF8               INT_FSTS_FIF8_Msk

#define INT_FSTS_FIF9_Pos             (9U)
#define INT_FSTS_FIF9_Msk        (0x1L << INT_FSTS_FIF9_Pos)          
#define INT_FSTS_FIF9               INT_FSTS_FIF9_Msk

#define INT_FSTS_FIF10_Pos            (10U)
#define INT_FSTS_FIF10_Msk        (0x1L << INT_FSTS_FIF10_Pos)          
#define INT_FSTS_FIF10               INT_FSTS_FIF10_Msk

#define INT_FSTS_FIF11_Pos            (11U)
#define INT_FSTS_FIF11_Msk        (0x1L << INT_FSTS_FIF11_Pos)          
#define INT_FSTS_FIF11               INT_FSTS_FIF11_Msk

#define INT_FSTS_FIF12_Pos            (12U)
#define INT_FSTS_FIF12_Msk        (0x1L << INT_FSTS_FIF12_Pos)          
#define INT_FSTS_FIF12               INT_FSTS_FIF12_Msk

#define INT_FSTS_FIF13_Pos            (13U)
#define INT_FSTS_FIF13_Msk        (0x1L << INT_FSTS_FIF13_Pos)          
#define INT_FSTS_FIF13               INT_FSTS_FIF13_Msk

#define INT_FSTS_FIF14_Pos            (14U)
#define INT_FSTS_FIF14_Msk        (0x1L << INT_FSTS_FIF14_Pos)          
#define INT_FSTS_FIF14               INT_FSTS_FIF14_Msk

#define INT_FSTS_FIF15_Pos            (15U)
#define INT_FSTS_FIF15_Msk        (0x1L << INT_FSTS_FIF15_Pos)          
#define INT_FSTS_FIF15               INT_FSTS_FIF15_Msk

/********************  Bit definition for INT_RSTS register  ********************/
#define INT_RSTS_RIF0_Pos             (0U)
#define INT_RSTS_RIF0_Msk      (0x1L << INT_RSTS_RIF0_Pos)          
#define INT_RSTS_RIF0              INT_RSTS_RIF0_Msk

#define INT_RSTS_RIF1_Pos             (1U)
#define INT_RSTS_RIF1_Msk      (0x1L << INT_RSTS_RIF1_Pos)          
#define INT_RSTS_RIF1              INT_RSTS_RIF1_Msk

#define INT_RSTS_RIF2_Pos             (2U)
#define INT_RSTS_RIF2_Msk      (0x1L << INT_RSTS_RIF2_Pos)          
#define INT_RSTS_RIF2              INT_RSTS_RIF2_Msk

#define INT_RSTS_RIF3_Pos             (3U)
#define INT_RSTS_RIF3_Msk      (0x1L << INT_RSTS_RIF3_Pos)          
#define INT_RSTS_RIF3              INT_RSTS_RIF3_Msk

#define INT_RSTS_RIF4_Pos             (4U)
#define INT_RSTS_RIF4_Msk      (0x1L << INT_RSTS_RIF4_Pos)          
#define INT_RSTS_RIF4              INT_RSTS_RIF4_Msk

#define INT_RSTS_RIF5_Pos             (5U)
#define INT_RSTS_RIF5_Msk      (0x1L << INT_RSTS_RIF5_Pos)          
#define INT_RSTS_RIF5              INT_RSTS_RIF5_Msk

#define INT_RSTS_RIF6_Pos             (6U)
#define INT_RSTS_RIF6_Msk      (0x1L << INT_RSTS_RIF6_Pos)          
#define INT_RSTS_RIF6              INT_RSTS_RIF6_Msk

#define INT_RSTS_RIF7_Pos             (7U)
#define INT_RSTS_RIF7_Msk      (0x1L << INT_RSTS_RIF7_Pos)          
#define INT_RSTS_RIF7               INT_RSTS_RIF7_Msk

#define INT_RSTS_RIF8_Pos             (8U)
#define INT_RSTS_RIF8_Msk      (0x1L << INT_RSTS_RIF8_Pos)          
#define INT_RSTS_RIF8              INT_RSTS_RIF8_Msk

#define INT_RSTS_RIF9_Pos             (9U)
#define INT_RSTS_RIF9_Msk      (0x1L << INT_RSTS_RIF9_Pos)          
#define INT_RSTS_RIF9              INT_RSTS_RIF9_Msk

#define INT_RSTS_RIF10_Pos            (10U)
#define INT_RSTS_RIF10_Msk      (0x1L << INT_RSTS_RIF10_Pos)          
#define INT_RSTS_RIF10              INT_RSTS_RIF10_Msk

#define INT_RSTS_RIF11_Pos            (11U)
#define INT_RSTS_RIF11_Msk      (0x1L << INT_RSTS_RIF11_Pos)          
#define INT_RSTS_RIF11              INT_RSTS_RIF11_Msk

#define INT_RSTS_RIF12_Pos            (12U)
#define INT_RSTS_RIF12_Msk      (0x1L << INT_RSTS_RIF12_Pos)          
#define INT_RSTS_RIF12              INT_RSTS_RIF12_Msk

#define INT_RSTS_RIF13_Pos           (13U)
#define INT_RSTS_RIF13_Msk        (0x1L << INT_RSTS_RIF13_Pos)          
#define INT_RSTS_RIF13              INT_RSTS_RIF13_Msk

#define INT_RSTS_RIF14_Pos             (14U)
#define INT_RSTS_RIF14_Msk        (0x1L << INT_RSTS_RIF14_Pos)          
#define INT_RSTS_RIF14                 INT_RSTS_RIF14_Msk

#define INT_RSTS_RIF15_Pos            (15U)
#define INT_RSTS_RIF15_Msk         (0x1L << INT_RSTS_RIF15_Pos)          
#define INT_RSTS_RIF15              INT_RSTS_RIF15_Msk
/******************************************************************************/
/*                                                                            */
/*                             LCD                                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DDR_CON register  *******************/
#define DDR_CON_DMOD_Pos              (0U)
#define DDR_CON_DMOD_Msk                  (0x1L << DDR_CON_DMOD_Pos)          
#define DDR_CON_DMOD                DDR_CON_DMOD_Msk

#define DDR_CON_BIAS_Pos              (1U)
#define DDR_CON_BIAS_Msk                  (0x1L << DDR_CON_BIAS_Pos)          
#define DDR_CON_BIAS                DDR_CON_BIAS_Msk

#define DDR_CON_VOIRSF_Pos                (3U)
#define DDR_CON_VOIRSF_Msk          (0x1L << DDR_CON_VOIRSF_Pos)          
#define DDR_CON_VOIRSF               DDR_CON_VOIRSF_Msk

#define DDR_CON_TYPE_Pos              (4U)
#define DDR_CON_TYPE_Msk                  (0x1L << DDR_CON_TYPE_Pos)          
#define DDR_CON_TYPE                DDR_CON_TYPE_Msk

#define DDR_CON_DDRON_Pos             (7U)
#define DDR_CON_DDRON_Msk           (0x1L << DDR_CON_DDRON_Pos)          
#define DDR_CON_DDRON                DDR_CON_DDRON_Msk

#define DDR_CON_DDRCK_Pos              (8U)
#define DDR_CON_DDRCK_Msk           (0x3L << DDR_CON_DDRCK_Pos)          
#define DDR_CON_DDRCK                DDR_CON_DDRCK_Msk

#define DDR_CON_TRICOM_Pos              (14U)
#define DDR_CON_TRICOM_Msk         (0x1L << DDR_CON_TRICOM_Pos)          
#define DDR_CON_TRICOM               DDR_CON_TRICOM_Msk

#define DDR_CON_TRIMODE_Pos            (15U)
#define DDR_CON_TRIMODE_Msk         (0x1L << DDR_CON_TRIMODE_Pos)          
#define DDR_CON_TRIMODE               DDR_CON_TRIMODE_Msk

/********************  Bit definition for DDR_CFG register  ********************/
#define DDR_CFG_DMOD_Pos              (0U)
#define DDR_CFG_DMOD_Msk             (0x3L << DDR_CFG_DMOD_Pos)          
#define DDR_CFG_DMOD                DDR_CFG_DMOD_Msk

#define DDR_CFG_DUTY_Pos              (4U)
#define DDR_CFG_DUTY_Msk           (0x3L << DDR_CFG_DUTY_Pos)          
#define DDR_CFG_DUTY                DDR_CFG_DUTY_Msk

#define DDR_CFG_SCS_Pos              (7U)
#define DDR_CFG_SCS_Msk            (0x3L << DDR_CFG_SCS_Pos)          
#define DDR_CFG_SCS                  DDR_CFG_SCS_Msk

#define DDR_CFG_VLCD_Pos              (8U)
#define DDR_CFG_VLCD_Msk           (0x0FL << DDR_CFG_VLCD_Pos)          
#define DDR_CFG_VLCD                DDR_CFG_VLCD_Msk
/******************************************************************************/
/*                                                                            */
/*                                OP                                          */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for OP_CON register  ********************/
#define OP_CON_ENOP_Pos                  (0U)
#define OP_CON_ENOP_Msk                  (0x1L << OP_CON_ENOP_Pos)          
#define OP_CON_ENOP                      OP_CON_ENOP_Msk

#define OP_CON_OPOSEL_Pos                (1U)
#define OP_CON_OPOSEL_Msk                (0x1L << OP_CON_OPOSEL_Pos)          
#define OP_CON_OPOSEL                      OP_CON_OPOSEL_Msk

#define OP_CON_OPNSEL_Pos                  (3U)
#define OP_CON_OPNSEL_Msk                  (0x1L << OP_CON_OPNSEL_Pos)          
#define OP_CON_OPNSEL                      OP_CON_OPNSEL_Msk

#define OP_CON_OPPSEL_Pos                  (5U)
#define OP_CON_OPPSEL_Msk                  (0x7L << OP_CON_OPPSEL_Pos)          
#define OP_CON_OPPSEL                      OP_CON_OPPSEL_Msk

#define OP_CON_PGAGAN_Pos                  (8U)
#define OP_CON_PGAGAN_Msk                  (0x3L << OP_CON_PGAGAN_Pos)          
#define OP_CON_PGAGAN                      OP_CON_PGAGAN_Msk

#define OP_CON_FDBRSEL_Pos                  (12U)
#define OP_CON_FDBRSEL_Msk                  (0x3L << OP_CON_FDBRSEL_Pos)          
#define OP_CON_FDBRSEL                      OP_CON_FDBRSEL_Msk

#define OP_CON_TRIMOFFSETNL_Pos              (16U)
#define OP_CON_TRIMOFFSETNL_Msk              (0x1FL << OP_CON_TRIMOFFSETNL_Pos)          
#define OP_CON_TRIMOFFSETNL                  OP_CON_TRIMOFFSETNL_Msk

#define OP_CON_PGAOFC_Pos                  (23U)
#define OP_CON_PGAOFC_Msk                  (0x1L << OP_CON_PGAOFC_Pos)          
#define OP_CON_PGAOFC                      OP_CON_PGAOFC_Msk

#define OP_CON_TRIMOFFSETNH_Pos              (24U)
#define OP_CON_TRIMOFFSETNH_Msk              (0x1FL << OP_CON_TRIMOFFSETNH_Pos)          
#define OP_CON_TRIMOFFSETNH                   OP_CON_TRIMOFFSETNH_Msk
/******************************************************************************/
/*                                                                            */
/*                            PWM0                                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for PWM0_CON register  ******************/
#define PWM_CON_PWMCLK_Pos             (0U)
#define PWM_CON_PWMCLK_Msk             (0x7L << PWM_CON_PWMCLK_Pos)          
#define PWM_CON_PWMCLK                 PWM_CON_PWMCLK_Msk

#define PWM_CON_PWMMD1_Pos             (5U)
#define PWM_CON_PWMMD1_Msk             (0x1L << PWM_CON_PWMMD1_Pos)          
#define PWM_CON_PWMMD1                 PWM_CON_PWMMD1_Msk

#define PWM_CON_PWMMD0_Pos             (6U)
#define PWM_CON_PWMMD0_Msk                 (0x1L << PWM_CON_PWMMD0_Pos)          
#define PWM_CON_PWMMD0                 PWM_CON_PWMMD0_Msk

#define PWM_CON_ENPWM_Pos              (7U)
#define PWM_CON_ENPWM_Msk                  (0x1L << PWM_CON_ENPWM_Pos)          
#define PWM_CON_ENPWM                      PWM_CON_ENPWM_Msk

#define PWM_CON_INTEN_Pos              (8U)
#define PWM_CON_INTEN_Msk         (0x1L << PWM_CON_INTEN_Pos)          
#define PWM_CON_INTEN                PWM_CON_INTEN_Msk
/********************  Bit definition for PWM0_CHN register  ********************/
#define PWM_CHN_ENPWM0_Pos             (0U)
#define PWM_CHN_ENPWM0_Msk         (0x1L << PWM0_CHN_ENPWM0_Pos)          
#define PWM_CHN_ENPWM                PWM0_CHN_ENPWM_Msk

#define PWM_CHN_ENPWM1_Pos             (1U)
#define PWM_CHN_ENPWM1_Msk         (0x1L << PWM_CHN_ENPWM1_Pos)          
#define PWM_CHN_ENPWM1                PWM_CHN_ENPWM1_Msk

#define PWM_CHN_ENPWM2_Pos             (2U)
#define PWM_CHN_ENPWM2_Msk         (0x1L << PWM_CHN_ENPWM2_Pos)          
#define PWM_CHN_ENPWM2                PWM_CHN_ENPWM2_Msk

#define PWM_CHN_ENPWM3_Pos             (3U)
#define PWM_CHN_ENPWM3_Msk         (0x1L << PWM_CHN_ENPWM3_Pos)          
#define PWM_CHN_ENPWM3                PWM_CHN_ENPWM3_Msk

#define PWM_CHN_ENPWM4_Pos             (4U)
#define PWM_CHN_ENPWM4_Msk         (0x1L << PWM_CHN_ENPWM4_Pos)          
#define PWM_CHN_ENPWM4                PWM_CHN_ENPWM4_Msk

#define PWM_CHN_ENPWM5_Pos             (5U)
#define PWM_CHN_ENPWM5_Msk         (0x1L << PWM_CHN_ENPWM5_Pos)          
#define PWM_CHN_ENPWM5                PWM_CHN_ENPWM5_Msk

#define PWM_CHN_ENPWM6_Pos             (6U)
#define PWM_CHN_ENPWM6_Msk         (0x1L << PWM_CHN_ENPWM6_Pos)          
#define PWM_CHN_ENPWM6                PWM_CHN_ENPWM6_Msk

#define PWM_CHN_ENPWM7_Pos             (7U)
#define PWM_CHN_ENPWM7_Msk         (0x1L << PWM_CHN_ENPWM7_Pos)          
#define PWM_CHN_ENPWM7                PWM_CHN_ENPWM7_Msk
/********************  Bit definition for PWM_STS register  ********************/
#define PWM_STS_PWMIF_Pos              (0U)
#define PWM_STS_PWMIF_Msk         (0x1L << PWM_STS_PWMIF_Pos)          
#define PWM_STS_PWMIF                PWM_STS_PWMIF_Msk

#define PWM_STS_FLTSTA_Pos             (1U)
#define PWM_STS_FLTSTA_Msk         (0x1L << PWM_STS_FLTSTA_Pos)          
#define PWM_STS_FLTSTA               PWM_STS_FLTSTA_Msk
/********************  Bit definition for PWM_INV register  ********************/
#define PWM_INV_INV0_Pos              (0U)
#define PWM_INV_INV0_Msk          (0x1L << PWM_INV_INV0_Pos)          
#define PWM_INV_INV0                 PWM_INV_INV0_Msk

#define PWM_INV_INV1_Pos              (1U)
#define PWM_INV_INV1_Msk          (0x1L << PWM_INV_INV1_Pos)          
#define PWM_INV_INV1                 PWM_INV_INV1_Msk

#define PWM_INV_INV2_Pos              (2U)
#define PWM_INV_INV2_Msk          (0x1L << PWM_INV_INV2_Pos)          
#define PWM_INV_INV2                 PWM_INV_INV2_Msk

#define PWM_INV_INV3_Pos              (3U)
#define PWM_INV_INV3_Msk          (0x1L << PWM_INV_INV3_Pos)          
#define PWM_INV_INV3                 PWM_INV_INV3_Msk

#define PWM_INV_INV4_Pos              (4U)
#define PWM_INV_INV4_Msk          (0x1L << PWM_INV_INV4_Pos)          
#define PWM_INV_INV4                 PWM_INV_INV4_Msk

#define PWM_INV_INV5_Pos              (5U)
#define PWM_INV_INV5_Msk          (0x1L << PWM_INV_INV5_Pos)          
#define PWM_INV_INV5                 PWM_INV_INV5_Msk

#define PWM_INV_INV6_Pos              (6U)
#define PWM_INV_INV6_Msk          (0x1L << PWM_INV_INV6_Pos)          
#define PWM_INV_INV6                 PWM_INV_INV6_Msk

#define PWM_INV_INV7_Pos              (7U)
#define PWM_INV_INV7_Msk          (0x1L << PWM_INV_INV7_Pos)          
#define PWM_INV_INV7                 PWM_INV_INV7_Msk
/********************  Bit definition for PWM_DFR register  *******************/
#define PWM_DFR_PDR_Pos               (0U)
#define PWM_DFR_PDR_Msk          (0x0FL << PWM_DFR_PDR_Pos)          
#define PWM_DFR_PDR                 PWM_DFR_PDR_Msk

#define PWM_DFR_PDF_Pos               (8U)
#define PWM_DFR_PDF_Msk          (0x0FL << PWM_DFR_PDF_Pos)          
#define PWM_DFR_PDF                 PWM_DFR_PDF_Msk
/********************  Bit definition for PWM_FLT register  *******************/
#define PWM_FLT_FLTDT_Pos              (0U)
#define PWM_FLT_FLTDT_Msk         (0x03L << PWM_FLT_FLTDT_Pos)          
#define PWM_FLT_FLTDT                PWM_FLT_FLTDT_Msk

#define PWM_FLT_FLTTV_Pos              (4U)
#define PWM_FLT_FLTTV_Msk         (0x1L << PWM_FLT_FLTTV_Pos)          
#define PWM_FLT_FLTTV                PWM_FLT_FLTTV_Msk

#define PWM_FLT_FLTMD_Pos              (5U)
#define PWM_FLT_FLTMD_Msk         (0x1L << PWM_FLT_FLTMD_Pos)          
#define PWM_FLT_FLTMD                PWM_FLT_FLTMD_Msk

#define PWM_FLT_FLTEN_Pos              (7U)
#define PWM_FLT_FLTEN_Msk         (0x1L << PWM_FLT_FLTEN_Pos)          
#define PWM_FLT_FLTEN                PWM_FLT_FLTEN_Msk
/******************************************************************************/
/*                                                                            */
/*                      LEDPWM                                                */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for LEDPWM_CON register  ****************/
#define LEDPWM_CON_PWMCLK_Pos               (0U)
#define LEDPWM_CON_PWMCLK_Msk               (0xFL << LEDPWM_CON_PWMCLK_Pos)          
#define LEDPWM_CON_PWMCLK                   LEDPWM_CON_PWMCLK_Msk

#define LEDPWM_CON_PWMMD0_Pos               (6U)
#define LEDPWM_CON_PWMMD0_Msk               (0x1L << LEDPWM_CON_PWMMD0_Pos)          
#define LEDPWM_CON_PWMMD0                   LEDPWM_CON_PWMMD0_Msk

#define LEDPWM_CON_ENPWM_Pos                (7U)
#define LEDPWM_CON_ENPWM_Msk                (0x1L << LEDPWM_CON_ENPWM_Pos)          
#define LEDPWM_CON_ENPWM                    LEDPWM_CON_ENPWM_Msk

#define LEDPWM_CON_INTEN_Pos                (8U)
#define LEDPWM_CON_INTEN_Msk                (0x1L << LEDPWM_CON_INTEN_Pos)          
#define LEDPWM_CON_INTEN                    LEDPWM_CON_INTEN_Msk
/********************  Bit definition for PWM1_STS register  ********************/
#define LEDPWM_STS_PWMIF_Pos                (0U)
#define LEDPWM_STS_PWMIF_Msk                (0x1L << LEDPWM_STS_PWMIF_Pos)          
#define LEDPWM_STS_PWMIF                    LEDPWM_STS_PWMIF_Msk
/******************************************************************************/
/*                                                                            */
/*                      SPI                 																*/
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for SPI_CON register  ********************/
#define SPI_CON_MSTR_Pos         	   (0U)
#define	SPI_CON_MSTR_Msk		   (0x1L << SPI_CON_MSTR_Pos)
#define SPI_CON_MSTR          		   SPI_CON_MSTR_Msk

#define SPI_CON_SPMD_Pos         	   (1U)
#define	SPI_CON_SPMD_Msk		   (0x1L << SPI_CON_SPMD_Pos)
#define SPI_CON_SPMD          		   SPI_CON_SPMD_Msk

#define SPI_CON_DORD_Pos         	   (2U)
#define	SPI_CON_DORD_Msk		   (0x1L << SPI_CON_DORD_Pos)
#define SPI_CON_DORD          	            SPI_CON_DORD_Msk

#define SPI_CON_CPHA_Pos         	   (3U)
#define	SPI_CON_CPHA_Msk		   (0x1L << SPI_CON_CPHA_Pos)
#define SPI_CON_CPHA          		   SPI_CON_CPHA_Msk

#define SPI_CON_CPOL_Pos         	   (4U)
#define	SPI_CON_CPOL_Msk		   (0x1L << SPI_CON_CPOL_Pos)
#define SPI_CON_CPOL          		    SPI_CON_CPOL_Msk

#define SPI_CON_SPEN_Pos         	   (7U)
#define	SPI_CON_SPEN_Msk		   (0x1L << SPI_CON_SPEN_Pos)
#define SPI_CON_SPEN          		   SPI_CON_SPEN_Msk

#define SPI_CON_SPR_Pos         	  (8U)
#define	SPI_CON_SPR_Msk		          (0x0FL << SPI_CON_SPR_Pos)
#define SPI_CON_SPR          		   SPI_CON_SPR_Msk

#define SPI_CON_SPOS_Pos         	   (14U)
#define	SPI_CON_SPOS_Msk		   (0x3L << SPI_CON_SPOS_Pos)
#define SPI_CON_SPOS          		   SPI_CON_SPOS_Msk
/********************  Bit definition for SPI_STS register  ********************/
#define SPI_STS_SPIF_Pos         	   (0U)
#define	SPI_STS_SPIF_Msk		   (0x1L << SPI_STS_SPIF_Pos)
#define SPI_STS_SPIF          		    SPI_STS_SPIF_Msk

#define SPI_STS_RINEIF_Pos         	   (1U)
#define	SPI_STS_RINEIF_Msk		   (0x1L << SPI_STS_RINEIF_Pos)
#define SPI_STS_RINEIF          	   SPI_STS_RINEIF_Msk

#define SPI_STS_TXEIF_Pos         	   (2U)
#define	SPI_STS_TXEIF_Msk		   (0x1L << SPI_STS_TXEIF_Pos)
#define SPI_STS_TXEIF          		   SPI_STS_TXEIF_Msk

#define SPI_STS_RXFIF_Pos         	   (3U)
#define	SPI_STS_RXFIF_Msk		   (0x1L << SPI_STS_RXFIF_Pos)
#define SPI_STS_RXFIF          		   SPI_STS_RXFIF_Msk

#define SPI_STS_RXHIF_Pos         	   (4U)
#define	SPI_STS_RXHIF_Msk		   (0x1L << SPI_STS_RXHIF_Pos)
#define SPI_STS_RXHIF          		    SPI_STS_RXHIF_Msk

#define SPI_STS_TXHIF_Pos         	    (5U)
#define	SPI_STS_TXHIF_Msk		    (0x1L << SPI_STS_TXHIF_Pos)
#define SPI_STS_TXHIF          		     SPI_STS_TXHIF_Msk

#define SPI_STS_WCOL_Pos         	    (7U)
#define	SPI_STS_WCOL_Msk	            (0x1L << SPI_STS_WCOL_Pos)
#define SPI_STS_WCOL          		    SPI_STS_WCOL_Msk
/********************  Bit definition for SPI_IDE register  ********************/
#define SPI_IDE_INTEN_Pos         	    (0U)
#define	SPI_IDE_INTEN_Msk		    (0x1L << SPI_IDE_INTEN_Pos)
#define SPI_IDE_INTEN         		    SPI_IDE_INTEN_Msk

#define SPI_IDE_RXNEIE_Pos         	     (1U)
#define	SPI_IDE_RXNEIE_Msk		     (0x1L << SPI_IDE_RXNEIE_Pos)
#define SPI_IDE_RXNEIE         		     SPI_IDE_RXNEIE_Msk

#define SPI_IDE_TBIE_Pos         	     (2U)
#define	SPI_IDE_TBIE_Msk		     (0x1L << SPI_IDE_TBIE_Pos)
#define SPI_IDE_TBIE        		     SPI_IDE_TBIE_Msk

#define SPI_IDE_RXIE_Pos         	     (3U)
#define	SPI_IDE_RXIE_Msk		     (0x1L << SPI_IDE_RXIE_Pos)
#define SPI_IDE_RXIE        		     SPI_IDE_RXIE_Msk

#define SPI_IDE_RXHIE_Pos         	    (4U)
#define	SPI_IDE_RXHIE_Msk		    (0x1L << SPI_IDE_RXHIE_Pos)
#define SPI_IDE_RXHIE        		    SPI_IDE_RXHIE_Msk

#define SPI_IDE_TXHIE_Pos         	    (5U)
#define	SPI_IDE_TXHIE_Msk		    (0x1L << SPI_IDE_TXHIE_Pos)
#define SPI_IDE_TXHIE        		    SPI_IDE_TXHIE_Msk

#define SPI_IDE_RXDMAEN_Pos         	    (6U)
#define	SPI_IDE_RXDMAEN_Msk		    (0x1L << SPI_IDE_RXDMAEN_Pos)
#define SPI_IDE_RXDMAEN        		     SPI_IDE_RXDMAEN_Msk

#define SPI_IDE_TXDMAEN_Pos         	     (7U)
#define	SPI_IDE_TXDMAEN_Msk		     (0x1L << SPI_IDE_TXDMAEN_Pos)
#define SPI_IDE_TXDMAEN        		     SPI_IDE_TXDMAEN_Msk

/******************************************************************************/
/*                                                                            */
/*                      TIM                                                   */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for TIM_CON register  ********************/
#define TIM_CON_CPRL_Pos               (0U)
#define TIM_CON_CPRL_Msk          (0x1L << TIM_CON_CPRL_Pos)          
#define TIM_CON_CPRL                 TIM_CON_CPRL_Msk

#define TIM_CON_CTSEL_Pos              (1U)
#define TIM_CON_CTSEL_Msk          (0x1L << TIM_CON_CTSEL_Pos)          
#define TIM_CON_CTSEL                TIM_CON_CTSEL_Msk

#define TIM_CON_EXENR_Pos              (2U)
#define TIM_CON_EXENR_Msk          (0x1L << TIM_CON_EXENR_Pos)          
#define TIM_CON_EXENR                TIM_CON_EXENR_Msk

#define TIM_CON_EXENF_Pos              (3U)
#define TIM_CON_EXENF_Msk          (0x1L << TIM_CON_EXENF_Pos)          
#define TIM_CON_EXENF                TIM_CON_EXENF_Msk

#define TIM_CON_FSEL_Pos               (4U)
#define TIM_CON_FSEL_Msk          (0x1L << TIM_CON_FSEL_Pos)          
#define TIM_CON_FSEL                TIM_CON_FSEL_Msk

#define TIM_CON_EXENX_Pos              (5U)
#define TIM_CON_EXENX_Msk          (0x1L << TIM_CON_EXENX_Pos)          
#define TIM_CON_EXENX                TIM_CON_EXENX_Msk

#define TIM_CON_DEC_Pos               (6U)
#define TIM_CON_DEC_Msk           (0x1L << TIM_CON_DEC_Pos)          
#define TIM_CON_DEC                 TIM_CON_DEC_Msk

#define TIM_CON_TR_Pos                (7U)
#define TIM_CON_TR_Msk           (0x1L << TIM_CON_TR_Pos)          
#define TIM_CON_TR                 TIM_CON_TR_Msk

#define TIM_CON_TIMCLK_Pos              (8U)
#define TIM_CON_TIMCLK_Msk         (0x7L << TIM_CON_TIMCLK_Pos)          
#define TIM_CON_TIMCLK                TIM_CON_TIMCLK_Msk

#define TIM_CON_INVNB_Pos              (11U)
#define TIM_CON_INVNB_Msk          (0x1L << TIM_CON_INVNB_Pos)          
#define TIM_CON_INVNB                TIM_CON_INVNB_Msk

#define TIM_CON_INVNA_Pos              (12U)
#define TIM_CON_INVNA_Msk          (0x1L << TIM_CON_INVNA_Pos)          
#define TIM_CON_INVNA                TIM_CON_INVNA_Msk

#define TIM_CON_EPWMNB_Pos              (13U)
#define TIM_CON_EPWMNB_Msk         (0x1L << TIM_CON_EPWMNB_Pos)          
#define TIM_CON_EPWMNB                TIM_CON_EPWMNB_Msk

#define TIM_CON_EPWMNA_Pos              (14U)
#define TIM_CON_EPWMNA_Msk         (0x1L << TIM_CON_EPWMNA_Pos)          
#define TIM_CON_EPWMNA                TIM_CON_EPWMNA_Msk

#define TIM_CON_TXOE_Pos               (15U)
#define TIM_CON_TXOE_Msk          (0x1L << TIM_CON_TXOE_Pos)          
#define TIM_CON_TXOE                 TIM_CON_TXOE_Msk

/********************  Bit definition for TIM_STS register  ********************/
#define TIM_STS_TIF_Pos               (0U)
#define TIM_STS_TIF_Msk           (0x1L << TIM_STS_TIF_Pos)          
#define TIM_STS_TIF                 TIM_STS_TIF_Msk

#define TIM_STS_EXIR_Pos               (1U)
#define TIM_STS_EXIR_Msk          (0x1L << TIM_STS_EXIR_Pos)          
#define TIM_STS_EXIR                 TIM_STS_EXIR_Msk

#define TIM_STS_EXIF_Pos               (2U)
#define TIM_STS_EXIF_Msk          (0x1L << TIM_STS_EXIF_Pos)          
#define TIM_STS_EXIF                TIM_STS_EXIF_Msk
/********************  Bit definition for TIM_IDE register  ********************/
#define TIM_IDE_INTEN_Pos              (0U)
#define TIM_IDE_INTEN_Msk          (0x1L << TIM_IDE_INTEN_Pos)          
#define TIM_IDE_INTEN                TIM_IDE_INTEN_Msk

#define TIM_IDE_TIE_Pos               (1U)
#define TIM_IDE_TIE_Msk           (0x1L << TIM_IDE_TIE_Pos)          
#define TIM_IDE_TIE                 TIM_IDE_TIE_Msk

#define TIM_IDE_EXIRE_Pos              (2U)
#define TIM_IDE_EXIRE_Msk          (0x1L << TIM_IDE_EXIRE_Pos)          
#define TIM_IDE_EXIRE                TIM_IDE_EXIRE_Msk

#define TIM_IDE_EXIFE_Pos              (3U)
#define TIM_IDE_EXIFE_Msk          (0x1L << TIM_IDE_EXIFE_Pos)          
#define TIM_IDE_EXIFE                TIM_IDE_EXIFE_Msk

#define TIM_IDE_TIDE_Pos               (4U)
#define TIM_IDE_TIDE_Msk          (0x1L << TIM_IDE_TIDE_Pos)          
#define TIM_IDE_TIDE                 TIM_IDE_TIDE_Msk

#define TIM_IDE_CAPRDE_Pos              (5U)
#define TIM_IDE_CAPRDE_Msk         (0x1L << TIM_IDE_CAPRDE_Pos)          
#define TIM_IDE_CAPRDE               TIM_IDE_CAPRDE_Msk

#define TIM_IDE_CAPFDE_Pos              (6U)
#define TIM_IDE_CAPFDE_Msk         (0x1L << TIM_IDE_CAPFDE_Pos)          
#define TIM_IDE_CAPFDE               TIM_IDE_CAPFDE_Msk
/******************************************************************************/
/*                                                                            */
/*                      TK                                                    */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for TK_CON register  ********************/
#define TK_CON_TRIG_Pos               (0U)
#define TK_CON_TRIG_Msk           (0x1L << TK_CON_TRIG_Pos)          
#define TK_CON_TRIG                 TK_CON_TRIG_Msk

#define TK_CON_TKIF_Pos               (1U)
#define TK_CON_TKIF_Msk           (0x1L << TK_CON_TKIF_Pos)          
#define TK_CON_TKIF                TK_CON_TKIF_Msk

#define TK_CON_INTEN_Pos               (4U)
#define TK_CON_INTEN_Msk          (0x1L << TK_CON_INTEN_Pos)          
#define TK_CON_INTEN                TK_CON_INTEN_Msk

#define TK_CON_PRSC_Pos               (5U)
#define TK_CON_PRSC_Msk           (0x1L << TK_CON_PRSC_Pos)          
#define TK_CON_PRSC                 TK_CON_PRSC_Msk

#define TK_CON_PRS_Pos                (6U)
#define TK_CON_PRS_Msk           (0x1L << TK_CON_PRS_Pos)          
#define TK_CON_PRS                  TK_CON_PRS_Msk

#define TK_CON_ENTKS_Pos               (7U)
#define TK_CON_ENTKS_Msk          (0x1L << TK_CON_ENTKS_Pos)          
#define TK_CON_ENTKS                 TK_CON_ENTKS_Msk

#define TK_CON_TKCKS_Pos               (8U)
#define TK_CON_TKCKS_Msk          (0x1L << TK_CON_TKCKS_Pos)          
#define TK_CON_TKCKS                 TK_CON_TKCKS_Msk

#define TK_CON_CTIME_Pos               (12U)
#define TK_CON_CTIME_Msk          (0xFL << TK_CON_CTIME_Pos)          
#define TK_CON_CTIME                 TK_CON_CTIME_Msk

#define TK_CON_TKMOD_Pos               (16U)
#define TK_CON_TKMOD_Msk          (0x1L << TK_CON_TKMOD_Pos)          
#define TK_CON_TKMOD                 TK_CON_TKMOD_Msk

#define TK_CON_TKSCN_Pos               (17U)
#define TK_CON_TKSCN_Msk          (0xFL << TK_CON_TKSCN_Pos)          
#define TK_CON_TKSCN                 TK_CON_TKSCN_Msk

/********************  Bit definition for TK_CFG register  ********************/
#define TK_CFG_ICHG_Pos                     (0U)
#define TK_CFG_ICHG_Msk                     (0xFFL << TK_CFG_ICHG_Pos)          
#define TK_CFG_ICHG                 TK_CFG_ICHG_Msk

#define TK_CFG_ICHA_Pos                     (9U)
#define TK_CFG_ICHA_Msk                     (0x7FL << TK_CFG_ICHA_Pos)          
#define TK_CFG_ICHA                 TK_CFG_ICHA_Msk

#define TK_CFG_V4V_Pos                      (16U)
#define TK_CFG_V4V_Msk                      (0x1L << TK_CFG_V4V_Pos)          
#define TK_CFG_V4V                   TK_CFG_V4V_Msk

#define TK_CFG_IVSEL_Pos                    (22U)
#define TK_CFG_IVSEL_Msk                    (0x1L << TK_CFG_IVSEL_Pos)          
#define TK_CFG_IVSEL                 TK_CFG_IVSEL_Msk

#define TK_CFG_IGOSEL_Pos                   (23U)
#define TK_CFG_IGOSEL_Msk                   (0x1L << TK_CFG_IGOSEL_Pos)          
#define TK_CFG_IGOSEL                TK_CFG_IGOSEL_Msk

#define TK_CFG_VREF_Pos                     (24U)
#define TK_CFG_VREF_Msk                     (0xFL << TK_CFG_VREF_Pos)          
#define TK_CFG_VREF                 TK_CFG_VREF_Msk

#define TK_CFG_ICHGC_Pos                    (28U)
#define TK_CFG_ICHGC_Msk                    (0x3L << TK_CFG_ICHGC_Pos)          
#define TK_CFG_ICHGC                 TK_CFG_ICHGC_Msk

#define TK_CFG_ICHAC_Pos                    (30U)
#define TK_CFG_ICHAC_Msk                    (0x3L << TK_CFG_ICHAC_Pos)          
#define TK_CFG_ICHAC                 TK_CFG_ICHAC_Msk

/******************************************************************************/
/*                                                                            */
/*                               TWI                                          */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for TWI_CON register  ********************/
#define TWI_CON_STRETCH_Pos               (0U)
#define TWI_CON_STRETCH_Msk               (0x1L << TWI_CON_STRETCH_Pos)          
#define TWI_CON_STRETCH                   TWI_CON_STRETCH_Msk

#define TWI_CON_AA_Pos                    (1U)
#define TWI_CON_AA_Msk                    (0x1L << TWI_CON_AA_Pos)          
#define TWI_CON_AA                        TWI_CON_AA_Msk

#define TWI_CON_STO_Pos                   (4U)
#define TWI_CON_STO_Msk                   (0x1L << TWI_CON_STO_Pos)          
#define TWI_CON_STO                       TWI_CON_STO_Msk

#define TWI_CON_STA_Pos                   (5U)
#define TWI_CON_STA_Msk                   (0x1L << TWI_CON_STA_Pos)          
#define TWI_CON_STA                       TWI_CON_STA_Msk

#define TWI_CON_TWEN_Pos                  (7U)
#define TWI_CON_TWEN_Msk                  (0x1L << TWI_CON_TWEN_Pos)          
#define TWI_CON_TWEN                      TWI_CON_TWEN_Msk

#define TWI_CON_TWCK_Pos                  (8U)
#define TWI_CON_TWCK_Msk                  (0x0FL << TWI_CON_TWCK_Pos)
#define TWI_CON_TWCK                      TWI_CON_TWCK_Msk

#define TWI_CON_SPOS_Pos                  (13U)
#define TWI_CON_SPOS_Msk                  (0x7L << TWI_CON_SPOS_Pos)
#define TWI_CON_SPOS                      TWI_CON_SPOS_Msk
/********************  Bit definition for TWI_STS register  ********************/
#define TWI_STS_TWIF_Pos                  (0U)
#define TWI_STS_TWIF_Msk                  (0x1L << TWI_STS_TWIF_Pos)
#define TWI_STS_TWIF                      TWI_STS_TWIF_Msk

#define TWI_STS_TXERXE_Pos                (1U)
#define TWI_STS_TXERXE_Msk                (0x1L << TWI_STS_TXERXE_Pos)
#define TWI_STS_TXERXE                    TWI_STS_TXERXE_Msk

#define TWI_STS_GCA_Pos                   (2U)
#define TWI_STS_GCA_Msk                   (0x1L << TWI_STS_GCA_Pos)
#define TWI_STS_GCA                       TWI_STS_GCA_Msk

#define TWI_STS_MSTR_Pos                  (3U)
#define TWI_STS_MSTR_Msk                  (0x1L << TWI_STS_MSTR_Pos)
#define TWI_STS_MSTR                      TWI_STS_MSTR_Msk

#define TWI_STS_STATE_Pos                 (8U)
#define TWI_STS_STATE_Msk                 (0x7L << TWI_STS_STATE_Pos)
#define TWI_STS_STATE                     TWI_STS_STATE_Msk

#define TWI_STS_NBYTES_Pos                (16U)
#define TWI_STS_NBYTES_Msk                (0xFFL << TWI_STS_NBYTES_Pos)
#define TWI_STS_NBYTES                    TWI_STS_NBYTES_Msk
/********************  Bit definition for TWI_ADD register  ********************/
#define TWI_ADD_GC_Pos                    (0U)
#define	TWI_ADD_GC_Msk	                  (0x1L << TWI_ADD_GC_Pos)
#define TWI_ADD_GC         		  TWI_ADD_GC_Msk

#define TWI_ADD_TWA_Pos         	  (1U)
#define	TWI_ADD_TWA_Msk			  (0x7FL << TWI_ADD_TWA_Pos)
#define TWI_ADD_TWA                       TWI_ADD_TWA_Msk
/********************  Bit definition for TWI_IDE register  ********************/
#define TWI_IDE_INTEN_Pos                 (0U)
#define TWI_IDE_INTEN_Msk                 (0x1L << TWI_IDE_INTEN_Pos)
#define TWI_IDE_INTEN                     TWI_IDE_INTEN_Msk

#define TWI_IDE_RXDMAEN_Pos               (6U)
#define TWI_IDE_RXDMAEN_Msk               (0x1L << TWI_IDE_RXDMAEN_Pos)
#define TWI_IDE_RXDMAEN                   TWI_IDE_RXDMAEN_Msk

#define TWI_IDE_TXDMAEN_Pos               (7U)
#define TWI_IDE_TXDMAEN_Msk               (0x1L << TWI_IDE_TXDMAEN_Pos)
#define TWI_IDE_TXDMAEN                   TWI_IDE_TXDMAEN_Msk

/******************************************************************************/
/*                                                                            */
/*                              UART                                          */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for UART_CON register  ********************/
#define UART_CON_SM01_Pos                 (0U)
#define UART_CON_SM01_Msk                 (0x3L << UART_CON_SM01_Pos) 
#define UART_CON_SM01                     UART_CON_SM01_Msk

#define UART_CON_SM2_Pos                  (2U)
#define UART_CON_SM2_Msk                  (0x1L << UART_CON_SM2_Pos)          
#define UART_CON_SM2                      UART_CON_SM2_Msk

#define UART_CON_PERSCALER_Pos            (4U)
#define UART_CON_PERSCALER_Msk            (0x1L << UART_CON_PERSCALER_Pos)          
#define UART_CON_PERSCALER                UART_CON_PERSCALER_Msk

#define UART_CON_RXEN_Pos                 (6U)
#define UART_CON_RXEN_Msk                 (0x1L << UART_CON_RXEN_Pos)          
#define UART_CON_RXEN                     UART_CON_RXEN_Msk

#define UART_CON_TXEN_Pos                 (7U)
#define UART_CON_TXEN_Msk                 (0x1L << UART_CON_TXEN_Pos)          
#define UART_CON_TXEN                     UART_CON_TXEN_Msk

#define UART_CON_FUNCSEL_Pos              (8U)
#define UART_CON_FUNCSEL_Msk              (0x1L << UART_CON_FUNCSEL_Pos)          
#define UART_CON_FUNCSEL                  UART_CON_FUNCSEL_Msk

#define UART_CON_SPOS_Pos                 (14U)
#define UART_CON_SPOS_Msk                 (0x3L << UART_CON_SPOS_Pos)          
#define UART_CON_SPOS                     UART_CON_SPOS_Msk

#define UART_CON_SLVEN_Pos                (16U)
#define UART_CON_SLVEN_Msk                (0x1L << UART_CON_SLVEN_Pos)          
#define UART_CON_SLVEN                    UART_CON_SLVEN_Msk

#define UART_CON_SLVAREN_Pos              (17U)
#define UART_CON_SLVAREN_Msk              (0x1L << UART_CON_SLVAREN_Pos)          
#define UART_CON_SLVAREN                  UART_CON_SLVAREN_Msk

#define UART_CON_LBDL_Pos                 (18U)
#define UART_CON_LBDL_Msk                 (0x1L << UART_CON_LBDL_Pos)          
#define UART_CON_LBDL                     UART_CON_LBDL_Msk

#define UART_CON_BKTR_Pos                 (24U)
#define UART_CON_BKTR_Msk                 (0x1L << UART_CON_BKTR_Pos)          
#define UART_CON_BKTR                     UART_CON_BKTR_Msk

#define UART_CON_BKSIZE_Pos               (26U)
#define UART_CON_BKSIZE_Msk               (0x1L << UART_CON_BKSIZE_Pos)          
#define UART_CON_BKSIZE                   UART_CON_BKSIZE_Msk

/********************  Bit definition for UART_STS register  ********************/
#define UART_STS_RXIF_Pos                 (0U)
#define UART_STS_RXIF_Msk                 (0x1L << UART_STS_RXIF_Pos)           
#define UART_STS_RXIF                     UART_STS_RXIF_Msk

#define UART_STS_TXIF_Pos                 (1U)
#define UART_STS_TXIF_Msk                 (0x1L << UART_STS_TXIF_Pos)          
#define UART_STS_TXIF                     UART_STS_TXIF_Msk

#define UART_STS_WKIF_Pos                 (4U)
#define UART_STS_WKIF_Msk                 (0x1L << UART_STS_WKIF_Pos)          
#define UART_STS_WKIF                     UART_STS_WKIF_Msk

#define UART_STS_BKIF_Pos                 (8U)
#define UART_STS_BKIF_Msk                 (0x1L << UART_STS_BKIF_Pos)          
#define UART_STS_BKIF                     UART_STS_BKIF_Msk

#define UART_STS_SLVHEIF_Pos              (9U)
#define UART_STS_SLVHEIF_Msk              (0x1L << UART_STS_SLVHEIF_Pos)          
#define UART_STS_SLVHEIF                  UART_STS_SLVHEIF_Msk

#define UART_STS_SLVSYNIF_Pos             (10U)
#define UART_STS_SLVSYNIF_Msk             (0x1L << UART_STS_SLVSYNIF_Pos)          
#define UART_STS_SLVSYNIF                 UART_STS_SLVSYNIF_Msk

#define UART_STS_SYNCIF_Pos               (11U)
#define UART_STS_SYNCIF_Msk               (0x1L << UART_STS_SYNCIF_Pos)          
#define UART_STS_SYNCIF                   UART_STS_SYNCIF_Msk
/********************  Bit definition for UART_IDE register  ********************/
#define UART_IDE_INTEN_Pos                (0U)
#define UART_IDE_INTEN_Msk                (0x1L << UART_IDE_INTEN_Pos)          
#define UART_IDE_INTEN                    UART_IDE_INTEN_Msk

#define UART_IDE_RXIE_Pos                 (1U)
#define UART_IDE_RXIE_Msk                 (0x1L << UART_IDE_RXIE_Pos)          
#define UART_IDE_RXIE                     UART_IDE_RXIE_Msk

#define UART_IDE_TXIE_Pos                 (2U)
#define UART_IDE_TXIE_Msk                 (0x1L << UART_IDE_TXIE_Pos)          
#define UART_IDE_TXIE                     UART_IDE_TXIE_Msk

#define UART_IDE_WKIE_Pos                 (4U)
#define UART_IDE_WKIE_Msk                 (0x1L << UART_IDE_WKIE_Pos)          
#define UART_IDE_WKIE                     UART_IDE_WKIE_Msk

#define UART_IDE_RXDMAEN_Pos              (6U)
#define UART_IDE_RXDMAEN_Msk              (0x1L << UART_IDE_RXDMAEN_Pos)          
#define UART_IDE_RXDMAEN                  UART_IDE_RXDMAEN_Msk

#define UART_IDE_TXDMAEN_Pos              (7U)
#define UART_IDE_TXDMAEN_Msk              (0x1L << UART_IDE_TXDMAEN_Pos)          
#define UART_IDE_TXDMAEN                  UART_IDE_TXDMAEN_Msk

#define UART_IDE_BKIE_Pos                 (8U)
#define UART_IDE_BKIE_Msk                 (0x1L << UART_IDE_BKIE_Pos)          
#define UART_IDE_BKIE                     UART_IDE_BKIE_Msk

#define UART_IDE_SLVHEIE_Pos              (9U)
#define UART_IDE_SLVHEIE_Msk              (0x1L << UART_IDE_SLVHEIE_Pos)          
#define UART_IDE_SLVHEIE                  UART_IDE_SLVHEIE_Msk

#define UART_IDE_SYNCIE_Pos               (11U)
#define UART_IDE_SYNCIE_Msk               (0x1L << UART_IDE_SYNCIE_Pos)          
#define UART_IDE_SYNCIE                   UART_IDE_SYNCIE_Msk

/******************************************************************************/
/*                                                                            */
/*                      WDT                                                   */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for WDT_CON register  ********************/
#define WDT_CON_CLRWDT_Pos                (0U)
#define WDT_CON_CLRWDT_Msk                (0x1L << WDT_CON_CLRWDT_Pos)          
#define WDT_CON_CLRWDT                    WDT_CON_CLRWDT_Msk

/********************  Bit definition for WDT_CFG register  ********************/
#define WDT_CFG_WDTCKS_Pos                (0U)
#define WDT_CFG_WDTCKS_Msk                (0x7L << WDT_CFG_WDTCKS_Pos)          
#define WDT_CFG_WDTCKS                    WDT_CFG_WDTCKS_Msk

/******************************************************************************/
/*                         CustomerOption Registers Bits Definition           */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                      Option0                                               */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for COPT0_CFG register  ********************/
#define COPT0_CFG_LVRS_Pos                (0U)
#define COPT0_CFG_LVRS_Msk                (0x3L << COPT0_CFG_LVRS_Pos)          
#define COPT0_CFG_LVRS                    COPT0_CFG_LVRS_Msk

#define COPT0_CFG_DISLVR_Pos              (2U)
#define COPT0_CFG_DISLVR_Msk              (0x1L << COPT0_CFG_DISLVR_Pos)          
#define COPT0_CFG_DISLVR                  COPT0_CFG_DISLVR_Msk
/******************************************************************************/
/*                                                                            */
/*                      Option0                                               */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for COPT1_CFG register  ********************/
#define COPT1_CFG_OPBL_Pos                (0U)
#define COPT1_CFG_OPBL_Msk                (0x3L << COPT1_CFG_OPBL_Pos)          
#define COPT1_CFG_OPBL                    COPT1_CFG_OPBL_Msk

#define COPT1_CFG_DISRST_Pos              (5U)
#define COPT1_CFG_DISRST_Msk              (0x1L << COPT1_CFG_DISRST_Pos)          
#define COPT1_CFG_DISRST                  COPT1_CFG_DISRST_Msk

#define COPT1_CFG_DISJTAG_Pos             (6U)
#define COPT1_CFG_DISJTAG_Msk             (0x1L << COPT1_CFG_DISJTAG_Pos)          
#define COPT1_CFG_DISJTAG                 COPT1_CFG_DISJTAG_Msk

#define COPT1_CFG_ENWDT_Pos               (7U)
#define COPT1_CFG_ENWDT_Msk               (0x1L << COPT1_CFG_ENWDT_Pos)          
#define COPT1_CFG_ENWDT                   COPT1_CFG_ENWDT_Msk
/** @addtogroup Exported_macros
  * @{
  */

/**
  * @}
  */

 /**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SC32F12xx_H */

/**
  * @}
  */

  /**
  * @}
  */

/************************ (C) COPYRIGHT SIN ONE CHIP *****END OF FILE****/
