/*
 ******************************************************************************
 * @file    sc32f1xxx_btm.c
 * @author  SOC AE Team
 * @version V1.7
 * @date     17-10-2024
 * @brief  BTM function module
 *
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

/* Includes ------------------------------------------------------------------*/
#include "sc32f1xxx_btm.h"

/** @defgroup BTM_Exported_Functions_Group1 Configuration of the BTM computation unit functions
 *  @brief   Configuration of the BTM computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### BTM configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitialize the BTMx peripheral registers to their default reset values.
 * @param  BTMx[out]:
 *                  - BTM: Only BTM can be select the BTMx peripheral.
 * @retval None
 */
void BTM_DeInit ( BTM_TypeDef* BTMx )
{
    /* Check the parameters */
    assert_param ( IS_BTM_ALL_PERIPH ( BTMx ) );

    if ( BTMx == BTM )
    {
        /* Enable BTM0 reset state */
        BTMx->BTM_CON = 0x0000;
        BTMx->BTM_STS = 0xFFFF;
    }
}

/**
 * @brief  Configures the BTMx Frequency Select.
 * @param  BTMx[out]:
 *                  - BTM: Only BTM can be select the BTMx peripheral.
 * @param  BTM_FreqSelect[in]:specifies the BTM Frequency Select.
 *                  - BTM_FreqSelect_15_625MS:BTM Interruption: Happens every 15.625MS
 *                  - BTM_FreqSelect_31_25MS :BTM Interruption: Happens every 31.25MS
 *                  - BTM_FreqSelect_62_5MS:BTM Interruption: Happens every 62.5MS
 *                  - BTM_FreqSelect_125MS:BTM Interruption: Happens every 125MS
 *                  - BTM_FreqSelect_250MS :BTM Interruption: Happens every 250MS
 *                  - BTM_FreqSelect_500MS:BTM Interruption: Happens every 500MS
 *                  - BTM_FreqSelect_1S :BTM Interruption: Happens every 1S
 *                  - BTM_FreqSelect_2S :BTM Interruption: Happens every 2S
 *                  - BTM_FreqSelect_4S:BTM Interruption: Happens every 4S
 *                  - BTM_FreqSelect_8S:BTM Interruption: Happens every 8S
 *                  - BTM_FreqSelect_16S :BTM Interruption: Happens every 16S
 *                  - BTM_FreqSelect_32S : Happens every 32S
 * @retval None
 */
void BTM_FSConfig ( BTM_TypeDef* BTMx, BTM_FreqSelect_TypeDef BTM_FreqSelect )
{
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_BTM_ALL_PERIPH ( BTMx ) );
    assert_param ( IS_BTM_FREQSELECT ( BTM_FreqSelect ) );

    /*---------------------------- BTMx BTM_CON Configuration ------------------------*/
    /* Get the BTMx BTM_CON value */
    tmpreg = BTMx->BTM_CON;
    /* Clear BTMFS bits */
    tmpreg &= ( uint32_t ) ~ BTM_CON_BTMFS ;

    /* Configure BTMx: Freq Select */
    /* Set BTMFS bit to BTM_FreqSelect value */
    tmpreg |= ( uint32_t ) ( BTM_FreqSelect );
    /* Write to BTMx BTM_CON */
    BTMx->BTM_CON = tmpreg;
}

/**
 * @brief  Enables or disables the specified BTM peripheral.
 * @param  BTMx[out]:
 *                  - BTM: Only BTM can be select the BTMx peripheral.
 * @param  NewState[in]: new state of the BTMx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void BTM_Cmd ( BTM_TypeDef* BTMx, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_BTM_ALL_PERIPH ( BTMx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the BTM Function */
        BTMx->BTM_CON |= BTM_CON_BTMEN;
    }
    else
    {
        /* Disable the BTM Function */
        BTMx->BTM_CON &= ( uint16_t ) ~BTM_CON_BTMEN;
    }
}

/** @defgroup BTM_Group2 Interrupts and flags management functions
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
 * @brief  Enables or disables the specified BTM interrupts.
 * @param  BTMx[out]:
 *                  - BTM: Only BTM can be select the BTMx peripheral.
 * @param  BTM_IT[in]: specifies the BTM interrupts sources to be enabled or disabled.
 *                  - BTM_IT_INT : BTM Interrupt
 * @param  NewState[in]: new state of the BTM interrupts.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void BTM_ITConfig ( BTM_TypeDef* BTMx, uint16_t BTM_IT, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_BTM_ALL_PERIPH ( BTMx ) );
    assert_param ( IS_BTM_IT ( BTM_IT ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the Interrupt sources */
        BTMx->BTM_CON |= BTM_IT;
    }
    else
    {
        /* Disable the Interrupt sources */
        BTMx->BTM_CON &= ( uint16_t ) ~BTM_IT;
    }
}

/**
 * @brief  Checks whether the specified BTM flag is set or not.
 * @param  BTMx[out]:
 *                  - BTM: Only BTM can be select the BTMx peripheral.
 * @param  BTM_FLAG[in]: specifies the flag to check.
 *                  - BTM_FLAG_IF :Interrupt flag
 * @retval FlagStatus:
 *          -  RESET:Flag reset
 *          -  SET :Flag up
 */
FlagStatus BTM_GetFlagStatus ( BTM_TypeDef* BTMx, BTM_FLAG_TypeDef BTM_FLAG )
{
    ITStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param ( IS_BTM_ALL_PERIPH ( BTMx ) );
    assert_param ( IS_GET_BTM_FLAG ( BTM_FLAG ) );

    if ( ( BTMx->BTM_STS & BTM_FLAG ) != ( uint16_t ) RESET )
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    return bitstatus;
}

/**
 * @brief  Clears the BTMx's pending flags.
 * @param  BTMx[out]:
 *                  - BTM: Only BTM can be select the BTMx peripheral.
 * @param  BTM_FLAG[in]: specifies the flag bit to clear.
 *                  - BTM_FLAG_IF :Interrupt flag
 * @retval None
 */
void BTM_ClearFlag ( BTM_TypeDef* BTMx, BTM_FLAG_TypeDef BTM_FLAG )
{
    /* Check the parameters */
    assert_param ( IS_BTM_ALL_PERIPH ( BTMx ) );
    assert_param ( IS_BTM_FLAG ( BTM_FLAG ) );

    /* Clear the flags */
    BTMx->BTM_STS = ( uint16_t ) BTM_FLAG;
}

/**
 * @}
 */
/* End of BTM_Group2.	*/

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
