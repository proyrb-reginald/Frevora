/**
 ******************************************************************************
 * @file    sc32f1xxx_spi.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   Header file of SPI module.
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
#ifndef __sc32f1xxx_SPI_H
#define __sc32f1xxx_SPI_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "sc32f1xxx.h"
#include "sc32.h"
#include "sc32f1xxx_rcc.h"
#if !defined(SC32f15xx)
/** @addtogroup sc32f1xxx_StdPeriph_Driver
 * @{
 */

/** @addtogroup SPI
 * @{
 */

/** @defgroup SPI_Exported_Enumerations SPI Exported Enumerations
 * @{
 */

/** @brief SPI_Mode SPI Mode
 * @{
 */
typedef enum
{
    SPI_Mode_Slave = ( uint16_t ) ( 0X00U << SPI_CON_MSTR_Pos ), /*!< SPI Mode:Slave   */
    SPI_Mode_Master = ( uint16_t ) ( 0X01U << SPI_CON_MSTR_Pos ), /*!< SPI Mode:Master    */
} SPI_Mode_TypeDef;

#define IS_SPI_Mode(MODE)	(((MODE) == SPI_Mode_Master) ||  \
													 ((MODE) == SPI_Mode_Slave))
/**
 * @}
 */

/** @brief SPI_DataSize SPI Data Size
 * @{
 */
typedef enum
{
    SPI_DataSize_8B  = ( uint16_t ) ( 0X00U << SPI_CON_SPMD_Pos ), /*!< SPI Data Size:Set data frame format to 8bit    */
    SPI_DataSize_16B = ( uint16_t ) ( 0X01U << SPI_CON_SPMD_Pos ), /*!< SPI Data Size:Set data frame format to 16bit   */
} SPI_DataSize_TypeDef;

#define IS_SPI_DATASIZE(SIZE)	(((SIZE) == SPI_DataSize_8B) ||  \
															 ((SIZE) == SPI_DataSize_16B))
/**
 * @}
 */

/** @brief SPI_FirstBit SPI First Bit
 * @{
 */
typedef enum
{
    SPI_FirstBit_MSB = ( uint16_t ) ( 0X00U << SPI_CON_DORD_Pos ), /*!< SPI First Bit:MSB    */
    SPI_FirstBit_LSB = ( uint16_t ) ( 0X01U << SPI_CON_DORD_Pos ), /*!< SPI First Bit:LSB    */
} SPI_FirstBit_TypeDef;

#define IS_SPI_FIRSTBIT(BIT)	(((BIT) == SPI_FirstBit_MSB) ||  \
															((BIT) == SPI_FirstBit_LSB))
/**
 * @}
 */

/** @brief SPI_CPHA_TypeDef SPI CPHA
 * @{
 */
typedef enum
{
    SPI_CPHA_1Edge = ( uint16_t ) ( 0X00U << SPI_CON_CPHA_Pos ), /*!< SPI Clock Phase:The first edge signal is triggered   */
    SPI_CPHA_2Edge = ( uint16_t ) ( 0X01U << SPI_CON_CPHA_Pos ), /*!< SPI Clock Phase:The second edge signal is triggered    */
} SPI_CPHA_TypeDef;

#define IS_SPI_CPHA(CPHA)	(((CPHA) == SPI_CPHA_1Edge) ||  \
												   ((CPHA) == SPI_CPHA_2Edge))
/**
 * @}
 */

/** @brief SPI_CPOL SPI CPOL
 * @{
 */
typedef enum
{
    SPI_CPOL_Low  = ( uint16_t ) ( 0X00U << SPI_CON_CPOL_Pos ), /*!< SPI Clock Polarity:It is low in the idle state  */
    SPI_CPOL_High = ( uint16_t ) ( 0X01U << SPI_CON_CPOL_Pos ), /*!< SPI Clock Polarity:It is high in the idle state    */
} SPI_CPOL_TypeDef;

#define IS_SPI_CPOL(CPOL)	(((CPOL) == SPI_CPOL_Low) ||  \
													 ((CPOL) == SPI_CPOL_High))
/**
 * @}
 */

/** @brief SPI_Prescaler SPI Prescaler
 * @{
 */
