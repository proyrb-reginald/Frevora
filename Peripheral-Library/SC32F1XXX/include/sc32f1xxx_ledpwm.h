/**
 ******************************************************************************
 * @file    SC32f10xx_pwm.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    14-10-2024
 * @brief   Header file of LEDPWM module.
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
#ifndef __sc32f1xxx_LEDPWM_H
#define __sc32f1xxx_LEDPWM_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "sc32f1xxx.h"
#include "sc32.h"
#include "sc32f1xxx_rcc.h"

/** @addtogroup SC32f10xx_StdPeriph_Driver
 * @{
 */

/** @addtogroup LEDPWM
 * @{
 */

/** @defgroup LEDPWM_Enumerations LEDPWM Enumerations
 * @{
 */

/** @brief LEDPWM_Prescaler LEDPWM Prescaler
 * @{
 */
typedef enum
{
    LEDPWM_PRESCALER_DIV1	 = ( uint16_t ) ( 0x00U << LEDPWM_CON_PWMCLK_Pos ),	/*!< Clock division: Fsource/1    */
    LEDPWM_PRESCALER_DIV2	 = ( uint16_t ) ( 0x01U << LEDPWM_CON_PWMCLK_Pos ),	/*!< Clock division: Fsource/2    */
    LEDPWM_PRESCALER_DIV4	 = ( uint16_t ) ( 0x02U << LEDPWM_CON_PWMCLK_Pos ),	/*!< Clock division: Fsource/4    */
    LEDPWM_PRESCALER_DIV8	 = ( uint16_t ) ( 0x03U << LEDPWM_CON_PWMCLK_Pos ),	/*!< Clock division: Fsource/8    */
    LEDPWM_PRESCALER_DIV16	 = ( uint16_t ) ( 0x04U << LEDPWM_CON_PWMCLK_Pos ),	/*!< Clock division: Fsource/16    */
    LEDPWM_PRESCALER_DIV32	 = ( uint16_t ) ( 0x05U << LEDPWM_CON_PWMCLK_Pos ),	/*!< Clock division: Fsource/32    */
    LEDPWM_PRESCALER_DIV64	 = ( uint16_t ) ( 0x06U << LEDPWM_CON_PWMCLK_Pos ),	/*!< Clock division: Fsource/64    */
    LEDPWM_PRESCALER_DIV128 = ( uint16_t ) ( 0x07U << LEDPWM_CON_PWMCLK_Pos ), /*!< Clock division: Fsource/128    */
    LEDPWM_PRESCALER_DIV256 = ( uint16_t ) ( 0x08U << LEDPWM_CON_PWMCLK_Pos ), /*!< Clock division: Fsource/256    */
} LEDPWM_Prescaler_TypeDef;

#define IS_LEDPWM_PRESCALER(PRESCALER) (((PRESCALER) == LEDPWM_PRESCALER_DIV1) ||   \
																		 ((PRESCALER) == LEDPWM_PRESCALER_DIV2) ||   \
																		 ((PRESCALER) == LEDPWM_PRESCALER_DIV4) ||   \
																		 ((PRESCALER) == LEDPWM_PRESCALER_DIV8) ||   \
																		 ((PRESCALER) == LEDPWM_PRESCALER_DIV16) ||  \
																		 ((PRESCALER) == LEDPWM_PRESCALER_DIV32) ||  \
																		 ((PRESCALER) == LEDPWM_PRESCALER_DIV64) ||  \
																		 ((PRESCALER) == LEDPWM_PRESCALER_DIV128) || \
																		 ((PRESCALER) == LEDPWM_PRESCALER_DIV256))
/**
 * @}
 */

/** @brief LEDPWM_AlignedMode_TypeDef
 * @{
 */
typedef enum
{
    LEDPWM_AlignmentMode_Edge	 = ( uint16_t ) ( 0x00U << LEDPWM_CON_PWMMD0_Pos ),	 /*!< Edge Alignment mode */
    LEDPWM_AlignmentMode_Center = ( uint16_t ) ( 0x01U << LEDPWM_CON_PWMMD0_Pos ), /*!< Center Alignment mode */
} LEDPWM_AlignedMode_TypeDef;

#define IS_LEDPWM_AlignedMode(MODE) (((MODE) == LEDPWM_AlignmentMode_Edge) || \
																	((MODE) == LEDPWM_AlignmentMode_Center))
/**
 * @}
 */

/** @brief LEDPWM_Channel
 * @{
 */
