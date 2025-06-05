/*
 ******************************************************************************
 * @file    SC32f1xxx_pwm.c
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief PWM function module
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#if !defined(SC32f15xx)
#include "sc32f1xxx_pwm.h"

/** @defgroup PWM_Exported_Functions_Group1 Configuration of the PWM computation unit functions
 *  @brief   Configuration of the PWM computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### PWM configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitializes the PWM peripheral
 * @param  PWMx[out]: where x can be to select the PWMx peripheral.
 *             - PWM0:Select PWM0
 * @retval None
 */
void PWM_DeInit ( PWM_TypeDef* PWMx )
{
    /* Check the parameters */
    assert_param ( IS_PWM_ALL_PERIPH ( PWMx ) );

    if ( PWMx == PWM0 )
    {
        /* Enable PWM reset state */
        RCC_APB0PeriphResetCmd ( RCC_APB0Periph_PWM0, ENABLE );
        /* Enable PWM reset state */
        RCC_APB0PeriphResetCmd ( RCC_APB0Periph_PWM0, DISABLE );
    }
}

/**
  * @brief  Fills each PWM_InitStruct member with its default value.
  * @param  PWM_InitStruct[out]:Pointer to structure PWM_InitTypeDef, to be initialized.
  * @retval None
  */
void PWM_StructInit ( PWM_InitTypeDef* PWM_InitStruct )
{
    /* Set the default configuration */
    PWM_InitStruct->PWM_AlignedMode = PWM_AlignmentMode_Edge;
    PWM_InitStruct->PWM_Cycle = 0x0000;
    PWM_InitStruct->PWM_LowPolarityChannl = PWMChannel_Less;
    PWM_InitStruct->PWM_OutputChannel = PWMChannel_Less;
    PWM_InitStruct->PWM_Prescaler = PWM_PRESCALER_DIV1;
    PWM_InitStruct->PWM_WorkMode = PWM_WorkMode_Independent;
}

/**
  * @brief  Initializes the PWMx peripheral according to
  *         the specified parameters in the PWM_Base_InitStruct.
 * @param  PWMx[out]: where x can be to select the PWMx peripheral.
 *             - PWM:Select PWM
 * @param  PWM_InitStruct[out]:Pointer to structure PWM_InitTypeDef, to be initialized.
 * @retval None
 */
void PWM_Init ( PWM_TypeDef* PWMx, PWM_InitTypeDef* PWM_InitStruct )
{
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_PWM_COMPLEMENTARY_PERIPH ( PWMx ) );

    /*---------------------------- PWMx PWM_CON Configuration ------------------------*/
    /* Get the PWMx PWM_CON value */
    tmpreg = PWMx->PWM_CON;
    /* Clear PWMCLK, PWMMD0 and PWMMD1 SPR bits */
    tmpreg &= ( uint32_t ) ~ ( PWM_CON_PWMCLK | PWM_CON_PWMMD0 | PWM_CON_PWMMD1 );
    /* Configure PWMx: Prescaler, AlignedMode and WorkMode */
    /* Set PWMCLK bits according to Prescaler value */
    /* Set PWMMD0 bit according to AlignedMode value */
    /* Set PWMMD1 bit according to WorkMode value */
    tmpreg |= ( uint32_t ) ( PWM_InitStruct->PWM_Prescaler | PWM_InitStruct->PWM_AlignedMode |
                             PWM_InitStruct->PWM_WorkMode );

    /* Write to PWMx PWM_CON */
    PWMx->PWM_CON = tmpreg;

    /* Write to PWMx PWM_CHN */
    PWMx->PWM_CHN = PWM_InitStruct->PWM_OutputChannel;

    /* Write to PWMx PWM_INV */
    PWMx->PWM_INV = PWM_InitStruct->PWM_LowPolarityChannl;

    /* Write to PWMx PWM_CYCLE */
    PWMx->PWM_CYCLE = PWM_InitStruct->PWM_Cycle;
}


/**
 * @brief  Configures the PWMx Rising Dead Time Register value
 * @param  PWMx[out]: where x can be to select the PWMx peripheral.
 *             - PWM0:Select PWM0
 * @param  PWM_RisingDeadTime[in]: specifies the Rising Dead Time register new value.
 * @retval None.
 */
void PWM_RisingDeadTimeConfig ( PWM_TypeDef* PWMx, uint8_t PWM_RisingDeadTime )
{
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_PWM_COMPLEMENTARY_PERIPH ( PWMx ) );

    /* Get the PWMx PWM_DFR value */
    tmpreg = PWMx->PWM_DFR;

    /* Clear PDR bits */
    tmpreg &= ( uint32_t ) ~ ( PWM_DFR_PDR );

    /* Set PDR bits to Rising Dead Time value */
    tmpreg |= ( uint32_t ) ( PWM_RisingDeadTime << PWM_DFR_PDR_Pos );

    /* Write to PWMx PWM_DFR */
    PWMx->PWM_DFR = tmpreg;
}