typedef enum
{
    SPI_Prescaler_1 = 0x00U << SPI_CON_SPR_Pos,    /*!< Clock division: Fsource/1    */
    SPI_Prescaler_2 = 0x01U << SPI_CON_SPR_Pos,    /*!< Clock division: Fsource/2    */
    SPI_Prescaler_4 = 0x02U << SPI_CON_SPR_Pos,    /*!< Clock division: Fsource/4    */
    SPI_Prescaler_8 = 0x03U << SPI_CON_SPR_Pos,    /*!< Clock division: Fsource/8    */
    SPI_Prescaler_16 = 0x04U << SPI_CON_SPR_Pos,   /*!< Clock division: Fsource/16    */
    SPI_Prescaler_32 = 0x05U << SPI_CON_SPR_Pos,   /*!< Clock division: Fsource/32    */
    SPI_Prescaler_64 = 0x06U << SPI_CON_SPR_Pos,   /*!< Clock division: Fsource/64    */
    SPI_Prescaler_128 = 0x07U << SPI_CON_SPR_Pos,  /*!< Clock division: Fsource/128    */
    SPI_Prescaler_256 = 0x08U << SPI_CON_SPR_Pos,  /*!< Clock division: Fsource/256    */
    SPI_Prescaler_512 = 0x09U << SPI_CON_SPR_Pos,  /*!< Clock division: Fsource/512    */
    SPI_Prescaler_1024 = 0x0AU << SPI_CON_SPR_Pos, /*!< Clock division: Fsource/1024    */
} SPI_Prescaler_TypeDef;

#define IS_SPI_PRESCALER(PRESCALER) (((PRESCALER) == SPI_Prescaler_1) || \
                                     ((PRESCALER) == SPI_Prescaler_2) || \
                                     ((PRESCALER) == SPI_Prescaler_4) || \
                                     ((PRESCALER) == SPI_Prescaler_8) || \
                                     ((PRESCALER) == SPI_Prescaler_16) || \
                                     ((PRESCALER) == SPI_Prescaler_32) || \
                                     ((PRESCALER) == SPI_Prescaler_64) || \
                                     ((PRESCALER) == SPI_Prescaler_128) || \
                                     ((PRESCALER) == SPI_Prescaler_256) || \
                                     ((PRESCALER) == SPI_Prescaler_512) || \
                                     ((PRESCALER) == SPI_Prescaler_1024))

/**
 * @}
 */

/** @brief SPI_PinRemap TIM Pin Remap
 * @{
 */
#if defined(SC32f10xx)
typedef enum
{
    SPI_PinRemap_Default = ( uint32_t ) ( 0x00 << SPI_CON_SPOS_Pos ), /*!< TIM Pin Remap: Disable */
    SPI_PinRemap_A       = ( uint32_t ) ( 0x01 << SPI_CON_SPOS_Pos ), /*!< TIM Pin Remap: Remap mode A */
    SPI_PinRemap_B       = ( uint32_t ) ( 0x02 << SPI_CON_SPOS_Pos ), /*!< TIM Pin Remap: Remap mode B */
} SPI_PinRemap_TypeDef;

#define IS_SPI_LIST1_PINREMAP(REMAP) (((REMAP) == SPI_PinRemap_Default) ||  \
															      	((REMAP) == SPI_PinRemap_A)  ||  \
																      ((REMAP) == SPI_PinRemap_B))

#define IS_SPI_LIST2_PINREMAP(REMAP) (((REMAP) == SPI_PinRemap_Default) ||  \
															      	((REMAP) == SPI_PinRemap_A))
#elif  defined(SC32f11xx)||defined(SC32f12xx)
typedef enum
{
    SPI_PinRemap_Default = ( uint32_t ) ( 0x00 << SPI_CON_SPOS_Pos ), /*!< TIM Pin Remap: Disable */
    SPI_PinRemap_A       = ( uint32_t ) ( 0x01 << SPI_CON_SPOS_Pos ), /*!< TIM Pin Remap: Remap mode A */
    SPI_PinRemap_B       = ( uint32_t ) ( 0x02 << SPI_CON_SPOS_Pos ), /*!< TIM Pin Remap: Remap mode B */
    SPI_PinRemap_C       = ( uint32_t ) ( 0x03 << SPI_CON_SPOS_Pos ), /*!< TIM Pin Remap: Remap mode C */
} SPI_PinRemap_TypeDef;

