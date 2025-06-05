/**
 ******************************************************************************
 * @file    sc32f1xxx_spi.c
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief  SPI1_TWI1 function module
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
#include "sc32f1xxx_spi1_twi1.h"


/** @defgroup spi1_twi1_Group1 Configuration of the spi1_twi1 computation unit functions
 *  @brief   Configuration of the spi1_twi1 computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### spi1_twi1 configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitialize the SPIx peripheral registers to their default reset values.
 * @param  SPIx_TWIx[out]:where x can be select the SPIx or TWIx  peripheral.  
 *           - SPI1: select the SPI1 peripheral.
 *           - TWI1: select the TWI1 peripheral.

 * @retval None
 */
void SPI1_TWI1_DeInit(SPITWI_TypeDef* SPIx_TWIx)
{
 

    /* Enable SPI0 reset state */
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_SPI1_TWI1, ENABLE);
    /* Release SPI0 from reset state */
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_SPI1_TWI1, DISABLE);

}

/**
  * @brief  Fills each SPI_InitStruct member with its default value.
  * @param  SPI1_InitStruct[out]: Pointer to structure SPI1_InitTypeDef, to be initialized. 
  * @retval None
  */
void SPI1_StructInit(SPI1_InitTypeDef* SPI1_InitStruct)
{
  /* Set the default configuration */
  SPI1_InitStruct->SPI1_Mode = SPI1_Mode_Slave;
  SPI1_InitStruct->SPI1_DataSize = SPI1_DataSize_8B;
  SPI1_InitStruct->SPI1_FirstBit = SPI1_FirstBit_LSB;
  SPI1_InitStruct->SPI1_CPHA = SPI1_CPHA_1Edge;
  SPI1_InitStruct->SPI1_CPOL = SPI1_CPOL_Low;
  SPI1_InitStruct->SPI1_Prescaler = SPI1_TWI1_Prescaler_4;
}


/**
 * @brief  Initializes the peripheral SPIx register with the parameters specified in SPI_InitStruct
 * @param  SPIx[out]:where can to select the SPI1 peripheral.  
 *           - SPI1: select the SPI1 peripheral.
  * @param  SPI1_InitStruct[out]: Pointer to structure SPI1_InitTypeDef, to be initialized. 
 * @retval None
 */
void SPI1_Init(SPITWI_TypeDef* SPIx, SPI1_InitTypeDef* SPI1_InitStruct)
{

  uint32_t tmpreg;
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(SPIx));
  assert_param(IS_SPI1_Mode(SPI1_InitStruct->SPI1_Mode));
  assert_param(IS_SPI1_DATASIZE(SPI1_InitStruct->SPI1_DataSize));
  assert_param(IS_SPI1_CPHA(SPI1_InitStruct->SPI1_CPHA));
  assert_param(IS_SPI1_CPOL(SPI1_InitStruct->SPI1_CPOL));
  assert_param(IS_SPI1_TWI1_Prescaler(SPI1_InitStruct->SPI1_Prescaler));
  assert_param(IS_SPI1_FIRSTBIT(SPI1_InitStruct->SPI1_FirstBit));
 if(SPIx==SPITWI_SPI1)
 {
  /*---------------------------- SPIx SPI1_CON Configuration ------------------------*/
  /* Get the SPIx SPI0_CON value */
  tmpreg = SPITWI_TWI1->SPI1_TWI1_CON;
  /* Clear MSTR, SPMD, DORD, CPOL, SPR bits */
  tmpreg &= (uint32_t) ~(SPI1_CON_MSTR | SPI1_CON_SPMD | SPI1_CON_DORD |
                         SPI1_CON_CPHA | SPI1_CON_CPOL | SPI1_TWI1_CON_SPOS);
  /* Configure SPIx: mode, data size, first transmitted bit,clock predivision , CPOL and CPHA */
  /* Set MSTR bits to SPI0_Mode value */
  /* Set SPMD bit according to SPI1_DataSize value */
  /* Set DORD bit according to SPI1_FirstBit value */
  /* Set CPOL bit according to SPI1_CPOL value */
  /* Set CPHA bit according to SPI1_CPHA value */
  /* Set SPR according to SPI0_Prescaler value */
	tmpreg |= WorkeMode_SPI1 ;
  tmpreg |= (uint32_t)(SPI1_InitStruct->SPI1_Mode | SPI1_InitStruct->SPI1_DataSize |
                       SPI1_InitStruct->SPI1_FirstBit | SPI1_InitStruct->SPI1_CPHA |
                       SPI1_InitStruct->SPI1_CPOL | SPI1_InitStruct->SPI1_Prescaler);
  /* Write to SPIx SPI0_CON */
  SPITWI_TWI1->SPI1_TWI1_CON = tmpreg;
}
}

