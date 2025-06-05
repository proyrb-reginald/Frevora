/**
 ******************************************************************************
 * @file    sc32f1xxx_rcc.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   This file contains all the functions prototypes for the RCC
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __sc32f1xxx_RCC_H
#define __sc32f1xxx_RCC_H


#ifdef __cplusplus
extern "C"
{
#endif

/*!< Includes ----------------------------------------------------------------*/
#include "sc32f1xxx.h"
#include "sc32.h"

/** @addtogroup sc32f1xxx_StdPeriph_Driver
 * @{
 */

/** @addtogroup RCC
 * @{
 */

/* Exported types ------------------------------------------------------------*/
/** @brief RCC_SYSCLKSource System Clock Source
 * @{
 */
#if defined(SC32f10xx)
typedef enum
{
    RCC_SYSCLKSource_HIRC   = ( uint16_t ) ( ~RCC_CFG0_SYSCLKSW ), /*!< SYSCLK Source £º HIRC */
    RCC_SYSCLKSource_LIRC    =
        ( uint16_t ) ( ( 0x00 << RCC_CFG0_SYSCLKSEL_Pos ) ), /*!< SYSCLK Source £º LIRC */
    RCC_SYSCLKSource_HXT    =
        ( uint16_t ) ( ( 0x01 << RCC_CFG0_SYSCLKSEL_Pos ) ), /*!< SYSCLK Source £º HXT */
    RCC_SYSCLKSource_PLLRCLK =
        ( uint16_t ) ( ( 0x02 << RCC_CFG0_SYSCLKSEL_Pos ) ), /*!< SYSCLK Source £º PLLCK */
    RCC_SYSCLKSource_LXT    =
        ( uint16_t ) ( ( 0x03 << RCC_CFG0_SYSCLKSEL_Pos ) ), /*!< SYSCLK Source £º LXT */
} RCC_SYSCLKSource_TypeDef;

#define IS_RCC_SYSCLKSOURCE(SOURCE) (((SOURCE) == RCC_SYSCLKSource_HIRC) || \
                                     ((SOURCE) == RCC_SYSCLKSource_LIRC) || \
                                     ((SOURCE) == RCC_SYSCLKSource_HXT)  || \
                                     ((SOURCE) == RCC_SYSCLKSource_PLLRCLK) || \
                                     ((SOURCE) == RCC_SYSCLKSource_LXT))
#elif defined(SC32f11xx) || defined(SC32f12xx)
typedef enum
{
    RCC_SYSCLKSource_HIRC_2   = ( uint16_t ) ( ~RCC_CFG0_SYSCLKSW ), /*!< SYSCLK Source £º HIRC/2 */
    RCC_SYSCLKSource_LIRC    =
        ( uint16_t ) ( ( 0x00 << RCC_CFG0_SYSCLKSEL_Pos ) ), /*!< SYSCLK Source £º LIRC */
    RCC_SYSCLKSource_HXT    =
        ( uint16_t ) ( ( 0x01 << RCC_CFG0_SYSCLKSEL_Pos ) ), /*!< SYSCLK Source £º HXT */
    RCC_SYSCLKSource_HIRC =
        ( uint16_t ) ( ( 0x02 << RCC_CFG0_SYSCLKSEL_Pos ) ), /*!< SYSCLK Source £º HIRC */
    RCC_SYSCLKSource_LXT    =
        ( uint16_t ) ( ( 0x03 << RCC_CFG0_SYSCLKSEL_Pos ) ), /*!< SYSCLK Source £º LXT */
} RCC_SYSCLKSource_TypeDef;

#define IS_RCC_SYSCLKSOURCE(SOURCE) (((SOURCE) == RCC_SYSCLKSource_HIRC_2) || \
                                     ((SOURCE) == RCC_SYSCLKSource_LIRC) || \
                                     ((SOURCE) == RCC_SYSCLKSource_HXT)  || \
                                     ((SOURCE) == RCC_SYSCLKSource_HIRC) || \
                                     ((SOURCE) == RCC_SYSCLKSource_LXT))
#elif defined(SC32f15xx)
/** @defgroup RCC_SysTickSource SysTick Clock Source
 * @{
 */
typedef enum
{
  RCC_SYSCLKSource_HIRC_2   = (uint16_t)(~RCC_CFG0_SYSCLKSW),    /*!< SYSCLK Source £º HIRC/2 */
  RCC_SYSCLKSource_LIRC    =
    (uint16_t)((0x00 << RCC_CFG0_SYSCLKSEL_Pos)),/*!< SYSCLK Source £º LIRC */
  RCC_SYSCLKSource_HIRC =
    (uint16_t)((0x02 << RCC_CFG0_SYSCLKSEL_Pos)),/*!< SYSCLK Source £º HIRC */
  RCC_SYSCLKSource_LXT    =
    (uint16_t)((0x03 << RCC_CFG0_SYSCLKSEL_Pos)),/*!< SYSCLK Source £º LXT */
} RCC_SYSCLKSource_TypeDef;

