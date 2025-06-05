/*
 ******************************************************************************
 * @file    sc32f1xxx_ledpwm.c
 * @author  SOC AE Team
 * @version V1.7
 * @date     17-10-2024
 * @brief LEDPWM function module
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
#if !defined(SC32f15xx)
#include "sc32f1xxx_ledpwm.h"

/** @defgroup LEDPWM_Exported_Functions_Group1 Configuration of the LEDPWM computation unit functions
 *  @brief   Configuration of the LEDPWM computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### LEDPWM configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitializes the LEDPWM peripheral
 * @retval None
 */
void LEDPWM_DeInit ( void )
{
    /* Enable LEDPWM reset state */
    RCC_APB2PeriphResetCmd ( RCC_APB2Periph_LEDPWM, ENABLE );
    /* Disable LEDPWM reset state */
    RCC_APB2PeriphResetCmd ( RCC_APB2Periph_LEDPWM, DISABLE );
}

/**
  * @brief  Fills each LEDPWM_InitStruct member with its default value.
  * @param  LEDPWM_InitStruct[out]:Pointer to structure LEDPWM_InitTypeDef, to be initialized.
  * @retval None
  */
void LEDPWM_StructInit ( LEDPWM_InitTypeDef* LEDPWM_InitStruct )
{
    /* Set the default configuration */
    LEDPWM_InitStruct->LEDPWM_AlignedMode = LEDPWM_AlignmentMode_Edge;
    LEDPWM_InitStruct->LEDPWM_Cycle = 0x0000;
#if defined(SC32f10xx) || defined(SC32f12xx)
    LEDPWM_InitStruct->LEDPWM_LowPolarityChannl = LEDPWMChannel_Less;
    LEDPWM_InitStruct->LEDPWM_OutputChannel = LEDPWMChannel_Less;
#elif defined(SC32f11xx)
    LEDPWM_InitStruct->LEDPWM_LowPolarityChannl0 = LEDPWMChannel_Less;
    LEDPWM_InitStruct->LEDPWM_OutputChannel0 = LEDPWMChannel_Less;

    LEDPWM_InitStruct->LEDPWM_LowPolarityChannl1 = LEDPWMChannel_Less;
    LEDPWM_InitStruct->LEDPWM_OutputChannel1 = LEDPWMChannel_Less;
#endif
    LEDPWM_InitStruct->LEDPWM_Prescaler = LEDPWM_PRESCALER_DIV1;
}

/**
 * @brief  LEDPWM initialization configuration
 * @param  LEDPWM_InitStruct[out]:Pointer to structure LEDPWM_InitTypeDef, to be initialized.
 * @retval None
 */
void LEDPWM_Init ( LEDPWM_InitTypeDef* LEDPWM_InitStruct )
{
    uint32_t tmpreg;

    /*---------------------------- LEDPWM LEDPWM_CON Configuration ------------------------*/
    /* Get the LEDPWM LEDPWM_CON value */
    tmpreg = LEDPWM->LEDPWM_CON;
    /* Clear LEDPWMCLK, LEDPWMMD0 and LEDPWMMD1 SPR bits */
    tmpreg &= ( uint32_t ) ~ ( LEDPWM_CON_PWMCLK | LEDPWM_CON_PWMMD0 );
    /* Configure LEDPWM: Prescaler, AlignedMode and WorkMode */
    /* Set LEDPWMCLK bits according to Prescaler value */
    /* Set LEDPWMMD0 bit according to AlignedMode value */
    /* Set LEDPWMMD1 bit according to WorkMode value */
    tmpreg |= ( uint32_t ) ( LEDPWM_InitStruct->LEDPWM_Prescaler | LEDPWM_InitStruct->LEDPWM_AlignedMode );

    /* Write to LEDPWM LEDPWM_CON */
    LEDPWM->LEDPWM_CON = tmpreg;
#if defined(SC32f10xx) || defined(SC32f12xx)
    /* Write to LEDPWM LEDPWM_CHN */
    LEDPWM->LEDPWM_CHN = LEDPWM_InitStruct->LEDPWM_OutputChannel;

    /* Write to LEDPWM LEDPWM_INV */
    LEDPWM->LEDPWM_INV = LEDPWM_InitStruct->LEDPWM_LowPolarityChannl;
#elif defined(SC32f11xx)
    if ( LEDPWM_InitStruct->LEDPWM_OutputChannel0 <= 0x80000000 || LEDPWM_InitStruct->LEDPWM_OutputChannel0 == 0xFFFFFFFF )
    {
        LEDPWM->LEDPWM_CHN0 = LEDPWM_InitStruct->LEDPWM_OutputChannel0;
        /* Write to LEDPWM LEDPWM_INV */
        LEDPWM->LEDPWM_INV0 = LEDPWM_InitStruct->LEDPWM_LowPolarityChannl0;
    }
    /* Write to LEDPWM LEDPWM_CYCLE */

    if ( ( LEDPWM_InitStruct->LEDPWM_OutputChannel1 & 0x0FFFFFFF ) < 0x0000004F || LEDPWM_InitStruct->LEDPWM_OutputChannel1 == 0x0000007F )
    {
        LEDPWM->LEDPWM_CHN1 = LEDPWM_InitStruct->LEDPWM_OutputChannel1 & 0x7FFFFFFF;
        LEDPWM->LEDPWM_INV1 = LEDPWM_InitStruct->LEDPWM_LowPolarityChannl1 & 0x7FFFFFFF;
    }
#endif
    /* Write to LEDPWM LEDPWM_CYCLE */
    LEDPWM->LEDPWM_CYCLE = LEDPWM_InitStruct->LEDPWM_Cycle;
}

