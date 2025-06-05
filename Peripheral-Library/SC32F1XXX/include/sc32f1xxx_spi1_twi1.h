/**
 ******************************************************************************
 * @file    sc32f15Gx_spi.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   Header file of SPI1_TWI1 module.
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
#ifndef __sc32f15Gx_TWI1_SPI1_H
#define __sc32f15Gx_TWI1_SPI1_H

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

/** @addtogroup SPI
 * @{
 */

/** @defgroup SPI1_Exported_Enumerations SPI Exported Enumerations
 * @{
 */

/** @defgroup SPI1_Mode SPI Mode
 * @{
 */
typedef enum
{
  SPI1_Mode_Slave = (uint32_t)(0x00U << SPI1_CON_MSTR_Pos), /*!< SPI Mode:Slave   */
  SPI1_Mode_Master = (uint32_t)(0x01U << SPI1_CON_MSTR_Pos),  /*!< SPI Mode:Master    */
} SPI1_Mode_TypeDef;

#define IS_SPI1_Mode(MODE)	(((MODE) == SPI1_Mode_Master) ||  \
													 ((MODE) == SPI1_Mode_Slave))
/**
 * @}
 */

/** @defgroup SPI1_DataSize SPI Data Size
 * @{
 */
typedef enum
{
  SPI1_DataSize_8B  = (uint32_t)(0X00U << SPI1_CON_SPMD_Pos),  /*!< SPI Data Size:Set data frame format to 8bit    */
  SPI1_DataSize_16B = (uint32_t)(0X01U << SPI1_CON_SPMD_Pos),  /*!< SPI Data Size:Set data frame format to 16bit   */
} SPI1_DataSize_TypeDef;

#define IS_SPI1_DATASIZE(SIZE)	(((SIZE) == SPI1_DataSize_8B) ||  \
															 ((SIZE) == SPI1_DataSize_16B))
/**
 * @}
 */

/** @defgroup SPI1_FirstBit SPI1 First Bit
 * @{
 */
typedef enum
{
  SPI1_FirstBit_MSB = (uint32_t)(0X00U << SPI1_CON_DORD_Pos),  /*!< SPI1 First Bit:MSB    */
  SPI1_FirstBit_LSB = (uint32_t)(0X01U << SPI1_CON_DORD_Pos), /*!< SPI1 First Bit:LSB    */
} SPI1_FirstBit_TypeDef;

#define IS_SPI1_FIRSTBIT(BIT)	(((BIT) == SPI1_FirstBit_MSB) ||  \
															((BIT) == SPI1_FirstBit_LSB))
/**
 * @}
 */

/** @defgroup SPI1_CPHA_TypeDef SPI CPHA
 * @{
 */
typedef enum
{
  SPI1_CPHA_1Edge = (uint32_t)(0X00U << SPI1_CON_CPHA_Pos),  /*!< SPI1 Clock Phase:The first edge signal is triggered   */
  SPI1_CPHA_2Edge = (uint32_t)(0X01U << SPI1_CON_CPHA_Pos), /*!< SPI1 Clock Phase:The second edge signal is triggered    */
} SPI1_CPHA_TypeDef;

#define IS_SPI1_CPHA(CPHA)	(((CPHA) == SPI1_CPHA_1Edge) ||  \
												   ((CPHA) == SPI1_CPHA_2Edge))
/**
 * @}
 */

/** @defgroup SPI1_CPOL SPI CPOL
 * @{
 */
typedef enum
{
  SPI1_CPOL_Low  = (uint32_t)(0X00U << SPI1_CON_CPOL_Pos),  /*!< SPI1 Clock Polarity:It is low in the idle state  */
  SPI1_CPOL_High = (uint32_t)(0X01U << SPI1_CON_CPOL_Pos), /*!< SPI1 Clock Polarity:It is high in the idle state    */
} SPI1_CPOL_TypeDef;

#define IS_SPI1_CPOL(CPOL)	(((CPOL) == SPI1_CPOL_Low) ||  \
													 ((CPOL) == SPI1_CPOL_High))
/**
 * @}
 */

