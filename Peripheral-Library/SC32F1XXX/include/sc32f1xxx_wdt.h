/**
 ******************************************************************************
 * @file    sc32f1xxx_WDT.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   Header file of WDT module.
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
#ifndef __sc32f1xxx_WDT_H
#define __sc32f1xxx_WDT_H

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

/** @addtogroup WDT
 * @{
 */

/** @defgroup WDT_Enumerations WDT Enumerations
 * @{
 */

/** @brief WDT_OverTime WDT OverTime
 * @{
 */
typedef enum
{
    WDT_OverTime_500MS = ( uint8_t ) 0x00U << WDT_CFG_WDTCKS_Pos, /*!< WDT Interruption: Happens every 500MS    */
    WDT_OverTime_250MS = ( uint8_t ) 0x01U << WDT_CFG_WDTCKS_Pos, /*!< WDT Interruption: Happens every 250MS   */
    WDT_OverTime_125MS = ( uint8_t ) 0x02U << WDT_CFG_WDTCKS_Pos, /*!< WDT Interruption: Happens every 125MS    */
    WDT_OverTime_62_5MS = ( uint8_t ) 0x03U << WDT_CFG_WDTCKS_Pos, /*!< WDT Interruption: Happens every 62.5MS    */
    WDT_OverTime_31_5MS = ( uint8_t ) 0x04U << WDT_CFG_WDTCKS_Pos, /*!< WDT Interruption: Happens every 31.5MS    */
    WDT_OverTime_15_75MS = ( uint8_t ) 0x05U << WDT_CFG_WDTCKS_Pos, /*!< WDT Interruption: Happens every 15.75MS    */
    WDT_OverTime_7_88MS = ( uint8_t ) 0x06U << WDT_CFG_WDTCKS_Pos, /*!< WDT Interruption: Happens every 7.88MS    */
    WDT_OverTime_3_94MS = ( uint8_t ) 0x07U << WDT_CFG_WDTCKS_Pos, /*!< WDT Interruption: Happens every 3.94MS    */
} WDT_OverTime_TypeDef;

#define IS_WDT_OverTime(OVERTIME) (((OVERTIME) == WDT_OverTime_500MS) || \
                                    ((OVERTIME) == WDT_OverTime_250MS) || \
                                    ((OVERTIME) == WDT_OverTime_125MS) || \
                                    ((OVERTIME) == WDT_OverTime_62_5MS) || \
                                    ((OVERTIME) == WDT_OverTime_31_5MS) || \
                                    ((OVERTIME) == WDT_OverTime_15_75MS) || \
                                    ((OVERTIME) == WDT_OverTime_7_88MS) || \
                                    ((OVERTIME) == WDT_OverTime_3_94MS))
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup WDT_Functions WDT Functions
 * @{
 */

/* WDT Base functions ********************************************************/
void WDT_DeInit ( void );
void WDT_SetOverTime ( WDT_OverTime_TypeDef WDT_OverTime );
void WDT_Cmd ( FunctionalState NewState );

/* WDT SetReload functions  **********************************************/
void WDT_SetReload ( void );

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
