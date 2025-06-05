/**
 ******************************************************************************
 * @file    sc32f1xxx_can.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   Header file of CAN module.
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
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __sc32f1xxx_can_H
#define __sc32f1xxx_can_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "sc32f1xxx.h"
#include "sc32.h"
#include "sc32f1xxx_rcc.h"
/** @defgroup CAN_Enumerations CAN Enumerations
 * @{
 */

/** @brief CAN IDE schema enumeration
  * @{
  */

#define CAN_BaudRate_800k 800000
#define CAN_BaudRate_500k 500000
#define CAN_Sampling_pos_75 0.75
#define CAN_Sampling_pos_80 0.8
#define CAN_Sampling_pos_875 0.875
typedef enum
{
	CAN_Standard_format = (uint8_t)(0x00<<CAN_TX_CTRL_IDE_Pos),/*!<Packets are sent in standard mode*/
	CAN_Extended_format = (uint8_t)(0x01<<CAN_TX_CTRL_IDE_Pos),/*!<Packets are in extended mode*/
} CAN_IDEMODE_Typedef;

#define IS_CAN_IDEMODE(IDEMODE) (((IDEMODE) == CAN_Standard_format) || \
                               ((IDEMODE) == CAN_Extended_format)   )
/** @brief CAN RTR mode enumeration
  * @{
  */

typedef enum
{
	CAN_Data_frame =   (uint8_t)(0x0L << CAN_TX_CTRL_RTR_Pos),	/*!<The message uses a data frame*/
	CAN_Remote_frame = (uint8_t)(0x1L << CAN_TX_CTRL_RTR_Pos),/*!<The packet uses a remote frame*/
}CAN_RTRMODE_Typedef;	
#define IS_CAN_RTRMODE(RTRMODE) (((RTRMODE) == CAN_Data_frame ) || \
                               ((RTRMODE) == CAN_Remote_frame))
/** @brief CAN send frame mode
  * @{
  */
typedef enum
{
	
	CAN_Standard_frame = (uint8_t)(0x00 <<CAN_TX_CTRL_FDF_Pos ),/*!<The packet uses 2.0 frames*/
	CAN_FD_frame = (uint8_t)(0x01<<CAN_TX_CTRL_FDF_Pos),/*!<The message uses an FD frame*/

}CAN_FDFMODE_Typedef;
#define IS_CAN_FDFMODE(FDFMODE) (((FDFMODE) == CAN_Standard_frame  ) || \
                               ((FDFMODE) ==CAN_FD_frame))
/** @brief  CAN BRSMODE
  * @{
  */
typedef enum
{
	CAN_Disable_BRS = (uint8_t)(0x00 <<CAN_TX_CTRL_BRS_Pos),/*!<Packet bit rate switching is disabled. Procedure*/
	CAN_Enable_BRS = (uint8_t)(0x01 <<CAN_TX_CTRL_BRS_Pos),/*!<The packet allows switching of the bit rate*/
	
}CAN_BRSMODE_Typedef;
#define IS_CAN_BRSMODE(BRSMODE) (((BRSMODE) == CAN_Disable_BRS) || \
                               ((BRSMODE)== CAN_Enable_BRS))
/** @brief  PTB automatic retransmission mode selected
  * @{
  */
typedef enum
{
	
	CAN_TPSS_Enable = (uint32_t)(0x00 <<CAN_CFG_STAT_TPSS_Pos),/*!<Enable automatic PTB retransmission*/
	CAN_TPSS_Disable = (uint32_t)(0x01 <<CAN_CFG_STAT_TPSS_Pos),/*!<Disable automatic PTB retransmission*/
}CAN_PTB_AutoRetrans_TypeDef;
#define IS_CAN_PTB_AutoRetrans(PTB_AutoRetrans) (((PTB_AutoRetrans) == CAN_TPSS_Enable) || \
                                             ((PTB_AutoRetrans)==CAN_TPSS_Disable))
/** @brief  STB automatic retransmission mode selection
  * @{
  */
typedef enum
{
	
	CAN_TSSS_Enable = (uint32_t)(0x00 << CAN_CFG_STAT_TSSS_Pos),/*!<Enable automatic STB retransmission*/	
	CAN_TSSS_Disable = (uint32_t)(0x01 << CAN_CFG_STAT_TSSS_Pos),/*!<Disable STB automatic retransmission*/
}CAN_STB_AutoRetrans_TypeDef;
#define IS_CAN_STB_AutoRetrans(STB_AutoRetrans) (((STB_AutoRetrans) == CAN_TSSS_Enable) || \
                                             ((STB_AutoRetrans)== CAN_TSSS_Disable))
