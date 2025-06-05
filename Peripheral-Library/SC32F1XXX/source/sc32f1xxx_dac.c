/**
 ******************************************************************************
 * @file    sc32f1xxx_dac.c
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief  DAC function module
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
#if defined(SC32f15xx)
#include "sc32f1xxx_dac.h"



/** @defgroup DAC_Exported_Functions_Group1 Configuration of the DAC computation unit functions
 *  @brief   Configuration of the DAC computation unit functions.Common functions of motor
 *
@verbatim
 ===============================================================================
                     ##### DAC configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitializes the DAC peripheral
 * @param  DACx[in]: where can be to select the DAC peripheral.
 * @retval None
 */
void DAC_DeInit(DAC_TypeDef* DACx)
{
    /* Check the parameters */
    assert_param(IS_DAC_ALL_PERIPH(DACx));

    /* Reset DAC register */
    DACx->DAC_CFG = 0x00;
    DACx->DAC_IN = 0x00;
    DACx->DAC_STS = 0x00;
}

/**
 * @brief  Enables or disables the specified DAC peripheral.
 * @param  DACx[in]: where can be to select the DAC peripheral.
 * @param  NewState[in]: new state of the DACx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable  
 * @retval None
 */
void DAC_Cmd(DAC_TypeDef* DACx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_DAC_ALL_PERIPH(DACx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if(NewState != DISABLE)
    {
        /* Enable the DAC Counter */
        DACx->DAC_CFG |= DAC_CFG_DACEN;
    }
    else
    {
        /* Disable the DAC Counter */
        DACx->DAC_CFG &= (uint32_t)~DAC_CFG_DACEN;
    }
}

/**
 * @brief  Sets the DAC output channel.
 * @param  DACx[in]: where can be to select the DAC peripheral.
 * @param  DAC_Channel[in]:select the DAC output channel
 *         -DAC_Channel_0:DAC output channel 0 
 *         -DAC_Channel_1:DAC output channel 1 
 * @param  NewState[in]: new state of the DACx peripheral.
 *         - DISABLE:Function disable
 *         - ENABLE:Function enable  
 */
void DAC_ChannelConfig(DAC_TypeDef* DACx, DAC_Channel_TypeDef DAC_Channel, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_DAC_ALL_PERIPH(DACx));
    
    if(NewState != DISABLE)
    {
        if (DAC_Channel_0 == DAC_Channel)
        {
            DACx->DAC_CFG |= (uint8_t)DAC_CFG_OUT0EN;
        }
        else if (DAC_Channel_1 == DAC_Channel)
        {
            DACx->DAC_CFG |= (uint8_t)DAC_CFG_OUT1EN;
        }
    }
    else
    {
        if (DAC_Channel_0 == DAC_Channel)
        {
            DACx->DAC_CFG &= (uint8_t)~DAC_CFG_OUT0EN;
        }
        else if (DAC_Channel_1 == DAC_Channel)
        {
            DACx->DAC_CFG &= (uint8_t)~DAC_CFG_OUT1EN;
        }
    }
}

/**
 * @brief  Gets the DAC input channel.
 * @param  DACx[in]: where can be to select the DAC peripheral.
 * @param  DAC_REF[in]:Select DAC reference voltage 
 *         - DAC_RefSource_VDD:DAC reference voltage is VDD    
 *         - DAC_RefSource_VREF:DAC reference voltage is Vref
 * @retval None
 */
void DAC_VrefConfig(DAC_TypeDef* DACx, DAC_REF_TypeDef DAC_REF)
{
    uint32_t tmpreg;

    /* Check the parameters */
    assert_param(IS_DAC_ALL_PERIPH(DACx));
    assert_param(IS_DAC_VREF(DAC_REF));

    tmpreg = DACx->DAC_CFG;
    tmpreg &= ~DAC_CFG_REFSEL;
    tmpreg |= (uint32_t)DAC_REF;
    DACx->DAC_CFG = tmpreg;

}

/**
 * @}
 */
/* End of DAC_VREF_Group1.	*/


/** @defgroup DAC_Group2 Conversion management functions
 *  @brief   Conversion management functions
 *
@verbatim
 ===============================================================================
                     ##### DAC Conversion management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  Set DACx conversion result data for all channel.
 * @param  DACx[in]: where can be to select the DAC peripheral.
 * @param  DAC_Value[in]:DAC output voltage conversion value
 * @retval None
 */
void DAC_SetConversionValue(DAC_TypeDef* DACx, uint16_t DAC_Value)
{
    /* Check the parameters */
    assert_param(IS_DAC_ALL_PERIPH(DACx));

    /* Set DACx conversion */
    DACx->DAC_IN = DAC_Value;
}

/**
 * @}
 */
/* End of DAC_Group2.	*/

/** @defgroup DAC_Group3 Interrupts, DMA and flags management functions
 *  @brief    Interrupts, DMA and flags management functions
 *
@verbatim
 ===============================================================================
                     ##### Interrupts, DMA and flags management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  Checks whether the specified DAC flag is set or not.
 * @param  DACx[in]: where can be to select the DAC peripheral.
 * @param  DAC_FLAG[in]: specifies the flag to check.
 *             - DAC_DACSTA_Endconversion:DAC end conversion
 *             - DAC_DACSTA_Inconversion:DAC is being converted
 * @retval The new state of DAC_FLAG 
 *                  -  RESET:Flag reset
 *                  -  SET :Flag up
 */
FlagStatus DAC_GetFlagStatus(DAC_TypeDef* DACx, uint16_t DAC_FLAG)
{
    ITStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param(IS_DAC_ALL_PERIPH(DACx));
    assert_param(IS_GET_DAC_FLAG(DAC_FLAG));

    if((DACx->DAC_STS & DAC_FLAG) != (uint16_t)RESET)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    return bitstatus;
}
#endif
/**
 * @}
 */
/* End of DAC_Group3.	*/



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
