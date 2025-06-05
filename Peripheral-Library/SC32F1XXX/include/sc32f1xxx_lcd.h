/**
 ******************************************************************************
 * @file    sc32f1xxx_LCD.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    14-10-2024
 * @brief   Header file of LCD module.
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
#ifndef __sc32f1xxx_LCD_H
#define __sc32f1xxx_LCD_H

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

/** @addtogroup LCD
 * @{
 */

/* Exported enumerations ------------------------------------------------------------*/
/** @defgroup LCD_Exported_Enumerations LCD Exported Enumerations
 * @{
 */

/** @brief LCD_FrameFre LCD Frame Frequency
 * @{
 */
typedef enum
{
    LCD_FrameFre_A32Hz	 = ( uint32_t ) ( ( 0x00U << DDR_CON_DDRCK_Pos ) | DDR_CON_TYPE ), /*!< The LCD/LED frame frequency of typeA is 32Hz */
    LCD_FrameFre_A64Hz	 = ( uint32_t ) ( ( 0x01U << DDR_CON_DDRCK_Pos ) | DDR_CON_TYPE ), /*!< The LCD/LED frame frequency of typeA is 64Hz */
    LCD_FrameFre_A128Hz  = ( uint32_t ) ( ( 0x02U << DDR_CON_DDRCK_Pos ) | DDR_CON_TYPE ), /*!< The LCD/LED frame frequency of typeA is 128Hz */
    LCD_FrameFre_B64Hz	 = ( uint32_t ) ( 0x00U << DDR_CON_DDRCK_Pos ),	 /*!< The LCD/LED frame frequency of typeB is 64Hz */
    LCD_FrameFre_B128Hz	 = ( uint32_t ) ( 0x01U << DDR_CON_DDRCK_Pos ), /*!< The LCD/LED frame frequency of typeB is 128Hz*/
    LCD_FrameFre_B256Hz	 = ( uint32_t ) ( 0x02U << DDR_CON_DDRCK_Pos ), /*!< The LCD/LED frame frequency of typeB is 256Hz*/
    LCD_FrameFre_ACustom	 = ( uint32_t ) ( DDR_CON_TRIMODE | DDR_CON_TYPE ),             /*!< The LCD/LED frame frequency of typeA is customized*/
    LCD_FrameFre_BCustom	 = ( uint32_t ) ( DDR_CON_TRIMODE ), /*!< The LCD/LED frame frequency of typeB is customized*/
} LCD_FrameFre_TypeDef;

#define IS_LCD_FRAMEFRE(FRAMEFRE) (((FRAMEFRE) == LCD_FrameFre_A32Hz) || \
                                      ((FRAMEFRE) == LCD_FrameFre_A64Hz) || \
                                      ((FRAMEFRE) == LCD_FrameFre_A128Hz) || \
                                      ((FRAMEFRE) == LCD_FrameFre_B64Hz) || \
                                      ((FRAMEFRE) == LCD_FrameFre_B128Hz) || \
                                      ((FRAMEFRE) == LCD_FrameFre_B256Hz) || \
                                      ((FRAMEFRE) == LCD_FrameFre_B128Hz) || \
                                      ((FRAMEFRE) == LCD_FrameFre_B256Hz))
/**
 * @}
 */



/** @brief LCD_Duty LCD DUTY
 * @{
 */
#if defined(SC32f10xx) || defined(SC32f12xx)
typedef enum
{
    LCD_Duty_1_8 = ( uint32_t ) ( 0x00U << DDR_CFG_DUTY_Pos ),		/*!< LCD/LED display duty cycle: 1/8    */
    LCD_Duty_1_6 = ( uint32_t ) ( 0x01U << DDR_CFG_DUTY_Pos ),		/*!< LCD/LED display duty cycle: 1/6    */
    LCD_Duty_1_5 = ( uint32_t ) ( 0x02U << DDR_CFG_DUTY_Pos ),		/*!< LCD/LED display duty cycle: 1/5    */
    LCD_Duty_1_4_SEG0_27COM4_7
        = ( uint32_t ) ( 0x03U << DDR_CFG_DUTY_Pos ),								/*!< LCD/LED display duty cycle: 1/4    */
    LCD_Duty_1_4_SEG4_27COM0_3
        = ( uint32_t ) ( ( 0x03U << DDR_CFG_DUTY_Pos ) | DDR_CFG_SCS ),		/*!< LCD/LED display duty cycle: 1/4    */
} LCD_Duty_TypeDef;