/** @brief  CAN send buffer selection
  * @{
  */
typedef enum
{
	CAN_TBUFTx_PTB = (uint32_t)(0x00 << CAN_CFG_STAT_TBSEL_Pos),	/*!<Send buffer Select PTB*/
	CAN_TBUFTx_STB = (uint32_t)(0x01 << CAN_CFG_STAT_TBSEL_Pos),/*!<Send buffer select STB*/
}CANTBUF_TypeDef;
#define IS_CANTBUF(CANTBUF) (((CANTBUF) == CAN_TBUFTx_PTB) || \
                             ((CANTBUF)== CAN_TBUFTx_STB))
/** @brief  CAN TX Enable select
  * @{
  */
typedef enum
{
	
	CAN_TxDisable =(uint16_t)(0x00 << CAN_IDE_TXEN_Pos),/*!<The CAN sending function is disabled*/
	CAN_TxEnable =(uint16_t)(0x01 << CAN_IDE_TXEN_Pos),/*!<The CAN sending function was enabled*/
}CANTXEN_TypeDef;
#define IS_CANTXEN(CANTXEN) (((CANTXEN) == CAN_TxDisable) || \
                              ((CANTXEN)== CAN_TxEnable))
/** @brief  CAN RX Enable select
  * @{
  */
typedef enum
{	
	CAN_RxDisable = (uint16_t)(0x00 << CAN_IDE_RXEN_Pos),/*!<The CAN receiving function is disabled*/
	CAN_RxEnable =  (uint16_t)(0x01 << CAN_IDE_RXEN_Pos),	/*!<The CAN receiving function was enabled*/
}CANRXEN_TypeDef;
#define IS_CANRXEN(CANRXEN) (((CANRXEN) == CAN_RxDisable) || \
                              ((CANRXEN)== CAN_RxEnable))
/** @brief CAN receive overflow Discard old and new packets Select
  * @{
  */
typedef enum
{
	CAN_ROM_Old = (uint32_t)(0x00 << CAN_CFG_STAT_ROM_Pos),/*!<The oldest packet was discarded. Procedure*/
	CAN_ROM_New = (uint32_t)(0x01 << CAN_CFG_STAT_ROM_Pos),/*!<Discard the latest packet*/
}CANROM_TypeDef;
#define IS_CANROM(CANROM) (((CANROM) == CAN_ROM_Old) || \
                           ((CANROM)== CAN_ROM_New))
/** @brief CAN filter enumeration
  * @{
  */
typedef enum
{
	CAN_Fliter0 = 0x00,/*!<Select Fliter0*/
	CAN_Fliter1 = 0x01,/*!<Select Fliter1*/
	CAN_Fliter2 = 0x02,/*!<Select Fliter2*/
	CAN_Fliter3 = 0x03,/*!<Select Fliter3*/
	CAN_Fliter4 = 0x04,/*!<Select Fliter4*/
	CAN_Fliter5 = 0x05,/*!<Select Fliter5*/
	CAN_Fliter6 = 0x06,/*!<Select Fliter6*/
	CAN_Fliter7 = 0x07,/*!<Select Fliter7*/
}FliterNumber;
#define IS_FliterNumber(FliterNumber) (((FliterNumber) == CAN_Fliter0) || \
                                       ((FliterNumber)== CAN_Fliter1)  || \
                                       ((FliterNumber)== CAN_Fliter2)  || \
                                       ((FliterNumber)== CAN_Fliter3)  || \
                                       ((FliterNumber)== CAN_Fliter4)  || \
                                       ((FliterNumber)== CAN_Fliter5)  || \
                                       ((FliterNumber)== CAN_Fliter6)  || \
                                       ((FliterNumber)== CAN_Fliter7))
/** @brief The CAN filter selects standard frames from extended frames
  * @{
  */                                   