#define IS_RCC_SYSCLKSOURCE(SOURCE) (((SOURCE) == RCC_SYSCLKSource_HIRC) || \
                                     ((SOURCE) == RCC_SYSCLKSource_LIRC) || \
                                     ((SOURCE) == RCC_SYSCLKSource_HIRC_2) || \
                                     ((SOURCE) == RCC_SYSCLKSource_LXT))

#endif
/**
 * @}
 */

/** @brief RCC_SysTickSource SysTick Clock Source
 * @{
 */
typedef enum
{
    RCC_SysTickSource_HCLK_DIV8 =
        ( uint8_t ) ( 0X00 << RCC_CFG1_STCLKSEL_Pos ), /*!< SysTickCLK clock = HCLK/8 */
    RCC_SysTickSource_HIRC_DIV2  =
        ( uint8_t ) ( 0X01 << RCC_CFG1_STCLKSEL_Pos ), /*!< SysTickCLK clock = HIRC/2 */
    RCC_SysTickSource_HXT_DIV2  =
        ( uint8_t ) ( 0X02 << RCC_CFG1_STCLKSEL_Pos ), /*!< SysTickCLK clock = HXT/2 */
    RCC_SysTickSource_LIRC  =
        ( uint8_t ) ( 0X03 << RCC_CFG1_STCLKSEL_Pos ), /*!< SysTickCLK clock = LIRC */
    RCC_SysTickSource_LXT  =
        ( uint8_t ) ( 0X04 << RCC_CFG1_STCLKSEL_Pos ), /*!< SysTickCLK clock = LXT */
    RCC_SysTickSource_HCLK = ( uint8_t ) ( 0X01 ), /*!< SysTickCLK clock = HCLK */
} RCC_SysTickSource_TypeDef;

#define IS_RCC_SYSTICKSOURCE(SOURCE) (((SOURCE) == RCC_SysTickSource_HCLK_DIV8) || \
                                      ((SOURCE) == RCC_SysTickSource_HIRC_DIV2) || \
                                      ((SOURCE) == RCC_SysTickSource_HXT_DIV2) || \
                                      ((SOURCE) == RCC_SysTickSource_LIRC) || \
                                      ((SOURCE) == RCC_SysTickSource_LXT)|| \
                                      ((SOURCE) == RCC_SysTickSource_HCLK))
/**
 * @}
 */

/** @brief RCC_HCLK HCLK clock Source
 * @{
 */
typedef enum
{
    RCC_SYSCLK_Div1  = ( uint32_t ) ( 0x00 << AHB_CFG_CLKDIV_Pos ), /*!< AHB clock = SYSCLK */
    RCC_SYSCLK_Div2  = ( uint32_t ) ( 0x01 << AHB_CFG_CLKDIV_Pos ), /*!< AHB clock = SYSCLK/2 */
    RCC_SYSCLK_Div4  = ( uint32_t ) ( 0x02 << AHB_CFG_CLKDIV_Pos ), /*!< AHB clock = SYSCLK/4 */
    RCC_SYSCLK_Div8  = ( uint32_t ) ( 0x03 << AHB_CFG_CLKDIV_Pos ), /*!< AHB clock = SYSCLK/8 */
    RCC_SYSCLK_Div16 = ( uint32_t ) ( 0x04 << AHB_CFG_CLKDIV_Pos ), /*!< AHB clock = SYSCLK/16 */
} RCC_HCLK_TypeDef;

#define IS_RCC_HCLK(HCLK) (((HCLK) == RCC_SYSCLK_Div1) || \
                           ((HCLK) == RCC_SYSCLK_Div2) || \
                           ((HCLK) == RCC_SYSCLK_Div4) || \
                           ((HCLK) == RCC_SYSCLK_Div8) || \
                           ((HCLK) == RCC_SYSCLK_Div16))

/**
 * @}
 */

/** @brief RCC_PCLK  RCC PCLK
 * @{
 */

