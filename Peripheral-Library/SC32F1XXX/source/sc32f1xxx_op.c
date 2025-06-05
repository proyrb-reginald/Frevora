/*
 ******************************************************************************
 * @file    SC32f1xxx_OP.c
 * @author  SOC AE Team
 * @version V1.7
 * @date     17-10-2024
 * @brief OP function module
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
#if defined (SC32f12xx) || defined (SC32f15xx)
#include "sc32f1xxx_op.h"
/** @defgroup OP_Exported_Functions_Group1 Configuration of the OP computation unit functions
 *  @brief   Configuration of the OP computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### OP configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitialize the OP peripheral registers to their default reset values.
 * @param  OPx[out]:  can be select the OPx peripheral.
 *                SC32f12xx Selection range(OP)
 *                SC32f15xx Selection range(OP0 - OP2) 
 *               - OP: OP can be select the OPx peripheral.
 *               - OP0: select the OP0 peripheral
 *               - OP1: select the OP1 peripheral
 *               - OP2: select the OP2 peripheral
 * @retval None
 */
void OP_DeInit ( OP_TypeDef* OPx )
{
#if defined (SC32f12xx)
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_OP_ALL_PERIPH ( OPx ) );

    if ( OPx == OP )
    {
        /* Get the OPx OP_CON value */
        tmpreg = OPx->OP_CON;

        /* Set OPFS bit to OP_FreqSelect value */
        tmpreg &= 0x00000000;

        /* Write to OPx OP_CON */
        OPx->OP_CON = ( uint32_t ) tmpreg;
    }
#elif defined (SC32f15xx)
			/* Check the parameters */
		assert_param(IS_OP_ALL_PERIPH(OPx)); 

		if (OPx==OP_0)
		{
		 OP->OP0_CON = (uint32_t)0x00;
		}       
		else if (OPx==OP_1)
		{
		 OP->OP1_CON = (uint32_t)0x00;
		}
		else if (OPx==OP_2)
		{
		 OP->OP2_CON = (uint32_t)0x00;
		}

			OP->OPX_CFG = (uint32_t)0x00;
			OP->OPX_IDE = (uint32_t)0x00;
			OP->OPX_STS = (uint32_t)0x06;
#endif
}


/**
 * @brief  DeInitializes the OP peripheral
 * @param  OPx[out]:  can be select the OPx peripheral.
 *                SC32f12xx Selection range(OP)
 *                SC32f15xx Selection range(OP0 - OP2) 
 *               - OP: OP can be select the OPx peripheral.
 *               - OP_0: select the OP0 peripheral
 *               - OP_1: select the OP1 peripheral
 *               - OP_2: select the OP2 peripheral
 * @param  OP_InitStruct[out]:Pointer to structure OP_InitTypeDef, to be initialized.
 * @retval None
 */
void OP_Init ( OP_TypeDef* OPx, OP_InitTypeDef* OP_InitStruct )
{
#if defined (SC32f12xx)
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_OP_ALL_PERIPH ( OPx ) );
    assert_param ( IS_OP_Output ( Output ) );
    assert_param ( IS_OP_Negative ( Negative ) );
    assert_param ( IS_OP_Posittive ( Posittive ) );
    assert_param ( IS_OP_PGAGain ( PGAGain ) );
    assert_param ( IS_OP_FDBResisrance ( FDBResisrance ) );
    assert_param ( IS_OP_ShortCircuit ( ShortCircuit ) );

    /*---------------------------- OPx OP_CON Configuration ------------------------*/
    /* Get the OPx OP_CON value */
    tmpreg = OPx->OP_CON;

    /* Clear OPFS bits */
    tmpreg &= ( uint32_t ) ~ ( OP_CON_OPOSEL | OP_CON_OPNSEL | OP_CON_OPPSEL
                               | OP_CON_PGAGAN | OP_CON_FDBRSEL | OP_CON_PGAOFC );
    /* Set OPFS bit to OP_FreqSelect value */
    tmpreg |= ( uint32_t ) ( OP_InitStruct->OP_FDBResisrance | OP_InitStruct->OP_Negative | OP_InitStruct->OP_Output |
                             OP_InitStruct->OP_PGAGain | OP_InitStruct->OP_Posittive | OP_InitStruct->OP_ShortCircuit );

    /* Write to OPx OP_CON */
    OPx->OP_CON = tmpreg;
