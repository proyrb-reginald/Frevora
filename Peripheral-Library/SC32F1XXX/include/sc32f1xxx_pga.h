/**
 ******************************************************************************
 * @file    sc32f1xxx_pga.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    14-10-2024
 * @brief   Header file of PGA module.
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
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __sc32f1xxx_PGA_H
#define __sc32f1xxx_PGA_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "sc32f1xxx.h"
#include "sc32.h"
#include "sc32f1xxx_rcc.h"





/** @addtogroup PGA
 * @{
 */

/** @brief PGA_Enumerations PGA Enumerations
 * @{
 */

typedef enum
{
    PGA_INSEL_PGAI0	= ( uint16_t ) ( 0x00U << PGA_CON_PGAINSEL_Pos ), /*!< The current PGA signal input is PGAI0 */
    PGA_INSEL_PGAI1	= ( uint16_t ) ( 0x01U << PGA_CON_PGAINSEL_Pos ), /*!< The current PGA signal input is PGAI1  */
} PGA_INSEL_TypeDef;

#define IS_PGA_INSEL(COM) (((COM) == PGA_INSEL_PGAI0) || \
													((COM) == PGA_INSEL_PGAI1))


/** @brief PGA_POSITIVE PGA POSITIVE
 * @{
 */
typedef enum
{
    PGA_COM_0V		= ( uint16_t ) ( 0x00U << PGA_CON_PGACOM_Pos ), /*!< The common-mode voltage : 0V    */
    PGA_COM_1_2V	= ( uint16_t ) ( 0x01U << PGA_CON_PGACOM_Pos ), /*!< The common-mode voltage : 1.2V    */
} PGA_COM_TypeDef;

#define IS_PGA_COM(COM) (((COM) == PGA_COM_0V) || \
                                    ((COM) == PGA_COM_1_2V))

/**
 * @}
 */

/** @brief PGA_NEGATIVE PGA NEGATIVE
 * @{
 */
typedef enum
{
    PGA_GAN_Invert19 = ( uint16_t ) ( ( 0x00U << PGA_CON_PGAGAN_Pos ) | PGA_CON_PGAIPT ), /*!< The PGA inverting input gain is 19 times  */
    PGA_GAN_Invert99 = ( uint16_t ) ( ( 0x01U << PGA_CON_PGAGAN_Pos ) | PGA_CON_PGAIPT ), /*!< The PGA inverting input gain is 99 times   */

    PGA_GAN_NonInvert20 = ( uint16_t ) ( 0x00U << PGA_CON_PGAGAN_Pos ), /*!< The PGA in-phase input gain is 20 times  */
    PGA_GAN_NonInvert100 = ( uint16_t ) ( 0x01U << PGA_CON_PGAGAN_Pos ), /*!< The PGA in-phase input gain is 100 times  */
} PGA_GAN_TypeDef;

#define IS_PGA_GAN(GAN) (((GAN) == PGA_GAN_NonInvert20) || \
                                    ((GAN) == PGA_GAN_NonInvert100) || \
                                    ((GAN) == PGA_GAN_Invert19) || \
                                    ((GAN) == PGA_GAN_Invert99))

/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @brief PGA_Constants PGA Constants
  * @{
  */

#define IS_PGA_ALL_PERIPH(PERIPH) ((PERIPH) == PGA)
/**
 * @}
 */
/* End of constants -----------------------------------------------------*/

/** @brief PGA_Struct PGA Struct
 * @{
 */

/** @brief PGA Time base Configuration Structure definition
 * @{
 */
typedef struct
{

    uint16_t PGA_INSEL; /*!< This member configures PGA .
                                              This parameter can be a value of @ref PGA_INSEL_TypeDef. */


    uint16_t PGA_COM;   /*!< This member configures PGA common-mode voltage.
                                              This parameter can be a value of @ref PGA_COM_TypeDef. */

    uint16_t PGA_GAN; /*!< This member configures PGA input gain.
                                              This parameter can be a value of @ref PGA_GAN_TypeDef. */

} PGA_InitTypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of Struct -----------------------------------------------------*/

/** @addtogroup PGA_Functions PGA Functions
 * @{
 */

/* PGA Base functions ********************************************************/
void PGA_DeInit ( PGA_TypeDef* PGAx );
void PGA_Init ( PGA_TypeDef* PGAx, PGA_InitTypeDef* PGA_InitStruct );
void PGA_Cmd ( PGA_TypeDef* PGAx, FunctionalState NewState );

/* Calibration functions ******************************************************/
void PGA_OffsetTrimConfig ( PGA_TypeDef* PGAx, uint32_t PGA_TrimValue );
void PGA_StartCalibration ( PGA_TypeDef* PGAx, FunctionalState NewState );

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
