/**
 ******************************************************************************
 * @file    sc32f1xxx_CRC.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   Header file of CRC module.
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
#ifndef __sc32f1xxx_CRC_H
#define __sc32f1xxx_CRC_H

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

/** @addtogroup CRC
 * @{
 */

/* Exported enumerations ------------------------------------------------------------*/
/** @defgroup CRC_Exported_Enumerations CRC Exported Enumerations
 * @{
 */

/** @brief DEFAULT_Polynomial    Indicates whether or not default polynomial is used
  * @{
  */
typedef enum
{
    DEFAULT_Polynomial_Enable		=	( ( uint8_t ) 0x00U ), /*!< Enable default generating polynomial 0x04C11DB7  */
    DEFAULT_Polynomial_Disable	=	( ( uint8_t ) 0x01U ), /*!< Disable default generating polynomial 0x04C11DB7 */
} DEFAULT_Polynomial_TypeDef;

#define IS_DEFAULT_POLYNOMIAL(POSITIVE) (((DEFAULT) == DEFAULT_Polynomial_Enable) || \
																				((DEFAULT) == DEFAULT_Polynomial_Disable))
/**
  * @}
  */

/** @brief DEFAULT_InitValue    Indicates whether or not default init value is used
  * @{
  */
typedef enum
{
    DEFAULT_InitValue_Enable	=	( ( uint8_t ) 0x00U ), /*!< Enable initial CRC default value  */
    DEFAULT_InitValue_Disable	=	( ( uint8_t ) 0x01U ), /*!< Disable initial CRC default value */
} DEFAULT_InitValue_TypeDef;

#define IS_DEFAULT_INITVALUE(VALUE) (((VALUE) == DEFAULT_Polynomial_Enable) || \
																		((VALUE) == DEFAULT_Polynomial_Disable))
/**
  * @}
  */

/** @brief CRC_POLYSIZE CRC POLY Length
 * @{
 */
typedef enum
{
    CRC_POLYSIZE_7B = 0x03U << CRC_CON_POLYSIZE_Pos,    /*!< The Size of the polynomial: 7Bit   */
    CRC_POLYSIZE_8B = 0x02U << CRC_CON_POLYSIZE_Pos,    /*!< The Size of the polynomial: 8Bit   */
    CRC_POLYSIZE_16B = 0x01U << CRC_CON_POLYSIZE_Pos,    /*!< The Size of the polynomial: 16Bit   */
    CRC_POLYSIZE_32B = 0x00U << CRC_CON_POLYSIZE_Pos,   /*!< The Size of the polynomial: 32Bit   */
} CRC_POLYSIZE_TypeDef;

#define IS_CRC_POLYSIZE(POSITIVE) (((POSITIVE) == CRC_POLYSIZE_7B) || \
                                   ((POSITIVE) == CRC_POLYSIZE_8B) || \
                                   ((POSITIVE) == CRC_POLYSIZE_16B) || \
                                   ((POSITIVE) == CRC_POLYSIZE_32B))

/**
 * @}
 */

/** @brief CRC_InputData_Format CRC Input Buffer Format
 * @{
 */
typedef enum
{
    CRC_InputData_Format_BYTES			= 0x00000001U, /*!< Input data in byte format      */
    CRC_InputData_Format_HALFWORDS	= 0x00000002U,  /*!< Input data in half-word format */
    CRC_InputData_Format_WORDS			= 0x00000003U, /*!< Input data in word format      */
} CRC_InputData_Format_TypeDef;

#define IS_CRC_INPUTDATA_FORMAT(FORMAT) (((FORMAT) == CRC_InputData_Format_UNDEFINED) || \
																				((FORMAT) == CRC_InputData_Format_BYTES) || \
																				((FORMAT) == CRC_InputData_Format_HALFWORDS) || \
																				((FORMAT) == CRC_InputData_Format_WORDS))

/**
 * @}
 */

/* End of enumerations -----------------------------------------------------*/

