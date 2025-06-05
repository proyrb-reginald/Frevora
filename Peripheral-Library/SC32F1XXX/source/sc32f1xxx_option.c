/*
 ******************************************************************************
 * @file    sc32f1xxx_option.c
 * @author  SOC AE Team
 * @version V1.7
 * @date     17-10-2024
 * @brief OPTION function module
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
#include "sc32f1xxx_option.h"

/** @defgroup OPTION_Group1 Configuration of the option computation unit functions
 *  @brief   Configuration of the option computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### option configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
  * @brief  Enables or disables the WDT peripheral.
  * @param  NewState[in]:  new state of the ADCx peripheral.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable
  * @retval None
  */
void OPTION_WDTCmd ( FunctionalState NewState )
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


/**
 * @brief  Configures the LVR voltage gear.
 * @param  OPTION_LVR[in]: specifies the LVR voltage gear.
 *            - OPTION_LVR_DISABLE: LVR Reset: disable
 *            - OPTION_LVR_1_9V: LVR Reset: 1.9V
 *            - OPTION_LVR_2_9V: LVR Reset: 2.9V
 *            - OPTION_LVR_3_7V: LVR Reset: 3.7V
 *            - OPTION_LVR_4_3V: LVR Reset: 4.3V
 * @retval None
 */
void OPTION_LVRConfig ( OPTION_LVR_TypeDef OPTION_LVR )
{
    OPT->OPINX = 0xC1;

    OPT->OPREG &= 0XF8;

    OPT->OPREG |= OPTION_LVR;
}

/**
 * @brief  Enables or disables the JTAG function.
* @param  NewState[in]: new state of the ADCx peripheral.
*                  - DISABLE:Function disable
*                  - ENABLE:Function enable
 * @retval None
 */
void OPTION_JTAGCmd ( FunctionalState NewState )
{
    OPT->OPINX = 0xC2;
    if ( NewState == DISABLE )
    {
        OPT->OPREG |= 0X40;
    }
    else
    {
        OPT->OPREG &= 0XBF;
    }
}

/**
 * @brief  IAP protection locale A
* @param  IAPPROAST[in]: The start sector of the IAP protection zone
* @param  IAPPROAED[in]: The end-of-IAP protected sector
 */
void OPTION_IAPPORA ( uint16_t IAPPROAST, uint16_t IAPPROAED )
{
    OPT->OPINX = 0xC3;

    OPT->OPREG = IAPPROAST;

    OPT->OPINX = 0xC5;

    OPT->OPREG = IAPPROAED;

}

/**
 * @brief IAP protection locale B
 * @param  IAPPROBST[in]: The start sector of the IAP protection zone
 * @param  IAPPROBED[in]: The end-of-IAP protected sector
 * @retval None
 */
void OPTION_IAPPORB ( uint16_t IAPPROBST, uint16_t IAPPROBED )
{
    OPT->OPINX = 0xC7;

    OPT->OPREG = IAPPROBST;

    OPT->OPINX = 0xC9;

    OPT->OPREG = IAPPROBED;

}

/**
 * @}
 */
/* End of option_Group1.	*/

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT SOCicroelectronics *****END OF FILE****/

