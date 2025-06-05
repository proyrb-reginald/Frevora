/*
 ******************************************************************************
 * @file    sc32f1xxx_iap.c
 * @author  SOC AE Team
 * @version V1.7
 * @date     17-10-2024
 * @brief IAP function module
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
#include "sc32f1xxx_iap.h"

/** @defgroup IAP_Group1 FLASH Memory Programming functions
 *  @brief   FLASH Memory Programming functions
 *
@verbatim
 ===============================================================================
                     ##### FLASH Memory Programming functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
  * @brief  Unlocks the FLASH control register access
  * @param  None
  * @retval boolType: The returned value can be: TRUE or FALSE.
	*                 - FALSE
	*                 - TRUE
  */
boolType IAP_Unlock ( void )
{

#if defined(SC32f10xx)
    /* HIRC must be enabled before IAP operation */
    RCC_Unlock ( 0xFF );
    RCC_HIRCCmd ( ENABLE );
#endif
    /* Authorize the FLASH Registers access */
    IAP->IAPKEY = IAP_KEY1;
    IAP->IAPKEY = IAP_KEY2;

    if ( IAP->IAPKEY == 0x01 )
        /* Unlock success */
        return TRUE;
    else
        /* Unlock Error */
        return FALSE;
}

/**
  * @brief  Recovers the FLASH control register access
  * @param  None
  * @retval None
  */
void IAP_Lock ( void )
{
    /* Set the LOCK Bit to lock the FLASH Registers access */
    IAP->IAP_CON = ( uint32_t ) IAP_CON_LOCK;
}

/**
  * @brief  Enables or disables IAP programming features
  * @param  FunctionalState[in]:
	*                  - DISABLE:Function disable
	*                  - ENABLE:Function enable
  * @retval None
  */
void IAP_WriteCmd ( FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        IAP->IAP_CON |= ( uint32_t ) IAP_CON_PRG;
    }
    else
    {
        IAP->IAP_CON &= ~ ( uint32_t ) IAP_CON_PRG;
    }
}

/**
  * @brief  Erases a specified FLASH Sector.
  * @note   If an erase and a program operations are requested simultaneously,
  *         the erase operation is performed before the program one.
  *         Using this function disables the write function.
  * @param  IAP_Sector[in]: The Sector number to be erased.
  * @retval None
  */
void IAP_EraseSector ( uint32_t IAP_Sector )
{
    uint32_t tmpreg;
    IAP->IAP_SNB = 0x4C000000 | IAP_Sector;
    tmpreg = IAP->IAP_CON;
    tmpreg &= ( uint32_t ) ~ ( IAP_CON_ERASE | IAP_CON_CMD | IAP_CON_PRG );
    tmpreg |= ( uint32_t ) ( IAP_CON_SERASE );
    IAP->IAP_CON = tmpreg;
    IAP->IAP_CON |= ( 0x02 << IAP_CON_CMD_Pos );
}

#if defined(SC32f11xx) ||  defined(SC32f12xx) || defined(SC32f15xx)
/**
  * @brief  Erases a specified FLASH Sector.
  * @note   If an erase and a program operations are requested simultaneously,
  *         the erase operation is performed before the program one.
  *         Using this function disables the write function.
  * @param  IAP_Sector[in]: The Sector number to be erased.
  * @retval None
  */
void IAP_EEPROMEraseSector ( uint32_t IAP_Sector )
{
    uint32_t tmpreg;
    IAP->IAP_SNB = 0x69000000 | IAP_Sector;
    tmpreg = IAP->IAP_CON;
    tmpreg &= (uint32_t)~(IAP_CON_ERASE | IAP_CON_CMD | IAP_CON_PRG);
    tmpreg |= (uint32_t)(IAP_CON_SERASE  );
    IAP->IAP_CON = tmpreg;
  	IAP->IAP_CON |= (0x02 << IAP_CON_CMD_Pos);
}

#endif
/**
  * @brief  Program a word (32-bit) at a specified address.
  * @param  Address[in]: specifies the address to be programmed.
  *         This parameter can be any address in Program memory zone or in OTP zone.
  * @param  Data[in]: specifies the data to be programmed.
  * @retval boolType:  The returned value can be: TRUE or FALSE.
	*                 - FALSE
	*                 - TRUE
  */
