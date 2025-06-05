/**
 ******************************************************************************
 * @file    sc32f1xxx_iap.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   Header file of IAP module.
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
#ifndef __sc32f1xxx_IAP_H
#define __sc32f1xxx_IAP_H

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

/** @addtogroup IAP
 * @{
 */



/** @defgroup IAP_Enumerations IAP Enumerations
 * @{
 */

/** @brief IAP_BTLD IAP Reset Startup area
 * @{
 */
typedef enum
{
    IAP_BTLD_APPROM = ( uint8_t ) 0x00 << IAP_CON_BTLD_Pos,
    IAP_BTLD_LDROM  = ( uint8_t ) 0x01 << IAP_CON_BTLD_Pos,
    IAP_BTLD_SRAM   = ( uint8_t ) 0x02 << IAP_CON_BTLD_Pos,
} IAP_BTLD_TypeDef;

#define IS_IAP_BTLD(BTLD) (((BTLD) == IAP_BTLD_APPROM) || \
                           ((BTLD) == IAP_BTLD_LDROM)  || \
                           ((BTLD) == IAP_BTLD_SRAM))
/**
 * @}
 */
/** @defgroup IAP_Keys
  * @{
  */
///IAP_KEY1 value
#define IAP_KEY1               ((uint32_t)0x12345678)
///IAP_KEY2 value
#define IAP_KEY2               ((uint32_t)0xA05F05FA)
/**
  * @}
  */
/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/


#define IS_IAP_SECTOR(SECTOR) ((SECTOR) <= 0X000001FF)

#define IS_IAP_ADDRESS(ADDRESS) (((ADDRESS) >= 0x08000000) && ((ADDRESS) <= 0x0803FFFF))

/**
 * @}
 */
/* End of constants -----------------------------------------------------*/

/** @addtogroup IAP_Functions IAP Functions
 * @{
 */

/* FLASH Memory Programming functions *****************************************/
boolType IAP_Unlock ( void );
void IAP_Lock ( void );
void IAP_WriteCmd ( FunctionalState NewState );
void IAP_EraseSector ( uint32_t IAP_Sector );
#if defined(SC32f11xx) ||  defined(SC32f12xx)
void IAP_EEPROMEraseSector ( uint32_t IAP_Sector );
#endif
boolType IAP_ProgramWord ( uint32_t Address, uint32_t Data );
#if defined(SC32f10xx) || defined(SC32f11xx)
boolType IAP_ProgramHalfWord ( uint32_t Address, uint16_t Data );
boolType IAP_ProgramByte ( uint32_t Address, uint8_t Data );
#endif
uint32_t IAP_ReadWord ( uint32_t Address );
uint16_t IAP_ReadHalfWord ( uint32_t Address );
uint8_t IAP_ReadByte ( uint32_t Address );
uint8_t IAP_ProgramWordArray ( uint32_t Address, uint32_t* ByteArray, uint16_t ArraySize );
#if defined(SC32f10xx) || defined(SC32f11xx)
uint8_t IAP_ProgramHalfWordArray ( uint32_t Address, uint16_t* ByteArray, uint16_t ArraySize );
uint8_t IAP_ProgramByteArray ( uint32_t Address, uint8_t* ByteArray, uint16_t ArraySize );
#endif
uint8_t IAP_ReadWordArray ( uint32_t Address, uint32_t* ByteArray, uint16_t ArraySize );
uint8_t IAP_ReadHalfWordArray ( uint32_t Address, uint16_t* ByteArray, uint16_t ArraySize );
uint8_t IAP_ReadByteArray ( uint32_t Address, uint8_t* ByteArray, uint16_t ArraySize );

/* FLASH Reset functions *****************************************/
void IAP_SoftwareReset ( IAP_BTLD_TypeDef IAP_BTLDType );
#if defined(SC32f15xx)
/* Automatic continuous burning  functions *****************************************/
void IAP_DMAENCmd(FunctionalState NewState);
void IAP_CONTBurnlength(uint8_t Burnlength);
#endif
/**
 * @}
 */
/* End of functions --------------------------------------------------*/


#ifdef __cplusplus
}
#endif

#endif
/************************ (C) COPYRIGHT SOC Microelectronics *****END OF FILE****/