#define IS_LCD_DUTY(DUTY) (((DUTY) == LCD_Duty_1_8) ||   \
																((DUTY) == LCD_Duty_1_6) ||   \
																((DUTY) == LCD_Duty_1_5) ||   \
																((DUTY) == LCD_Duty_1_4_SEG0_27COM4_7) ||   \
																((DUTY) == LCD_Duty_1_4_SEG4_27COM0_3))
#elif defined(SC32f11xx)
typedef enum
{
    LCD_Duty_1_8 = ( uint32_t ) ( 0x00U << DDR_CFG_DUTY_Pos ),		/*!< LCD/LED display duty cycle: 1/8    */
    LCD_Duty_1_6 = ( uint32_t ) ( 0x01U << DDR_CFG_DUTY_Pos ),		/*!< LCD/LED display duty cycle: 1/6    */
    LCD_Duty_1_5 = ( uint32_t ) ( 0x02U << DDR_CFG_DUTY_Pos ),		/*!< LCD/LED display duty cycle: 1/5    */
    LCD_Duty_1_4_SEG0_34COM4_7
        = ( uint32_t ) ( 0x03U << DDR_CFG_DUTY_Pos ),								/*!< LCD/LED display duty cycle: 1/4    */
    LCD_Duty_1_4_SEG4_34COM0_3
        = ( uint32_t ) ( ( 0x03U << DDR_CFG_DUTY_Pos ) | DDR_CFG_SCS ),		/*!< LCD/LED display duty cycle: 1/4    */
} LCD_Duty_TypeDef;

#define IS_LCD_DUTY(DUTY) (((DUTY) == LCD_Duty_1_8) ||   \
																((DUTY) == LCD_Duty_1_6) ||   \
																((DUTY) == LCD_Duty_1_5) ||   \
																((DUTY) == LCD_Duty_1_4_SEG0_34COM4_7) ||   \
																((DUTY) == LCD_Duty_1_4_SEG4_34COM0_3))
#endif
/**
 * @}
 */

/** @brief LCD_Bias  LCD Bias Voltage
 * @{
 */
typedef enum
{
    LCD_Bias_1_4 = ( uint32_t ) ( 0x00U << DDR_CON_BIAS_Pos ), /*!< Display drive bias voltage Settings:1/3 */
    LCD_Bias_1_3 = ( uint32_t ) ( 0x01U << DDR_CON_BIAS_Pos ), /*!< Display drive bias voltage Settings:1/4 */
} LCD_Bias_TypeDef;

#define IS_LCD_BIAS(BIAS) (((BIAS) == LCD_Bias_1_3) || \
												   ((BIAS) == LCD_Bias_1_4))
/**
 * @}
 */

/** @brief LCD_VOIRSIF LCD Quick Charge State
 * @{
 */
typedef enum
{
    LCD_VOIRSIF_Disable = ( uint32_t ) ( 0x00U << DDR_CON_VOIRSF_Pos ), /*!< Quick charge: Disable */
    LCD_VOIRSIF_Enable = ( uint32_t ) ( 0x01U << DDR_CON_VOIRSF_Pos ), /*!< Quick charge: Enable */
} LCD_VOIRSIF_TypeDef;

#define IS_LCD_VOIRSIF(VOIRSIF) (((VOIRSIF) == LCD_VOIRSIF_DISABLE) || \
												        ((VOIRSIF) == LCD_VOIRSIF_ENABLE))