/** @defgroup SPI1_TWI1_Prescaler SPI1_TWI1 Prescaler
 * @{
 */
typedef enum
{
  SPI1_TWI1_Prescaler_1 =  (uint16_t)(0x00U << SPI1_TWI1_CON_QTWCK_Pos),    /*!< Clock division: Fsource/1    */
  SPI1_TWI1_Prescaler_2 =  (uint16_t)(0x01U << SPI1_TWI1_CON_QTWCK_Pos),    /*!< Clock division: Fsource/2    */
  SPI1_TWI1_Prescaler_4 =  (uint16_t)(0x02U << SPI1_TWI1_CON_QTWCK_Pos),    /*!< Clock division: Fsource/4    */
  SPI1_TWI1_Prescaler_8 =  (uint16_t)(0x03U << SPI1_TWI1_CON_QTWCK_Pos),    /*!< Clock division: Fsource/8    */
  SPI1_TWI1_Prescaler_16 = (uint16_t)(0x04U << SPI1_TWI1_CON_QTWCK_Pos),   /*!< Clock division: Fsource/16    */
  SPI1_TWI1_Prescaler_32 = (uint16_t)(0x05U << SPI1_TWI1_CON_QTWCK_Pos),   /*!< Clock division: Fsource/32    */
  SPI1_TWI1_Prescaler_64 = (uint16_t)(0x06U << SPI1_TWI1_CON_QTWCK_Pos),   /*!< Clock division: Fsource/64    */
  SPI1_TWI1_Prescaler_128 = (uint16_t)(0x07U << SPI1_TWI1_CON_QTWCK_Pos),  /*!< Clock division: Fsource/128    */
  SPI1_TWI1_Prescaler_256 = (uint16_t)(0x08U << SPI1_TWI1_CON_QTWCK_Pos),  /*!< Clock division: Fsource/256    */
  SPI1_TWI1_Prescaler_512 = (uint16_t)(0x09U << SPI1_TWI1_CON_QTWCK_Pos),  /*!< Clock division: Fsource/512    */
  SPI1_TWI1_Prescaler_1024 = (uint16_t)(0x0AU << SPI1_TWI1_CON_QTWCK_Pos), /*!< Clock division: Fsource/1024    */
  SPI1_TWI1_Prescaler_2048 = (uint16_t)(0x0BU << SPI1_TWI1_CON_QTWCK_Pos), /*!< Clock division: Fsource/2048   */
	SPI1_TWI1_Prescaler_4096 = (uint16_t)(0x0CU << SPI1_TWI1_CON_QTWCK_Pos), /*!< Clock division: Fsource/2048   */
} SPI1_TWI1_Prescaler_TypeDef;

#define IS_SPI1_TWI1_Prescaler(PRESCALER) (((PRESCALER) == SPI1_TWI1_Prescaler_1) || \
                                     ((PRESCALER) == SPI1_TWI1_Prescaler_2) || \
                                     ((PRESCALER) == SPI1_TWI1_Prescaler_4) || \
                                     ((PRESCALER) == SPI1_TWI1_Prescaler_8) || \
                                     ((PRESCALER) == SPI1_TWI1_Prescaler_16) || \
                                     ((PRESCALER) == SPI1_TWI1_Prescaler_32) || \
                                     ((PRESCALER) == SPI1_TWI1_Prescaler_64) || \
                                     ((PRESCALER) == SPI1_TWI1_Prescaler_128) || \
                                     ((PRESCALER) == SPI1_TWI1_Prescaler_256) || \
                                     ((PRESCALER) == SPI1_TWI1_Prescaler_512) || \
                                     ((PRESCALER) == SPI1_TWI1_Prescaler_1024)|| \
                                     ((PRESCALER) == SPI1_TWI1_Prescaler_2048) || \
                                     ((PRESCALER) == SPI1_TWI1_Prescaler_4096)     )
/**
 * @}SPI1_TWI1_WorkMode SPI1 TWI1 
*/
typedef enum
{
  WorkeMode_TWI1 = (uint32_t)(0X00U << SPI1_TWI1_CON_MODE_Pos),  /*!< WorkeMode TWI1    */
  WorkeMode_SPI1  = (uint32_t)(0X01U << SPI1_TWI1_CON_MODE_Pos), /*!< WorkeMode SPI1   */
} SPI1_TWI1_WorkMode_TypeDef;

