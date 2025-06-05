/*
 ******************************************************************************
 * @file    sc32f1xxx_dma.c
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief  DMA function module
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
#include "sc32f1xxx_dma.h"

/* Exported functions ---------------------------------------------------------*/
/** @defgroup DMA_Exported_Functions
 * @{
 */

/** @defgroup DMA_Group1 Initialization and Configuration functions
 *  @brief Initialization and Configuration functions
 *
@verbatim
 ===============================================================================
                     ##### Initialization and de-initialization functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitializes the DMA peripheral
 * @param  DMAx[out]:
 *                 SC32f10xx Selection range(DMA0 - DMA3)
 *                 SC32f11xx Selection range(DMA0 - DMA3)
 *                 SC32f12xx Selection range(DMA0 - DMA1)
 *                 SC32f15xx Selection range(DMA0 - DMA3)
 *                  - DMA0 :select DMA0 peripherals
 *                  - DMA1 :select DMA1 peripherals
 *                  - DMA2 :select DMA2 peripherals
 *                  - DMA3 :select DMA3 peripherals
 * @retval None
 */
void DMA_DeInit ( DMA_TypeDef* DMAx )
{
    /* Check the parameters */
    assert_param ( IS_DMA_ALL_PERIPH ( DMAx ) );

    if ( DMAx != 0x00 )
    {
        /* Enable DMA reset state */
        RCC_AHBPeriphResetCmd ( RCC_AHBPeriph_DMA, ENABLE );
        /* Release DMA from reset state */
        RCC_AHBPeriphResetCmd ( RCC_AHBPeriph_DMA, DISABLE );
    }
}

/**
 * @brief  Initialize the DMA according to the specified
 *         parameters in the DMA_InitTypeDef and create the associated handle.
 * @param  DMAx[out]:
 *                 SC32f10xx Selection range(DMA0 - DMA3)
 *                 SC32f11xx Selection range(DMA0 - DMA3)
 *                 SC32f12xx Selection range(DMA0 - DMA1)
 *                 SC32f15xx Selection range(DMA0 - DMA3)
 *                  - DMA0 :select DMA0 peripherals
 *                  - DMA1 :select DMA1 peripherals
 *                  - DMA2 :select DMA2 peripherals
 *                  - DMA3 :select DMA3 peripherals
 * @param  DMA_InitStruct[out]:Pointer to structure DMA_InitStruct, to be initialized.
 * @retval None
 */
void DMA_Init ( DMA_TypeDef* DMAx, DMA_InitTypeDef* DMA_InitStruct )
{
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_DMA_ALL_PERIPH ( DMAx ) );
    assert_param ( IS_DMA_PROIORITY ( DMA_InitStruct->DMA_Priority ) );
    assert_param ( IS_DMA_CIRCULARMODE ( DMA_InitStruct->DMA_CircularMode ) );
    assert_param ( IS_DMA_DATASIZE ( DMA_InitStruct->DMA_DataSize ) );
    assert_param ( IS_DMA_TARGERT_MODE ( DMA_InitStruct->DMA_TargetMode ) );
    assert_param ( IS_DMA_SOURCE_MODE ( DMA_InitStruct->DMA_SourceMode ) );
    assert_param ( IS_DMA_BURST ( DMA_InitStruct->DMA_Burst ) );

    tmpreg = DMAx->DMA_CFG;

    tmpreg &=
        ( uint32_t ) ~ ( DMA_CFG_PL | DMA_CFG_TXWIDTH | DMA_CFG_CIRC |
                         DMA_CFG_CHRST | DMA_CFG_CHEN | DMA_CFG_DAINC | DMA_CFG_SAINC |
                         DMA_CFG_BURSIZE | DMA_CFG_TPTYPE |
                         DMA_CFG_REQSRC );
    tmpreg |=
        ( uint32_t ) ( DMA_InitStruct->DMA_Priority | DMA_InitStruct->DMA_CircularMode |
                       DMA_InitStruct->DMA_DataSize | DMA_InitStruct->DMA_TargetMode |
                       DMA_InitStruct->DMA_SourceMode | DMA_InitStruct->DMA_Burst |
                       DMA_InitStruct->DMA_Request );

    DMAx->DMA_CFG = tmpreg;

    DMAx->DMA_SADR = DMA_InitStruct->DMA_SrcAddress;
    DMAx->DMA_DADR = DMA_InitStruct->DMA_DstAddress;
    DMAx->DMA_CNT = DMA_InitStruct->DMA_BufferSize;
}

