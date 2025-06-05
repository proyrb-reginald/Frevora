/*
 ******************************************************************************
 * @file    sc32f1xxx_cmp.c
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief  CMP function module
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
#include "sc32f1xxx_cmp.h"


/** @defgroup CMP_Group1 Configuration of the CMP computation unit functions
 *  @brief   Configuration of the CMP computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### CMP configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitialize the CMPx peripheral registers to their default reset values.
 * @param  CMPx[out]:
 *                SC32f10xx Selection range(CMP)
 *                SC32f11xx Selection range(CMP)
 *                SC32f12xx Selection range(CMP)
 *                SC32f15xx Selection range(CMP_0 - CMP3) 
 *               - CMP: Only CMP can be select the CMPx peripheral.
 *               - CMP_0: select the CMP0 peripheral
 *               - CMP_1: select the CMP1 peripheral
 *               - CMP_2: select the CMP2 peripheral 
 *               - CMP3: select the CMP3 peripheral 
 * @retval None
 */
void CMP_DeInit ( CMP_TypeDef* CMPx )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );

    if ( CMPx == CMP )
    {
        /* Enable CMP0 reset state */
        CMPx->CMP_CFG = 0x0000;
        CMPx->CMP_STS = 0xFFFF;
    }
#elif defined(SC32f15xx)
    assert_param(IS_CMP_ALL_PERIPH(CMPx));
   if(CMPx==CMP_0 ||CMPx==CMP_1 ||CMPx==CMP_2 )
	 {
		CMP->CMP_STS = 0x00;
    CMP->CMP_CON = 0x00;
    CMP->CMP_IDE = 0x00;
    CMP->CMP_CFG = 0x00;
	  CMP->CMP_CFG1 = 0x00;
    CMP->CMP_CFG2 = 0x00;
	 }
	 else if(CMPx==CMP3)
	 {
    CMP3->CMP_STS = 0x00;
    CMP3->CMP_CON = 0x00;
	  CMP3->CMP_IDE = 0x00;
    CMP3->CMP_CFG = 0x00;
	 }
#endif		
}

/**
 * @brief  Initializes the peripheral CMP register according to the parameters specified in CMP_InitStruct
 * @param  CMPx[out]:
 *                SC32f10xx Selection range(CMP)
 *                SC32f11xx Selection range(CMP)
 *                SC32f12xx Selection range(CMP)
 *                SC32f15xx Selection range(CMP_0 - CMP3) 
 *               - CMP: Only CMP can be select the CMPx peripheral.
 *               - CMP_0: select the CMP0 peripheral
 *               - CMP_1: select the CMP1 peripheral
 *               - CMP_2: select the CMP2 peripheral 
 *               - CMP3: select the CMP3 peripheral 
 * @param  CMP_InitStruct[out]:pointer to a CMP_InitTypeDef structure which will be initialized.
 * @retval None
 */
void CMP_Init ( CMP_TypeDef* CMPx, CMP_InitTypeDef* CMP_InitStruct )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );
    assert_param ( IS_CMP_Negative ( CMP_InitStruct->CMP_Negative ) );
    assert_param ( IS_CMP_Positive ( CMP_InitStruct->CMP_Positive ) );
    assert_param ( IS_CMP_TRIGGER ( CMP_InitStruct->CMP_TriggerMode ) );

    /*---------------------------- CMPx CMP_CFG Configuration ------------------------*/
    /* Get the CMPx CMP_CFG value */
    tmpreg = CMPx->CMP_CFG;
    /* Clear CMPFS bits */
    tmpreg &= ( uint32_t ) ~ ( CMP_CFG_CMPIS | CMP_CFG_CMPP | CMP_CFG_CMPIM |
                               CMP_CFG_CMPRF ) ;

    /* Set CMPRF bits according to CMP_NEGATIVE value */
    /* Set CMPIS bits and CMPIP bit according to CMP_POSITIVE value */
    /* Set CMPIM bits according to CMP_TriggerMode value */
    tmpreg |= ( uint32_t ) ( CMP_InitStruct->CMP_Negative | CMP_InitStruct->CMP_Positive |
                             CMP_InitStruct->CMP_TriggerMode );
    /* Write to CMPx CMP_CFG */
    CMPx->CMP_CFG = tmpreg;