typedef enum
{
    RCC_HCLK_Div1		= ( uint32_t ) ( 0x00 << AHB_CFG_CLKDIV_Pos ), /*!< APB clock = AHB */
    RCC_HCLK_Div2		= ( uint32_t ) ( 0x01 << AHB_CFG_CLKDIV_Pos ), /*!< APB clock = AHB/2 */
    RCC_HCLK_Div4		= ( uint32_t ) ( 0x02 << AHB_CFG_CLKDIV_Pos ), /*!< APB clock = AHB/4 */
    RCC_HCLK_Div8  	= ( uint32_t ) ( 0x03 << AHB_CFG_CLKDIV_Pos ), /*!< APB clock = AHB/8 */
    RCC_HCLK_Div16 	= ( uint32_t ) ( 0x04 << AHB_CFG_CLKDIV_Pos ), /*!< APB clock = AHB/16 */
    RCC_HCLK_Div32 	= ( uint32_t ) ( 0x05 << AHB_CFG_CLKDIV_Pos ), /*!< APB clock = AHB/32 */
    RCC_HCLK_Div64 	= ( uint32_t ) ( 0x06 << AHB_CFG_CLKDIV_Pos ), /*!< APB clock = AHB/64 */
    RCC_HCLK_Div128 = ( uint32_t ) ( 0x07 << AHB_CFG_CLKDIV_Pos ), /*!< APB clock = AHB/128 */
} RCC_PCLK_TypeDef;

#define IS_RCC_PCLK(PCLK) (((PCLK) == RCC_HCLK_Div1) || \
                           ((PCLK) == RCC_HCLK_Div2) || \
                           ((PCLK) == RCC_HCLK_Div4) || \
                           ((PCLK) == RCC_HCLK_Div8) || \
                           ((PCLK) == RCC_HCLK_Div16)|| \
                           ((PCLK) == RCC_HCLK_Div32)|| \
                           ((PCLK) == RCC_HCLK_Div64)|| \
                           ((PCLK) == RCC_HCLK_Div128))
/**
 * @}
 */

/** @brief RCC_LCDLEDCLKSource LCDLED clock Source
 * @{
 */
#if defined(SC32f11xx) || defined(SC32f12xx)|| defined(SC32f10xx)
typedef enum
{
    RCC_LCDLEDCLKSource_LIRC = ( uint32_t ) ( 0x00 << RCC_CFG1_LCDCLKSEL_Pos ), /*!< LCD_LED clock = LIRC */
    RCC_LCDLEDCLKSource_LXT  = ( uint32_t ) ( 0x01 << RCC_CFG1_LCDCLKSEL_Pos ), /*!< LCD_LED clock = LXT */
} RCC_LCDLEDCLKSource_TypeDef;

#define RCC_LCDLEDCLKSOURCE(SOURCE) (((SOURCE) == RCC_LCDLEDCLKSource_LIRC) || \
																		((SOURCE) == RCC_LCDLEDCLKSource_LXT))
#endif
/**
 * @}
 */

/** @brief RCC_BTMCLKSource BTM clock Source
* @{
*/
typedef enum
{
    RCC_BTMCLKSource_LIRC = ( uint32_t ) ( 0x00 << RCC_CFG1_BTMCLKSEL_Pos ), /*!< BTM clock = LIRC */
    RCC_BTMCLKSource_LXT  = ( uint32_t ) ( 0x01 << RCC_CFG1_BTMCLKSEL_Pos ), /*!< BTM clock = LXT */
} RCC_BTMCLKSource_TypeDef;

#define RCC_BTMCLKSOURCE(SOURCE) (((SOURCE) == RCC_BTMCLKSource_LIRC) || \
                                  ((SOURCE) == RCC_BTMCLKSource_LXT))

/**
 * @}
 */
#if defined(SC32f10xx)
/** @brief RCC_PLLCLKSource PLL clock Source
* @{
*/
typedef enum
{
    RCC_PLLCLKSource_HIRC  = ( uint32_t ) ( 0x00 << PLL_CFG_PLLCLKSEL_Pos ), /*!< PLL clock = HIRC */
    RCC_PLLCLKSource_HXT   = ( uint32_t ) ( 0x01 << PLL_CFG_PLLCLKSEL_Pos ), /*!< PLL clock = HXT */
} RCC_PLLCLKSource_TypeDef;

#define RCC_PLLCLKSOURCE(SOURCE) (((SOURCE) == RCC_PLLCLKSource_HXT) || \
                                  ((SOURCE) == RCC_PLLCLKSource_HIRC))
/**
 * @}
 */
#endif
/** @defgroup RCC_PWM0CLKSELSource PWM0 clock Source
 * @{
 */


#if defined(SC32f12xx) || defined(SC32f11xx)
typedef enum
{
    RCC_PWM0CLKSource_PCLK = ( uint32_t ) ( 0x00 << RCC_CFG1_PWM0CLKSEL_Pos ), /*!< PWM0 clock = PCLK */
    RCC_PWM0CLKSource_Div1HIRC = ( uint32_t ) ( 0x01 << RCC_CFG1_PWM0CLKSEL_Pos ), /*!< PWM0 clock = HIRC */
} RCC_PWM0CLKSource_TypeDef;

#define RCC_PWM0CLKSOURCE(SOURCE) (((SOURCE) == RCC_PWM0CLKSource_PCLK) || \
                                   ((SOURCE) == RCC_PWM0CLKSource_Div1HIRC))
