/*
 ******************************************************************************
 * @file    sc32f1xxx_int.c
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief INT function module
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
#include "sc32f1xxx_int.h"

/** @defgroup INT_Group1 Configuration of the INT computation unit functions
 *  @brief   Configuration of the INT computation unit functions
 *
@endverbatim
 ===============================================================================
                     ##### INT configuration functions #####
 ===============================================================================
@endendverbatim
  * @{
  */

/**
 * @brief  DeInitializes the INT peripheral,
 * @retval None
 */
void INT_DeInit ( void )
{
    INT->INTF_IE  = ( uint16_t ) 0x00000000U;
    INT->INTR_IE  = ( uint16_t ) 0x00000000U;
    INT->INT_SEL0 = ( uint16_t ) 0x00000000U;
    INT->INT_SEL1 = ( uint16_t ) 0x00000000U;
    INT->INTF_CON = ( uint16_t ) 0x00000000U;
    INT->INTR_CON = ( uint16_t ) 0x00000000U;
    INT->INTF_STS = ( uint16_t ) 0x00000000U;
    INT->INTR_STS = ( uint16_t ) 0x00000000U;
}

/**
  * @brief  Initializes the INT peripheral according to the specified
  *         parameters in the INT_InitStruct.
  * @param  INT_InitStruct[out]: Pointer to structure INT_InitTypeDef, to be initialized.
  * @retval None
  */
void INT_Init ( INT_InitTypeDef* INT_InitStruct )
{
    uint32_t tmppin, tmppos, tmpreg;
    /* Check the parameters */
    assert_param ( IS_INT_CHANNEL ( INT_InitStruct->INT_Channel ) );
    assert_param ( IS_INT_TRIGGER ( INT_InitStruct->INT_Trigger ) );
    assert_param ( IS_INT_INTSEL ( INT_InitStruct->INT_INTSEL ) );

    if ( ( INT_InitStruct->INT_Trigger & INT_Trigger_Rising ) != INT_Trigger_Null )
    {
        /* Set Rising edge configuration */
        INT->INTR_CON |= ( uint32_t ) INT_InitStruct->INT_Channel;
    }
    else
    {
        /* Clear Rising edge configuration */
        INT->INTR_CON &= ( uint32_t ) ( ~INT_InitStruct->INT_Channel );
    }

    if ( ( INT_InitStruct->INT_Trigger & INT_Trigger_Falling ) != INT_Trigger_Null )
    {
        /* Set Falling edge configuration */
        INT->INTF_CON |= ( uint32_t ) INT_InitStruct->INT_Channel;
    }
    else
    {
        /* Clear Falling edge configuration */
        INT->INTF_CON &= ( uint32_t ) ( ~INT_InitStruct->INT_Channel );
    }

    /* Get GPIOx PXLEV value */
    tmpreg = INT->INT_SEL0;
    /* Query the Pins that needs to be manipulated */
    for ( tmppos = 0; tmppos < 8; tmppos++ )
    {
        tmppin = ( uint32_t ) ( 0x01 << tmppos );
        if ( ( tmppin & INT_InitStruct->INT_Channel ) != RESET )
        {
            /* Clear the LEVx bits */
            tmpreg &= ( uint32_t ) ~ ( 0x0F << ( tmppos * 4 ) );
            /* Set LEVx bits according to Drive Level value */
            tmpreg |= ( uint32_t ) ( INT_InitStruct->INT_INTSEL << ( tmppos * 4 ) );
        }
    }
    /* Store GPIOx INT_SEL0 the new value */
    INT->INT_SEL0 = tmpreg;

    /* Get GPIOx INT_SEL1 value */
    tmpreg = INT->INT_SEL1;
    /* Query the Pins that needs to be manipulated */
    for ( ; tmppos < 16; tmppos++ )
    {
        tmppin = ( uint32_t ) ( 0x01 << tmppos );
        if ( ( tmppin & INT_InitStruct->INT_Channel ) != RESET )
        {
            /* Clear the INT_SEL1 bits */
            tmpreg &= ( uint32_t ) ~ ( 0x0F << ( ( tmppos - 8 ) * 4 ) );
            /* Set INT_SEL1 bits according to Drive Level value */
            tmpreg |= ( uint32_t ) ( INT_InitStruct->INT_INTSEL << ( ( tmppos - 8 ) * 4 ) );
        }
    }
    /* Store GPIOx INT_SEL1 the new value */
    INT->INT_SEL1 = tmpreg;
}