/**
 * @}
 */

/** @brief LCD_ResSel LCD resistor select
 * @{
 */
typedef enum
{
    LCD_ResSel_33K  = ( uint8_t ) ( 0x00U << DDR_CON_VOIRSF_Pos ), /*!< LCD voltage outlet voltage divider resistor:33K */
    LCD_ResSel_100K = ( uint8_t ) ( 0x01U << DDR_CON_VOIRSF_Pos ), /*!< LCD voltage outlet voltage divider resistor:100K */
    LCD_ResSel_300K = ( uint8_t ) ( 0x02U << DDR_CON_VOIRSF_Pos ),	/*!< LCD voltage outlet voltage divider resistor:300K */
    LCD_ResSel_800K = ( uint8_t ) ( 0x03U << DDR_CON_VOIRSF_Pos ), /*!< LCD voltage outlet voltage divider resistor:800K */
} LCD_ResSel_TypeDef;

#define IS_LCD_RESSEL(RES) (((RES) == LCD_ResSel_33K) || \
                            ((RES) == LCD_ResSel_100K) || \
                            ((RES) == LCD_ResSel_300K) || \
													  ((RES) == LCD_ResSel_800K))
/**
 * @}
 */

/** @brief LCD_Channel
 * @{
 */
#if defined(SC32f10xx) || defined(SC32f12xx)
typedef enum
{
    LCD_Channel_Less = ( int32_t ) 0x00000000U,	/*!< PMW output channel 0 */
    LCD_Channel_0 = ( int32_t ) 0x00000001U,	/*!< PMW output channel 0 */
    LCD_Channel_1 = ( int32_t ) 0x00000002U,	/*!< PMW output channel 1 */
    LCD_Channel_2 = ( int32_t ) 0x00000004U,	/*!< PMW output channel 2 */
    LCD_Channel_3 = ( int32_t ) 0x00000008U,	/*!< PMW output channel 3 */
    LCD_Channel_4 = ( int32_t ) 0x00000010U,	/*!< PMW output channel 4 */
    LCD_Channel_5 = ( int32_t ) 0x00000020U,	/*!< PMW output channel 5 */
    LCD_Channel_6 = ( int32_t ) 0x00000040U,	/*!< PMW output channel 6 */
    LCD_Channel_7 = ( int32_t ) 0x00000080U,	/*!< PMW output channel 7 */
    LCD_Channel_8 = ( int32_t ) 0x00000100U,	/*!< PMW output channel 8 */
    LCD_Channel_9 = ( int32_t ) 0x00000200U,	/*!< PMW output channel 9 */
    LCD_Channel_10 = ( int32_t ) 0x00000400U, /*!< PMW output channel 10 */
    LCD_Channel_11 = ( int32_t ) 0x00000800U, /*!< PMW output channel 11 */
    LCD_Channel_12 = ( int32_t ) 0x00001000U, /*!< PMW output channel 12 */
    LCD_Channel_13 = ( int32_t ) 0x00002000U, /*!< PMW output channel 13 */
    LCD_Channel_14 = ( int32_t ) 0x00004000U, /*!< PMW output channel 14 */
    LCD_Channel_15 = ( int32_t ) 0x00008000U, /*!< PMW output channel 15 */
    LCD_Channel_16 = ( int32_t ) 0x00010000U, /*!< PMW output channel 16 */
    LCD_Channel_17 = ( int32_t ) 0x00020000U, /*!< PMW output channel 17 */
    LCD_Channel_18 = ( int32_t ) 0x00040000U, /*!< PMW output channel 18 */
    LCD_Channel_19 = ( int32_t ) 0x00080000U, /*!< PMW output channel 19 */
    LCD_Channel_20 = ( int32_t ) 0x00100000U, /*!< PMW output channel 20 */
    LCD_Channel_21 = ( int32_t ) 0x00200000U, /*!< PMW output channel 21 */
    LCD_Channel_22 = ( int32_t ) 0x00400000U, /*!< PMW output channel 22 */
    LCD_Channel_23 = ( int32_t ) 0x00800000U, /*!< PMW output channel 23 */
    LCD_Channel_24 = ( int32_t ) 0x01000000U, /*!< PMW output channel 24 */
    LCD_Channel_25 = ( int32_t ) 0x02000000U, /*!< PMW output channel 25 */
    LCD_Channel_26 = ( int32_t ) 0x04000000U, /*!< PMW output channel 26 */
    LCD_Channel_27 = ( int32_t ) 0x08000000U, /*!< PMW output channel 27 */
    LCD_Channel_28 = ( int32_t ) 0x10000000U, /*!< PMW output channel 28 */
    LCD_Channel_29 = ( int32_t ) 0x20000000U, /*!< PMW output channel 29 */
    LCD_Channel_30 = ( int32_t ) 0x40000000U, /*!< PMW output channel 30 */
    LCD_Channel_31 = ( int32_t ) 0x80000000U, /*!< PMW output channel 31 */
} LCD_Channel_Typedef;