typedef enum
{
	CAN_Fliter_Standard = (uint8_t)(0x00<<CAN_ACFCTRL_ACFADR_Pos),/*!<Only standard frames pass through the filter*/	
	CAN_Fliter_Extension = (uint8_t)(0x01<<CAN_ACFCTRL_ACFADR_Pos),/*!<Let only the extension frames pass through the filter*/
	CAN_Fliter_Default = (uint8_t)(0x02<<CAN_ACFCTRL_ACFADR_Pos),/*No limit*/
}FliterFrame_TypeDef;
#define IS_FliterFrame(FliterFrame) (((FliterFrame) == CAN_Fliter_Standard) || \
                                       ((FliterFrame)== CAN_Fliter_Extension)|| \
                                        ((FliterFrame)== CAN_Fliter_Default) )
/** @brief CAN disables the mask switch
  * @{
  */
typedef enum
{
	
	CAN_INToff =  (uint8_t)(0x00<<CAN_IDE_INTEN_Pos),/*!<Interrupt mask*/
	CAN_INTon = (uint8_t)(0x01<<CAN_IDE_INTEN_Pos),	/*!<Interrupt on*/
}CANInt_TypeDef;
#define IS_CANInt(CANInt) (((CANInt) == CAN_INToff) || \
                           ((CANInt)== CAN_INTon) )
/** @brief CAN send packet mode Select
  * @{
  */
typedef enum
{
	
	CAN_TxFIFO = (uint8_t)(0x00<<CAN_CFG_STAT_TSMODE_Pos),/*!<FIFO mode*/
	CAN_IDPriority = (uint8_t)(0x01<<CAN_CFG_STAT_TSMODE_Pos),/*!<ID priority mode*/
}CANTSMODE_TypeDef;
#define IS_CANTSMODE(CANTSMODE) (((CANTSMODE) == CAN_TxFIFO) || \
                                ((CANTSMODE)== CAN_IDPriority) )
/** @brief CAN disables the mask switch
  * @{
  */

/*CAN中断枚举*/
typedef enum
{
	CAN_INTEN = (uint8_t)(0x01<<CAN_IDE_INTEN_Pos), /*!<The  interrupt function was enabled*/
	CAN_RIEEN = (uint16_t)(0x01<<CAN_RTIE_RIE_Pos), /*!<The receiving interrupt function was enabled*/
	CAN_ROIEEN = (uint16_t)(0x01<<CAN_RTIE_ROIE_Pos) , /*!<Overflow interrupt was enabled. Procedure*/
	CAN_RFIEEN = (uint16_t)(0x01<<CAN_RTIE_RFIE_Pos), /*!<RB full interrupt was enabled. Procedure*/
	CAN_RAFIEEN = (uint16_t)(0x01<<CAN_RTIE_RAFIE_Pos ), /*!<RB slots Threshold warning Indicates the interrupt function*/
	CAN_TPIEEN =(uint16_t)(0x01<<CAN_RTIE_TPIE_Pos ) , /*!<The interruption of PTB transmission completion was enabled*/
	CAN_TSIEEN = (uint16_t)(0x01<<CAN_RTIE_TSIE_Pos ), /*!<The STB transmission completion interrupt was enabled*/
	CAN_EIEEN = (uint16_t)(0x01<<CAN_RTIE_EIE_Pos ), /*!<The error interrupt function was enabled*/
	CAN_ALIEEN = (uint16_t)(0x01<<CAN_RTIE_ALIE_Pos ), /*!<The arbitration loss interruption function was enabled*/
	CAN_BEIEEN = (uint32_t)(0x01<<CAN_RTIE_BEIE_Pos ) , /*!<Bus error interrupt enabled*/
	CAN_EPIEEN = (uint32_t)(0x01<<CAN_RTIE_EPIE_Pos), /*!<Error passive interrupt enable bit*/
}CAN_INT_TypeDef;
#define IS_CAN_INT(CAN_INT) (((CAN_INT) == CAN_RIEEN)  ||\
                             ((CAN_INT)== CAN_ROIEEN)  ||\
                             ((CAN_INT)== CAN_RFIEEN)  ||\
                             ((CAN_INT)== CAN_RAFIEEN) ||\
													   ((CAN_INT)== CAN_TPIEEN)  ||\
														 ((CAN_INT)== CAN_TSIEEN)  ||\
														 ((CAN_INT)== CAN_EIEEN)   ||\
														 ((CAN_INT)== CAN_ALIEEN)  ||\
													   ((CAN_INT)== CAN_BEIEEN)  ||\
														 ((CAN_INT)== CAN_EPIEEN) )
/** @brief CAN disables the mask switch
  * @{
  */

