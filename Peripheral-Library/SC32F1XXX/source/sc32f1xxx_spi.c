/*
 ******************************************************************************
 * @file    sc32f1xxx_spi.c
 * @author  SOC AE Team
 * @version V1.7
 * @date     17-10-2024
 * @brief SPI function module
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
#include "sc32f1xxx_spi.h"

/** @defgroup SPI_Group1 Configuration of the SPI computation unit functions
 *  @brief   Configuration of the SPI computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### SPI configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitialize the SPIx peripheral registers to their default reset values.
 * @param  SPIx[out]:where x can be select the SPIx peripheral.
 *           SC32f10xx Selection range(SPI0 - SPI1)
 *           SC32f11xx Selection range(SPI0 - SPI1)
 *           SC32f12xx Selection range(SPI0 - SPI2)
 *           SC32f15xx Selection range(SPI0 - SPI1)
 *           - SPI0: select the SPI0 peripheral.
 *           - SPI1: select the SPI1 peripheral.
 *           - SPI2: select the SPI2 peripheral.
 * @retval None
 */
void SPI_DeInit ( SPI_TypeDef* SPIx )
{
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    if ( SPIx == SPI0 )
    {
        /* Enable SPI0 reset state */
        RCC_APB0PeriphResetCmd ( RCC_APB0Periph_SPI0, ENABLE );
        /* Release SPI0 from reset state */
        RCC_APB0PeriphResetCmd ( RCC_APB0Periph_SPI0, DISABLE );
    }
    else if ( SPIx == SPI1 )
    {
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
        /* Clear SPI1 Register */
        SPIx->SPI_CON  = ( uint16_t ) 0x00000000;
        SPIx->SPI_DATA = ( uint16_t ) 0x00000000;
        SPIx->SPI_IDE  = ( uint16_t ) 0x00000000;
        SPIx->SPI_STS  = ( uint16_t ) 0x000000FF;
#elif defined(SC32f15xx)
        /* Enable SPI1 reset state */
        RCC_APB1PeriphResetCmd ( RCC_APB1Periph_SPI1_TWI1, ENABLE );
        /* Release SPI1 from reset state */
        RCC_APB1PeriphResetCmd ( RCC_APB1Periph_SPI1_TWI1, DISABLE );
#endif
    }
#if defined(SC32f12xx)
    if ( SPIx == SPI2 )
    {
        /* Clear SPI1 Register */
        SPIx->SPI_CON  = ( uint16_t ) 0x00000000;
        SPIx->SPI_DATA = ( uint16_t ) 0x00000000;
        SPIx->SPI_IDE  = ( uint16_t ) 0x00000000;
        SPIx->SPI_STS  = ( uint16_t ) 0x000000FF;
    }
#endif

}

/**
  * @brief  Fills each SPI_InitStruct member with its default value.
  * @param  SPI_InitStruct[out]: Pointer to structure SPI_InitTypeDef, to be initialized.
  * @retval None
  */
void SPI_StructInit ( SPI_InitTypeDef* SPI_InitStruct )
{
    /* Set the default configuration */
    SPI_InitStruct->SPI_Mode = SPI_Mode_Slave;
    SPI_InitStruct->SPI_DataSize = SPI_DataSize_8B;
    SPI_InitStruct->SPI_FirstBit = SPI_FirstBit_LSB;
    SPI_InitStruct->SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStruct->SPI_CPOL = SPI_CPOL_Low;
    SPI_InitStruct->SPI_Prescaler = SPI_Prescaler_4;
}

/**
 * @brief  Initializes the peripheral SPIx register with the parameters specified in SPI_InitStruct
 * @param  SPIx[out]:where x can be select the SPIx peripheral.
 *           SC32f10xx Selection range(SPI0 - SPI1)
 *           SC32f11xx Selection range(SPI0 - SPI1)
 *           SC32f12xx Selection range(SPI0 - SPI2)
 *           SC32f15xx Selection range(SPI0 - SPI1)
 *           - SPI0: select the SPI0 peripheral.
 *           - SPI1: select the SPI1 peripheral.
 *           - SPI2: select the SPI2 peripheral.
  * @param  SPI_InitStruct[out]: Pointer to structure SPI_InitTypeDef, to be initialized.
 * @retval None
 */