#define IS_SPI_LIST1_PINREMAP(REMAP) (((REMAP) == SPI_PinRemap_Default) ||  \
															      	((REMAP) == SPI_PinRemap_A)  ||  \
																      ((REMAP) == SPI_PinRemap_B)  ||  \
                                      ((REMAP) == SPI_PinRemap_C))

#define IS_SPI_LIST2_PINREMAP(REMAP) (((REMAP) == SPI_PinRemap_Default) ||  \
															      	((REMAP) == SPI_PinRemap_A)  ||  \
																      ((REMAP) == SPI_PinRemap_B)  ||  \
                                      ((REMAP) == SPI_PinRemap_C))
#endif
/**
 * @}
 */

/** @brief SPI_IT SPI Interrupt
 * @{
 */
typedef enum
{
    SPI_IT_INTEN = ( uint32_t ) SPI_IDE_INTEN,	/*!< SPI Interrupt: SPI total interruption */
    SPI_IT_RXNE  = ( uint32_t ) SPI_IDE_RXNEIE,	/*!< SPI Interrupt: SPI RX buffer not empty Interrupt */
    SPI_IT_TB    = ( uint32_t ) SPI_IDE_TBIE,  		/*!< SPI Interrupt: SPI TX buffer is empty Interrupt */
    SPI_IT_RX    = ( uint32_t ) SPI_IDE_RXIE,  		/*!< SPI Interrupt: Receiving FIFO overflow Interrupt */
    SPI_IT_RXH   = ( uint32_t ) SPI_IDE_RXHIE,  	/*!< SPI Interrupt: Receive FIFO over half Interrupt */
    SPI_IT_TXH   = ( uint32_t ) SPI_IDE_TXHIE,  	/*!< SPI Interrupt: Transmit FIFO under half Interrupt */
} SPI_IT_TypeDef;

#define IS_SPI_IT(IT) (((IT) == SPI_IT_INTEN) || \
                       ((IT) == SPI_IT_RXNE) || \
                       ((IT) == SPI_IT_TB) || \
                       ((IT) == SPI_IT_RX) || \
											 ((IT) == SPI_IT_RXH) || \
                       ((IT) == SPI_IT_TXH)|| \
                       ((IT) == SPI_IT_TBIE))

/**
 * @}
 */

/** @brief SPI_FLAG SPI Flag
 * @{
 */
typedef enum
{
    SPI_Flag_SPIF   = ( uint32_t ) SPI_STS_SPIF, /*!< SPI Flag: SPI transmit and receive flag */
    SPI_Flag_RINEIF = ( uint32_t ) SPI_STS_RINEIF, /*!< SPI Flag: SPI RX buffer not empty flag */
    SPI_Flag_TXEIF  = ( uint32_t ) SPI_STS_TXEIF, /*!< SPI Flag: TX buffer is empty flag */
    SPI_Flag_RXFIF  = ( uint32_t ) SPI_STS_RXFIF, /*!< SPI Flag: Receiving FIFO overflow flag */
    SPI_Flag_RXHIF  = ( uint32_t ) SPI_STS_RXHIF, /*!< SPI Flag: Receive FIFO over half flag */
    SPI_Flag_TXHIF  = ( uint32_t ) SPI_STS_TXHIF, /*!< SPI Flag: Transmit FIFO under half flag */
    SPI_Flag_WCOL   = ( uint32_t ) SPI_STS_WCOL, /*!< SPI Flag: Write conflict flag */

} SPI_FLAG_TypeDef;

#define IS_SPI_FLAG(FLAG) (((FLAG) == SPI_Flag_SPIF) || \
                           ((FLAG) == SPI_Flag_RINEIF) || \
                           ((FLAG) == SPI_Flag_TXEIF) || \
                           ((FLAG) == SPI_Flag_RXFIF) || \
                           ((FLAG) == SPI_Flag_RXHIF) || \
                           ((FLAG) == SPI_Flag_TXHIF) || \
                           ((FLAG) == SPI_Flag_WCOL))