/**
  * @brief  Fills each DMA_InitStruct member with its default value.
  * @param  DMA_InitStruct[out]:Pointer to structure DMA_InitStruct, to be initialized.
  * @retval None
  */
void DMA_StructInit ( DMA_InitTypeDef* DMA_InitStruct )
{
    /* Initialize the DMA_Priority member */
    DMA_InitStruct->DMA_Priority = DMA_Priority_LOW;

    /* Initialize the DMA_CircularMode member */
    DMA_InitStruct->DMA_CircularMode = DMA_CircularMode_Disable;

    /* Initialize the DMA_DataSize member */
    DMA_InitStruct->DMA_DataSize = DMA_DataSize_Byte;

    /* Initialize the DMA_TargetMode member */
    DMA_InitStruct->DMA_TargetMode = DMA_TargetMode_FIXED;

    /* Initialize the DMA_SourceMode member */
    DMA_InitStruct->DMA_SourceMode = DMA_SourceMode_FIXED;

    /* Initialize the DMA_Burst member */
    DMA_InitStruct->DMA_Burst = DMA_Burst_Disable;

    /* Initialize the DMA_Request member */
    DMA_InitStruct->DMA_Request = DMA_Request_Null;
}

/**
  * @brief  Enables or disables the specified DMAx.
	* @param  DMAx[out]:
  *                 SC32f10xx Selection range(DMA0 - DMA3)
  *                 SC32f11xx Selection range(DMA0 - DMA3)
  *                 SC32f12xx Selection range(DMA0 - DMA1)
  *                 SC32f15xx Selection range(DMA0 - DMA3)
	*                  - DMA0 :select DMA0 peripherals
	*                  - DMA1 :select DMA1 peripherals
	*                  - DMA2 :select DMA2 peripherals
	*                  - DMA3 :select DMA3 peripherals
  * @param  NewState[in]: new state of the DMAx.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable
  *
  * @retval None
  */
void DMA_Cmd ( DMA_TypeDef* DMAx, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_DMA_ALL_PERIPH ( DMAx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the selected DMAy Streamx by setting EN bit */
        DMAx->DMA_CFG |= ( uint32_t ) DMA_CFG_CHEN;
    }
    else
    {
        /* Disable the selected DMAy Streamx by clearing EN bit */
        DMAx->DMA_CFG &= ~ ( uint32_t ) DMA_CFG_CHEN;
    }
}

/**
  * @brief  Enables or disables the specified DMAx Pause.
 * @param  DMAx[out]:
 *                 SC32f10xx Selection range(DMA0 - DMA3)
 *                 SC32f11xx Selection range(DMA0 - DMA3)
 *                 SC32f12xx Selection range(DMA0 - DMA1)
 *                 SC32f15xx Selection range(DMA0 - DMA3)
 *                  - DMA0 :select DMA0 peripherals
 *                  - DMA1 :select DMA1 peripherals
 *                  - DMA2 :select DMA2 peripherals
 *                  - DMA3 :select DMA3 peripherals
  * @param  NewState[in]: new state of the DMAx.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable
  * @retval None
  */
void DMA_PauseCmd ( DMA_TypeDef* DMAx, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_DMA_ALL_PERIPH ( DMAx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the selected DMAy Streamx by setting PAUSE bit */
        DMAx->DMA_CFG |= ( uint32_t ) DMA_CFG_PAUSE;
    }
    else
    {
        /* Enable the selected DMAy Streamx by clearing EN bit */
        DMAx->DMA_CFG = ( uint32_t ) ( ( DMAx->DMA_CFG | DMA_CFG_CHEN ) & ( ~DMA_CFG_PAUSE ) );
    }
}