#elif defined (SC32f15xx)
    uint32_t tmpreg;
   
    /* Check the parameters */
    assert_param(IS_OP_ALL_PERIPH(OPx));;
    assert_param(IS_OP_INVERTINPUT(OP_InitStruct->OP_NonInvertInput));
    assert_param(IS_OP_GAN(OP_InitStruct->OP_GAN));

    /*---------------------------- OPx_CON Configuration ------------------------*/
    /* Get the OPx OP_CON value */
    if(OPx==OP_0)  tmpreg =  OP->OP0_CON ;
	  else if(OPx==OP_1)  tmpreg =  OP->OP1_CON ;
    else if(OPx==OP_2)  tmpreg =  OP->OP2_CON ;
    
    tmpreg &= (uint32_t)~(OP_CON_OPOSEL | OP_CON_OPNSEL | OP_CON_OPPSEL |
                          OP_CON_PGAGAN | OP_CON_OPRF | OP_CON_FDBRSEL);

    tmpreg |= (uint32_t)(OP_InitStruct->OP_OutputPin | OP_InitStruct->OP_InvertInput |
                         OP_InitStruct->OP_NonInvertInput | OP_InitStruct->OP_PGAGain |
                         OP_InitStruct->OP_OPRF | OP_InitStruct->OP_FDBR);
			
	  if(OPx==OP_0)
		{
      if(OP_InitStruct->OP_InvertInput == OP_InvertInput_Res )
		  {
				    GPIOB->PXCON &= (uint32_t)(~0x0002);
	        	GPIOB->PXPH &= (uint32_t)(~0x0002);	
		  }
			 OP->OP0_CON = tmpreg ;

		}
	  else if(OPx==OP_1)
		{
			if(OP_InitStruct->OP_InvertInput == OP_InvertInput_Res )
		  {
				    GPIOB->PXCON &= (uint32_t)(~0x0010);
	        	GPIOB->PXPH &= (uint32_t)(~0x0010);	
		  }
			 OP->OP1_CON = tmpreg;
			 OP->OPX_CFG &= (uint32_t)~OP_CFG_OPCMPIM1;
       OP->OPX_CFG |= (OP_InitStruct->OP_CMPIM1 << OP_CFG_OPCMPIM1_Pos)|(OP_InitStruct->OP_REFSEL << OP_CFG_REFSEL_Pos);
		
		}
    else if(OPx==OP_2)
		{
			if(OP_InitStruct->OP_InvertInput == OP_InvertInput_Res )
		  {
				    GPIOB->PXCON &= (uint32_t)(~0x0800);
	        	GPIOB->PXPH &= (uint32_t)(~0x0800);	
		  }
			 OP->OP2_CON = tmpreg;
			 OP->OPX_CFG &= (uint32_t)~OP_CFG_OPCMPIM2;
       OP->OPX_CFG |= (OP_InitStruct->OP_CMPIM2 << OP_CFG_OPCMPIM2_Pos)|(OP_InitStruct->OP_REFSEL << OP_CFG_REFSEL_Pos);
		}
#endif
}
#if defined (SC32f15xx)
/**
  * @brief  Fills each OP_StruetInit member with its default value.
  * @param  OP_InitStruet[out]: pointer to an OP_InitTypeDef structure that contains
  *         the configuration information for the specified OP peripheral.
  * @retval None
  */
void OP_StructInit(OP_InitTypeDef* OP_InitStruet)
{
	/* Set the default configuratiom */
  OP_InitStruet->OP_REFSEL=OP_RefSource_VDD;
  OP_InitStruet->OP_CMPIM2=OP_TriggerMode_Disable;
  OP_InitStruet->OP_CMPIM1 = OP_TriggerMode_Disable;
  OP_InitStruet->OP_OutputPin = OP_OutputPin_Disable;
  OP_InitStruet->OP_InvertInput =OP_InvertInput_OPxN;
  OP_InitStruet->OP_NonInvertInput =OP_NonInvertInput_VSS;
  OP_InitStruet->OP_PGAGain=OP_PGAGain_NonInvert4_Invert3;
  OP_InitStruet->OP_OPRF =OP_OPRF_1D16OP_VREF;
  OP_InitStruet->OP_FDBR =OP_FDBR_VSS;
}
#endif
/**
 * @brief  Enables or disables the specified OP peripheral.
 * @param  OPx[out]:  can be select the OPx peripheral.
 *                SC32f12xx Selection range(OP)
 *                SC32f15xx Selection range(OP0 - OP2) 
 *               - OP: OP can be select the OPx peripheral.
 *               - OP_0: select the OP0 peripheral
 *               - OP_1: select the OP1 peripheral
 *               - OP_2: select the OP2 peripheral
 * @param  NewState[in]: new state of the OPx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void OP_Cmd ( OP_TypeDef* OPx, FunctionalState NewState )
{
#if defined (SC32f12xx)
    /* Check the parameters */
    assert_param ( IS_OP_ALL_PERIPH ( OPx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the OP Function */
        OPx->OP_CON |= OP_CON_ENOP;
    }
    else
    {
        /* Disable the OP Function */
        OPx->OP_CON &= ( uint16_t ) ~OP_CON_ENOP;
    }
#elif defined (SC32f15xx)
    /* Check the parameters */
    assert_param(IS_OP_ALL_PERIPH(OPx)); 
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if(NewState != DISABLE)
    {
			/* Enable the OP Function */
			if(OPx==OP_0)
			{
				 OP->OP0_CON |= (uint32_t)OP_CON_ENOP;
			}
			else if(OPx==OP_1)
			{
				 OP->OP1_CON |= (uint32_t)OP_CON_ENOP;
			}
			else if(OPx==OP_2)
			{
				 OP->OP2_CON |= (uint32_t)OP_CON_ENOP;
			}
        
    }
    else
    {
        /* Disable the OP Function */
			if(OPx==OP_0)
			{
				 OP->OP0_CON &= (uint32_t)~OP_CON_ENOP;
			}
			else if(OPx==OP_1)
			{
				 OP->OP1_CON &= (uint32_t)~OP_CON_ENOP;
			}
			else if(OPx==OP_2)
			{
				 OP->OP2_CON &= (uint32_t)~OP_CON_ENOP;
			}
    }
#endif
}

