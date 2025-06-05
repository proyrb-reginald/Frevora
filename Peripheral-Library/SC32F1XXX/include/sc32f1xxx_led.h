/**
 ******************************************************************************
 * @file    sc32f1xxx_LED.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    14-10-2024
 * @brief   Header file of LED module.
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
#ifndef __sc32f1xxx_LED_H
#define __sc32f1xxx_LED_H

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

/** @addtogroup LED
 * @{
 */

/* Exported enumerations ------------------------------------------------------------*/
/** @defgroup LED_Exported_Enumerations LED Exported Enumerations
 * @{
 */

/** @brief LED_FrameFre LED Frame Frequency
 * @{
 */
typedef enum
{
    LED_FrameFre_A32Hz	 = ( uint32_t ) ( ( 0x00U << DDR_CON_DDRCK_Pos ) | DDR_CON_TYPE ), /*!< The LED/LED frame frequency of typeA is 32Hz */
    LED_FrameFre_A64Hz	 = ( uint32_t ) ( ( 0x01U << DDR_CON_DDRCK_Pos ) | DDR_CON_TYPE ), /*!< The LED/LED frame frequency of typeA is 64Hz */
    LED_FrameFre_A128Hz  = ( uint32_t ) ( ( 0x02U << DDR_CON_DDRCK_Pos ) | DDR_CON_TYPE ), /*!< The LED/LED frame frequency of typeA is 128Hz */
    LED_FrameFre_B64Hz	 = ( uint32_t ) ( 0x00U << DDR_CON_DDRCK_Pos ),	 /*!< The LED/LED frame frequency of typeB is 64Hz */
    LED_FrameFre_B128Hz	 = ( uint32_t ) ( 0x01U << DDR_CON_DDRCK_Pos ), /*!< The LED/LED frame frequency of typeB is 128Hz*/
    LED_FrameFre_B256Hz	 = ( uint32_t ) ( 0x02U << DDR_CON_DDRCK_Pos ), /*!< The LED/LED frame frequency of typeB is 256Hz*/
    LED_FrameFre_ACustom	 = ( uint32_t ) ( DDR_CON_TRIMODE | DDR_CON_TYPE ),             /*!< The LED/LED frame frequency of typeA is customized*/
    LED_FrameFre_BCustom	 = ( uint32_t ) ( DDR_CON_TRIMODE ), /*!< The LED/LED frame frequency of typeB is customized*/
} LED_FrameFre_TypeDef;

#define IS_LED_FRAMEFRE(FRAMEFRE) (((FRAMEFRE) == LED_FrameFre_A32Hz) || \
                                      ((FRAMEFRE) == LED_FrameFre_A64Hz) || \
                                      ((FRAMEFRE) == LED_FrameFre_A128Hz) || \
                                      ((FRAMEFRE) == LED_FrameFre_B64Hz) || \
                                      ((FRAMEFRE) == LED_FrameFre_B128Hz) || \
                                      ((FRAMEFRE) == LED_FrameFre_B256Hz) || \
                                      ((FRAMEFRE) == LED_FrameFre_B128Hz) || \
                                      ((FRAMEFRE) == LED_FrameFre_B256Hz))
/**
 * @}
 */



/** @brief LED_Duty LED Duty
 * @{
 */
#if defined(SC32f10xx) || defined(SC32f12xx)
typedef enum
{
    LED_Duty_1_8 = ( uint32_t ) ( 0x00U << DDR_CFG_DUTY_Pos ),		/*!< LED/LED display duty cycle: 1/8    */
    LED_Duty_1_6 = ( uint32_t ) ( 0x01U << DDR_CFG_DUTY_Pos ),		/*!< LED/LED display duty cycle: 1/6    */
    LED_Duty_1_5 = ( uint32_t ) ( 0x02U << DDR_CFG_DUTY_Pos ),		/*!< LED/LED display duty cycle: 1/5    */
    LED_Duty_1_4_SEG0_27COM4_7
        = ( uint32_t ) ( 0x03U << DDR_CFG_DUTY_Pos ),								/*!< LED/LED display duty cycle: 1/4    */
    LED_Duty_1_4_SEG4_27COM0_3
        = ( uint32_t ) ( ( 0x03U << DDR_CFG_DUTY_Pos ) | DDR_CFG_SCS ),		/*!< LED/LED display duty cycle: 1/4    */
} LED_Duty_TypeDef;