/**
 * @brief  Enables or disables the specified SPI peripheral.
 * @param  SPIx[out]:where can to select the SPI1 peripheral.  
 *           - SPI1: select the SPI1 peripheral.
 * @param  NewState[in]:new state of the SPIx peripheral. 
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable   
 * @retval None
 */
void SPI1_Cmd(SPITWI_TypeDef* SPIx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(SPIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if(SPIx==SPITWI_SPI1)
	{
	
  if(NewState != DISABLE)
  {
    /* Enable the SPI TX Function */
    SPIx->SPI1_TWI1_CON |= SPI1_TWI1_CON_QTWEN;
  }
  else
  {
    /* Disable the SPI TX Function */
    SPIx->SPI1_TWI1_CON &= (uint16_t)~SPI1_TWI1_CON_QTWEN;
  }
}
}

/**
 * @brief  Set the working mode of the SPI.
 * @param  SPIx[out]:where can to select the SPI1 peripheral.  
 *           - SPI1: select the SPI1 peripheral.
 * @param  SPI1_Mode[in]:specifies the data transfer direction in bidirectional mode.
 *             - SPI1_Mode_Slave:SPI Mode select Slave   
 *             - SPI1_Mode_Master:SPI Mode select Master 
 * @retval None
 */
void SPI1_SetMode(SPITWI_TypeDef* SPIx, SPI1_Mode_TypeDef SPI1_Mode)
{
  uint32_t tmpreg;
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(SPIx));
  if(SPIx==SPITWI_SPI1)
	{
  tmpreg = SPIx->SPI1_TWI1_CON;
  /* Clear MSTR bit */
  tmpreg &= (uint32_t)~SPI1_CON_MSTR;
  /* Cogfig MSTR bit */
  tmpreg |= (uint32_t)SPI1_Mode;
  /* Set new MSTR bit value */
  SPIx->SPI1_TWI1_CON |= tmpreg;
	}
}

/**
 * @brief  Configures the data size for the selected SPI.
 * @param  SPIx[out]:where can to select the SPI1 peripheral.  
 *           - SPI1: select the SPI1 peripheral.
  * @param  SPI1_DataSize[in]:specifies the SPI data size. 
  *               - SPI1_DataSize_8B:Set data frame format to 8bit    
  *               - SPI1_DataSize_16B:Set data frame format to 16bit  
  * @retval None
  */
void SPI1_DataSizeConfig(SPITWI_TypeDef* SPIx, SPI1_DataSize_TypeDef SPI1_DataSize)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(SPIx));
  assert_param(IS_SPI1_DATASIZE(SPI1_DataSize));
  if(SPIx==SPITWI_SPI1)
	{
  /* Clear SPMD bit */
  SPIx->SPI1_TWI1_CON &= (uint32_t)~SPI1_CON_SPMD;
  /* Set new SPMD bit value */
  SPIx->SPI1_TWI1_CON |= (uint32_t)SPI1_DataSize;
	}
}

/**
 * @}
 */
/* End of SPI1_TWI1_Group1.	*/

/** @defgroup SPI1_Group2 Data transfers functions
 *  @brief   Data transfers functions
 *
@verbatim
 ===============================================================================
                      ##### Data transfers functions #####
 ===============================================================================
@endverbatim
  * @{
  */


/**
 * @brief  Transmits multiple data through the SPIx peripheral FIFO.
 * @param  SPIx[out]:where can to select the SPI1 peripheral.  
 *           - SPI1: select the SPI1 peripheral.
 * @param  Data[in]: the datas to transmit.
 * @retval None
 */