#elif defined(SC32f10xx)
typedef enum
{
    RCC_PWM0CLKSource_PCLK = ( uint32_t ) ( 0x00 << RCC_CFG1_PWM0CLKSEL_Pos ), /*!< PWM0 clock = PCLK */
    RCC_PWM0CLKSource_PLLQ = ( uint32_t ) ( 0x01 << RCC_CFG1_PWM0CLKSEL_Pos ), /*!< PWM0 clock = PLL */
} RCC_PWM0CLKSource_TypeDef;

#define RCC_PWM0CLKSOURCE(SOURCE) (((SOURCE) == RCC_PWM0CLKSource_PCLK) || \
                                   ((SOURCE) == RCC_PWM0CLKSource_PLLQ))
#endif
/**
 * @}
 */
/** @brief RCC_AHBPeriph AHB Periph
 * @{
 */
#if defined(SC32f10xx) || defined(SC32f12xx)
typedef enum
{
    RCC_AHBPeriph_DMA = ( uint8_t ) AHB_CFG_DMAEN,
    RCC_AHBPeriph_CRC = ( uint8_t ) AHB_CFG_CRCEN,
    RCC_AHBPeriph_IFB = ( uint8_t ) AHB_CFG_IFBEN,
    RCC_AHBPeriph_ALL = ( uint8_t ) 0X07,
} RCC_AHBPeriph_TypeDef;
#define IS_RCC_AHBPERIPH(PERIPH) ((((PERIPH) & (uint8_t)0xF8) == 0x00) && ((PERIPH) != (uint8_t)0x00))
#elif defined(SC32f11xx) || defined(SC32f15xx)
typedef enum
{
    RCC_AHBPeriph_DMA = ( uint8_t ) AHB_CFG_DMAEN,
    RCC_AHBPeriph_CRC = ( uint8_t ) AHB_CFG_CRCEN,
    RCC_AHBPeriph_IFB = ( uint8_t ) AHB_CFG_IFBEN,
    RCC_AHBPeriph_CAN = ( uint8_t ) AHB_CFG_CANEN,
    RCC_AHBPeriph_ALL = ( uint8_t ) 0X17,
} RCC_AHBPeriph_TypeDef;
#define IS_RCC_AHBPERIPH(PERIPH) ((((PERIPH) & (uint8_t)0xE8) == 0x00) && ((PERIPH) != (uint8_t)0x00))
#endif
/**
 * @}
 */

/** @brief RCC_APB0Periph APB0 Periph
* @{
*/
#if defined(SC32f10xx)
typedef enum
{
    RCC_APB0Periph_TIM0  = ( uint16_t ) APB0_CFG_TIM0EN,
    RCC_APB0Periph_TIM1  = ( uint16_t ) APB0_CFG_TIM1EN,
    RCC_APB0Periph_TIM2  = ( uint16_t ) APB0_CFG_TIM2EN,
    RCC_APB0Periph_TIM3  = ( uint16_t ) APB0_CFG_TIM3EN,
    RCC_APB0Periph_TWI0  = ( uint16_t ) APB0_CFG_TWI0EN,
    RCC_APB0Periph_SPI0  = ( uint16_t ) APB0_CFG_SPI0EN,
    RCC_APB0Periph_UART0 = ( uint16_t ) APB0_CFG_UART0EN,
    RCC_APB0Periph_UART1 = ( uint16_t ) APB0_CFG_UART1EN,
    RCC_APB0Periph_PWM0  = ( uint16_t ) APB0_CFG_PWM0EN,
    RCC_APB0Periph_ALL   = ( uint16_t ) 0X01FF,
} RCC_APB0Periph_TypeDef;
#define IS_RCC_APB0PERIPH(PERIPH) ((((PERIPH) & (uint8_t)0xFE00) == 0x00) && ((PERIPH) != (uint16_t)0x00))


#elif defined(SC32f11xx) || defined(SC32f12xx)
typedef enum
{
    RCC_APB0Periph_TIM0  = ( uint16_t ) APB0_CFG_TIM0EN,
    RCC_APB0Periph_TIM1  = ( uint16_t ) APB0_CFG_TIM1EN,
    RCC_APB0Periph_TIM2  = ( uint16_t ) APB0_CFG_TIM2EN,
    RCC_APB0Periph_TIM3  = ( uint16_t ) APB0_CFG_TIM3EN,
    RCC_APB0Periph_TWI0  = ( uint16_t ) APB0_CFG_TWI0EN,
    RCC_APB0Periph_SPI0  = ( uint16_t ) APB0_CFG_SPI0EN,
    RCC_APB0Periph_UART0 = ( uint16_t ) APB0_CFG_UART0EN,
    RCC_APB0Periph_UART1 = ( uint16_t ) APB0_CFG_UART1EN,
    RCC_APB0Periph_PWM0  = ( uint16_t ) APB0_CFG_PWM0EN,
    RCC_APB0Periph_UART5 = ( uint16_t ) APB0_CFG_UART5EN,
    RCC_APB0Periph_ALL   = ( uint16_t ) 0X03FF,
} RCC_APB0Periph_TypeDef;
#define IS_RCC_APB0PERIPH(PERIPH) ((((PERIPH) & (uint8_t)0xFC00) == 0x00) && ((PERIPH) != (uint16_t)0x00))
#elif defined(SC32f15xx) 