#elif defined(SC32f15xx)
    uint32_t tmpreg;
	  if(CMPx==CMP_0 ||CMPx==CMP_1 ||CMPx==CMP_2 )
		{
			/* Check the parameters */
			assert_param(IS_CMP_ALL_PERIPH(CMPx));
			assert_param(IS_CMP_Negative(CMP_InitStruct->CMP_Negative));
			assert_param(IS_CMP_TRIGGER(CMP_InitStruct->CMP_TriggerMode));

			/*---------------------------- CMPx CMP_CFG Configuration ------------------------*/
			tmpreg = CMP->CMP_CON;
		
			tmpreg &= (uint16_t)~(CMP_CON_HYS);
		
			tmpreg |= CMP_InitStruct->CMP_HYS;
		
			CMP->CMP_CON = tmpreg;
		
			if(CMPx==CMP_0)
			{
			tmpreg = CMP->CMP_CFG;

			tmpreg &= (uint16_t)~(CMPX_CFG_CMPIM | CMPX_CFG_CMPNS | CMPX_CFG_CMPPS);

			/* Set CMPIS bits and CMPIP bit according to CMP_Sub0_Positive value */
			/* Set CMPIM bits according to CMP_TriggerMode value */
			tmpreg |= (uint32_t)(CMP_InitStruct->CMP_Negative | CMP_InitStruct->CMP_Positive |
													 CMP_InitStruct->CMP_TriggerMode);
			/* Write to CMPx CMP_CFG */
			CMP->CMP_CFG = tmpreg;
			}
			else if(CMPx==CMP_1)
			{
			/*---------------------------- CMPx CMP_CFG Configuration ------------------------*/
			tmpreg = CMP->CMP_CFG1;

			tmpreg &= (uint16_t)~(CMPX_CFG_CMPIM | CMPX_CFG_CMPNS | CMPX_CFG_CMPPS );
			/* Set CMPIS bits and CMPIP bit according to CMP_Sub0_Positive value */
			/* Set CMPIM bits according to CMP_TriggerMode value */
			tmpreg |= (uint32_t)(CMP_InitStruct->CMP_Negative |
													 CMP_InitStruct->CMP_TriggerMode);
			/* Write to CMPx CMP_CFG */
			CMP->CMP_CFG1 = tmpreg;
			}
			else if(CMPx==CMP_2)
			{
			/*---------------------------- CMPx CMP_CFG Configuration ------------------------*/
			tmpreg = CMP->CMP_CFG2;

			tmpreg &= (uint16_t)~(CMPX_CFG_CMPIM | CMPX_CFG_CMPNS | CMPX_CFG_CMPPS );
			/* Set CMPIS bits and CMPIP bit according to CMP_Sub0_Positive value */
			/* Set CMPIM bits according to CMP_TriggerMode value */
			tmpreg |= (uint32_t)(CMP_InitStruct->CMP_Negative|
													 CMP_InitStruct->CMP_TriggerMode);
			/* Write to CMPx CMP_CFG */
			CMP->CMP_CFG2 = tmpreg;
			}
		}
	  else if(CMPx==CMP3)
	 {
    /* Check the parameters */
    assert_param(IS_CMP_ALL_PERIPH(CMPx));
    assert_param(IS_CMP_Negative(CMP_InitStruct->CMP_Negative));
    assert_param(IS_CMP_Positive(CMP_InitStruct->CMP_Positive));
    assert_param(IS_CMP_TRIGGER(CMP_InitStruct->CMP_TriggerMode));

	  CMP3->CMP_CON &= ~(CMP_CON_REFSEL|CMP_CON_HYS);
    CMP3->CMP_CON |= (uint32_t)(CMP_InitStruct->CMP_VREF |  CMP_InitStruct->CMP_HYS);

    /*---------------------------- CMPx CMP_CFG Configuration ------------------------*/
    tmpreg = CMP3->CMP_CFG;

    tmpreg &= (uint16_t)~(CMP_CFG_CMPIM | CMP_CFG_CMPNS | CMP_CFG_CMPPS | CMP_CFG_CMPRF);

    /* Set CMPRF bits according to CMP_NEGATIVE value */
    /* Set CMPIS bits and CMPIP bit according to CMP_POSITIVE value */
    /* Set CMPIM bits according to CMP_TriggerMode value */
    tmpreg |= (uint32_t)(CMP_InitStruct->CMP_Negative | CMP_InitStruct->CMP_Positive |
                         CMP_InitStruct->CMP_TriggerMode | CMP_InitStruct->CMP_CMPRF);
    /* Write to CMPx CMP_CFG */
    CMP3->CMP_CFG |= tmpreg;
	}
#endif
}

/**
  * @brief  Fills each CMP_CMPInitStruct member with its default value.
  * @param  CMP_InitStruct[out]:pointer to a CMP_InitTypeDef structure which will be initialized.
  * @retval None
  */
void CMP_StructInit ( CMP_InitTypeDef* CMP_InitStruct )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    /* Set the default configuration */
    CMP_InitStruct->CMP_Negative = CMP_Negative_CMPR;
    CMP_InitStruct->CMP_Positive = CMP_Positive_CMP0;
    CMP_InitStruct->CMP_TriggerMode = CMP_TriggerMode_Disable;
#elif defined(SC32f15xx)
    /* Set the default configuration */

    CMP_InitStruct->CMP_Negative     = CMP0_1_2NegativeSelect_CMPxN;
    CMP_InitStruct->CMP_Positive     = CMP0_Positive_CMP0P;
    CMP_InitStruct->CMP_VREF         = CMP0_1_2RefSource_VDD;
    CMP_InitStruct->CMP_CMPRF        = CMP3_Negative_1D16CMP_VREF;
    CMP_InitStruct->CMP_TriggerMode  = CMP0_1_2TriggerMode_Disable;
    CMP_InitStruct->CMP_HYS          = CMP_HYS_0mV;	
#endif
}

