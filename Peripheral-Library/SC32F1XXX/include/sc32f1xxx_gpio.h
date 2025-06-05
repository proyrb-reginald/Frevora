/**
 ******************************************************************************
 * @file    sc32f1xxx_gpio.h
 * @author  SOC AE Team
 * @version V1.7
 * @date     17-10-2024
 * @brief   Header file of GPIO module.
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
#ifndef __sc32f1xxx_GPIO_H
#define __sc32f1xxx_GPIO_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "sc32f1xxx.h"

/** @addtogroup sc32f1xxx_StdPeriph_Driver
 * @{
 */

/** @addtogroup GPIO
 * @{
 */

/** @defgroup GPIO_Enumerations GPIO Enumerations
 * @{
 */

/** @brief GPIO_Mode GPIO Mode
 * @{
 */
typedef enum
{
    GPIO_Mode_IN_HI = 0x00,  /*!< GPIO High-resistance Input Mode   */
    GPIO_Mode_IN_PU = 0x01,  /*!< GPIO Pull-up Input Mode  */
    GPIO_Mode_OUT_PP = 0x02  /*!< GPIO Strong push-pull Output Mode   */
} GPIO_Mode_TypeDef;

#define IS_GPIO_MODE(MODE) (((MODE) == GPIO_Mode_IN_HI) ||\
														((MODE) == GPIO_Mode_IN_PU) ||\
                            ((MODE) == GPIO_Mode_OUT_PP))
/**
 * @}
 */

/** @brief GPIO_DriveLevel GPIO DriveLevel
 * @{
 */
typedef enum
{
    GPIO_DriveLevel_0 = 0x00, /*!< I/O output Drive: Level 0(Max) */
    GPIO_DriveLevel_1 = 0x01, /*!< I/O output Drive: Level 1 */
    GPIO_DriveLevel_2 = 0x02, /*!< I/O output Drive: Level 2 */
    GPIO_DriveLevel_3 = 0x03  /*!< I/O output Drive: Level 3 */
} GPIO_DriveLevel_TypeDef;

#define IS_GPIO_DriveLevel(LEVEL)	(((LEVEL) == GPIO_DriveLevel_0) ||\
																	((LEVEL) == GPIO_DriveLevel_1) ||\
																	((LEVEL) == GPIO_DriveLevel_2) ||\
																	((LEVEL) == GPIO_DriveLevel_3))

/**
 * @}
 */

/** @brief   BitAction
 * @{
 */
typedef enum
{
    Bit_RESET = 0,
    Bit_SET
} BitAction;

#define IS_GPIO_BITACTION(STATE) (((STATE) == Bit_RESET) || ((STATE) == Bit_SET))

/**
 * @}
 */
#if defined(SC32f10xx) || defined(SC32f12xx)|| defined(SC32f15xx)
#define IS_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == GPIOA) || \
                                    ((PERIPH) == GPIOB) || \
                                    ((PERIPH) == GPIOC))
#elif defined(SC31f11xx)
#define IS_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == GPIOA) || \
                                    ((PERIPH) == GPIOB) || \
                                    ((PERIPH) == GPIOC) || \
                                    ((PERIPH) == GPIOD))
#endif
/** @brief GPIO_Pin GPIO Pins enumeration
 * @{
 */