/**
 * @brief  INT Trigger Mode Select
 * @param  INT_Channel[in]:INTx channel selection.
 *                   - INT_Channel_0:Int Select: Px0
 *                   - INT_Channel_1:Int Select: Px1
 *                   - INT_Channel_2:Int Select: Px2
 *                   - INT_Channel_3:Int Select: Px3
 *                   - INT_Channel_4:Int Select: Px4
 *                   - INT_Channel_5:Int Select: Px5
 *                   - INT_Channel_6:Int Select: Px6
 *                   - INT_Channel_7:Int Select: Px7
 *                   - INT_Channel_8:Int Select: Px8
 *                   - INT_Channel_9:Int Select: Px9
 *                   - INT_Channel_10:Int Select: Px10
 *                   - INT_Channel_11:Int Select: Px11
 *                   - INT_Channel_12:Int Select: Px12
 *                   - INT_Channel_13:Int Select: Px13
 *                   - INT_Channel_14:Int Select: Px14
 *                   - INT_Channel_15:Int Select: Px15
 * @param  INT_IT[in]: Select triggering mode.
 *                   - INT_Trigger_Null:INT Interrupt: Null
 *                   - INT_Trigger_Rising: Rising edge capture
 *                   - INT_Trigger_Falling: Falling edge capture
 *                   - INT_Trigger_Rising_Falling: Rising and Falling edge capture
 * @retval None
 */
void INT_TriggerMode ( INT_Channel_Typedef INT_Channel, INT_Trigger_TypeDef Trigger_Mode )
{
    if ( ( Trigger_Mode & INT_Trigger_Rising ) != INT_Trigger_Null )
    {
        /* Set Rising edge configuration */
        INT->INTR_CON |= ( uint32_t ) INT_Channel;
    }
    else
    {
        /* Clear Rising edge configuration */
        INT->INTR_CON &= ( uint32_t ) ( ~INT_Channel );
    }

    if ( ( Trigger_Mode & INT_Trigger_Falling ) != INT_Trigger_Null )
    {
        /* Set Falling edge configuration */
        INT->INTF_CON |= ( uint32_t ) INT_Channel;
    }
    else
    {
        /* Clear Falling edge configuration */
        INT->INTF_CON &= ( uint32_t ) ( ~INT_Channel );
    }

}
/**
 * @}
 */
/* End of INT_Group1.	*/

/** @defgroup INT_Group2 Interrupts and flags management functions
 *  @brief   PWM management functions
 *
@endverbatim
 ===============================================================================
                     ##### Interrupts and flags management functions #####
 ===============================================================================
@endendverbatim
  * @{
  */

/**
 * @brief  INT Indicates whether to enable or disable interrupts
 * @param  INT_Channel[in]:INTx channel selection.
 *                   - INT_Channel_0:Int Select: Px0
 *                   - INT_Channel_1:Int Select: Px1
 *                   - INT_Channel_2:Int Select: Px2
 *                   - INT_Channel_3:Int Select: Px3
 *                   - INT_Channel_4:Int Select: Px4
 *                   - INT_Channel_5:Int Select: Px5
 *                   - INT_Channel_6:Int Select: Px6
 *                   - INT_Channel_7:Int Select: Px7
 *                   - INT_Channel_8:Int Select: Px8
 *                   - INT_Channel_9:Int Select: Px9
 *                   - INT_Channel_10:Int Select: Px10
 *                   - INT_Channel_11:Int Select: Px11
 *                   - INT_Channel_12:Int Select: Px12
 *                   - INT_Channel_13:Int Select: Px13
 *                   - INT_Channel_14:Int Select: Px14
 *                   - INT_Channel_15:Int Select: Px15
 * @param  INT_IT[in]: Select an interrupt triggering mode.
 *                   - INT_Trigger_Null:INT Interrupt: Null
 *                   - INT_Trigger_Rising:INT Interrupt: Rising edge capture
 *                   - INT_Trigger_Falling:INT Interrupt: Falling edge capture
 *                   - INT_Trigger_Rising_Falling:INT Interrupt: Rising and Falling edge capture
 * @param  NewState[in]: INT Indicates whether the interrupt is enabled or disabled.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void INT_ITConfig ( uint16_t INT_Channel, uint16_t INT_IT, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_INT_CHANNEL ( INT_Channel ) );
    assert_param ( IS_INT_TRIGGER ( INT_IT ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    /* Configure INTR_IE Register */
    if ( INT_IT & INT_Trigger_Rising )
    {
        if ( NewState == ENABLE )
        {
            INT->INTR_IE |= INT_Channel;
        }
        else
        {
            INT->INTR_IE &= ( uint16_t ) ( ~INT_Channel );
        }
    }

    /* Configure INTF_IE Register */
    if ( INT_IT & INT_Trigger_Falling )
    {
        if ( NewState == ENABLE )
        {
            INT->INTF_IE |= INT_Channel;
        }
        else
        {
            INT->INTF_IE &= ( uint16_t ) ( ~INT_Channel );
        }
    }
}