/**
  * @brief  Enables or disables the specified DMAx CHRQ.
 * @param  DMAx[out]:
 *                 SC32f10xx Selection range(DMA0 - DMA3)
 *                 SC32f11xx Selection range(DMA0 - DMA3)
 *                 SC32f12xx Selection range(DMA0 - DMA1)
 *                 SC32f15xx Selection range(DMA0 - DMA3)
 *                  - DMA0 :select DMA0 peripherals
 *                  - DMA1 :select DMA1 peripherals
 *                  - DMA2 :select DMA2 peripherals
 *                  - DMA3 :select DMA3 peripherals
  * @param  NewState[in]: new state of the DMAx.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable
  * @retval None
  */
void DMA_CHRQCmd ( DMA_TypeDef* DMAx, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_DMA_ALL_PERIPH ( DMAx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the selected DMAy Streamx by setting CHRQ bit */
        DMAx->DMA_CFG |= ( uint32_t ) DMA_CFG_CHRQ;
    }
    else
    {
        /* Enable the selected DMAy Streamx by clearing CHRQ bit */
        DMAx->DMA_CFG &= ( uint32_t ) ~DMA_CFG_CHRQ;
    }
}

/**
  * @brief  Reset DMA Channel
 * @param  DMAx[out]:
 *                 SC32f10xx Selection range(DMA0 - DMA3)
 *                 SC32f11xx Selection range(DMA0 - DMA3)
 *                 SC32f12xx Selection range(DMA0 - DMA1)
 *                 SC32f15xx Selection range(DMA0 - DMA3)
 *                  - DMA0 :select DMA0 peripherals
 *                  - DMA1 :select DMA1 peripherals
 *                  - DMA2 :select DMA2 peripherals
 *                  - DMA3 :select DMA3 peripherals
  * @retval None
  */
void DMA_ChannelReset ( DMA_TypeDef* DMAx )
{
    /* Check the parameters */
    assert_param ( IS_DMA_ALL_PERIPH ( DMAx ) );

    DMAx->DMA_CFG |= ( uint32_t ) DMA_CFG_CHRST;
}

/**
 * @}
 */

/** @defgroup DMA_Group2 Data Counter functions
 *  @brief   Data Counter functions
 *
@verbatim
 ===============================================================================
                      ##### Data Counter functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
  * @brief  Sets the source address for the specified DMA.
 * @param  DMAx[out]:
 *                 SC32f10xx Selection range(DMA0 - DMA3)
 *                 SC32f11xx Selection range(DMA0 - DMA3)
 *                 SC32f12xx Selection range(DMA0 - DMA1)
 *                 SC32f15xx Selection range(DMA0 - DMA3)
 *                  - DMA0 :select DMA0 peripherals
 *                  - DMA1 :select DMA1 peripherals
 *                  - DMA2 :select DMA2 peripherals
 *                  - DMA3 :select DMA3 peripherals
  * @param  SrcAddress[in]:Data source address transmitted by DMAx .
  *
  *
  */
void DMA_SetSrcAddress ( DMA_TypeDef* DMAx, uint32_t SrcAddress )
{
    /* Check the parameters */
    assert_param ( IS_DMA_ALL_PERIPH ( DMAx ) );

    /* Write the number of data units to be transferred */
    DMAx->DMA_SADR = ( uint32_t ) SrcAddress;
}

/**
  * @brief  Sets the destination address for the specified DMA.
 * @param  DMAx[out]:
 *                 SC32f10xx Selection range(DMA0 - DMA3)
 *                 SC32f11xx Selection range(DMA0 - DMA3)
 *                 SC32f12xx Selection range(DMA0 - DMA1)
 *                 SC32f15xx Selection range(DMA0 - DMA3)
 *                  - DMA0 :select DMA0 peripherals
 *                  - DMA1 :select DMA1 peripherals
 *                  - DMA2 :select DMA2 peripherals
 *                  - DMA3 :select DMA3 peripherals
  * @param  DstAddress[in]: Destination address of data transmitted by DMAx.
  * @retval Null.
  */