#define IS_LED_DUTY(DUTY) (((DUTY) == LED_Duty_1_8) ||   \
													((DUTY) == LED_Duty_1_6) ||   \
													((DUTY) == LED_Duty_1_5) ||   \
													((DUTY) == LED_Duty_1_4_SEG0_27COM4_7) ||   \
													((DUTY) == LED_Duty_1_4_SEG4_27COM0_3))
#elif defined(SC32f11xx)
typedef enum
{
    LED_Duty_1_8 = ( uint32_t ) ( 0x00U << DDR_CFG_DUTY_Pos ),		/*!< LED/LED display duty cycle: 1/8    */
    LED_Duty_1_6 = ( uint32_t ) ( 0x01U << DDR_CFG_DUTY_Pos ),		/*!< LED/LED display duty cycle: 1/6    */
    LED_Duty_1_5 = ( uint32_t ) ( 0x02U << DDR_CFG_DUTY_Pos ),		/*!< LED/LED display duty cycle: 1/5    */
    LED_Duty_1_4_SEG0_34COM4_7
        = ( uint32_t ) ( 0x03U << DDR_CFG_DUTY_Pos ),								/*!< LED/LED display duty cycle: 1/4    */
    LED_Duty_1_4_SEG4_34COM0_3
        = ( uint32_t ) ( ( 0x03U << DDR_CFG_DUTY_Pos ) | DDR_CFG_SCS ),		/*!< LED/LED display duty cycle: 1/4    */
} LED_Duty_TypeDef;

#define IS_LED_DUTY(DUTY) (((DUTY) == LED_Duty_1_8) ||   \
													((DUTY) == LED_Duty_1_6) ||   \
													((DUTY) == LED_Duty_1_5) ||   \
													((DUTY) == LED_Duty_1_4_SEG0_34COM4_7) ||   \
													((DUTY) == LED_Duty_1_4_SEG4_34COM0_3))
#endif
/**
 * @}
 */


/** @brief  LED_Channel
 * @{
 */