typedef enum
{
  RCC_APB0Periph_TIM0   = (uint16_t)APB0_CFG_TIM0EN,
  RCC_APB0Periph_TIM1   = (uint16_t)APB0_CFG_TIM1EN,
  RCC_APB0Periph_TWI0   = (uint16_t)APB0_CFG_TWI0EN,
  RCC_APB0Periph_SPI0   = (uint16_t)APB0_CFG_SPI0EN,
  RCC_APB0Periph_UART0  = (uint16_t)APB0_CFG_UART0EN,
  RCC_APB0Periph_UART1  = (uint16_t)APB0_CFG_UART1EN,
  RCC_APB0Periph_ALL    = (uint16_t)0X00F3,
} RCC_APB0Periph_TypeDef;
#define IS_RCC_APB0PERIPH(PERIPH) ((((PERIPH) & (uint8_t)0x0C) == 0x00) && ((PERIPH) != (uint16_t)0x00))
#endif

/**
 * @}
 */

/** @brief RCC_APB1Periph APB1 Periph
* @{
*/
#if defined(SC32f10xx)
typedef enum
{
    RCC_APB1Periph_TIM4  = ( uint16_t ) APB1_CFG_TIM4EN,
    RCC_APB1Periph_TIM5  = ( uint16_t ) APB1_CFG_TIM5EN,
    RCC_APB1Periph_TIM6  = ( uint16_t ) APB1_CFG_TIM6EN,
    RCC_APB1Periph_TIM7  = ( uint16_t ) APB1_CFG_TIM7EN,
    RCC_APB1Periph_TWI1  = ( uint16_t ) APB1_CFG_TWI1EN,
    RCC_APB1Periph_UART2  = ( uint16_t ) APB1_CFG_UART2EN,
    RCC_APB1Periph_ALL   = ( uint16_t ) 0X009F,
} RCC_APB1Periph_TypeDef;
#define IS_RCC_APB1PERIPH(PERIPH) ((((PERIPH) & (uint8_t)0xFF60) == 0x00) && ((PERIPH) != (uint16_t)0x00))

#elif defined(SC32f11xx)
typedef enum
{
    RCC_APB1Periph_TIM4  = ( uint16_t ) APB1_CFG_TIM4EN,
    RCC_APB1Periph_TIM5  = ( uint16_t ) APB1_CFG_TIM5EN,
    RCC_APB1Periph_TIM6  = ( uint16_t ) APB1_CFG_TIM6EN,
    RCC_APB1Periph_TIM7  = ( uint16_t ) APB1_CFG_TIM7EN,
    RCC_APB1Periph_TWI1  = ( uint16_t ) APB1_CFG_TWI1EN,
    RCC_APB1Periph_UART4  = ( uint16_t ) APB1_CFG_UART4EN,
    RCC_APB1Periph_UART2  = ( uint16_t ) APB1_CFG_UART2EN,
    RCC_APB1Periph_ALL   = ( uint16_t ) 0X00DF,
} RCC_APB1Periph_TypeDef;
#define IS_RCC_APB1PERIPH(PERIPH) ((((PERIPH) & (uint8_t)0xFF20) == 0x00) && ((PERIPH) != (uint16_t)0x00))

#elif defined(SC32f12xx)
typedef enum
{
    RCC_APB1Periph_TIM4  = ( uint16_t ) APB1_CFG_TIM4EN,
    RCC_APB1Periph_TIM5  = ( uint16_t ) APB1_CFG_TIM5EN,
    RCC_APB1Periph_TIM6  = ( uint16_t ) APB1_CFG_TIM6EN,
    RCC_APB1Periph_TIM7  = ( uint16_t ) APB1_CFG_TIM7EN,
    RCC_APB1Periph_TWI1  = ( uint16_t ) APB1_CFG_TWI1EN,
    RCC_APB1Periph_SPI1  = ( uint16_t ) APB1_CFG_SPI1EN,
    RCC_APB1Periph_UART4  = ( uint16_t ) APB1_CFG_UART4EN,
    RCC_APB1Periph_UART2  = ( uint16_t ) APB1_CFG_UART2EN,
    RCC_APB1Periph_SPI2  = ( uint16_t ) APB1_CFG_SPI2EN,
    RCC_APB1Periph_ALL   = ( uint16_t ) 0X01FF,
} RCC_APB1Periph_TypeDef;
#define IS_RCC_APB1PERIPH(PERIPH) ((((PERIPH) & (uint8_t)0xFE00) == 0x00) && ((PERIPH) != (uint16_t)0x00))
#elif defined(SC32f15xx)

