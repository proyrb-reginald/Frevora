/**
 ******************************************************************************
 * @file    sc32f1xxx_int.h
 * @author  SOC AE Team
 * @version V1.7
 * @date     17-10-2024
 * @brief   Header file of INT module.
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
#ifndef __sc32f1xxx_INT_H
#define __sc32f1xxx_INT_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "sc32f1xxx.h"
#include "sc32.h"
#include "sc32f1xxx_rcc.h"

/** @addtogroup sc32f1xxx_StdPeriph_Driver
 * @{
 */

/** @brief INT_Channel INT Int Select
 * @{
 */
typedef enum
{
    INT_Channel_0  = 0x00000001U,   /*!< Int Select: Px0    */
    INT_Channel_1  = 0x00000002U,   /*!< Int Select: Px1    */
    INT_Channel_2  = 0x00000004U,   /*!< Int Select: Px2    */
    INT_Channel_3  = 0x00000008U,   /*!< Int Select: Px3    */
    INT_Channel_4  = 0x00000010U,   /*!< Int Select: Px4    */
    INT_Channel_5  = 0x00000020U,   /*!< Int Select: Px5    */
    INT_Channel_6  = 0x00000040U,   /*!< Int Select: Px6    */
    INT_Channel_7  = 0x00000080U,   /*!< Int Select: Px7    */
    INT_Channel_8  = 0x00000100U,   /*!< Int Select: Px8    */
    INT_Channel_9  = 0x00000200U,   /*!< Int Select: Px9    */
    INT_Channel_10 = 0x00000400U,   /*!< Int Select: Px10    */
    INT_Channel_11 = 0x00000800U,   /*!< Int Select: Px11    */
    INT_Channel_12 = 0x00001000U,   /*!< Int Select: Px12    */
    INT_Channel_13 = 0x00002000U,   /*!< Int Select: Px13    */
    INT_Channel_14 = 0x00004000U,   /*!< Int Select: Px14    */
    INT_Channel_15 = 0x00008000U,   /*!< Int Select: Px15    */
} INT_Channel_Typedef;

#define IS_INT_CHANNEL(CHANNEL) (((CHANNEL) == INT_Channel_0) || \
                                  ((CHANNEL) == INT_Channel_1) || \
                                  ((CHANNEL) == INT_Channel_2) || \
                                  ((CHANNEL) == INT_Channel_3) || \
                                  ((CHANNEL) == INT_Channel_4) || \
                                  ((CHANNEL) == INT_Channel_5) || \
                                  ((CHANNEL) == INT_Channel_6) || \
                                  ((CHANNEL) == INT_Channel_7) || \
                                  ((CHANNEL) == INT_Channel_8) || \
                                  ((CHANNEL) == INT_Channel_9) || \
                                  ((CHANNEL) == INT_Channel_10) || \
                                  ((CHANNEL) == INT_Channel_11) || \
                                  ((CHANNEL) == INT_Channel_12) || \
                                  ((CHANNEL) == INT_Channel_13) || \
                                  ((CHANNEL) == INT_Channel_14) || \
                                  ((CHANNEL) == INT_Channel_15))
/**
 * @}
 */

#define IS_INT_MODE(MODE) (((MODE) == INT_Mode_Interrupt) || ((MODE) == INT_Mode_Event))

#if defined(SC32f10xx) || defined(SC32f12xx) || defined(SC32f15xx)
/** @brief INT_INTSEL INT INTSEL
 * @{
 */
typedef enum
{
    INT_INTSEL_PA = 0x00000000U,   /*!< Int Select: PA    */
    INT_INTSEL_PB = 0x00000001U,   /*!< Int Select: PB    */
    INT_INTSEL_PC = 0x00000002U,   /*!< Int Select: PC    */
} INT_INTSEL_Typedef;

#define IS_INT_INTSEL(INTSEL) (((INTSEL) == INT_INTSEL_PA) || \
                               ((INTSEL) == INT_INTSEL_PB) || \
                               ((INTSEL) == INT_INTSEL_PC))