#define IS_SPI1_TWI1_WorkMode(WorkMode)	(((WorkMode) == WorkeMode_TWI1) ||  \
												  ((WorkMode) == WorkeMode_SPI1))

/** @defgroup TWI1_Ack TWI1 Ack State
 * @{
 */
typedef enum
{
  TWI1_Ack_Disable = (uint8_t)(0X00U << TWI1_CON_AA_Pos),  /*!< TWI1 Ack:Disable    */
  TWI1_Ack_Enable  = (uint8_t)(0X01U << TWI1_CON_AA_Pos), /*!< TWI1 Ack:Enable   */
} TWI1_Ack_TypeDef;

#define IS_TWI1_ACK(STATE)	(((STATE) == TWI1_Ack_Disable) ||  \
												  ((STATE) == TWI1_Ack_Enable))
/**
 * @}
 */


/** @defgroup TWI1_Stretch TWI1 Stretch State
 * @{
 */
typedef enum
{
  TWI1_Stretch_Disable	= (uint8_t)(0X00U << TWI1_CON_STRETCH_Pos),  /*!< TWI1 Slave Clock Stretch:Disable    */
  TWI1_Stretch_Enable	= (uint8_t)(0X01U << TWI1_CON_STRETCH_Pos), /*!< TWI1 Slave Clock Stretch:Enable   */
} TWI1_Stretch_TypeDef;

#define IS_TWI1_STRETCH(STRETCH)	(((STRETCH) == TWI1_Stretch_Enable) ||  \
																((STRETCH) == TWI1_Stretch_Disable))
/**
 * @}
 */

/** @defgroup TWI1_GeneralCall TWI First Bit
 * @{
 */
typedef enum
{
  TWI1_GeneralCall_Disable = (uint8_t)(0X00U << TWI1_ADD_GC_Pos),  /*!< TWI1 General Call State:Disable    */
  TWI1_GeneralCall_Enable =(uint8_t) (0X01U << TWI1_ADD_GC_Pos), /*!< TWI1 General Call State:Enable    */
} TWI1_GeneralCall_TypeDef;

#define IS_TWI1_GENERALCALL(GENERALCALL)	(((GENERALCALL) == TWI1_GeneralCall_Disable) ||  \
																				((GENERALCALL) == TWI1_GeneralCall_Enable))
/**
 * @}
 */

/** @defgroup TWI1_Command TWI1 Command
 * @{
 */
typedef enum
{
  TWI1_Command_Write = (uint8_t)0X00U,  /*!< TWI1 Command:Write    */
  TWI1_Command_Read  = (uint8_t)0X01U, /*!< TWI1 Command:Read    */
} TWI1_Command_TypeDef;

#define IS_TWI1_COMMAND(COMMAND)	(((COMMAND) == TWI1_Command_Write) ||  \
														    	((COMMAND) == TWI1_Command_Read))
/**
 * @}
 */


/** @defgroup SPI1_TWI1_PinRemap SPI1_TWI1 Pin Remap
 * @{
 */
typedef enum
{
  SPI1_TWI1_PinRemap_Default = (uint32_t)(0x00 << SPI1_TWI1_CON_SPOS_Pos),  /*!< SPI1_TWI1 Pin Remap: Disable */
  SPI1_TWI1_PinRemap_A       = (uint32_t)(0x01 << SPI1_TWI1_CON_SPOS_Pos),  /*!< SPI1_TWI1 Pin Remap: Remap mode A */
  SPI1_TWI1_PinRemap_B       = (uint32_t)(0x02 << SPI1_TWI1_CON_SPOS_Pos),  /*!< SPI1_TWI1 Pin Remap: Remap mode B */
  SPI1_TWI1_PinRemap_C       = (uint32_t)(0x03 << SPI1_TWI1_CON_SPOS_Pos),  /*!< SPI1_TWI1 Pin Remap: Remap mode C */
} SPI1_TWI1_PinRemap_TypeDef;

