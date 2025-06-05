/**
 ******************************************************************************
 * @file    sc32f1xxx_qep.c
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   QEP function module
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
#if defined (SC32f15xx)
#include "sc32f1xxx_qep.h"


/** @defgroup QEP_Exported_Functions_Group1 Configuration of the QEP computation unit functions
 *  @brief   Configuration of the QEP computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### QEP configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitializes the QEP peripheral
 * @param  QEPx[out]:where x only can be 0 or 1 to select QEP peripherals.
 *               - QEPQ0: select the PCAP peripheral
 *               - QEP1: select the PCAP peripheral
 * @retval None
 */
void QEP_DeInit(QEP_TypeDef* QEPx)
{
    /* Check the parameters */
    assert_param(IS_QEP_ALL_PERIPH(QEPx));

    QEPx->QEP_CON  = (uint32_t)0x00000000U;
    QEPx->QEP_PCNT = (uint32_t)0x00000000U;
    QEPx->QEP_PMAX = (uint32_t)0x00000000U;
    QEPx->QEP_STS  = (uint32_t)0x0000000FU;
    QEPx->QEP_IDE  = (uint32_t)0x00000000U;
}

/**
 * @brief  Initializes the QEP peripheral
 * @param  QEPx[out]:where x only can be 0 or 1 to select QEP peripherals.
 *               - QEPQ0: select the PCAP peripheral
 *               - QEP1: select the PCAP peripheral
 *         QEP_InitStruct[out]: Pointer to structure QEP_InitTypeDef, to be initialized.
 * @retval None
 */
void QEP_Init(QEP_TypeDef* QEPx, QEP_InitTypeDef* QEP_InitStruct)
{
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param(IS_QEP_ALL_PERIPH(QEPx));
    assert_param(IS_QEP_CEN(QEP_InitStruct->QEP_CEN));
    assert_param(IS_QEP_GATE(QEP_InitStruct->QEP_GATE));
    assert_param(IS_QEP_FILTERINGDIV(QEP_InitStruct->QEP_QFDIV));
    assert_param(IS_QEP_POLARITY(QEP_InitStruct->QEP_QAP));
    assert_param(IS_QEP_POLARITY(QEP_InitStruct->QEP_QBP));
    assert_param(IS_QEP_SWAP(QEP_InitStruct->QEP_SWAP));

    tmpreg = QEPx->QEP_CON;
    tmpreg &= ~(QEP_CON_QSRC | QEP_CON_RPCEN | QEP_CON_FPCEN|QEP_CON_QIP
              | QEP_CON_QAGATE | QEP_CON_QBGATE | QEP_CON_IGATE | QEP_CON_QFDIV
              | QEP_CON_QAP | QEP_CON_QBP | QEP_CON_PCRM | QEP_CON_SWAP);

    tmpreg |= (QEP_InitStruct->QEP_Mode | QEP_InitStruct->QEP_CEN | QEP_InitStruct->QEP_GATE |
              QEP_InitStruct->QEP_QFDIV | QEP_InitStruct->QEP_IndexMode | QEP_InitStruct->QEP_QEPnI|
	            QEP_InitStruct->QEP_SWAP);

    tmpreg |= (QEP_InitStruct->QEP_QAP << QEP_CON_QAP_Pos) | (QEP_InitStruct->QEP_QBP << QEP_CON_QBP_Pos);

    QEPx->QEP_CON = tmpreg;

    QEPx->QEP_PMAX = QEP_InitStruct->QEP_PMAX;

}

/**
  * @brief  Fills each QEP_InitStruct member with its default value.
  * @param  QEP_InitStruct[out]: pointer to a QEP_InitTypeDef structure which will be initialized.
  * @retval None
  */
void QEP_StructInit(QEP_InitTypeDef* QEP_InitStruct)
{
    /* Check the parameters */

    QEP_InitStruct->QEP_Mode     = QEP_Mode_Orthogonal;
    QEP_InitStruct->QEP_CEN      = QEP_CEN_Default;
    QEP_InitStruct->QEP_GATE     = QEP_GATE_Default;
    QEP_InitStruct->QEP_QFDIV    = QEP_FilteringDIV_1;
    QEP_InitStruct->QEP_QAP      = QEP_Polarity_Positive;
    QEP_InitStruct->QEP_QBP      = QEP_Polarity_Positive;
    QEP_InitStruct->QEP_IndexMode = QEP_IndexMode_Disable;
    QEP_InitStruct->QEP_SWAP     = QEP_SWAP_Default;
	  QEP_InitStruct->QEP_QEPnI    = QEP_QEPnI_Forward;

}