/**
 * @brief  Enables or disables the specified LEDPWM peripheral.
 * @param  NewState[in]: new state of the LEDPWM peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void LEDPWM_Cmd ( FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the LEDPWM Counter */
        LEDPWM->LEDPWM_CON |= LEDPWM_CON_ENPWM;
    }
    else
    {
        /* Disable the LEDPWM Counter */
        LEDPWM->LEDPWM_CON &= ( uint16_t ) ~LEDPWM_CON_ENPWM;
    }
}

/**
 * @brief  Set the LEDPWM Clock Division value.
 * @param  LEDPWM_Prescaler[in]:Select the LEDPWM frequency.
 *         - LEDPWM_PRESCALER_DIV1: Clock division: Fsource/1
 *         - LEDPWM_PRESCALER_DIV2: Clock division: Fsource/2
 *         - LEDPWM_PRESCALER_DIV4: Clock division: Fsource/4
 *         - LEDPWM_PRESCALER_DIV8: Clock division: Fsource/8
 *         - LEDPWM_PRESCALER_DIV16: Clock division: Fsource/16
 *         - LEDPWM_PRESCALER_DIV32: Clock division: Fsource/32
 *         - LEDPWM_PRESCALER_DIV64:  Clock division: Fsource/64
 *         - LEDPWM_PRESCALER_DIV128: Clock division: Fsource/128
 *         - LEDPWM_PRESCALER_DIV256: Clock division: Fsource/256
 * @retval None
 */
void LEDPWM_SetPrescaler ( LEDPWM_Prescaler_TypeDef LEDPWM_Prescaler )
{
    /* Check the parameters */
    assert_param ( IS_LEDPWM_PRESCALER ( LEDPWM_Prescaler ) );

    /* Reset the CKD Bits */
    LEDPWM->LEDPWM_CON &= ( uint16_t ) ~ ( LEDPWM_CON_PWMCLK );

    /* Set the CKD value */
    LEDPWM->LEDPWM_CON |= LEDPWM_Prescaler;
}

/**
 * @brief  Gets the LEDPWM Clock Division value.
 * @retval The clock division value.
 *         - LEDPWM_PRESCALER_DIV1: Clock division: Fsource/1
 *         - LEDPWM_PRESCALER_DIV2: Clock division: Fsource/2
 *         - LEDPWM_PRESCALER_DIV4: Clock division: Fsource/4
 *         - LEDPWM_PRESCALER_DIV8: Clock division: Fsource/8
 *         - LEDPWM_PRESCALER_DIV16: Clock division: Fsource/16
 *         - LEDPWM_PRESCALER_DIV32: Clock division: Fsource/32
 *         - LEDPWM_PRESCALER_DIV64:  Clock division: Fsource/64
 *         - LEDPWM_PRESCALER_DIV128: Clock division: Fsource/128
 *         - LEDPWM_PRESCALER_DIV256: Clock division: Fsource/256
 */
LEDPWM_Prescaler_TypeDef LEDPWM_GetPrescaler ( void )
{
    /* Get the CKD value */
    return ( LEDPWM_Prescaler_TypeDef ) ( LEDPWM->LEDPWM_CON & LEDPWM_CON_PWMCLK );
}


/**
 * @brief  Sets the LEDPWM Cycle Register value
 * @param  LEDPWM_Cycle[in]: specifies the ReloadData register new value.
 * @retval None
 */