void SPI1_SendData(SPITWI_TypeDef* SPIx, uint16_t Data)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(SPIx));
	  if(SPIx==SPITWI_SPI1)
	{
  /* Transmit  Data */
  SPIx->SPI1_TWI1_DATA = (uint16_t)Data;
  }
}

/**
 * @brief  SPIx receives data through FIFO.
 * @param  SPIx[out]:where can to select the SPI1 peripheral.  
 *           - SPI1: select the SPI1 peripheral.
 * @retval The received data.
 */
uint16_t SPI1_ReceiveData(SPITWI_TypeDef* SPIx)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(SPIx));
	return (uint16_t) SPIx->SPI1_TWI1_DATA;
}

/**
 * @}
 */
/* End of SPI1_Group2.	*/

/** @defgroup SPI_Group3 Interrupts, DMA and flags management functions
 *  @brief   Interrupts, DMA and flags management functions
 *
@verbatim
 ===============================================================================
            ##### Interrupts, DMA and flags management functions #####
 ===============================================================================
@endverbatim
  * @{
  */
/**
 * @brief  Enables or disables the TWI's DMA interface.
 * @param  SPIx_TWIx[out]:where  can  to select the TWI1 or SPI11 peripheral. 
 *                  - SPI1:Timer peripheral select SPII1
 *                  - TWI1:Timer peripheral select TWI1
 * @param  TWI_DMAReq[in]:specifies the DMA request. 
 *                - SPI1_TWI1_DMAReq_RX:SPI1_TWI1 DMA Request  Receive 
 *                - SPI1_TWI1_DMAReq_TX :SPI1_TWI1 DMA Request: Transmit 
 * @param  NewState[in]:new state of the DMA Request sources. 
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable 
 * @retval None
 */
void SPI1_DMACmd(SPITWI_TypeDef* SPIx, SPI1_DMAReq_TypeDef SPI1_DMAReq, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(SPIx));
  assert_param(IS_SPI1_DMAReq(SPI1_DMAReq));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
	if(SPIx == SPITWI_SPI1)
	{
		if(NewState != DISABLE)
		{
			/* Enable the selected TWI DMA requests */
			SPIx->SPI1_TWI1_IDE |= SPI1_DMAReq;
		}
		else
		{
			/* Disable the selected TWI DMA requests */
			SPIx->SPI1_TWI1_IDE &= (uint8_t)~SPI1_DMAReq;
		}
  }
}
/**
 * @brief  Enables or disables the specified SPI interrupts.
 * @param  SPIx[out]:where can to select the SPI1 peripheral.  
 *           - SPI1: select the SPI1 peripheral.
 * @param  SPI1_IT[in]:specifies the SPI interrupts sources to be enabled or disabled.
 *               - SPI1_IT_INT:SPI total interruption  
 *               - SPI1_IT_TBIE:SPI TX buffer is empty Interrupt 
 * @param  NewState[in]: new state of the SPI interrupts.
 *               - DISABLE:Function disable
 *               - ENABLE:Function enable 
 * @retval None
 */