/*CAN中断枚举*/
typedef enum
{ 
	CAN_FlAG_RIF = (uint32_t)(0x01<<CAN_RTIE_RIF_Pos),  /*!<Select the RIF FLAG*/
	CAN_FlAG_TSFF = (uint16_t)(0x01<<CAN_RTIE_TSFF_Pos), /*!<Select the TSFF FLAG*/
	CAN_FlAG_AIF = (uint16_t)(0x01<<CAN_RTIE_AIF_Pos), /*!<Select the AIF FLAG*/
	CAN_FlAG_EIF = (uint16_t)(0x01<<CAN_RTIE_EIF_Pos) ,	/*!<Select the EIF FLAG*/
	CAN_FlAG_TSIF = (uint16_t)(0x01<<CAN_RTIE_TSIF_Pos),/*!<Select the TSIF FLAG*/
	CAN_FlAG_TPIF = (uint16_t)(0x01<<CAN_RTIE_TPIF_Pos ),/*!<Select the TPIF FLAG*/
	CAN_FlAG_RAFIF =(uint16_t)(0x01<<CAN_RTIE_RAFIF_Pos ) ,/*!<Select the RAFIF FLAG*/
	CAN_FlAG_RFIF = (uint16_t)(0x01<<CAN_RTIE_RFIF_Pos ),/*!<Select the RFIF FLAG*/
	CAN_FlAG_ROIF = (uint16_t)(0x01<<CAN_RTIE_ROIF_Pos ),/*!<Select the ROIF FLAG*/
	CAN_FlAG_ALIF = (uint16_t)(0x01<<CAN_RTIE_ALIF_Pos ),/*!<Select the ALIF FLAG*/
	CAN_FlAG_BEIF = (uint32_t)(0x01<<CAN_RTIE_BEIF_Pos ) ,/*!<Select the BEIF FLAG*/
	CAN_FlAG_EPIF = (uint32_t)(0x01<<CAN_RTIE_EPIF_Pos),/*!<Select the EPIF FLAG*/
}CAN_FLAG_TypeDef;
#define IS_CAN_FLAG(CAN_FLAG) (((CAN_FLAG) == CAN_FlAG_RIF)  ||\
                              ((CAN_FLAG)== CAN_FlAG_TSFF)  ||\
                              ((CAN_FLAG)== CAN_FlAG_AIF)  ||\
                              ((CAN_FLAG)== CAN_FlAG_EIF) ||\
													    ((CAN_FLAG)== CAN_FlAG_TSIF)  ||\
														  ((CAN_FLAG)== CAN_FlAG_TPIF)  ||\
														  ((CAN_FLAG)== CAN_FlAG_RAFIF)   ||\
														  ((CAN_FLAG)== CAN_FlAG_RFIF)  ||\
													    ((CAN_FLAG)== CAN_FlAG_ROIF)  ||\
														  ((CAN_FLAG)== CAN_FlAG_ALIF)  ||\
                              ((CAN_FLAG)== CAN_FlAG_BEIF)   ||\
                              ((CAN_FLAG)== CAN_FlAG_EPIF)     )
/** @brief CAN Timestamp Enable Select
  * @{
  */
typedef enum
{
	
	CAN_TimeStampDisable = (uint8_t)(0x00<<CAN_ACFCTRL_TIMEEN_Pos),/*!<The timestamp is disabled*/
  CAN_TimeStampEnable = (uint8_t)(0x01<<CAN_ACFCTRL_TIMEEN_Pos),/*!<The timestamp was enabled*/
}CANTimeStamp_TypeDef;
#define IS_CANTimeStamp(CANTimeStamp) (((CANTimeStamp) == CAN_TimeStampDisable) || \
                                ((CANTimeStamp)== CAN_TimeStampEnable) )
/** @brief CAN Indicates whether to enable timestamp counting
  * @{
  */ 
typedef enum
{

	CAN_TimeStampCntDisable = (uint16_t)(0x00<<CAN_IDE_TIMEN_Pos),	/*!<Disable the timestamp counting function*/
  CAN_TimeStampCntEnable = (uint16_t)(0x00<<CAN_IDE_TIMEN_Pos),/*!<Enable the timestamp counting function*/
}CANTimeStampCnt_TypeDef;
#define IS_CANTimeStampCnt(CANTimeStampCnt) (((CANTimeStampCnt) == CAN_TimeStampCntDisable) || \
                                ((CANTimeStampCnt)== CAN_TimeStampCntEnable) )