void SPI_Init ( SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    assert_param ( IS_SPI_Mode ( SPI_InitStruct->SPI_Mode ) );
    assert_param ( IS_SPI_DATASIZE ( SPI_InitStruct->SPI_DataSize ) );
    assert_param ( IS_SPI_CPHA ( SPI_InitStruct->SPI_CPHA ) );
    assert_param ( IS_SPI_CPOL ( SPI_InitStruct->SPI_CPOL ) );
    assert_param ( IS_SPI_PRESCALER ( SPI_InitStruct->SPI_Prescaler ) );
    assert_param ( IS_SPI_FIRSTBIT ( SPI_InitStruct->SPI_FirstBit ) );

    /*---------------------------- SPIx SPI_CON Configuration ------------------------*/
    /* Get the SPIx SPI_CON value */
    tmpreg = SPIx->SPI_CON;
    /* Clear MSTR, SPMD, DORD, CPOL, SPR bits */
    tmpreg &= ( uint32_t ) ~ ( SPI_CON_MSTR | SPI_CON_SPMD | SPI_CON_DORD |
                               SPI_CON_CPHA | SPI_CON_CPOL | SPI_CON_SPR );
    /* Configure SPIx: mode, data size, first transmitted bit,clock predivision , CPOL and CPHA */
    /* Set MSTR bits to SPI_Mode value */
    /* Set SPMD bit according to SPI_DataSize value */
    /* Set DORD bit according to SPI_FirstBit value */
    /* Set CPOL bit according to SPI_CPOL value */
    /* Set CPHA bit according to SPI_CPHA value */
    /* Set SPR according to SPI_Prescaler value */
    tmpreg |= ( uint32_t ) ( SPI_InitStruct->SPI_Mode | SPI_InitStruct->SPI_DataSize |
                             SPI_InitStruct->SPI_FirstBit | SPI_InitStruct->SPI_CPHA |
                             SPI_InitStruct->SPI_CPOL | SPI_InitStruct->SPI_Prescaler );
    /* Write to SPIx SPI_CON */
    SPIx->SPI_CON = tmpreg;
#elif defined(SC32f15xx)
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    assert_param ( IS_SPI_Mode ( SPI_InitStruct->SPI_Mode ) );
    assert_param ( IS_SPI_DATASIZE ( SPI_InitStruct->SPI_DataSize ) );
    assert_param ( IS_SPI_CPHA ( SPI_InitStruct->SPI_CPHA ) );
    assert_param ( IS_SPI_CPOL ( SPI_InitStruct->SPI_CPOL ) );
    assert_param ( IS_SPI_PRESCALER ( SPI_InitStruct->SPI_Prescaler ) );
    assert_param ( IS_SPI_FIRSTBIT ( SPI_InitStruct->SPI_FirstBit ) );

    /*---------------------------- SPIx SPI0_CON Configuration ------------------------*/
    if ( SPIx == SPI0 )
    {
        /* Get the SPIx SPI0_CON value */
        tmpreg = SPIx->SPI_CON;
        /* Clear MSTR, SPMD, DORD, CPOL, SPR bits */
        tmpreg &= ( uint32_t ) ~ ( SPI0_CON_MSTR | SPI0_CON_SPMD | SPI0_CON_DORD |
                                   SPI0_CON_CPHA | SPI0_CON_CPOL | SPI0_CON_SPR );
        /* Configure SPIx: mode, data size, first transmitted bit,clock predivision , CPOL and CPHA */
        /* Set MSTR bits to SPI0_Mode value */
        /* Set SPMD bit according to SPI0_DataSize value */
        /* Set DORD bit according to SPI0_FirstBit value */
        /* Set CPOL bit according to SPI0_CPOL value */
        /* Set CPHA bit according to SPI0_CPHA value */
        /* Set SPR according to SPI0_Prescaler value */
        tmpreg |= ( uint32_t ) ( SPI_InitStruct->SPI_Mode | SPI_InitStruct->SPI_DataSize |
                                 SPI_InitStruct->SPI_FirstBit | SPI_InitStruct->SPI_CPHA |
                                 SPI_InitStruct->SPI_CPOL | SPI_InitStruct->SPI_Prescaler );

        /* Write to SPIx SPI0_CON */

        SPIx->SPI_CON = tmpreg;
    }
    if ( SPIx == SPI1 )
    {
        /* Get the SPIx SPI0_CON value */
        tmpreg = SPIx->SPI_CON;
        /* Clear MSTR, SPMD, DORD, CPOL, SPR bits */
        tmpreg &= ( uint32_t ) ~ ( SPI1_CON_MSTR | SPI1_CON_SPMD | SPI1_CON_DORD |
                                   SPI1_CON_CPHA | SPI1_CON_CPOL | SPI1_TWI1_CON_QTWCK );
        /* Configure SPIx: mode, data size, first transmitted bit,clock predivision , CPOL and CPHA */
        /* Set MSTR bits to SPI0_Mode value */
        /* Set SPMD bit according to SPI1_DataSize value */
        /* Set DORD bit according to SPI1_FirstBit value */
        /* Set CPOL bit according to SPI1_CPOL value */
        /* Set CPHA bit according to SPI1_CPHA value */
        /* Set SPR according to SPI0_Prescaler value */
        tmpreg |= ( uint32_t ) ( ( ( SPI_InitStruct->SPI_Mode | SPI_InitStruct->SPI_DataSize |
                                     SPI_InitStruct->SPI_FirstBit | SPI_InitStruct->SPI_CPHA |
                                     SPI_InitStruct->SPI_CPOL ) ) << 16 ) | ( 0x01 << SPI1_TWI1_CON_MODE_Pos ) |
                  SPI_InitStruct->SPI_Prescaler;

        /* Write to SPIx SPI0_CON */

        SPIx->SPI_CON = tmpreg;

    }
#endif
}