/** @defgroup RCC_APB1Periph APB1 Periph
* @{
*/
typedef enum
{
  RCC_APB1Periph_TIM2       = (uint16_t)APB1_CFG_TIM2EN,
  RCC_APB1Periph_TIM3       = (uint16_t)APB1_CFG_TIM3EN,
  RCC_APB1Periph_SPI1_TWI1  = (uint16_t)APB1_CFG_SPI1_TWI1EN,
  RCC_APB1Periph_UART2      = (uint16_t)APB1_CFG_UART2EN,
  RCC_APB1Periph_ALL        = (uint16_t)0X0093,
} RCC_APB1Periph_TypeDef;
#define IS_RCC_APB1PERIPH(PERIPH) ((((PERIPH) & (uint8_t)0xFF6C) == 0x00) && ((PERIPH) != (uint16_t)0x00))

#endif
/**
 * @}
 */

/** @brief RCC_APB2Periph APB2 Periph
* @{
*/
#if defined(SC32f10xx) ||  defined(SC32f11xx)||  defined(SC32f12xx)
typedef enum
{
    RCC_APB2Periph_LEDPWM   = ( uint16_t ) APB2_CFG_LEDPWMEN,
    RCC_APB2Periph_LCD_LED  = ( uint16_t ) APB2_CFG_LCDEN,
    RCC_APB2Periph_UART3    = ( uint16_t ) APB2_CFG_UART3EN,
    RCC_APB2Periph_ALL      = ( uint16_t ) 0X0007,
} RCC_APB2Periph_TypeDef;
#define IS_RCC_APB2PERIPH(PERIPH) ((((PERIPH) & (uint8_t)0xFFF8) == 0x00) && ((PERIPH) != (uint16_t)0x00))
#elif defined(SC32f15xx) 
/** @defgroup RCC_APB2Periph APB2 Periph
* @{
*/
typedef enum
{
  RCC_APB2Periph_QEP0  = (uint16_t)APB2_CFG_QEP0EN,
  RCC_APB2Periph_QEP1  = (uint16_t)APB2_CFG_QEP1EN,
  RCC_APB2Periph_ADC   = (uint16_t)APB2_CFG_ADCEN,
  RCC_APB2Periph_ALL   = (uint16_t)0X004C,
} RCC_APB2Periph_TypeDef;
#define IS_RCC_APB2PERIPH(PERIPH) ((((PERIPH) & (uint8_t)0xFFA0) == 0x00) && ((PERIPH) != (uint16_t)0x00))
#endif
/**
 * @}
 */
/** @defgroup NMI_CFG Periph NMI Periph
* @{
*/
#if defined(SC32f10xx) ||  defined(SC32f11xx)||  defined(SC32f12xx)
typedef enum
{
    RCC_NMIPeriph_CSS = ( uint16_t ) NMI_CFG_CSSEN,
    RCC_NMIPeriph_CMP = ( uint16_t ) NMI_CFG_CMPEN,
    RCC_NMIPeriph_INT0    = ( uint16_t ) NMI_CFG_INT0EN,
#if defined(SC32f11xx) || defined(SC32f12xx)
    RCC_NMIPeriph_SRAMPE      = ( uint16_t ) NMI_CFG_SRAMPEEN,
#endif
    RCC_NMIPeriph_ALL  = ( uint16_t ) 0X0F,
} RCC_NMIPeriph_TypeDef;
#define IS_RCC_NMIPeriph(NMIPeriph) ((((NMIPeriph) & (uint8_t)0xFF00) == 0x00) && ((NMIPeriph) != (uint16_t)0x00))
#elif defined(SC32f15xx) 
typedef enum
{
  RCC_NMIPeriph_INT0    = (uint16_t)NMI_CFG_INT0EN,
  RCC_NMIPeriph_SRAMPE      = (uint16_t)NMI_CFG_SRAMPEEN,
  RCC_NMIPeriph_OP2  = (uint16_t)NMI_CFG_OP2EN,
  RCC_NMIPeriph_OP1      = (uint16_t)NMI_CFG_OP1EN,
  RCC_NMIPeriph_CMP3      = (uint16_t)NMI_CFG_CMP3EN,
	RCC_NMIPeriph_CMP0    = (uint16_t)NMI_CFG_CMP0EN,
	RCC_NMIPeriph_ALL  = (uint16_t)0XFC,
} RCC_NMIPeriph_TypeDef;
#define IS_RCC_NMIPeriph(NMIPeriph) ((((NMIPeriph) & (uint8_t)0xFF00) == 0x00) && ((NMIPeriph) != (uint16_t)0x00))
#endif