/** @brief CAN timestamp location selection
  * @{
  */
typedef enum
{
	
	CAN_TimeStampPosition_SOF = (uint16_t)(0x00<<CAN_ACFCTRL_TIMEPOS_Pos),/*!<Select the frame start as the timestamp location*/
  CAN_TimeStampPosition_EOF = (uint16_t)(0x01<<CAN_ACFCTRL_TIMEPOS_Pos),	/*!<Select the end of frame as the timestamp location*/
}CANTimeStampPosition_TypeDef;
#define IS_CANTimeStampPosition(CANTimeStampPosition) (((CANTimeStampPosition) == CAN_TimeStampPosition_SOF) || \
                                                       ((CANTimeStampPosition)== CAN_TimeStampPosition_EOF) )

/** @brief CAN DATA Length
  * @{
  */
 typedef enum 
	{
    CAN_DLC_0 = 0x00,/*!<Select CAN DATA Length 0*/
    CAN_DLC_1 = 0x01,/*!<Select CAN DATA Length 1*/
    CAN_DLC_2 = 0x02,/*!<Select CAN DATA Length 2*/  
    CAN_DLC_3 = 0x03,/*!<Select CAN DATA Length 3*/
    CAN_DLC_4 = 0x04,/*!<Select CAN DATA Length 4*/
    CAN_DLC_5 = 0x05,/*!<Select CAN DATA Length 5*/
    CAN_DLC_6 = 0x06,/*!<Select CAN DATA Length 6*/
    CAN_DLC_7 = 0x07,/*!<Select CAN DATA Length 7*/
    CAN_DLC_8 = 0x08,/*!<Select CAN DATA Length 8*/
    CAN_DLC_12 = 0x09,/*!<Select CAN DATA Length 12*/
    CAN_DLC_16 = 0x0A,/*!<Select CAN DATA Length 16*/
    CAN_DLC_20 = 0x0B,/*!<Select CAN DATA Length 20*/
    CAN_DLC_24 = 0x0C,/*!<Select CAN DATA Length 24*/
    CAN_DLC_32 = 0x0D,/*!<Select CAN DATA Length 32*/
    CAN_DLC_48 = 0x0E,/*!<Select CAN DATA Length 4*/
    CAN_DLC_64 = 0x0F,/*!<Select CAN DATA Length 64*/
} CAN_DLC;
/** @brief CAN Select the sending mode
  * @{
  */
typedef enum
{
	CAN_TransMod_TPE =(uint16_t) (0x01<<CAN_CFG_STAT_TPE_Pos),	/*!<PTB Send a single message*/	
	CAN_TransMod_TSONE =(uint16_t)(0x01<<CAN_CFG_STAT_TSONE_Pos),/*!<STB single send*/
  CAN_TransMod_TSALL = (uint16_t)(0x01<<CAN_CFG_STAT_TSALL_Pos),	/*!<All STBS are sent*/
}CAN_TransMod_TypeDef;
#define IS_CAN_TransMod(CAN_TransMod) (((CAN_TransMod) ==CAN_TransMod_TPE) || \
                                     ((CAN_TransMod) ==CAN_TransMod_TSONE) || \
                                     ((CAN_TransMod)== CAN_TransMod_TSALL) )
/** @brief CAN ISO mode selection
  * @{
  */
typedef enum
{
	
	CAN_BOSCH = (uint32_t)(0x00<<CAN_CFG_STAT_FD_ISO_Pos),/*!<Non-iso mode*/
	

	CAN_ISO = (uint32_t)(0x01<<CAN_CFG_STAT_FD_ISO_Pos),	/*!<ISO mode*/
}CANFD_ISO_MODE_TypeDef;
#define IS_CANFD_ISO_MODE(ISO_MODE) (((ISO_MODE) == CAN_BOSCH) || \
                           ((ISO_MODE)== CAN_ISO) )
/** @brief CAN BaudRate
  * @{
  */
typedef enum
{
	 CAN_Baudrate_125kHz = 125000,/*!<Select the baud rate of 125khz*/
   CAN_Baudrate_250kHz = 250000,/*!<Select the baud rate of 250khz*/
	 CAN_Baudrate_500kHz = 500000,/*!<Select the baud rate of 500khz*/
	 CAN_Baudrate_800kHz = 800000,/*!<Select the baud rate of 800khz*/
	 CAN_Baudrate_1000kHz = 1000000,/*!<Select the baud rate of 1000khz*/
}CAN_BaudRate;