/**
 * @brief  Enables or disables the specified SPI peripheral.
 * @param  SPIx[out]:where x can be select the SPIx peripheral.
 *           SC32f10xx Selection range(SPI0 - SPI1)
 *           SC32f11xx Selection range(SPI0 - SPI1)
 *           SC32f12xx Selection range(SPI0 - SPI2)
 *           SC32f15xx Selection range(SPI0 - SPI1)
 *           - SPI0: select the SPI0 peripheral.
 *           - SPI1: select the SPI1 peripheral.
 *           - SPI2: select the SPI2 peripheral.
 * @param  NewState[in]:new state of the SPIx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void SPI_Cmd ( SPI_TypeDef* SPIx, FunctionalState NewState )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );
    if ( NewState != DISABLE )
    {
        /* Enable the SPI TX Function */
        SPIx->SPI_CON |= SPI_CON_SPEN;
    }
    else
    {
        /* Disable the SPI TX Function */
        SPIx->SPI_CON &= ( uint16_t ) ~SPI_CON_SPEN;
    }
#elif defined(SC32f15xx)
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );
    if ( SPIx == SPI0 )
    {
        if ( NewState != DISABLE )
        {
            /* Enable the SPI TX Function */
            SPIx->SPI_CON |= SPI0_CON_SPEN;
        }
        else
        {
            /* Disable the SPI TX Function */
            SPIx->SPI_CON &= ( uint16_t ) ~SPI0_CON_SPEN;
        }
    }
    if ( SPIx == SPI1 )
    {
        if ( NewState != DISABLE )
        {
            /* Enable the SPI TX Function */
            SPIx->SPI_CON |= SPI1_TWI1_CON_QTWEN;
        }
        else
        {
            /* Disable the SPI TX Function */
            SPIx->SPI_CON &= ( uint16_t ) ~SPI1_TWI1_CON_QTWEN;
        }
    }
#endif
}

/**
 * @brief  Set the working mode of the SPI.
 * @param  SPIx[out]:where x can be select the SPIx peripheral.
 *           SC32f10xx Selection range(SPI0 - SPI1)
 *           SC32f11xx Selection range(SPI0 - SPI1)
 *           SC32f12xx Selection range(SPI0 - SPI2)
 *           SC32f15xx Selection range(SPI0 - SPI1)
 *           - SPI0: select the SPI0 peripheral.
 *           - SPI1: select the SPI1 peripheral.
 *           - SPI2: select the SPI2 peripheral.
 * @param  SPIMode[in]:specifies the data transfer direction in bidirectional mode.
 *             - SPI_Mode_Slave:SPI Mode select Slave
 *             - SPI_Mode_Master:SPI Mode select Master
 * @retval None
 */
