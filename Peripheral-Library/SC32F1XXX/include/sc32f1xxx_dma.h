/**
 ******************************************************************************
 * @file    sc32f1xxx_dma.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   Header file of DMA module.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __sc32f1xxx_DMA_H
#define __sc32f1xxx_DMA_H

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

/** @addtogroup DMA
 * @{
 */

/* Exported enumerations ------------------------------------------------------------*/
/** @defgroup DMA_Exported_Enumerations DMA Exported Enumerations
 * @{
 */

/** @brief DMA_Priority DMA Priority
 * @{
 */
typedef enum
{
    DMA_Priority_LOW				= ( ( uint32_t ) 0x00U << DMA_CFG_PL_Pos ),		/*!< Priority level: Low       */
    DMA_Priority_MEDIUM 		= ( ( uint32_t ) 0x01U << DMA_CFG_PL_Pos ),		/*!< Priority level: Medium    */
    DMA_Priority_HIGH				= ( ( uint32_t ) 0x02U << DMA_CFG_PL_Pos ),		/*!< Priority level: High      */
    DMA_Priority_VERY_HIGH	= ( ( uint32_t ) 0x03U << DMA_CFG_PL_Pos ),		/*!< Priority level: Very High */
} DMA_Priority_TypeDef;

#define IS_DMA_PROIORITY(PROIORITY) (((PROIORITY) == DMA_Priority_LOW) || \
                                    ((PROIORITY) == DMA_Priority_MEDIUM) || \
                                    ((PROIORITY) == DMA_Priority_HIGH) || \
                                    ((PROIORITY) == DMA_Priority_VERY_HIGH))
/**
 * @}
 */

/** @brief DMA_CircularMode DMA CircularMode
 * @{
 */
typedef enum
{
    DMA_CircularMode_Disable	  = ( ( uint32_t ) 0x00U << DMA_CFG_CIRC_Pos ), /*!< DMA Mode: Disable */
    DMA_CircularMode_Enable	= ( ( uint32_t ) 0x01U << DMA_CFG_CIRC_Pos ), /*!< DMA Mode: Enable */
} DMA_CircularMode_TypeDef;

#define IS_DMA_CIRCULARMODE(MODE) (((MODE) == DMA_CircularMode_Disable ) || \
                           ((MODE) == DMA_CircularMode_Enable))
/**
 * @}
 */

/** @brief DMA_DataSize DMA Data DataSize
 * @{
 */
typedef enum
{
    DMA_DataSize_Byte			= ( ( uint32_t ) 0x00U << DMA_CFG_TXWIDTH_Pos ),		 /*!< Peripheral data alignment: Byte     */
    DMA_DataSize_HakfWord	= ( ( uint32_t ) 0x01U << DMA_CFG_TXWIDTH_Pos ),		 /*!< Peripheral data alignment: HalfWord */
    DMA_DataSize_Word			= ( ( uint32_t ) 0x02U << DMA_CFG_TXWIDTH_Pos ),		 /*!< Peripheral data alignment: Word     */
} DMA_DataSize_TypeDef;

#define IS_DMA_DATASIZE(SIZE) (((SIZE) == DMA_DataSize_Byte) || \
                               ((SIZE) == DMA_DataSize_HakfWord) || \
                               ((SIZE) == DMA_DataSize_Word))
/**
 * @}
 */

/** @brief DMA_TargetMode DMA Target Address Change Mode
 * @{
 */
typedef enum
{
    DMA_TargetMode_FIXED		= ( ( uint32_t ) 0x00U << DMA_CFG_DAINC_Pos ), /*!< DMA Target Mode: Fixed address */
    DMA_TargetMode_INC			= ( ( uint32_t ) 0x01U << DMA_CFG_DAINC_Pos ), /*!< DMA Target Mode: Address increase */
    DMA_TargetMode_DEC			= ( ( uint32_t ) 0x02U << DMA_CFG_DAINC_Pos ), /*!< DMA Target Mode: Address decrease */
    DMA_TargetMode_INC_CIRC	= ( ( uint32_t ) 0x03U << DMA_CFG_DAINC_Pos ), /*!< DMA Target Mode: Address increase loop */
} DMA_TargetMode_TypeDef;