/**
 * @brief  Enables or disables the specified CMP.
 * @param  CMPx[out]:
 *                SC32f10xx Selection range(CMP)
 *                SC32f11xx Selection range(CMP)
 *                SC32f12xx Selection range(CMP)
 *                SC32f15xx Selection range(CMP_0 - CMP3) 
 *               - CMP: Only CMP can be select the CMPx peripheral.
 *               - CMP_0: select the CMP0 peripheral
 *               - CMP_1: select the CMP1 peripheral
 *               - CMP_2: select the CMP2 peripheral 
 *               - CMP3: select the CMP3 peripheral 
 * @param  NewState[in]: new state of the CMPx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void CMP_Cmd ( CMP_TypeDef* CMPx, FunctionalState NewState )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the CMP Function */
        CMPx->CMP_CFG |= CMP_CFG_CMPEN;
    }
    else
    {
        /* Disable the CMP Function */
        CMPx->CMP_CFG &= ( uint16_t ) ~CMP_CFG_CMPEN;
    }
#elif  defined(SC32f15xx)
    /* Check the parameters */
    assert_param(IS_CMP_ALL_PERIPH(CMPx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

	 if(CMPx==CMP_0)
		{
			if(NewState != DISABLE)
			{
					/* Enable the CMP Function */
				 CMP->CMP_CFG |= (uint16_t)CMPX_CFG_CMPEN;
			}
			else
			{
					/* Disable the CMP Function */
				 CMP->CMP_CFG &= (uint16_t)~CMPX_CFG_CMPEN;
			}
 	  }
		 if(CMPx==CMP_1)
		{
			if(NewState != DISABLE)
     {
        /* Enable the CMP Function */
       CMP->CMP_CFG1 |= (uint16_t)CMPX_CFG_CMPEN;
     }
     else
     {
        /* Disable the CMP Function */
       CMP->CMP_CFG1 &= (uint16_t)~CMPX_CFG_CMPEN;
     }
		}
		if(CMPx==CMP_2)
		{
			if(NewState != DISABLE)
     {
        /* Enable the CMP Function */
       CMP->CMP_CFG2 |= (uint16_t)CMPX_CFG_CMPEN;
     }
     else
     {
        /* Disable the CMP Function */
       CMP->CMP_CFG2 &= (uint16_t)~CMPX_CFG_CMPEN;
     }
		}
	  if(CMPx==CMP3)
	  {
      if(NewState != DISABLE)
     {
      /* Enable the CMP Function */
      CMP3->CMP_CFG |= (uint16_t)CMP_CFG_CMPEN;
     }
      else
     {
      /* Disable the CMP Function */
      CMP3->CMP_CFG &= (uint16_t)~CMP_CFG_CMPEN;
     }
	}
#endif	
}
/**
 * @brief  Configure the CMP negative input channel
 * @param  CMPx[out]:
 *                SC32f10xx Selection range(CMP)
 *                SC32f11xx Selection range(CMP)
 *                SC32f12xx Selection range(CMP)
 *                SC32f15xx Selection range(CMP_0 - CMP3) 
 *               - CMP: Only CMP can be select the CMPx peripheral.
 *               - CMP_0: select the CMP0 peripheral
 *               - CMP_1: select the CMP1 peripheral
 *               - CMP_2: select the CMP2 peripheral 
 *               - CMP3: select the CMP3 peripheral 
 * @param  CMP_Negative_Channel[in]:
 *                  - CMPx_Negative_CMPR:The comparison voltage of CMP is CMPR
 *                  - CMPx_Negative_1D16VDD:The comparison voltage of CMP is 1/16VDD
 *                  - CMPx_Negative_2D16VDD:The comparison voltage of CMP is 2/16VDD
 *                  - CMPx_Negative_3D16VDD:The comparison voltage of CMP is 3/16VDD
 *                  - CMPx_Negative_4D16VDD:The comparison voltage of CMP is 4/16VDD
 *                  - CMPx_Negative_5D16VDD:The comparison voltage of CMP is 5/16VDD
 *                  - CMPx_Negative_6D16VDD:The comparison voltage of CMP is 6/16VDD
 *                  - CMPx_Negative_7D16VDD:The comparison voltage of CMP is 7/16VDD
 *                  - CMPx_Negative_8D16VDD:The comparison voltage of CMP is 8/16VDD
 *                  - CMPx_Negative_9D16VDD: The comparison voltage of CMP is 9/16VDD
 *                  - CMPx_Negative_10D16VDD:The comparison voltage of CMP is 10/16VDD
 *                  - CMPx_Negative_11D16VDD:The comparison voltage of CMP is 11/16VDD
 *                  - CMPx_Negative_12D16VDD:The comparison voltage of CMP is 12/16VDD
 *                  - CMPx_Negative_13D16VDD:The comparison voltage of CMP is 13/16VDD
 *                  - CMPx_Negative_14D16VDD:The comparison voltage of CMP is 14/16VDD
 *                  - CMPx_Negative_15D16VDD:The comparison voltage of CMP is 15/16VDD
 * @retval None
 */
void CMP_SetNegativeChannel ( CMP_TypeDef* CMPx, CMP_Negative_TypeDef CMP_Negative_Channel )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );
    assert_param ( IS_CMP_Negative ( CMP_Negative_Channel ) );

    CMPx->CMP_CFG &= ( uint32_t ) ~CMP_CFG_CMPRF;
    CMPx->CMP_CFG |= ( uint32_t ) CMP_Negative_Channel;