boolType IAP_ProgramWord ( uint32_t Address, uint32_t Data )
{
    assert_param ( IS_IAP_ADDRESS ( Address ) );

    * ( __IO uint32_t* ) Address = Data;
    if ( Data == * ( __IO uint32_t * ) Address )
        return TRUE;
    else
        return FALSE;

}
#if defined (SC32f10xx) || defined(SC32f11xx)|| defined(SC32f15xx)
/**
  * @brief  Program a half word (16-bit) at a specified address.
  * @param  Address[in]: specifies the address to be programmed.
  *         This parameter can be any address in Program memory zone or in OTP zone.
  * @param  Data[in]: specifies the data to be programmed.
  * @retval boolType: The returned value can be: TRUE or FALSE.
	*                 - FALSE
	*                 - TRUE
  */
boolType IAP_ProgramHalfWord ( uint32_t Address, uint16_t Data )
{
    assert_param ( IS_IAP_ADDRESS ( Address ) );

    * ( __IO uint16_t* ) Address = Data;
    if ( Data == * ( __IO uint16_t * ) Address )
        return TRUE;
    else
        return FALSE;
}

/**
  * @brief  Program a byte (8-bit) at a specified address.
  * @param  Address[in]: specifies the address to be programmed.
  *         This parameter can be any address in Program memory zone or in OTP zone.
  * @param  Data[in]: specifies the data to be programmed.
  * @retval boolType:  The returned value can be: TURE or FALSE.
	*                 - FALSE
	*                 - TRUE
  */
boolType IAP_ProgramByte ( uint32_t Address, uint8_t Data )
{
    assert_param ( IS_IAP_ADDRESS ( Address ) );

    * ( uint8_t* ) Address = Data;
    if ( Data == * ( uint8_t * ) Address )
        return TRUE;
    else
        return FALSE;
}
#elif defined (SC32f12xx)
/**
  * @brief  Program a byte (8-bit) at a specified address.
  * @param  Address[in]: specifies the address to be programmed.
  *         This parameter can be any address in Program memory zone or in OTP zone.
  * @param  Data[in]: specifies the data to be programmed.
  * @retval boolType:  The returned value can be: TURE or FALSE.
	*                 - FALSE
	*                 - TRUE
  */
boolType IAP_ProgramByte ( uint32_t Address, uint8_t Data )
{
    assert_param ( IS_IAP_ADDRESS ( Address ) );

    uint32_t Addr_Temp = Address & 0xFFFFFFFC;
    /*读入对齐地址的数据*/
    uint32_t Data_Temp = * ( __IO uint32_t* ) Addr_Temp;
    /*插入待写入数据*/
    switch ( Address & 0x00000003 )
    {
    case 0:
    {
        Data_Temp |= ( uint32_t ) Data;
        break;
    }
    case 1:
    {
        Data_Temp |= ( uint32_t ) ( Data << 8 );
        break;
    }
    case 2:
    {
        Data_Temp |= ( uint32_t ) ( Data << 16 );
        break;
    }
    default:
    {
        Data_Temp |= ( uint32_t ) ( Data << 24 );
        break;
    }



    }

    /*写入入数据*/
    for ( int i = 2; i > 0 ; i-- )
    {
        * ( __IO uint32_t* ) Addr_Temp = Data_Temp;
    }

    if ( Data_Temp == * ( __IO uint32_t * ) Addr_Temp )
        return TRUE;
    else
        return FALSE;

}
/**
  * @brief  Program a half word (16-bit) at a specified address.
  * @param  Address[in]: specifies the address to be programmed.
  *         This parameter can be any address in Program memory zone or in OTP zone.
  * @param  Data[in]: specifies the data to be programmed.
  * @retval boolType: The returned value can be: TRUE or FALSE.
	*                 - FALSE
	*                 - TRUE
  */
boolType IAP_ProgramHalfWord ( uint32_t Address, uint16_t Data )
{
    assert_param ( IS_IAP_ADDRESS ( Address ) );

    uint32_t Addr_Temp = Address & 0xFFFFFFFC;
    /*读入对齐地址的数据*/
    uint32_t Data_Temp = * ( __IO uint32_t* ) Addr_Temp;
    /*插入待写入数据*/
    switch ( Address & 0x00000003 )
    {
    case 0:
    {
        Data_Temp |= ( uint32_t ) Data;
        break;
    }
    case 1:
    {
        return FALSE;  //地址不对齐，错误
    }
    case 2:
    {
        Data_Temp |= ( uint32_t ) ( Data << 16 );
        break;
    }
    case 3:
    {
        return FALSE;  //地址不对齐，错误
    }
    }

    /*写入入数据*/
    for ( int i = 2; i > 0 ; i-- )
    {
        * ( __IO uint32_t* ) Addr_Temp = Data_Temp;
    }

    if ( Data_Temp == * ( __IO uint32_t * ) Addr_Temp )
        return TRUE;
    else
        return FALSE;

}
#endif
/**
  * @brief  Read a word (32-bit) at a specified address.
  * @param  Address[in]: specifies the address to be read.
  *         This parameter can be any address in Program memory zone or in OTP zone.
  * @retval uint32_t: The data to be read.
  */