#define IS_LCD_Channel(Channel) ((Channel) <= (LCD_Channel_All))
#elif defined(SC32f11xx)
typedef enum
{
    LCD_Channel_Less = ( int32_t ) 0x00000000U,	/*!< LCD output channel 0 */
    LCD_Channel_0 = ( int32_t ) 0x00000001U,
    LCD_Channel_1 = ( int32_t ) 0x00000002U,
    LCD_Channel_2 = ( int32_t ) 0x00000004U,
    LCD_Channel_3 = ( int32_t ) 0x00000008U,
    LCD_Channel_4 = ( int32_t ) 0x00000010U,
    LCD_Channel_5 = ( int32_t ) 0x00000020U,
    LCD_Channel_6 = ( int32_t ) 0x00000040U,
    LCD_Channel_7 = ( int32_t ) 0x00000080U,
    LCD_Channel_8 = ( int32_t ) 0x00000100U,
    LCD_Channel_9 = ( int32_t ) 0x00000200U,
    LCD_Channel_10 = ( int32_t ) 0x00000400U,
    LCD_Channel_11 = ( int32_t ) 0x00000800U,
    LCD_Channel_12 = ( int32_t ) 0x00001000U,
    LCD_Channel_13 = ( int32_t ) 0x00002000U,
    LCD_Channel_14 = ( int32_t ) 0x00004000U,
    LCD_Channel_15 = ( int32_t ) 0x00008000U,
    LCD_Channel_16 = ( int32_t ) 0x00010000U,
    LCD_Channel_17 = ( int32_t ) 0x00020000U,
    LCD_Channel_18 = ( int32_t ) 0x00040000U,
    LCD_Channel_19 = ( int32_t ) 0x00080000U,
    LCD_Channel_20 = ( int32_t ) 0x00100000U,
    LCD_Channel_21 = ( int32_t ) 0x00200000U,
    LCD_Channel_22 = ( int32_t ) 0x00400000U,
    LCD_Channel_23 = ( int32_t ) 0x00800000U,
    LCD_Channel_24 = ( int32_t ) 0x01000000U,
    LCD_Channel_25 = ( int32_t ) 0x02000000U,
    LCD_Channel_26 = ( int32_t ) 0x04000000U,
    LCD_Channel_27 = ( int32_t ) 0x08000000U,
    LCD_Channel_28 = ( int32_t ) 0x10000000U,
    LCD_Channel_29 = ( int32_t ) 0x20000000U,
    LCD_Channel_30 = ( int32_t ) 0x40000000U,
    LCD_Channel_31 = ( int32_t ) 0x80000000U,
} LCD_Channel_Typedef;
#define LCD_Channel_32 (uint64_t)0x100000000
#define LCD_Channel_33 (uint64_t)0x200000000
#define LCD_Channel_34 (uint64_t)0x400000000
#define IS_LCD_Channel(Channel) ((Channel) <= (LCD_Channel_All))