void SPI1_ITConfig(SPITWI_TypeDef* SPIx, uint16_t SPI1_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(SPIx));
  assert_param(IS_SPI1_IT(SPI1_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
	if(SPIx==SPITWI_SPI1)
	{
  if(NewState != DISABLE)
  {
    /* Enable the Interrupt sources */
    SPIx->SPI1_TWI1_IDE |= SPI1_IT;
  }
  else
  {
    /* Disable the Interrupt sources */
    SPIx->SPI1_TWI1_IDE &= (uint16_t)~SPI1_IT;
  }
  }
}

/**
 * @brief  Checks whether the specified SPI flag is set or not.
 * @param  SPIx[out]:where can to select the SPI1 peripheral.  
 *           - SPI1: select the SPI1 peripheral.
 * @param  SPI_FLAG[in]: specifies the flag to check. 
 *         - SPI1_Flag_QTWIF:Interrupt flag 
 *         - SPI1_Flag_TXEIF:TX buffer is empty flag 
 *         - SPI1_Flag_WCOL:Write conflict flag   
 * @retval The new state of INT_Flag (SET or RESET).
 *                  -  RESET:Flag reset
 *                  -  SET :Flag up
 */
FlagStatus SPI1_GetFlagStatus(SPITWI_TypeDef* SPIx, SPI1_FLAG_TypeDef SPI1_FLAG)
{
  ITStatus bitstatus = RESET;
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(SPIx));
  assert_param(IS_SPI1_FLAG(SPI1_FLAG));
  if(SPIx==SPITWI_SPI1)
	{
  if((SPIx->SPI1_TWI1_STS & SPI1_FLAG) != (uint16_t)RESET)
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
	}
  return bitstatus;
 
}
/**
 * @brief  Clears the SPIx's pending flags.
 * @param  SPIx[out]:where can to select the SPI1 peripheral.  
 *           - SPI1: select the SPI1 peripheral.
 * @param  SPI1_FLAG[in]:specifies the flag bit to clear.
 *         - SPI1_Flag_QTWIF:Interrupt flag 
 *         - SPI1_Flag_TXEIF:TX buffer is empty flag 
 *         - SPI1_Flag_WCOL:Write conflict flag   
 * @retval None
 */
void SPI1_ClearFlag(SPITWI_TypeDef* SPIx, uint32_t SPI1_FLAG)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(SPIx));
  /* Clear the flags */
	  if(SPIx==SPITWI_SPI1)
	{
  SPIx->SPI1_TWI1_STS = (uint16_t)SPI1_FLAG;
	}
}
/**
 * @}
 */
/* End of SPI_Group3.	*/
/** @defgroup TWI1_Group4 Configuration of the TWI1 computation unit functions
 *  @brief   Configuration of the TWI1 computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### TWI1 configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */
/**
  * @brief  Fills each TWI_InitStruct member with its default value.
  * @param  TWI_InitStruct[out]: Pointer to structure TWI_InitTypeDef, to be initialized. 
  * @retval None
  */
void TWI1_StructInit(TWI1_InitTypeDef* TWI1_InitStruct)
{
  /* Set the default configuration */
  TWI1_InitStruct->TWI1_Ack = TWI1_Ack_Enable;
  TWI1_InitStruct->TWI1_Prescaler = SPI1_TWI1_Prescaler_4096;
  TWI1_InitStruct->TWI1_Stretch = TWI1_Stretch_Disable;
  TWI1_InitStruct->TWI1_GeneralCall = TWI1_GeneralCall_Disable;
  TWI1_InitStruct->TWI1_SlaveAdress = 0x00;
}
/**
 * @brief  Initializes the peripheral TWIx register with the parameters specified in TWI_InitStruct
 * @param  TWIx[out]:where can to select the TWI1 peripheral. 
 *                  - TWI1:Timer peripheral select TWI1
 * @param  TWI_InitStruct[out]: Pointer to structure TWI_InitTypeDef, to be initialized. 
 * @retval None
 */