/**
 * @brief  Configures the PWMx Dead Falling Time Register value
 * @param  PWMx[out]: where x can be to select the PWMx peripheral.
 *             - PWM0:Select PWM0
 * @param  PWM_fallingDeadTime[in]: specifies the Falling Dead Time register new value.
 * @retval None.
 */
void PWM_FallingDeadTimeConfig ( PWM_TypeDef* PWMx, uint8_t PWM_FallingDeadTime )
{
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_PWM_ALL_PERIPH ( PWMx ) );

    /* Get the PWMx PWM_DFR value */
    tmpreg = PWMx->PWM_DFR;

    /* Clear PDF bits */
    tmpreg &= ( uint32_t ) ~ ( PWM_DFR_PDF );

    /* Set PDF bits to Rising Dead Time value */
    tmpreg |= ( uint32_t ) ( PWM_FallingDeadTime << PWM_DFR_PDF_Pos );

    /* Write to PWMx PWM_DFR */
    PWMx->PWM_DFR = tmpreg;
}

/**
 * @brief  Enables or disables the specified PWM peripheral.
 * @param  PWMx[out]: where x can be to select the PWMx peripheral.
 *             - PWM0:Select PWM0
 * @param  NewState[in]:new state of the PWMx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void PWM_Cmd ( PWM_TypeDef* PWMx, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_PWM_ALL_PERIPH ( PWMx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the PWM Counter */
        PWMx->PWM_CON |= PWM_CON_ENPWM;
    }
    else
    {
        /* Disable the PWM Counter */
        PWMx->PWM_CON &= ( uint16_t ) ~PWM_CON_ENPWM;
    }
}

/**
 * @brief  Sets the PWMx Clock Division value.
 * @param  PWMx[out]: where x can be to select the PWMx peripheral.
 *             - PWM0:Select PWM0
 * @param  PWM_Prescaler[in]:
 *             - PWM_PRESCALER_DIV1:Clock division: Fsource/1
 *             - PWM_PRESCALER_DIV2: Clock division: Fsource/2
 *             - PWM_PRESCALER_DIV4: Clock division: Fsource/4
 *             - PWM_PRESCALER_DIV8: Clock division: Fsource/8
 *             - PWM_PRESCALER_DIV16: Clock division: Fsource/16
 *             - PWM_PRESCALER_DIV32: Clock division: Fsource/32
 *             - PWM_PRESCALER_DIV64: Clock division: Fsource/64
 *             - PWM_PRESCALER_DIV128: Clock division: Fsource/128
 * @retval None
 */
void PWM_SetPrescaler ( PWM_TypeDef* PWMx, PWM_Prescaler_TypeDef PWM_Prescaler )
{
    /* Check the parameters */
    assert_param ( IS_PWM_ALL_PERIPH ( PWMx ) );
    assert_param ( IS_PWM_PRESCALER ( PWM_Prescaler ) );

    /* Reset the CKD Bits */
    PWMx->PWM_CON &= ( uint16_t ) ~ ( PWM_CON_PWMCLK );

    /* Set the CKD value */
    PWMx->PWM_CON |= PWM_Prescaler;
}

/**
 * @brief  Gets the PWMx Clock Division value.
 * @param  PWMx[out]: where x can be to select the PWMx peripheral.
 *             - PWM0:Select PWM0
 * @retval The clock division value.
 *             - PWM_PRESCALER_DIV1:Clock division: Fsource/1
 *             - PWM_PRESCALER_DIV2: Clock division: Fsource/2
 *             - PWM_PRESCALER_DIV4: Clock division: Fsource/4
 *             - PWM_PRESCALER_DIV8: Clock division: Fsource/8
 *             - PWM_PRESCALER_DIV16: Clock division: Fsource/16
 *             - PWM_PRESCALER_DIV32: Clock division: Fsource/32
 *             - PWM_PRESCALER_DIV64: Clock division: Fsource/64
 *             - PWM_PRESCALER_DIV128: Clock division: Fsource/128
 */
PWM_Prescaler_TypeDef PWM_GetPrescaler ( PWM_TypeDef* PWMx )
{
    /* Check the parameters */
    assert_param ( IS_PWM_ALL_PERIPH ( PWMx ) );

    /* Get the CKD value */
    return ( PWM_Prescaler_TypeDef ) ( PWMx->PWM_CON & PWM_CON_PWMCLK );
}


/**
 * @brief  Sets the PWMx Cycle Register value
 * @param  PWMx[out]: where x can be to select the PWMx peripheral.
 *             - PWM0:Select PWM0
 * @param  PWM_Cycle[in]: specifies the ReloadData register new value.
 * @retval None
 */