/**
 * @}
 */

/** @brief SPI_DMAReq SPI DMA Request
 * @{
 */
typedef enum
{
    SPI_DMAReq_RX = ( uint32_t ) SPI_IDE_RXDMAEN, /*!< SPI DMA Request: Receive */
    SPI_DMAReq_TX = ( uint32_t ) SPI_IDE_TXDMAEN, /*!< SPI DMA Request: Transmit */
} SPI_DMAReq_TypeDef;

#define IS_SPI_DMAREQ(DMAREQ) (((DMAREQ) == SPI_DMAReq_RX) || \
                               ((DMAREQ) == SPI_DMAReq_TX))
/**
 * @}
 */

/**
 * @}
 */

/** @brief SPI_Constants SPI Constants
  * @{
  */
#if defined(SC32f10xx)  ||defined(SC32f11xx)
#define IS_SPI_ALL_PERIPH(PERIPH) (((PERIPH) == SPI0) || \
                                   ((PERIPH) == SPI1))
#elif defined(SC32f12xx)
#define IS_SPI_ALL_PERIPH(PERIPH) (((PERIPH) == SPI0) || \
                                   ((PERIPH) == SPI1) ||\
                                   ((PERIPH) == SPI2)  )
#endif
#else
/** @defgroup SPI_Mode SPI Mode
 * @{
 */
typedef enum
{
  SPI_Mode_Slave = (uint16_t)(0X00U << SPI0_CON_MSTR_Pos), /*!< SPI Mode:Slave   */
  SPI_Mode_Master = (uint16_t)(0X01U << SPI0_CON_MSTR_Pos),  /*!< SPI Mode:Master    */
} SPI_Mode_TypeDef;

#define IS_SPI_Mode(MODE)	(((MODE) == SPI_Mode_Master) ||  \
													 ((MODE) == SPI_Mode_Slave))
/**
 * @}
 */

/** @defgroup SPI_DataSize SPI Data Size
 * @{
 */
typedef enum
{
  SPI_DataSize_8B  = (uint16_t)(0X00U << SPI0_CON_SPMD_Pos),  /*!< SPI Data Size:Set data frame format to 8bit    */
  SPI_DataSize_16B = (uint16_t)(0X01U << SPI0_CON_SPMD_Pos),  /*!< SPI Data Size:Set data frame format to 16bit   */
} SPI_DataSize_TypeDef;

#define IS_SPI_DATASIZE(SIZE)	(((SIZE) == SPI_DataSize_8B) ||  \
															 ((SIZE) == SPI_DataSize_16B))
/**
 * @}
 */

/** @defgroup SPI0_FirstBit SPI First Bit
 * @{
 */
typedef enum
{
  SPI_FirstBit_MSB = (uint16_t)(0X00U << SPI0_CON_DORD_Pos),  /*!< SPI First Bit:MSB    */
  SPI_FirstBit_LSB = (uint16_t)(0X01U << SPI0_CON_DORD_Pos), /*!< SPI First Bit:LSB    */
} SPI_FirstBit_TypeDef;

#define IS_SPI_FIRSTBIT(BIT)	(((BIT) == SPI_FirstBit_MSB) ||  \
															((BIT) == SPI_FirstBit_LSB))
/**
 * @}
 */

/** @defgroup SPI_CPHA_TypeDef SPI CPHA
 * @{
 */
typedef enum
{
  SPI_CPHA_1Edge = (uint16_t)(0X00U << SPI0_CON_CPHA_Pos),  /*!< SPI Clock Phase:The first edge signal is triggered   */
  SPI_CPHA_2Edge = (uint16_t)(0X01U << SPI0_CON_CPHA_Pos), /*!< SPI Clock Phase:The second edge signal is triggered    */
} SPI_CPHA_TypeDef;

#define IS_SPI_CPHA(CPHA)	(((CPHA) == SPI_CPHA_1Edge) ||  \
												   ((CPHA) == SPI_CPHA_2Edge))
/**
 * @}
 */

/** @defgroup SPI_CPOL SPI CPOL
 * @{
 */
