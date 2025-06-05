/**
 ******************************************************************************
 * @file    sc32f1xxx_TS.c
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief  TS function module
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
#include "sc32f1xxx_Temper.h"


/** @defgroup TS_Functions
 * @{
 */

/** @defgroup TS_Group1 Initialization and Configuration functions
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
 * @brief  DeInitializes the TS peripheral
 * @retval None
 */
void TemperSensor_DeInit(void)
{
  /* Enable TS reset state */
   TS->TS_CFG = 0x00;
}

/**
 * @brief Enabled or Disable TS peripheral  
 * @param  TSx[out]:where can to select the TS peripheral.
 *                  - TS:Timer peripheral select TS
 * @param  NewState[in]: new state of the TS .
 *         - ENABLE: Function enable   
 *         - DISABLE:Function disable
 * @retval None
 */
void TemperSensor_Cmd(TS_TypeDef* TSx, FunctionalState NewState)
{
  /* Enable TS reset state */
	 if(NewState != DISABLE)
  {
    /* Enable the TS  */
    TSx->TS_CFG |= TemperSensor_Enable;
  }
  else
  {
    /* Disable the TS  */
     TSx->TS_CFG &= (uint8_t)~TemperSensor_Enable;
  }
   
}

/**
 * @brief  The TS peripheral triggers the temperature reading
 * @param  TSx[out]:where can to select the TS peripheral.
 *                  - TS:Timer peripheral select TS
 * @param  NewState[in]: new state of the TS Offset .
 *         - ENABLE: Function enable   
 *         - DISABLE:Function disable
 * @retval None
 */
void TemperSensor_OffSetCmd(TS_TypeDef* TSx)
{
  
 
    TSx->TS_CFG |= 0x01<<TS_CFG_CHOP_Pos;	
 
}
/**
 * @brief  The TS peripheral triggers the temperature reading
 * @param  TSx[out]:where can to select the TS peripheral.
 *                  - TS:Timer peripheral select TS
 * @param  NewState[in]: new state of the TS Offset .
 *         - ENABLE: Function enable   
 *         - DISABLE:Function disable
 * @retval None
 */
void TemperSensor_OffResetCmd(TS_TypeDef* TSx)
{ 

    TSx->TS_CFG &=~ (0x01<<TS_CFG_CHOP_Pos);

 
}
/**
 * @brief  Return the TS check data.
 * @param  None
 * @retval the TS check data.
 */
uint16_t TemperSensor_ReadValue(void)
{
	uint16_t TS_Value;
	TS_Value =((*(uint8_t*)0x8c00480)<<8)+(*(uint8_t*)0x8c00481);
	return TS_Value;
}
#endif
/**
 * @}
 */

/************************ (C) COPYRIGHT SOC Microelectronics *****END OF FILE****/