#if defined(SC32f10xx) ||  defined(SC32f12xx)
typedef enum
{
    LEDPWMChannel_Less = 0x00000000UL, /*!< No channels are selected */
    LEDPWM_Channel_0 = ( int32_t ) 0x00000001UL,	/*!< PMW output channel 0 */
    LEDPWM_Channel_1 = ( int32_t ) 0x00000002UL,	/*!< PMW output channel 1 */
    LEDPWM_Channel_2 = ( int32_t ) 0x00000004UL,	/*!< PMW output channel 2 */
    LEDPWM_Channel_3 = ( int32_t ) 0x00000008UL,	/*!< PMW output channel 3 */
    LEDPWM_Channel_4 = ( int32_t ) 0x00000010UL,	/*!< PMW output channel 4 */
    LEDPWM_Channel_5 = ( int32_t ) 0x00000020UL,	/*!< PMW output channel 5 */
    LEDPWM_Channel_6 = ( int32_t ) 0x00000040UL,	/*!< PMW output channel 6 */
    LEDPWM_Channel_7 = ( int32_t ) 0x00000080UL,	/*!< PMW output channel 7 */
    LEDPWM_Channel_8 = ( int32_t ) 0x00000100UL,	/*!< PMW output channel 8 */
    LEDPWM_Channel_9 = ( int32_t ) 0x00000200UL,	/*!< PMW output channel 9 */
    LEDPWM_Channel_10 = ( int32_t ) 0x00000400UL,	/*!< PMW output channel 10 */
    LEDPWM_Channel_11 = ( int32_t ) 0x00000800UL,	/*!< PMW output channel 11 */
    LEDPWM_Channel_12 = ( int32_t ) 0x00001000UL,	/*!< PMW output channel 12 */
    LEDPWM_Channel_13 = ( int32_t ) 0x00002000UL,	/*!< PMW output channel 13 */
    LEDPWM_Channel_14 = ( int32_t ) 0x00004000UL,	/*!< PMW output channel 14 */
    LEDPWM_Channel_15 = ( int32_t ) 0x00008000UL,	/*!< PMW output channel 15 */
    LEDPWM_Channel_16 = ( int32_t ) 0x00010000UL,	/*!< PMW output channel 16 */
    LEDPWM_Channel_17 = ( int32_t ) 0x00020000UL,	/*!< PMW output channel 17 */
    LEDPWM_Channel_18 = ( int32_t ) 0x00040000UL,	/*!< PMW output channel 18 */
    LEDPWM_Channel_19 = ( int32_t ) 0x00080000UL,	/*!< PMW output channel 19 */
    LEDPWM_Channel_20 = ( int32_t ) 0x00100000UL,	/*!< PMW output channel 20 */
    LEDPWM_Channel_21 = ( int32_t ) 0x00200000UL,	/*!< PMW output channel 21 */
    LEDPWM_Channel_22 = ( int32_t ) 0x00400000UL,	/*!< PMW output channel 22 */
    LEDPWM_Channel_23 = ( int32_t ) 0x00800000UL,	/*!< PMW output channel 23 */
    LEDPWM_Channel_24 = ( int32_t ) 0x01000000UL,	/*!< PMW output channel 24 */
    LEDPWM_Channel_25 = ( int32_t ) 0x02000000UL,	/*!< PMW output channel 25 */
    LEDPWM_Channel_26 = ( int32_t ) 0x04000000UL,	/*!< PMW output channel 26 */
    LEDPWM_Channel_27 = ( int32_t ) 0x08000000UL,	/*!< PMW output channel 27 */
    LEDPWM_Channel_28 = ( int32_t ) 0x10000000UL,	/*!< PMW output channel 28 */
    LEDPWM_Channel_29 = ( int32_t ) 0x20000000UL,	/*!< PMW output channel 29 */
    LEDPWM_Channel_30 = ( int32_t ) 0x40000000UL,	/*!< PMW output channel 30 */
    LEDPWM_Channel_31 = ( int32_t ) 0x80000000UL,	/*!< PMW output channel 31 */
    LEDPWM_Channel_All = ( int32_t ) 0xFFFFFFFFUL, /*!< PMW output channel ALL */
} LEDPWM_Channel_Typedef;

