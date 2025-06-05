/**
 ******************************************************************************
 * @file    SC32f10xx_pwm.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    14-10-2024
 * @brief   Header file of PWM module.
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
#ifndef __sc32f1xxx_PWM_H
#define __sc32f1xxx_PWM_H

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

/** @addtogroup PWM
 * @{
 */

/** @defgroup PWM_Enumerations PWM Enumerations
 * @{
 */

/** @brief PWM_Prescaler PWM Prescaler
 * @{
 */
typedef enum
{
    PWM_PRESCALER_DIV1	 = ( uint16_t ) ( 0x00U << PWM_CON_PWMCLK_Pos ),	/*!< Clock division: Fsource/1    */
    PWM_PRESCALER_DIV2	 = ( uint16_t ) ( 0x01U << PWM_CON_PWMCLK_Pos ),	/*!< Clock division: Fsource/2    */
    PWM_PRESCALER_DIV4	 = ( uint16_t ) ( 0x02U << PWM_CON_PWMCLK_Pos ),	/*!< Clock division: Fsource/4    */
    PWM_PRESCALER_DIV8	 = ( uint16_t ) ( 0x03U << PWM_CON_PWMCLK_Pos ),	/*!< Clock division: Fsource/8    */
    PWM_PRESCALER_DIV16	 = ( uint16_t ) ( 0x04U << PWM_CON_PWMCLK_Pos ),	/*!< Clock division: Fsource/16    */
    PWM_PRESCALER_DIV32	 = ( uint16_t ) ( 0x05U << PWM_CON_PWMCLK_Pos ),	/*!< Clock division: Fsource/32    */
    PWM_PRESCALER_DIV64	 = ( uint16_t ) ( 0x06U << PWM_CON_PWMCLK_Pos ),	/*!< Clock division: Fsource/64    */
    PWM_PRESCALER_DIV128 = ( uint16_t ) ( 0x07U << PWM_CON_PWMCLK_Pos ), /*!< Clock division: Fsource/128    */
    PWM_PRESCALER_DIV256 = ( uint16_t ) ( 0x08U << PWM_CON_PWMCLK_Pos ), /*!< Clock division: Fsource/256    */
} PWM_Prescaler_TypeDef;

#define IS_PWM_PRESCALER(PRESCALER) (((PRESCALER) == PWM_PRESCALER_DIV1) ||   \
																		 ((PRESCALER) == PWM_PRESCALER_DIV2) ||   \
																		 ((PRESCALER) == PWM_PRESCALER_DIV4) ||   \
																		 ((PRESCALER) == PWM_PRESCALER_DIV8) ||   \
																		 ((PRESCALER) == PWM_PRESCALER_DIV16) ||  \
																		 ((PRESCALER) == PWM_PRESCALER_DIV32) ||  \
																		 ((PRESCALER) == PWM_PRESCALER_DIV64) ||  \
																		 ((PRESCALER) == PWM_PRESCALER_DIV128) || \
																		 ((PRESCALER) == PWM_PRESCALER_DIV256))
/**
 * @}
 */

/** @brief PWM_AlignedMode PWM AlignedMode
 * @{
 */
typedef enum
{
    PWM_AlignmentMode_Edge	 = ( uint16_t ) ( 0x00U << PWM_CON_PWMMD0_Pos ),	 /*!< Edge Alignment mode */
    PWM_AlignmentMode_Center = ( uint16_t ) ( 0x01U << PWM_CON_PWMMD0_Pos ), /*!< Center Alignment mode */
} PWM_AlignedMode_TypeDef;

#define IS_PWM_AlignedMode(MODE) (((MODE) == PWM_AlignmentMode_Edge) || \
																	((MODE) == PWM_AlignmentMode_Center))
/**
 * @}
 */

/** @brief PWM_WordMode PWM WordMode
 * @{
 */
typedef enum
{
    PWM_WorkMode_Independent		= ( uint16_t ) ( 0x00U << PWM_CON_PWMMD1_Pos ),	 /*!< Independent working mode */
    PWM_WorkMode_Complementary	= ( uint16_t ) ( 0x01U << PWM_CON_PWMMD1_Pos ), /*!< Complementary working mode*/
} PWM_WorkMode_TypeDef;

#define IS_PWM_WORKMode(MODE)	(((MODE) == PWM_Mode_Independent) || \
															((MODE) == PWM_Mode_Complementary))
/**
 * @}
 */

/** @brief PWM_Channel PWM Channel
 * @{
 */
