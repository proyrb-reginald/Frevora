/**
 ******************************************************************************
 * @file    sc32f15Gx_QEP.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   Header file of QEP module.
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
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __sc32f15Gx_QEP_H
#define __sc32f15Gx_QEP_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "sc32f15Gx.h"
#include "sc32.h"
#include "sc32f1xxx_rcc.h"

/** @addtogroup sc32f15Gx_StdPeriph_Driver
 * @{
 */

/** @addtogroup QEP
 * @{
 */

/* Exported enumerations ------------------------------------------------------------*/
/** @defgroup QEP_Exported_Enumerations QEP Exported Enumerations
 * @{
 */
 
  /** @defgroup QEP_Mode QEP Mode
 * @{
 */
typedef enum
{
  QEP_Mode_Orthogonal  = (uint32_t)(0x00U << QEP_CON_QSRC_Pos ),  /*!< Location count source selection: Orthogonal  */
  QEP_Mode_Direction   = (uint32_t)(0x01U << QEP_CON_QSRC_Pos ),  /*!< Location count source selection: Direction   */
  QEP_Mode_Dipulse     = (uint32_t)(0x02U << QEP_CON_QSRC_Pos ),  /*!< Location count source selectione: Dipulse     */
} QEP_Mode_TypeDef;

#define IS_QEP_MODE(MODE) (((MODE) == QEP_Mode_Orthogonal) || \
	                       ((MODE) == QEP_Mode_Direction) || \
                           ((MODE) == QEP_Mode_Dipulse))
/**
 * @}
 */
 
 /** @defgroup QEP_CEN Edge counting enable
 * @{
 */
typedef enum
{
  QEP_CEN_Default        = (uint32_t)0x00U,                            /*!< QEP Edge count: Default */
  QEP_CEN_Rising         = (uint32_t)(QEP_CON_RPCEN),                  /*!< QEP Edge count: The rising edge is enabled */
  QEP_CEN_Falling        = (uint32_t)(QEP_CON_FPCEN),                  /*!< QEP Edge count: The falling edge is enabled */
} QEP_CEN_TypeDef;

#define IS_QEP_CEN(CEN) (((CEN) == QEP_CEN_Default) || \
                         ((CEN) == QEP_CEN_Rising) || \
                         ((CEN) == QEP_CEN_Falling))
/**
 * @}
 */

 /** @defgroup QEP_PATE QEP Pin gating
 * @{
 */
typedef enum
{
  QEP_GATE_Default   = (uint32_t)0x00U,                                              /*!< QEP Pin: Default    */
  QEP_GATE_QA        = (uint32_t)(QEP_CON_QAGATE),                   /*!< QEP Pin: QEPnA Gating   */
  QEP_GATE_QB        = (uint32_t)(QEP_CON_QBGATE),                   /*!< QEP Pin: QEPnB Gating   */
  QEP_GATE_QI     = (uint32_t)(QEP_CON_IGATE),  /*!< QEP Pin: QEPnA and QEPnB Gating   */
} QEP_GATE_TypeDef;

#define IS_QEP_GATE(GATE) (((GATE) == QEP_GATE_Default) || \
                           ((GATE) == QEP_GATE_QA) || \
                           ((GATE) == QEP_GATE_QB) || \
                           ((GATE) == QEP_GATE_QI))
/**
 * @}
 */

/** @defgroup QEP_FilteringDIV QEP digital input filter clock division
 * @{
 */
typedef enum
{
  QEP_FilteringDIV_1   = (uint32_t)(0x00U << QEP_CON_QFDIV_Pos),  /*!< filter clock division: Fapb/1   */
  QEP_FilteringDIV_2   = (uint32_t)(0x01U << QEP_CON_QFDIV_Pos),  /*!< filter clock division: Fapb/2   */
  QEP_FilteringDIV_4   = (uint32_t)(0x02U << QEP_CON_QFDIV_Pos),  /*!< filter clock division: Fapb/4   */
  QEP_FilteringDIV_8   = (uint32_t)(0x03U << QEP_CON_QFDIV_Pos),  /*!< filter clock division: Fapb/8   */
  QEP_FilteringDIV_16  = (uint32_t)(0x04U << QEP_CON_QFDIV_Pos),  /*!< filter clock division: Fapb/16  */
  QEP_FilteringDIV_32  = (uint32_t)(0x05U << QEP_CON_QFDIV_Pos),  /*!< filter clock division: Fapb/32  */
  QEP_FilteringDIV_64  = (uint32_t)(0x06U << QEP_CON_QFDIV_Pos),  /*!< filter clock division: Fapb/64  */
  QEP_FilteringDIV_128 = (uint32_t)(0x07U << QEP_CON_QFDIV_Pos),  /*!< filter clock division: Fapb/128 */
} QEP_FilteringDIV_TypeDef;