void LEDPWM_SetCycle ( uint8_t LEDPWM_Cycle )
{
    /* Set the ReloadData Register value */
    LEDPWM->LEDPWM_CYCLE = LEDPWM_Cycle;
}

/**
 * @brief  Gets the period value of LEDPWM.
 * @retval the period value of LEDPWM
 */
uint8_t LEDPWM_GetCycle()
{
    /* Get the period value of LEDPWM */
    return ( uint8_t ) LEDPWM->LEDPWM_CYCLE;
}

/**
 * @brief  Sets the LEDPWM Duty value.
 * @param  LEDPWM_Channel[in]: specifies the LEDPWM channel to check.
 *                SC32f10xx Selection range(LEDPWMChannel_Less,LEDPWM_Channel_0 - LEDPWM_Channel_31,LEDPWM_Channel_All)
 *                SC32f11xx Selection range(LEDPWMChannel_Less,LED_RAMRegister_0 - LED_RAMRegister_38,LEDPWM_Channel_32_38,LEDPWM_Channel_All)
 *                SC32f12xx Selection range(LEDPWMChannel_Less,LEDPWM_Channel_0 - LEDPWM_Channel_31,LEDPWM_Channel_All)
 *                - LEDPWMChannel_Less : No channels are selected
 *                - LEDPWM_Channel_0:PMW output channel 0
 *                - LEDPWM_Channel_1:PMW output channel 1
 *                - LEDPWM_Channel_2:PMW output channel 2
 *                - LEDPWM_Channel_3:PMW output channel 3
 *                - LEDPWM_Channel_4:PMW output channel 4
 *                - LEDPWM_Channel_5:PMW output channel 5
 *                - LEDPWM_Channel_6:PMW output channel 6
 *                - LEDPWM_Channel_7:PMW output channel 7
 *                - LEDPWM_Channel_8:PMW output channel 8
 *                - LEDPWM_Channel_9:PMW output channel 9
 *                - LEDPWM_Channel_10:PMW output channel 10
 *                - LEDPWM_Channel_11:PMW output channel 11
 *                - LEDPWM_Channel_12:PMW output channel 12
 *                - LEDPWM_Channel_13:PMW output channel 13
 *                - LEDPWM_Channel_14:PMW output channel 14
 *                - LEDPWM_Channel_15:PMW output channel 15
 *                - LEDPWM_Channel_16:PMW output channel 16
 *                - LEDPWM_Channel_17:PMW output channel 17
 *                - LEDPWM_Channel_18:PMW output channel 18
 *                - LEDPWM_Channel_19:PMW output channel 19
 *                - LEDPWM_Channel_20:PMW output channel 20
 *                - LEDPWM_Channel_21:PMW output channel 21
 *                - LEDPWM_Channel_22:PMW output channel 22
 *                - LEDPWM_Channel_23:PMW output channel 23
 *                - LEDPWM_Channel_24:PMW output channel 24
 *                - LEDPWM_Channel_25:PMW output channel 25
 *                - LEDPWM_Channel_26:PMW output channel 26
 *                - LEDPWM_Channel_27:PMW output channel 27
 *                - LEDPWM_Channel_28:PMW output channel 28
 *                - LEDPWM_Channel_29: PMW output channel 29
 *                - LEDPWM_Channel_30:PMW output channel 30
 *                - LEDPWM_Channel_31:PMW output channel 31
 *                - LEDPWM_Channel_32:PMW output channel 25
 *                - LEDPWM_Channel_33:PMW output channel 26
 *                - LEDPWM_Channel_34: PMW output channel 27
 *                - LEDPWM_Channel_35:PMW output channel 28
 *                - LEDPWM_Channel_36:PMW output channel 29
 *                - LEDPWM_Channel_37:PMW output channel 30
 *                - LEDPWM_Channel_38:PMW output channel 31
 *                - LEDPWM_Channel_32_38:PMW32_38 output channel ALL
 *                - LEDPWM_Channel_Al:PMW output channel ALL
 * @param  LEDPWM_Duty[in]: specifies the Duty register new value.
 * @retval None
 */