uint32_t IAP_ReadWord ( uint32_t Address )
{
    assert_param ( IS_IAP_ADDRESS ( Address ) );

    uint32_t Data;
    Data = * ( __IO uint32_t* ) Address;
    return Data;
}

/**
  * @brief  Read a half word (16-bit) at a specified address.
  * @param  Address[in]: specifies the address to be read.
  *         This parameter can be any address in Program memory zone or in OTP zone.
  * @retval uint16_t: The data to be read.
  */
uint16_t IAP_ReadHalfWord ( uint32_t Address )
{
    assert_param ( IS_IAP_ADDRESS ( Address ) );

    uint16_t Data;
    Data = * ( __IO uint16_t* ) Address;
    return Data;
}

/**
  * @brief  Read a byte (8-bit) at a specified address.
  * @param  Address[in]: specifies the address to be read.
  *         This parameter can be any address in Program memory zone or in OTP zone.
  * @retval uint8_t: The data to be read.
  */
uint8_t IAP_ReadByte ( uint32_t Address )
{
    assert_param ( IS_IAP_ADDRESS ( Address ) );

    uint8_t Data;
    Data = * ( uint8_t* ) Address;
    return Data;
}

/**
  * @brief  Program a word (32-bit) array of configurable length.
  * @param  Address[in]: specifies the address to be program.
  *         This parameter can be any address in Program memory zone or in OTP zone.
  * @param  ByteArray[out]:An array pointer to write data.
  * @param  ArraySize[in]:Array size.
  * @retval uint8_t:The length of the array that needs to be written.
  */
uint8_t IAP_ProgramWordArray ( uint32_t Address, uint32_t* ByteArray, uint16_t ArraySize )
{
    assert_param ( IS_IAP_ADDRESS ( Address ) );

    uint8_t tmpCnt = 0;

    if ( ( Address & 0x03 ) == 0 )
    {
        do
        {
            * ( __IO uint32_t* ) Address = ByteArray[tmpCnt];

            if ( ByteArray[tmpCnt] != * ( __IO uint32_t * ) Address )
                break;

            Address = Address + 4;

        } while ( ++tmpCnt < ArraySize );
    }
    return tmpCnt;

}
#if defined(SC32f10xx) || defined(SC32f11xx) || defined(SC32f15xx)
/**
  * @brief  Program a half word (16-bit) array of configurable length.
  * @param  Address[in]: specifies the address to be program.
  *         This parameter can be any address in Program memory zone or in OTP zone.
  * @param  ByteArray[out]:An array pointer to write data.
  * @param  ArraySize[in]:Array size.
  * @retval uint8_t :The length of the array that needs to be written.
  */

uint8_t IAP_ProgramHalfWordArray ( uint32_t Address, uint16_t* ByteArray, uint16_t ArraySize )
{
    assert_param ( IS_IAP_ADDRESS ( Address ) );

    uint8_t tmpCnt = 0;
    if ( ( Address & 0x01 ) == 0 )
    {
        do
        {

            * ( __IO uint16_t* ) Address = ByteArray[tmpCnt];

            if ( ByteArray[tmpCnt] != * ( __IO uint16_t * ) Address )
                break;

            Address = Address + 2;

        } while ( ++tmpCnt < ArraySize );
    }
    return tmpCnt;
}

/**
  * @brief  Program a half word (16-bit) array of configurable length.
  * @param  Address[in]: specifies the address to be program.
  *         This parameter can be any address in Program memory zone or in OTP zone.
  * @param  ByteArray[out]:An array pointer to write data.
  * @param  ArraySize[in]:Array size.
  * @retval uint8_t :The length of the array that needs to be written.
  */
uint8_t IAP_ProgramByteArray ( uint32_t Address, uint8_t* ByteArray, uint16_t ArraySize )
{
    assert_param ( IS_IAP_ADDRESS ( Address ) );

    uint8_t tmpCnt = 0;
    do
    {
        * ( __IO uint8_t* ) Address = ByteArray[tmpCnt];

        if ( ByteArray[tmpCnt] != * ( __IO uint8_t * ) Address )
            break;

        Address = Address + 1;

    } while ( ++tmpCnt < ArraySize );

    return tmpCnt;
}

#endif
/**
  * @brief  Program a byte (8-bit) array of configurable length.
  * @param  Address[in]: specifies the address to be program.
  *         This parameter can be any address in Program memory zone or in OTP zone.
  * @param  ByteArray[out]:An array pointer to write data.
  * @param  ArraySize[in]:Array size.
  * @retval uint8_t:The length of the array that needs to be written.
  */
