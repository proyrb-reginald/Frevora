/*
 ******************************************************************************
 * @file    sc32f1xxx_wdt.c
 * @author  SOC AE Team
 * @version V1.7
 * @date     17-10-2024
 * @brief   WDT function module
 *
 *******************************************************************************
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

/* Includes ------------------------------------------------------------------*/
#include "sc32f1xxx_wdt.h"

/** @defgroup WDT_Group1 Configuration of the WDT computation unit functions
 *  @brief   Configuration of the WDT computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### WDT configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitialize the WDTx peripheral registers to their default reset values.
 * @param  None
 * @retval None
 */
void WDT_DeInit ( void )
{
    /* Check the parameters */

    WDT->WDT_CFG = 0x00;
    WDT->WDT_CON = 0x00;
}

/**
  * @brief  Set the reset time for WDT.
  * @param  WDT_OverTime[in]: specifies the WDG OverTime value.
  *                     - WDT_OverTime_500MS:WDT Interruption: Happens every 500MS
  *                     - WDT_OverTime_250MS:WDT Interruption: Happens every 250MS
  *                     - WDT_OverTime_125MS:WDT Interruption: Happens every 125MS
  *                     - WDT_OverTime_62_5MS:WDT Interruption: Happens every 62.5MS
  *                     - WDT_OverTime_31_5MS:WDT Interruption: Happens every 31.5MS
  *                     - WDT_OverTime_15_75MS:WDT Interruption: Happens every 15.75MS
  *                     - WDT_OverTime_7_88MS:WDT Interruption: Happens every 7.88MS
  *                     - WDT_OverTime_3_94MS:WDT Interruption: Happens every 3.94MS
  * @retval None
  */
void WDT_SetOverTime ( WDT_OverTime_TypeDef WDT_OverTime )
{
    uint8_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_WDT_OverTime ( WDT_OverTime ) );

    tmpreg = ( uint8_t ) WDT->WDT_CFG;

    tmpreg &= ~WDT_CFG_WDTCKS;

    tmpreg |= WDT_OverTime;

    WDT->WDT_CFG = tmpreg;
}

/**
  * @brief  Enables or disables the WDT peripheral.
  * @param  NewState[in]: new state of the ADCx peripheral.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable
  * @retval None
  */
void WDT_Cmd ( FunctionalState NewState )
{
    OPT->OPINX = 0xC2;

    if ( NewState == DISABLE )
    {
        OPT->OPREG &= 0X7F;
    }
    else
    {
        OPT->OPREG |= 0X80;
    }
}
/** @defgroup WDT_Group2 Interrupts and flags management functions
 *  @brief   Interrupts and flags management functions
 *
@verbatim
 ===============================================================================
            ##### Interrupts and flags management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
  * @brief  Sets WDG Reload.
  * @retval None
  */
void WDT_SetReload ( void )
{
    /* Check the parameters */
    WDT->WDT_CON |= WDT_CON_CLRWDT;
}

/**
 * @}
 */
/* End of WDT_Group2.	*/

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT SOC Microelectronics *****END OF FILE****/
