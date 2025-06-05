/**
******************************************************************************
* @file    sc32f15Gx_Temper.h
* @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
* @brief   Header file of TS module.
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
#ifndef __sc32f15Gx_TS_H
#define __sc32f15Gx_TS_H

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

/** @addtogroup TS
 * @{
 */

/* Exported enumerations ------------------------------------------------------------*/
/** @defgroup TS_Exported_Enumerations TS Exported Enumerations
 * @{
 */

/** @defgroup TemperSensor_EN TemperSensor EN
 * @{
 */
typedef enum
{
   TemperSensor_Disable = 0x00<< TS_CFG_EN_Pos,/*!< TS Disable*/
	 TemperSensor_Enable = 0x01<< TS_CFG_EN_Pos,/*!< TS Enable */
} TemperSensor_EN_TypeDef;



/**
 * @}
 */
/* End of struct -----------------------------------------------------*/

/** @addtogroup TS_Exported_Functions TS Exported Functions
 * @{
 */

/* Initialization and Configuration functions ***********************************************/

void TemperSensor_DeInit(void);
void TemperSensor_Cmd(TS_TypeDef* TSx, FunctionalState NewState);
void TemperSensor_OffSetCmd(TS_TypeDef* TSx);
void TemperSensor_OffResetCmd(TS_TypeDef* TSx);
uint16_t TemperSensor_ReadValue(void);
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