/** @brief CAN mode selection
  * @{
  */
typedef enum
{
	CAN_Normal =0,/*!<Working mode:Normal*/
	CAN_Listenonly,/*!<Working mode:Listenonly*/
	CAN_StandBy,/*!<Working mode:StandBy*/
	CAN_LoopBack,/*!<Working mode:LoopBack*/
	CAN_LoopBackIn,/*!<Working mode:LoopBackIn*/
	CAN_LoopBackSack,/*!<Working mode:LoopBackSack*/
}ModSelect_TypeDef;

/**
 * @}
 */
/* End of constants -----------------------------------------------------*/

/** @defgroup CAN_Struct CAN Struct
 * @{
 */
/** @brief CAN send data structures
  * @{
  */
typedef struct
{
	uint32_t CAN_TXID; /*!< This member configures the ID of the CAN sent data */
  uint32_t Tx_msg[8]; /*!< This member configures the sending data of CAN*/
	uint16_t Data_len; /*!< This member configures the length of the sent data of CAN*/
	uint8_t CAN_RTR; /*!< This member configures whether the sent data of CAN is a remote frame*/
	uint8_t CAN_FDF; /*!< This member configures whether the sent data of CAN is FD*/
	uint8_t CAN_BRS; /*!<This member configures whether CAN sends data at a variable baud rate*/
	uint8_t CAN_IDE; /*!< This member configures whether the sent data of CAN is an extended frame*/  
	uint8_t Tx_msg_len; /*!< This member configures the number of data sent by CAN */
}CanTxMsg;

typedef struct
{
	uint32_t CAN_RXID; /*!< This member is the ID of the CAN receive data */
	uint32_t Rx_msg[8];/*!< This member is the receive data of CAN*/ 
	uint8_t CAN_IDE; /*!< This member is The frame format of the received data */
	uint16_t Data_len;/*!< This member is the length of the receive data of CAN*/
	uint8_t CAN_RTR; /*!< This member is The frame format of the received data*/
	uint8_t CAN_FDF; /*!< This member configures whether the received data of CAN is FD*/
	uint8_t CAN_BRS;  /*!<This member Gets whether the baud rate of the received data is variable */
} CanRxMsg;

typedef struct
{
	uint32_t S_SJW; /*!< This member configures CAN SLOW BAUD. */	
	
	uint32_t S_SEG1; /*!< This member configures CAN SLOW BAUD. */	
	
	uint32_t S_SEG2; /*!< This member configures CAN SLOW BAUD. */	
	
	uint32_t S_PRESCALER; /*!< This member configures CAN SLOW BAUD. */	
	
	uint32_t F_SJW; /*!< This member configures CAN HIGH BAUD. */	
	
	uint32_t F_SEG1; /*!< This member configures CAN HIGH BAUD. */
	
	uint32_t F_SEG2; /*!< This member configures CAN HIGH BAUD. */
	
	uint32_t F_PRESCALER; /*!< This member configures CAN HIGH BAUD. */
	
	uint32_t CANFDFrame; /*!< This member configures CAN Frame.
                                              This parameter can be a value of FD_Mode_on/FD_Mode_off */	

	uint32_t CANROMSelect; /*!< This member configures CAN ROMSelect.
                                              This parameter can be a value of @ref CANROM_TypeDef */
	uint32_t CAN_MOD; /*!< This member configures CAN  mode.
                                              This parameter can be a value of @ref ModSelect_TypeDef */
	
  uint32_t CANTSMODESelect; /*!< This member configures CAN TSMODESelect.
                                              This parameter can be a value of @ref CANTSMODE_TypeDef */
	
	uint32_t CANFDISOSelect; /*!< This member configures CAN FDISO Select.
                                              This parameter can be a value of @ref CANFD_ISO_MODE_TypeDef */
	
	uint16_t CANTimeStampPositon; /*!< This member configures CAN TimeStamp Positon.
                                              This parameter can be a value of @ref CANTimeStampPosition_TypeDef */
	
	uint16_t CANTBUFSelect; /*!< This member configures CAN Sending mode.
                                              This parameter can be a value of @ref CANTBUF_TypeDef */
	
	uint16_t  TransMod; /*!< This member configures CAN TransMod.
                                              This parameter can be a value of @ref ModSelect_TypeDef */
	
	FunctionalState CANTXEN; /*!< This member configures CAN Send enable.
                                              This parameter can be a value of @ref FunctionalState */
	
	FunctionalState CANRXEN; /*!< This member configures CAN Receive enable.
                                              This parameter can be a value of @ref FunctionalState */
	
	FunctionalState CANTimeStamp; /*!< This member configures CAN TimeStamp mode.
                                              This parameter can be a value of @ref FunctionalState */
	
	FunctionalState CANTimeStampCnt; /*!< This member configures CAN TimeStampCnt mode.
                                              This parameter can be a value of @ref FunctionalState */
	
	FunctionalState CAN_PTB_AutoRetrans; /*!< This member configures CAN PTB AutoRetrans enable.
                                              This parameter can be a value of @ref FunctionalState */
	
	FunctionalState CAN_STB_AutoRetrans; /*!< This member configures CAN STB AutoRetrans enable.
                                              This parameter can be a value of @ref FunctionalState */
	
}CAN_InitTypeDef;

