/**
 ******************************************************************************
 * @file    sc32f1xxx_cmp.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   Header file of CMP module.
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
#ifndef __sc32f1xxx_CMP_H
#define __sc32f1xxx_CMP_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "sc32f1xxx.h"
#include "sc32.h"
#include "sc32f1xxx_rcc.h"

/** @addtogroup sc32f1xxx_StdPeriph_Driver
 * @{
 */

/** @addtogroup CMP
 * @{
 */

/* Exported enumerations ------------------------------------------------------------*/
/** @defgroup CMP_Enumerations CMP Enumerations
 * @{
 */

/** @brief CMP_Positive CMP Positive
 * @{
 */
#if defined(SC32f10xx)
typedef enum
{
    CMP_Positive_CMP0 = ( uint16_t ) ( 0x00U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP0 as the CMP input port    */
    CMP_Positive_CMP1 = ( uint16_t ) ( 0x01U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP1 as the CMP input port  */
    CMP_Positive_CMP2 = ( uint16_t ) ( 0x02U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP2 as the CMP input port   */
    CMP_Positive_CMP3 = ( uint16_t ) ( 0x03U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP3 as the CMP input port   */
    CMP_Positive_1_5V = ( uint16_t ) ( 0x01U << CMP_CFG_CMPP_Pos ), /*!< Select CMPP as the CMP input port,CMPP is 1.5V reference voltage     */
} CMP_Positive_TypeDef;

#define IS_CMP_Positive(POSITIVE) (((POSITIVE) == CMP_Positive_CMP0) || \
                                   ((POSITIVE) == CMP_Positive_CMP1) || \
                                   ((POSITIVE) == CMP_Positive_CMP2) || \
                                   ((POSITIVE) == CMP_Positive_CMP3) || \
                                   ((POSITIVE) == CMP_Positive_1_5V))
#elif defined(SC32f11xx)
typedef enum
{
    CMP_Positive_CMP0 = ( uint16_t ) ( 0x00U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP0 as the CMP input port    */
    CMP_Positive_CMP1 = ( uint16_t ) ( 0x01U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP1 as the CMP input port    */
    CMP_Positive_1_5V = ( uint16_t ) ( 0x01U << CMP_CFG_CMPP_Pos ), /*!< Select CMPP as the CMP input port,CMPP is 1.5V reference voltage     */
    CMP_Positive_PGA  = ( uint16_t ) ( 0x07U << CMP_CFG_CMPIS_Pos ), /*!< Select OP as the CMP input port       */
} CMP_Positive_TypeDef;

#define IS_CMP_Positive(POSITIVE) (((POSITIVE) == CMP_Positive_CMP0) || \
                                   ((POSITIVE) == CMP_Positive_CMP1) || \
                                   ((POSITIVE) == CMP_Positive_1_5V) || \
																	 ((POSITIVE) == CMP_Positive_PGA))

#elif defined(SC32f12xx)
typedef enum
{
    CMP_Positive_CMP0 = ( uint16_t ) ( 0x00U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP0 as the CMP input port    */
    CMP_Positive_CMP1 = ( uint16_t ) ( 0x01U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP1 as the CMP input port    */
    CMP_Positive_CMP2 = ( uint16_t ) ( 0x02U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP2 as the CMP input port    */
    CMP_Positive_CMP3 = ( uint16_t ) ( 0x03U << CMP_CFG_CMPIS_Pos ), /*!< Select CMP3 as the CMP input port    */
    CMP_Positive_1_6V = ( uint16_t ) ( 0x01U << CMP_CFG_CMPP_Pos ), /*!< Select CMPP as the CMP input port,CMPP is 1.5V reference voltage     */
    CMP_Positive_OP  = ( uint16_t ) ( 0x07U << CMP_CFG_CMPIS_Pos ), /*!< Select OP as the CMP input port       */
} CMP_Positive_TypeDef;

#define IS_CMP_Positive(POSITIVE) (((POSITIVE) == CMP_Positive_CMP0) || \
                                   ((POSITIVE) == CMP_Positive_CMP1) || \
                                   ((POSITIVE) == CMP_Positive_CMP2) || \
                                   ((POSITIVE) == CMP_Positive_CMP3) || \
                                   ((POSITIVE) == CMP_Positive_1_5V) || \
																	 ((POSITIVE) == CMP_Positive_OP))
#elif defined(SC32f15xx)
typedef enum
{
  CMP0_Positive_CMP0P = (uint16_t)(0x00U<<CMPX_CFG_CMPPS_Pos),    /*!< CMP0 Select CMP0P as the CMP Positive port    */
  CMP0_Positive_OP1O = (uint16_t)(0x01U << CMPX_CFG_CMPPS_Pos),    /*!< CMP0 Select OP1O as the CMP Positive port  */
  CMP0_Positive_OP2O = (uint16_t)(0x02U << CMPX_CFG_CMPPS_Pos),    /*!< CMP0 Select OP2O as the CMP Positive port   */
  CMP3_Positive_CMP3P = (uint16_t)(0x00U << CMP_CFG_CMPPS_Pos),    /*!< CMP3 Select CMP3P as the CMP input port    */
  CMP3_Positive_OP1O = (uint16_t)(0x01U << CMP_CFG_CMPPS_Pos),    /*!< CMP3 Select OP1O as the CMP input port  */
  CMP3_Positive_OP2O = (uint16_t)(0x02U << CMP_CFG_CMPPS_Pos),    /*!< CMP3 Select OP2O as the CMP input port   */
} CMP_Positive_TypeDef;

#define IS_CMP_Positive(POSITIVE) (((POSITIVE) == CMP0_Positive_CMP0P) || \
																	((POSITIVE) == CMP0_Positive_OP1O) || \
																	((POSITIVE) == CMP0_Positive_OP2O) || \
                                  ((POSITIVE) == CMP3_Positive_CMP3P) || \
                                  ((POSITIVE) == CMP3_Positive_OP1O)  || \
                                  ((POSITIVE) == CMP3_Positive_OP2O))
#endif

/**
 * @}
 */
#if defined(SC32f15xx)
typedef enum
{
    CMP0_1_2NegativeSelect_CMPxN 	= (uint16_t)(0x00U << CMPX_CFG_CMPNS_Pos),  /*!<  Select CMPxN as the CMP0_1_2 Negative port   */
    CMP0_1_2NegativeSelect_DAC 	    = (uint16_t)(0x01U << CMPX_CFG_CMPNS_Pos),    /*!< Select DAC as the CMP0_1_2 Negative port   */
    CMP0_1_2NegativeSelect_BEMF_MID = (uint16_t)(0x02U << CMPX_CFG_CMPNS_Pos), /*!< Select BEMF_MID as the CMP0_1_2 Negative port   */
    CMP3_NegativeSelect_CMPxN       = (uint16_t)(0x00U << CMP_CFG_CMPNS_Pos),  /*!< Select CMPN as the CMP3 Negative input port    */
    CMP3_NegativeSelect_DAC 	    = (uint16_t)(0x01U << CMP_CFG_CMPNS_Pos),  /*!< Select DAC as the CMP3 Negative input port    */
    CMP3_NegativeSelect_CMPRF       = (uint16_t)(0x02U << CMP_CFG_CMPNS_Pos),  /*!< Select CMPRF as the CMP3 Negative input port    */
} CMP_NegativeSelect_TypeDef ;

#define IS_CMP_NegativeSelect(NegativeSelect) (((NegativeSelect) == CMP0_1_2NegativeSelect_CMPxN) || \
																	((NegativeSelect) == CMP0_1_2_NegativeSelect_DAC) || \
																	((NegativeSelect) == CMP0_1_2_NegativeSelect_BEMF_MID) || \
                                  ((NegativeSelect) == CMP3_NegativeSelect_CMPxN)|| \
                                  ((NegativeSelect) == CMP3_NegativeSelect_DAC) || \
                                  ((NegativeSelect) == CMP3_NegativeSelect_CMPRF))
/** @defgroup CMP_VREF CMP Reference Voltage
 * @{
 */
typedef enum
{
    CMP0_1_2RefSource_VDD  = (uint32_t)(0x00 << CMP_CON_REFSEL_Pos),	  /*!< CMP0_1_2 reference voltage is VDD    */
    CMP0_1_2RefSource_VREF = (uint32_t)(0x01 << CMP_CON_REFSEL_Pos),	  /*!< CMP0_1_2 reference voltage is Vref */
    CMP3_RefSource_VDD  = (uint32_t)(0x00 << CMP_CON_REFSEL_Pos),	  /*!< CMP3 reference voltage is VDD    */
    CMP3_RefSource_VREF = (uint32_t)(0x01 << CMP_CON_REFSEL_Pos),	  /*!< CMP3 reference voltage is Vref */
} CMP_VREF_TypeDef;

#define IS_CMP_VREF(VREF) (((VREF) == CMP0_1_2RefSource_VDD)    || \
                           ((VREF) == CMP0_1_2RefSource_VREF) || \
                           ((VREF) == CMP3_RefSource_VDD)    || \
                           ((VREF) == CMP3_RefSource_VREF))

#endif
/** @brief CMP_Negative CMP Negative
 * @{
 */
 #if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
typedef enum
{

    CMP_Negative_CMPR    	= ( uint16_t ) ( 0x00U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is CMPR  */
    CMP_Negative_1D16VDD 	= ( uint16_t ) ( 0x01U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 1/16VDD   */
    CMP_Negative_2D16VDD 	= ( uint16_t ) ( 0x02U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 2/16VDD   */
    CMP_Negative_3D16VDD 	= ( uint16_t ) ( 0x03U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 3/16VDD   */
    CMP_Negative_4D16VDD 	= ( uint16_t ) ( 0x04U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 4/16VDD   */
    CMP_Negative_5D16VDD 	= ( uint16_t ) ( 0x05U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 5/16VDD   */
    CMP_Negative_6D16VDD 	= ( uint16_t ) ( 0x06U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 6/16VDD   */
    CMP_Negative_7D16VDD 	= ( uint16_t ) ( 0x07U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 7/16VDD   */
    CMP_Negative_8D16VDD 	= ( uint16_t ) ( 0x08U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 8/16VDD   */
    CMP_Negative_9D16VDD 	= ( uint16_t ) ( 0x09U << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 9/16VDD   */
    CMP_Negative_10D16VDD = ( uint16_t ) ( 0x0AU << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 10/16VDD   */
    CMP_Negative_11D16VDD = ( uint16_t ) ( 0x0BU << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 11/16VDD   */
    CMP_Negative_12D16VDD = ( uint16_t ) ( 0x0CU << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 12/16VDD   */
    CMP_Negative_13D16VDD = ( uint16_t ) ( 0x0DU << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 13/16VDD   */
    CMP_Negative_14D16VDD = ( uint16_t ) ( 0x0EU << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 14/16VDD   */
    CMP_Negative_15D16VDD = ( uint16_t ) ( 0x0FU << CMP_CFG_CMPRF_Pos ), /*!< The comparison voltage of CMP is 15/16VDD   */
} CMP_Negative_TypeDef;

#define IS_CMP_Negative(NEGATIVE) (((NEGATIVE) == CMP_Negative_CMPR) || \
                                   ((NEGATIVE) == CMP_Negative_1D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_2D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_3D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_4D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_5D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_6D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_7D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_8D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_9D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_10D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_11D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_12D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_13D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_14D16VDD) || \
                                   ((NEGATIVE) == CMP_Negative_15D16VDD))
/** @brief CMP_TriggerMode CMP TriggerMode
 * @{
 */
typedef enum
{
    CMP_TriggerMode_Disable   = ( uint16_t ) ( 0x00U << CMP_CFG_CMPIM_Pos ), /*!< The trigger mode is disable  */
    CMP_TriggerMode_RISE      = ( uint16_t ) ( 0x01U << CMP_CFG_CMPIM_Pos ), /*!< The trigger mode of simulated comparator is rising edge  */
    CMP_TriggerMode_FALL      = ( uint16_t ) ( 0x02U << CMP_CFG_CMPIM_Pos ), /*!< The trigger mode of simulated comparator is falling edge  */
    CMP_TriggerMode_RISE_FALL = ( uint16_t ) ( 0x03U << CMP_CFG_CMPIM_Pos ), /*!< The trigger mode of the simulated comparator is rising edge and falling edge  */
} CMP_TriggerMode_TypeDef;

#define IS_CMP_TRIGGER(TRIGGER) (((TRIGGER) == CMP_TriggerMode_Disable) || \
                                 ((TRIGGER) == CMP_TriggerMode_RISE) || \
                                 ((TRIGGER) == CMP_TriggerMode_FALL) || \
                                 ((TRIGGER) == CMP_TriggerMode_RISE_FALL))
/** @brief CMP_CMPSTA CMP CMPSTA
 * @{
 */
typedef enum
{
    CMP_CMPSTA_Low		= ( uint32_t ) ( 0x00 << CMP_STS_CMPSTA_Pos ), /*!< CMP Flag: The non-inverting input is at a lower voltage than the inverting input */
    CMP_CMPSTA_High		= ( uint32_t ) ( 0x01 << CMP_STS_CMPSTA_Pos ), /*!< CMP Flag: The non-inverting input is at a higher voltage than the inverting input */
} CMP_CMPSTA_TypeDef;

#define IS_CMP_CMPSTA(STA) (((STA) == CMP_TriggerMode_Disable) || \
                           ((STA) == CMP_TriggerMode_RISE_FALL))
/**
 * @}
 */

/** @brief CMP_FLAG CMP Flag
 * @{
 */
typedef enum
{
    CMP_FLAG_IF		= ( uint32_t ) CMP_STS_CMPIF, /*!< CMP Flag: Interrupt flag */
} CMP_FLAG_TypeDef;

#define IS_CMP_FLAG(FLAG) ((FLAG) == CMP_FLAG_IF)
#elif defined(SC32f15xx)
typedef enum
{
    CMP3_Negative_1D16CMP_VREF   = (uint16_t)(0x01U << CMP_CFG_CMPRF_Pos),  /*!< The comparison voltage of CMP is 1/16VDD   */
    CMP3_Negative_2D16CMP_VREF   = (uint16_t)(0x02U << CMP_CFG_CMPRF_Pos),  /*!< The comparison voltage of CMP is 2/16VDD   */
    CMP3_Negative_3D16CMP_VREF   = (uint16_t)(0x03U << CMP_CFG_CMPRF_Pos),  /*!< The comparison voltage of CMP is 3/16VDD   */
    CMP3_Negative_4D16CMP_VREF   = (uint16_t)(0x04U << CMP_CFG_CMPRF_Pos),  /*!< The comparison voltage of CMP is 4/16VDD   */
    CMP3_Negative_5D16CMP_VREF   = (uint16_t)(0x05U << CMP_CFG_CMPRF_Pos),  /*!< The comparison voltage of CMP is 5/16VDD   */
    CMP3_Negative_6D16CMP_VREF   = (uint16_t)(0x06U << CMP_CFG_CMPRF_Pos),  /*!< The comparison voltage of CMP is 6/16VDD   */
    CMP3_Negative_7D16CMP_VREF   = (uint16_t)(0x07U << CMP_CFG_CMPRF_Pos),  /*!< The comparison voltage of CMP is 7/16VDD   */
    CMP3_Negative_8D16CMP_VREF   = (uint16_t)(0x08U << CMP_CFG_CMPRF_Pos),  /*!< The comparison voltage of CMP is 8/16VDD   */
    CMP3_Negative_9D16CMP_VREF   = (uint16_t)(0x09U << CMP_CFG_CMPRF_Pos),  /*!< The comparison voltage of CMP is 9/16VDD   */
    CMP3_Negative_10D16CMP_VREF  = (uint16_t)(0x0AU << CMP_CFG_CMPRF_Pos),  /*!< The comparison voltage of CMP is 10/16VDD   */
    CMP3_Negative_11D16CMP_VREF  = (uint16_t)(0x0BU << CMP_CFG_CMPRF_Pos),  /*!< The comparison voltage of CMP is 11/16VDD   */
    CMP3_Negative_12D16CMP_VREF  = (uint16_t)(0x0CU << CMP_CFG_CMPRF_Pos),  /*!< The comparison voltage of CMP is 12/16VDD   */
    CMP3_Negative_13D16CMP_VREF  = (uint16_t)(0x0DU << CMP_CFG_CMPRF_Pos),  /*!< The comparison voltage of CMP is 13/16VDD   */
    CMP3_Negative_14D16CMP_VREF  = (uint16_t)(0x0EU << CMP_CFG_CMPRF_Pos),  /*!< The comparison voltage of CMP is 14/16VDD   */
    CMP3_Negative_15D16CMP_VREF  = (uint16_t)(0x0FU << CMP_CFG_CMPRF_Pos),  /*!< The comparison voltage of CMP is 15/16VDD   */
} CMP_Negative_TypeDef;

#define IS_CMP_Negative(Negative) (((Negative) == CMP3_Negative_1D16CMP_VREF) || \
															((Negative) == CMP3_Negative_2D16CMP_VREF) || \
															((Negative) == CMP3_Negative_3D16CMP_VREF) || \
															((Negative) == CMP3_Negative_4D16CMP_VREF) || \
															((Negative) == CMP3_Negative_5D16CMP_VREF) || \
															((Negative) == CMP3_Negative_6D16CMP_VREF) || \
															((Negative) == CMP3_Negative_7D16CMP_VREF) || \
															((Negative) == CMP3_Negative_8D16CMP_VREF) || \
															((Negative) == CMP3_Negative_9D16CMP_VREF) || \
															((Negative) == CMP3_Negative_10D16CMP_VREF) || \
															((Negative) == CMP3_Negative_11D16CMP_VREF) || \
															((Negative) == CMP3_Negative_12D16CMP_VREF) || \
															((Negative) == CMP3_Negative_13D16CMP_VREF) || \
															((Negative) == CMP3_Negative_14D16CMP_VREF) || \
															((Negative) == CMP3_Negative_15D16CMP_VREF))
/** @defgroup CMP_TriggerMode_TypeDef CMP TriggerMode
 * @{
 */
typedef enum
{
	  CMP0_1_2TriggerMode_Disable   = (uint16_t)(0x00U << CMPX_CFG_CMPIM_Pos),    /*!< CMP0_1_2 the trigger mode is disable  */
    CMP0_1_2TriggerMode_RISE      = (uint16_t)(0x01U << CMPX_CFG_CMPIM_Pos),    /*!< CMP0_1_2 The trigger mode of the simulated comparator is rising edge  */
    CMP0_1_2TriggerMode_FALL      = (uint16_t)(0x02U << CMPX_CFG_CMPIM_Pos),    /*!< CMP0_1_2 The trigger mode of simulated comparator is falling edge   */
    CMP0_1_2TriggerMode_RISE_FALL = (uint16_t)(0x03U << CMPX_CFG_CMPIM_Pos),    /*!< CMP0_1_2 The trigger mode of the simulated comparator is rising edge and falling edge  */
    CMP3_TriggerMode_Disable   = (uint16_t)(0x00U << CMP_CFG_CMPIM_Pos),    /*!< CMP3 the trigger mode is disable  */
    CMP3_TriggerMode_RISE      = (uint16_t)(0x01U << CMP_CFG_CMPIM_Pos),    /*!< CMP3 The trigger mode of the simulated comparator is rising edge  */
    CMP3_TriggerMode_FALL      = (uint16_t)(0x02U << CMP_CFG_CMPIM_Pos),    /*!< CMP3 The trigger mode of simulated comparator is falling edge   */
    CMP3_TriggerMode_RISE_FALL = (uint16_t)(0x03U << CMP_CFG_CMPIM_Pos),    /*!< CMP3 The trigger mode of the simulated comparator is rising edge and falling edge  */
} CMP_TriggerMode_TypeDef;

#define IS_CMP_TRIGGER(TRIGGER) (((TRIGGER) == CMP0_1_2TriggerMode_Disable) || \
                                 ((TRIGGER) == CMP0_1_2TriggerMode_RISE) || \
                                 ((TRIGGER) == CMP0_1_2TriggerMode_FALL) || \
                                 ((TRIGGER) == CMP0_1_2TriggerMode_RISE_FALL)|| \
                                 ((TRIGGER) == CMP3_TriggerMode_Disable) || \
                                 ((TRIGGER) == CMP3_TriggerMode_RISE) || \
                                 ((TRIGGER) == CMP3_TriggerMode_FALL) || \
                                 ((TRIGGER) == CMP3_TriggerMode_RISE_FALL))
/** @defgroup CMP_HYS_TypeDef CMP HYS
 * @{
 */
typedef enum
{
    CMP_HYS_0mV		  = (uint32_t)(0x00 << CMP_CON_HYS_Pos), /*!< CMP_HYS_0mV: Hysteresis voltage selection CMP0_1_2HYS_0mV */
    CMP_HYS_5mV		  = (uint32_t)(0x01 << CMP_CON_HYS_Pos), /*!<  CMP_HYS_5mV: Hysteresis voltage selection CMP0_1_2HYS_5mV */
    CMP_HYS_10mV		  = (uint32_t)(0x02 << CMP_CON_HYS_Pos), /*!<  CMP_HYS_10mV: Hysteresis voltage selection CMP0_1_2HYS_10mV */
    CMP_HYS_20mV		  = (uint32_t)(0x03 << CMP_CON_HYS_Pos), /*!<  CMP_HYS_20mV: Hysteresis voltage selection CMP0_1_2HYS_20mV */
} CMP_HYS_TypeDef;

#define IS_CMP_HYS(HYS) (((HYS) == CMP0_1_2HYS_0mV) || \
                        ((HYS) == CMP0_1_2HYS_5mV)|| \
                        ((HYS) == CMP0_1_2HYS_10mV)|| \
                        ((HYS) == CMP0_1_2HYS_20mV)|| \
                        ((HYS) == CMP3_HYS_0mV) || \
                        ((HYS) == CMP3_HYS_5mV)|| \
                        ((HYS) == CMP3_HYS_10mV)|| \
                        ((HYS) == CMP3_HYS_20mV))
/**
 * @}
 */
/** @defgroup CMP_IT CMP Interrupt
 * @{
 */
typedef enum
{
    CMP0_1_2IT_INT    = (uint8_t) CMP_IDE_INTEN,      /*!< CMP0_1_2 Interrupt: CMP0_1_2 Interrupt */
    CMP0_1_2IT_CMP0   = (uint8_t)CMP_IDE_CMP0IE,   /*!< CMP0 Interrupt: CMP0 Interrupt */
    CMP0_1_2IT_CMP1   = (uint8_t)CMP_IDE_CMP1IE,   /*!< CMP1 Interrupt: CMP1  Interrupt */
    CMP0_1_2IT_CMP2   = (uint8_t)CMP_IDE_CMP2IE,   /*!< CMP2 Interrupt: CMP2 Interrupt */
    CMP3_IT_INT    = (uint8_t)CMP_IDE_INTEN,        /*!< CMP3 Interrupt: CMP3 Interrupt */
} CMP_IT_TypeDef;

#define IS_CMP_IT(IT) (((IT) == CMP0_1_2IT_INT) || \
                       ((IT) == CMP0_1_2IT_CMP0) || \
                       ((IT) == CMP0_1_2IT_CMP1) || \
                       ((IT) == CMP0_1_2IT_CMP2) || \
                       ((IT) == CMP3_IT_INT))
/**
 * @}
 */

/** @defgroup CMP_FLAG CMP Flag
 * @{
 */
typedef enum
{
    CMP_FLAG_CMP0    = (uint8_t)CMP_STS_CMP0IF,     /*!< CMP0 Flag: CMP0 flag */
    CMP_FLAG_CMP1    = (uint8_t)CMP_STS_CMP1IF,     /*!< CMP1 Flag: CMP1 flag */
    CMP_FLAG_CMP2    = (uint8_t)CMP_STS_CMP2IF,     /*!< CMP2 Flag: CMP2 flag */
    CMP_FLAG_CMP3    = (uint8_t)CMP_STS_CMP3IF,     /*!< CMP  Flag: Interrupt flag */

} CMP_FLAG_TypeDef;

#define IS_CMP_FLAG(FLAG) (((FLAG) == CMP_FLAG_CMP0) ||\
                            ((FLAG) == CMP_FLAG_CMP1)||\
                            ((FLAG) == CMP_FLAG_CMP2)||\
                            ((FLAG) == CMP_FLAG_CMP3))
/** @defgroup CMP_CMPSTA CMP CMPSTA
 * @{
 */
typedef enum
{
  CMP_CMP0STA_Low		= (uint32_t)(0x00 << CMP_STS_CMP0STA_Pos), /*!<  The non-inverting input is at a lower voltage than the inverting input */
  CMP_CMP0STA_High		= (uint32_t)(0x01 << CMP_STS_CMP0STA_Pos), /*!<The non-inverting input is at a higher voltage than the inverting input */
  CMP_CMP1STA_Low		= (uint32_t)(0x00 << CMP_STS_CMP1STA_Pos), /*!<The non-inverting input is at a lower voltage than the inverting input */
  CMP_CMP1STA_High		= (uint32_t)(0x01 << CMP_STS_CMP1STA_Pos), /*!<The non-inverting input is at a higher voltage than the inverting input */
  CMP_CMP2STA_Low		= (uint32_t)(0x00 << CMP_STS_CMP2STA_Pos), /*!< The non-inverting input is at a lower voltage than the inverting input */
  CMP_CMP2STA_High		= (uint32_t)(0x01 << CMP_STS_CMP2STA_Pos), /*!<The non-inverting input is at a higher voltage than the inverting input */
  CMP_CMP3STA_Low		= (uint32_t)(0x00 << CMP_STS_CMP3STA_Pos), /*!< CMP3 positive terminal voltage is less than the negative terminal voltage */
  CMP_CMP3STA_High		= (uint32_t)(0x01 << CMP_STS_CMP3STA_Pos), /*!<  The positive terminal voltage of CMP3 is greater than the negative terminal voltage */
} CMP_CMPSTA_TypeDef;

#define IS_CMP_CMPSTA(STA) (((STA) == CMP_CMP0STA_Low) || \
                           ((STA) == CMP_CMP0STA_High) || \
                           ((STA) == CMP_CMP1STA_Low) || \
                           ((STA) == CMP_CMP1STA_High)|| \
                           ((STA) == CMP_CMP2STA_Low) || \
                           ((STA) == CMP_CMP2STA_High)|| \
                           ((STA) == CMP_CMP3STA_Low) || \
                           ((STA) == CMP_CMP3STA_High))
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

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/


#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
#define IS_CMP_ALL_PERIPH(PERIPH) ((PERIPH) == CMP)
#elif defined(SC32f15xx)
#define IS_CMP_ALL_PERIPH(PERIPH) (((PERIPH) == CMP_0) ||\
                                   ((PERIPH) == CMP_1) ||\
                                   ((PERIPH) == CMP_2) ||\
                                   ((PERIPH) == CMP3))
#endif																	 
/**
 * @}
 */
/* End of constants -----------------------------------------------------*/

/** @defgroup CMP_Exported_Struct CMP Exported Struct
 * @{
 */

/** @brief CMP Time base Configuration Structure definition
 * @{
 */
 #if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
typedef struct
{
    uint16_t CMP_Negative;   /*!< This member configures CMP NEGATIVE.
                                              This parameter can be a value of @ref CMP_Negative_TypeDef. */

    uint16_t CMP_Positive; /*!< This member configures CMP POSITIVE.
                                              This parameter can be a value of @ref CMP_Positive_TypeDef. */

    uint16_t CMP_TriggerMode; /*!< This member configures CMPTRIGGER.
                                              This parameter can be a value of @ref CMP_TriggerMode_TypeDef. */

} CMP_InitTypeDef;
#elif defined(SC32f15xx)
/** @defgroup CMP  base Configuration Structure definition
 * @{
 */
typedef struct
{
    uint16_t CMP_Negative;   /*!< This member configures CMP NEGATIVE.
                                              This parameter can be a value of @ref CMP_Negative_TypeDef. */

    uint16_t CMP_Positive; /*!< This member configures CMP POSITIVE.
                                              This parameter can be a value of @ref CMP_Positive_TypeDef. */

    uint16_t CMP_VREF; /*!< This member configures CMP VREF.
                                              This parameter can be a value of @ref CMP_VREF_TypeDef. */

    uint16_t CMP_CMPRF; /*!< This member configures CMP CMPRF.
                                              This parameter can be a value of @ref CMP_CMPRF_TypeDef. */

    uint16_t CMP_TriggerMode; /*!< This member configures TriggerMode.
                                              This parameter can be a value of @ref CMP_TriggerMode_TypeDef. */

    uint16_t CMP_HYS; /*!< This member configures CMP HYS.
                                              This parameter can be a value of @ref CMP_HYS_TypeDef. */
} CMP_InitTypeDef;
#endif
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @addtogroup CMP_Functions CMP Functions
 * @{
 */
/* CMP Base functions ********************************************************/
void CMP_DeInit ( CMP_TypeDef* CMPx );
void CMP_Init ( CMP_TypeDef* CMPx, CMP_InitTypeDef* CMP_InitStruct );
void CMP_StructInit ( CMP_InitTypeDef* CMP_InitStruct );
void CMP_Cmd ( CMP_TypeDef* CMPx, FunctionalState NewState );
void CMP_SetNegativeChannel ( CMP_TypeDef* CMPx, CMP_Negative_TypeDef CMP_Negative_Channel );
CMP_Negative_TypeDef CMP_GetNegativeChannel ( CMP_TypeDef* CMPx );
void CMP_SetPositiveChannel ( CMP_TypeDef* CMPx, CMP_Positive_TypeDef CMP_Positive_Channel );
CMP_Positive_TypeDef CMP_GetPositiveChannel ( CMP_TypeDef* CMPx );
/* Interrupts and flags management functions  **********************************************/
CMP_CMPSTA_TypeDef CMP_GetCMPSTA ( CMP_TypeDef* CMPx );
FlagStatus CMP_GetFlagStatus ( CMP_TypeDef* CMPx, CMP_FLAG_TypeDef CMP_FLAG );
void CMP_ClearFlag ( CMP_TypeDef* CMPx, CMP_FLAG_TypeDef CMP_FLAG );
#if  defined(SC32f15xx)
void CMP_NegativeSelection(CMP_TypeDef* CMPx, CMP_NegativeSelect_TypeDef NegativeSelect);
CMP_NegativeSelect_TypeDef CMP_GetNegativeSelection(CMP_TypeDef* CMPx);
void CMP_ITConfig(CMP_TypeDef* CMPx, uint16_t CMP_IT, FunctionalState NewState);
#endif
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