/**
 * @brief  Enables or disables the specified QEP peripheral.
 * @param  QEPx[out]:where x only can be 0 or 1 to select QEP peripherals.
 *               - QEPQ0: select the PCAP peripheral
 *               - QEP1: select the PCAP peripheral
 * @param  NewState[in]: new state of the QEPx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable  
 * @retval None
 */
void QEP_Cmd(QEP_TypeDef* QEPx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_QEP_ALL_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if(NewState != DISABLE)
    {
    /* Enable the QEP Counter */
    QEPx->QEP_CON |= QEP_CON_QEPEN;
    }
    else
    {
    /* Disable the QEP Counter */
    QEPx->QEP_CON &= (uint32_t)~QEP_CON_QEPEN;
    }
}

/**
 * @brief  Enables or disables the QEPnI gate.
 * @param  QEPx[out]:where x only can be 0 or 1 to select QEP peripherals.
 *               - QEPQ0: select the PCAP peripheral
 *               - QEP1: select the PCAP peripheral
 * @param  NewState[in]: new state of the QEPx QEPnI.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable  
 * @retval None
 */
void QEP_QEPnICmd(QEP_TypeDef* QEPx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_QEP_ALL_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if(NewState != DISABLE)
    {
    /* Enable the QEP Counter */
    QEPx->QEP_CON |= QEP_CON_IGATE;
    }
    else
    {
    /* Disable the QEP Counter */
    QEPx->QEP_CON &= (uint32_t)~QEP_CON_IGATE;
    }
}

/**
 * @brief  Location count source selection.
 * @param  QEPx[out]:where x only can be 0 or 1 to select QEP peripherals.
 *               - QEPQ0: select the PCAP peripheral
 *               - QEP1: select the PCAP peripheral
 * @param  QEP_Mode[in]: new state of the QEPx QEPnI.
 *               - QEP_Mode_Orthogonal:Location count source selection Orthogonal 
 *               - QEP_Mode_Direction:Location count source selection: Direction  
 *               - QEP_Mode_Dipulse:Location count source selectione: Dipulse  
 * @retval None
 */
void QEP_QSRCModeSelect(QEP_TypeDef* QEPx, QEP_Mode_TypeDef QEP_Mode)
{
  /* Check the parameters */
  assert_param(IS_QEP_ALL_PERIPH(QEPx));

    QEPx->QEP_CON &= ~QEP_CON_QSRC;
    /* Enable the Interrupt sources */
    QEPx->QEP_CON |= QEP_Mode;
 
}
/**
 * @brief  Digital input filter filter width selection.
 * @param  QEPx[out]:where x only can be 0 or 1 to select QEP peripherals.
 *               - QEPQ0: select the PCAP peripheral
 *               - QEP1: select the PCAP peripheral
 * @param  QEP_FilteringDIV[in]:  Digital input filter filter width.
 *               - QEP_FilteringDIV_1:filter clock division: Fapb/1  
 *               - QEP_FilteringDIV_2:filter clock division: Fapb/2   
 *               - QEP_FilteringDIV_4:filter clock division: Fapb/4   
 *               - QEP_FilteringDIV_8:filter clock division: Fapb/8   
 *               - QEP_FilteringDIV_16:filter clock division: Fapb/16  
 *               - QEP_FilteringDIV_32:filter clock division: Fapb/32  
 *               - QEP_FilteringDIV_64:filter clock division: Fapb/64  
 *               - QEP_FilteringDIV_128:filter clock division: Fapb/128  
 * @retval None
 */
void QEP_QFDIVSelect(QEP_TypeDef* QEPx, QEP_FilteringDIV_TypeDef QEP_FilteringDIV)
{
  /* Check the parameters */
  assert_param(IS_QEP_ALL_PERIPH(QEPx));

    QEPx->QEP_CON &= ~QEP_CON_QFDIV;
    /* Enable the Interrupt sources */
    QEPx->QEP_CON |= QEP_FilteringDIV;
 
}