/** @brief Filter structure
  * @{
  */
typedef struct
{
	uint32_t Acode;/*!<Filter ID Settings*/
	uint32_t Amask;/*!<Filter ID Settings*/
	uint8_t CAN_Fliter;/*!<Configure filter*/
  uint8_t CANFliterFrame;/*!<Filter frame format*/
}CAN_FliterTypeDef;



#endif

#define CAN_FDMode_on 0x80000000
#define CAN_FDMode_off 0x00000000
#define CAN_CFG_STAT_ACK 0x80000000
/** @brief CAN_synchronisation_jump_width 
  * @{
  */

#define CAN_SJW_1tq                 ((uint8_t)0x00)  /*!< 1 time quantum */
#define CAN_SJW_2tq                 ((uint8_t)0x01)  /*!< 2 time quantum */
#define CAN_SJW_3tq                 ((uint8_t)0x02)  /*!< 3 time quantum */
#define CAN_SJW_4tq                 ((uint8_t)0x03)  /*!< 4 time quantum */

#define IS_CAN_SJW(SJW) (((SJW) == CAN_SJW_1tq) || ((SJW) == CAN_SJW_2tq)|| \
                         ((SJW) == CAN_SJW_3tq) || ((SJW) == CAN_SJW_4tq))
/**
  * @}
  */

/** @brief CAN_time_quantum_in_bit_segment_1 
  * @{
  */

#define CAN_SEG1_1tq                 ((uint8_t)0x00)  /*!< 1 time quantum */
#define CAN_SEG1_2tq                 ((uint8_t)0x01)  /*!< 2 time quantum */
#define CAN_SEG1_3tq                 ((uint8_t)0x02)  /*!< 3 time quantum */
#define CAN_SEG1_4tq                 ((uint8_t)0x03)  /*!< 4 time quantum */
#define CAN_SEG1_5tq                 ((uint8_t)0x04)  /*!< 5 time quantum */
#define CAN_SEG1_6tq                 ((uint8_t)0x05)  /*!< 6 time quantum */
#define CAN_SEG1_7tq                 ((uint8_t)0x06)  /*!< 7 time quantum */
#define CAN_SEG1_8tq                 ((uint8_t)0x07)  /*!< 8 time quantum */
#define CAN_SEG1_9tq                 ((uint8_t)0x08)  /*!< 9 time quantum */
#define CAN_SEG1_10tq                ((uint8_t)0x09)  /*!< 10 time quantum */
#define CAN_SEG1_11tq                ((uint8_t)0x0A)  /*!< 11 time quantum */
#define CAN_SEG1_12tq                ((uint8_t)0x0B)  /*!< 12 time quantum */
#define CAN_SEG1_13tq                ((uint8_t)0x0C)  /*!< 13 time quantum */
#define CAN_SEG1_14tq                ((uint8_t)0x0D)  /*!< 14 time quantum */
#define CAN_SEG1_15tq                ((uint8_t)0x0E)  /*!< 15 time quantum */
#define CAN_SEG1_16tq                ((uint8_t)0x0F)  /*!< 16 time quantum */

#define IS_CAN_SEG1(SEG1) ((SEG1) <= CAN_SEG1_16tq)
/**
  * @}
  */

/** @brief CAN_time_quantum_in_bit_segment_2 
  * @{
  */