void PWM_SetCycle ( PWM_TypeDef* PWMx, uint32_t PWM_Cycle )
{
    /* Check the parameters */
    assert_param ( IS_PWM_ALL_PERIPH ( PWMx ) );

    /* Set the ReloadData Register value */
    PWMx->PWM_CYCLE = PWM_Cycle;
}

/**
 * @brief  Gets the PWMx Cycle Register value.
 * @param  PWMx[out]: where x can be to select the PWMx peripheral.
 *             - PWM0:Select PWM0
 * @retval Period value of PWM
 */
uint16_t PWM_GetCycle ( PWM_TypeDef* PWMx )
{
    /* Check the parameters */
    assert_param ( IS_PWM_ALL_PERIPH ( PWMx ) );

    /* Get the ReloadData Register value */
    return ( uint16_t ) PWMx->PWM_CYCLE;
}

/**
 * @brief  Sets the PWMx Duty value.
 * @param  PWMx[out]: where x can be to select the PWMx peripheral.
 *             - PWM0:Select PWM0
 * @param  PWM_Channel[in]:specifies the PWM channel to check.
 *             - PWMChannel_Less:No channels are selected
 *             - PWM_Channel_0:PMW output channel 0
 *             - PWM_Channel_1:PMW output channel 1
 *             - PWM_Channel_2:PMW output channel 2
 *             - PWM_Channel_3:PMW output channel 3
 *             - PWM_Channel_4:PMW output channel 4
 *             - PWM_Channel_5:PMW output channel 5
 *             - PWM_Channel_6:PMW output channel 6
 *             - PWM_Channel_7:PMW output channel 7
 *             - PWM_Channel_All:PMW output channel ALL
 * @param  PWM_Duty[in]: specifies the Duty register new value.
 * @retval None
 */
void PWM_SetDuty ( PWM_TypeDef* PWMx, PWM_Channel_Typedef PWM_Channel, uint16_t PWM_Duty )
{
    uint8_t tmpvalue;
    uint32_t tmpchannel;
    /* Check the parameters */
    assert_param ( IS_PWM_ALL_PERIPH ( PWMx ) );
    assert_param ( IS_PWM_CHANNEL ( PWM_Channel ) );

    tmpchannel = 1;
    for ( tmpvalue = 0; tmpvalue < 8; tmpvalue++ )
    {
        if ( ( uint32_t ) PWM_Channel & tmpchannel )
        {
            PWMx->PWM_DT[tmpvalue] = PWM_Duty;
        }
        tmpchannel = tmpchannel << 1;
    }
}

/**
 * @brief  Gets the PWMx Duty value.
 * @param  PWMx[out]: where x can be to select the PWMx peripheral.
 *             - PWM0:Select PWM0
 * @param  PWM_Channel[in]:specifies the PWM channel to check.
 *             - PWMChannel_Less:No channels are selected
 *             - PWM_Channel_0:PMW output channel 0
 *             - PWM_Channel_1:PMW output channel 1
 *             - PWM_Channel_2:PMW output channel 2
 *             - PWM_Channel_3:PMW output channel 3
 *             - PWM_Channel_4:PMW output channel 4
 *             - PWM_Channel_5:PMW output channel 5
 *             - PWM_Channel_6:PMW output channel 6
 *             - PWM_Channel_7:PMW output channel 7
 *             - PWM_Channel_All:PMW output channel ALL
 * @retval the Duty register new value.
 */
uint16_t PWM_GetDuty ( PWM_TypeDef* PWMx, PWM_Channel_Typedef PWM_Channel )
{
    uint8_t tmpvalue ;
    uint32_t tmpchannel;
    /* Check the parameters */
    assert_param ( IS_PWM_ALL_PERIPH ( PWMx ) );
    assert_param ( IS_PWM_CHANNEL ( PWM_Channel ) );

    tmpchannel = 1;
    for ( tmpvalue = 0; tmpvalue < 8; tmpvalue++ )
    {
        if ( ( uint32_t ) PWM_Channel & tmpchannel )
        {
            return ( uint16_t ) ( PWMx->PWM_DT[tmpvalue] );
        }
        tmpchannel = tmpchannel << 1;
    }
    return 0;
}

/**
 * @}
 */
/* End of PWM_Group1.	*/



/** @defgroup PWM_Group2 Fault Dectection management functions
 *  @brief   Fault Dectection management functions
 *
@verbatim
 ===============================================================================
                     ##### PWM Falut Dectection management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
  * @brief  Fill each parameter in PWM_FDInitStruct with its default value.
  * @param  PWM_FDInitStruct[out]:Pointer to structure PWM_FDInitTypeDef, to be initialized.
  * @retval None
  */
