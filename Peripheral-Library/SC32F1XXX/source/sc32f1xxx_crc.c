/*
 ******************************************************************************
 * @file    sc32f1xxx_CRC.c
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief  CRC function module
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
#include "sc32f1xxx_crc.h"

static uint32_t CRC_Handle_8 ( uint8_t pBuffer[], uint32_t BufferLength );
static uint32_t CRC_Handle_16 ( uint16_t pBuffer[], uint32_t BufferLength );

/** @defgroup CRC_Group1 Configuration of the CRC computation unit functions
 *  @brief   Configuration of the CRC computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### CRC configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitialize the CRC peripheral registers to their default reset values.
 * @retval None
 */
void CRC_DeInit ( void )
{
    RCC_AHBPeriphResetCmd ( RCC_AHBPeriph_CRC, ENABLE );
    RCC_AHBPeriphResetCmd ( RCC_AHBPeriph_CRC, DISABLE );
}

/**
 * @brief  Initializes the peripheral CRC register according to the parameters specified in CRC_InitStruct
 * @param  CRC_InitStruct[out]:Pointer to structure CRC_InitTypeDef, to be initialized.
 * @retval None
 */
void CRC_Init ( CRC_InitTypeDef* CRC_InitStruct )
{
    /*---------------------------- CRC_CON Configuration ------------------------*/
    /* check whether or not non-default generating polynomial has been
    * picked up by user */
    assert_param ( IS_CRC_POLYSIZE ( CRC_InitStruct->DefaultPolynomialUse ) );
    if ( CRC_InitStruct->DefaultPolynomialUse == DEFAULT_Polynomial_Enable )
    {
        /* initialize peripheral with default generating polynomial */
        CRC->CRC_POL = DEFAULT_CRC32_POLY;

        CRC->CRC_CON &= ( uint32_t ) ~CRC_CON_POLYSIZE;
    }
    else
    {
        /* Check the parameters */
        assert_param ( IS_CRC_POLYSIZE ( CRC_InitStruct->CRCSize ) );

        /* initialize CRC peripheral with generating polynomial defined by user */
        CRC->CRC_POL = CRC_InitStruct->GeneratingPolynomial;

        CRC->CRC_CON &= ( uint32_t ) ~CRC_CON_POLYSIZE;

        /* Set CRC_CON bit to CRCSize value */
        CRC->CRC_CON |= ( uint32_t ) CRC_InitStruct->CRCSize ;
    }

    /* check whether or not non-default CRC initial value has been
     * picked up by user */
    assert_param ( IS_DEFAULT_INITVALUE ( CRC_InitStruct->DefaultInitValueUse ) );
    if ( CRC_InitStruct->DefaultInitValueUse == DEFAULT_InitValue_Enable )
    {
        CRC->CRC_INT = DEFAULT_CRC_INITVALUE;
    }
    else
    {
        CRC->CRC_INT = CRC_InitStruct->InitValue;
    }

}

/**
  * @brief  Selects the polynomial size.
  * @param  CRC_PolSize[in]: Specifies the polynomial size.
	*           - CRC_POLYSIZE_7B:The Size of the polynomial 7Bit
	*           - CRC_POLYSIZE_8B:The Size of the polynomial  8Bit
	*           - CRC_POLYSIZE_16B:The Size of the polynomial 16Bit
	*           - CRC_POLYSIZE_32B:The Size of the polynomial 32Bit
  * @retval None
  */
void CRC_PolynomialSizeSelect ( CRC_POLYSIZE_TypeDef CRC_PolSize )
{
    /* Check the parameter */
    assert_param ( IS_CRC_POLYSIZE ( CRC_PolSize ) );

    /* Reset POL_SIZE bits */
    CRC->CRC_CON &= ( uint32_t ) ~ ( ( uint32_t ) CRC_CON_POLYSIZE );
    /* Set the polynomial size */
    CRC->CRC_CON |= ( uint32_t ) CRC_PolSize;
}


/**
  * @brief  Initializes the CRC register.
  * @param  CRC_InitValue[in]: Programmable initial CRC value
  * @retval None
  */
void CRC_SetInitRegister ( uint32_t CRC_InitValue )
{
    CRC->CRC_INT = CRC_InitValue;
}

/**
  * @brief  Set the coefficients of the POL polynomial.
  * @param  CRC_Pol[in]: Polynomial to be used for CRC calculation.
  * @retval None
  */
void CRC_SetPolynomial ( uint32_t CRC_Pol )
{
    CRC->CRC_POL = CRC_Pol;
}

/** @defgroup CRC_Group2 Data calculation functions
 *  @brief   Data calculation functions
 *
@verbatim
 ===============================================================================
            ##### Data calculation functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  Reset the CRCDR register.
 * @param  None.
 * @retval None.
 */
void CRC_ResetDR ( void )
{
    /* Set CRCRST bit to CRC_CON */
    CRC->CRC_CON |= CRC_CON_CRCRST;
}
/**
 * @}
 */

