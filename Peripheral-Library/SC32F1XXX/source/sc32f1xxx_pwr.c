/*
 ******************************************************************************
 * @file    sc32f1xxx_pwr.c
 * @author  SOC AE Team
 * @version V1.7
 * @date     17-10-2024
 * @brief PWR function module
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
#include "sc32f1xxx_pwr.h"

/** @defgroup PWR_Group1 Low Power modes configuration functions
 *  @brief   Low Power modes configuration functions
 *
@verbatim
	==============================================================================
							##### Low Power modes configuration functions #####
	==============================================================================
@endverbatim
  * @{
  */

/**
  * @brief  Enters IDLE mode.
  * @note   In IDLE mode, all I/O pins keep the same state as in Run mode.
  * @param  PWR_IDLEEntry[in]: specifies if IDLE mode in entered with WFI or WFE instruction.
  *          This parameter can be one of the following values:
  *             - PWR_SLEEPEntry_WFI: enter SLEEP mode with WFI instruction
  *             - PWR_SLEEPEntry_WFE: enter SLEEP mode with WFE instruction
  * @retval None
  */
void PWR_EnterIDLEMode ( uint8_t PWR_IDLEEntry )
{
    /* Check the parameters */
    assert_param ( IS_PWR_IDLE_ENTRY ( PWR_IDLEEntry ) );

    /* Reset SLEEPDEEP bit of Cortex System Control Register */
    SCB->SCR &= ( uint32_t ) ~ ( ( uint32_t ) SCB_SCR_SLEEPDEEP_Msk );

    /* Select SLEEP mode entry -------------------------------------------------*/
    if ( PWR_IDLEEntry == PWR_IDLEEntry_WFI )
    {
        /* Request Wait For Interrupt */
        __WFI();
    }
    else
    {
        /* Request Wait For Event */
        __SEV();
        __WFE();
        __WFE();
    }
}

/**
  * @brief  Enters STOP mode.
  * @note   In STOP mode, all I/O pins keep the same state as in Run mode.
  * @param  PWR_STOPEntry[in]: specifies if STOP mode in entered with WFI or WFE instruction.
  *          This parameter can be one of the following values:
  *             - PWR_STOPEntry_WFI: enter STOP mode with WFI instruction
  *             - PWR_STOPEntry_WFE: enter STOP mode with WFE instruction
  * @retval None
  */
void PWR_EnterSTOPMode ( uint8_t PWR_STOPEntry )
{
    /* Check the parameters */
    assert_param ( IS_PWR_STOP_ENTRY ( PWR_STOPEntry ) );

    /* Set STOPDEEP bit of Cortex System Control Register */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    /* Select STOP mode entry -------------------------------------------------*/
    if ( PWR_STOPEntry == PWR_STOPEntry_WFI )
    {
        /* Request Wait For Interrupt */
        __WFI();
    }
    else
    {
        /* Request Wait For Event */
        __SEV();
        __WFE();
        __WFE();
    }

    /* Reset STOPDEEP bit of Cortex System Control Register */
    SCB->SCR &= ( uint32_t ) ~ ( ( uint32_t ) SCB_SCR_SLEEPDEEP_Msk );
}

/**
  * @}
  */

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