void SPI_SetMode ( SPI_TypeDef* SPIx, SPI_Mode_TypeDef SPI_Mode )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );

    tmpreg = SPIx->SPI_CON;
    /* Clear MSTR bit */
    tmpreg &= ( uint32_t ) ~SPI_CON_MSTR;
    /* Cogfig MSTR bit */
    tmpreg |= ( uint32_t ) SPI_Mode;
    /* Set new MSTR bit value */
    SPIx->SPI_CON |= tmpreg;
#elif defined(SC32f15xx)
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );

    tmpreg = SPIx->SPI_CON;
    /* Clear MSTR bit */
    tmpreg &= ( uint32_t ) ~SPI0_CON_MSTR;
    /* Cogfig MSTR bit */
    tmpreg |= ( uint32_t ) SPI_Mode;
    if ( SPIx == SPI0 )
    {
        /* Set new MSTR bit value */
        SPIx->SPI_CON |= tmpreg;
    }
    if ( SPIx == SPI1 )
    {
        /* Set new MSTR bit value */
        SPIx->SPI_CON |= ( tmpreg << 16 );
    }
#endif
}

/**
 * @brief  Configures the data size for the selected SPI.
 * @param  SPIx[out]:where x can be select the SPIx peripheral.
 *           SC32f10xx Selection range(SPI0 - SPI1)
 *           SC32f11xx Selection range(SPI0 - SPI1)
 *           SC32f12xx Selection range(SPI0 - SPI2)
 *           SC32f15xx Selection range(SPI0 - SPI1)
 *           - SPI0: select the SPI0 peripheral.
 *           - SPI1: select the SPI1 peripheral.
 *           - SPI2: select the SPI2 peripheral.
  * @param  SPI_DataSize[in]:specifies the SPI data size.
  *               - SPI_DataSize_8B:Set data frame format to 8bit
  *               - SPI_DataSize_16B:Set data frame format to 16bit
  * @retval None
  */
void SPI_DataSizeConfig ( SPI_TypeDef* SPIx, SPI_DataSize_TypeDef SPI_DataSize )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    assert_param ( IS_SPI_DATASIZE ( SPI_DataSize ) );

    /* Clear SPMD bit */
    SPIx->SPI_CON &= ( uint16_t ) ~SPI_CON_SPMD;
    /* Set new SPMD bit value */
    SPIx->SPI_CON |= SPI_DataSize;
#elif defined(SC32f15xx)
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    assert_param ( IS_SPI_DATASIZE ( SPI_DataSize ) );
    if ( SPIx == SPI0 )
    {
        /* Clear SPMD bit */
        SPIx->SPI_CON &= ( uint16_t ) ~SPI0_CON_SPMD;
        /* Set new SPMD bit value */
        SPIx->SPI_CON |= SPI_DataSize;
    }
    if ( SPIx == SPI1 )
    {
        /* Clear SPMD bit */
        SPIx->SPI_CON &= ( uint16_t ) ~SPI1_CON_SPMD;
        /* Set new SPMD bit value */
        SPIx->SPI_CON |= SPI_DataSize << 16;
    }
#endif
}

/**
 * @}
 */
/* End of SPI_Group1.	*/

/** @defgroup SPI_Group2 Data transfers functions
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
 * @param  SPIx[out]:where x can be select the SPIx peripheral.
 *           SC32f10xx Selection range(SPI0 - SPI1)
 *           SC32f11xx Selection range(SPI0 - SPI1)
 *           SC32f12xx Selection range(SPI0 - SPI2)
 *           SC32f15xx Selection range(SPI0 - SPI1)
 *           - SPI0: select the SPI0 peripheral.
 *           - SPI1: select the SPI1 peripheral.
 *           - SPI2: select the SPI2 peripheral.
 * @param  Data[in]: the datas to transmit.
 * @param  length[in]: the data length to tramsmit.
 * @retval None
 */