typedef enum
{
    RCC_WAIT_0 = ( uint16_t ) 0x00 << RCC_CFG0_WAIT_Pos, /*!< Wait number selection 0 */
    RCC_WAIT_1 = ( uint16_t ) 0x01 << RCC_CFG0_WAIT_Pos, /*!< Wait number selection 1 */
    RCC_WAIT_2 = ( uint16_t ) 0x02 << RCC_CFG0_WAIT_Pos, /*!< Wait number selection 2 */
    RCC_WAIT_3 = ( uint16_t ) 0x03 << RCC_CFG0_WAIT_Pos, /*!< Wait number selection 3 */
} RCC_Wait_TypeDef;
#define IS_RCC_Wait(Wait) (((Wait) == RCC_WAIT_0) ||  \
                           ((Wait) == RCC_WAIT_1)||\
                           ((Wait) == RCC_WAIT_2)||\
                           ((Wait) == RCC_WAIT_3))
/** @brief RCC_FLAG RCC FLAG
* @{
*/
#if defined(SC32f10xx)
typedef enum
{
    RCC_FLAG_CLKIF   = ( uint8_t ) RCC_STS_CLKFIF, /*!< RCC FLAG: Clock source exception flag */
    RCC_FLAG_LOCKERR = ( uint8_t ) RCC_STS_LOCKERR, /*!< RCC FLAG: PLL out-of-lock record flag */
    RCC_FLAG_PLLRDY  = ( uint8_t ) RCC_STS_PLLRDY, /*!< RCC FLAG: PLL Clock Ready Flag */
} RCC_FLAG_TypeDef;

#define IS_RCC_FLAG(FLAG) ((((FLAG) & (uint8_t)0xFFF8) == 0x00) && ((FLAG) != (uint16_t)0x00))
#define IS_GET_RCC_FLAG(FLAG) (((FLAG) == RCC_FLAG_CLKIF) ||  \
                               ((FLAG) == RCC_FLAG_LOCKERR) || \
                               ((FLAG) == RCC_FLAG_PLLRDY))
#elif  defined(SC32f11xx) ||  defined(SC32f12xx) ||defined(SC32f15xx)
typedef enum
{
	#if defined(SC32f11xx) ||  defined(SC32f12xx)
    RCC_FLAG_CLKIF   = ( uint8_t ) RCC_STS_CLKFIF, /*!< CLKIF FLAG: Clock source exception flag */
	#endif
    RCC_FLAG_SRAMPEIF = ( uint8_t ) RCC_STS_SRAMPEIF, /*!< SRAMPEIF FLAG: SRAM parity error flag */
} RCC_FLAG_TypeDef;
#if  defined(SC32f11xx) ||  defined(SC32f12xx)
#define IS_RCC_FLAG(FLAG) ((((FLAG) & (uint8_t)0xFFF6) == 0x00) && ((FLAG) != (uint16_t)0x00))
#define IS_GET_RCC_FLAG(FLAG) (((FLAG) == RCC_FLAG_CLKIF) ||  \
                               ((FLAG) == RCC_FLAG_SRAMPEIF))
#elif  defined(SC32f15xx)
#define IS_RCC_FLAG(FLAG) ((((FLAG) & (uint8_t)0xFFF6) == 0x00) && ((FLAG) != (uint16_t)0x00))
#define IS_GET_RCC_FLAG(FLAG) (((FLAG) == RCC_FLAG_SRAMPEIF))
#endif
#endif
/**
 * @}
 */
#if defined(SC32f10xx)
/** @defgroup RLL_Factor  RLL Factor
 * @{
 */
/** @brief RLL_Factor  RLL Factor
 * @{
 */

typedef struct
{
    uint32_t PLLM; /*!<	Prescaler M */
    uint32_t PLLN; /*!< PLL multiplication factor N */
    uint32_t PLLP; /*!< PLLRCLK Clock output dividing Coefficient */
} RLL_Factor_TypeDef;
#endif

/** @brief RCC_ClocksTypeDef
 * @{
 */

typedef struct
{
    uint32_t SYSCLK_Frequency; /*!<  SYSCLK clock frequency expressed in Hz */
    uint32_t HCLK_Frequency;   /*!<  HCLK clock frequency expressed in Hz   */
    uint32_t PCLK0_Frequency;  /*!<  PCLK0 clock frequency expressed in Hz  */
    uint32_t PCLK1_Frequency;  /*!<  PCLK1 clock frequency expressed in Hz  */
    uint32_t PCLK2_Frequency;  /*!<  PCLK2 clock frequency expressed in Hz  */
} RCC_ClocksTypeDef;