#define IS_SPI1_TWI1_LIST1_PINREMAP(REMAP) (((REMAP) == SPI1_TWI1_PinRemap_Default) ||  \
																      ((REMAP) == SPI1_TWI1_PinRemap_A) ||  \
																      ((REMAP) == SPI1_TWI1_PinRemap_B) ||  \
																      ((REMAP) == SPI1_TWI1_PinRemap_C))


/**
 * @}
 */

/** @defgroup TWI1_StateMachine TWI1 StateMachine
 * @{
 */
typedef enum
{
  TWI1_Slave_Idle = 0x00 << TWI1_STS_STATE_Pos,
  TWI1_Slave_ReceivedaAddress = 0x01 << TWI1_STS_STATE_Pos,
  TWI1_Slave_ReceivedaData = 0x02 << TWI1_STS_STATE_Pos,
  TWI1_Slave_SendData = 0x03 << TWI1_STS_STATE_Pos,


  TWI1_Master_Idle = 0x00 << TWI1_STS_STATE_Pos,
  TWI1_Master_SendAddress = 0x01 << TWI1_STS_STATE_Pos,
  TWI1_Master_SendData = 0x02 << TWI1_STS_STATE_Pos,
  TWI1_Master_ReceivedaData = 0x03 << TWI1_STS_STATE_Pos,
} TWI1_StateMachine_TypeDef;

#define IS_TWI1_STATEMACHINE(STATE)	(((STATE) == TWI1_Slave_Idle) ||  \
															((STATE) == TWI1_Slave_ReceivedaAddress) ||  \
                              ((STATE) == TWI1_Slave_ReceivedaData) ||  \
                              ((STATE) == TWI1_Slave_SendData)||  \
                              ((STATE) == TWI1_Master_Idle) ||  \
                              ((STATE) == TWI1_Master_SendAddress) ||  \
                              ((STATE) == TWI1_Master_SendData) ||  \
                              ((STATE) == TWI1_Master_ReceivedaData))
/**
 * @}
 */

/** @defgroup SPI1_IT SPI1 Interrupt
 * @{
 */
typedef enum
{
  SPI1_IT_INT = (uint8_t)SPI1_TWI1_IDE_INTEN,	/*!< SPI1 Interrupt: SPI1 Interrupt */
	SPI1_IT_TBIE = (uint8_t)SPI1_IDE_TBIE,
} SPI1_IT_TypeDef;

#define IS_SPI1_IT(IT) (((IT) == SPI1_IT_INT) ||\
                        ((IT) == SPI1_IT_TBIE))
/** @defgroup TWI_IT TWI Interrupt
 * @{
 */
typedef enum
{
 TWI1_IT_INT = (uint8_t)SPI1_TWI1_IDE_INTEN,	/*!< TWI Interrupt: TWI Interrupt */
	
} TWI1_IT_TypeDef;

#define IS_TWI1_IT(IT) ((IT) == TWI1_IT_INT)
/**
 * @}
 */

/** @defgroup SPI1_TWI1_DMAReq SPI1_TWI1 DMA Request
 * @{
 */
typedef enum
{
  SPI1_DMAReq_RX = (uint8_t)SPI1_IDE_RXDMAEN, /*!< SPI1_TWI1 DMA Request: Receive */
  SPI1_DMAReq_TX = (uint8_t)SPI1_IDE_TXDMAEN, /*!< SPI1_TWI1 DMA Request: Transmit */
} SPI1_DMAReq_TypeDef;

#define IS_SPI1_DMAReq(DMAREQ) (((DMAREQ) == SPI1_DMAReq_RX) || \
                                   ((DMAREQ) == SPI1_DMAReq_TX))
/**
 * @}
 */

/** @defgroup SPI1_FLAG SPI1 Flag
 * @{
 */
typedef enum
{
  SPI1_FLAG_QTWIF = (uint8_t)SPI1_TWI1_STS_QTWIF, /*!< SPI1 Flag: Interrupt flag */
	SPI1_FLAG_TXEIF = (uint8_t)SPI1_STS_TXEIF,
	SPI1_FLAG_WCOL = (uint8_t)SPI1_STS_WCOL,
} SPI1_FLAG_TypeDef;