#if defined(SC32f10xx) || defined(SC32f12xx)
typedef enum
{
    LED_Channel_Less = ( int32_t ) 0x00000000U,	/*!< PMW output channel 0 */
    LED_Channel_0 = ( int32_t ) 0x00000001U,	/*!< PMW output channel 0 */
    LED_Channel_1 = ( int32_t ) 0x00000002U,	/*!< PMW output channel 1 */
    LED_Channel_2 = ( int32_t ) 0x00000004U,	/*!< PMW output channel 2 */
    LED_Channel_3 = ( int32_t ) 0x00000008U,	/*!< PMW output channel 3 */
    LED_Channel_4 = ( int32_t ) 0x00000010U,	/*!< PMW output channel 4 */
    LED_Channel_5 = ( int32_t ) 0x00000020U,	/*!< PMW output channel 5 */
    LED_Channel_6 = ( int32_t ) 0x00000040U,	/*!< PMW output channel 6 */
    LED_Channel_7 = ( int32_t ) 0x00000080U,	/*!< PMW output channel 7 */
    LED_Channel_8 = ( int32_t ) 0x00000100U,	/*!< PMW output channel 8 */
    LED_Channel_9 = ( int32_t ) 0x00000200U,	/*!< PMW output channel 9 */
    LED_Channel_10 = ( int32_t ) 0x00000400U, /*!< PMW output channel 10 */
    LED_Channel_11 = ( int32_t ) 0x00000800U, /*!< PMW output channel 11 */
    LED_Channel_12 = ( int32_t ) 0x00001000U, /*!< PMW output channel 12 */
    LED_Channel_13 = ( int32_t ) 0x00002000U, /*!< PMW output channel 13 */
    LED_Channel_14 = ( int32_t ) 0x00004000U, /*!< PMW output channel 14 */
    LED_Channel_15 = ( int32_t ) 0x00008000U, /*!< PMW output channel 15 */
    LED_Channel_16 = ( int32_t ) 0x00010000U, /*!< PMW output channel 16 */
    LED_Channel_17 = ( int32_t ) 0x00020000U, /*!< PMW output channel 17 */
    LED_Channel_18 = ( int32_t ) 0x00040000U, /*!< PMW output channel 18 */
    LED_Channel_19 = ( int32_t ) 0x00080000U, /*!< PMW output channel 19 */
    LED_Channel_20 = ( int32_t ) 0x00100000U, /*!< PMW output channel 20 */
    LED_Channel_21 = ( int32_t ) 0x00200000U, /*!< PMW output channel 21 */
    LED_Channel_22 = ( int32_t ) 0x00400000U, /*!< PMW output channel 22 */
    LED_Channel_23 = ( int32_t ) 0x00800000U, /*!< PMW output channel 23 */
    LED_Channel_24 = ( int32_t ) 0x01000000U, /*!< PMW output channel 24 */
    LED_Channel_25 = ( int32_t ) 0x02000000U, /*!< PMW output channel 25 */
    LED_Channel_26 = ( int32_t ) 0x04000000U, /*!< PMW output channel 26 */
    LED_Channel_27 = ( int32_t ) 0x08000000U, /*!< PMW output channel 27 */
    LED_Channel_28 = ( int32_t ) 0x10000000U, /*!< PMW output channel 28 */
    LED_Channel_29 = ( int32_t ) 0x20000000U, /*!< PMW output channel 29 */
    LED_Channel_30 = ( int32_t ) 0x40000000U, /*!< PMW output channel 30 */
    LED_Channel_31 = ( int32_t ) 0x80000000U, /*!< PMW output channel 31 */
} LED_Channel_Typedef;

#define IS_LED_Channel(Channel) ((Channel) <= (LED_Channel_All))
#elif  defined(SC32f11xx)
typedef enum
{
    LED_Channel_Less = ( int32_t ) 0x00000000U,	/*!< No channels are selected */
    LED_Channel_0 = ( int32_t ) 0x00000001U,
    LED_Channel_1 = ( int32_t ) 0x00000002U,
    LED_Channel_2 = ( int32_t ) 0x00000004U,
    LED_Channel_3 = ( int32_t ) 0x00000008U,
    LED_Channel_4 = ( int32_t ) 0x00000010U,
    LED_Channel_5 = ( int32_t ) 0x00000020U,
    LED_Channel_6 = ( int32_t ) 0x00000040U,
    LED_Channel_7 = ( int32_t ) 0x00000080U,
    LED_Channel_8 = ( int32_t ) 0x00000100U,
    LED_Channel_9 = ( int32_t ) 0x00000200U,
    LED_Channel_10 = ( int32_t ) 0x00000400U,
    LED_Channel_11 = ( int32_t ) 0x00000800U,
    LED_Channel_12 = ( int32_t ) 0x00001000U,
    LED_Channel_13 = ( int32_t ) 0x00002000U,
    LED_Channel_14 = ( int32_t ) 0x00004000U,
    LED_Channel_15 = ( int32_t ) 0x00008000U,
    LED_Channel_16 = ( int32_t ) 0x00010000U,
    LED_Channel_17 = ( int32_t ) 0x00020000U,
    LED_Channel_18 = ( int32_t ) 0x00040000U,
    LED_Channel_19 = ( int32_t ) 0x00080000U,
    LED_Channel_20 = ( int32_t ) 0x00100000U,
    LED_Channel_21 = ( int32_t ) 0x00200000U,
    LED_Channel_22 = ( int32_t ) 0x00400000U,
    LED_Channel_23 = ( int32_t ) 0x00800000U,
    LED_Channel_24 = ( int32_t ) 0x01000000U,
    LED_Channel_25 = ( int32_t ) 0x02000000U,
    LED_Channel_26 = ( int32_t ) 0x04000000U,
    LED_Channel_27 = ( int32_t ) 0x08000000U,
    LED_Channel_28 = ( int32_t ) 0x10000000U,
    LED_Channel_29 = ( int32_t ) 0x20000000U,
    LED_Channel_30 = ( int32_t ) 0x40000000U,
    LED_Channel_31 = ( int32_t ) 0x80000000U,
} LED_Channel_Typedef;
#define LED_Channel_32 (uint64_t)0x100000000
#define LED_Channel_33 (uint64_t)0x200000000
#define LED_Channel_34 (uint64_t)0x400000000
#define IS_LED_Channel(Channel) ((Channel) <= (LED_Channel_All))
#endif
/**
 * @}
 */