/**
  * @brief  Configure the trimming value of the OPAMP.
 * @param  OPx[out]:  can be select the OPx peripheral.
 *                SC32f12xx Selection range(OP)
 *                SC32f15xx Selection range(OP0 - OP2) 
 *               - OP: OP can be select the OPx peripheral.
 *               - OP_0: select the OP0 peripheral
 *               - OP_1: select the OP1 peripheral
 *               - OP_2: select the OP2 peripheral
  * @param  OP_TrimValueH[in]: the trimming value(high).
  * @param  OP_TrimValueL[in]: the trimming value(low).
  * @retval None
  */
void OP_OffsetTrimConfig ( OP_TypeDef* OPx,  uint32_t OP_TrimValueH, uint32_t OP_TrimValueL )
{
#if defined (SC32f12xx)
    uint32_t tmpreg = 0;

    /* Check the parameters */
    assert_param ( IS_OP_ALL_PERIPH ( OPx ) );


    /*!< Get the OPAMPx_CSR register value */
    tmpreg = OPx->OP_CON;

    /*!< Clear the trimming bits */
    tmpreg &= ( uint32_t ) ~ ( ( OP_CON_TRIMOFFSETNL | OP_CON_TRIMOFFSETNH ) );

    /*!< Configure the new trimming value */
    tmpreg |= ( uint32_t ) ( ( OP_TrimValueL << OP_CON_TRIMOFFSETNL_Pos ) | ( OP_TrimValueH << OP_CON_TRIMOFFSETNH_Pos ) );

    /*!< Write to OPAMPx_CSR register */
    OPx->OP_CON = tmpreg;
#elif defined (SC32f15xx)
  uint32_t tmpreg = 0;

  /* Check the parameters */
  assert_param(IS_OP_ALL_PERIPH(OPx)); 
	if(OPx==OP_0)
	{
  tmpreg = OP->OP0_CON;

  /*!< Clear the trimming bits */
  tmpreg &= (uint32_t)~((OP_CON_TRIMOFFSETP | OP_CON_TRIMOFFSETN));

  /*!< Configure the new trimming value */
  tmpreg |= (uint32_t)((OP_TrimValueL<<OP_CON_TRIMOFFSETP_Pos)|(OP_TrimValueH<<OP_CON_TRIMOFFSETN_Pos));

  /*!< Write to OPAMPx_CSR register */
  OP->OP0_CON = tmpreg;
	}
	else if(OPx==OP_1)
	{
  tmpreg = OP->OP1_CON;

  /*!< Clear the trimming bits */
  tmpreg &= (uint32_t)~((OP_CON_TRIMOFFSETP | OP_CON_TRIMOFFSETN));

  /*!< Configure the new trimming value */
  tmpreg |= (uint32_t)((OP_TrimValueL<<OP_CON_TRIMOFFSETP_Pos)|(OP_TrimValueH<<OP_CON_TRIMOFFSETN_Pos));

  /*!< Write to OPAMPx_CSR register */
  OP->OP1_CON = tmpreg;
	}
	else if(OPx==OP_2)
	{
  tmpreg = OP->OP2_CON;

  /*!< Clear the trimming bits */
  tmpreg &= (uint32_t)~((OP_CON_TRIMOFFSETP | OP_CON_TRIMOFFSETN));

  /*!< Configure the new trimming value */
  tmpreg |= (uint32_t)((OP_TrimValueL<<OP_CON_TRIMOFFSETP_Pos)|(OP_TrimValueH<<OP_CON_TRIMOFFSETN_Pos));

  /*!< Write to OPAMPx_CSR register */
  OP->OP2_CON = tmpreg;
	}

  /*!< Get the OPAMPx_CSR register value */
#endif
}