#define IS_LEDPWM_CHANNEL(CHANNEL) (((CHANNEL) & (uint32_t)0xFFFFFF00) == 0x00)
#elif  defined(SC32f11xx)
typedef enum
{
    LEDPWMChannel_Less = 0x00000000UL, /*!< No channels are selected */
    LEDPWM_Channel_0 = ( int32_t ) 0x00000001UL,	/*!< PMW output channel 0 */
    LEDPWM_Channel_1 = ( int32_t ) 0x00000002UL,	/*!< PMW output channel 1 */
    LEDPWM_Channel_2 = ( int32_t ) 0x00000004UL,	/*!< PMW output channel 2 */
    LEDPWM_Channel_3 = ( int32_t ) 0x00000008UL,	/*!< PMW output channel 3 */
    LEDPWM_Channel_4 = ( int32_t ) 0x00000010UL,	/*!< PMW output channel 4 */
    LEDPWM_Channel_5 = ( int32_t ) 0x00000020UL,	/*!< PMW output channel 5 */
    LEDPWM_Channel_6 = ( int32_t ) 0x00000040UL,	/*!< PMW output channel 6 */
    LEDPWM_Channel_7 = ( int32_t ) 0x00000080UL,	/*!< PMW output channel 7 */
    LEDPWM_Channel_8 = ( int32_t ) 0x00000100UL,	/*!< PMW output channel 8 */
    LEDPWM_Channel_9 = ( int32_t ) 0x00000200UL,	/*!< PMW output channel 9 */
    LEDPWM_Channel_10 = ( int32_t ) 0x00000400UL,	/*!< PMW output channel 10 */
    LEDPWM_Channel_11 = ( int32_t ) 0x00000800UL,	/*!< PMW output channel 11 */
    LEDPWM_Channel_12 = ( int32_t ) 0x00001000UL,	/*!< PMW output channel 12 */
    LEDPWM_Channel_13 = ( int32_t ) 0x00002000UL,	/*!< PMW output channel 13 */
    LEDPWM_Channel_14 = ( int32_t ) 0x00004000UL,	/*!< PMW output channel 14 */
    LEDPWM_Channel_15 = ( int32_t ) 0x00008000UL,	/*!< PMW output channel 15 */
    LEDPWM_Channel_16 = ( int32_t ) 0x00010000UL,	/*!< PMW output channel 16 */
    LEDPWM_Channel_17 = ( int32_t ) 0x00020000UL,	/*!< PMW output channel 17 */
    LEDPWM_Channel_18 = ( int32_t ) 0x00040000UL,	/*!< PMW output channel 18 */
    LEDPWM_Channel_19 = ( int32_t ) 0x00080000UL,	/*!< PMW output channel 19 */
    LEDPWM_Channel_20 = ( int32_t ) 0x00100000UL,	/*!< PMW output channel 20 */
    LEDPWM_Channel_21 = ( int32_t ) 0x00200000UL,	/*!< PMW output channel 21 */
    LEDPWM_Channel_22 = ( int32_t ) 0x00400000UL,	/*!< PMW output channel 22 */
    LEDPWM_Channel_23 = ( int32_t ) 0x00800000UL,	/*!< PMW output channel 23 */
    LEDPWM_Channel_24 = ( int32_t ) 0x01000000UL,	/*!< PMW output channel 24 */
    LEDPWM_Channel_25 = ( int32_t ) 0x02000000UL,	/*!< PMW output channel 25 */
    LEDPWM_Channel_26 = ( int32_t ) 0x04000000UL,	/*!< PMW output channel 26 */
    LEDPWM_Channel_27 = ( int32_t ) 0x08000000UL,	/*!< PMW output channel 27 */
    LEDPWM_Channel_28 = ( int32_t ) 0x10000000UL,	/*!< PMW output channel 28 */
    LEDPWM_Channel_29 = ( int32_t ) 0x20000000UL,	/*!< PMW output channel 29 */
    LEDPWM_Channel_30 = ( int32_t ) 0x40000000UL,	/*!< PMW output channel 30 */
    LEDPWM_Channel_31 = ( int32_t ) 0x80000000UL,	/*!< PMW output channel 31 */
    LEDPWM_Channel_0_31 = ( int32_t ) 0xFFFFFFFFUL, /*!< PMW output channel ALL */
    LEDPWM_Channel_32 = ( int32_t ) 0x80000001UL	, /*!<  PMW output channel 32 */
    LEDPWM_Channel_33 = ( int32_t ) 0x80000002UL,	/*!< PMW output channel 33 */
    LEDPWM_Channel_34 = ( int32_t ) 0x80000004UL	, /*!<  PMW output channel 34 */
    LEDPWM_Channel_35 = ( int32_t ) 0x80000008UL,	/*!< PMW output channel 35 */
    LEDPWM_Channel_36 = ( int32_t ) 0x80000010UL	, /*!<  PMW output channel 36 */
    LEDPWM_Channel_37 = ( int32_t ) 0x80000020UL,	/*!< PMW output channel 37*/
    LEDPWM_Channel_38 = ( int32_t ) 0x80000040UL,	/*!< PMW output channel 38*/
    LEDPWM_Channel_32_38 = ( int32_t ) 0x8000007UL,	/*!< PMW output channel 32_38 */
} LEDPWM_Channel_Typedef;