void SPI_SendDataFIFO ( SPI_TypeDef* SPIx, uint16_t* Data, uint16_t length )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    uint8_t tmpNum;
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    /* Transmit 16Bit Data */
    if ( SPIx->SPI_CON & SPI_CON_SPMD )
    {
        for ( tmpNum = 0; tmpNum < length; tmpNum++ )
        {
            SPIx->SPI_DATA = ( uint16_t ) Data[tmpNum];
        }
    }
    /* Transmit 8 Bit Data */
    else
    {
        for ( tmpNum = 0; tmpNum < length; tmpNum++ )
        {
            SPIx->SPI_DATA = ( uint16_t ) ( * ( ( uint8_t* ) Data + tmpNum ) );
        }
    }
#elif defined(SC32f15xx)
    uint8_t tmpNum;
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    /* Transmit 16Bit Data */
    if ( SPIx == SPI0 )
    {
        if ( SPIx->SPI_CON & SPI0_CON_SPMD )
        {
            for ( tmpNum = 0; tmpNum < length; tmpNum++ )
            {
                SPIx->SPI_DATA = ( uint16_t ) Data[tmpNum];
            }
        }
        /* Transmit 8 Bit Data */
        else
        {
            for ( tmpNum = 0; tmpNum < length; tmpNum++ )
            {
                SPIx->SPI_DATA = ( uint16_t ) ( * ( ( uint8_t* ) Data + tmpNum ) );
            }
        }
    }
#endif
}

/**
 * @brief  SPIx receives data through FIFO.
 * @param  SPIx[out]:where x can be select the SPIx peripheral.
 *           SC32f10xx Selection range(SPI0 - SPI1)
 *           SC32f11xx Selection range(SPI0 - SPI1)
 *           SC32f12xx Selection range(SPI0 - SPI2)
 *           SC32f15xx Selection range(SPI0 - SPI1)
 *           - SPI0: select the SPI0 peripheral.
 *           - SPI1: select the SPI1 peripheral.
 *           - SPI2: select the SPI2 peripheral.
 * @param  Data[in]: the datas to receive.
 * @param  length[in]: the data length to receive.
 * @retval The received data.
 */
void SPI_ReceiveDataFIFO ( SPI_TypeDef* SPIx, uint16_t* Data, uint16_t length )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    uint16_t tmpNum;
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    /* ReceiveData 16Bit Data */
    if ( SPIx->SPI_CON & SPI_CON_SPMD )
    {
        for ( tmpNum = 0; tmpNum < length; tmpNum++ )
        {
            Data[tmpNum] = ( uint16_t ) SPIx->SPI_DATA;
        }
    }
    /* Transmit 8 Bit Data */
    else
    {
        for ( tmpNum = 0; tmpNum < length; tmpNum++ )
        {
            ( * ( ( uint8_t* ) Data + tmpNum ) ) = ( uint8_t ) SPIx->SPI_DATA;
        }
    }
#elif defined(SC32f15xx)
    uint16_t tmpNum;
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    /* ReceiveData 16Bit Data */
    if ( SPIx == SPI0 )
    {
        if ( SPIx->SPI_CON & SPI0_CON_SPMD )
        {
            for ( tmpNum = 0; tmpNum < length; tmpNum++ )
            {
                Data[tmpNum] = ( uint16_t ) SPIx->SPI_DATA;
            }
        }
        /* Transmit 8 Bit Data */
        else
        {
            for ( tmpNum = 0; tmpNum < length; tmpNum++ )
            {
                ( * ( ( uint8_t* ) Data + tmpNum ) ) = ( uint8_t ) SPIx->SPI_DATA;
            }
        }
    }
#endif
}

/**
 * @brief  Send a data through the peripheral SPIx.
 * @param  SPIx[out]:where x can be select the SPIx peripheral.
 *           SC32f10xx Selection range(SPI0 - SPI1)
 *           SC32f11xx Selection range(SPI0 - SPI1)
 *           SC32f12xx Selection range(SPI0 - SPI2)
 *           SC32f15xx Selection range(SPI0 - SPI1)
 *           - SPI0: select the SPI0 peripheral.
 *           - SPI1: select the SPI1 peripheral.
 *           - SPI2: select the SPI2 peripheral.
 * @param  Data[in]: the datas to transmit.
 * @retval None
 */