/** @defgroup CRC_Exported_Struct CRC Exported Struct
 * @{
 */

/** @brief CRC Configuration Structure definition
 * @{
 */
typedef struct
{
    uint16_t DefaultPolynomialUse;	/*!< This parameter is a value of @ref DEFAULT_Polynomial_TypeDef and indicates if default polynomial is used.
																										If set to DEFAULT_POLYNOMIAL_ENABLE, resort to default
																										X^32 + X^26 + X^23 + X^22 + X^16 + X^12 + X^11 + X^10 +X^8 + X^7 + X^5 +
																										X^4 + X^2+ X +1.
																										In that case, there is no need to set GeneratingPolynomial field.
																										If otherwise set to DEFAULT_POLYNOMIAL_DISABLE, GeneratingPolynomial and
																										CRCLength fields must be set. */

    uint16_t DefaultInitValueUse;	/*!< This parameter is a value of @ref DEFAULT_InitValue_TypeDef and indicates if default init value is used.
																									If set to DEFAULT_INIT_VALUE_ENABLE, resort to default
																									0xFFFFFFFF value. In that case, there is no need to set InitValue field. If
																									otherwise set to DEFAULT_INIT_VALUE_DISABLE, InitValue field must be set. */

    uint32_t GeneratingPolynomial;      /*!< Set CRC generating polynomial as a 7, 8, 16 or 32-bit long value for a polynomial degree
                                           respectively equal to 7, 8, 16 or 32. This field is written in normal,
                                           representation e.g., for a polynomial of degree 7, X^7 + X^6 + X^5 + X^2 + 1
                                           is written 0x65. No need to specify it if DefaultPolynomialUse is set to
                                            DEFAULT_POLYNOMIAL_ENABLE.   */

    uint32_t InitValue;  /*!< Init value to initiate CRC computation. No need to specify it if DefaultInitValueUse
                                           is set to DEFAULT_INIT_VALUE_ENABLE.   */

    uint32_t CRCSize;                 /*!< This parameter is a value of @ref CRC_POLYSIZE_TypeDef and indicates CRC length. */

} CRC_InitTypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of struct -----------------------------------------------------*/


/** @defgroup  CRC_Macros CRC Macros
  * @{
  */


///   X^32 + X^26 + X^23 + X^22 + X^16 + X^12 + X^11 + X^10 +X^8 + X^7 + X^5 + X^4 + X^2+ X +1
#define DEFAULT_CRC32_POLY      0x04C11DB7U


/** @brief CRC_Default_InitValue    Default CRC computation initialization value
  * @{
  */
///   Initial CRC default value
#define DEFAULT_CRC_INITVALUE   0xFFFFFFFFU
/**
  * @}
  */

/**
 * @}
 */

/** @addtogroup CRC_Functions CRC Functions
 * @{
 */

/* CRC Base functions ********************************************************/
void CRC_DeInit ( void );
void CRC_Init ( CRC_InitTypeDef* CRC_InitStruct );
void CRC_PolynomialSizeSelect ( CRC_POLYSIZE_TypeDef CRC_PolSize );
void CRC_SetInitRegister ( uint32_t CRC_InitValue );
void CRC_SetPolynomial ( uint32_t CRC_Pol );

/* CRC Operate functions ********************************************************/
void CRC_ResetDR ( void );
uint32_t CRC_CalcCRC ( uint32_t CRC_Data );
uint32_t CRC_CalcCRC16bits ( uint16_t CRC_Data );
uint32_t CRC_CalcCRC8bits ( uint8_t CRC_Data );
uint32_t CRC_GetCRC ( void );
uint32_t CRC_Accumulate ( CRC_InputData_Format_TypeDef InputDataFormat, uint32_t pBuffer[], uint32_t BufferLength );
uint32_t CRC_Calculate ( CRC_InputData_Format_TypeDef InputDataFormat, uint32_t pBuffer[], uint32_t BufferLength );
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