/**
  * @brief  Computes the 32-bit CRC of a given data word(32-bit).
  * @param  CRC_Data[in]: data word(32-bit) to compute its CRC
  * @retval 32-bit CRC
  */
uint32_t CRC_CalcCRC ( uint32_t CRC_Data )
{
    /* Write to CRC_DR */
    CRC->CRC_DR = CRC_Data;

    return ( CRC->CRC_DR );
}

/**
  * @brief  Computes the 16-bit CRC of a given 16-bit data.
  * @param  CRC_Data[in]: data half-word(16-bit) to compute its CRC
  * @retval 32-bit CRC
  */
uint32_t CRC_CalcCRC16bits ( uint16_t CRC_Data )
{
    * ( volatile uint16_t* ) ( &CRC->CRC_DR ) = ( uint16_t ) CRC_Data;

    return ( CRC->CRC_DR );
}

/**
  * @brief  Computes the 8-bit CRC of a given 8-bit data.
  * @param  CRC_Data[in]: 8-bit data to compute its CRC
  * @retval 8-bit CRC
  */
uint32_t CRC_CalcCRC8bits ( uint8_t CRC_Data )
{
    * ( volatile uint8_t* ) ( &CRC->CRC_DR ) = ( uint8_t ) CRC_Data;
    return ( CRC->CRC_DR );
}


/**
 * @}
 */

/**
 * @brief  Get CRC Result.
 * @param  None.
 * @retval CRC Result Data
 */
uint32_t CRC_GetCRC ( void )
{
    return ( CRC->CRC_DR );
}

/**
 * @}
 */

/**
  * @brief  The CRC checksum is calculated
  * @param  InputDataFormat[in]:Input Buffer Format.
  *                       - CRC_InputData_Format_BYTES:Input data in byte format
  *                       - CRC_InputData_Format_HALFWORDS:Input data in half-word format
  *                       - CRC_InputData_Format_WORDS:Input data in word format
  * @param  pBuffer[in]: pointer to the input data buffer, exact input data format is
  *         provided by hcrc->InputDataFormat.
  * @param  BufferLength[in]:input data buffer length (number of bytes if pBuffer
  *         type is * uint8_t, number of half-words if pBuffer type is * uint16_t,
  *         number of words if pBuffer type is * uint32_t).
  * @retval uint32_t CRC (returned value LSBs for CRC shorter than 32 bits)
  */
uint32_t CRC_Accumulate ( CRC_InputData_Format_TypeDef InputDataFormat, uint32_t pBuffer[], uint32_t BufferLength )
{
    uint32_t index;      /* CRC input data buffer index */
    uint32_t temp = 0U;  /* CRC output (read from CRC->CRC_DRregister) */


    switch ( InputDataFormat )
    {
    case CRC_InputData_Format_WORDS:
        /* Enter Data to the CRC calculator */
        for ( index = 0U; index < BufferLength; index++ )
        {
            CRC->CRC_DR = pBuffer[index];
        }
        temp = CRC->CRC_DR;
        break;

    case CRC_InputData_Format_BYTES:
        temp = CRC_Handle_8 ( ( uint8_t* ) pBuffer, BufferLength );
        break;

    case CRC_InputData_Format_HALFWORDS:
        temp = CRC_Handle_16 ( ( uint16_t* ) ( void* ) pBuffer, BufferLength ); /* Derogation MisraC2012 R.11.5 */
        break;
    }

    /* Return the CRC computed value */
    return temp;
}

/**
  * @brief  Calculate the CRC check value from the first number
  * @param  InputDataFormat[in]:Input Buffer Format
  *                       - CRC_InputData_Format_BYTES:Input data in byte format
  *                       - CRC_InputData_Format_HALFWORDS:Input data in half-word format
  *                       - CRC_InputData_Format_WORDS:Input data in word format
  * @param  pBuffer[in]:pointer to the input data buffer, exact input data format is
  *         provided by hcrc->InputDataFormat.
  * @param  BufferLength[in]:Input data buffer length (number of bytes if pBuffer
  *         type is * uint8_t, number of half-words if pBuffer type is * uint16_t,
  *         number of words if pBuffer type is * uint32_t).
  * @retval uint32_t CRC (returned value LSBs for CRC shorter than 32 bits)
  */