void SPI_SendData ( SPI_TypeDef* SPIx, uint16_t Data )
{

    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    /* Transmit  Data */
    SPIx->SPI_DATA = ( uint16_t ) Data;

}

/**
 * @brief  Returns the most recent data received through SPIx.
 * @param  SPIx[out]:where x can be select the SPIx peripheral.
 *           SC32f10xx Selection range(SPI0 - SPI1)
 *           SC32f11xx Selection range(SPI0 - SPI1)
 *           SC32f12xx Selection range(SPI0 - SPI2)
 *           SC32f15xx Selection range(SPI0 - SPI1)
 *           - SPI0: select the SPI0 peripheral.
 *           - SPI1: select the SPI1 peripheral.
 *           - SPI2: select the SPI2 peripheral.
 * @retval The received data.
 */
uint16_t SPI_ReceiveData ( SPI_TypeDef* SPIx )
{
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    return ( uint16_t ) SPIx->SPI_DATA;
}

/**
 * @}
 */
/* End of SPI_Group2.	*/

/** @defgroup SPI_Group3 Pin remap management functions
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
 * @brief  Configure remapping pins for SPIx
 * @param  SPIx[out]:where x can be select the SPIx peripheral.
 *           SC32f10xx Selection range(SPI0 - SPI1)
 *           SC32f11xx Selection range(SPI0 - SPI1)
 *           SC32f12xx Selection range(SPI0 - SPI2)
 *           SC32f15xx Selection range(SPI0 - SPI1)
 *           - SPI0: select the SPI0 peripheral.
 *           - SPI1: select the SPI1 peripheral.
 *           - SPI2: select the SPI2 peripheral.
 * @param  SPI_Remap[in]: specifies the TIM input remapping source.
 *             SC32f10xx Selection range(SPI_PinRemap_Default,SPI_PinRemap_A-SPI_PinRemap_B)
 *             SC32f12xx Selection range(SPI_PinRemap_Default,SPI_PinRemap_A-SPI_PinRemap_C)
 *             SC32f15xx Selection range(SPI_PinRemap_Default,SPI_PinRemap_A-SPI_PinRemap_C)
 *            - SPI_PinRemap_Default:TIM Pin Remap Disable
 *            - SPI_PinRemap_A:TIM Pin Remap select Remap mode A
 *            - SPI_PinRemap_B:TIM Pin Remap select Remap mode B
 *            - SPI_PinRemap_C£ºTIM Pin Remap select Remap mode C
 * @retval None
 */
void SPI_PinRemapConfig ( SPI_TypeDef* SPIx, SPI_PinRemap_TypeDef SPI_PinRemap )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    uint32_t tmpreg ;
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    if ( SPIx == SPI0 )
    {
        assert_param ( IS_SPI_LIST1_PINREMAP ( SPI_PinRemap ) );
    }
    else
    {
        assert_param ( IS_SPI_LIST2_PINREMAP ( SPI_PinRemap ) );
    }

    tmpreg = SPIx->SPI_CON;

    tmpreg &= ( uint32_t ) ( ~SPI_CON_SPOS );

    tmpreg |= SPI_PinRemap;

    SPIx->SPI_CON = tmpreg;


#elif defined(SC32f15xx)
    uint32_t tmpreg ;
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    assert_param ( IS_SPI_LIST_PINREMAP ( SPI_PinRemap ) );


    tmpreg = SPIx->SPI_CON;
    if ( SPIx == SPI0 )
    {
        tmpreg &= ( uint32_t ) ( ~SPI0_CON_SPOS );
    }

    if ( SPIx == SPI1 )
    {
        tmpreg &= ( uint32_t ) ( ~SPI1_TWI1_CON_SPOS );
    }
    tmpreg |= SPI_PinRemap;

    SPIx->SPI_CON = tmpreg;
#endif
}

/**
 * @}
 */
/* End of SPI_Group3.	*/