/**
  * @brief  OP gain selection.
 * @param  OPx[out]:  can be select the OPx peripheral.
 *                SC32f12xx Selection range(OP)
 *                SC32f15xx Selection range(OP0 - OP2) 
 *               - OP: OP can be select the OPx peripheral.
 *               - OP_0: select the OP0 peripheral
 *               - OP_1: select the OP1 peripheral
 *               - OP_2: select the OP2 peripheral
  * @param  OPGain[in]: Gain multiple.
 *                SC32f12xx Selection range(OP_PGAGain_NonInvert8_Invert7,OP_PGAGain_NonInvert16_Invert15,OP_PGAGain_NonInvert32_Invert31,OP_PGAGain_NonInvert64_Invert63)
 *                SC32f15xx Selection range(OP_PGAGain_NonInvert4_Invert3,OP_PGAGain_NonInvert8_Invert7,OP_PGAGain_NonInvert16_Invert15,OP_PGAGain_NonInvert32_Invert31) 
  *                  - OP_PGAGain_NonInvert4_Invert3:The OP inverting input gain is 4/3 times
  *                  - OP_PGAGain_NonInvert8_Invert7:The OP inverting input gain is 8/7 times
  *                  - OP_PGAGain_NonInvert16_Invert15:The OP inverting input gain is 16/15 times
  *                  - OP_PGAGain_NonInvert32_Invert31:The OP in-phase input gain is 32/31 times
  *                  - OP_PGAGain_NonInvert64_Invert63:The OP in-phase input gain is 64/63 times
  * @retval None
  */
void OP_GainSelection ( OP_TypeDef* OPx, OP_PGAGain_TypeDef PGAGain )
{
#if defined (SC32f12xx)
    /* Check the parameters */
    assert_param ( IS_OP_ALL_PERIPH ( OPx ) );
    assert_param ( IS_OP_PGAGain ( PGAGAN ) );


    OPx->OP_CON &= ~ ( OP_CON_PGAGAN );
    OPx->OP_CON |= PGAGain;
#elif defined (SC32f15xx)
  /* Check the parameters */
  assert_param(IS_OP_ALL_PERIPH(OPx)); 
  assert_param( IS_OP_GAN(PGAGain) );

  if(OPx==OP_0)
	{
			OP->OP0_CON &= ~OP_CON_PGAGAN;
			OP->OP0_CON = PGAGain;
	}
	else if(OPx==OP_1)
	{
			OP->OP1_CON &= ~OP_CON_PGAGAN;
			OP->OP1_CON =  PGAGain;
	}
	else if(OPx==OP_2)
	{
			OP->OP2_CON &= ~OP_CON_PGAGAN;
			OP->OP2_CON = ~PGAGain;
	}
#endif

}

/**
 * @}
 */
/**
  * @brief  OP Output port selection.
 * @param  OPx[out]:  can be select the OPx peripheral.
 *                SC32f12xx Selection range(OP)
 *                SC32f15xx Selection range(OP0 - OP2) 
 *               - OP: OP can be select the OPx peripheral.
 *               - OP_0: select the OP0 peripheral
 *               - OP_1: select the OP1 peripheral
 *               - OP_2: select the OP2 peripheral
  * @param  OPOutput[in]: Output port selection.
  *                  - OP_Output_OFF:The OP Output  OFF
  *                  - OP_Output_ON:The OP Output  ON
  * @retval None
  */
void OP_OutputSelection ( OP_TypeDef* OPx, OP_Output_TypeDef OPOutput )
{
#if defined (SC32f12xx)
    /* Check the parameters */
    assert_param ( IS_OP_ALL_PERIPH ( OPx ) );
    assert_param ( IS_OP_Output ( OPOutput ) );


    OPx->OP_CON &= ~ ( OP_CON_OPOSEL );
    OPx->OP_CON |= OPOutput;
#elif defined (SC32f15xx)
  /* Check the parameters */
  assert_param(IS_OP_ALL_PERIPH(OPx));
  assert_param( IS_OP_OUTPUTPIN(OPOutput) );

  if(OPx==OP_0)
	{
		OP->OP0_CON &= ~OP_CON_OPOSEL;
		OP->OP0_CON = OPOutput;
	}
	else if(OPx==OP_1)
	{
		OP->OP1_CON &= ~OP_CON_OPOSEL;
		OP->OP1_CON =  OPOutput;
	}
	else if(OPx==OP_2)
	{
		OP->OP2_CON &= ~OP_CON_OPOSEL;
		OP->OP2_CON = ~OPOutput;
	}
#endif
}
#if defined(SC32f15xx)
/**
  * @brief  OP Non Invert Input port selection.
 * @param  OPx[out]:  can be select the OPx peripheral.
 *               - OP_0: select the OP0 peripheral
 *               - OP_1: select the OP1 peripheral
 *               - OP_2: select the OP2 peripheral
 * @param  OPNonInvertInput[in]: No invert input port selection.  
 *               - OP_NonInvertInput_VSS:The no Invert input is VSS
 *               - OP_NonInvertInput_VREF_Div2:no Invert input is VREF_Div2 
 *               - OP_NonInvertInput_OPxP:no Invert input is OPxP 
  * @retval None
  */