void TWI1_Init(SPITWI_TypeDef* TWIx, TWI1_InitTypeDef* TWI_InitStruct)
{
  uint32_t tmpreg;
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(TWIx));
  assert_param(IS_TWI1_ACK(TWI_InitStruct->TWI1_Ack));
  assert_param(IS_SPI1_TWI1_Prescaler(TWI_InitStruct->TWI1_Prescaler));
  assert_param(IS_TWI1_STRETCH(TWI_InitStruct->TWI1_Stretch));
  assert_param(IS_TWI1_GENERALCALL(TWI_InitStruct->TWI1_GeneralCall));
  /*---------------------------- TWIx TWI_CON Configuration ------------------------*/
	 if(TWIx==SPITWI_TWI1)
 {
  /* Get the TWIx TWI_CON value */
  tmpreg = TWIx->SPI1_TWI1_CON;
  /* Clear AA, TWCK, STRETCH bits */
  tmpreg &= (uint32_t) ~(TWI1_CON_AA | SPI1_TWI1_CON_QTWCK_Msk | TWI1_CON_STRETCH|SPI1_TWI1_CON_MODE_Msk);
  /* Configure TWIx: Ack, Clock division and Slave Clock Stretch */
  /* Set AA bits to TWI_Ack value */
  /* Set TWCK bits according to TWI_DataSize value */
  /* Set STRETCH bit according to TWI_Stretch value */
  tmpreg |= (uint32_t)(TWI_InitStruct->TWI1_Ack | TWI_InitStruct->TWI1_Prescaler |
                       TWI_InitStruct->TWI1_Stretch|WorkeMode_TWI1);
  /* Write to TWIx TWI_CON */
  TWIx->SPI1_TWI1_CON = tmpreg;
  /*---------------------------- TWIx TWI_ADD Configuration ------------------------*/
  /* Get the TWIx TWI_ADD value */
  tmpreg = TWIx->TWI1_ADD;
  /* Clear GC, TWCK, STRETCH bits */
  tmpreg &= (uint32_t) ~(TWI1_ADD_GC | TWI1_ADD_QTWADD);
  /* Configure TWIx: General Call and Slave Slave Address */
  /* Set AA bits to TWI_GC value */
  /* Set TWA according to TWI_SlaveAdress value */
  tmpreg |= (uint32_t)(TWI_InitStruct->TWI1_GeneralCall | (TWI_InitStruct->TWI1_SlaveAdress & 0xFE));

  /* Write to TWIx TWI_ADD */
  TWIx->TWI1_ADD = tmpreg;
}
}

/**
 * @brief  Enables or disables the specified TWI peripheral.
 * @param  TWIx[out]:where can to select the TWI1 peripheral. 
 *                  - TWI1:Timer peripheral select TWI1
 * @param  NewState[in]:new state of the TWIx peripheral. 
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable  
 * @retval None
 */