typedef enum
{
  SPI_CPOL_Low  = (uint16_t)(0X00U << SPI0_CON_CPOL_Pos),  /*!< SPI Clock Polarity:It is low in the idle state  */
  SPI_CPOL_High = (uint16_t)(0X01U << SPI0_CON_CPOL_Pos), /*!< SPI Clock Polarity:It is high in the idle state    */
} SPI_CPOL_TypeDef;

#define IS_SPI_CPOL(CPOL)	(((CPOL) == SPI_CPOL_Low) ||  \
													 ((CPOL) == SPI_CPOL_High))
/**
 * @}
 */

/** @defgroup SPI_Prescaler SPI Prescaler
 * @{
 */
typedef enum
{
  SPI_Prescaler_1 = 0x00U << SPI0_CON_SPR_Pos,    /*!< Clock division: Fsource/1    */
  SPI_Prescaler_2 = 0x01U << SPI0_CON_SPR_Pos,    /*!< Clock division: Fsource/2    */
  SPI_Prescaler_4 = 0x02U << SPI0_CON_SPR_Pos,    /*!< Clock division: Fsource/4    */
  SPI_Prescaler_8 = 0x03U << SPI0_CON_SPR_Pos,    /*!< Clock division: Fsource/8    */
  SPI_Prescaler_16 = 0x04U << SPI0_CON_SPR_Pos,   /*!< Clock division: Fsource/16    */
  SPI_Prescaler_32 = 0x05U << SPI0_CON_SPR_Pos,   /*!< Clock division: Fsource/32    */
  SPI_Prescaler_64 = 0x06U << SPI0_CON_SPR_Pos,   /*!< Clock division: Fsource/64    */
  SPI_Prescaler_128 = 0x07U << SPI0_CON_SPR_Pos,  /*!< Clock division: Fsource/128    */
  SPI_Prescaler_256 = 0x08U << SPI0_CON_SPR_Pos,  /*!< Clock division: Fsource/256    */
  SPI_Prescaler_512 = 0x09U << SPI0_CON_SPR_Pos,  /*!< Clock division: Fsource/512    */
  SPI_Prescaler_1024 = 0x0AU << SPI0_CON_SPR_Pos, /*!< Clock division: Fsource/1024    */
  
  SPI_Prescaler_2048 = (uint16_t)(0x0BU << SPI1_TWI1_CON_QTWCK_Pos), /*!< Clock division: Fsource/2048   */
	SPI_Prescaler_4096 = (uint16_t)(0x0CU << SPI1_TWI1_CON_QTWCK_Pos), /*!< Clock division: Fsource/2048   */
} SPI_Prescaler_TypeDef;

#define IS_SPI_PRESCALER(PRESCALER) (((PRESCALER) == SPI_Prescaler_1) || \
                                     ((PRESCALER) == SPI_Prescaler_2) || \
                                     ((PRESCALER) == SPI_Prescaler_4) || \
                                     ((PRESCALER) == SPI_Prescaler_8) || \
                                     ((PRESCALER) == SPI_Prescaler_16) || \
                                     ((PRESCALER) == SPI_Prescaler_32) || \
                                     ((PRESCALER) == SPI_Prescaler_64) || \
                                     ((PRESCALER) == SPI_Prescaler_128) || \
                                     ((PRESCALER) == SPI_Prescaler_256) || \
                                     ((PRESCALER) == SPI_Prescaler_512) || \
                                     ((PRESCALER) == SPI_Prescaler_1024)|| \
                                     ((PRESCALER) == SPI_Prescaler_2048) || \
                                     ((PRESCALER) == SPI_Prescaler_4096) )
/**
 * @}
 */

/** @defgroup SPI_PinRemap TIM Pin Remap
 * @{
 */
typedef enum
{
  SPI_PinRemap_Default = (uint32_t)(0x00 << SPI0_CON_SPOS_Pos),  /*!< SPI0 Pin Remap: Disable */
  SPI_PinRemap_A       = (uint32_t)(0x01 << SPI0_CON_SPOS_Pos),  /*!< SPI0 Pin Remap: Remap mode A */
  
	SPI_PinRemap_B       = (uint32_t)(0x02 << SPI1_TWI1_CON_SPOS_Pos),  /*!< SPI1_TWI1 Pin Remap: Remap mode B */
  SPI_PinRemap_C       = (uint32_t)(0x03 << SPI1_TWI1_CON_SPOS_Pos),  /*!< SPI1_TWI1 Pin Remap: Remap mode C */
} SPI_PinRemap_TypeDef;