void OP_NonInvertInputSelection(OP_TypeDef* OPx, OP_NonInvertInput_TypeDef OPNonInvertInput)
{
  /* Check the parameters */
  assert_param(IS_OP_ALL_PERIPH(OPx)); 
  assert_param(IS_OP_NonInvertInput(OPNonInvertInput));

  if(OPx==OP_0)
	{
		OP->OP0_CON &= ~OP_CON_OPPSEL;
		OP->OP0_CON = OPNonInvertInput;
	}
	else if(OPx==OP_1)
	{
		OP->OP1_CON &= ~OP_CON_OPPSEL;
		OP->OP1_CON =  OPNonInvertInput;
	}
	else if(OPx==OP_2)
	{
	  OP->OP2_CON &= ~OP_CON_OPPSEL;
		OP->OP2_CON = ~OPNonInvertInput;
	}  

}
/**
  * @brief  OP InverInput port selection.
 * @param  OPx[out]:  can be select the OPx peripheral.
 *               - OP_0: select the OP0 peripheral
 *               - OP_1: select the OP1 peripheral
 *               - OP_2: select the OP2 peripheral
 * @param  OPNonInvertInput[in]: No invert input port selection.  
 *               - OP_OPRF_1D16OP_VREF:Opamp inverter input voltage select 1D16OP_VREF
 *               - OP_OPRF_2D16OP_VREF:Opamp inverter input voltage select 2D16OP_VREF 
 *               - OP_OPRF_3D16OP_VREF:Opamp inverter input voltage select 3D16OP_VREF   
 *               - OP_OPRF_4D16OP_VREF:Opamp inverter input voltage select 4D16OP_VREF   
 *               - OP_OPRF_5D16OP_VREF:Opamp inverter input voltage select 5D16OP_VREF  
 *               - OP_OPRF_6D16OP_VREF:Opamp inverter input voltage select 6D16OP_VREF   
 *               - OP_OPRF_7D16OP_VREF:Opamp inverter input voltage select 7D16OP_VREF  
 *               - OP_OPRF_8D16OP_VREF:Opamp inverter input voltage select 8D16OP_VREF   
 *               - OP_OPRF_9D16OP_VREF:Opamp inverter input voltage select 9D16OP_VREF   
 *               - OP_OPRF_10D16OP_VREF:Opamp inverter input voltage select 10D16OP_VREF    
 *               - OP_OPRF_11D16OP_VREF:Opamp inverter input voltage select 11D16OP_VREF   
 *               - OP_OPRF_12D16OP_VREF:Opamp inverter input voltage select 12D16OP_VREF   
 *               - OP_OPRF_13D16OP_VREF:Opamp inverter input voltage select 13D16OP_VREF    
 *               - OP_OPRF_14D16OP_VREF:Opamp inverter input voltage select 14D16OP_VREF  
 *               - OP_OPRF_15D16OP_VREF:Opamp inverter input voltage select 15D16OP_VREF 
  * @retval None
  */
void OP_InverInputVoltage(OP_TypeDef* OPx, OP_OPRF_TypeDef OP_OPRF)
{
  /* Check the parameters */
  assert_param(IS_OP_ALL_PERIPH(OPx));  
  assert_param(IS_OP_FAILINGCAP(OP_OPRF));

   if(OPx==OP_0)
	{
		OP->OP0_CON &= ~OP_CON_OPRF;
		OP->OP0_CON = OP_OPRF;
	}
	else if(OPx==OP_1)
	{
		OP->OP1_CON &= ~OP_CON_OPRF;
		OP->OP1_CON =  OP_OPRF;
	}
	else if(OPx==OP_2)
	{
		OP->OP2_CON &= ~OP_CON_OPRF;
		OP->OP2_CON = ~OP_OPRF;
	}  

}

/**
 * @brief  Configure the trimming value of the OPAMP.
 * @param  OPx[out]:  can be select the OPx peripheral.
 *               - OP_0: select the OP0 peripheral
 *               - OP_1: select the OP1 peripheral
 *               - OP_2: select the OP2 peripheral
 * @param  OPInvertInput[in]: select OP invert input . 
 *               - OP_InvertInput_OPxN:The Invert input is OPxN 
 *               - OP_InvertInput_DAC:The Invert input is DAC 
 *               - OP_InvertInput_OPRF:The Invert input is OPRF 
 *               - OP_InvertInput_Res:The Invert input is Res 
 * @retval None
 */