void TWI1_Cmd(SPITWI_TypeDef* TWIx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(TWIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
		if(TWIx==SPITWI_TWI1)
	{
  if(NewState != DISABLE)
  {
    /* Enable the SPI TX Function */
    TWIx->SPI1_TWI1_CON |= SPI1_TWI1_CON_QTWEN;
  }
  else
  {
    /* Disable the SPI TX Function */
    TWIx->SPI1_TWI1_CON &= (uint16_t)~SPI1_TWI1_CON_QTWEN;
  }
  }
}


/**
  * @brief  Enables or disables the specified TWI acknowledge feature.
 * @param  TWIx[out]:where can to select the TWI1 peripheral. 
 *                  - TWI1:Timer peripheral select TWI1
  * @param  NewState[in]: new state of the TWI Acknowledgement.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable  
  * @retval None.
  */
void TWI1_AcknowledgeConfig(SPITWI_TypeDef* TWIx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(TWIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
	if(TWIx==SPITWI_TWI1)
	{
  if(NewState != DISABLE)
  {
    /* Enable the acknowledgement */
    TWIx->SPI1_TWI1_CON |= TWI1_CON_AA;
  }
  else
  {
    /* Disable the acknowledgement */
    TWIx->SPI1_TWI1_CON &= (uint16_t)~TWI1_CON_AA;
  }
  }
}

/**
  * @brief  Enables or disables the specified TWI general call feature.
 * @param  TWIx[out]:where can to select the TWI1 peripheral. 
 *                  - TWI1:Timer peripheral select TWI1
  * @param  NewState[in]: new state of the TWI General call.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable 
  * @retval None
  */
void TWI1_GeneralCallCmd(SPITWI_TypeDef* TWIx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(TWIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
	if(TWIx==SPITWI_TWI1)
	{
  if(NewState != DISABLE)
  {
    /* Enable general call */
    TWIx->TWI1_ADD |= TWI_ADD_GC;
  }
  else
  {
    /* Disable general call */
    TWIx->TWI1_ADD &= (uint16_t)~TWI_ADD_GC;
  }
  }
}

/**
  * @brief  Enables or disables the specified TWI Clock stretching.
 * @param  TWIx[out]:where can to select the TWI1 peripheral. 
 *                  - TWI1:Timer peripheral select TWI1
  * @param  NewState[in]: new state of the TWIx Clock stretching.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable 
  * @retval None
  */
void TWI1_StretchClockConfig(SPITWI_TypeDef* TWIx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(TWIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
	if(TWIx==SPITWI_TWI1)
	{
  if(NewState == DISABLE)
  {
    /* Enable the selected TWI Clock stretching */
    TWIx->SPI1_TWI1_CON |= TWI1_CON_STRETCH;
  }
  else
  {
    /* Disable the selected TWI Clock stretching */
    TWIx->SPI1_TWI1_CON &= (uint16_t)~((uint16_t)TWI1_CON_STRETCH);
  }
  }
}

/**
  * @brief  Example Set the number of Nbytes.
 * @param  TWIx[out]:where can to select the TWI1 peripheral. 
 *                  - TWI1:Timer peripheral select TWI1
  * @param  Nbytes[in]: Number of bytes to be sent or received.
  *          This parameter can be less than 256.
  * @retval None
  */
void TWI1_SetNbytes(SPITWI_TypeDef* TWIx, uint8_t Nbytes)
{
	  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(TWIx));
  if(TWIx==SPITWI_TWI1)
	{
	TWIx->SPI1_TWI1_STS = (uint32_t)(Nbytes << TWI1_STS_NBYTES_Pos);
	}
}


/**
  * @brief  Obtain the number of remaining Nbytes.
 * @param  TWIx[out]:where can to select the TWI1 peripheral. 
 *                  - TWI1:Timer peripheral select TWI1
  * @retval Number of bytes to be sent or received.
  */
uint8_t TWI1_GetNbytes(SPITWI_TypeDef* TWIx)
{
	uint8_t tmpnum;
	if(TWIx==SPITWI_TWI1)
	{
	
	
	  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(TWIx));

	tmpnum = (uint8_t)(TWIx->SPI1_TWI1_STS >> TWI_STS_NBYTES_Pos);
	
	
	}
	return tmpnum;
}

/** @defgroup TWI_Group5 Data transfers functions
 *  @brief   Data transfers functions
 *
@verbatim
 ===============================================================================
                      ##### Data transfers functions #####
 ===============================================================================
@endverbatim
  * @{
  */


/**
  * @brief  Generates TWIx communication START condition.
 * @param  TWIx[out]:where can to select the TWI1 peripheral. 
 *                  - TWI1:Timer peripheral select TWI1
  * @param  NewState[in]:new state of the TWI START condition generation. 
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable 
  * @retval None.
  */
void TWI1_GenerateSTART(SPITWI_TypeDef* TWIx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(TWIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
		if(TWIx==SPITWI_TWI1)
	{
  if(NewState != DISABLE)
  {
    /* Generate a START condition */
    TWIx->SPI1_TWI1_CON |= TWI_CON_STA;
  }
  else
  {
    /* Disable the START condition generation */
    TWIx->SPI1_TWI1_CON &= (uint16_t)~TWI_CON_STA;
  }
  }
}

/**
  * @brief  Generates TWIx communication STOP condition.
  * @param  TWIx[out]:where can to select the TWI1 peripheral. 
  *                  - TWI1:Timer peripheral select TWI1
  * @param  NewState[in]:new state of the TWI STOP condition generation.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable 
  * @retval None.
  */
void TWI1_GenerateSTOP(SPITWI_TypeDef* TWIx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(TWIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if(TWIx==SPITWI_TWI1)
	{
  if(NewState != DISABLE)
  {
    /* Generate a STOP condition */
    TWIx->SPI1_TWI1_CON |= TWI1_CON_STOP;
  }
  else
  {
    /* Disable the STOP condition generation */
    TWIx->SPI1_TWI1_CON &= (uint16_t)~TWI1_CON_STOP;
  }
  }
}

/**
  * @brief  Sends an address word to the specified slave TWI device.
 * @param  TWIx[out]:where can to select the TWI1 peripheral. 
 *                  - TWI1:Timer peripheral select TWI1
  * @param  Address[in]: specifies the slave address which will be transmitted
  * @param  TWI_Command[in]:specifies whether the TWI device will be a Transmitter or a Receiver.
  *                  - TWI_Command_Write:TWI Command:Write   
  *                  - TWI_Command_Read:TWI Command:Read   
  * @retval None.
  */
void TWI1_Send7bitAddress(SPITWI_TypeDef* TWIx, uint8_t Address, TWI1_Command_TypeDef TWI1_Command)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(TWIx));
  assert_param(IS_TWI1_COMMAND(TWI1_Command));
	  if(TWIx==SPITWI_TWI1)
	{
  /* Test on the direction to set/reset the read/write bit */
	if(TWI1_Command != TWI1_Command_Write)
	{
		/* Set the address bit0 for read */
    Address |= TWI1_Command_Read;
	}
	else
	{
		/* Reset the address bit0 for write */
    Address &= (uint8_t)~((uint8_t)TWI1_Command_Read);
	}

  /* Send the address */
  TWIx->SPI1_TWI1_DATA = Address;
}
}

/**
 * @}
 */


/**
 * @brief  Send a data through the peripheral TWIx.
 * @param  TWIx[out]:where can to select the TWI1 peripheral. 
 *                  - TWI1:Timer peripheral select TWI1
 * @param  Data[in]: the data to transmit.
 * @retval None
 */
void TWI1_SendData(SPITWI_TypeDef* TWIx, uint16_t Data)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(TWIx));
	if(TWIx==SPITWI_TWI1)
	{
  /* Transmit Data */
  TWIx->SPI1_TWI1_DATA = Data;
	}
}