void LEDPWM_SetDuty ( LEDPWM_Channel_Typedef LEDPWM_Channel, uint8_t LEDPWM_Duty )
{
    uint8_t tmpvalue;
    uint32_t tmpchannel;
    /* Check the parameters */
    assert_param ( IS_LEDPWM_CHANNEL ( LEDPWM_Channel ) );
#if defined (SC32f10xx) || (SC32f12xx)
    tmpchannel = 1;
    for ( tmpvalue = 0; tmpvalue < 32; tmpvalue++ )
    {
        if ( ( uint32_t ) LEDPWM_Channel & tmpchannel )
        {
            LEDPWM->LEDPWM_DT[tmpvalue] = LEDPWM_Duty;
        }
        tmpchannel = tmpchannel << 1;
    }
#elif defined (SC32f11xx)
    if ( LEDPWM_Channel <= 0x80000000 )
    {
        for ( tmpvalue = 0; tmpvalue < 32; tmpvalue++ )
        {
            if ( ( uint32_t ) LEDPWM_Channel & tmpchannel )
            {
                LEDPWM->LEDPWM_DT[tmpvalue] = LEDPWM_Duty;
            }
            tmpchannel = tmpchannel << 1;
        }
    }
    else
    {
        for ( tmpvalue = 0; tmpvalue < 7; tmpvalue++ )
        {
            if ( ( uint32_t ) LEDPWM_Channel & tmpchannel )
            {
                LEDPWM->LEDPWM_DT[tmpvalue + 31] = LEDPWM_Duty;
            }
            tmpchannel = tmpchannel << 1;
        }
    }
#endif
}

/**
 * @brief  Gets the LEDPWM Duty value.
 * @param  LEDPWM_Channel[in]:
 *                SC32f10xx Selection range(LEDPWMChannel_Less,LEDPWM_Channel_0 - LEDPWM_Channel_31,LEDPWM_Channel_All)
 *                SC32f11xx Selection range(LEDPWMChannel_Less,LED_RAMRegister_0 - LED_RAMRegister_38,LEDPWM_Channel_32_38,LEDPWM_Channel_All)
 *                SC32f12xx Selection range(LEDPWMChannel_Less,LEDPWM_Channel_0 - LEDPWM_Channel_31,LEDPWM_Channel_All)
 *                - LEDPWMChannel_Less : No channels are selected
 *                - LEDPWM_Channel_0:PMW output channel 0
 *                - LEDPWM_Channel_1:PMW output channel 1
 *                - LEDPWM_Channel_2:PMW output channel 2
 *                - LEDPWM_Channel_3:PMW output channel 3
 *                - LEDPWM_Channel_4:PMW output channel 4
 *                - LEDPWM_Channel_5:PMW output channel 5
 *                - LEDPWM_Channel_6:PMW output channel 6
 *                - LEDPWM_Channel_7:PMW output channel 7
 *                - LEDPWM_Channel_8:PMW output channel 8
 *                - LEDPWM_Channel_9:PMW output channel 9
 *                - LEDPWM_Channel_10:PMW output channel 10
 *                - LEDPWM_Channel_11:PMW output channel 11
 *                - LEDPWM_Channel_12:PMW output channel 12
 *                - LEDPWM_Channel_13:PMW output channel 13
 *                - LEDPWM_Channel_14:PMW output channel 14
 *                - LEDPWM_Channel_15:PMW output channel 15
 *                - LEDPWM_Channel_16:PMW output channel 16
 *                - LEDPWM_Channel_17:PMW output channel 17
 *                - LEDPWM_Channel_18:PMW output channel 18
 *                - LEDPWM_Channel_19:PMW output channel 19
 *                - LEDPWM_Channel_20:PMW output channel 20
 *                - LEDPWM_Channel_21:PMW output channel 21
 *                - LEDPWM_Channel_22:PMW output channel 22
 *                - LEDPWM_Channel_23:PMW output channel 23
 *                - LEDPWM_Channel_24:PMW output channel 24
 *                - LEDPWM_Channel_25:PMW output channel 25
 *                - LEDPWM_Channel_26:PMW output channel 26
 *                - LEDPWM_Channel_27:PMW output channel 27
 *                - LEDPWM_Channel_28:PMW output channel 28
 *                - LEDPWM_Channel_29:PMW output channel 29
 *                - LEDPWM_Channel_30:PMW output channel 30
 *                - LEDPWM_Channel_31:PMW output channel 31
 *                - LEDPWM_Channel_32:PMW output channel 25
 *                - LEDPWM_Channel_33:PMW output channel 26
 *                - LEDPWM_Channel_34:PMW output channel 27
 *                - LEDPWM_Channel_35:PMW output channel 28
 *                - LEDPWM_Channel_36:PMW output channel 29
 *                - LEDPWM_Channel_37:PMW output channel 30
 *                - LEDPWM_Channel_38:PMW output channel 31
 *                - LEDPWM_Channel_32_38:PMW32_38 output channel ALL
 *                - LEDPWM_Channel_Al:PMW output channel ALL
 * @retval the Duty register new value.
 */