/** @defgroup SPI_Group4 Interrupts, DMA and flags management functions
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
 * @brief  Enables or disables the specified SPI interrupts.
 * @param  SPIx[out]:where x can be select the SPIx peripheral.
 *           SC32f10xx Selection range(SPI0 - SPI1)
 *           SC32f11xx Selection range(SPI0 - SPI1)
 *           SC32f12xx Selection range(SPI0 - SPI2)
 *           SC32f15xx Selection range(SPI0 - SPI1)
 *           - SPI0: select the SPI0 peripheral.
 *           - SPI1: select the SPI1 peripheral.
 *           - SPI2: select the SPI2 peripheral.
 * @param  SPI_IT[in]:specifies the SPI interrupts sources to be enabled or disabled.
 *               - SPI_IT_INTEN:SPI total interruption
 *               - SPI_IT_RXNE:SPI RX buffer not empty Interrupt
 *               - SPI_IT_TB:SPI TX buffer is empty Interrupt
 *               - SPI_IT_RX:Receiving FIFO overflow Interrupt
 *               - SPI_IT_RXH:Receive FIFO over half Interrupt
 *               - SPI_IT_TXH:Transmit FIFO under half Interrupt
 *               - SPI_IT_TBIE£ºSPI Interrupt: Transmit TBIE under half Interrupt 
 * @param  NewState[in]: new state of the SPI interrupts.
 *               - DISABLE:Function disable
 *               - ENABLE:Function enable
 * @retval None
 */
void SPI_ITConfig ( SPI_TypeDef* SPIx, uint16_t SPI_IT, FunctionalState NewState )
{

    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    assert_param ( IS_SPI_IT ( SPI_IT ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );
    if ( NewState != DISABLE )
    {
        /* Enable the Interrupt sources */
        SPIx->SPI_IDE |= SPI_IT;
    }
    else
    {
        /* Disable the Interrupt sources */
        SPIx->SPI_IDE &= ( uint16_t ) ~SPI_IT;
    }

}

/**
 * @brief  Checks whether the specified SPI flag is set or not.
 * @param  SPIx[out]:where x can be select the SPIx peripheral.
 *           SC32f10xx Selection range(SPI0 - SPI1)
 *           SC32f11xx Selection range(SPI0 - SPI1)
 *           SC32f12xx Selection range(SPI0 - SPI2)
 *           SC32f15xx Selection range(SPI0 - SPI1)
 *           - SPI0: select the SPI0 peripheral.
 *           - SPI1: select the SPI1 peripheral.
 *           - SPI2: select the SPI2 peripheral.
 * @param  SPI_FLAG[in]: specifies the flag to check.
 *         - SPI_Flag_SPIF:SPI transmit and receive flag
 *         - SPI_Flag_RINEIF:SPI RX buffer not empty flag
 *         - SPI_Flag_TXEIF:TX buffer is empty flag
 *         - SPI_Flag_RXFIF:Receiving FIFO overflow flag
 *         - SPI_Flag_RXHIF:Receive FIFO over half flag
 *         - SPI_Flag_TXHIF:Transmit FIFO under half flag
 *         - SPI_Flag_WCOL:Write conflict flag
 *         - SPI_FLAG_QTWIF = (uint8_t)SPI1_TWI1_STS_QTWIF  
 * @retval The new state of INT_Flag (SET or RESET).
 *                  -  RESET:Flag reset
 *                  -  SET :Flag up
 */
FlagStatus SPI_GetFlagStatus ( SPI_TypeDef* SPIx, SPI_FLAG_TypeDef SPI_FLAG )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    ITStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    assert_param ( IS_SPI_FLAG ( SPI_FLAG ) );

    if ( ( SPIx->SPI_STS & SPI_FLAG ) != ( uint16_t ) RESET )
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    return bitstatus;
#elif defined(SC32f15xx)
    ITStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    assert_param ( IS_SPI_FLAG ( SPI_FLAG ) );
    if ( SPIx == SPI0 )
    {
        if ( ( SPIx->SPI_STS & SPI_FLAG ) != ( uint16_t ) RESET )
        {
            bitstatus = SET;
        }
        else
        {
            bitstatus = RESET;
        }
    }
    if ( SPIx == SPI1 )
    {
        if ( SPI_FLAG == SPI_Flag_TXEIF )
        {
            if ( ( SPIx->SPI_STS & ( SPI_FLAG << 4 ) ) != ( uint16_t ) RESET )
            {
                bitstatus = SET;
            }
            else
            {
                bitstatus = RESET;
            }
        }
        if ( ( SPIx->SPI_STS & SPI_FLAG ) != ( uint16_t ) RESET )
        {
            bitstatus = SET;
        }
        else
        {
            bitstatus = RESET;
        }
    }
    return bitstatus;
#endif
}