/**
 * @}
 */

/**
 * @}
 */
/* End of struct -----------------------------------------------------*/


/* Configuration of the RCC computation unit **********************************/
void RCC_DeInit ( void );

/* Internal/external clocks, PLL configuration functions *********/

ErrorStatus RCC_Unlock ( uint8_t TimeLimit );

#if !defined(SC32f15xx)
void RCC_HXTCmd ( FunctionalState NewState );
#endif
void RCC_LXTCmd ( FunctionalState NewState );
void RCC_HIRCCmd ( FunctionalState NewState );
void RCC_LIRCCmd ( FunctionalState NewState );

#if defined(SC32f10xx)
void RCC_PLLCmd ( FunctionalState NewState );
void RCC_PLLRCmd ( FunctionalState NewState );
void RCC_PLLConfig ( RCC_PLLCLKSource_TypeDef RCC_PLLCLKSource, RLL_Factor_TypeDef* PLL_Factor );
#endif
#if defined(SC32f11xx)||defined(SC32f12xx)||defined(SC32f15xx)
void RCC_HIRCDIV1Cmd ( FunctionalState NewState );
#endif
void RCC_APB0Cmd ( FunctionalState NewState );
void RCC_APB1Cmd ( FunctionalState NewState );
void RCC_APB2Cmd ( FunctionalState NewState );


/* System, AHB and APB busses clocks configuration functions ******************/
ErrorStatus RCC_SYSCLKConfig ( RCC_SYSCLKSource_TypeDef RCC_SYSCLKSource );
RCC_SYSCLKSource_TypeDef RCC_GetSYSCLKSource ( void );
void RCC_HCLKConfig ( RCC_HCLK_TypeDef RCC_HCLKCLKSource );
void RCC_APB0Config ( RCC_PCLK_TypeDef RCC_APB0CLKSource );
void RCC_APB1Config ( RCC_PCLK_TypeDef RCC_APB1CLKSource );
void RCC_APB2Config ( RCC_PCLK_TypeDef RCC_APB2CLKSource );
void RCC_GetClocksFreq ( RCC_ClocksTypeDef* RCC_Clocks );
void RCC_WaitConfig ( RCC_Wait_TypeDef RCC_Wait );
/* Peripheral clocks configuration functions **********************************/
#if defined (SC32f11xx)|| defined(SC32f12xx)
void RCC_PWM0CLKConfig ( RCC_PWM0CLKSource_TypeDef RCC_PWM0CLKSource );
#endif
#if defined (SC32f11xx)|| defined(SC32f12xx)|| defined(SC32f10xx)
void RCC_LCDLEDCLKConfig ( RCC_LCDLEDCLKSource_TypeDef RCC_LCDLEDCLKSource );
#endif
void RCC_BTMCLKConfig ( RCC_BTMCLKSource_TypeDef RCC_BTMCLKSource );

void RCC_AHBPeriphClockCmd ( uint32_t RCC_AHBPeriph, FunctionalState NewState );
void RCC_APB0PeriphClockCmd ( uint32_t RCC_APB0Periph, FunctionalState NewState );
void RCC_APB1PeriphClockCmd ( uint32_t RCC_APB1Periph, FunctionalState NewState );
void RCC_APB2PeriphClockCmd ( uint32_t RCC_APB2Periph, FunctionalState NewState );

void RCC_AHBPeriphResetCmd ( uint32_t RCC_AHBPeriph, FunctionalState NewState );
void RCC_APB0PeriphResetCmd ( uint32_t RCC_APB0Periph, FunctionalState NewState );
void RCC_APB1PeriphResetCmd ( uint32_t RCC_APB1Periph, FunctionalState NewState );
void RCC_APB2PeriphResetCmd ( uint32_t RCC_APB2Periph, FunctionalState NewState );

/* Systick Timer configuration functions **********************************/
void RCC_SystickCLKConfig ( RCC_SysTickSource_TypeDef RCC_SYSTICKSource );
void RCC_SystickSetCounter ( uint32_t Counter );
void RCC_SystickCmd ( FunctionalState NewState );
FlagStatus RCC_SystickGetFlagStatus ( void );

/* Interrupts and flags management functions **********************************/
void RCC_ITConfig ( FunctionalState NewState );
FlagStatus RCC_GetFlagStatus ( uint32_t RCC_FLAG );
void RCC_EnableCSS ( void );

#ifdef __cplusplus
}
#endif

#endif /* __sc32f1xxx_RCC_H */

/**
* @}
*/

/**
* @}
*/

/************************ (C) COPYRIGHT SOC Microelectronics *****END OF FILE****/
