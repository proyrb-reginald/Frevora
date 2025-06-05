/**
 ******************************************************************************
 * @file    sc32f1xxx_PWR.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   Header file of PWR module.
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
#ifndef __sc32f1xxx_PWR_H
#define __sc32f1xxx_PWR_H

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

/** @addtogroup PWR
 * @{
 */

/** @defgroup PWR_Enumerations PWR Enumerations
 * @{
 */

/** @brief PWR_IDLEEntry PWR IDLE Mode Entry
 * @{
 */
typedef enum
{
    PWR_IDLEEntry_WFI = ( ( uint8_t ) 0x01 ), /*!< WFI SLEEP Mode   */
    PWR_IDLEEntry_WFE = ( ( uint8_t ) 0x02 ), /*!< WFE SLEEP Mode   */

} PWR_IDLEEntry_TypeDef;

#define IS_PWR_IDLE_ENTRY(ENTRY) (((ENTRY) == PWR_IDLEEntry_WFI) || \
                                   ((ENTRY) == PWR_IDLEEntry_WFE))
/**
 * @}
 */

/** @brief PWR_STOPEntry PWR STOP Mode Entry
 * @{
 */
typedef enum
{
    PWR_STOPEntry_WFI = ( ( uint8_t ) 0x01 ), /*!< WFI STOP Mode   */
    PWR_STOPEntry_WFE = ( ( uint8_t ) 0x02 ), /*!< WFE STOP Mode   */

} PWR_STOPEntry_TypeDef;

#define IS_PWR_STOP_ENTRY(ENTRY) (((ENTRY) == PWR_STOPEntry_WFI) || \
                                   ((ENTRY) == PWR_STOPEntry_WFE))
/**
 * @}
 */

/**
 * @}
 */
/* End of PWR Enumerations.	*/

/** @addtogroup PWR_Functions PWR Functions
 * @{
 */

/* Low Power modes configuration functions ********************************************************/
void PWR_EnterIDLEMode ( uint8_t PWR_IDLEEntry );
void PWR_EnterSTOPMode ( uint8_t PWR_STOPEntry );
/**
 * @}
 */
/* End of PWR Functions.	*/

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
