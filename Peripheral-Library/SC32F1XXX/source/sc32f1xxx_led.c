/*
 ******************************************************************************
 * @file    sc32f1xxx_led.c
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief LED function module
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
#include "sc32f1xxx_led.h"

/** @defgroup LED_Group1 Initialization and Configuration functions
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
 * @brief  Deinitializes the LED peripheral
 * @retval None
 */
void LED_DeInit ( void )
{
    /* Enable LCD_LED reset state */
    RCC_APB2PeriphResetCmd ( RCC_APB2Periph_LCD_LED, ENABLE );
    /* Disable LCD_LED reset state */
    RCC_APB2PeriphResetCmd ( RCC_APB2Periph_LCD_LED, DISABLE );
}

/**
 * @brief Initializes the peripheral LED register according
 *         to the parameters specified in LED_InitStruct.
 * @param  LED_InitStruct[out]:Pointer to structure LED_InitTypeDef, to be initialized.
 * @retval None
 */
void LED_Init ( LED_InitTypeDef* LED_InitStruct )
{
    uint32_t tmpreg;

    /* Check the parameters */
    assert_param ( IS_LED_FRAMEFRE ( LED_InitStruct->LED_FrameFre ) );
    assert_param ( IS_LED_DUTY ( LED_InitStruct->LED_Duty ) );

    /*---------------------------- LCD_LEDx DDR_CON Configuration ------------------------*/
    /* Get the LCD_LEDx DDR_CFG value */
    tmpreg = LCD_LED->DDR_CON;

    /* Clear DMOD,TYPE,DDRCK and TRIMODE bits */
    tmpreg &= ( uint32_t ) ~ ( DDR_CON_DMOD | DDR_CON_TYPE | DDR_CON_DDRCK | DDR_CON_TRIMODE );

    /* Configure LCD_LEDx: */
    /* Set DMOD bit to LED_MOD value */
    /* Set DDRCK,TRIMODE and TRIMODE bit to LED_FrameFre value */
    tmpreg |= ( uint32_t ) ( DDR_CON_DMOD |
                             LED_InitStruct->LED_FrameFre );
    /* Write to LCD_LEDx DDR_CON */
    LCD_LED->DDR_CON = tmpreg;

    /*---------------------------- LCD_LEDx DDR_CFG Configuration ------------------------*/
    /* Clear DUTY and BIAS bits */
    LCD_LED->DDR_CFG &= ( uint32_t ) ~ ( DDR_CFG_DUTY  | DDR_CFG_SCS );

    /* Configure LCD_LEDx: */
    /* Set DUTY bits to LED_MOD value */
    /* Set SCS bit to LED_TPYE value */
    LCD_LED->DDR_CFG |= ( uint32_t ) LED_InitStruct->LED_Duty;

    /* Write to LCD_LEDx SEG_EN */
#if defined(SC32f10xx) || defined(SC32f12xx)
    LCD_LED->SEG_EN = LED_InitStruct->LED_SegPin;
#elif defined(SC32f11xx)
    LCD_LED->SEG_EN0 = ( uint32_t ) LED_InitStruct->LED_SegPin;
    LCD_LED->SEG_EN1 = ( uint32_t ) ( LED_InitStruct->LED_SegPin >> 32 );
#endif


    /* Write to LCD_LEDx COM_EN */
    LCD_LED->COM_EN = LED_InitStruct->LED_ComPin;
}

/**
  * @brief  Fills each LED_InitTypeDef member with its default value.
  * @param  LED_InitStruct[out]:Pointer to structure LED_InitTypeDef, to be initialized.
  * @retval None
  */
void LED_StructInit ( LED_InitTypeDef* LED_InitStruct )
{
    /* Set the default configuration */
    LED_InitStruct->LED_ComPin = LED_Channel_Less;
    LED_InitStruct->LED_Duty = LED_Duty_1_8;
    LED_InitStruct->LED_FrameFre = LED_FrameFre_B64Hz;
    LED_InitStruct->LED_SegPin =  LED_Channel_Less;
}

/**
 * @brief  Enables or disables the specified LCD_LEDx peripheral.
 * @param  NewState[in]:new state of the LCD_LEDx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void LED_Cmd ( FunctionalState NewState )
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
/* End of LED_Group1.	*/