#define IS_SPI_LIST_PINREMAP(REMAP) (((REMAP) == SPI_PinRemap_Default) ||  \
															      	((REMAP) == SPI_PinRemap_A)||  \
                                       ((REMAP) == SPI_PinRemap_B) ||  \
															      	((REMAP) == SPI_PinRemap_C) )

/**
 * @}
 */

/** @defgroup SPI_IT SPI Interrupt
 * @{
 */
typedef enum
{
  SPI_IT_INTEN = (uint32_t)SPI0_IDE_INTEN,	/*!< SPI Interrupt: SPI total interruption */
  SPI_IT_RXNE  = (uint32_t)SPI0_IDE_RXNEIE,	/*!< SPI Interrupt: SPI RX buffer not empty Interrupt */
  SPI_IT_TB    = (uint32_t)SPI0_IDE_TBIE,  		/*!< SPI Interrupt: SPI TX buffer is empty Interrupt */
  SPI_IT_RX    = (uint32_t)SPI0_IDE_RXIE,  		/*!< SPI Interrupt: Receiving FIFO overflow Interrupt */
  SPI_IT_RXH   = (uint32_t)SPI0_IDE_RXHIE,  	/*!< SPI Interrupt: Receive FIFO over half Interrupt */
  SPI_IT_TXH   = (uint32_t)SPI0_IDE_TXHIE,  	/*!< SPI Interrupt: Transmit FIFO under half Interrupt */
	SPI_IT_TBIE = (uint8_t)SPI1_IDE_TBIE,/*!< SPI Interrupt: Transmit TBIE under half Interrupt */
	
} SPI_IT_TypeDef;

#define IS_SPI_IT(IT) (((IT) == SPI_IT_INTEN) || \
                       ((IT) == SPI_IT_RXNE) || \
                       ((IT) == SPI_IT_TB) || \
                       ((IT) == SPI_IT_RX) || \
											 ((IT) == SPI_IT_RXH) || \
                       ((IT) == SPI_IT_TXH)|| \
                       ((IT) == SPI_IT_TBIE))
/**
 * @}
 */

/** @defgroup SPI_FLAG SPI Flag
 * @{
 */
typedef enum
{
  SPI_Flag_SPIF   = (uint32_t)SPI0_STS_SPIF, /*!< SPI Flag: SPI transmit and receive flag */
  SPI_Flag_RINEIF = (uint32_t)SPI0_STS_RXNEIF, /*!< SPI Flag: SPI RX buffer not empty flag */
  SPI_Flag_TXEIF  = (uint32_t)SPI0_STS_TXEIF, /*!< SPI Flag: TX buffer is empty flag */
  SPI_Flag_RXFIF  = (uint32_t)SPI0_STS_RXFIF, /*!< SPI Flag: Receiving FIFO overflow flag */
  SPI_Flag_RXHIF  = (uint32_t)SPI0_STS_RXHIF, /*!< SPI Flag: Receive FIFO over half flag */
  SPI_Flag_TXHIF  = (uint32_t)SPI0_STS_TXHIF, /*!< SPI Flag: Transmit FIFO under half flag */
  SPI_Flag_WCOL   = (uint32_t)SPI0_STS_WCOL, /*!< SPI Flag: Write conflict flag */
	SPI_FLAG_QTWIF = (uint8_t)SPI1_TWI1_STS_QTWIF, /*!< SPI1 Flag: Interrupt flag */
} SPI_FLAG_TypeDef;

#define IS_SPI_FLAG(FLAG) (((FLAG) == SPI_Flag_SPIF) || \
                           ((FLAG) == SPI_Flag_RINEIF) || \
                           ((FLAG) == SPI_Flag_TXEIF) || \
                           ((FLAG) == SPI_Flag_RXFIF) || \
                           ((FLAG) == SPI_Flag_RXHIF) || \
                           ((FLAG) == SPI_Flag_TXHIF) || \
                           ((FLAG) == SPI_Flag_WCOL) || \
                           ((FLAG) == SPI_FLAG_QTWIF))