typedef enum
{
    PWMChannel_Less = 0x00000000UL, /*!< No channels are selected */
    PWM_Channel_0 = ( int32_t ) 0x00000001UL,	/*!< PMW output channel 0 */
    PWM_Channel_1 = ( int32_t ) 0x00000002UL,	/*!< PMW output channel 1 */
    PWM_Channel_2 = ( int32_t ) 0x00000004UL,	/*!< PMW output channel 2 */
    PWM_Channel_3 = ( int32_t ) 0x00000008UL,	/*!< PMW output channel 3 */
    PWM_Channel_4 = ( int32_t ) 0x00000010UL,	/*!< PMW output channel 4 */
    PWM_Channel_5 = ( int32_t ) 0x00000020UL,	/*!< PMW output channel 5 */
    PWM_Channel_6 = ( int32_t ) 0x00000040UL,	/*!< PMW output channel 6 */
    PWM_Channel_7 = ( int32_t ) 0x00000080UL,	/*!< PMW output channel 7 */
    PWM_Channel_All = ( int32_t ) 0x000000FFUL, /*!< PMW output channel ALL */
} PWM_Channel_Typedef;

#define IS_PWM_CHANNEL(CHANNEL) (((CHANNEL) & (uint32_t)0xFFFFFF00) == 0x00)
/**
 * @}
 */

/** @brief PWM_FDMode PWM FDMode
 * @{
 */
typedef enum
{
    PWM_FDMode_Latch		 = ( uint16_t ) ( 0x00U << PWM_FLT_FLTMD_Pos ),	/*!< PWM fault detection mode: Latch mode */
    PWM_FDMode_Immediate = ( uint16_t ) ( 0x01U << PWM_FLT_FLTMD_Pos ), /*!< PWM fault detection mode: Immediate mode */
} PWM_FDMode_TypeDef;

#define IS_PWM_FDMODE(MODE) (((MODE) == PWM_FDMode_Latch) || \
														 ((MODE) == PWM_FDMode_Immediate))
/**
 * @}
 */

/** @brief PWM_FDVoltage PWM FDVoltage
 * @{
 */
typedef enum
{
    PWM_FDVoltage_Low		= ( uint16_t ) ( 0x00U << PWM_FLT_FLTTV_Pos ),	 /*!< PWM fault detection Voltage:Low level */
    PWM_FDVoltage_High	= ( uint16_t ) ( 0x01U << PWM_FLT_FLTTV_Pos ), /*!< PWM fault detection Voltage:High level */
} PWM_FDVoltage_TypeDef;

#define IS_PWM_FDVOLTAGE(VOLTAGE) (((VOLTAGE) == PWM_FDVoltage_Low) || \
																	 ((VOLTAGE) == PWM_FDVoltage_High))
/**
 * @}
 */

/** @brief PWM_FDFilteringTime PWM FDFilteringTime
 * @{
 */
typedef enum
{
    PWM_FilteringTime_0us		= ( uint16_t ) ( 0x00U << PWM_FLT_FLTDT_Pos ),	/*!< PWM fault detection input signal filtering time is 0us */
    PWM_FilteringTime_1us		= ( uint16_t ) ( 0x01U << PWM_FLT_FLTDT_Pos ),	/*!< PWM fault detection input signal filtering time is 1us */
    PWM_FilteringTime_4us		= ( uint16_t ) ( 0x02U << PWM_FLT_FLTDT_Pos ),	/*!< PWM fault detection input signal filtering time is 4us */
    PWM_FilteringTime_16us	= ( uint16_t ) ( 0x03U << PWM_FLT_FLTDT_Pos ), /*!< PWM fault detection input signal filtering time is 16us */
} PWM_FDFilteringTime_TypeDef;

#define IS_PWM_FDFILTERINGTIME(TIME) (((TIME) == PWM_WaveFilteringTime_0us) || \
																			((TIME) == PWM_WaveFilteringTime_1us) || \
																			((TIME) == PWM_WaveFilteringTime_4us) || \
																			((TIME) == PWM_WaveFilteringTime_16us))
/**
 * @}
 */

/** @brief PWM_IT PWM Interrupt
 * @{
 */
typedef enum
{
    PWM_IT_INTEN = ( uint16_t ) PWM_CON_INTEN,	/*!< PWM Interrupt: PWM Interrupt */
} PWM_IT_TypeDef;

#define IS_PWM_IT(IT) ((((IT) & (uint16_t)0xFEFF) == 0x00) && ((IT) != (uint16_t)0x0000))

/**
 * @}
 */

/** @brief PWM_Flag PWM Flag
 * @{
 */
typedef enum
{
    PWM_Flag_PWMIF  = ( uint8_t ) PWM_STS_PWMIF,	/*!< PWM Interrupt: PWM Interrupt */
    PWM_Flag_FLTSTA = ( uint8_t ) PWM_STS_FLTSTA, /*!< PWM Interrupt: Flult Interrupt */
} PWM_Flag_TypeDef;

#define IS_PWM_FLAG(FLAG) ((((FLAG) & (uint8_t)0xFC) == 0x00) && ((FLAG) != (uint8_t)0x00))