typedef enum
{
    GPIO_Pin_0 = ( ( uint16_t ) 0x0001 ), /*!< Pin 0 selected    */
    GPIO_Pin_1 = ( ( uint16_t ) 0x0002 ), /*!< Pin 1 selected    */
    GPIO_Pin_2 = ( ( uint16_t ) 0x0004 ), /*!< Pin 2 selected    */
    GPIO_Pin_3 = ( ( uint16_t ) 0x0008 ), /*!< Pin 3 selected    */
    GPIO_Pin_4 = ( ( uint16_t ) 0x0010 ), /*!< Pin 4 selected    */
    GPIO_Pin_5 = ( ( uint16_t ) 0x0020 ), /*!< Pin 5 selected    */
    GPIO_Pin_6 = ( ( uint16_t ) 0x0040 ), /*!< Pin 6 selected    */
    GPIO_Pin_7 = ( ( uint16_t ) 0x0080 ), /*!< Pin 7 selected    */
    GPIO_Pin_8 = ( ( uint16_t ) 0x0100 ), /*!< Pin 8 selected    */
    GPIO_Pin_9 = ( ( uint16_t ) 0x0200 ), /*!< Pin 9 selected    */
    GPIO_Pin_10 = ( ( uint16_t ) 0x0400 ), /*!< Pin 10 selected    */
    GPIO_Pin_11 = ( ( uint16_t ) 0x0800 ), /*!< Pin 11 selected    */
    GPIO_Pin_12 = ( ( uint16_t ) 0x1000 ), /*!< Pin 12 selected    */
    GPIO_Pin_13 = ( ( uint16_t ) 0x2000 ), /*!< Pin 13 selected    */
    GPIO_Pin_14 = ( ( uint16_t ) 0x4000 ), /*!< Pin 14 selected    */
    GPIO_Pin_15 = ( ( uint16_t ) 0x8000 ), /*!< Pin 15 selected    */
    GPIO_PIN_LNIB = ( ( uint16_t ) 0x00FF ), /*!< Pin Low 8 Bits selected			*/
    GPIO_PIN_HNIB = ( ( uint16_t ) 0xFF00 ), /*!< Pin High 8 Bits selected		*/
    GPIO_PIN_All = ( ( uint16_t ) 0xFFFF ), /* All pins selected */
} GPIO_Pin_TypeDef;



#define GPIO_PIN_MASK 0x0000FFFFU /* PIN mask for assert test */

#define IS_GPIO_PIN(PIN) ((((PIN)&GPIO_PIN_MASK) != 0x00U) && (((PIN) & ~GPIO_PIN_MASK) == 0x00U))

#define IS_GET_GPIO_PIN(PIN) (((PIN) == GPIO_Pin_0) ||  \
                              ((PIN) == GPIO_Pin_1) ||  \
                              ((PIN) == GPIO_Pin_2) ||  \
                              ((PIN) == GPIO_Pin_3) ||  \
                              ((PIN) == GPIO_Pin_4) ||  \
                              ((PIN) == GPIO_Pin_5) ||  \
                              ((PIN) == GPIO_Pin_6) ||  \
                              ((PIN) == GPIO_Pin_7) ||  \
                              ((PIN) == GPIO_Pin_8) ||  \
                              ((PIN) == GPIO_Pin_9) ||  \
                              ((PIN) == GPIO_Pin_10) || \
                              ((PIN) == GPIO_Pin_11) || \
                              ((PIN) == GPIO_Pin_12) || \
                              ((PIN) == GPIO_Pin_13) || \
                              ((PIN) == GPIO_Pin_14) || \
                              ((PIN) == GPIO_Pin_15))

/**
 * @}
 */

/**
 * @}
 */
/* End of Enumerations --------------------------------------------------*/

/** @defgroup GPIO_Struct GPIO Struct
 * @{
 */

/** @brief GPIO_InitTypeDef  GPIO structure definition
 * @{
 */
typedef struct
{
    uint16_t GPIO_Pin;          /*!< Specifies the GPIO pins to be configured.
                                     This parameter can be any value of @ref GPIO_Pin_TypeDef */
    uint16_t GPIO_Mode; /*!< Specifies the operating mode for the selected pins.
                                     This parameter can be a value of @ref GPIO_Mode_TypeDef   */
    uint16_t GPIO_DriveLevel; /*!< Specifies the operating Drive Level for the selected pins.
                                     This parameter can be a value of @ref GPIO_DriveLevel_TypeDef   */
} GPIO_InitTypeDef;

/**
 * @}
 */

/**
 * @}
 */
/* End of Struct --------------------------------------------------*/

/** @addtogroup GPIO_Exported_Functions
 * @{
 */

/* Initialization and de-initialization functions *****************************/
void GPIO_DeInit ( GPIO_TypeDef* GPIOx );
void GPIO_Init ( GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct );
void GPIO_SetDriveLevel ( GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_DriveLevel_TypeDef GPIO_DriveLevel );

/* IO operation functions *****************************************************/
uint16_t GPIO_ReadData ( GPIO_TypeDef* GPIOx );
BitAction GPIO_ReadDataBit ( GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin );
void GPIO_SetBits ( GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin );
void GPIO_ResetBits ( GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin );
void GPIO_Write ( GPIO_TypeDef* GPIOx, uint16_t PortVal );
void GPIO_WriteBit ( GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal );
void GPIO_TogglePins ( GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin );

/**
 * @}
 */
/* End of functions --------------------------------------------------*/

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* _SC32F1XXX_GPIO_H */