/** @brief LED_RAMRegister
 * @{
 */
#if defined(SC32f10xx) || defined(SC32f12xx)
typedef enum
{
    LED_RAMRegister_0 = 0x00000000U,
    LED_RAMRegister_1 = 0x00000001U,
    LED_RAMRegister_2 = 0x00000002U,
    LED_RAMRegister_3 = 0x00000003U,
    LED_RAMRegister_4 = 0x00000004U,
    LED_RAMRegister_5 = 0x00000005U,
    LED_RAMRegister_6 = 0x00000006U,
    LED_RAMRegister_7 = 0x00000007U,
    LED_RAMRegister_8 = 0x00000008U,
    LED_RAMRegister_9 = 0x00000009U,
    LED_RAMRegister_10 = 0x0000000AU,
    LED_RAMRegister_11 = 0x0000000BU,
    LED_RAMRegister_12 = 0x0000000CU,
    LED_RAMRegister_13 = 0x0000000DU,
    LED_RAMRegister_14 = 0x0000000EU,
    LED_RAMRegister_15 = 0x0000000FU,
    LED_RAMRegister_16 = 0x00000010U,
    LED_RAMRegister_17 = 0x00000011U,
    LED_RAMRegister_18 = 0x00000012U,
    LED_RAMRegister_19 = 0x00000013U,
    LED_RAMRegister_20 = 0x00000014U,
    LED_RAMRegister_21 = 0x00000015U,
    LED_RAMRegister_22 = 0x00000016U,
    LED_RAMRegister_23 = 0x00000017U,
    LED_RAMRegister_24 = 0x00000018U,
    LED_RAMRegister_25 = 0x00000019U,
    LED_RAMRegister_26 = 0x0000001AU,
    LED_RAMRegister_27 = 0x0000001BU,
} LED_RAMRegister_Typedef;