/** @defgroup LED_Group2 Data management functions
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
 * @brief  Writes data to SEG RAM.
 * @param  LED_RAMRegister[in]:Output channel selection.
 *                  SC32f10xx Selection range(LED_RAMRegister_0 - LED_RAMRegister_27)
 *                  SC32f11xx Selection range(LED_RAMRegister_0 - LED_RAMRegister_34)
 *                  SC32f12xx Selection range(LED_RAMRegister_0 - LED_RAMRegister_27)
 *                     - LED_RAMRegister_0:select LED_RAMRegister_0
 *                     - LED_RAMRegister_1:select LED_RAMRegister_1
 *                     - LED_RAMRegister_2:select LED_RAMRegister_2
 *                     - LED_RAMRegister_3:select LED_RAMRegister_3
 *                     - LED_RAMRegister_4:select LED_RAMRegister_4
 *                     - LED_RAMRegister_5:select LED_RAMRegister_5
 *                     - LED_RAMRegister_6:select LED_RAMRegister_6
 *                     - LED_RAMRegister_7:select LED_RAMRegister_7
 *                     - LED_RAMRegister_8:select LED_RAMRegister_8
 *                     - LED_RAMRegister_9:select LED_RAMRegister_9
 *                     - LED_RAMRegister_10:select LED_RAMRegister_10
 *                     - LED_RAMRegister_11:select LED_RAMRegister_11
 *                     - LED_RAMRegister_12:select LED_RAMRegister_12
 *                     - LED_RAMRegister_13:select LED_RAMRegister_13
 *                     - LED_RAMRegister_14:select LED_RAMRegister_14
 *                     - LED_RAMRegister_15:select LED_RAMRegister_15
 *                     - LED_RAMRegister_16:select LED_RAMRegister_16
 *                     - LED_RAMRegister_17:select LED_RAMRegister_17
 *                     - LED_RAMRegister_18:select LED_RAMRegister_18
 *                     - LED_RAMRegister_19:select LED_RAMRegister_19
 *                     - LED_RAMRegister_20:select LED_RAMRegister_20
 *                     - LED_RAMRegister_21:select LED_RAMRegister_21
 *                     - LED_RAMRegister_22:select LED_RAMRegister_22
 *                     - LED_RAMRegister_23:select LED_RAMRegister_23
 *                     - LED_RAMRegister_24:select LED_RAMRegister_24
 *                     - LED_RAMRegister_25:select LED_RAMRegister_25
 *                     - LED_RAMRegister_26:select LED_RAMRegister_26
 *                     - LED_RAMRegister_27:select LED_RAMRegister_27
 * @param  LED_Data[in]:  LCD_LED display data.
 * @retval None
 */
void LED_Write ( LED_RAMRegister_Typedef LED_RAMRegister, uint8_t LED_Data )
{
    LCD_LED->SEGRn[LED_RAMRegister] = LED_Data;
}
/**
 * @brief  Set the COM pin
 * @param  COMSelect[in]:COM pin selection.
 *         Selection range(COM0 -COM7)
 * @param  NewState[in]:new state of COM pin .
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void LED_COMConfig ( LED_COMEN_Typedef COMSelect, FunctionalState NewState )
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
 *                  SC32f10xx Selection range(LED_Channel_0 - LED_Channel_27)
 *                  SC32f11xx Selection range(LED_Channel_0 - LED_Channel_34)
 *                  SC32f12xx Selection range(LED_Channel_0 - LED_Channel_27)
 *                     - LED_Channel_0:select LED_Channel_0
 *                     - LED_Channel_1:select LED_Channel_1
 *                     - LED_Channel_2:select LED_Channel_2
 *                     - LED_Channel_3:select LED_Channel_3
 *                     - LED_Channel_4:select LED_Channel_4
 *                     - LED_Channel_5:select LED_Channel_5
 *                     - LED_Channel_6:select LED_Channel_6
 *                     - LED_Channel_7:select LED_Channel_7
 *                     - LED_Channel_8:select LED_Channel_8
 *                     - LED_Channel_9:select LED_Channel_9
 *                     - LED_Channel_10:select LED_Channel_10
 *                     - LED_Channel_11:select LED_Channel_11
 *                     - LED_Channel_12:select LED_Channel_12
 *                     - LED_Channel_13:select LED_Channel_13
 *                     - LED_Channel_14:select LED_Channel_14
 *                     - LED_Channel_15:select LED_Channel_15
 *                     - LED_Channel_16:select LED_Channel_16
 *                     - LED_Channel_17:select LED_Channel_17
 *                     - LED_Channel_18:select LED_Channel_18
 *                     - LED_Channel_19:select LED_Channel_19
 *                     - LED_Channel_20:select LED_Channel_20
 *                     - LED_Channel_21:select LED_Channel_21
 *                     - LED_Channel_22:select LED_Channel_22
 *                     - LED_Channel_23:select LED_Channel_23
 *                     - LED_Channel_24:select LED_Channel_24
 *                     - LED_Channel_25:select LED_Channel_25
 *                     - LED_Channel_26:select LED_Channel_26
 *                     - LED_Channel_27:select LED_Channel_27
 * @param  NewState[in]:new state of SEG pin .
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void LED_SEGConfig ( uint64_t SEGSelect, FunctionalState NewState )
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
 * @brief  Switching COM port output.
 * @note   If the duty cycle is selected as 1/8
							Default COM7 output first, ending at COM0.
 * @retval None
 */
void LED_CustomModeScan ( void )
{
    LCD_LED->DDR_CON = DDR_CON_TRICOM;
}

/**
 * @}
 */
/* End of LED_Group2.	*/
#endif
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