#define IS_DMA_TARGERT_MODE(MODE) (((MODE) == DMA_TargetMode_FIXED ) || \
                                  ((MODE) == DMA_TargetMode_INC) || \
                                  ((MODE) == DMA_TargetMode_DEC) || \
                                  ((MODE) == DMA_TargetMode_INC_CIRC))
/**
 * @}
 */

/** @brief DMA_SourceMode DMA Source
 * @{
 */
typedef enum
{
    DMA_SourceMode_FIXED		= ( ( uint32_t ) 0x00U << DMA_CFG_SAINC_Pos ),			/*!< DMA Source Mode: Fixed address */
    DMA_SourceMode_INC			= ( ( uint32_t ) 0x01U << DMA_CFG_SAINC_Pos ),			/*!< DMA Source Mode: Address increase */
    DMA_SourceMode_DEC			= ( ( uint32_t ) 0x02U << DMA_CFG_SAINC_Pos ),			/*!< DMA Source Mode: Address decrease */
    DMA_SourceMode_INC_CIRC = ( ( uint32_t ) 0x03U << DMA_CFG_SAINC_Pos ),			/*!< DMA Source Mode: Address increase loop */
} DMA_SourceMode_TypeDef;

#define IS_DMA_SOURCE_MODE(MODE) (((MODE) == DMA_SourceMode_FIXED ) || \
                                  ((MODE) == DMA_SourceMode_INC) || \
                                  ((MODE) == DMA_SourceMode_DEC) || \
                                  ((MODE) == DMA_SourceMode_INC_CIRC))
/**
 * @}
 */

/** @brief DMA_Burst  DMA Brust
 * @{
 */
typedef enum
{
    DMA_Burst_Disable	= ( ( uint16_t ) 0x00000000 ), /*!< Brust Mode Disable */
    DMA_Burst_1B		= ( ( ( uint16_t ) 0x07U << DMA_CFG_BURSIZE_Pos ) | DMA_CFG_TPTYPE ), /*!< Burst Mode: rease 1 */
    DMA_Burst_2B		= ( ( ( uint16_t ) 0x06U << DMA_CFG_BURSIZE_Pos ) | DMA_CFG_TPTYPE ), /*!< Burst Mode: rease 2 */
    DMA_Burst_4B		= ( ( ( uint16_t ) 0x05U << DMA_CFG_BURSIZE_Pos ) | DMA_CFG_TPTYPE ), /*!< Burst Mode: rease 4 */
    DMA_Burst_8B		= ( ( ( uint16_t ) 0x04U << DMA_CFG_BURSIZE_Pos ) | DMA_CFG_TPTYPE ), /*!< Burst Mode: rease 8 */
    DMA_Burst_16B		= ( ( ( uint16_t ) 0x03U << DMA_CFG_BURSIZE_Pos ) | DMA_CFG_TPTYPE ), /*!< Burst Mode: rease 16 */
    DMA_Burst_32B		= ( ( ( uint16_t ) 0x02U << DMA_CFG_BURSIZE_Pos ) | DMA_CFG_TPTYPE ), /*!< Burst Mode: rease 32 */
    DMA_Burst_64B		= ( ( ( uint16_t ) 0x01U << DMA_CFG_BURSIZE_Pos ) | DMA_CFG_TPTYPE ), /*!< Burst Mode: rease 64 */
    DMA_Burst_128B	= ( ( ( uint16_t ) 0x00U << DMA_CFG_BURSIZE_Pos ) | DMA_CFG_TPTYPE ), /*!< Burst Mode: rease 128 */
} DMA_Burst_TypeDef;

#define IS_DMA_BURST(BURST) (((BURST) == DMA_Burst_Disable) || \
                             ((BURST) == DMA_Burst_1B)    || \
                             ((BURST) == DMA_Burst_2B)    || \
                             ((BURST) == DMA_Burst_4B)    || \
                             ((BURST) == DMA_Burst_8B)    || \
                             ((BURST) == DMA_Burst_16B)   || \
                             ((BURST) == DMA_Burst_32B)   || \
                             ((BURST) == DMA_Burst_64B)   || \
                             ((BURST) == DMA_Burst_128B))