#elif  defined(SC32f15xx)
	/* Check the parameters */
  assert_param(IS_CMP_ALL_PERIPH(CMPx));
  assert_param(IS_CMP_Negative(CMP_Negative_Channel));
  if(CMPx == CMP3)
	{
	CMP3->CMP_CFG &= (uint32_t) ~CMP_CFG_CMPRF;
  CMP3->CMP_CFG |= (uint32_t)  CMP_Negative_Channel;
	}	
#endif	
}

/**
 * @brief  Get the CMP negative input channel
 * @param  CMPx[out]:
 *                SC32f10xx Selection range(CMP)
 *                SC32f11xx Selection range(CMP)
 *                SC32f12xx Selection range(CMP)
 *                SC32f15xx Selection range(CMP_0 - CMP3) 
 *               - CMP: Only CMP can be select the CMPx peripheral.
 *               - CMP_0: select the CMP0 peripheral
 *               - CMP_1: select the CMP1 peripheral
 *               - CMP_2: select the CMP2 peripheral 
 *               - CMP3: select the CMP3 peripheral 
 * @retval  CMP_Negative_Channel[in]: CMP negative input channel type.
 *                  - CMPx_Negative_CMPR:The comparison voltage of CMP is CMPR
 *                  - CMPx_Negative_1D16VDD:The comparison voltage of CMP is 1/16VDD
 *                  - CMPx_Negative_2D16VDD:The comparison voltage of CMP is 2/16VDD
 *                  - CMPx_Negative_3D16VDD:The comparison voltage of CMP is 3/16VDD
 *                  - CMPx_Negative_4D16VDD:The comparison voltage of CMP is 4/16VDD
 *                  - CMPx_Negative_5D16VDD:The comparison voltage of CMP is 5/16VDD
 *                  - CMPx_Negative_6D16VDD:The comparison voltage of CMP is 6/16VDD
 *                  - CMPx_Negative_7D16VDD:The comparison voltage of CMP is 7/16VDD
 *                  - CMPx_Negative_8D16VDD:The comparison voltage of CMP is 8/16VDD
 *                  - CMPx_Negative_9D16VDD: The comparison voltage of CMP is 9/16VDD
 *                  - CMPx_Negative_10D16VDD:The comparison voltage of CMP is 10/16VDD
 *                  - CMPx_Negative_11D16VDD:The comparison voltage of CMP is 11/16VDD
 *                  - CMPx_Negative_12D16VDD:The comparison voltage of CMP is 12/16VDD
 *                  - CMPx_Negative_13D16VDD:The comparison voltage of CMP is 13/16VDD
 *                  - CMPx_Negative_14D16VDD:The comparison voltage of CMP is 14/16VDD
 *                  - CMPx_Negative_15D16VDD:The comparison voltage of CMP is 15/16VDD
 */
CMP_Negative_TypeDef CMP_GetNegativeChannel ( CMP_TypeDef* CMPx )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );

    /* Get the CMP negative input channel type */
    return ( CMP_Negative_TypeDef ) ( CMPx->CMP_CFG & CMP_CFG_CMPRF );
#elif  defined(SC32f15xx)
	CMP_Negative_TypeDef ReadCMPRF;
	/* Check the parameters */
  assert_param(IS_CMP_ALL_PERIPH(CMPx));
  if(CMPx == CMP3)
	{
		ReadCMPRF = (CMP_Negative_TypeDef)(CMP3->CMP_CFG & CMP_CFG_CMPRF);
	}
	/* Get the CMP negative input channel type */
	return (CMP_Negative_TypeDef)ReadCMPRF;
#endif	
}

/**
 * @brief  Configure the CMP positive input channel
 * @param  CMPx[out]:
 *                SC32f10xx Selection range(CMP)
 *                SC32f11xx Selection range(CMP)
 *                SC32f12xx Selection range(CMP)
 *                SC32f15xx Selection range(CMP_0 - CMP3) 
 *               - CMP: Only CMP can be select the CMPx peripheral.
 *               - CMP_0: select the CMP0 peripheral
 *               - CMP_1: select the CMP1 peripheral
 *               - CMP_2: select the CMP2 peripheral 
 *               - CMP3: select the CMP3 peripheral 
 * @param  CMP_Positive_Channel[in]: CMP positive input channel selection.
 *                  SC32f10xx Selection range(CMP_Positive_CMP0-CMP_Positive_CMP3,CMP_Positive_1_5V)
 *                  SC32f11xx Selection range(CMP_Positive_CMP0-CMP_Positive_CMP1,CMP_Positive_1_5V,CMP_Positive_PGA)
 *                  SC32f12xx Selection range(CMP_Positive_CMP0-CMP_Positive_CMP3,CMP_Positive_1_5V,CMP_Positive_OP)
 *                  SC32f15xx Selection range(CMP0_Positive_CMP0P-CMP3_Positive_OP2O)
 *                  - CMP_Positive_CMP0:Select CMP0 as the CMP input port
 *                  - CMP_Positive_CMP1:Select CMP1 as the CMP input port
 *                  - CMP_Positive_CMP2:Select CMP2 as the CMP input port
 *                  - CMP_Positive_CMP3:Select CMP3 as the CMP input port
 *                  - CMP_Positive_1_5V:Select CMPP as the CMP input port,CMPP is 1.5V reference voltage
 *                  - CMP_Positive_PGA:Select PGA as the CMP input port
 *                  - CMP_Positive_OP:Select OP as the CMP input port
 *                  - CMP0_Positive_CMP0P:CMP0 Select CMP0P as the CMP0 Positive port   
 *                  - CMP0_Positive_OP1O:CMP0 Select OP1O as the CMP Positive port  
 *                  - CMP0_Positive_OP2O:CMP0 Select OP2O as the CMP Positive port   
 *                  - CMP3_Positive_CMP3P:Select CMP3 as the CMP input port   
 *                  - CMP3_Positive_OP1O :Select OP1O as the CMP input port 
 *                  - CMP3_Positive_OP2O:Select OP2Oas the CMP input port 
 * @retval None
 */