#endif
/**
 * @}
 */

/** @brief LCD_RAMRegister
 * @{
 */
#if defined(SC32f10xx) || defined(SC32f12xx)
typedef enum
{
    LCD_RAMRegister_0 = 0x00000000U,
    LCD_RAMRegister_1 = 0x00000001U,
    LCD_RAMRegister_2 = 0x00000002U,
    LCD_RAMRegister_3 = 0x00000003U,
    LCD_RAMRegister_4 = 0x00000004U,
    LCD_RAMRegister_5 = 0x00000005U,
    LCD_RAMRegister_6 = 0x00000006U,
    LCD_RAMRegister_7 = 0x00000007U,
    LCD_RAMRegister_8 = 0x00000008U,
    LCD_RAMRegister_9 = 0x00000009U,
    LCD_RAMRegister_10 = 0x0000000AU,
    LCD_RAMRegister_11 = 0x0000000BU,
    LCD_RAMRegister_12 = 0x0000000CU,
    LCD_RAMRegister_13 = 0x0000000DU,
    LCD_RAMRegister_14 = 0x0000000EU,
    LCD_RAMRegister_15 = 0x0000000FU,
    LCD_RAMRegister_16 = 0x00000010U,
    LCD_RAMRegister_17 = 0x00000011U,
    LCD_RAMRegister_18 = 0x00000012U,
    LCD_RAMRegister_19 = 0x00000013U,
    LCD_RAMRegister_20 = 0x00000014U,
    LCD_RAMRegister_21 = 0x00000015U,
    LCD_RAMRegister_22 = 0x00000016U,
    LCD_RAMRegister_23 = 0x00000017U,
    LCD_RAMRegister_24 = 0x00000018U,
    LCD_RAMRegister_25 = 0x00000019U,
    LCD_RAMRegister_26 = 0x0000001AU,
    LCD_RAMRegister_27 = 0x0000001BU,
} LCD_RAMRegister_Typedef;

#define IS_LCD_RAM_REGISTER(REGISTER) ((REGISTER) <= (LCD_RAMRegister27))
#elif defined(SC32f11xx)
typedef enum
{
    LCD_RAMRegister_0 = 0x00000000U,
    LCD_RAMRegister_1 = 0x00000001U,
    LCD_RAMRegister_2 = 0x00000002U,
    LCD_RAMRegister_3 = 0x00000003U,
    LCD_RAMRegister_4 = 0x00000004U,
    LCD_RAMRegister_5 = 0x00000005U,
    LCD_RAMRegister_6 = 0x00000006U,
    LCD_RAMRegister_7 = 0x00000007U,
    LCD_RAMRegister_8 = 0x00000008U,
    LCD_RAMRegister_9 = 0x00000009U,
    LCD_RAMRegister_10 = 0x0000000AU,
    LCD_RAMRegister_11 = 0x0000000BU,
    LCD_RAMRegister_12 = 0x0000000CU,
    LCD_RAMRegister_13 = 0x0000000DU,
    LCD_RAMRegister_14 = 0x0000000EU,
    LCD_RAMRegister_15 = 0x0000000FU,
    LCD_RAMRegister_16 = 0x00000010U,
    LCD_RAMRegister_17 = 0x00000011U,
    LCD_RAMRegister_18 = 0x00000012U,
    LCD_RAMRegister_19 = 0x00000013U,
    LCD_RAMRegister_20 = 0x00000014U,
    LCD_RAMRegister_21 = 0x00000015U,
    LCD_RAMRegister_22 = 0x00000016U,
    LCD_RAMRegister_23 = 0x00000017U,
    LCD_RAMRegister_24 = 0x00000018U,
    LCD_RAMRegister_25 = 0x00000019U,
    LCD_RAMRegister_26 = 0x0000001AU,
    LCD_RAMRegister_27 = 0x0000001BU,
    LCD_RAMRegister_28 = 0x0000001CU,
    LCD_RAMRegister_29 = 0x0000001DU,
    LCD_RAMRegister_30 = 0x0000001EU,
    LCD_RAMRegister_31 = 0x0000001FU,
    LCD_RAMRegister_32 = 0x00000020U,
    LCD_RAMRegister_33 = 0x00000021U,
    LCD_RAMRegister_34 = 0x00000022U,

} LCD_RAMRegister_Typedef;
#define IS_LCD_RAM_REGISTER(REGISTER) ((REGISTER) <= (LCD_RAMRegister_34))
#endif