#define IS_QEP_FILTERINGDIV(DIV) (((DIV) == QEP_FilteringDIV_1) || \
                                  ((DIV) == QEP_FilteringDIV_2) || \
                                  ((DIV) == QEP_FilteringDIV_4) || \
                                  ((DIV) == QEP_FilteringDIV_8) || \
                                  ((DIV) == QEP_FilteringDIV_16) || \
                                  ((DIV) == QEP_FilteringDIV_32) || \
                                  ((DIV) == QEP_FilteringDIV_64) || \
                                  ((DIV) == QEP_FilteringDIV_128))
/**
 * @}
 */

/** @defgroup QEP_Polarity QEP input Polarity
 * @{
 */
typedef enum
{
    QEP_Polarity_Positive  = (uint32_t)(0X00U),    /*!< QEP Polarity: Positive    */
    QEP_Polarity_Negative  = (uint32_t)(0X01U),    /*!< QEP Polarity: Negative   */
} QEP_Polarity_Typedef;

#define IS_QEP_POLARITY(POLARITY) (((POLARITY) == QEP_Polarity_Positive) ||  \
                                    ((POLARITY) == QEP_Polarity_Negative))
/**
 * @}
 */


/** @defgroup QEP_IndexMode QEP Index Mode
 * @{
 */
typedef enum
{
    QEP_IndexMode_Enable = (uint32_t)0x00<<QEP_CON_PCRM_Pos,   /*!< QEP PCRM: Index event    */
    QEP_IndexMode_Disable   = (uint32_t)0x01<<QEP_CON_PCRM_Pos,    /*!< QEP PCRM: Counter overflow    */
	
} QEP_IndexMode_Typedef;

#define IS_QEP_IndexMode(IndexMode) (((IndexMode) == QEP_Index_Enable) ||  \
                                ((IndexMode) == QEP_Index_Disable) )

/** @defgroup QEP_QEPnI QEP QEPnI Mode
 * @{
 */
typedef enum
{
    QEP_QEPnI_Forward = (uint32_t)0x00<<QEP_CON_QIP_Pos,   /*!< QEP QEPnI direction Index event    */
    QEP_QEPnI_Reverse   = (uint32_t)0x01<<QEP_CON_QIP_Pos,    /*!< QEP QEPnI direction Counter overflow    */
} QEP_QEPnI_Typedef;

#define IS_QEP_QEPnI(INDEX) (((QEPnI) == QEP_QEPnI_Forward) ||  \
                                ((QEPnI) == QEP_QEPnI_Reverse) )
/** @defgroup QEP_SWAP QEP Swap orthogonal input directions
 * @{
 */
typedef enum
{
  QEP_SWAP_Default  = (uint32_t)(0X00U << QEP_CON_SWAP_Pos),   /*!< QEP input directions: Orthogonal clock inputs are not swap    */
  QEP_SWAP_Exchange = (uint32_t)(0X01U << QEP_CON_SWAP_Pos),   /*!< QEP input directions: Orthogonal clock inputs are swap    */
} QEP_SWAP_Typedef;

#define IS_QEP_SWAP(SWAP) (((SWAP) == QEP_SWAP_Default) ||  \
                           ((SWAP) == QEP_SWAP_Exchange))
/**
 * @}
 */

/** @defgroup QEP_PinRemap QEP Pin Remap
 * @{
 */
typedef enum
{
    QEP_PinRemap_Default = (uint32_t)(0x00 << QEP_CON_SPOS_Pos),  /*!< QEP Pin Remap: Disable */
    QEP_PinRemap_A       = (uint32_t)(0x01 << QEP_CON_SPOS_Pos),  /*!< QEP Pin Remap: Remap mode A */
} QEP_PinRemap_TypeDef;

#define IS_QEP_PINREMAP(PINREMAP) (((PINREMAP) == QEP_PinRemap_Default) ||  \
                                   ((PINREMAP) == QEP_PinRemap_Enable))
/**
 * @}
 */

/** @defgroup QEP_IT QEP Interrupt
 * @{
 */
typedef enum
{
  QEP_IT_INT     = (uint8_t)QEP_IDE_INTEN, /*!< QEP Interrupt: QEP Interrupt */
  QEP_IT_PCU    = (uint8_t)QEP_IDE_PCUIE, /*!< QEP Interrupt: Location counter underflow interrupt */
  QEP_IT_PCO    = (uint8_t)QEP_IDE_PCOIE, /*!< QEP Interrupt: Location counter overflow interrupt */
  QEP_IT_IER    = (uint8_t)QEP_IDE_IERIE, /*!<Index event reset interrupt */
  QEP_IT_UPEVNT = (uint8_t)QEP_IDE_UPEVNTIE, /*!< Unit location event */
} QEP_IT_TypeDef;

#define IS_QEP_IT(IT) ((((IT) & (uint8_t)0xE0) == 0x00) && ((IT) != 0x00))
/**
 * @}
 */

/** @defgroup QEP_FLAG QEP Flag
 * @{
 */