void CMP_SetPositiveChannel ( CMP_TypeDef* CMPx, CMP_Positive_TypeDef CMP_Positive_Channel )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );
    assert_param ( IS_CMP_Positive ( CMP_Positive_Channel ) );

    CMPx->CMP_CFG &= ( uint32_t ) ~ ( CMP_CFG_CMPIS | CMP_CFG_CMPP );
    CMPx->CMP_CFG |= ( uint32_t ) CMP_Positive_Channel;
#elif  defined(SC32f15xx)
		/* Check the parameters */
		assert_param(IS_CMP_ALL_PERIPH(CMPx));
		assert_param(IS_CMP_Positive(CMP_Positive_Channel));
		if(CMPx == CMP_0)
		{
		CMP->CMP_CFG &= (uint32_t) ~(CMPX_CFG_CMPPS);
		CMP->CMP_CFG |= (uint32_t) CMP_Positive_Channel;
		}
		if(CMPx == CMP3)
		{
		CMP3->CMP_CFG &= (uint32_t) ~(CMP_CFG_CMPPS);
		CMP3->CMP_CFG |= (uint32_t) CMP_Positive_Channel;		
		}
#endif	
}

/**
 * @brief  Get the CMP positive input channel
 * @param  CMPx[out]:
 *                SC32f10xx Selection range(CMP)
 *                SC32f11xx Selection range(CMP)
 *                SC32f12xx Selection range(CMP)
 *                SC32f15xx Selection range(CMP_0 - CMP3) 
 *               - CMP: Only CMP can be select the CMPx peripheral.
 *               - CMP_0: select the CMP0 peripheral
 *               - CMP_1: select the CMP1 peripheral
 *               - CMP_2: select the CMP2 peripheral 
 *               - CMP3: select the CMP3 peripheral 
 * @param  CMP_Positive_Channel[in]: CMP positive input channel selection.
 *                  SC32f10xx Selection range(CMP_Positive_CMP0-CMP_Positive_CMP3,CMP_Positive_1_5V)
 *                  SC32f11xx Selection range(CMP_Positive_CMP0-CMP_Positive_CMP1,CMP_Positive_1_5V,CMP_Positive_PGA)
 *                  SC32f12xx Selection range(CMP_Positive_CMP0-CMP_Positive_CMP3,CMP_Positive_1_5V,CMP_Positive_OP)
 *                  SC32f15xx Selection range(CMP0_Positive_CMP0P-CMP3_Positive_OP2O)
 *                  - CMP_Positive_CMP0:Select CMP0 as the CMP input port
 *                  - CMP_Positive_CMP1:Select CMP1 as the CMP input port
 *                  - CMP_Positive_CMP2:Select CMP2 as the CMP input port
 *                  - CMP_Positive_CMP3:Select CMP3 as the CMP input port
 *                  - CMP_Positive_1_5V:Select CMPP as the CMP input port,CMPP is 1.5V reference voltage
 *                  - CMP_Positive_PGA:Select PGA as the CMP input port
 *                  - CMP_Positive_OP:Select OP as the CMP input port
 *                  - CMP0_Positive_CMP0P:CMP0 Select CMP0P as the CMP0 Positive port   
 *                  - CMP0_Positive_OP1O:CMP0 Select OP1O as the CMP Positive port  
 *                  - CMP0_Positive_OP2O:CMP0 Select OP2O as the CMP Positive port   
 *                  - CMP3_Positive_CMP3P:Select CMP3 as the CMP input port   
 *                  - CMP3_Positive_OP1O :Select OP1O as the CMP input port 
 *                  - CMP3_Positive_OP2O:Select OP2Oas the CMP input port 
 */
CMP_Positive_TypeDef CMP_GetPositiveChannel ( CMP_TypeDef* CMPx )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );

    /* Get the CMP positive input channel type */
    return ( CMP_Positive_TypeDef ) ( CMPx->CMP_CFG & ( CMP_CFG_CMPIS | CMP_CFG_CMPP ) );
#elif defined(SC32f15xx)
	CMP_Positive_TypeDef ReadCMPPositive;
	/* Check the parameters */
  assert_param(IS_CMP_ALL_PERIPH(CMPx));
  if(CMPx == CMP_0)
	{
		ReadCMPPositive = (CMP_Positive_TypeDef)(CMP->CMP_CFG & ( CMPX_CFG_CMPPS));
	}
	if(CMPx == CMP3)
	{
		ReadCMPPositive = (CMP_Positive_TypeDef)(CMP3->CMP_CFG & ( CMP_CFG_CMPPS));
	}
	/* Get the CMP positive input channel type */
	return ReadCMPPositive;