uint8_t IAP_ReadWordArray ( uint32_t Address, uint32_t* ByteArray, uint16_t ArraySize )
{
    assert_param ( IS_IAP_ADDRESS ( Address ) );

    uint8_t tmpCnt = 0;
    if ( ( Address & 0x03 ) == 0 )
    {
        do
        {
            ByteArray[tmpCnt] = * ( __IO uint32_t* ) Address;
            Address = Address + 4;

        } while ( ++tmpCnt < ArraySize );
    }
    return tmpCnt;
}

/**
  * @brief  Read a half word (16-bit) array of configurable length.
  * @param  Address[in]: specifies the address to be read.
  *         This parameter can be any address in Program memory zone or in OTP zone.
  * @param  ByteArray[out]:An array pointer to read data.
  * @param  ArraySize[in]:Array size.
  * @retval uint8_t:The length of the array that needs to be read.
  */
uint8_t IAP_ReadHalfWordArray ( uint32_t Address, uint16_t* ByteArray, uint16_t ArraySize )
{
    assert_param ( IS_IAP_ADDRESS ( Address ) );

    uint8_t tmpCnt = 0;
    if ( ( Address & 0x01 ) == 0 )
    {
        do
        {
            ByteArray[tmpCnt] = * ( __IO uint16_t* ) Address;
            Address = Address + 2;

        } while ( ++tmpCnt < ArraySize );
    }
    return tmpCnt;
}

/**
  * @brief  Read a byte (8-bit) array of configurable length.
  * @param  Address[in]: specifies the address to be read.
  *         This parameter can be any address in Program memory zone or in OTP zone.
  * @param  ByteArray[out]:An array pointer to read data.
  * @param  ArraySize[in]:Array size.
  * @retval uint8_t:The length of the array that needs to be read.
  */
uint8_t IAP_ReadByteArray ( uint32_t Address, uint8_t* ByteArray, uint16_t ArraySize )
{
    assert_param ( IS_IAP_ADDRESS ( Address ) );

    uint8_t tmpCnt = 0;
    do
    {
        ByteArray[tmpCnt] = * ( __IO uint8_t* ) Address;
        Address = Address + 1;

    } while ( ++tmpCnt < ArraySize );

    return tmpCnt;
}

/**
 * @}
 */
/* End of IAP_Group1.	*/

/** @defgroup IAP_Group2 Software reset functions
 *  @brief   Software reset functions
 *
@verbatim
 ===============================================================================
                     ##### Software reset  functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
  * @brief  IAP Software Reset.
  * @param  IAP_BTLDType[in]:
  *                   - IAP_BTLD_APPROM :Select the APPROM region
  *                   - IAP_BTLD_LDROM:Select the LDROM region
  *                   - IAP_BTLD_SRAM:Select the SRAM region
	*
  */
void IAP_SoftwareReset ( IAP_BTLD_TypeDef IAP_BTLDType )
{
    IAP->IAP_CON = ( IAP_BTLDType | IAP_CON_RST );
}

#if defined(SC32f15xx)
/** @defgroup IAP_Group3 Automatic continuous burning  functions
 *  @brief   Automatic continuous burning  functions
 *
@verbatim
 ===============================================================================
                     ##### Automatic continuous burning  functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
  * @brief  IAP Software Reset.
  * @param  IAP_BTLDType[in]: 
  *                   - IAP_BTLD_APPROM :Select the APPROM region
  *                   - IAP_BTLD_LDROM:Select the LDROM region
  *                   - IAP_BTLD_SRAM:Select the SRAM region
	*
  */
void IAP_DMAENCmd(FunctionalState NewState)
{
  assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if(NewState != DISABLE)
  {
    IAP->IAP_CON |= (uint32_t)IAP_CON_DMAEN;
  }
  else
  {
    IAP->IAP_CON &= ~(uint32_t)IAP_CON_DMAEN;
  }
}

/**
  * @brief  IAP Software Reset.
  * @param  IAP_BTLDType[in]: 
  *                   - IAP_BTLD_APPROM :Select the APPROM region
  *                   - IAP_BTLD_LDROM:Select the LDROM region
  *                   - IAP_BTLD_SRAM:Select the SRAM region
	*
  */
void IAP_CONTBurnlength(uint8_t Burnlength)
{
   IAP->IAP_CON &=  (uint32_t)IAP_CON_CONT;
	
	 IAP->IAP_CON |=  Burnlength<<IAP_CON_CONT_Pos;
}
/**
 * @}
 */
/* End of IAP_Group3.	*/
#endif

/**
 * @}
 */
/* End of IAP_Group2.	*/

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
