/**
 ******************************************************************************
 * @file    sc32f1xxx_btm.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   Header file of BTM module.
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
#ifndef __sc32f1xxx_BTM_H
#define __sc32f1xxx_BTM_H

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

/** @addtogroup BTM
 * @{
 */

/** @defgroup BTM_Enumerations BTM Enumerations
 * @{
 */

/** @brief BTM_FreqSelect BTM FreqSelect
 * @{
 */
typedef enum
{
    BTM_FreqSelect_15_625MS = 0x00U << BTM_CON_BTMFS_Pos,    /*!< BTM Interruption: Happens every 15.625MS    */
    BTM_FreqSelect_31_25MS = 0x01U << BTM_CON_BTMFS_Pos,    /*!< BTM Interruption: Happens every 31.25MS   */
    BTM_FreqSelect_62_5MS = 0x02U << BTM_CON_BTMFS_Pos,    /*!< BTM Interruption: Happens every 62.5MS    */
    BTM_FreqSelect_125MS = 0x03U << BTM_CON_BTMFS_Pos,    /*!< BTM Interruption: Happens every 125MS    */
    BTM_FreqSelect_250MS = 0x04U << BTM_CON_BTMFS_Pos,   /*!< BTM Interruption: Happens every 250MS    */
    BTM_FreqSelect_500MS = 0x05U << BTM_CON_BTMFS_Pos,   /*!< BTM Interruption: Happens every 500MS    */
    BTM_FreqSelect_1S = 0x06U << BTM_CON_BTMFS_Pos,   /*!< BTM Interruption: Happens every 1S    */
    BTM_FreqSelect_2S = 0x07U << BTM_CON_BTMFS_Pos,  /*!< BTM Interruption: Happens every 2S    */
    BTM_FreqSelect_4S = 0x08U << BTM_CON_BTMFS_Pos,  /*!< BTM Interruption: Happens every 4S    */
    BTM_FreqSelect_8S = 0x09U << BTM_CON_BTMFS_Pos,  /*!< BTM Interruption: Happens every 8S    */
    BTM_FreqSelect_16S = 0x0AU << BTM_CON_BTMFS_Pos, /*!< BTM Interruption: Happens every 16S    */
    BTM_FreqSelect_32S = 0x0BU << BTM_CON_BTMFS_Pos,       /*!< Happens every 32S    */
} BTM_FreqSelect_TypeDef;

#define IS_BTM_FREQSELECT(SELECT) (((SELECT) == BTM_FreqSelect_15_625MS) || \
                                   ((SELECT) == BTM_FreqSelect_31_25MS) || \
                                   ((SELECT) == BTM_FreqSelect_62_5MS) || \
                                   ((SELECT) == BTM_FreqSelect_125MS) || \
                                   ((SELECT) == BTM_FreqSelect_250MS) || \
                                   ((SELECT) == BTM_FreqSelect_500MS) || \
                                   ((SELECT) == BTM_FreqSelect_1S) || \
                                   ((SELECT) == BTM_FreqSelect_2S) || \
                                   ((SELECT) == BTM_FreqSelect_4S) || \
                                   ((SELECT) == BTM_FreqSelect_8S) || \
                                   ((SELECT) == BTM_FreqSelect_16S) || \
                                   ((SELECT) == BTM_FreqSelect_32S))
/**
 * @}
 */

/** @brief BTM_IT BTM Interrupt
 * @{
 */
typedef enum
{
    BTM_IT_INT = ( uint32_t ) BTM_CON_INTEN,	/*!< BTM Interrupt: BTM Interrupt */
} BTM_IT_TypeDef;

#define IS_BTM_IT(IT) ((((IT) & (uint8_t)0xFE) == 0x00) && ((IT) != (uint8_t)0x00))
/**
 * @}
 */

/** @brief BTM_FLAG BTM Flag
 * @{
 */
typedef enum
{
    BTM_FLAG_IF = ( uint8_t ) BTM_STS_BTMIF, /*!< BTM Flag: Interrupt flag */
} BTM_FLAG_TypeDef;

#define IS_BTM_FLAG(FLAG) ((((FLAG) & (uint8_t)0xFE) == 0x00) && ((FLAG) != (uint8_t)0x00))

#define IS_GET_BTM_FLAG(FLAG) (((FLAG) == BTM_FLAG_IF))
/**
 * @}
 */

/**
 * @}
 */
/* End of BTM Enumerations.	*/


#define IS_BTM_ALL_PERIPH(PERIPH) ((PERIPH) == BTM)
/**
 * @}
 */
/* End of constants -----------------------------------------------------*/


/** @addtogroup BTM_Functions BTM Functions
 * @{
 */

/* BTM Base functions ********************************************************/
void BTM_DeInit ( BTM_TypeDef* BTMx );
void BTM_FSConfig ( BTM_TypeDef* BTMx, BTM_FreqSelect_TypeDef BTM_FreqSelect );
void BTM_Cmd ( BTM_TypeDef* BTMx, FunctionalState NewState );

/* Interrupts and flags management functions  **********************************************/
void BTM_ITConfig ( BTM_TypeDef* BTMx, uint16_t BTM_IT, FunctionalState NewState );
FlagStatus BTM_GetFlagStatus ( BTM_TypeDef* BTMx, BTM_FLAG_TypeDef BTM_FLAG );
void BTM_ClearFlag ( BTM_TypeDef* BTMx, BTM_FLAG_TypeDef BTM_FLAG );

/**
 * @}
 */
/* End of BTM Functions.	*/

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