/**
 * @brief  Returns the most recent data received via TWIx.
 * @param  TWIx[out]:where can to select the TWI1 peripheral. 
 *                  - TWI1:Timer peripheral select TWI1
 * @retval the most recent data received via TWIx.
 */
uint16_t TWI1_ReceiveData(SPITWI_TypeDef* TWIx)
{
	if(TWIx==SPITWI_TWI1)
	{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(TWIx));
  /* Receive Data */
 
	} 
	return (uint16_t)TWIx->SPI1_TWI1_DATA;
}

/**
 * @}
 */

/**
 * @brief  Get whether the specified TWI State Machine.
 * @param  TWIx[out]:where can to select the TWI1 peripheral. 
 *                  - TWI1:Timer peripheral select TWI1
 * @retval The new state  Machine of TWIx.
 *                  - TWI1_Slave_Idle 
 *                  - TWI1_Slave_ReceivedaAddress 
 *                  - TWI1_Slave_ReceivedaData  
 *                  - TWI1_Slave_SendData                  
 *                  - TWI1_Master_Idle 
 *                  - TWI1_Master_SendAddress 
 *                  - TWI1_Master_SendData  
 */
TWI1_StateMachine_TypeDef TWI1_GetStateMachine(SPITWI_TypeDef* TWIx)
{
	  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(TWIx));
	
	return (TWI1_StateMachine_TypeDef)(TWIx->SPI1_TWI1_STS & TWI1_STS_STATE);
}



/**
 * @}
 */
/* End of TWI1_Group5.	*/

/** @defgroup TWI1_Group6 Interrupts and flags management functions
 *  @brief   Interrupts and flags management functions
 *
@verbatim
 ===============================================================================
            ##### Interrupts, DMA and flags management functions #####
 ===============================================================================
@endverbatim
  * @{
  */
/**
 * @brief  Enables or disables the specified TWI interrupts.
 * @param  TWIx[out]:where can to select the TWI1 peripheral. 
 *                  - TWI1:Timer peripheral select TWI1
 * @param  TWI1_IT[in]:specifies the TWI interrupts sources to be enabled or disabled.  
 *                  - TWI1_IT_INT: TWI Interrupt 
 * @param  NewState[in]: new state of the TWI interrupts.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable  
 *        
 * @retval None
 */
