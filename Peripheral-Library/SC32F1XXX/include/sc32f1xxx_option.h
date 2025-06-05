/**
 ******************************************************************************
 * @file    sc32f1xxx_option.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   Header file of OPTION module.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __sc32f1xxx_OPTION_H
#define __sc32f1xxx_OPTION_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "sc32f1xxx.h"
#include "SC32.h"

/** @addtogroup sc32f1xxx_StdPeriph_Driver
 * @{
 */

/** @addtogroup OPTION
 * @{
 */

/** @defgroup OPTION_Enumerations OPTION Enumerations
 * @{
 */

/** @brief OPTION_LVR  LVR stalls
 * @{
 */

typedef enum
{
    OPTION_LVR_DISABLE = ( uint8_t ) 0x04, /*!< LVR Reset: disable */
    OPTION_LVR_1_9V    = ( uint8_t ) 0x00, /*!< LVR Reset: 1.9V */
    OPTION_LVR_2_9V    = ( uint8_t ) 0x01, /*!< LVR Reset: 2.9V */
    OPTION_LVR_3_7V    = ( uint8_t ) 0x02, /*!< LVR Reset: 3.7V */
    OPTION_LVR_4_3V    = ( uint8_t ) 0x03, /*!< LVR Reset: 4.3V */
} OPTION_LVR_TypeDef;

#define IS_OPTION_LVR(LVR) (((LVR) == OPTION_LVR_DISABLE) ||  \
                            ((LVR) == OPTION_LVR_1_9V) ||  \
                            ((LVR) == OPTION_LVR_2_9V) ||  \
                            ((LVR) == OPTION_LVR_3_7V) ||  \
                            ((LVR) == OPTION_LVR_4_3V))

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup OPTION_Functions OPTION Functions
 * @{
 */

/* option configuration ********************************************************/
void OPTION_WDTCmd ( FunctionalState NewState );
void OPTION_LVRConfig (OPTION_LVR_TypeDef OPTION_LVR );
void OPTION_JTAGCmd ( FunctionalState NewState );
void OPTION_IAPPORA ( uint16_t IAPPROAST, uint16_t IAPPROAED );
void OPTION_IAPPORB ( uint16_t IAPPROBST, uint16_t IAPPROBED );
/**
 * @}
 */

/* End of exported functions --------------------------------------------------*/

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
