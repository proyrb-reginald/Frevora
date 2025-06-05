/**
 ******************************************************************************
 * @file    sc32f15Gx_dac.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   Header file of DAC module.
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
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __sc32f15Gx_DAC_H
#define __sc32f15Gx_DAC_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "sc32f15Gx.h"
#include "sc32.h"
#include "sc32f1xxx_rcc.h"



/** @defgroup DAC_Prescaler DAC Prescaler
 * @{
 */
typedef enum
{
  DAC_Channel_0	 = (uint16_t)(0x00U),	/*!< DAC output channel 0 */
  DAC_Channel_1	 = (uint16_t)(0x01U),	/*!< DAC output channel 1 */
} DAC_Channel_TypeDef;

#define IS_DAC_PRESCALER(PRESCALER) (((PRESCALER) == DAC_Channel_0)  ||   \
                                      ((PRESCALER) == DAC_Channel_1))
/**
 * @}
 */

/** @defgroup DAC_VREF DAC Reference Voltage
 * @{
 */
typedef enum
{
  DAC_RefSource_VDD  = (uint32_t)(0x00 << DAC_CFG_REFSEL_Pos),	  /*!< DAC reference voltage is VDD    */
  DAC_RefSource_VREF = (uint32_t)(0x01 << DAC_CFG_REFSEL_Pos),	  /*!< DAC reference voltage is Vref */
} DAC_REF_TypeDef;

#define IS_DAC_VREF(VREF) (((VREF) == DAC_RefSource_VDD)    || \
                           ((VREF) == DAC_RefSource_VREF))
/**
 * @}
 */

/** @defgroup DAC_Flag DAC Flag
 * @{
 */
typedef enum
  {
  DAC_Flag_STA = (uint8_t)DAC_STS_OVFIF,  /*!< DAC Interrupt: DAC Interrupt */
} DAC_Flag_TypeDef;
#define IS_DAC_Flag(Flag) (((VREF) == DAC_Flag_STA))
/**
 * @}
 */

/** @defgroup DAC_DACSTA DAC DACSTA
 * @{
 */
typedef enum
{
	DAC_DACSTA_Endconversion		= (uint8_t)(0x00 << DAC_STS_OVFIF_Pos), /*!< DAC end conversion  */
  DAC_DACSTA_Inconversion		= (uint8_t)(0x01 << DAC_STS_OVFIF_Pos), /*!<DAC is being converted */
} DAC_DACSTA_TypeDef;


#define IS_DAC_DACSTA(DACSTA) ((DACSTA) == DAC_DACSTA_Endconversion ||\
                                (DACSTA) == DAC_DACSTA_Inconversion )

#define IS_GET_DAC_FLAG(FLAG) ((FLAG) == DAC_DACSTA_Endconversion ||\
                                (FLAG) == DAC_DACSTA_Inconversion )
/**
 * @}
 */

#define IS_DAC_ALL_PERIPH(PERIPH) ((PERIPH) == DAC)


/**
 * @}
 */


/** @defgroup DAC_Constants DAC Constants
  * @{
  */


/**
 * @}
 */

/* Exported struct ------------------------------------------------------------*/
/** @defgroup DAC_Exported_Struct DAC Exported Struct
 * @{
 */

/**
 * @}
 */
/* End of struct -----------------------------------------------------*/

/** @addtogroup DAC_Functions DAC Functions
 * @{
 */

/* DAC Base functions ********************************************************/
void DAC_DeInit(DAC_TypeDef* DACx);
void DAC_Cmd(DAC_TypeDef* DACx, FunctionalState NewState);
void DAC_ChannelConfig(DAC_TypeDef* DACx, DAC_Channel_TypeDef DAC_Channel, FunctionalState NewState);
void DAC_VrefConfig(DAC_TypeDef* DACx, DAC_REF_TypeDef DAC_REF);

/* DAC Conversion management functions **********************************************/
void DAC_SetConversionValue(DAC_TypeDef* DACx, uint16_t DAC_Value);
/* Interrupt Handler functions  ***********************************************/
FlagStatus DAC_GetFlagStatus(DAC_TypeDef* DACx, uint16_t DAC_FLAG);


/**
 * @}
 */
/* End of functions --------------------------------------------------*/

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