void DMA_SetDstAddress ( DMA_TypeDef* DMAx, uint32_t DstAddress )
{
    /* Check the parameters */
    assert_param ( IS_DMA_ALL_PERIPH ( DMAx ) );

    /* Write the number of data units to be transferred */
    DMAx->DMA_DADR = ( uint32_t ) DstAddress;
}

/**
  * @brief  Sets the number of transfers for the specified DMA.
 * @param  DMAx[out]:
 *                 SC32f10xx Selection range(DMA0 - DMA3)
 *                 SC32f11xx Selection range(DMA0 - DMA3)
 *                 SC32f12xx Selection range(DMA0 - DMA1)
 *                 SC32f15xx Selection range(DMA0 - DMA3)
 *                  - DMA0 :select DMA0 peripherals
 *                  - DMA1 :select DMA1 peripherals
 *                  - DMA2 :select DMA2 peripherals
 *                  - DMA3 :select DMA3 peripherals
  * @param  Counter[in]: Number of data units to be transferred (from 0 to 65535)
  *          Number of data items depends only on the Peripheral data format.
  *
  * @retval Null.
  */
void DMA_SetCurrDataCounter ( DMA_TypeDef* DMAx, uint32_t Counter )
{
    /* Check the parameters */
    assert_param ( IS_DMA_ALL_PERIPH ( DMAx ) );

    /* Write the number of data units to be transferred */
    DMAx->DMA_CNT = ( uint32_t ) Counter;
}

/**
  * @brief  Gets the number of transfers for the specified DMA.
 * @param  DMAx[out]:
 *                 SC32f10xx Selection range(DMA0 - DMA3)
 *                 SC32f11xx Selection range(DMA0 - DMA3)
 *                 SC32f12xx Selection range(DMA0 - DMA1)
 *                 SC32f15xx Selection range(DMA0 - DMA3)
 *                  - DMA0 :select DMA0 peripherals
 *                  - DMA1 :select DMA1 peripherals
 *                  - DMA2 :select DMA2 peripherals
 *                  - DMA3 :select DMA3 peripherals
  * @retval The number of DMA transfers.
  */
uint32_t DMA_GetCurrDataCounter ( DMA_TypeDef* DMAx )
{
    /* Check the parameters */
    assert_param ( IS_DMA_ALL_PERIPH ( DMAx ) );

    /* Return The number of DMA transfers */
    return ( ( uint32_t ) ( DMAx->DMA_CNT ) );
}

/**
  * @brief  The software triggers the transfer of the specified DMA.
 * @param  DMAx[out]:
 *                 SC32f10xx Selection range(DMA0 - DMA3)
 *                 SC32f11xx Selection range(DMA0 - DMA3)
 *                 SC32f12xx Selection range(DMA0 - DMA1)
 *                 SC32f15xx Selection range(DMA0 - DMA3)
 *                  - DMA0 :select DMA0 peripherals
 *                  - DMA1 :select DMA1 peripherals
 *                  - DMA2 :select DMA2 peripherals
 *                  - DMA3 :select DMA3 peripherals
  * @retval None
  */
void DMA_SoftwareTrigger ( DMA_TypeDef* DMAx )
{
    /* Check the parameters */
    assert_param ( IS_DMA_ALL_PERIPH ( DMAx ) );

    /* Set DMA STS SWREQ Bit */
    DMAx->DMA_STS = DMA_STS_SWREQ;
}
/**
  * @}
  */
/* End of DMA_Group2 ---------------------------------------------------------*/