#endif	
	
}
#if defined(SC32f15xx)
/**
 * @brief  Configure the CMP negative input channel
 * @param  CMPx[out]: 
 *               - CMP_0: select the CMP0 peripheral
 *               - CMP_1: select the CMP1 peripheral
 *               - CMP_2: select the CMP2 peripheral 
 *               - CMP3: select the CMP3 peripheral 
 * @param  CMP_Negative_TypeDef[in]: CMP negative input channel selection.
 *                  - CMP0_1_2NegativeSelect_CMPxN:Select CMPxN as the CMP0_1_2 Negative port   
 *                  - CMP0_1_2NegativeSelect_DAC:Select DAC as the CMP0_1_2 Negative port   
 *                  - CMP0_1_2NegativeSelect_BEMF_MID:Select BEMF_MID as the CMP0_1_2 Negative port   
 *                  - CMP3_NegativeSelect_CMPxN:Select CMPN as the CMP negative input port
 *                  - CMP3_NegativeSelect_DAC:Select DAC as the CMP negative input port  
 *                  - CMP3_NegativeSelect_CMPRF:Select CMPRF as the CMP negative input port   
 * @retval None
 */
void CMP_NegativeSelection(CMP_TypeDef* CMPx, CMP_NegativeSelect_TypeDef NegativeSelect)
{
	/* Check the parameters */
  assert_param(IS_CMP_ALL_PERIPH(CMPx));
  assert_param(IS_CMP_Negative(NegativeSelect));
  if(CMPx == CMP_0)
	{
	CMP->CMP_CFG &= (uint32_t) ~(CMPX_CFG_CMPNS);
  CMP->CMP_CFG |= (uint32_t) NegativeSelect;
	}
	if(CMPx == CMP_1)
	{
	CMP->CMP_CFG1 &= (uint32_t) ~(CMPX_CFG_CMPNS);
  CMP->CMP_CFG1 |= (uint32_t) NegativeSelect;
	}
	if(CMPx == CMP_2)
	{
	CMP->CMP_CFG2 &= (uint32_t) ~(CMPX_CFG_CMPNS);
  CMP->CMP_CFG2 |= (uint32_t)NegativeSelect;
	}
  if(CMPx == CMP3)
	{
	CMP3->CMP_CFG &= (uint32_t) ~(CMP_CFG_CMPNS);
  CMP3->CMP_CFG |= (uint32_t)NegativeSelect;
	}
}

/**
 * @brief  Get the CMP negative input channel
 * @param  CMPx[out]: 
 *               - CMP_0: select the CMP0 peripheral
 *               - CMP_1: select the CMP1 peripheral
 *               - CMP_2: select the CMP2 peripheral 
 *               - CMP3: select the CMP3 peripheral 
 * @retval  CMP_Negative_TypeDef[in]: CMP negative input channel type.
 *                  - CMP0_1_2NegativeSelect_CMPxN:Select CMPxN as the CMP0_1_2 Negative port   
 *                  - CMP0_1_2NegativeSelect_DAC:Select DAC as the CMP0_1_2 Negative port   
 *                  - CMP0_1_2NegativeSelect_BEMF_MID:Select BEMF_MID as the CMP0_1_2 Negative port   
 *                  - CMP3_NegativeSelect_CMPxN:Select CMPN as the CMP negative input port
 *                  - CMP3_NegativeSelect_DAC:Select DAC as the CMP negative input port  
 *                  - CMP3_NegativeSelect_CMPRF:Select CMPRF as the CMP negative input port     
 */
CMP_NegativeSelect_TypeDef CMP_GetNegativeSelection(CMP_TypeDef* CMPx)
{
	/* Check the parameters */
	CMP_NegativeSelect_TypeDef ReadCMPNegative;
  assert_param(IS_CMP_ALL_PERIPH(CMPx));
  if(CMPx== CMP_0)
	{
	/* Get the CMP0 positive input channel type */
	ReadCMPNegative =(CMP_NegativeSelect_TypeDef)(CMP->CMP_CFG & ( CMPX_CFG_CMPNS));
	}
  if(CMPx== CMP_1)
	{
	/* Get the CMP1 positive input channel type */
	ReadCMPNegative =(CMP_NegativeSelect_TypeDef)(CMP->CMP_CFG1 & ( CMPX_CFG_CMPNS));
	}
	if(CMPx== CMP_2)
	{
	/* Get the CMP2 positive input channel type */
	ReadCMPNegative =(CMP_NegativeSelect_TypeDef)(CMP->CMP_CFG2 & ( CMPX_CFG_CMPNS));
	}
	if(CMPx== CMP3)
	{
  /* Get the CMP2 positive input channel type */
	ReadCMPNegative =(CMP_NegativeSelect_TypeDef)(CMP3->CMP_CFG & ( CMP_CFG_CMPNS));
	}
	/* Get the CMP positive input channel type */
	return (CMP_NegativeSelect_TypeDef)ReadCMPNegative;
}
#endif
/** @defgroup CMP_Group2 Interrupts and flags management functions
 *  @brief   Interrupts and flags management functions
 *
@verbatim
 ===============================================================================
            ##### Interrupts and flags management functions #####
 ===============================================================================
@endverbatim
  * @{
  */