void OP_InputSelection(OP_TypeDef* OPx,OP_InvertInput_TypeDef OPInvertInput)
{

  /* Check the parameters */
    assert_param(IS_OP_ALL_PERIPH(OPx)); 
		if(OPx==OP_0)
		{
			if(OPInvertInput==OP_InvertInput_OPxN ||OPInvertInput==OP_InvertInput_Res )
			{
				if(OPInvertInput==OP_InvertInput_Res )
				{
						GPIOB->PXCON &= (uint32_t)(~0x0002);
						GPIOB->PXPH &= (uint32_t)(~0x0002);	
				}				
				OP->OP0_CON &= ~OP_CON_OPNSEL;
				OP->OP0_CON = OPInvertInput;
			}
		}
		else if(OPx==OP_1)
		{
		    if(OPInvertInput==OP_InvertInput_Res )
				{
				    GPIOB->PXCON &= (uint32_t)(~0x0010);
	        	GPIOB->PXPH &= (uint32_t)(~0x0010);	
				}	
				OP->OP1_CON &= ~OP_CON_OPNSEL;
				OP->OP1_CON =  OPInvertInput;
		}
		else if(OPx==OP_2)
		{
				if(OPInvertInput==OP_InvertInput_Res )
				{
					  GPIOB->PXCON &= (uint32_t)(~0x0800);
	        	GPIOB->PXPH &= (uint32_t)(~0x0800);	
				}	
				OP->OP2_CON &= ~OP_CON_OPNSEL;
				OP->OP2_CON = ~OPInvertInput;
		}
 
}
/**
  * @brief  Configure the ReferenceVref of the OPAMP.
 * @param  OPx[out]:  can be select the OPx peripheral.
 *               - OP_1: select the OP1 peripheral
 *               - OP_2: select the OP2 peripheral
 * @param  OPVREF[in]:Select the ReferenceVref of the OPAMP. 
 *               - OP_RefSource_VDD:OP reference voltage is VDD  
 *               - OP_RefSource_VREF:OP reference voltage is Vref
  * @retval None
  */
void OP_ReferenceVref(OP_TypeDef* OPx,OP_VREF_TypeDef OPVREF)
{

  /* Check the parameters */
  assert_param(IS_OP_ALL_PERIPH(OPx)); 
   if(OPx==OP_1)
		{
			OP->OP1_CON &= ~OP_CFG_REFSEL;
			OP->OP1_CON =  OPVREF;
		}
		else if(OPx==OP_2)
		{
			OP->OP2_CON &= ~OP_CFG_REFSEL;
			OP->OP2_CON = ~OPVREF;
		}

 
}
/**
 * @}
 */
/* End of OP_Group1.	*/

/** @defgroup OP_Group2 Interrupts and flags management functions
 *  @brief   Interrupts and flags management functions
 *
@verbatim
 ===============================================================================
            ##### Interrupts and flags management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
  * @brief  Enable the CMP Trigger of selected OPAMP peripheral.
 * @param  OPx[out]:  can be select the OPx peripheral.
 *               - OP_1: select the OP1 peripheral
 *               - OP_2: select the OP2 peripheral
  * @param  NewState[in]: new state of the OPAMP peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable  
  * @retval None
  */
void OP_CMPTriggerCmd(OP_TypeDef* OPx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_OP_ALL_PERIPH(OPx)); 
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if(NewState != DISABLE)
    {
		   /* Enable the OP Function */
			  if(OPx==OP_1)
				{
					OP->OP1_CON |= (uint32_t)OP_CON_MODE;
				}
				else if(OPx==OP_2)
				{
					 OP->OP2_CON |= (uint32_t)OP_CON_MODE;
				}


    }
    else
    {
        /* Disable the OP Function */
				if(OPx==OP_1)
				{
					OP->OP1_CON &= (uint32_t)~OP_CON_MODE;
				}
				else if(OPx==OP_2)
				{
					 OP->OP2_CON &= (uint32_t)~OP_CON_MODE;
				}
    }
}

/**
  * @brief   Configure the Trigger Mode of the OPx.
 * @param  OPx[out]:  can be select the OPx peripheral.
 *               - OP_1: select the OP1 peripheral
 *               - OP_2: select the OP2 peripheral
  * @param  TriggerMode: new state of the OPAMP peripheral.
 *               -OP_TriggerMode_Disable:the trigger mode is disable
 *               -OP_TriggerMode_RISE:The trigger mode of the simulated comparator is rising edge
 *               -OP_TriggerMode_FALL:The trigger mode of simulated comparator is falling edge   
 *               -OP_TriggerMode_RISE_FALL:The trigger mode of the simulated comparator is rising edge and falling edge 
  * @retval None
  */
