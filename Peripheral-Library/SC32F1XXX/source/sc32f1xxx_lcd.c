/*
 ******************************************************************************
 * @file    sc32f1xxx_LCD.c
 * @author  SOC AE Team
 * @version V1.7
 * @date     17-10-2024
 * @brief LCD function module
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
#include "sc32f1xxx_lcd.h"

/** @defgroup LCD_Group1 Initialization and Configuration functions
 *  @brief Initialization and Configuration functions
 *
@verbatim
 ===============================================================================
                     ##### Initialization and Configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitializes the LCD_LED peripheral
 * @retval None
 */
void LCD_DeInit ( void )
{
    /* Enable LCD reset state */
    RCC_APB2PeriphResetCmd ( RCC_APB2Periph_LCD_LED, ENABLE );
    /* Disable LCD reset state */
    RCC_APB2PeriphResetCmd ( RCC_APB2Periph_LCD_LED, DISABLE );
}

/**
 * @brief  Initializes the peripheral LCD register according to the parameters specified in LCD_InitStruct.
 * @param  LCD_InitStruct[out]: Pointer to structure LCD_InitTypeDef, to be initialized.
 * @retval None
 */
void LCD_Init ( LCD_InitTypeDef* LCD_InitStruct )
{
    uint32_t tmpreg;

    /* Check the parameters */
    assert_param ( IS_LCD_FRAMEFRE ( LCD_InitStruct->LCD_FrameFre ) );
    assert_param ( IS_LCD_DUTY ( LCD_InitStruct->LCD_Duty ) );

    /*---------------------------- LCD_LEDx DDR_CON Configuration ------------------------*/
    /* Get the LCD_LEDx DDR_CON value */
    tmpreg = LCD_LED->DDR_CON;

    /* Clear DMOD,BIAS,VOIRSIF,TYPE,DDRCK and TRIMODE bits */
    tmpreg &= ( uint32_t ) ~ ( DDR_CON_DMOD | DDR_CON_TYPE | DDR_CON_DDRCK | DDR_CON_TRIMODE );

    /* Configure LCD_LEDx: */
    /* Set DMOD bit to LCD_LED_MOD value */
    /* Set DDRCK,TRIMODE and TRIMODE bit to LCD_LED_FrameFre value */
    /* Set BIAS bit to LED_BiasVoltage value */
    /* Set VOIRSF bit to LED_VOIRSIF value */
    tmpreg |= ( uint32_t ) ( LCD_InitStruct->LCD_FrameFre |
                             LCD_InitStruct->LCD_Bias | LCD_InitStruct->LCD_VOIRSIF );

    /* Write to LCD_LEDx DDR_CON */
    LCD_LED->DDR_CON = tmpreg;

    /*---------------------------- LCD_LEDx DDR_CFG Configuration ------------------------*/
    /* Get the LCD_LEDx DDR_CFG value */
    tmpreg = LCD_LED->DDR_CFG;

    /* Clear DUTY,VOIRS and SCS bits */
    tmpreg &= ( uint32_t ) ~ ( DDR_CFG_DMOD | DDR_CFG_DUTY  | DDR_CFG_SCS );

    /* Configure LCD_LEDx: */
    /* Set DUTY bits to LCD_MOD value */
    /* Set VOIRS bits to LCD_ResSel value */
    /* Set SCS bits to LCD_Voltage value */
    tmpreg |= ( uint32_t ) ( LCD_InitStruct->LCD_ResSel |
                             LCD_InitStruct->LCD_Duty | ( LCD_InitStruct->LCD_Voltage << DDR_CFG_VLCD_Pos ) );

    /* Write to LCD_LEDx DDR_CON */
    LCD_LED->DDR_CFG = tmpreg;

    /* Write to LCD_LEDx SEG_EN */
#if defined(SC32f10xx) || defined(SC32f12xx)
    LCD_LED->SEG_EN = LCD_InitStruct->LCD_SegPin;
#elif defined(SC32f11xx)
    LCD_LED->SEG_EN0 = ( uint32_t ) LCD_InitStruct->LCD_SegPin;
    LCD_LED->SEG_EN1 = ( uint32_t ) ( LCD_InitStruct->LCD_SegPin >> 32 );
#endif
    /* Write to LCD_LEDx COM_EN */
    LCD_LED->COM_EN = LCD_InitStruct->LCD_ComPin;
}

/**
  * @brief  Fills each LCD_InitTypeDef member with its default value.
  * @param  LCD_InitStruct[out]: Pointer to structure LCD_InitTypeDef, to be initialized.
  * @retval None
  */