#define IS_LEDPWM_CHANNEL(CHANNEL) (((CHANNEL) & (uint32_t)0xFFFFFF00) == 0x00)
#endif
/**
 * @}
 */


/** @brief LEDPWM_IT LEDPWM Interrupt
 * @{
 */
typedef enum
{
    LEDPWM_IT_INTEN = ( uint16_t ) LEDPWM_CON_INTEN,	/*!< LEDPWM Interrupt: LEDPWM Interrupt */
} LEDPWM_IT_TypeDef;

#define IS_LEDPWM_IT(IT) ((((IT) & (uint16_t)0xFEFF) == 0x00) && ((IT) != (uint16_t)0x0000))

/**
 * @}
 */

/** @brief LEDPWM_Flag LEDPWM Flag
 * @{
 */
typedef enum
{
    LEDPWM_Flag_LEDPWMIF  = ( uint8_t ) LEDPWM_STS_PWMIF,	/*!< LEDPWM Interrupt: LEDPWM Interrupt */
} LEDPWM_Flag_TypeDef;

#define IS_LEDPWM_FLAG(FLAG) ((((FLAG) & (uint8_t)0xFE) == 0x00) && ((FLAG) != (uint8_t)0x00))

#define IS_GET_LEDPWM_FLAG(FLAG) ((FLAG) == LEDPWM_Flag_LEDPWMIF)
/**
 * @}
 */


/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/* Exported struct ------------------------------------------------------------*/
/** @defgroup LEDPWM_Exported_Struct LEDPWM Exported Struct
 * @{
 */

/** @brief LEDPWM Time base Configuration Structure definition
 * @{
 */
typedef struct
{
    uint16_t LEDPWM_Prescaler; /*!<  Specifies the predivision.
																			This parameter can be a value of @ref LEDPWM_Prescaler_TypeDef */

    uint16_t LEDPWM_AlignedMode; /*!< Specifies the aligne mode.
																			This parameter can be a value of @ref LEDPWM_AlignedMode_TypeDef */

    uint8_t LEDPWM_Cycle;   /*!< Specifies the cycle.
															 */

    uint64_t LEDPWM_OutputChannel; /*!< Specifies the output Channel.
																			 This parameter can be a value of @ref LEDPWM_Channel_Typedef */

    uint64_t LEDPWM_LowPolarityChannl; /*!< Specifies the low polarity Channel.
																				 This parameter can be a value of @ref LEDPWM_Channel_Typedef */
#if defined(SC32f11xx)
    uint32_t LEDPWM_OutputChannel0; /*!< Specifies the output Channel.
																			 This parameter can be a value of @ref LEDPWM_Channel_Typedef */

    uint64_t LEDPWM_OutputChannel1; /*!< Specifies the output Channel.
																			 This parameter can be a value of @ref LEDPWM_Channel_Typedef */

    uint64_t LEDPWM_LowPolarityChannl0; /*!< Specifies the low polarity Channel.
																				 This parameter can be a value of @ref LEDPWM_Channel_Typedef */

    uint64_t LEDPWM_LowPolarityChannl1; /*!< Specifies the low polarity Channel.
																				 This parameter can be a value of @ref LEDPWM_Channel_Typedef */
#endif
} LEDPWM_InitTypeDef;
/**
 * @}
 */
/**
 * @}
 */
/* End of struct -----------------------------------------------------*/

/** @addtogroup LEDPWM_Functions LEDPWM Functions
 * @{
 */

/* LEDPWM Base functions ********************************************************/
void LEDPWM_DeInit ( void );
void LEDPWM_StructInit ( LEDPWM_InitTypeDef* LEDPWM_InitStruct );
void LEDPWM_Init ( LEDPWM_InitTypeDef* LEDPWM_InitStruct );
void LEDPWM_Cmd ( FunctionalState NewState );
void LEDPWM_SetCycle ( uint8_t LEDPWM_Cycle );
uint8_t LEDPWM_GetCycle ( void );
void LEDPWM_SetPrescaler ( LEDPWM_Prescaler_TypeDef LEDPWM_Prescaler );
LEDPWM_Prescaler_TypeDef LEDPWM_GetPrescaler ( void );
void LEDPWM_SetDuty ( LEDPWM_Channel_Typedef LEDPWM_Channel, uint8_t LEDPWM_Duty );
uint8_t LEDPWM_GetDuty ( LEDPWM_Channel_Typedef LEDPWM_Channel );

/* Interrupt Handler functions  ***********************************************/
void LEDPWM_ITConfig ( uint16_t LEDPWM_IT, FunctionalState NewState );
FlagStatus LEDPWM_GetFlagStatus ( uint16_t LEDPWM_FLAG );
void LEDPWM_ClearFlag ( uint16_t LEDPWM_FLAG );

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