#define CAN_SEG2_1tq                 ((uint8_t)0x00)  /*!< 1 time quantum */
#define CAN_SEG2_2tq                 ((uint8_t)0x01)  /*!< 2 time quantum */
#define CAN_SEG2_3tq                 ((uint8_t)0x02)  /*!< 3 time quantum */
#define CAN_SEG2_4tq                 ((uint8_t)0x03)  /*!< 4 time quantum */
#define CAN_SEG2_5tq                 ((uint8_t)0x04)  /*!< 5 time quantum */
#define CAN_SEG2_6tq                 ((uint8_t)0x05)  /*!< 6 time quantum */
#define CAN_SEG2_7tq                 ((uint8_t)0x06)  /*!< 7 time quantum */
#define CAN_SEG2_8tq                 ((uint8_t)0x07)  /*!< 8 time quantum */

#define IS_CAN_SEG2(SEG2) ((SEG2) <= CAN_SEG2_8tq)

/**
  * @}
  */
#define IS_CAN_PRESCALER(PRESCALER) (((PRESCALER) >= 0) && ((PRESCALER) <= 255))
#define IS_CAN_ALL_PERIPH(PERIPH) ((PERIPH) == CAN)
/* CAN Base functions ********************************************************/
void CAN_DeInit(CAN_TypeDef* CANx);
void CAN_Init(CAN_TypeDef *CANx, CAN_InitTypeDef *CAN_InitStruct);
void CAN_StructInit(CAN_InitTypeDef* CAN_InitStruct);
void CAN_TBUFSelect(CAN_TypeDef *CANx, CANTBUF_TypeDef CANTBUF);
void CAN_FBaudRate_Select(unsigned int CAN_Clk,unsigned int CAN_FPrescaler,uint32_t BaudRate);
void CAN_SBaudRate_Select(unsigned int CAN_Clk,unsigned int CAN_FPrescaler,uint32_t BaudRate);
void CAN_FDMODECmd(CAN_TypeDef *CANx,FunctionalState NewState );
void CAN_Trans_Select(CAN_TypeDef *CANx,CAN_TransMod_TypeDef TransModSelect);
void CAN_RxThresholdConfig(CAN_TypeDef *CANx, int Rth);
void CAN_RxDataALLStorageMode ( CAN_TypeDef *CANx, FunctionalState NewState );
void CAN_PTBAutoRetransMode(CAN_TypeDef *CANx, FunctionalState NewState);
void CAN_STBAutoRetransMode(CAN_TypeDef *CANx, FunctionalState NewState);
void CAN_FliterInit( CAN_FliterTypeDef *CAN_FliterStruct);
void CAN_ModeSelect(CAN_TypeDef *CANx, ModSelect_TypeDef CAN_MOD);
/* Data transfers functions ********************************************************/
void CAN_Trans_Init(CAN_TypeDef *CANx, CanTxMsg *CAN_Tx_msg);
void CAN_TxDCompensateCmd ( CAN_TypeDef *CANx, FunctionalState NewState );
void CAN_TransStop(CAN_TypeDef *CANx);
void CAN_TDCompensateCmd ( CAN_TypeDef *CANx, FunctionalState NewState );
void CAN_RecieveConfig(CAN_TypeDef *CANx, CanRxMsg* RxMessage);
/* Interrupts and flags management functions  **********************************************/
void CAN_ITConfig(CAN_TypeDef* CANx, uint32_t CAN_IT, FunctionalState NewState);
ITStatus CAN_GetFlagStatus(CAN_TypeDef *CANx, uint32_t CAN_Flag);
void CAN_ClearFlag(CAN_TypeDef *CANx, uint32_t CAN_Flag);
/* Number of error data and Reset  **********************************************/
void CAN_ErrorThresholdconfig ( CAN_TypeDef* CANx, uint8_t Errorcnt );
uint8_t CAN_GetTECNT(CAN_TypeDef* CANx);
uint8_t CAN_GetRECNT(CAN_TypeDef* CANx);
void CAN_ResetCmd(CAN_TypeDef *CANx, FunctionalState NewState);
/* Timestamp function implementation configuration **********************************************/
void CAN_TIMEPOSConfig(CAN_TypeDef* CANx, CANTimeStampPosition_TypeDef CANTimeStampPosition);
void CAN_TIMEENCmd(CAN_TypeDef* CANx, FunctionalState NewState);
void CAN_TIMECounterCmd(CAN_TypeDef* CANx, FunctionalState NewState);
/************************ (C) COPYRIGHT SOC Microelectronics *****END OF FILE****/