void PWM_FDStructInit ( PWM_FDInitTypeDef* PWM_FDInitStruct )
{
    /* Set the default configuration */
    PWM_FDInitStruct->PWM_FDFilteringTime = PWM_FilteringTime_0us;
    PWM_FDInitStruct->PWM_FDMode = PWM_FDMode_Latch;
    PWM_FDInitStruct->PWM_FDVoltage = PWM_FDVoltage_Low;
}

/**
 * @brief  Set PWM fault detection mode.
 * @param  PWMx[out]: where x can be to select the PWMx peripheral.
 *             - PWM0:Select PWM0
 * @param  PWM_FDInitStruct[out]:Pointer to structure PWM_FDInitTypeDef, to be initialized.
 * @retval None
 */
void PWM_FDInit ( PWM_TypeDef* PWMx, PWM_FDInitTypeDef* PWM_FDInitStruct )
{
    assert_param ( IS_PWM_ALL_PERIPH ( PWMx ) );

    PWMx->PWM_FLT &= ( uint32_t ) ~ ( PWM_FLT_FLTDT | PWM_FLT_FLTTV | PWM_FLT_FLTMD );
    PWMx->PWM_FLT |= ( uint32_t ) ( PWM_FDInitStruct->PWM_FDFilteringTime | PWM_FDInitStruct->PWM_FDMode |
                                    PWM_FDInitStruct->PWM_FDVoltage );
}

/**
 * @brief  The PWM fault detection function is enabled or disabled.
 * @param  PWMx[out]: where x can be to select the PWMx peripheral.
 *             - PWM0:Select PWM0
 * @param  NewState[in]:new state of the PWMx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void PWM_FDCmd ( PWM_TypeDef* PWMx, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_PWM_ALL_PERIPH ( PWMx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the PWM Fault Dectection */
        PWMx->PWM_FLT |= PWM_FLT_FLTEN;
    }
    else
    {
        /* Disable the PWM Fault Dectection */
        PWMx->PWM_FLT &= ( uint16_t ) ~PWM_FLT_FLTEN;
    }
}
/**
 * @}
 */
/* End of PWM_Group2.	*/

/** @defgroup PWM_Group3 Interrupts and flags management functions
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
 * @brief  Enables or disables the specified PWM interrupts.
 * @param  PWMx[out]: where x can be to select the PWMx peripheral.
 *             - PWM0:Select PWM0
 * @param  PWM_IT[in]:specifies the PWM interrupts sources to be enabled or disabled.
 *             - PWM_IT_INTEN:PWM Interrupt: PWM Interrupt
 * @param  NewState[in]:new state of the PWM interrupts.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void PWM_ITConfig ( PWM_TypeDef* PWMx, uint16_t PWM_IT, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_PWM_ALL_PERIPH ( PWMx ) );
    assert_param ( IS_PWM_IT ( PWM_IT ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the Interrupt sources */
        PWMx->PWM_CON |= PWM_IT;
    }
    else
    {
        /* Disable the Interrupt sources */
        PWMx->PWM_CON &= ( uint16_t ) ~PWM_IT;
    }
}

/**
 * @brief  Checks whether the specified PWM flag is set or not.
 * @param  PWMx[out]: where x can be to select the PWMx peripheral.
 *             - PWM0:Select PWM0
 * @param  PWM_FLAG[in]: specifies the flag to check.
 *             - PWM_Flag_PWMIF:PWM Interrupt: PWM Interrupt
 *             - PWM_Flag_FLTSTA:PWM Interrupt: Flult Interrupt
 * @retval The new state of PWM_FLAG (SET or RESET).

 */
FlagStatus PWM_GetFlagStatus ( PWM_TypeDef* PWMx, uint16_t PWM_FLAG )
{
    ITStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param ( IS_PWM_ALL_PERIPH ( PWMx ) );
    assert_param ( IS_PWM_FLAG ( PWM_FLAG ) );

    if ( ( PWMx->PWM_STS & PWM_FLAG ) != ( uint16_t ) RESET )
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
 * @brief  Clears the PWMx's pending flags.
 * @param  PWMx[out]: where x can be to select the PWMx peripheral.
 *             - PWM0:Select PWM0
 * @param  PWM_FLAG[in]:specifies the flag bit to clear.
 *             - PWM_Flag_PWMIF:PWM Interrupt: PWM Interrupt
 *             - PWM_Flag_FLTSTA:PWM Interrupt: Flult Interrupt
 * @retval None
 */
void PWM_ClearFlag ( PWM_TypeDef* PWMx, uint16_t PWM_FLAG )
{
    /* Check the parameters */
    assert_param ( IS_PWM_ALL_PERIPH ( PWMx ) );
    assert_param ( IS_GET_PWM_FLAG ( PWM_FLAG ) );

    /* Clear the flags */
    PWMx->PWM_STS = ( uint16_t ) PWM_FLAG;
}
#endif
/**
 * @}
 */
/* End of PWM_Group3.	*/

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
