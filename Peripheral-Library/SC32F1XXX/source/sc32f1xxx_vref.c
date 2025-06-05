/**
 ******************************************************************************
 * @file    sc32f1xxx_vref.c
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief  VREF function module
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
#include "sc32f1xxx_vref.h"

/** @addtogroup sc32f1xxx_StdPeriph_Driver
 * @{
 */

/** @defgroup vref
 * @brief vref driver modules
 * @{
 */

/** @defgroup VREF_Exported_Functions
 * @{
 */

/** @defgroup VREF_Exported_Functions_Group1 Configuration of the vref computation unit functions
 *  @brief   Configuration of the vref computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### vref configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */


/**
 * @brief System analog circuit Vref selection.
 * @param  Vrefx[out]: Only VREF can be select the Vrefx peripheral.
 *                  - VREF:select VREF peripheral
 * @param  Peripheral_Voltage[in]: specifies the Peripheral_Voltage to check.
 *                  - Vref_ReferenceVoltageNone :VREF Reference Voltage  None
 *                  - Vref_ExReferenceVoltage:VREF ExReference Voltage 
 *                  - Vref_InReferenceVoltageEx_2_048:VREF InReferenceVoltageEx 2.048  
 *                  - Vref_InReferenceVoltageEx_1_024:VREF InReferenceVoltageEx 1.024 
 *                  - Vref_InReferenceVoltageEx_2_4:VREF InReferenceVoltageEx 2.4  
 *                  - Vref_InReferenceVoltage_2_048:Vref_ReferenceVoltage:2.048 
 *                  - Vref_InReferenceVoltage_1_024:Vref_ReferenceVoltage:1.024 
 *                  - Vref_InReferenceVoltage_2_4 :Vref_ReferenceVoltage:2.4

 * @retval TNone
 */
ErrorStatus Vref_ReferenceVoltageConfig(VREF_TypeDef* Vrefx, Vref_ReferenceVoltage_TypeDef Vref_ReferenceVoltage)
{
     uint32_t tmpreg;
	
    /* Check the parameters */
    assert_param(IS_Vref_ALL_PERIPH(Vrefx));
    assert_param(IS_Vref_ReferenceVoltage(Vref_ReferenceVoltage));
    

    tmpreg  =   Vrefx->VREF_CFG;
    tmpreg &= ~(VREF_CFG_VREFS|0x03);
    tmpreg |= (uint32_t)Vref_ReferenceVoltage;
    Vrefx->VREF_CFG =  tmpreg;
	 if((VREF->VREF_CFG & 0x03)==0x01)
	 {
		 if((uint8_t)(VREF->VREF_CFG & VREF_CFG_VREFS) == ((Vref_ReferenceVoltage)&0xFC))
				return SUCCESS;
		 else
				return ERROR;
   }
	 else
		 return SUCCESS;
}



/**
 * @brief  Enabled or Disable VMID port 
 * @param  Vrefx[out]: Only VREF can be select the Vrefx peripheral.
 *                  - VREF:select VREF peripheral
 * @param  NewState[in]: new state of the VMID port.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable 
 * @retval None
 */
void Vref_VMIDCmd(VREF_TypeDef* Vrefx, FunctionalState NewState)
{
    assert_param(IS_Vref_ALL_PERIPH(Vrefx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if(NewState != DISABLE)
    {
        Vrefx->VREF_CFG |= VREF_CFG_VMIDEN;
    }
    else
    {
        Vrefx->VREF_CFG &= (~(VREF_CFG_VMIDEN));
    }
}
/**
 * @brief  The internal reference divider circuit is enabled
 * @param  Vrefx[out]: Only VREF can be select the Vrefx peripheral.
 *                  - VREF:select VREF peripheral
 * @param  NewState[in]: new state of the DIVEN .
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable 
 * @retval None
 */
void Vref_DIVENCmd(VREF_TypeDef* Vrefx, FunctionalState NewState)
{
	  assert_param(IS_Vref_ALL_PERIPH(Vrefx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if(NewState != DISABLE)
    {
        Vrefx->VREF_CFG |= VREF_CFG_DIVEN;
    }
    else
    {
        Vrefx->VREF_CFG &= (~(VREF_CFG_DIVEN));
    }
}
#endif
/**
 * @}
 */
/* End of DAC_Group4.	*/

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