typedef enum
{
  QEP_Flag_PCU    = (uint8_t)QEP_STS_PCUIF,     /*!< QEP Flag:Location counter underflow interrupted flag*/
  QEP_Flag_PCO    = (uint8_t)QEP_STS_PCOIF,     /*!< QEP Flag:Location counter overflow interrupt flag */
  QEP_Flag_IER    = (uint8_t)QEP_STS_IERIF,     /*!< QEP Flag: Index event reset interrupt flag */
  QEP_Flag_UPEVNT = (uint8_t)QEP_STS_UPEVNTIF,  /*!< QEP Flag: Unit location event flag */
  QEP_Flag_DQ     = (uint8_t)QEP_STS_DQIF,      /*!< QEP Flag: Orthogonal direction flag */
} QEP_FLAG_TypeDef;

#define IS_QEP_FLAG(FLAG) ((((FLAG) & (uint8_t)0xE0) == 0x00) && ((FLAG) != 0x00))

#define IS_GET_QEP_FLAG(FLAG) (((FLAG) == QEP_Flag_PCU) || \
                               ((FLAG) == QEP_Flag_PCO) || \
                               ((FLAG) == QEP_Flag_IER) || \
                               ((FLAG) == QEP_Flag_UPEVNT) || \
                               ((FLAG) == QEP_Flag_DQ))
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @defgroup QEP_Constants QEP Constants
  * @{
  */

#define IS_QEP_ALL_PERIPH(PERIPH) (((PERIPH) == QEP0) || \
                                   ((PERIPH) == QEP1))

#define IS_QEP_REMAP_PERIPH(PERIPH) ((PERIPH) == QEP1)

/**
 * @}
 */
/* End of constants -----------------------------------------------------*/

/** @defgroup QEP Time base Configuration Structure definition
 * @{
 */
typedef struct
{
  uint32_t QEP_Mode; /*!<   This member configures QEP Mode.
																				This parameter can be a value of @ref QEP_Mode_TypeDef */

  uint32_t QEP_GATE; /*!<  This member configures QEP GATE.
											This parameter can be a value of @ref QEP_GATE_TypeDef */

  uint32_t QEP_CEN; /*!<  This member configures QEP CEN.
											This parameter can be a value of @ref QEP_CEN_TypeDef. */

  uint32_t QEP_QFDIV; /*!< Specifies the digital input filter clock division.
																						This parameter can be a value of @ref QEP_FilteringDIV_TypeDef */

  uint32_t QEP_QAP; /*!< Specifies the QEPnA input polarity.
																						This parameter can be a value of @ref QEP_Polarity_Typedef */

  uint32_t QEP_QBP; /*!< Specifies the QEPnB input polarity.
																						This parameter can be a value of @ref QEP_Polarity_Typedef */

  uint32_t QEP_IndexMode; /*!< Specifies the rest mode.
																						This parameter can be a value of @ref QEP_IndexMode_Typedef */
	
	uint32_t QEP_QEPnI; /*!<  This member configures QEP QEPnI.
																						This parameter can be a value of @ref QEP_QEPnI_Typedef */
																						
  uint32_t QEP_SWAP; /*!<  This member configures QEP SWAP.
																						This parameter can be a value of @ref QEP_SWAP_Typedef */

  uint32_t QEP_PMAX; /*!<  This member configures QEP maxCnt.*/
} QEP_InitTypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of exported enumerations -----------------------------------------------------*/

/** @addtogroup QEP_Functions QEP Functions
 * @{
 */

/* QEP Base functions ********************************************************/
void QEP_DeInit(QEP_TypeDef* QEPx);
void QEP_Init(QEP_TypeDef* QEPx, QEP_InitTypeDef* QEP_InitStruct);
void QEP_StructInit(QEP_InitTypeDef* QEP_InitStruct);
void QEP_Cmd(QEP_TypeDef* QEPx, FunctionalState NewState);
void QEP_QEPnICmd(QEP_TypeDef* QEPx, FunctionalState NewState);
void QEP_QSRCModeSelect(QEP_TypeDef* QEPx, QEP_Mode_TypeDef QEP_Mode);
void QEP_QFDIVSelect(QEP_TypeDef* QEPx, QEP_FilteringDIV_TypeDef QEP_FilteringDIV);
void QEP_CountSelect(QEP_TypeDef* QEPx, QEP_CEN_TypeDef QEP_CEN);
void QEP_SetCnt(QEP_TypeDef* QEPx,uint16_t QEP_CountValue);
uint16_t QEP_GetCnt(QEP_TypeDef* QEPx);
void QEP_SetPmax(QEP_TypeDef* QEPx,uint16_t QEP_PmaxValue);
uint16_t QEP_GetPmax(QEP_TypeDef* QEPx);
/* Pin remap management functions  **********************************************/
void QEP_PinRemapConfig(QEP_TypeDef* QEPx, QEP_PinRemap_TypeDef QEP_Remap);

/* Interrupts, QEP and flags management functions  **********************************************/
void QEP_ITConfig(QEP_TypeDef* QEPx, uint16_t QEP_IT, FunctionalState NewState);
FlagStatus QEP_GetFlagStatus(QEP_TypeDef* QEPx, uint16_t QEP_FLAG);
void QEP_ClearFlag(QEP_TypeDef* QEPx, uint16_t QEP_FLAG);

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