/**
 * @brief  Checks whether the specified INT flag is set or not.
 * @param  INT_Channel[in]: INTx channel selection.
 *                   - INT_Channel_0:Int Select: Px0
 *                   - INT_Channel_1:Int Select: Px1
 *                   - INT_Channel_2:Int Select: Px2
 *                   - INT_Channel_3:Int Select: Px3
 *                   - INT_Channel_4:Int Select: Px4
 *                   - INT_Channel_5:Int Select: Px5
 *                   - INT_Channel_6:Int Select: Px6
 *                   - INT_Channel_7:Int Select: Px7
 *                   - INT_Channel_8:Int Select: Px8
 *                   - INT_Channel_9:Int Select: Px9
 *                   - INT_Channel_10:Int Select: Px10
 *                   - INT_Channel_11:Int Select: Px11
 *                   - INT_Channel_12:Int Select: Px12
 *                   - INT_Channel_13:Int Select: Px13
 *                   - INT_Channel_14:Int Select: Px14
 *                   - INT_Channel_15:Int Select: Px15
 * @param  INT_Flag[in]: specifies the flag to check.
 *                   - INT_Flag_Rising:INT Flag: INT overflow
 *                   - INT_Flag_Falling:INT Flag: Immediate mode
 * @retval The new state of INT_Flag (SET or RESET).
 *                  -  RESET:Flag reset
 *                  -  SET :Flag up
 */
FlagStatus INT_GetFlagStatus ( INT_Channel_Typedef INT_Channel, INT_Flag_TypeDef INT_Flag )
{
    FlagStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param ( IS_INT_CHANNEL ( INT_Channel ) );
    assert_param ( IS_INT_FLAG ( INT_Flag ) );

    /* Get INTR_IE Register */
    if ( INT_Flag & INT_Flag_Rising )
    {
        if ( ( INT->INTR_STS & INT_Channel ) != ( uint16_t ) RESET )
        {
            bitstatus = SET;
        }
        else
        {
            bitstatus = RESET;
        }
    }
    else
    {
        if ( ( INT->INTF_STS & INT_Channel ) != ( uint16_t ) RESET )
        {
            bitstatus = SET;
        }
        else
        {
            bitstatus = RESET;
        }
    }
    return bitstatus;
}

/**
 * @brief  Clears the INTx's pending flags.
 * @param  INT_Channel[in]: INTx channel selection.
 *                   - INT_Channel_0:Int Select: Px0
 *                   - INT_Channel_1:Int Select: Px1
 *                   - INT_Channel_2:Int Select: Px2
 *                   - INT_Channel_3:Int Select: Px3
 *                   - INT_Channel_4:Int Select: Px4
 *                   - INT_Channel_5:Int Select: Px5
 *                   - INT_Channel_6:Int Select: Px6
 *                   - INT_Channel_7:Int Select: Px7
 *                   - INT_Channel_8:Int Select: Px8
 *                   - INT_Channel_9:Int Select: Px9
 *                   - INT_Channel_10:Int Select: Px10
 *                   - INT_Channel_11:Int Select: Px11
 *                   - INT_Channel_12:Int Select: Px12
 *                   - INT_Channel_13:Int Select: Px13
 *                   - INT_Channel_14:Int Select: Px14
 *                   - INT_Channel_15:Int Select: Px15
 * @note   INT6 and INT7 can have only one update flag.
 * @note   INT_Flag_COM and INT_Flag_Break are used only with INT1 and INT8.
 *
 * @retval None
 */
void INT_ClearFlag ( uint32_t INT_Channel )
{
    /* Check the parameters */
    assert_param ( IS_INT_CHANNEL ( INT_Channel ) );

    /* Clear INTR_STS and INTF_STS Register */
    INT->INTR_STS &= ( uint16_t ) ( ~INT_Channel );
    INT->INTF_STS &= ( uint16_t ) ( ~INT_Channel );
}

/**
 * @}
 */
/* End of INT_Group2.	*/

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