void LCD_StructInit ( LCD_InitTypeDef* LCD_InitStruct )
{
    /* Set the default configuration */
    LCD_InitStruct->LCD_Bias = LCD_Bias_1_4;
    LCD_InitStruct->LCD_ComPin = LCD_Channel_Less;
    LCD_InitStruct->LCD_Duty = LCD_Duty_1_8;
    LCD_InitStruct->LCD_FrameFre = LCD_FrameFre_B64Hz;
    LCD_InitStruct->LCD_ResSel = LCD_ResSel_33K;
    LCD_InitStruct->LCD_SegPin =  LCD_Channel_Less;
    LCD_InitStruct->LCD_VOIRSIF = LCD_VOIRSIF_Disable;
    LCD_InitStruct->LCD_Voltage = 0;
}

/**
 * @brief  Enables or disables the specified LCD peripheral.
 * @param  NewState[in]: new state of the LCD_LEDx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void LCD_Cmd ( FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the LCD_LED Counter */
        LCD_LED->DDR_CON |= DDR_CON_DDRON;
    }
    else
    {
        /* Disable the LCD_LED Counter */
        LCD_LED->DDR_CON &= ( uint16_t ) ~DDR_CON_DDRON;
    }
}


/**
 * @}
 */
/* End of LCD_LED_Group1.	*/

/** @defgroup LCD_LED_Group2 Data management functions
 *  @brief   Data management functions
 *
@verbatim
 ===============================================================================
                     ##### Data management functions #####
 ===============================================================================
@endverbatim
  * @{
  */