void OP_CMPTriggerConfig(OP_TypeDef* OPx, OP_TriggerMode_TypeDef TriggerMode)
{
    /* Check the parameters */
    assert_param(IS_OP_ALL_PERIPH(OPx)); 
    assert_param(IS_OP_TRIGGER(TriggerMode));

    /* Enable the OP Function */
		if(OPx==OP_1)
		{
				OP->OPX_CFG &= (uint32_t)~OP_CFG_OPCMPIM1;
				OP->OPX_CFG |= (TriggerMode << OP_CFG_OPCMPIM1_Pos);
		}
		else if(OPx==OP_2)
		{
				OP->OPX_CFG &= (uint32_t)~OP_CFG_OPCMPIM2;
				OP->OPX_CFG |= (TriggerMode << OP_CFG_OPCMPIM2_Pos);
		}

}

/**
 * @}
 */
/* End of OP_Group2.	*/
/** @defgroup OP_Group3 Read check data functions
 *  @brief   Read check data functions
 *
@verbatim
 ===============================================================================
            ##### Read check data #####
 ===============================================================================
@endverbatim
  * @{
  */
/**
 * @brief  Return the OP0P check data.
 * @param  OPX_Readmos[in]:  can be select the OPxN/P to read offset.
 *                         - OP0_Pmos:select the OP0P  
 *                         - OP0_Nmos:select the OP0N  
 *                         - OP1_Pmos:select the OP1P
 *                         - OP1_Nmos:select the OP1N 
 *                         - OP2_Pmos:select the OP2P 
 *                         - OP2_Nmos:select the OP2N   
 * @retval the OPXP/N check data.
 */
uint8_t OP_ReadOffset(OP_PNMos_TypeDef OPx_Readmos)
{
	uint8_t OPx_Readoffset;
	if(OPx_Readmos == OP0_Pmos)
	{
		OPx_Readoffset =  *((uint8_t *)0X08C00000+0x491);
	}
	else if(OPx_Readmos == OP0_Nmos)
	{
		OPx_Readoffset = *((uint8_t *)0X08C00000+0x493);
	}
	else if(OPx_Readmos == OP1_Pmos)
	{
		OPx_Readoffset = *((uint8_t *)0X08C00000+0x495);
	}
	else if(OPx_Readmos == OP1_Nmos)
	{
		OPx_Readoffset = *((uint8_t *)0X08C00000+0x497);
	}
	else if(OPx_Readmos == OP2_Pmos)
	{
		OPx_Readoffset = *((uint8_t *)0X08C00000+0x499);
	}
  else if(OPx_Readmos == OP2_Nmos)
	{
		OPx_Readoffset = *((uint8_t *)0X08C00000+0x49B);
	}

	return OPx_Readoffset;
}
/**
 * @brief  Return the OP2N check data.
 * @param  None
 * @retval the OP2N check data.
 */
void OP_OffsetZero(OP_TypeDef* OPx)
{
    uint8_t OP_Pmos_offset, OP_Nmos_offset;
    uint32_t tmpreg ;

    if(OPx == OP_0)
    {
        OP_Pmos_offset = *((uint8_t*)0X08C00000 + 0x491);
        OP_Nmos_offset = *((uint8_t*)0X08C00000 + 0x493);

        tmpreg = OP->OP0_CON;

        /*!< Clear the trimming bits */
        tmpreg &= (uint32_t)~((OP_CON_TRIMOFFSETP | OP_CON_TRIMOFFSETN));

        /*!< Configure the new trimming value */
        tmpreg |= (uint32_t)((OP_Nmos_offset << OP_CON_TRIMOFFSETP_Pos) | (OP_Pmos_offset << OP_CON_TRIMOFFSETN_Pos));

        /*!< Write to OPAMPx_CSR register */
        OP->OP0_CON = tmpreg;
    }
    else if(OPx == OP_1)
    {
        OP_Pmos_offset = *((uint8_t*)0X08C00000 + 0x495);
        OP_Nmos_offset = *((uint8_t*)0X08C00000 + 0x497);

        tmpreg = OP->OP1_CON;

        /*!< Clear the trimming bits */
        tmpreg &= (uint32_t)~((OP_CON_TRIMOFFSETP | OP_CON_TRIMOFFSETN));

        /*!< Configure the new trimming value */
        tmpreg |= (uint32_t)((OP_Nmos_offset << OP_CON_TRIMOFFSETP_Pos) | (OP_Pmos_offset << OP_CON_TRIMOFFSETN_Pos));

        /*!< Write to OPAMPx_CSR register */
        OP->OP1_CON = tmpreg;
    }
    else if(OPx == OP_2)
    {
        OP_Pmos_offset = *((uint8_t*)0X08C00000 + 0x499);
        OP_Nmos_offset = *((uint8_t*)0X08C00000 + 0x49B);

        tmpreg = OP->OP2_CON;

        /*!< Clear the trimming bits */
        tmpreg &= (uint32_t)~((OP_CON_TRIMOFFSETP | OP_CON_TRIMOFFSETN));

        /*!< Configure the new trimming value */
        tmpreg |= (uint32_t)((OP_Nmos_offset << OP_CON_TRIMOFFSETP_Pos) | (OP_Pmos_offset << OP_CON_TRIMOFFSETN_Pos));

        /*!< Write to OPAMPx_CSR register */
        OP->OP2_CON = tmpreg;
    }
}