/** @defgroup DMA_Group3 Interrupts, DMA and flags management functions
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
  * @brief  Gets the transfer status of the specified DMA.
	* @param  DMAx[out]:
  *                 SC32f10xx Selection range(DMA0 - DMA3)
  *                 SC32f11xx Selection range(DMA0 - DMA3)
  *                 SC32f12xx Selection range(DMA0 - DMA1)
  *                 SC32f15xx Selection range(DMA0 - DMA3)
	*                  - DMA0 :select DMA0 peripherals
	*                  - DMA1 :select DMA1 peripherals
	*                  - DMA2 :select DMA2 peripherals
	*                  - DMA3 :select DMA3 peripherals
  * @retval Transfer status of DMA.
  *              - DMA_State_IDLE:DMA idle state
  *              - DMA_State_SOURCE:DMA write source address
  *              - DMA_State_BUSY:DMA reads the source address data and writes to the destination address
  *              - DMA_State_DESTINATION:DMA write destination address
  *              - DMA_State_HANG:DMA Hang state
  *              - DMA_State_PAUSE:DMA Pause state
  *              - DMA_State_BURST:DMA Burst transmission
  *              - DMA_State_STOP:DMA Stop state
  */
DMA_State_TypeDef DMA_GetStatus ( DMA_TypeDef* DMAx )
{
    DMA_State_TypeDef Status;

    /* Check the parameters */
    assert_param ( IS_DMA_ALL_PERIPH ( DMAx ) );

    Status = ( DMA_State_TypeDef ) ( DMAx->DMA_STS & DMA_STS_STATUS );
    return Status;
}


/**
  * @brief  Enables or disables the specified DMAy Streamx interrupts.
	* @param  DMAx[out]:
  *                 SC32f10xx Selection range(DMA0 - DMA3)
  *                 SC32f11xx Selection range(DMA0 - DMA3)
  *                 SC32f12xx Selection range(DMA0 - DMA1)
  *                 SC32f15xx Selection range(DMA0 - DMA3)
	*                  - DMA0 :select DMA0 peripherals
	*                  - DMA1 :select DMA1 peripherals
	*                  - DMA2 :select DMA2 peripherals
	*                  - DMA3 :select DMA3 peripherals
  * @param  DMA_IT[in]: specifies the DMA interrupt sources to be enabled or disabled.
  *                  - DMA_IT_INTEN: DMA IT: INTEN
  *                  - DMA_IT_TCIE: DMA IT: TCIE
  *                  - DMA_IT_HTIE:DMA IT: HTIE
  *                  - DMA_IT_TEIE:DMA IT: TEIE
  * @param  NewState[in]: new state of the specified DMA interrupts.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable
  * @retval None
  */
void DMA_ITConfig ( DMA_TypeDef* DMAx, uint32_t DMA_IT, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_DMA_ALL_PERIPH ( DMAx ) );
    assert_param ( IS_DMA_IT ( DMA_IT ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the selected DMA transfer interrupts */
        DMAx->DMA_CFG |= ( uint32_t ) ( DMA_IT );
    }
    else
    {
        /* Disable the selected DMA transfer interrupts */
        DMAx->DMA_CFG &= ~ ( uint32_t ) ( DMA_IT );
    }
}

/**
  * @brief  Checks whether the specified DMAy Streamx flag is set or not.
	* @param  DMAx[out]:
  *                 SC32f10xx Selection range(DMA0 - DMA3)
  *                 SC32f11xx Selection range(DMA0 - DMA3)
  *                 SC32f12xx Selection range(DMA0 - DMA1)
  *                 SC32f15xx Selection range(DMA0 - DMA3)
	*                  - DMA0 :select DMA0 peripherals
	*                  - DMA1 :select DMA1 peripherals
	*                  - DMA2 :select DMA2 peripherals
	*                  - DMA3 :select DMA3 peripherals
  * @param  DMA_FLAG[in]: specifies the flag to check.
	*                  - DMA_FLAG_GIF:Global interrupt flag
	*                  - DMA_FLAG_TCIF:Transmission completion interrupt flag bit
	*                  - DMA_FLAG_HTIF:Transmit half interrupt flag
	*                  - DMA_FLAG_TEIF:Transmission error interrupt flag
  * @retval The new state of DMA_FLAG (SET or RESET).
  *                  -  RESET:Flag reset
  *                  -  SET :Flag up
  */