#define IS_SPI1_FLAG(FLAG) (((FLAG) == SPI1_FLAG_QTWIF) || \
                           ((FLAG) == SPI1_FLAG_TXEIF)|| \
                           ((FLAG) == SPI1_FLAG_WCOL))
/** @defgroup TWI1_FLAG TWI1 Flag
 * @{
 */
typedef enum
{
  TWI1_FLAG_QTWIF = (uint8_t)SPI1_TWI1_STS_QTWIF, /*!< TWI1 Flag: Interrupt flag */
  TWI1_FLAG_TXRXnE = (uint8_t)TWI1_STS_TXERXE, /*!< TWI1 Flag: Transmit/receive completion flag */
  TWI1_FLAG_GCA = (uint8_t)TWI1_STS_GCA, /*!< TWI1 Flag: Generic Call flags */
} TWI1_FLAG_TypeDef;

#define IS_TWI1_FLAG(FLAG) (((FLAG) == TWI1_FLAG_QTWIF) || \
                           ((FLAG) == TWI1_FLAG_TXRXnE) || \
                           ((FLAG) == TWI1_FLAG_GCA) )
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @defgroup TWI_Constants TWI Constants
  * @{
  */

#define IS_SPI1_TWI1_ALL_PERIPH(PERIPH) (((PERIPH) == TWI1)|| (PERIPH) == SPI1)
/**
 * @}
 */
/* End of constants -----------------------------------------------------*/

/** @defgroup SPI1_Struct SPI1 Struct
 * @{
 */

/** @defgroup SPI1  base Configuration Structure definition
 * @{
 */
typedef struct
{
  uint32_t SPI1_Mode; /*!< This member configures SPI mode.
                                              This parameter can be a value of @ref SPI1_Mode_TypeDef */

  uint32_t SPI1_DataSize; /*!< This member configures SPI data size.
                                              This parameter can be a value of @ref SPI1_DataSize_TypeDef */


  uint32_t SPI1_CPHA; /*!< This member configures SPI Clock Phase.
                                              This parameter can be a value of @ref SPI1_CPHA_TypeDef */

  uint32_t SPI1_CPOL; /*!< This member configures SPI Clock Polarity.
                                              This parameter can be a value of @ref SPI1_CPOL_TypeDef */

  uint32_t SPI1_FirstBit; /*!< This member configures SPI first transmitted bit.
                                              This parameter can be a value of @ref SPI1_FirstBit_TypeDef */


  uint32_t SPI1_Prescaler; /*!< This member configures SPI clock predivision.
                                              This parameter can be a value of @ref SPI1_TWI1_Prescaler_TypeDef */
} SPI1_InitTypeDef; 

/** @defgroup TWI1_Struct TWI Struct
 * @{
 */

/** @defgroup TWI1 base Configuration Structure definition
 * @{
 */
typedef struct
{
  uint32_t TWI1_Ack; /*!< This member configures TWI Ack.
                                              This parameter can be a value of @ref TWI1_Ack_TypeDef. */

  uint32_t TWI1_Prescaler; /*!< This member configures TWI Prescaler.
                                              This parameter can be a value of @ref SPI1_TWI1_Prescaler_TypeDef. */

  uint32_t TWI1_Stretch; /*!< This member configures TWI Stretch.
                                              This parameter can be a value of @ref TWI1_Stretch_TypeDef. */

  uint32_t TWI1_GeneralCall; /*!< This member configures TWI General Call.
                                              This parameter can be a value of @ref TWI1_GeneralCall_TypeDef. */

  uint32_t TWI1_SlaveAdress; /*!< This member configures TWI SlaveAdress.
                                              This parameter can be a value of 1 to 127. */

} TWI1_InitTypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of Struct -----------------------------------------------------*/

/** @addtogroup TWI_Functions TWI Functions
 * @{
 */

/* spi1_twi1 configuration functions ********************************************************/
void SPI1_TWI1_DeInit(SPITWI_TypeDef* SPIx_TWIx);
void SPI1_StructInit(SPI1_InitTypeDef* SPI1_InitStruct);
void SPI1_Init(SPITWI_TypeDef* SPIx, SPI1_InitTypeDef* SPI1_InitStruct);
void SPI1_Cmd(SPITWI_TypeDef* SPIx, FunctionalState NewState);
void SPI1_SetMode(SPITWI_TypeDef* SPIx, SPI1_Mode_TypeDef SPI1_Mode);
void SPI1_DataSizeConfig(SPITWI_TypeDef* SPIx, SPI1_DataSize_TypeDef SPI1_DataSize);
/*  Data transfers functionsconfiguration functions **************************************/ 
void SPI1_SendData(SPITWI_TypeDef* SPIx, uint16_t Data);
uint16_t SPI1_ReceiveData(SPITWI_TypeDef* SPIx);
void SPI1_ITConfig(SPITWI_TypeDef* SPIx, uint16_t SPI1_IT, FunctionalState NewState);
/*  Interrupts, DMA and flags management functions ********************************************************/
FlagStatus SPI1_GetFlagStatus(SPITWI_TypeDef* SPIx, SPI1_FLAG_TypeDef SPI1_FLAG);
void SPI1_ClearFlag(SPITWI_TypeDef* SPIx, uint32_t SPI1_FLAG);
/*  TWI configuration functions ********************************************************/
void TWI1_StructInit(TWI1_InitTypeDef* TWI1_InitStruct);
void TWI1_Init(SPITWI_TypeDef* TWIx, TWI1_InitTypeDef* TWI_InitStruct);
void TWI1_Cmd(SPITWI_TypeDef* TWIx, FunctionalState NewState);
void TWI1_AcknowledgeConfig(SPITWI_TypeDef* TWIx, FunctionalState NewState);
void TWI1_GeneralCallCmd(SPITWI_TypeDef* TWIx, FunctionalState NewState);
void TWI1_StretchClockConfig(SPITWI_TypeDef* TWIx, FunctionalState NewState);
void TWI1_SetNbytes(SPITWI_TypeDef* TWIx, uint8_t Nbytes);
uint8_t TWI1_GetNbytes(SPITWI_TypeDef* TWIx);
/*  Data transfers functions ********************************************************/
void TWI1_GenerateSTART(SPITWI_TypeDef* TWIx, FunctionalState NewState);
void TWI1_GenerateSTOP(SPITWI_TypeDef* TWIx, FunctionalState NewState);
void TWI1_Send7bitAddress(SPITWI_TypeDef* TWIx, uint8_t Address, TWI1_Command_TypeDef TWI1_Command);
void TWI1_SendData(SPITWI_TypeDef* TWIx, uint16_t Data);
uint16_t TWI1_ReceiveData(SPITWI_TypeDef* TWIx);
TWI1_StateMachine_TypeDef TWI1_GetStateMachine(SPITWI_TypeDef* TWIx);
/* Pin remap management functions  **********************************************/
void SPI1_TWI1_PinRemapConfig(SPITWI_TypeDef* SPIx_TWIx, SPI1_TWI1_PinRemap_TypeDef TWI1_Remap);
/* Interrupts, DMA and flags management functions  **********************************************/
void TWI1_ITConfig(SPITWI_TypeDef* TWIx, uint16_t TWI1_IT, FunctionalState NewState);
FlagStatus TWI1_GetFlagStatus(SPITWI_TypeDef* TWIx, TWI1_FLAG_TypeDef TWI1_FLAG);
void TWI1_ClearFlag(SPITWI_TypeDef* TWIx, TWI1_FLAG_TypeDef TWI1_FLAG);
void SPI1_DMACmd(SPITWI_TypeDef* SPIx, SPI1_DMAReq_TypeDef SPI1_DMAReq, FunctionalState NewState);
void SPI1_TWI1_PinRemapConfig(SPITWI_TypeDef* SPIx_TWIx, SPI1_TWI1_PinRemap_TypeDef SPI1_TWI1_Remap);
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