/**
 * @brief  Clears the SPIx's pending flags.
 * @param  SPIx[out]:where x can be select the SPIx peripheral.
 *           SC32f10xx Selection range(SPI0 - SPI1)
 *           SC32f11xx Selection range(SPI0 - SPI1)
 *           SC32f12xx Selection range(SPI0 - SPI2)
 *           SC32f15xx Selection range(SPI0 - SPI1)
 *           - SPI0: select the SPI0 peripheral.
 *           - SPI1: select the SPI1 peripheral.
 *           - SPI2: select the SPI2 peripheral.
 * @param  SPI_FLAG[in]:specifies the flag bit to clear.
 *         - SPI_Flag_SPIF:SPI transmit and receive flag
 *         - SPI_Flag_RINEIF:SPI RX buffer not empty flag
 *         - SPI_Flag_TXEIF:TX buffer is empty flag
 *         - SPI_Flag_RXFIF:Receiving FIFO overflow flag
 *         - SPI_Flag_RXHIF:Receive FIFO over half flag
 *         - SPI_Flag_TXHIF:Transmit FIFO under half flag
 *         - SPI_Flag_WCOL:Write conflict flag
 * @retval None
 */
void SPI_ClearFlag ( SPI_TypeDef* SPIx, uint32_t SPI_FLAG )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    /* Clear the flags */
    SPIx->SPI_STS = ( uint16_t ) SPI_FLAG;
#elif defined(SC32f15xx)
  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  /* Clear the flags */
  if( SPIx == SPI0 )
	{
  SPIx->SPI_STS = (uint16_t)SPI_FLAG;
	}
	 if( SPIx == SPI1 )
	{		
		if(SPI_FLAG == SPI_Flag_TXEIF)
		{
			SPIx->SPI_STS = (uint16_t)SPI_FLAG<<4;
		}
		else
		{
		 SPIx->SPI_STS = (uint16_t)SPI_FLAG;
		}
	}
#endif
}

/**
 * @brief  Enables or disables the SPI's DMA interface.
 * @param  SPIx[out]:where x can be select the SPIx peripheral.
 *           SC32f10xx Selection range(SPI0 - SPI1)
 *           SC32f11xx Selection range(SPI0 - SPI1)
 *           SC32f12xx Selection range(SPI0 - SPI2)
 *           SC32f15xx Selection range(SPI0 - SPI1)
 *           - SPI0: select the SPI0 peripheral.
 *           - SPI1: select the SPI1 peripheral.
 *           - SPI2: select the SPI2 peripheral.
 * @param  SPI_DMAReq[in]: specifies the DMA request.
 *           - SPI_DMAReq_RX:SPI DMA Request Receive
 *           - SPI_DMAReq_TX:SPI DMA Request Transmit
 * @param  NewState[in]:new state of the DMA Request sources.
 *           - DISABLE:Function disable
 *           - ENABLE:Function enable
 * @retval None
 */
void SPI_DMACmd ( SPI_TypeDef* SPIx, uint16_t SPI_DMAReq, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    assert_param ( IS_SPI_DMAREQ ( SPI_DMAReq ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );
    if ( NewState != DISABLE )
    {
        /* Enable the selected SPI DMA requests */
        SPIx->SPI_IDE |= SPI_DMAReq;
    }
    else
    {
        /* Disable the selected SPI DMA requests */
        SPIx->SPI_IDE &= ( uint16_t ) ~SPI_DMAReq;
    }
}

/**
 * @}
 */
/* End of SPI_Group4.	*/

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