uint32_t CRC_Calculate ( CRC_InputData_Format_TypeDef InputDataFormat, uint32_t pBuffer[], uint32_t BufferLength )
{
    uint32_t index;      /* CRC input data buffer index */
    uint32_t temp = 0U;  /* CRC output (read from CRC->CRC_DRregister) */


    /* Reset CRC Calculation Unit */
    CRC_ResetDR();

    switch ( InputDataFormat )
    {
    case CRC_InputData_Format_WORDS:
        /* Enter 32-bit input data to the CRC calculator */
        for ( index = 0U; index < BufferLength; index++ )
        {
            CRC->CRC_DR = pBuffer[index];
        }
        temp = CRC->CRC_DR;
        break;

    case CRC_InputData_Format_BYTES:
        /* Specific 8-bit input data handling  */
        temp = CRC_Handle_8 ( ( uint8_t* ) pBuffer, BufferLength );
        break;

    case CRC_InputData_Format_HALFWORDS:
        /* Specific 16-bit input data handling  */
        temp = CRC_Handle_16 ( ( uint16_t* ) ( void* ) pBuffer, BufferLength ); /* Derogation MisraC2012 R.11.5 */
        break;
    }

    /* Return the CRC computed value */
    return temp;
}

/**
  * @brief  Enter 8-bit input data to the CRC calculator.
  *         Specific data handling to optimize processing time.
  * @param  pBuffer[in]:pointer to the input data buffer
  * @param  BufferLength[in]:input data buffer length
  * @retval uint32_t CRC (returned value LSBs for CRC shorter than 32 bits)
  */
static uint32_t CRC_Handle_8 ( uint8_t pBuffer[], uint32_t BufferLength )
{
    uint32_t i; /* input data buffer index */
    uint16_t data;
    __IO uint16_t* pReg;

    /* Processing time optimization: 4 bytes are entered in a row with a single word write,
     * last bytes must be carefully fed to the CRC calculator to ensure a correct type
     * handling by the peripheral */
    for ( i = 0U; i < ( BufferLength / 4U ); i++ )
    {
        CRC->CRC_DR = ( ( uint32_t ) pBuffer[4U * i] << 24U ) | \
                      ( ( uint32_t ) pBuffer[ ( 4U * i ) + 1U] << 16U ) | \
                      ( ( uint32_t ) pBuffer[ ( 4U * i ) + 2U] << 8U )  | \
                      ( uint32_t ) pBuffer[ ( 4U * i ) + 3U];
    }
    /* last bytes specific handling */
    if ( ( BufferLength % 4U ) != 0U )
    {
        if ( ( BufferLength % 4U ) == 1U )
        {
            * ( __IO uint8_t* ) ( __IO void* ) ( &CRC->CRC_DR ) = pBuffer[4U * i];  /* Derogation MisraC2012 R.11.5 */
        }
        if ( ( BufferLength % 4U ) == 2U )
        {
            data = ( uint16_t ) ( ( ( uint16_t ) ( pBuffer[4U * i] ) << 8U ) | ( uint16_t ) pBuffer[ ( 4U * i ) + 1U] );
            pReg = ( __IO uint16_t* ) ( __IO void* ) ( &CRC->CRC_DR );              /* Derogation MisraC2012 R.11.5 */
            *pReg = data;
        }
        if ( ( BufferLength % 4U ) == 3U )
        {
            data = ( uint16_t ) ( ( ( uint16_t ) ( pBuffer[4U * i] ) << 8U ) | ( uint16_t ) pBuffer[ ( 4U * i ) + 1U] );
            pReg = ( __IO uint16_t* ) ( __IO void* ) ( &CRC->CRC_DR );              /* Derogation MisraC2012 R.11.5 */
            *pReg = data;

            * ( __IO uint8_t* ) ( __IO void* ) ( &CRC->CRC_DR ) = pBuffer[ ( 4U * i ) + 2U]; /* Derogation MisraC2012 R.11.5 */
        }
    }

    /* Return the CRC computed value */
    return CRC->CRC_DR;
}

/**
  * @brief  Enter 16-bit input data to the CRC calculator.
  *         Specific data handling to optimize processing time.
  * @param  pBuffer[in]:pointer to the input data buffer
  * @param  BufferLength[in]:input data buffer length
  * @retval uint32_t CRC (returned value LSBs for CRC shorter than 32 bits)
  */
static uint32_t CRC_Handle_16 ( uint16_t pBuffer[], uint32_t BufferLength )
{
    uint32_t i;  /* input data buffer index */
    __IO uint16_t* pReg;

    /* Processing time optimization: 2 HalfWords are entered in a row with a single word write,
     * in case of odd length, last HalfWord must be carefully fed to the CRC calculator to ensure
     * a correct type handling by the peripheral */
    for ( i = 0U; i < ( BufferLength / 2U ); i++ )
    {
        CRC->CRC_DR = ( ( uint32_t ) pBuffer[2U * i] << 16U ) | ( uint32_t ) pBuffer[ ( 2U * i ) + 1U];
    }
    if ( ( BufferLength % 2U ) != 0U )
    {
        pReg = ( __IO uint16_t* ) ( __IO void* ) ( &CRC->CRC_DR );           /* Derogation MisraC2012 R.11.5 */
        *pReg = pBuffer[2U * i];
    }

    /* Return the CRC computed value */
    return CRC->CRC_DR;
}

/* End of CRC_Group2.	*/

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