FlagStatus DMA_GetFlagStatus ( DMA_TypeDef* DMAx, DMA_Flag_TypeDef DMA_FLAG )
{
    FlagStatus bitstatus = RESET;

    /* Check the parameters */
    assert_param ( IS_DMA_ALL_PERIPH ( DMAx ) );
    assert_param ( IS_GET_DMA_FLAG ( DMA_FLAG ) );


    /* Check the status of the specified DMA flag */
    if ( ( DMAx->DMA_STS & DMA_FLAG ) != ( uint32_t ) RESET )
    {
        /* DMA_FLAG is set */
        bitstatus = SET;
    }
    else
    {
        /* DMA_FLAG is reset */
        bitstatus = RESET;
    }

    /* Return the DMA_FLAG status */
    return  bitstatus;
}

/**
  * @brief  Clears the DMAy Streamx's pending flags.
	* @param  DMAx[out]:
  *                 SC32f10xx Selection range(DMA0 - DMA3)
  *                 SC32f11xx Selection range(DMA0 - DMA3)
  *                 SC32f12xx Selection range(DMA0 - DMA1)
  *                 SC32f15xx Selection range(DMA0 - DMA3)
	*                  - DMA0 :select DMA0 peripherals
	*                  - DMA1 :select DMA1 peripherals
	*                  - DMA2 :select DMA2 peripherals
	*                  - DMA3 :select DMA3 peripherals
  * @param  DMA_FLAG[in]: specifies the flag to clear.
  *                  - DMA_FLAG_GIF : Global interrupt flag
  *                  - DMA_FLAG_TCIF : Transmission completion interrupt flag bit
  *                  - DMA_FLAG_HTIF : Transmit half interrupt flag
  *                  - DMA_FLAG_TEIF : Transmission error interrupt flag
  * @retval None
  */
void DMA_ClearFlag ( DMA_TypeDef* DMAx, uint32_t DMA_FLAG )
{
    /* Check the parameters */
    assert_param ( IS_DMA_ALL_PERIPH ( DMAx ) );
    assert_param ( IS_GET_DMA_FLAG ( DMA_FLAG ) );

    /* Set DMAy STS register clear flag bits */
    DMAx->DMA_STS = ( uint32_t ) ( DMA_FLAG );
}

/**
  * @brief  Enable or disable DMA Requests DMA.
	* @param  DMAx[out]:
  *                 SC32f10xx Selection range(DMA0 - DMA3)
  *                 SC32f11xx Selection range(DMA0 - DMA3)
  *                 SC32f12xx Selection range(DMA0 - DMA1)
  *                 SC32f15xx Selection range(DMA0 - DMA3)
	*                  - DMA0 :select DMA0 peripherals
	*                  - DMA1 :select DMA1 peripherals
	*                  - DMA2 :select DMA2 peripherals
	*                  - DMA3 :select DMA3 peripherals
  * @param DMA_DMARequest[in]: specifies the DMA interrupt sources to be enabled or disabled.
  *                 - DMA_DMAReq_CHRQ:TIM overflow
  * @param NewState[in]:  new state of the specified DMA interrupts.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable
  * @retval None
  */
void DMA_DMACmd ( DMA_TypeDef* DMAx, uint32_t DMA_DMARequest, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_DMA_ALL_PERIPH ( DMAx ) );
    assert_param ( IS_DMA_DMAREQ ( DMA_DMARequest ) );

    /* Config DMA Request */
    if ( NewState != DISABLE )
    {
        /* Enable the selected DMA Request */
        DMAx->DMA_CFG |= ( uint32_t ) ( DMA_DMARequest );
    }
    else
    {
        /* Disable the selected DMA Request */
        DMAx->DMA_CFG &= ( uint32_t ) ~ ( DMA_DMARequest );
    }
}

/**
  * @}
  */
/* End of DMA_Group3 ---------------------------------------------------------*/

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