#if defined(SC32f15xx)
/**
 * @brief  Checks whether the specified CMP it is set or not.
 * @param  CMPx[out]: 
 *               - CMP_0: select the CMP0 peripheral
 *               - CMP_1: select the CMP1 peripheral
 *               - CMP_2: select the CMP2 peripheral 
 *               - CMP3: select the CMP3 peripheral 
 * @param  CMP_IT[in]: specifies the flag to check.
 *               - CMP0_1_2IT_INT:CMP0_1_2 Interrupt: CMP0_1_2 Interrupt 
 *               - CMP0_1_2IT_CMP0:CMP0 Interrupt: CMP0 Interrupt 
 *               - CMP0_1_2IT_CMP1:CMP1 Interrupt: CMP1  Interrupt 
 *               - CMP0_1_2IT_CMP2:CMP2 Interrupt: CMP2 Interrupt 
 *               - CMP3_IT_INT:CMP3 Interrupt: CMP3 Interrupt 
 * @param  NewState[in]: new state of the CMP trigger Interrupt.
 *         - ENABLE: Function enable   
 *         - DISABLE:Function disable
 * @retval None
 */
void CMP_ITConfig(CMP_TypeDef* CMPx, uint16_t CMP_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_CMP_ALL_PERIPH(CMPx));
  assert_param(IS_CMP_IT(CMP_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if(CMPx== CMP_0 || CMPx== CMP_2 || CMPx== CMP_2)
	{
		if(NewState != DISABLE)
    {
    /* Enable the Interrupt sources */
     CMP->CMP_IDE |= CMP_IT;
    }
    else
    {
    /* Disable the Interrupt sources */
     CMP->CMP_IDE &= (uint8_t)~CMP_IT;
    }
	}
	if(CMPx== CMP3)
	{
		if(NewState != DISABLE)
		{
			/* Enable the Interrupt sources */
			CMP->CMP_IDE |= CMP_IT;
		}
		else
		{
			/* Disable the Interrupt sources */
			CMP->CMP_IDE &= (uint16_t)~CMP_IT;
		}		
	}
}


#endif
/**
 * @brief  Return the cmp state (high or low) of the selected comparator.
 *                SC32f10xx Selection range(CMP)
 *                SC32f11xx Selection range(CMP)
 *                SC32f12xx Selection range(CMP)
 *                SC32f15xx Selection range(CMP_0 - CMP3) 
 *               - CMP: Only CMP can be select the CMPx peripheral.
 *               - CMP_0: select the CMP0 peripheral
 *               - CMP_1: select the CMP1 peripheral
 *               - CMP_2: select the CMP2 peripheral 
 *               - CMP3: select the CMP3 peripheral 
 * @retval The new state of CMP(CMP_CMPSTA_Low or CMP_CMPSTA_High).
 *               - CMP_CMPSTA_Low:The non-inverting input is at a lower voltage than the inverting input
 *               - CMP_CMPSTA_High: The non-inverting input is at a higher voltage than the inverting input
 *               - CMP_CMP0STA_Low: The non-inverting input is at a lower voltage than the inverting input 
 *               - CMP_CMP0STA_High: The non-inverting input is at a higher voltage than the inverting input 
 *               - CMP_CMP1STA_Low	: The non-inverting input is at a lower voltage than the inverting input 
 *               - CMP_CMP1STA_High: The non-inverting input is at a higher voltage than the inverting input 
 *               - CMP_CMP2STA_Low: The non-inverting input is at a lower voltage than the inverting input 
 *               - CMP_CMP2STA_High: The non-inverting input is at a higher voltage than the inverting input 
 *               - CMP_CMP3STA_Low: CMP3 positive terminal voltage is less than the negative terminal voltage 
 *               - CMP_CMP3STA_High:The positive terminal voltage of CMP3 is greater than the negative terminal voltage 
 */
CMP_CMPSTA_TypeDef CMP_GetCMPSTA ( CMP_TypeDef* CMPx )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    CMP_CMPSTA_TypeDef CMP_CMPSTA = CMP_CMPSTA_Low;
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );

    if ( ( CMPx->CMP_STS & CMP_STS_CMPSTA ) != 0 )
    {
        CMP_CMPSTA = CMP_CMPSTA_High;
    }
    else
    {
        CMP_CMPSTA = CMP_CMPSTA_Low;
    }

    return CMP_CMPSTA;