uint8_t LEDPWM_GetDuty ( LEDPWM_Channel_Typedef LEDPWM_Channel )
{
    uint8_t tmpvalue ;
    uint32_t tmpchannel;
    /* Check the parameters */
    assert_param ( IS_LEDPWM_CHANNEL ( LEDPWM_Channel ) );

    tmpchannel = 1;
#if defined (SC32f10xx) || (SC32f12xx)
    for ( tmpvalue = 0; tmpvalue < 32; tmpvalue++ )
    {
        if ( ( uint32_t ) LEDPWM_Channel & tmpchannel )
        {
            return ( uint16_t ) ( LEDPWM->LEDPWM_DT[tmpvalue] );
        }
        tmpchannel = tmpchannel << 1;
    }
#elif defined (SC32f11xx)
    if ( LEDPWM_Channel <= 0x80000000 )
    {
        for ( tmpvalue = 0; tmpvalue < 32; tmpvalue++ )
        {
            if ( ( uint32_t ) LEDPWM_Channel & tmpchannel )
            {
                return ( uint16_t ) ( LEDPWM->LEDPWM_DT[tmpvalue] );
            }
            tmpchannel = tmpchannel << 1;
        }
    }
    else
    {
        for ( tmpvalue = 0; tmpvalue < 32; tmpvalue++ )
        {
            if ( ( uint32_t ) LEDPWM_Channel & tmpchannel )
            {
                return ( uint16_t ) ( LEDPWM->LEDPWM_DT[tmpvalue] );
            }
            tmpchannel = tmpchannel << 1;
        }
        for ( tmpvalue = 0; tmpvalue < 7; tmpvalue++ )
        {
            if ( ( uint32_t ) LEDPWM_Channel & tmpchannel )
            {
                return ( uint16_t ) ( LEDPWM->LEDPWM_DT[tmpvalue + 31] );
            }
            tmpchannel = tmpchannel << 1;
        }
    }
#endif
    return 0;
}

/**
 * @}
 */
/* End of LEDPWM_Group1.	*/

/** @defgroup LEDPWM_Group2 Interrupts and flags management functions
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
 * @brief  Enables or disables the specified LEDPWM interrupts.
 * @param  LEDPWM_IT[in]: specifies the LEDPWM interrupts sources to be enabled or disabled.
 *                  -  LEDPWM_IT_INTEN :LEDPWM Interrupt: LEDPWM Interrupt
 * @param  NewState[in]: new state of the LEDPWM interrupts.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void LEDPWM_ITConfig ( uint16_t LEDPWM_IT, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_LEDPWM_IT ( LEDPWM_IT ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the Interrupt sources */
        LEDPWM->LEDPWM_CON |= LEDPWM_IT;
    }
    else
    {
        /* Disable the Interrupt sources */
        LEDPWM->LEDPWM_CON &= ( uint16_t ) ~LEDPWM_IT;
    }
}

/**
 * @brief  Checks whether the specified LEDPWM flag is set or not.
 * @param  LEDPWM_FLAG[in]:specifies the flag to check.
 *                  - LEDPWM_Flag_LEDPWMIF :LEDPWM Interrupt: LEDPWM Interrupt
 * @retval The new state of LEDPWM_FLAG (SET or RESET).
 *                  -  RESET:Flag reset
 *                  -  SET :Flag up
 */
FlagStatus LEDPWM_GetFlagStatus ( uint16_t LEDPWM_FLAG )
{
    ITStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param ( IS_LEDPWM_FLAG ( LEDPWM_FLAG ) );

    if ( ( LEDPWM->LEDPWM_STS & LEDPWM_FLAG ) != ( uint16_t ) RESET )
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
 * @brief  Clears the LEDPWM's pending flags.
 * @param  LEDPWM_FLAG[in]:specifies the flag bit to clear.
 *                  - LEDPWM_Flag_LEDPWMIF :LEDPWM Interrupt: LEDPWM Interrupt
 * @retval None
 */
void LEDPWM_ClearFlag ( uint16_t LEDPWM_FLAG )
{
    /* Check the parameters */
    assert_param ( IS_GET_LEDPWM_FLAG ( LEDPWM_FLAG ) );

    /* Clear the flags */
    LEDPWM->LEDPWM_STS = ( uint16_t ) LEDPWM_FLAG;
}

/**
 * @}
 */
/* End of LEDPWM_Group2.	*/
#endif
/**
 * @}
 */
/* End of functions ---------------------------------------------------------*/

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT SOC Microelectronics *****END OF FILE****/