/**
 * @}
 */

/** @brief DMA_Request  DMA Request Source
 * @{
 */
typedef enum
{
    DMA_Request_Null			= ( ( uint32_t ) 0x0000U << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: Null    */
    DMA_Request_UART0_TX	= ( ( uint32_t ) 0x0002U << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: UART0 TX    */
    DMA_Request_UART0_RX	= ( ( uint32_t ) 0x0003U << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: UART0 RX    */
    DMA_Request_UART1_TX	= ( ( uint32_t ) 0x0004U << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: UART1 TX    */
    DMA_Request_UART1_RX	= ( ( uint32_t ) 0x0005U << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: UART1 RX    */
    DMA_Request_SPI0_TX		= ( ( uint32_t ) 0x000CU << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: SPI0 TX    */
    DMA_Request_SPI0_RX		= ( ( uint32_t ) 0x000DU << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: SPI0 RX    */
    DMA_Request_SPI1_TX		= ( ( uint32_t ) 0x000EU << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: SPI1 TX    */
    DMA_Request_SPI1_RX		= ( ( uint32_t ) 0x000FU << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: SPI1 RX    */
    DMA_Request_TWI0_TX		= ( ( uint32_t ) 0x0014U << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: TWI0 TX    */
    DMA_Request_TWI0_RX		= ( ( uint32_t ) 0x0015U << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: TWI0 RX    */
    DMA_Request_TIM1_TI		= ( ( uint32_t ) 0x0021U << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: TIM1 TI    */
    DMA_Request_TIM1_CAPF	= ( ( uint32_t ) 0x0022U << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: TIM1 Falling edge capture */
    DMA_Request_TIM1_CAPR	= ( ( uint32_t ) 0x0023U << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: TIM1 Rising edge capture  */
    DMA_Request_TIM2_TI		= ( ( uint32_t ) 0x0024U << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: TIM2 TI    */
    DMA_Request_TIM2_CAPF	= ( ( uint32_t ) 0x0025U << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: TIM2 Falling edge capture */
    DMA_Request_TIM2_CAPR	= ( ( uint32_t ) 0x0026U << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: TIM2 Rising edge capture  */
    DMA_Request_TIM6_TI		= ( ( uint32_t ) 0x0030U << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: TIM6 TI    */
    DMA_Request_TIM6_CAPF	= ( ( uint32_t ) 0x0022U << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: TIM6 Falling edge capture */
    DMA_Request_TIM6_CAPR	= ( ( uint32_t ) 0x0023U << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: TIM6 Rising edge capture  */
    DMA_Request_ADC				= ( ( uint32_t ) 0x003BU << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: ADC    */
#if defined(SC32f10xx) || defined(SC32f11xx) || defined(SC32f15xx)
    DMA_Request_DMA0			= ( ( uint32_t ) 0x003CU << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: DMA0    */
    DMA_Request_DMA1			= ( ( uint32_t ) 0x003DU << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: DMA1    */
    DMA_Request_DMA2			= ( ( uint32_t ) 0x003EU << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: DMA2    */
    DMA_Request_DMA3			= ( ( uint32_t ) 0x003FU << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: DMA3    */
#elif defined(SC32f12xx)
    DMA_Request_DMA0			= ( ( uint32_t ) 0x003EU << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: DMA0    */
    DMA_Request_DMA1			= ( ( uint32_t ) 0x003FU << DMA_CFG_REQSRC_Pos ),			/*!< DMA Requtest: DMA1    */
#endif
} DMA_Request_TypeDef;



/**
 * @}
 */

/** @brief DMA_State DMA State
 * @{
 */
typedef enum
{
    DMA_State_IDLE				= ( ( uint32_t ) 0x00U << DMA_STS_STATUS_Pos ),			 /*!< DMA idle state */
    DMA_State_SOURCE			= ( ( uint32_t ) 0x01U << DMA_STS_STATUS_Pos ),			 /*!< DMA write source address */
    DMA_State_BUSY				= ( ( uint32_t ) 0x02U << DMA_STS_STATUS_Pos ),			 /*!< DMA reads the source address data and writes to the destination address */
    DMA_State_DESTINATION	= ( ( uint32_t ) 0x03U << DMA_STS_STATUS_Pos ),			 /*!< DMA write destination address */
    DMA_State_HANG				= ( ( uint32_t ) 0x04U << DMA_STS_STATUS_Pos ),			 /*!< DMA Hang state */
    DMA_State_PAUSE				= ( ( uint32_t ) 0x05U << DMA_STS_STATUS_Pos ),			 /*!< DMA Pause state */
    DMA_State_BURST				= ( ( uint32_t ) 0x06U << DMA_STS_STATUS_Pos ),			 /*!< DMA Burst transmission */
    DMA_State_STOP				= ( ( uint32_t ) 0x07U << DMA_STS_STATUS_Pos ),			 /*!< DMA Stop state */
} DMA_State_TypeDef;

#define IS_DMA_SASTE(SASTE) (((SASTE) == DMA_State_IDLE) || \
                            ((SASTE) == DMA_State_SOURCE) || \
                            ((SASTE) == DMA_State_BUSY) || \
                            ((SASTE) == DMA_State_DESTINATION) || \
                            ((SASTE) == DMA_State_HANG) || \
                            ((SASTE) == DMA_State_PAUSE) || \
                            ((SASTE) == DMA_State_BURST)) || \
                            ((SASTE) == DMA_State_STOP))
/**
 * @}
 */


/** @brief DMA_IT DMA Interrupt
 * @{
 */
typedef enum
{
    DMA_IT_INTEN = ( ( uint32_t ) DMA_CFG_INTEN ),			/*!< DMA IT: INTEN    */
    DMA_IT_TCIE	 = ( ( uint32_t ) DMA_CFG_TCIE ),			/*!< DMA IT: TCIE    */
    DMA_IT_HTIE	 = ( ( uint32_t ) DMA_CFG_HTIE ),			/*!< DMA IT: HTIE    */
    DMA_IT_TEIE	 = ( ( uint32_t ) DMA_CFG_TEIE ),			/*!< DMA IT: TEIE    */
} DMA_IT_TypeDef;

#define IS_DMA_IT(IT) ((((IT) & (uint8_t)0xF0) == 0x00) && ((IT) != (uint8_t)0x00))
/**
 * @}
 */

/** @brief DMA_Flag  DMA Flag
 * @{
 */
typedef enum
{
    DMA_FLAG_GIF	= ( ( uint8_t ) DMA_STS_GIF ),			/*!< DMA FLAG: Global interrupt flag */
    DMA_FLAG_TCIF	= ( ( uint8_t ) DMA_STS_TCIF ),		/*!< DMA FLAG: Transmission completion interrupt flag bit */
    DMA_FLAG_HTIF	= ( ( uint8_t ) DMA_STS_HTIF ),		/*!< DMA FLAG: Transmit half interrupt flag */
    DMA_FLAG_TEIF	= ( ( uint8_t ) DMA_STS_TEIF ),		/*!< DMA FLAG: Transmission error interrupt flag   */
} DMA_Flag_TypeDef;

#define IS_DMA_FLAG(FLAG) ((((FLAG) & (uint8_t)0xF0) == 0x00) && ((FLAG) != (uint8_t)0x00))

#define IS_GET_DMA_FLAG(FLAG) (((FLAG) == DMA_FLAG_GIF) ||  \
                               ((FLAG) == DMA_FLAG_TCIF) || \
															 ((FLAG) == DMA_FLAG_HTIF) || \
                               ((FLAG) == DMA_FLAG_TEIF))
/**
 * @}
 */

/** @brief DMA_DMAReq DMA DMAReq
 * @{
 */
typedef enum
{
    DMA_DMAReq_CHRQ = ( uint32_t ) DMA_CFG_CHRQ, /*!< TIM DMA: TIM overflow */
} DMA_DMAReq_TypeDef;

#define IS_DMA_DMAREQ(REQ) ((REQ) == DMA_DMAReq_CHRQ)
/**
 * @}
 */


/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @defgroup DMA_InitTypeDef TIM Exported Struct
 * @{
 */
/** @brief DMA_InitTypeDef
 * @{
 */
typedef struct
{
    uint16_t DMA_Priority; /*!<  Specifies the software priority for the DMAy Streamx.
																	This parameter can be a value of @ref DMA_Priority_level */

    uint16_t DMA_CircularMode; /*!< Specifies the DMA mode.
																	This parameter can be a value of @ref DMA_CircularMode_TypeDef */


    uint16_t DMA_DataSize; /*!< Specifies the DMA data width.
																		This parameter can be a value of @ref DMA_DataSize_TypeDef */

    uint16_t DMA_TargetMode; /*!< Specifies the DMA target address change mode.
																	This parameter can be a value of @ref DMA_TargetMode_TypeDef */

    uint16_t DMA_SourceMode; /*!< Specifies the DMA source address change mode.
																	This parameter can be a value of @ref DMA_Burst_TypeDef */


    uint16_t DMA_Burst; /*!< Specifies the counter dierction.
														This parameter can be a value of @ref DMA_Burst_TypeDef */


    uint32_t DMA_BufferSize;   /*!< Specifies the buffer size, in data unit, of the specified Stream.*/


    uint32_t DMA_Request;/*!< DMA request source.
																	This parameter can be a value of @ref DMA_Request_TypeDef */

    uint32_t DMA_SrcAddress; /*!< The source memory Buffer address. */

    uint32_t DMA_DstAddress; /*!< The destination memory Buffer address. */

} DMA_InitTypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of struct -----------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
#if defined(SC32f10xx) || defined(SC32f11xx) || defined(SC32f15xx)
#define IS_DMA_ALL_PERIPH(PERIPH) (((PERIPH) == DMA0) || \
																	 ((PERIPH) == DMA1) || \
																	 ((PERIPH) == DMA2) || \
																	 ((PERIPH) == DMA3))
#elif defined(SC32f12xx)
#define IS_DMA_ALL_PERIPH(PERIPH) (((PERIPH) == DMA0) || \
																	 ((PERIPH) == DMA1))
#endif
/**
 * @}
 */
/* End of macros -----------------------------------------------------*/

/** @addtogroup DMA_Functions DMA Functions
 * @{
 */
/* Initialization and de-initialization functions *****************/
void DMA_DeInit ( DMA_TypeDef* DMAx );
void DMA_Init ( DMA_TypeDef* DMAx, DMA_InitTypeDef* DMA_InitStruct );
void DMA_StructInit ( DMA_InitTypeDef* DMA_InitStruct );
void DMA_Cmd ( DMA_TypeDef* DMAx, FunctionalState NewState );
void DMA_PauseCmd ( DMA_TypeDef* DMAx, FunctionalState NewState );
void DMA_CHRQCmd ( DMA_TypeDef* DMAx, FunctionalState NewState );
void DMA_ChannelReset ( DMA_TypeDef* DMAx );
/* Initialization and de-initialization functions *****************/
void DMA_SetSrcAddress ( DMA_TypeDef* DMAx, uint32_t SrcAddress );
void DMA_SetDstAddress ( DMA_TypeDef* DMAx, uint32_t DstAddress );
void DMA_SetCurrDataCounter ( DMA_TypeDef* DMAx, uint32_t Counter );
uint32_t DMA_GetCurrDataCounter ( DMA_TypeDef* DMAx );
void DMA_SoftwareTrigger ( DMA_TypeDef* DMAx );

/* Interrupts, DMA and flags management functions ***********************/
DMA_State_TypeDef DMA_GetStatus ( DMA_TypeDef* DMAx );
void DMA_ITConfig ( DMA_TypeDef* DMAx, uint32_t DMA_IT, FunctionalState NewState );
FlagStatus DMA_GetFlagStatus ( DMA_TypeDef* DMAx, DMA_Flag_TypeDef DMA_FLAG );
void DMA_ClearFlag ( DMA_TypeDef* DMAx, uint32_t DMA_FLAG );
void DMA_DMACmd ( DMA_TypeDef* DMAx, uint32_t DMA_DMARequest, FunctionalState NewState );

/**
 * @}
 */
/* End of functions --------------------------------------------------------*/

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