typedef enum
{
    LCD_COMEN_0 = 0x00000001U,
    LCD_COMEN_1 = 0x00000002U,
    LCD_COMEN_2 = 0x00000004U,
    LCD_COMEN_3 = 0x00000008U,
    LCD_COMEN_4 = 0x00000010U,
    LCD_COMEN_5 = 0x00000020U,
    LCD_COMEN_6 = 0x00000040U,
    LCD_COMEN_7 = 0x00000080U,
} LCD_COMEN_Typedef;


/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/* Exported struct ------------------------------------------------------------*/
/** @defgroup LCD_Exported_Struct LCD Exported Struct
 * @{
 */

/** @brief LCD Display Init structure definition
 * @{
 */
typedef struct
{
    uint16_t LCD_FrameFre;				/*!< Specifies the frame frequency.
																			This parameter can be a value of @ref LCD_FrameFre_TypeDef */

    uint16_t LCD_Duty;						/*!< Specifies the display duty cycle.
																			This parameter can be a value of @ref LCD_Duty_TypeDef */

    uint16_t LCD_VOIRSIF;		/*!<  Specifies whether LCD VOIRSIF is enabled or disabled.
																			This parameter can be a value of @ref LCD_VOIRSIF_TypeDef */

    uint16_t LCD_Bias;						/*!<  Specifies the bias voltage.
																			This parameter can be a value of @ref LCD_Bias_TypeDef */

    uint16_t LCD_ResSel;						/*!<  Specifies the voltage outlet voltage divider resistor.
																				This parameter can be a value of @ref LCD_ResSel_TypeDef */

    uint16_t LCD_Voltage;						/*!<  Specifies the voltage.
																				The VLCD is computed using the following formula:
																				VLCD = VDD*(17+VLCD[3:0]/32) */

    uint32_t LCD_ComPin;						/*!< Specifies the Com Pin.
																				Each bit represents a Seg channel,Support 8 channels.*/
#if defined (SC32f10xx) || defined(SC32f12xx)
    uint32_t LCD_SegPin;						/*!< Specifies the Seg Pin.
																				Each bit represents a Seg channel,Support 28 channels.*/
#elif defined (SC32f11xx)
    uint64_t LCD_SegPin;            /*!< Specifies the Seg Pin.
																				Each bit represents a Seg channel,Support 35 channels.*/
#endif
} LCD_InitTypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of struct -----------------------------------------------------*/

/** @addtogroup LCD_Exported_Functions LCD Exported Functions
 * @{
 */

/* Initialization and Configuration functions ***********************************************/
void LCD_DeInit ( void );
void LCD_Init ( LCD_InitTypeDef* LCD_InitStruct );
void LCD_StructInit ( LCD_InitTypeDef* LCD_InitStruct );
void LCD_Cmd ( FunctionalState NewState );

/* Initialization and Configuration functions ***********************************************/
void LCD_COMConfig ( LCD_COMEN_Typedef COMSelect, FunctionalState NewState );
void LCD_SEGConfig ( uint64_t SEGSelect, FunctionalState NewState );
void LCD_Write ( LCD_RAMRegister_Typedef LCD_RAMRegister, uint8_t LCD_Data );
void LCD_CustomModeScan ( void );

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