#define IS_LED_RAM_REGISTER(REGISTER) ((REGISTER) <= (LED_RAMRegister27))
#elif  defined(SC32f11xx)
typedef enum
{
    LED_RAMRegister_0 = 0x00000000U,
    LED_RAMRegister_1 = 0x00000001U,
    LED_RAMRegister_2 = 0x00000002U,
    LED_RAMRegister_3 = 0x00000003U,
    LED_RAMRegister_4 = 0x00000004U,
    LED_RAMRegister_5 = 0x00000005U,
    LED_RAMRegister_6 = 0x00000006U,
    LED_RAMRegister_7 = 0x00000007U,
    LED_RAMRegister_8 = 0x00000008U,
    LED_RAMRegister_9 = 0x00000009U,
    LED_RAMRegister_10 = 0x0000000AU,
    LED_RAMRegister_11 = 0x0000000BU,
    LED_RAMRegister_12 = 0x0000000CU,
    LED_RAMRegister_13 = 0x0000000DU,
    LED_RAMRegister_14 = 0x0000000EU,
    LED_RAMRegister_15 = 0x0000000FU,
    LED_RAMRegister_16 = 0x00000010U,
    LED_RAMRegister_17 = 0x00000011U,
    LED_RAMRegister_18 = 0x00000012U,
    LED_RAMRegister_19 = 0x00000013U,
    LED_RAMRegister_20 = 0x00000014U,
    LED_RAMRegister_21 = 0x00000015U,
    LED_RAMRegister_22 = 0x00000016U,
    LED_RAMRegister_23 = 0x00000017U,
    LED_RAMRegister_24 = 0x00000018U,
    LED_RAMRegister_25 = 0x00000019U,
    LED_RAMRegister_26 = 0x0000001AU,
    LED_RAMRegister_27 = 0x0000001BU,
    LED_RAMRegister_28 = 0x0000001CU,
    LED_RAMRegister_29 = 0x0000001DU,
    LED_RAMRegister_30 = 0x0000001EU,
    LED_RAMRegister_31 = 0x0000001FU,
    LED_RAMRegister_32 = 0x00000020U,
    LED_RAMRegister_33 = 0x00000021U,
    LED_RAMRegister_34 = 0x00000022U,
    LED_RAMRegister_35 = 0x00000023U,


} LED_RAMRegister_Typedef;

#define IS_LED_RAM_REGISTER(REGISTER) ((REGISTER) <= (LED_RAMRegister_34))
#endif
/**
 * @}
 */
typedef enum
{
    LED_COMEN_0 = 0x00000001U,
    LED_COMEN_1 = 0x00000002U,
    LED_COMEN_2 = 0x00000004U,
    LED_COMEN_3 = 0x00000008U,
    LED_COMEN_4 = 0x00000010U,
    LED_COMEN_5 = 0x00000020U,
    LED_COMEN_6 = 0x00000040U,
    LED_COMEN_7 = 0x00000080U,
} LED_COMEN_Typedef;

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/* Exported struct ------------------------------------------------------------*/
/** @defgroup LED_Exported_Struct LED Exported Struct
 * @{
 */

/** @brief LED Base Configuration Structure definition
 * @{
 */
typedef struct
{

    uint16_t LED_FrameFre; /*!< Specifies the frame frequency.
																					This parameter can be a value of @ref LED_FrameFre_TypeDef */

    uint16_t LED_Duty; /*!< Specifies the display duty cycle.
																			This parameter can be a value of @ref LED_Duty_TypeDef */

    uint32_t LED_ComPin; /*!< Specifies the Com Pin.
																Each bit represents a Seg channel,Support 8 channels.*/
#if defined (SC32f10xx) || defined(SC32f12xx)
    uint32_t LED_SegPin; /*!< Specifies the Seg Pin.
																Each bit represents a Seg channel,Support 28 channels.*/
#elif defined(SC32f11xx)
    uint64_t LED_SegPin; /*!< Specifies the Seg Pin.
																Each bit represents a Seg channel,Support 35 channels.*/
#endif
} LED_InitTypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of struct -----------------------------------------------------*/

/** @addtogroup LED_Exported_Functions LED Exported Functions
 * @{
 */

/* Initialization and Configuration functions ***********************************************/
void LED_DeInit ( void );
void LED_Init ( LED_InitTypeDef* LCD_InitStruct );
void LED_StructInit ( LED_InitTypeDef* LED_InitStruct );
void LED_Cmd ( FunctionalState NewState );

/* Initialization and Configuration functions ***********************************************/
void LED_COMConfig ( LED_COMEN_Typedef COMSelect, FunctionalState NewState );
void LED_SEGConfig ( uint64_t SEGSelect, FunctionalState NewState );
void LED_Write ( LED_RAMRegister_Typedef LED_RAMRegister, uint8_t LED_Data );
void LED_CustomModeScan ( void );

/**
 * @}
 */
/* End of exported functions --------------------------------------------------*/

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