/**
 * @}
 */
/* End of OP_Group3.	*/
/** @defgroup OP_Group4 Interrupts and flags management functions
 *  @brief   Interrupts and flags management functions
 *
@verbatim
 ===============================================================================
            ##### Interrupts and flags management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  Return the cmp state (high or low) of the selected comparator.
 * @param  OPx[out]:  can be select the OPx peripheral.
 *               - OP_1: select the OP1 peripheral
 *               - OP_2: select the OP2 peripheral
 * @retval The new state of CMP(OP_CMPSTA_Low or OP_CMPSTA_High).
 *               - OP_CMPSTA_Low: The non-inverting input is at a lower voltage than the inverting input 
 *               - OP_CMPSTA_High: The non-inverting input is at a higher voltage than the inverting input 
 */
OP_CMPSTA_TypeDef OP_GetCMPSTA(OP_TypeDef* OPx)
{
    OP_CMPSTA_TypeDef OP_CMPSTA = OP_CMPSTA_Low;
    /* Check the parameters */
    assert_param(IS_OP_ALL_PERIPH(OPx)); 

    /* Enable the OP Function */
		if(OPx==OP_1)
		{
			if((OP->OPX_STS & OP_STS_OPCMP1STA) != 0)
			{
					OP_CMPSTA = OP_CMPSTA_High;
			}
			else
			{
					OP_CMPSTA = OP_CMPSTA_Low;
			}
		}
		else if(OPx==OP_2)
		{
			if((OP->OPX_STS & OP_STS_OPCMP2STA) != 0)
			{
					OP_CMPSTA = OP_CMPSTA_High;
			}
			else
			{
					OP_CMPSTA = OP_CMPSTA_Low;
			}
		}

    return OP_CMPSTA;
}

/**
 * @brief  Enables or disables the specified OP interrupts.
 * @param  OP_IT[in]: specifies the OP interrupts sources to be enabled or disabled.
 *         - OP_IT_INT: OP Interrupt
 *         - OP_IT_OPCMP1:OPCMP1 interrupt
 *         - OP_IT_OPCMP2: OPCMP2 interrupt
 * @param  NewState[in]: new state of the OP interrupts.
 *         - ENABLE: Function enable   
 *         - DISABLE:Function disable
 * @retval None
 */
void OP_ITConfig(uint16_t OP_IT, FunctionalState NewState)
{
    /* Check the parameters */
  
    assert_param(IS_OP_IT(OP_IT)); 
    assert_param(IS_FUNCTIONAL_STATE(NewState));


    if(NewState != DISABLE)
    {
        /* Enable the Interrupt sources */
        OP->OPX_IDE |= OP_IT;
    }
    else
    {
        /* Disable the Interrupt sources */
        OP->OPX_IDE &= (uint16_t)~OP_IT;
    }
}

/**
 * @brief  Checks whether the specified CMP flag is set or not.
 * @param  OP_FLAG[in]: specifies the flag to check.
 *               - OP_FLAG_OPCMP1: OPCMP1 flag
 *               - OP_FLAG_OPCMP2: OPCMP2 flag 
 * @retval The new state of OP_FLAG.
 *               - RESET
 *               - SET 
 */
FlagStatus OP_GetFlagStatus(OP_FLAG_TypeDef OP_FLAG)
{
    ITStatus bitstatus = RESET;
    /* Check the parameters */
    
    assert_param(IS_OP_FLAG(OP_FLAG)); 

    if((OP->OPX_STS & OP_FLAG) != (uint16_t)RESET)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    return bitstatus;
}

/**
 * @brief  Clear the specified CMP flag .
 * @param  OP_FLAG[in]: specifies the flag to check.
 *               - OP_FLAG_OPCMP1: OPCMP1 flag
 *               - OP_FLAG_OPCMP2: OPCMP2 flag 
 * @retval None.
 */
void OP_ClearFlag(uint16_t OP_FLAG)
{
    /* Clear the flags */
    OP->OPX_STS = (uint16_t)OP_FLAG;
}

/**
 * @}
 */
/* End of OP_Group4.	*/
#endif
#endif
/**
 * @}
 */
/**
 * @}
 */

/**
 * @}
 */

///************************ (C) COPYRIGHT SOC Microelectronics *****END OF FILE****/