#elif  defined(SC32f11xx)
typedef enum
{
    INT_INTSEL_PA = 0x00000000U,   /*!< Int Select: PA    */
    INT_INTSEL_PB = 0x00000001U,   /*!< Int Select: PB    */
    INT_INTSEL_PC = 0x00000002U,   /*!< Int Select: PC    */
    INT_INTSEL_PD = 0x00000003U,   /*!< Int Select: PD    */
} INT_INTSEL_Typedef;

#define IS_INT_INTSEL(INTSEL) (((INTSEL) == INT_INTSEL_PA) || \
                               ((INTSEL) == INT_INTSEL_PB) || \
                               ((INTSEL) == INT_INTSEL_PC) || \
                               ((INTSEL) == INT_INTSEL_PD))
#endif
/**
 * @}
 */

/** @brief INT_Trigger INT Trigger
 * @{
 */
typedef enum
{
    INT_Trigger_Null           = ( uint16_t ) 0x00,		/*!< INT Interrupt: Null */
    INT_Trigger_Rising         = ( uint16_t ) 0x01, /*!< INT Interrupt: Rising edge capture */
    INT_Trigger_Falling        = ( uint16_t ) 0x02, /*!< INT Interrupt: Falling edge capture */
    INT_Trigger_Rising_Falling = ( uint16_t ) 0x03,		/*!< INT Interrupt: Rising and Falling edge capture */
} INT_Trigger_TypeDef;

#define IS_INT_TRIGGER(TRIGGER)	(((TRIGGER) == INT_Trigger_Null) || \
																 ((TRIGGER) == INT_Trigger_Rising) || \
																 ((TRIGGER) == INT_Trigger_Rising) || \
																 ((TRIGGER) == INT_Trigger_Rising_Falling))
/**
 * @}
 */

/** @brief INT_IT INT Interrupt
 * @{
 */
typedef enum
{
    INT_IT_Rising         = ( uint16_t ) 0x01, /*!< INT Interrupt: Rising edge capture */
    INT_IT_Falling        = ( uint16_t ) 0x02, /*!< INT Interrupt: Falling edge capture */
} INT_IT_TypeDef;

#define IS_INT_IT(IT)	(((IT) == INT_IT_Null) || \
											 ((IT) == INT_IT_Rising) || \
											 ((IT) == INT_IT_Rising) || \
											 ((IT) == INT_IT_Rising_Falling))
/**
 * @}
 */

/** @brief INT_Flag INT Flag
 * @{
 */
typedef enum
{
    INT_Flag_Rising = ( uint16_t ) 0x01, /*!< INT Flag: INT overflow */
    INT_Flag_Falling = ( uint16_t ) 0x02, /*!< INT Flag: Immediate mode */
} INT_Flag_TypeDef;

#define IS_INT_FLAG(FLAG) (((FLAG) == INT_Flag_Rising) ||  \
                           ((FLAG) == INT_Flag_Falling))
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @brief INT_InitTypeDef
 * @{
 */



typedef struct
{
    uint16_t INT_Channel; /*!<  Specifies the INT channel.
																					This parameter can be a value of @ref INT_ClockDivision */

    uint16_t INT_Trigger; /*!< Specifies the external interrupt triggering mode.
                                         This parameter can be a value of @ref INT_Trigger_TypeDef */

    uint16_t INT_INTSEL;	/*!< Specifies the external interrupt port.
                                         This parameter can be a value of @ref INT_INTSEL_Typedef */

} INT_InitTypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of Struct --------------------------------------------------*/

/** @addtogroup INT_Functions INT Functions
 * @{
 */

/* Initialization and Configuration functions********************************************************/
void INT_DeInit ( void );
void INT_Init ( INT_InitTypeDef* INT_InitStruct );
void INT_TriggerMode ( INT_Channel_Typedef INT_Channel, INT_Trigger_TypeDef Trigger_Mode );

/* Interrupts and flags management functions ***********************************************/
void INT_ITConfig ( uint16_t INT_Channel, uint16_t INT_IT, FunctionalState NewState );
FlagStatus INT_GetFlagStatus ( INT_Channel_Typedef INT_Channel, INT_Flag_TypeDef INT_Flag );
void INT_ClearFlag ( uint32_t INT_Channel );

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

#endif