#define IS_GET_PWM_FLAG(FLAG) (((FLAG) == PWM_Flag_PWMIF) || \
													     ((FLAG) == PWM_Flag_FLTSTA))
/**
 * @}
 */


/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @brief PWM_Constants PWM Constants
  * @{
  */
#define IS_PWM_ALL_PERIPH(PERIPH) ((PERIPH) == PWM0)

#define IS_PWM_COMPLEMENTARY_PERIPH(PERIPH) ((PERIPH) == PWM0)
/**
 * @}
 */

/* Exported struct ------------------------------------------------------------*/
/** @defgroup PWM_Exported_Struct PWM Exported Struct
 * @{
 */

/** @brief PWM Time base Configuration Structure definition
 * @{
 */
typedef struct
{
    uint16_t PWM_Prescaler; /*!<  Specifies the predivision.
																			This parameter can be a value of @ref PWM_Prescaler_TypeDef */

    uint16_t PWM_AlignedMode; /*!< Specifies the aligne mode.
																			This parameter can be a value of @ref PWM_AlignedMode_TypeDef */

    uint16_t PWM_WorkMode; /*!< Specifies the work mode.
																					This parameter can be a value of @ref PWM_WorkMode_TypeDef */

    uint16_t PWM_Cycle;   /*!< Specifies the cycle.
															 */

    uint32_t PWM_OutputChannel; /*!< Specifies the output Channel.
																			 This parameter can be a value of @ref PWM_CHANNEL_Typedef */

    uint32_t PWM_LowPolarityChannl; /*!< Specifies the invert Channel.
																				 This parameter can be a value of @ref PWM_CHANNEL_Typedef */
} PWM_InitTypeDef;
/**
 * @}
 */

/** @brief PWM_FDInitTypeDef
 * @{
 */
typedef struct
{
    uint16_t PWM_FDMode;							 /*!<  Specifies the PWM fault detection mode.
																										 This parameter can be a value of @ref PWM_FDMode_TypeDef */
    uint16_t PWM_FDVoltage;				 /*!<  Specifies the PWM fault detection active level.
																							 This parameter can be a value of @ref PWM_FDVoltage_TypeDef */
    uint16_t PWM_FDFilteringTime; /*!<  Specifies the PWM fault detection filtering time.
																			 This parameter can be a value of @ref PWM_FDFilteringTime_TypeDef */
} PWM_FDInitTypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of struct -----------------------------------------------------*/

/** @addtogroup PWM_Functions PWM Functions
 * @{
 */

/* PWM Base functions ********************************************************/
void PWM_DeInit ( PWM_TypeDef* PWMx );
void PWM_StructInit ( PWM_InitTypeDef* PWM_InitStruct );
void PWM_Init ( PWM_TypeDef* PWMx, PWM_InitTypeDef* PWM_InitStruct );
void PWM_Cmd ( PWM_TypeDef* PWMx, FunctionalState NewState );
void PWM_SetCycle ( PWM_TypeDef* PWMx, uint32_t PWM_Cycle );
uint16_t PWM_GetCycle ( PWM_TypeDef* PWMx );
void PWM_SetPrescaler ( PWM_TypeDef* PWMx, PWM_Prescaler_TypeDef PWM_Prescaler );
PWM_Prescaler_TypeDef PWM_GetPrescaler ( PWM_TypeDef* PWMx );
void PWM_SetDuty ( PWM_TypeDef* PWMx, PWM_Channel_Typedef PWM_Channel, uint16_t PWM_Duty );
uint16_t PWM_GetDuty ( PWM_TypeDef* PWMx, PWM_Channel_Typedef PWM_Channel );
void PWM_RisingDeadTimeConfig ( PWM_TypeDef* PWMx, uint8_t PWM_RisingDeadTime );
void PWM_FallingDeadTimeConfig ( PWM_TypeDef* PWMx, uint8_t PWM_FallingDeadTime );

/* PWM Falut Dectection functions **********************************************/
void PWM_FDStructInit ( PWM_FDInitTypeDef* PWM_FDInitStruct );
void PWM_FDInit ( PWM_TypeDef* PWMx, PWM_FDInitTypeDef* PWM_FDInitStruct );
void PWM_FDCmd ( PWM_TypeDef* PWMx, FunctionalState NewState );

/* Interrupt Handler functions  ***********************************************/
void PWM_ITConfig ( PWM_TypeDef* PWMx, uint16_t PWM_IT, FunctionalState NewState );
FlagStatus PWM_GetFlagStatus ( PWM_TypeDef* PWMx, uint16_t PWM_FLAG );
void PWM_ClearFlag ( PWM_TypeDef* PWMx, uint16_t PWM_FLAG );

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