/**
 * @brief  QEP count mode selection.
 * @param  QEPx[out]:where x only can be 0 or 1 to select QEP peripherals.
 *               - QEPQ0: select the PCAP peripheral
 *               - QEP1: select the PCAP peripheral
 * @param  QEP_CEN[in]:  Digital input filter filter width.
 *               - QEP_CEN_Default:QEP Edge count: Default
 *               - QEP_CEN_Rising:QEP Edge count: The rising edge is enabled 
 *               - QEP_CEN_Falling:QEP Edge count: The falling edge is enabled 
 * @retval None
 */
void QEP_CountSelect(QEP_TypeDef* QEPx, QEP_CEN_TypeDef QEP_CEN)
{
  /* Check the parameters */
  assert_param(IS_QEP_ALL_PERIPH(QEPx));

    QEPx->QEP_CON &= ~(QEP_CON_RPCEN | QEP_CON_FPCEN);
    /* Enable the Interrupt sources */
    QEPx->QEP_CON |= QEP_CEN;
 
}
/**
 * @brief  Set the QEP Count value.
 * @param  QEPx[out]:where x only can be 0 or 1 to select QEP peripherals.
 *               - QEPQ0: select the PCAP peripheral
 *               - QEP1: select the PCAP peripheral
 * @param QEP_CountValue:QEP Count Value
 * @retval None
 */
void QEP_SetCnt(QEP_TypeDef* QEPx,uint16_t QEP_CountValue)
{
    /* Check the parameters */
    assert_param(IS_QEP_ALL_PERIPH(QEPx));

    QEPx->QEP_PCNT = QEP_CountValue;
}

/**
 * @brief  Gets the QEP Count value.
 * @param  QEPx[out]:where x only can be 0 or 1 to select QEP peripherals.
 *               - QEPQ0: select the PCAP peripheral
 *               - QEP1: select the PCAP peripheral
 * @retval QEP Count value
 */
uint16_t QEP_GetCnt(QEP_TypeDef* QEPx)
{
  /* Check the parameters */
  assert_param(IS_QEP_ALL_PERIPH(QEPx));

  return QEPx->QEP_PCNT;
}

/**
 * @brief  Set PCAP position counter maximum value.
 * @param  QEPx[out]:where x only can be 0 or 1 to select QEP peripherals.
 *               - QEPQ0: select the PCAP peripheral
 *               - QEP1: select the PCAP peripheral
 * @param QEP_PmaxValue:PCAP position counter Maximum value
 * @retval None
 */
void QEP_SetPmax(QEP_TypeDef* QEPx,uint16_t QEP_PmaxValue)
{
    /* Check the parameters */
    assert_param(IS_QEP_ALL_PERIPH(QEPx));

    QEPx->QEP_PMAX = QEP_PmaxValue;
}

/**
 * @brief  Gets PCAP position counter maximum value.
 * @param  QEPx[out]:where x only can be 0 or 1 to select QEP peripherals.
 *               - QEPQ0: select the PCAP peripheral
 *               - QEP1: select the PCAP peripheral
 * @retval PCAP position counter maximum value
 */
uint16_t QEP_GetPmax(QEP_TypeDef* QEPx)
{
  /* Check the parameters */
  assert_param(IS_QEP_ALL_PERIPH(QEPx));

  return QEPx->QEP_PMAX;
}
/**
 * @}
 */
/* End of QEP_Group1.	*/


/** @defgroup QEP_Group2 Pin remap management functions
 *  @brief  Pin remap management functions
 *
@verbatim
 ===============================================================================
                     ##### Pin remap management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  Configure the remapping of QEPx pins
 * @param  QEPx[out]: x only can be 1 to select QEP peripherals.
 *               - QEP1: select the PCAP peripheral
 * @param  QEP_Remap[in]: QEPx pin selection.
 *               - QEP_PinRemap_Default :QEP Pin Remap: Disable 
 *               - QEP_PinRemap_A:QEP Pin Remap: Remap mode A 
 *         
 * @retval None
 */