#elif defined(SC32f15xx)
  CMP_CMPSTA_TypeDef CMP_CMPSTA ;
  /* Check the parameters */
  assert_param(IS_CMP_ALL_PERIPH(CMPx));
	
		if(CMPx == CMP_0)
	{
		if((CMP->CMP_STS & CMP_STS_CMP0STA) != 0)
		{
			CMP_CMPSTA =CMP_CMP0STA_High;
		}
		else
		{
			CMP_CMPSTA = CMP_CMP0STA_Low;
		}
  }
	if(CMPx == CMP_1)
	{
		if((CMP->CMP_STS & CMP_STS_CMP1STA) != 0)
		{
			CMP_CMPSTA =CMP_CMP1STA_High;
		}
		else
		{
			CMP_CMPSTA = CMP_CMP1STA_Low;
		}
  }
	if(CMPx == CMP_2)
	{
		if((CMP->CMP_STS & CMP_STS_CMP2STA) != 0)
		{
			CMP_CMPSTA =CMP_CMP2STA_High;
		}
		else
		{
			CMP_CMPSTA = CMP_CMP2STA_Low;
		}
  }
	if(CMPx == CMP3)
	{
		if((CMP3->CMP_STS & CMP_STS_CMP3STA) != 0)
		{
			CMP_CMPSTA = CMP_CMP3STA_High;
		}
		else
		{
			CMP_CMPSTA = CMP_CMP3STA_Low;
		}
	}


  return CMP_CMPSTA;
#endif	
}

/**
 * @brief  Checks whether the specified CMP flag is set or not.
 * @param  CMPx[out]: 
 *                SC32f10xx Selection range(CMP)
 *                SC32f11xx Selection range(CMP)
 *                SC32f12xx Selection range(CMP)
 *                SC32f15xx Selection range(CMP_0 - CMP3) 
 *               - CMP: Only CMP can be select the CMPx peripheral.
 *               - CMP_0: select the CMP0 peripheral
 *               - CMP_1: select the CMP1 peripheral
 *               - CMP_2: select the CMP2 peripheral 
 *               - CMP3: select the CMP3 peripheral 
 * @param  CMP_FLAG[in]:specifies the flag to check.
 *                SC32f10xx Selection range(CMP_FLAG_IF)
 *                SC32f11xx Selection range(CMP_FLAG_IF)
 *                SC32f12xx Selection range(CMP_FLAG_IF)
 *                SC32f15xx Selection range(CMP_FLAG_CMP0 - CMP_FLAG_CMP3) 
 *               - CMP_FLAG_IF: Interrupt flag
 *               - CMP_FLAG_CMP0: CMP0 flag 
 *               - CMP_FLAG_CMP1: CMP1 flag 
 *               - CMP_FLAG_CMP2: CMP2 flag 
 *               - CMP_FLAG_CMP3: Interrupt flag 
 * @retval The new state of CMP_FLAG (SET or RESET).
 *                  -  RESET:Flag reset
 *                  -  SET :Flag up.
 */
FlagStatus CMP_GetFlagStatus ( CMP_TypeDef* CMPx, CMP_FLAG_TypeDef CMP_FLAG )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    ITStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );
    assert_param ( IS_CMP_FLAG ( CMP_FLAG ) );

    if ( ( CMPx->CMP_STS & CMP_FLAG ) != ( uint16_t ) RESET )
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
    assert_param(IS_CMP_ALL_PERIPH(CMPx));
    assert_param(IS_CMP_FLAG(CMP_FLAG));
	if(CMPx == CMP_0 || CMPx == CMP_1 || CMPx == CMP_2)  
	{
    if((CMP->CMP_STS & CMP_FLAG) != (uint16_t)RESET)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
	}
	if(CMPx == CMP3)
	{
    if((CMP3->CMP_STS & CMP_FLAG) != (uint16_t)RESET)
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
 * @brief  Clears the CMPx's pending flags.
 * @param  CMPx[out]: 
 *                SC32f10xx Selection range(CMP)
 *                SC32f11xx Selection range(CMP)
 *                SC32f12xx Selection range(CMP)
 *                SC32f15xx Selection range(CMP_0 - CMP3) 
 *               - CMP: Only CMP can be select the CMPx peripheral.
 *               - CMP_0: select the CMP0 peripheral
 *               - CMP_1: select the CMP1 peripheral
 *               - CMP_2: select the CMP2 peripheral 
 *               - CMP3: select the CMP3 peripheral 
 * @param  CMP_FLAG[in]: specifies the flag bit to clear.
 *                  -  CMP_FLAG_IF:CMP Flag: Interrupt flag
 *               - CMP_FLAG_CMP0: CMP0 flag 
 *               - CMP_FLAG_CMP1: CMP1 flag 
 *               - CMP_FLAG_CMP2: CMP2 flag 
 *               - CMP_FLAG_CMP3: Interrupt flag 
 * @retval None
 */
void CMP_ClearFlag ( CMP_TypeDef* CMPx, CMP_FLAG_TypeDef CMP_FLAG )
{
#if defined(SC32f10xx)||defined(SC32f11xx)||defined(SC32f12xx)
    /* Check the parameters */
    assert_param ( IS_CMP_ALL_PERIPH ( CMPx ) );

    /* Clear the flags */
    CMPx->CMP_STS = ( uint16_t ) CMP_FLAG;
#elif defined(SC32f15xx)
  /* Check the parameters */
  assert_param(IS_CMP_ALL_PERIPH(CMPx));
	if(CMPx == CMP_0 || CMPx == CMP_1 || CMPx == CMP_2)
	{
    /* Clear the flags */
    CMP->CMP_STS = (uint16_t)CMP_FLAG;		
	}
	if(CMPx == CMP3)
	{
    /* Clear the flags */
    CMP3->CMP_STS = (uint16_t)CMP_FLAG;
	}
#endif	
}

/**
 * @}
 */
/* End of CMP_Group2.	*/

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

