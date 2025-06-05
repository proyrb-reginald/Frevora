/**
 ******************************************************************************
 * @file    sc32f15Gx_vref.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   Header file of VREF module.
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
#ifndef __sc32f15Gx_VREF_H
#define __sc32f15Gx_VREF_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "sc32f15Gx.h"
#include "sc32.h"
#include "sc32f1xxx_rcc.h"

/** @addtogroup sc32f15Gx_StdPeriph_Driver
 * @{
 */


/** @defgroup Peripheral_Voltage Peripheral Reference Voltage
 * @{
 */
                     

typedef enum
{
    Vref_ReferenceVoltageNone     = (uint8_t)(0x00 << VREF_CFG_VREFCFG0_Pos),            /*!< VREF Reference Voltage  None*/
    Vref_ExReferenceVoltage       = (uint8_t)(0x02 << VREF_CFG_VREFCFG0_Pos),                /*!< VREF ExReference Voltage  */
	  Vref_InReferenceVoltageEx_2_048 = (uint8_t)(0x01 << VREF_CFG_VREFS_Pos)|(0x03 << VREF_CFG_VREFCFG0_Pos), /*!< VREF InReferenceVoltageEx 2.048  */
	  Vref_InReferenceVoltageEx_1_024 = (uint8_t)(0x02 << VREF_CFG_VREFS_Pos)|(0x03 << VREF_CFG_VREFCFG0_Pos), /*!< VREF InReferenceVoltageEx 1.024  */
	  Vref_InReferenceVoltageEx_2_4 = (uint8_t)(0x03 << VREF_CFG_VREFS_Pos)|(0x03 << VREF_CFG_VREFCFG0_Pos), /*!< VREF InReferenceVoltageEx 2.4  */
    Vref_InReferenceVoltage_2_048    = (uint8_t)(0x01 << VREF_CFG_VREFS_Pos)|(0x01 << VREF_CFG_VREFCFG0_Pos), /*!<Vref_ReferenceVoltage:2.048 */
    Vref_InReferenceVoltage_1_024    = (uint8_t)(0x02 << VREF_CFG_VREFS_Pos)|(0x01 << VREF_CFG_VREFCFG0_Pos),	/*!< Vref_ReferenceVoltage:1.024 */
    Vref_InReferenceVoltage_2_4      = (uint8_t)(0x03 << VREF_CFG_VREFS_Pos)|(0x01 << VREF_CFG_VREFCFG0_Pos),	/*!< Vref_ReferenceVoltage:2.4*/
} Vref_ReferenceVoltage_TypeDef;
#define  IS_Vref_ReferenceVoltage(Vref_ReferenceVoltage) (((Vref_ReferenceVoltage) == Vref_ReferenceVoltageNone)    || \
																												 ((Vref_ReferenceVoltage) == Vref_ExReferenceVoltage)    || \
																												 ((Vref_ReferenceVoltage) == Vref_InReferenceVoltageEx_2_048)    || \
                                                         ((Vref_ReferenceVoltage) == Vref_InReferenceVoltageEx_1_024)    || \
                                                         ((Vref_ReferenceVoltage) == Vref_InReferenceVoltageEx_2_4)    || \
																												 ((Vref_ReferenceVoltage) == Vref_InReferenceVoltage_2_048)    || \
																												 ((Vref_ReferenceVoltage) == Vref_InReferenceVoltage_1_024)    || \
																												 ((Vref_ReferenceVoltage) == Vref_InReferenceVoltage_2_4))
/**
 * @}
 */

#define IS_Vref_ALL_PERIPH(PERIPH) ((PERIPH)==VREF)
/* End of struct -----------------------------------------------------*/

/** @addtogroup VREF_Functions VREF Functions
 * @{
 */
/* Vref_Config functions  ***********************************************/
ErrorStatus Vref_ReferenceVoltageConfig(VREF_TypeDef* Vrefx, Vref_ReferenceVoltage_TypeDef Vref_ReferenceVoltage);
void Vref_DIVENCmd(VREF_TypeDef* Vrefx, FunctionalState NewState);
void Vref_VMIDCmd(VREF_TypeDef* Vrefx, FunctionalState NewState);
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