/**
 * @}
 */

/** @defgroup SPI_DMAReq SPI DMA Request
 * @{
 */
typedef enum
{
  SPI_DMAReq_RX = (uint32_t)SPI0_IDE_RXDMAEN, /*!< SPI DMA Request: Receive */
  SPI_DMAReq_TX = (uint32_t)SPI0_IDE_TXDMAEN, /*!< SPI DMA Request: Transmit */
} SPI_DMAReq_TypeDef;

#define IS_SPI_DMAREQ(DMAREQ) (((DMAREQ) == SPI_DMAReq_RX) || \
                               ((DMAREQ) == SPI_DMAReq_TX))
/**
 * @}
 */

/**
 * @}
 */

/** @defgroup SPI_Constants SPI Constants
  * @{
  */

#define IS_SPI_ALL_PERIPH(PERIPH) (((PERIPH) == SPI0))

#endif
/**
 * @}
 */
/* End of constants -----------------------------------------------------*/

/** @defgroup SPI_Struct SPI Struct
 * @{
 */

/** @brief SPI Time base Configuration Structure definition
 * @{
 */
typedef struct
{
    uint16_t SPI_Mode; /*!< This member configures SPI mode.
                                              This parameter can be a value of @ref SPI_Mode_TypeDef */

    uint16_t SPI_DataSize; /*!< This member configures SPI data size.
                                              This parameter can be a value of @ref SPI_DataSize_TypeDef */


    uint16_t SPI_CPHA; /*!< This member configures SPI Clock Phase.
                                              This parameter can be a value of @ref SPI_CPHA_TypeDef */

    uint16_t SPI_CPOL; /*!< This member configures SPI Clock Polarity.
                                              This parameter can be a value of @ref SPI_CPOL_TypeDef */

    uint32_t SPI_FirstBit; /*!< This member configures SPI first transmitted bit.
                                              This parameter can be a value of @ref SPI_FirstBit_TypeDef */


    uint32_t SPI_Prescaler; /*!< This member configures SPI clock predivision.
                                              This parameter can be a value of @ref SPI_Prescaler_TypeDef */
} SPI_InitTypeDef;
/**
 * @}
 */

/**
 * @}
 */

/** @addtogroup SPI_Functions SPI Functions
 * @{
 */

/* SPI Base functions ********************************************************/
void SPI_DeInit ( SPI_TypeDef* SPIx );
void SPI_StructInit ( SPI_InitTypeDef* SPI_InitStruct );
void SPI_Init ( SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct );
void SPI_Cmd ( SPI_TypeDef* SPIx, FunctionalState NewState );
void SPI_SetMode ( SPI_TypeDef* SPIx, SPI_Mode_TypeDef SPI_Mode );
void SPI_DataSizeConfig ( SPI_TypeDef* SPIx, SPI_DataSize_TypeDef SPI_DataSize );

/* Data transfers functions ********************************************************/
void SPI_SendData ( SPI_TypeDef* SPIx, uint16_t Data );
uint16_t SPI_ReceiveData ( SPI_TypeDef* SPIx );
void SPI_SendDataFIFO ( SPI_TypeDef* SPIx, uint16_t* Data, uint16_t length );
void SPI_ReceiveDataFIFO ( SPI_TypeDef* SPIx, uint16_t* Data, uint16_t length );

/* Pin remap management functions  **********************************************/
void SPI_PinRemapConfig ( SPI_TypeDef* SPIx, SPI_PinRemap_TypeDef SPI_PinRemap );

/* Interrupts and flags management functions  **********************************************/
void SPI_ITConfig ( SPI_TypeDef* SPIx, uint16_t SPI_IT, FunctionalState NewState );
FlagStatus SPI_GetFlagStatus ( SPI_TypeDef* SPIx, SPI_FLAG_TypeDef SPI_FLAG );
void SPI_ClearFlag ( SPI_TypeDef* SPIx, uint32_t SPI_FLAG );
void SPI_DMACmd ( SPI_TypeDef* SPIx, uint16_t SPI_DMAReq, FunctionalState NewState );
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