void TWI1_ITConfig(SPITWI_TypeDef* TWIx, uint16_t TWI1_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(TWIx));
  assert_param(IS_TWI1_IT(TWI1_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
		if(TWIx==SPITWI_TWI1)
	{
  if(NewState != DISABLE)
  {
    /* Enable the Interrupt sources */
    TWIx->SPI1_TWI1_IDE |= TWI1_IT;
  }
  else
  {
    /* Disable the Interrupt sources */
    TWIx->SPI1_TWI1_IDE &= (uint16_t)~TWI1_IT;
  }
 }
}

/**
 * @brief  Checks whether the specified TWI flag is set or not.
 * @param  TWIx[out]:where can to select the TWI1 peripheral. 
 *                  - TWI1:Timer peripheral select TWI1
 * @param  TWI1_FLAG[in]: specifies the flag to check. 
 *                  - TWI1_FLAG_QTWIF:Interrupt flag 
 *                  - TWI1_FLAG_TXRXnE:Transmit/receive completion flag 
 *                  - TWI1_FLAG_GCA:Generic Call flags  
 *                  - TWI1_FLAG_TMSTR:Flag to identify master or slave 
 * @retval The new state of TWI_FLAG (SET or RESET).
 *                  -  RESET:Flag reset
 *                  -  SET :Flag up
 */
FlagStatus TWI1_GetFlagStatus(SPITWI_TypeDef* TWIx, TWI1_FLAG_TypeDef TWI1_FLAG)
{
  ITStatus bitstatus = RESET;
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(TWIx));
  assert_param(IS_TWI1_FLAG(TWI1_FLAG));
  if(TWIx==SPITWI_TWI1)
	{
  if((TWIx->SPI1_TWI1_STS & TWI1_FLAG) != (uint16_t)RESET)
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
	}
  return bitstatus;
}

/**
 * @brief  Clears the TWIx's pending flags.
 * @param  TWIx[out]:where can to select the TWI1 peripheral. 
 *                  - TWI1:Timer peripheral select TWI1
 * @param  TWI1_FLAG[in]: specifies the flag bit to clear.
 *                  - TWI1_FLAG_QTWIF:Interrupt flag 
 *                  - TWI1_FLAG_TXRXnE:Transmit/receive completion flag 
 *                  - TWI1_FLAG_GCA:Generic Call flags  
 * @retval None
 */
void TWI1_ClearFlag(SPITWI_TypeDef* TWIx, TWI1_FLAG_TypeDef TWI1_FLAG)
{
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(TWIx));
  /* Clear the flags */
	if(TWIx==SPITWI_TWI1)
	{
		 if(TWI1_FLAG==TWI1_FLAG_QTWIF)
		{
			TWIx->SPI1_TWI1_STS &= (uint32_t)0xFFFFFFF9;
		}
		else if(TWI1_FLAG==TWI1_FLAG_TXRXnE)
		{
			TWIx->SPI1_TWI1_STS &= (uint32_t)0xFFFFFFFA;
		}
		else if(TWI1_FLAG==TWI1_FLAG_GCA)
		{
			TWIx->SPI1_TWI1_STS &= (uint32_t)0xFFFFFFFC;
		}

	}
}


/**
 * @brief  Configures the TIMx Pin Remap
 * @param  SPIx_TWIx[out]:where  can  to select the TWI1 or SPI11 peripheral. 
 *                  - SPI1:Timer peripheral select SPII1
 *                  - TWI1:Timer peripheral select TWI1
 * @param  TWI_Remap[in]:specifies the TIM input remapping source.
 *                  - SPI1_TWI1_PinRemap_Default:TIM Pin Remap  Disable  
 *                  - SPI1_TWI1_PinRemap_A:TIM Pin Remap: Remap mode A  
 *                  - SPI1_TWI1_PinRemap_B:TIM Pin Remap: Remap mode B  
 *                  - SPI1_TWI1_PinRemap_C:TIM Pin Remap: Remap mode C 
 * @retval None
 */
void SPI1_TWI1_PinRemapConfig(SPITWI_TypeDef* SPIx_TWIx, SPI1_TWI1_PinRemap_TypeDef SPI1_TWI1_Remap)
{
  uint32_t tmpreg ;
  /* Check the parameters */
  assert_param(IS_SPI1_TWI1_ALL_PERIPH(SPIx_TWIx));
  
  tmpreg = SPIx_TWIx->SPI1_TWI1_CON;

  tmpreg &= (uint32_t)(~SPI1_TWI1_CON_SPOS);

  tmpreg |= SPI1_TWI1_Remap;

  SPIx_TWIx->SPI1_TWI1_CON = tmpreg;
}
#endif
/**
 * @}
 */
/* End of TWI_Group6.	*/

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT SOC Microelectronics *****END OF FILE****/