void QEP_PinRemapConfig(QEP_TypeDef* QEPx, QEP_PinRemap_TypeDef QEP_Remap)
{
    /* Check the parameters */
    assert_param(IS_QEP_REMAP_PERIPH(QEPx));
    
	  QEP1->QEP_CON &= ~QEP_CON_SPOS;
    QEP1->QEP_CON |= QEP_Remap;
}


/**
 * @}
 */
/* End of QEP_Group2.	*/


/** @defgroup QEP_Group3 Interrupts, DMA and flags management functions
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
 * @brief  Enables or disables the specified QEP interrupts.
 * @param  QEPx[out]:where x only can be 0 or 1 to select QEP peripherals.
 *               - QEPQ0: select the PCAP peripheral
 *               - QEP1: select the PCAP peripheral
 * @param  QEP_IT[in]: specifies the QEP interrupts sources to be enabled or disabled.
 *               - QEP_IT_INT: QEP Interrupt 
 *               - QEP_IT_PCU: Location counter underflow interrupt 
 *               - QEP_IT_PCO: Location counter overflow interrupt 
 *               - QEP_IT_IER :event reset interrupt 
 *               - QEP_IT_UPEVNT: location event interrupt
 * @param  NewState[in]: new state of the QEP interrupts.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable  
 * @retval None
 */
void QEP_ITConfig(QEP_TypeDef* QEPx, uint16_t QEP_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_QEP_ALL_PERIPH(QEPx));
  assert_param(IS_QEP_IT(QEP_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if(NewState != DISABLE)
  {
    /* Enable the Interrupt sources */
    QEPx->QEP_IDE |= QEP_IT;
  }
  else
  {
    /* Disable the Interrupt sources */
    QEPx->QEP_IDE &= (uint32_t)~QEP_IT;
  }
}

/**
 * @brief  Checks whether the specified QEP flag is set or not.
 * @param  QEPx[out]:where x only can be 0 or 1 to select QEP peripherals.
 *               - QEPQ0: select the PCAP peripheral
 *               - QEP1: select the PCAP peripheral
 * @param  QEP_FLAG[in]: specifies the flag to check.
 *               - QEP_Flag_PCU:Location counter underflow interrupted flag
 *               - QEP_Flag_PCO:Location counter overflow interrupt flag 
 *               - QEP_Flag_IER: Index event reset interrupt flag 
 *               - QEP_Flag_UPEVNT: Unit location event flag 
 *               - QEP_Flag_DQ: Orthogonal direction flag 
 * @retval The new state of QEP_FLAG (SET or RESET).
 *                  -  RESET:Flag reset
 *                  -  SET :Flag up
 */
FlagStatus QEP_GetFlagStatus(QEP_TypeDef* QEPx, uint16_t QEP_FLAG)
{
  ITStatus bitstatus = RESET;
  /* Check the parameters */
  assert_param(IS_QEP_ALL_PERIPH(QEPx));
  assert_param(IS_GET_QEP_FLAG(QEP_FLAG));

  if((QEPx->QEP_STS & QEP_FLAG) != (uint16_t)RESET)
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  return bitstatus;
}

/**
 * @brief  Clears the QEPx's pending flags.
 * @param  QEPx[out]:where x only can be 0 or 1 to select QEP peripherals.
 *               - QEPQ0: select the PCAP peripheral
 *               - QEP1: select the PCAP peripheral
 * @param  QEP_FLAG: specifies the flag bit to clear.
 *               - QEP_Flag_PCU:Location counter underflow interrupted flag
 *               - QEP_Flag_PCO:Location counter overflow interrupt flag 
 *               - QEP_Flag_IER: Index event reset interrupt flag 
 *               - QEP_Flag_UPEVNT: Unit location event flag 
 *               - QEP_Flag_DQ: Orthogonal direction flag 
 * @retval None
 */
void QEP_ClearFlag(QEP_TypeDef* QEPx, uint16_t QEP_FLAG)
{
  /* Check the parameters */
  assert_param(IS_QEP_ALL_PERIPH(QEPx));

  /* Clear the flags */
  QEPx->QEP_STS = (uint16_t)QEP_FLAG;
}
#endif
/**
 * @}
 */
/* End of QEP_Group3.	*/

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