/**
 * @brief  Set the COM pin
 * @param  COMSelect[in]:COM pin selection.
 *         Selection range(COM0 -COM7)
 * @param  NewState[in]:new state of COM pin .
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void LCD_COMConfig ( LCD_COMEN_Typedef COMSelect, FunctionalState NewState )
{
    uint32_t temp;
    temp = LCD_LED->COM_EN;
    if ( NewState != DISABLE )
    {
        temp |= COMSelect;
    }
    else
    {
        temp &= ~COMSelect;
    }
    LCD_LED->COM_EN = temp;
}
/**
 * @brief  Set the SEG pin
 * @param  SEGSelect[in]:Output channel selection.
 *                  SC32f10xx Selection range(LCD_Channel_0 - LCD_Channel_27)
 *                  SC32f11xx Selection range(LCD_Channel_0 - LCD_Channel_34)
 *                  SC32f12xx Selection range(LCD_Channel_0 - LCD_Channel_27)
 *                     - LCD_Channel_0:select LCD_Channel_0
 *                     - LCD_Channel_1:select LCD_Channel_1
 *                     - LCD_Channel_2:select LCD_Channel_1
 *                     - LCD_Channel_3:select LCD_Channel_2
 *                     - LCD_Channel_4:select LCD_Channel_4
 *                     - LCD_Channel_5:select LCD_Channel_5
 *                     - LCD_Channel_6:select LCD_Channel_6
 *                     - LCD_Channel_7:select LCD_Channel_7
 *                     - LCD_Channel_8:select LCD_Channel_8
 *                     - LCD_Channel_9:select LCD_Channel_9
 *                     - LCD_Channel_10:select LCD_Channel_10
 *                     - LCD_Channel_11:select LCD_Channel_11
 *                     - LCD_Channel_12:select LCD_Channel_12
 *                     - LCD_Channel_13:select LCD_Channel_13
 *                     - LCD_Channel_14:select LCD_Channel_14
 *                     - LCD_Channel_15:select LCD_Channel_15
 *                     - LCD_Channel_16:select LCD_Channel_16
 *                     - LCD_Channel_17:select LCD_Channel_17
 *                     - LCD_Channel_18:select LCD_Channel_18
 *                     - LCD_Channel_19:select LCD_Channel_19
 *                     - LCD_Channel_20:select LCD_Channel_20
 *                     - LCD_Channel_21:select LCD_Channel_21
 *                     - LCD_Channel_22:select LCD_Channel_22
 *                     - LCD_Channel_23:select LCD_Channel_23
 *                     - LCD_Channel_24:select LCD_Channel_24
 *                     - LCD_Channel_25:select LCD_Channel_25
 *                     - LCD_Channel_26:select LCD_Channel_26
 *                     - LCD_Channel_27:select LCD_Channel_27
 * @param  NewState[in]:new state of SEG pin .
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void LCD_SEGConfig ( uint64_t SEGSelect, FunctionalState NewState )
{
#if  defined(SC32f10xx) || defined(SC32f12xx)
    uint32_t temp;
    temp = LCD_LED->SEG_EN;
    if ( NewState == ENABLE )
    {
        temp |= SEGSelect;
    }
    else
    {
        temp &= ~SEGSelect;
    }
    LCD_LED->SEG_EN = SEGSelect;
#elif defined(SC32f11xx)
    uint32_t temp0;
    uint32_t temp1;
    temp0 = LCD_LED->SEG_EN0;
    temp1 = LCD_LED->SEG_EN1;
    if ( NewState == ENABLE )
    {
        temp0 |= SEGSelect;
        temp1 |= SEGSelect >> 32;
    }
    else
    {
        temp0 &= ~SEGSelect;
        temp1 &= ~ ( SEGSelect >> 32 );
    }
    LCD_LED->SEG_EN0 = ( uint32_t ) temp0;
    LCD_LED->SEG_EN1 = ( uint32_t ) temp1;
#endif
}
/**
 * @brief  Writes data to SEG RAM.
 * @param  LCD_RAMRegister[in]:LCD RAM register selection.
 *                  SC32f10xx Selection range(LCD_RAMRegister_0 - LCD_RAMRegister_27)
 *                  SC32f11xx Selection range(LCD_RAMRegister_0 - LCD_RAMRegister_34)
 *                  SC32f12xx Selection range(LCD_RAMRegister_0 - LCD_RAMRegister_27)
 *                   - LCD_RAMRegister_0:select LCD_RAMRegister_0
 *                   - LCD_RAMRegister_1:select LCD_RAMRegister_1
 *                   - LCD_RAMRegister_2:select LCD_RAMRegister_2
 *                   - LCD_RAMRegister_3:select LCD_RAMRegister_3
 *                   - LCD_RAMRegister_4:select LCD_RAMRegister_4
 *                   - LCD_RAMRegister_5:select LCD_RAMRegister_5
 *                   - LCD_RAMRegister_6:select LCD_RAMRegister_6
 *                   - LCD_RAMRegister_7:select LCD_RAMRegister_7
 *                   - LCD_RAMRegister_8:select LCD_RAMRegister_8
 *                   - LCD_RAMRegister_9:select LCD_RAMRegister_9
 *                   - LCD_RAMRegister_10:select LCD_RAMRegister_10
 *                   - LCD_RAMRegister_11:select LCD_RAMRegister_11
 *                   - LCD_RAMRegister_12:select LCD_RAMRegister_12
 *                   - LCD_RAMRegister_13:select LCD_RAMRegister_13
 *                   - LCD_RAMRegister_14:select LCD_RAMRegister_14
 *                   - LCD_RAMRegister_15:select LCD_RAMRegister_15
 *                   - LCD_RAMRegister_16:select LCD_RAMRegister_16
 *                   - LCD_RAMRegister_17:select LCD_RAMRegister_17
 *                   - LCD_RAMRegister_18:select LCD_RAMRegister_18
 *                   - LCD_RAMRegister_19:select LCD_RAMRegister_19
 *                   - LCD_RAMRegister_20:select LCD_RAMRegister_20
 *                   - LCD_RAMRegister_21:select LCD_RAMRegister_21
 *                   - LCD_RAMRegister_22:select LCD_RAMRegister_22
 *                   - LCD_RAMRegister_23:select LCD_RAMRegister_23
 *                   - LCD_RAMRegister_24:select LCD_RAMRegister_24
 *                   - LCD_RAMRegister_25:select LCD_RAMRegister_25
 *                   - LCD_RAMRegister_26:select LCD_RAMRegister_26
 *                   - LCD_RAMRegister_27:select LCD_RAMRegister_27
 *                   - LCD_RAMRegister_28:select LCD_RAMRegister_28
 *                   - LCD_RAMRegister_29:select LCD_RAMRegister_29
 *                   - LCD_RAMRegister_30:select LCD_RAMRegister_30
 *                   - LCD_RAMRegister_31:select LCD_RAMRegister_31
 *                   - LCD_RAMRegister_32:select LCD_RAMRegister_32
 *                   - LCD_RAMRegister_33:select LCD_RAMRegister_33
 *                   - LCD_RAMRegister_34:select LCD_RAMRegister_34
 * @param  LCD_LED_Data[in]: LCD_LED display data.
 * @retval None
 */
void LCD_Write ( LCD_RAMRegister_Typedef LCD_RAMRegister, uint8_t LCD_LED_Data )
{
    LCD_LED->SEGRn[LCD_RAMRegister] = LCD_LED_Data;
}

/**
 * @brief  Switching COM port output.
 * @note   If the duty cycle is selected as 1/8
							Default COM7 output first, ending at COM0.
 * @retval None
 */
void LCD_CustomModeScan ( void )
{
    LCD_LED->DDR_CON |= DDR_CON_TRICOM;
}
#endif
/**
 * @}
 */
/* End of LCD_LED_Group2.	*/

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

