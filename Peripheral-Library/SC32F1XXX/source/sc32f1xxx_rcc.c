/*
 ******************************************************************************
 * @file    sc32f1xxx_rcc.c
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief  RCC function module
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
#include "sc32f1xxx_rcc.h"
#include "sc32.h"

/** @defgroup RCC_Group1 Internal/external clocks, RCC configuration functions
 *  @brief   Internal/external clocks, RCC configuration functions
 *
@verbatim
 ===============================================================================
					 ##### RCC configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  Reset the peripheral RCCx register to its default value.
 * @param  None
 * @retval None
 */
void RCC_DeInit ( void )
{
    /*	RCC Reg Unlock = 0 */
    RCC->RCC_KEY = 0x40;

    /* Reset RCC_CFG0 register */
    RCC->RCC_CFG0 = ( uint32_t ) 0x00001040;

    /* Reset RCC_CFG1 register */
    RCC->RCC_CFG1 = ( uint32_t ) 0x00000000;

#if defined(SC32f10xx)
    /* Reset PLL_CFG register */
    RCC->PLL_CFG = ( uint32_t ) 0x00000000;
#endif

    /* Reset PLL_CFG register */
    RCC->NMI_CFG = ( uint32_t ) 0x00000000;

}

/**
 * @brief  Unlock the RCC register operation function.
 * @note   The RCC_CFG0, RCC_CFG1, and PLL_CFG write operations require the RCC_KEY to be unlocked.
 * @param  TimeLimit[in] : Switching time limit
 *          This parameter needs to be greater than or equal to 0x40.
 * @note   If no register write command is received after a timeLimit system clock, the RCC rewrite function is disabled again.
 * @retval Set state:
 *               - SUCCESS
 *               - ERROR
 */
ErrorStatus RCC_Unlock ( uint8_t TimeLimit )
{
    if ( TimeLimit >= 0x40 )
    {
        RCC->RCC_KEY = TimeLimit;
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
}
#if !defined(SC32f15xx)
/**
  * @brief  Enables or disables the HXT clock.
  * @param  NewState[in]: new state of the HXT clock.
  *                   - DISABLE:Function disable
  *                   - ENABLE:Function enable
  * @retval None
  */
void RCC_HXTCmd ( FunctionalState NewState )
{
    RCC_Unlock ( 0xFF );
    if ( NewState != DISABLE )
    {
        /* Enable the selected HXT peripheral */
        RCC->RCC_CFG0 |= RCC_CFG0_HXTEN;
    }
    else
    {
        /* Disable the selected HXT peripheral */
        RCC->RCC_CFG0 &= ( uint32_t ) ~ ( ( uint32_t ) RCC_CFG0_HXTEN );
    }
}
#endif
/**
  * @brief  Enables or disables the HIRC clock.
  * @param  NewState[in]: new state of the HIRC clock.
  *                   - DISABLE:Function disable
  *                   - ENABLE:Function enable
  * @retval None
  */
void RCC_HIRCCmd ( FunctionalState NewState )
{
    RCC_Unlock ( 0xFF );
    if ( NewState != DISABLE )
    {
        /* Enable the selected HIRC peripheral */
        RCC->RCC_CFG0 |= RCC_CFG0_HIRCEN;
    }
    else
    {
        /* Disable the selected HIRC peripheral */
        RCC->RCC_CFG0 &= ( uint32_t ) ~ ( ( uint32_t ) RCC_CFG0_HIRCEN );
    }
}

/**
  * @brief  Enables or disables the LXT clock.
  * @param  NewState[in]: new state of the LXT clock.
  *                   - DISABLE:Function disable
  *                   - ENABLE:Function enable
  * @retval None
  */
void RCC_LXTCmd ( FunctionalState NewState )
{
    RCC_Unlock ( 0xFF );
    if ( NewState != DISABLE )
    {
        /* Enable the selected LXT peripheral */
        RCC->RCC_CFG0 |= RCC_CFG0_LXTEN;
    }
    else
    {
        /* Disable the selected LXT peripheral */
        RCC->RCC_CFG0 &= ( uint32_t ) ~ ( ( uint32_t ) RCC_CFG0_LXTEN );
    }
}

/**
  * @brief  Enables or disables the LIRC clock.
  * @param  NewState[in]: new state of the LIRC clock.
  *                   - DISABLE:Function disable
  *                   - ENABLE:Function enable
  * @retval None
  */
void RCC_LIRCCmd ( FunctionalState NewState )
{
    RCC_Unlock ( 0xFF );
    if ( NewState != DISABLE )
    {
        /* Enable the selected LIRC peripheral */
        RCC->RCC_CFG0 |= RCC_CFG0_LIRCEN;
    }
    else
    {
        /* Disable the selected LIRC peripheral */
        RCC->RCC_CFG0 &= ( uint32_t ) ~ ( ( uint32_t ) RCC_CFG0_LIRCEN );
    }
}

#if defined(SC32f10xx)
/**
  * @brief  Enables or disables the PLL clock.
  * @param  NewState[in]: new state of the PLL clock.
  *                   - DISABLE:Function disable
  *                   - ENABLE:Function enable
  * @retval None
  */
void RCC_PLLCmd ( FunctionalState NewState )
{
    RCC_Unlock ( 0xFF );
    /* Check the parameters */
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the PLL peripheral */
        RCC->PLL_CFG |= PLL_CFG_PLLON;
    }
    else
    {
        /* Disable the PLL Clock */
        RCC->PLL_CFG &= ( uint32_t ) ~ ( ( uint32_t ) PLL_CFG_PLLON );
    }
}

/**
  * @brief  Enables or disables the PLLR clock.
  * @param  NewState[in]: new state of the PLLR clock.
  *                   - DISABLE:Function disable
  *                   - ENABLE:Function enable
  * @retval None
  */
void RCC_PLLRCmd ( FunctionalState NewState )
{
    RCC_Unlock ( 0xFF );
    /* Check the parameters */
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        RCC->PLL_CFG |= PLL_CFG_PLLREN;
    }
    else
    {
        RCC->PLL_CFG &= ( uint32_t ) ~ ( ( uint32_t ) PLL_CFG_PLLREN );
    }
}
#endif
#if defined(SC32f12xx) || defined(SC32f11xx)|| defined(SC32f15xx)
/**
  * @brief  Enables or disables the HIRCDIV1_EN clock.
  * @param  NewState[in]:new state of the HIRCDIV1 clock.
  *                   - DISABLE:Function disable
  *                   - ENABLE:Function enable
  * @retval None
  */

void RCC_HIRCDIV1Cmd ( FunctionalState NewState )
{
    RCC_Unlock ( 0xFF );
    if ( NewState != DISABLE )
    {
        /* Enable the selected HIRCDIV1 peripheral */
        RCC->RCC_CFG0 |= RCC_CFG0_HIRCDIV1;
    }
    else
    {
        /* Disable the selected HIRCDIV1 peripheral */
        RCC->RCC_CFG0 &= ( uint32_t ) ~ ( ( uint32_t ) RCC_CFG0_HIRCDIV1 );
    }
}
#endif
/**
  * @brief  Enables or disables the APB0 clock.
  * @param  NewState[in]: new state of the APB0 clock.
  *                   - DISABLE:Function disable
  *                   - ENABLE:Function enable
  * @retval None
  */
void RCC_APB0Cmd ( FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        RCCAPB0->APB0_CFG |= APB0_CFG_ENAPB;
    }
    else
    {
        RCCAPB0->APB0_CFG &= ~APB0_CFG_ENAPB;
    }
}

/**
  * @brief  Enables or disables the APB1 clock.
  * @param  NewState[in]:new state of the APB1 clock.
  *                   - DISABLE:Function disable
  *                   - ENABLE:Function enable
  * @retval None
  */
void RCC_APB1Cmd ( FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        RCCAPB1->APB1_CFG |= APB1_CFG_ENAPB;
    }
    else
    {
        RCCAPB1->APB1_CFG &= ~APB1_CFG_ENAPB;
    }
}

/**
  * @brief  Enables or disables the APB2 clock.
  * @param  NewState[in]: new state of the APB2 clock.
  *                   - DISABLE:Function disable
  *                   - ENABLE:Function enable
  * @retval None
  */
void RCC_APB2Cmd ( FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        RCCAPB2->APB2_CFG |= APB2_CFG_ENAPB;
    }
    else
    {
        RCCAPB2->APB2_CFG &= ~APB2_CFG_ENAPB;
    }
}

#if defined(SC32f10xx)
/**
 * @brief Configures the PLL clock source
 * @param  RCC_PLLCLKSource[in] : PLL clock source.
 *                            - RCC_PLLCLKSource_HIRC:PLL clock is HIRC
 *                            - RCC_PLLCLKSource_HXT:PLL clock is HXT
 *
 * @param PLL_Factor[out]: A pointer to PLL_Factor_TypeDef to initialize PLL.
 * @retval None
 */
void RCC_PLLConfig ( RCC_PLLCLKSource_TypeDef RCC_PLLCLKSource, RLL_Factor_TypeDef* RLL_Factor )
{
    RCC_Unlock ( 0xFF );
    uint32_t tmpreg;
    
    /* Check the parameters */
    assert_param ( RCC_PLLCLKSOURCE ( RCC_PLLCLKSource ) );

     tmpreg = RCC->PLL_CFG;

    tmpreg &= ( uint32_t ) ~ ( PLL_CFG_PLLCLKSEL | PLL_CFG_MDIVM | PLL_CFG_NDIVN | PLL_CFG_PDIVP );

    tmpreg |= ( uint32_t ) ( RCC_PLLCLKSource | ( RLL_Factor->PLLM << PLL_CFG_MDIVM_Pos ) |
                             ( RLL_Factor->PLLN << PLL_CFG_NDIVN_Pos ) | ( RLL_Factor->PLLP << PLL_CFG_PDIVP_Pos ) );

    RCC->PLL_CFG = tmpreg;
}
#endif

/** @defgroup RCC_Group2 System, AHB and APB busses clocks configuration functions
 *  @brief  System, AHB and APB busses clocks configuration functions
 *
@verbatim
 ===============================================================================
		   ##### System, AHB and APB busses clocks configuration functions #####
 ===============================================================================

@endverbatim
  * @{
  */


/**
 * @brief  Configures the RCC system clock source (SYSCLK).
 * @param  RCC_SysTickCLKSource[in] : Systick clock source.
 *                         SC32f10xx Selection range(RCC_SYSCLKSource_HIRC,RCC_SYSCLKSource_LIRC,RCC_SYSCLKSource_HXT,RCC_SYSCLKSource_PLLRCLK,RCC_SYSCLKSource_LXT)
 *                         SC32f11xx Selection range(RCC_SYSCLKSource_HIRC,RCC_SYSCLKSource_LIRC,RCC_SYSCLKSource_HXT,RCC_SYSCLKSource_HIRC_2,RCC_SYSCLKSource_LXT)
 *                         SC32f12xx Selection range(RCC_SYSCLKSource_HIRC,RCC_SYSCLKSource_LIRC,RCC_SYSCLKSource_HXT,RCC_SYSCLKSource_HIRC_2,RCC_SYSCLKSource_LXT)
 *                         SC32f15xx Selection range(RCC_SYSCLKSource_HIRC,RCC_SYSCLKSource_LIRC,RCC_SYSCLKSource_HIRC_2,RCC_SYSCLKSource_LXT)
 *                         - RCC_SYSCLKSource_HIRC:SYSCLK Source is HIRC
 *                         - RCC_SYSCLKSource_LIRC:SYSCLK Source is LIRC
 *                         - RCC_SYSCLKSource_HXT:SYSCLK Source is HXT
 *                         - RCC_SYSCLKSource_PLLRCLK :SYSCLK Source is PLLCK
 *                         - RCC_SYSCLKSource_HIRC_2:SYSCLK Source is HIRC/2
 *                         - RCC_SYSCLKSource_LXT:SYSCLK Source is LXT
 * @retval Set state:
 *               - SUCCESS
 *               - ERROR
 */
ErrorStatus RCC_SYSCLKConfig ( RCC_SYSCLKSource_TypeDef RCC_SYSCLKSource )
{
    uint32_t tmpreg;
    RCC_Unlock ( 0xFF );


    /* Check the parameters */
    assert_param ( IS_RCC_SYSCLKSOURCE ( RCC_SYSCLKSource ) );
    if ( RCC_SYSCLKSource != ( ( uint16_t ) ( ~RCC_CFG0_SYSCLKSW ) ) )
    {

#if defined(SC32f11xx)||defined(SC32f12xx)||defined(SC32f15xx)
        if ( RCC_SYSCLKSource == RCC_SYSCLKSource_HIRC )
        {
            RCC->RCC_CFG0 &= ~RCC_CFG0_WAIT_Msk;
            RCC->RCC_CFG0 |= RCC_WAIT_2;
        }
#elif defined(SC32f10xx)
    uint32_t Multioperator = 1;
    for ( int i = 1; i <= ((RCC->PLL_CFG &0x03) + 1 ); i++ )
    {
        Multioperator *=  2;
    }
    if ( ( ( 2 * ((RCC->PLL_CFG &0xFF00)>>8) ) / Multioperator ) >= 64 )
    {
        RCC->RCC_CFG0 &= ~RCC_CFG0_WAIT_Msk;
        RCC->RCC_CFG0 |= RCC_WAIT_1;
    }
#endif
		    RCC_Unlock ( 0xFF );
				
        tmpreg = RCC->RCC_CFG0;

        tmpreg &= ( uint32_t ) ~ ( RCC_CFG0_SYSCLKSEL | RCC_CFG0_SYSCLKSW );

        tmpreg |= ( uint32_t ) RCC_SYSCLKSource;

        RCC->RCC_CFG0 = tmpreg;

        RCC->RCC_CFG0 |= RCC_CFG0_SYSCLKSW;

        if ( ( RCC->RCC_CFG0 & RCC_CFG0_SYSCLKSW ) != RESET )
            return SUCCESS;
        else
            return ERROR;
    }
    else
    {
        RCC->RCC_CFG0 &= ~RCC_CFG0_WAIT_Msk;
        RCC->RCC_CFG0 |= RCC_WAIT_1;
        RCC->RCC_CFG0 &= ( uint32_t ) ~RCC_CFG0_SYSCLKSW;

        if ( ( RCC->RCC_CFG0 & RCC_CFG0_SYSCLKSW ) == RESET )
            return SUCCESS;
        else
            return ERROR;
    }
}

/**
  * @brief  Returns the clock source used as system clock.
  * @param  None
  * @retval The clock source used as system clock.
	*                         SC32f10xx Selection range(RCC_SYSCLKSource_HIRC,RCC_SYSCLKSource_LIRC,RCC_SYSCLKSource_HXT,RCC_SYSCLKSource_PLLRCLK,RCC_SYSCLKSource_LXT)
	*                         SC32f11xx Selection range(RCC_SYSCLKSource_HIRC,RCC_SYSCLKSource_LIRC,RCC_SYSCLKSource_HXT,RCC_SYSCLKSource_HIRC_2,RCC_SYSCLKSource_LXT)
	*                         SC32f12xx Selection range(RCC_SYSCLKSource_HIRC,RCC_SYSCLKSource_LIRC,RCC_SYSCLKSource_HXT,RCC_SYSCLKSource_HIRC_2,RCC_SYSCLKSource_LXT)
  *                         SC32f15xx Selection range(RCC_SYSCLKSource_HIRC,RCC_SYSCLKSource_LIRC,RCC_SYSCLKSource_HIRC_2,RCC_SYSCLKSource_LXT)
	*                         - RCC_SYSCLKSource_HIRC:SYSCLK Source is HIRC
	*                         - RCC_SYSCLKSource_LIRC:SYSCLK Source is LIRC
	*                         - RCC_SYSCLKSource_HXT:SYSCLK Source is HXT
	*                         - RCC_SYSCLKSource_PLLRCLK :SYSCLK Source is PLLCK
	*                         - RCC_SYSCLKSource_HIRC_2:SYSCLK Source is HIRC/2
	*                         - RCC_SYSCLKSource_LXT:SYSCLK Source is LXT
  */
RCC_SYSCLKSource_TypeDef RCC_GetSYSCLKSource ( void )
{
    if ( ( RCC->RCC_CFG0 & RCC_CFG0_SYSCLKSW ) != RESET )
    {
        return ( ( RCC_SYSCLKSource_TypeDef ) ( RCC->RCC_CFG0 & RCC_CFG0_SYSCLKSEL ) );
    }
    else
    {
#if defined (SC32f10xx)
        return RCC_SYSCLKSource_HIRC;
#elif defined (SC32f11xx) ||  defined (SC32f12xx) ||  defined (SC32f15xx)
        return RCC_SYSCLKSource_HIRC_2;
#endif
    }

}

/**
 * @brief Configures the HCLK clock source (HCLK).
 * @param  RCC_HCLKSource[in] : HCLK clock source.
 *                    - RCC_SYSCLK_Div1:AHB clock = SYSCLK
 *                    - RCC_SYSCLK_Div2:AHB clock = SYSCLK/2
 *                    - RCC_SYSCLK_Div4:AHB clock = SYSCLK/4
 *                    - RCC_SYSCLK_Div8:AHB clock = SYSCLK/8
 *                    - RCC_SYSCLK_Div16:AHB clock = SYSCLK/16
 * @retval None
 */
void RCC_HCLKConfig ( RCC_HCLK_TypeDef RCC_HCLK )
{
    /* Check the parameters */
    assert_param ( IS_RCC_HCLK ( RCC_HCLK ) );

    RCCAHB->AHB_CFG &= ( uint32_t ) ~ ( AHB_CFG_CLKDIV );
    RCCAHB->AHB_CFG |= RCC_HCLK;
}

/**
 * @brief Configures the APB0 clock source
 * @param  RCC_APB0CLK[in] : APB0CLK clock source.
 *              - RCC_HCLK_Div1:APB clock = AHB
 *              - RCC_HCLK_Div2:APB clock = AHB/2
 *              - RCC_HCLK_Div4:APB clock = AHB/4
 *              - RCC_HCLK_Div8:APB clock = AHB/8
 *              - RCC_HCLK_Div16:APB clock = AHB/16
 *              - RCC_HCLK_Div32:APB clock = AHB/32
 *              - RCC_HCLK_Div64:APB clock = AHB/64
 *              - RCC_HCLK_Div128:APB clock = AHB/128
 * @retval None
 */
void RCC_APB0Config ( RCC_PCLK_TypeDef RCC_APB0CLK )
{
    /* Check the parameters */
    assert_param ( IS_RCC_PCLK ( RCC_APB0CLK ) );

    RCCAPB0->APB0_CFG &= ~ ( ( uint32_t ) APB0_CFG_CLKDIV );
    RCCAPB0->APB0_CFG |= RCC_APB0CLK;
}

/**
 * @brief Configures the APB1 clock source
 * @param  RCC_APB1CLK[in]: APB1CLK clock source.
 *               - RCC_HCLK_Div1:APB clock = AHB
 *               - RCC_HCLK_Div2:APB clock = AHB/2
 *               - RCC_HCLK_Div4:APB clock = AHB/4
 *               - RCC_HCLK_Div8:APB clock = AHB/8
 *               - RCC_HCLK_Div16:APB clock = AHB/16
 *               - RCC_HCLK_Div32:APB clock = AHB/32
 *               - RCC_HCLK_Div64:APB clock = AHB/64
 *               - RCC_HCLK_Div128:APB clock = AHB/128
 * @retval None
 */
void RCC_APB1Config ( RCC_PCLK_TypeDef RCC_APB1CLK )
{
    /* Check the parameters */
    assert_param ( IS_RCC_PCLK ( RCC_APB1CLK ) );

    RCCAPB1->APB1_CFG &= ~ ( ( uint32_t ) APB1_CFG_CLKDIV );
    RCCAPB1->APB1_CFG |= RCC_APB1CLK;
}

/**
 * @brief Configures the APB2 clock source
 * @param  RCC_APB2CLK[in] :
 *               - RCC_HCLK_Div1:APB clock = AHB
 *               - RCC_HCLK_Div2:APB clock = AHB/2
 *               - RCC_HCLK_Div4: APB clock = AHB/4
 *               - RCC_HCLK_Div8:APB clock = AHB/8
 *               - RCC_HCLK_Div16:APB clock = AHB/16
 *               - RCC_HCLK_Div32:APB clock = AHB/32
 *               - RCC_HCLK_Div64:APB clock = AHB/64
 *               - RCC_HCLK_Div128:APB clock = AHB/128
 * @retval None
 */
void RCC_APB2Config ( RCC_PCLK_TypeDef RCC_APB2CLK )
{
    /* Check the parameters */
    assert_param ( IS_RCC_PCLK ( RCC_APB2CLK ) );

    RCCAPB2->APB2_CFG &= ~ ( ( uint32_t ) APB2_CFG_CLKDIV );
    RCCAPB2->APB2_CFG |= RCC_APB2CLK;
}

/**
  * @brief  Gets the frequency of each clock bus.
  * @param  RCC_Clocks[out]: Pointer to structure RCC_ClocksTypeDef, to be initialized.
  *
  * @retval None
  */
void RCC_GetClocksFreq ( RCC_ClocksTypeDef* RCC_Clocks )
{
    uint32_t  tmp;

#if defined(SC32f10xx)
    uint32_t  pllp, pllsource, pllm, plln;
#endif

    /* Get SYSCLK source -------------------------------------------------------*/
    if ( ( RCC->RCC_CFG0 & RCC_CFG0_SYSCLKSW ) == RESET )
    {
#if defined(SC32f10xx)
        RCC_Clocks->SYSCLK_Frequency = HIRC_VALUE;
#elif defined(SC32f11xx) ||defined(SC32f12xx)
        RCC_Clocks->SYSCLK_Frequency = HIRC_VALUE / 2;
#endif
    }
    else
    {
        switch ( RCC->RCC_CFG0 & RCC_CFG0_SYSCLKSEL )
        {
#if defined(SC32f11xx) ||defined(SC32f12xx)
        case RCC_SYSCLKSource_HXT:   /* HXT used as system clock source */
            RCC_Clocks->SYSCLK_Frequency = HXT_VALUE;
            break;
#endif
        case RCC_SYSCLKSource_LIRC:   /* LIRC used as system clock source */
            RCC_Clocks->SYSCLK_Frequency = LIRC_VALUE;
            break;
        case RCC_SYSCLKSource_LXT:   /* LXT used as system clock source */
            RCC_Clocks->SYSCLK_Frequency = LXT_VALUE;
            break;
#if defined(SC32f11xx) ||defined(SC32f12xx)||defined(SC32f15xx)
        case RCC_SYSCLKSource_HIRC_2:   /* HIRC used as system clock source */
            RCC_Clocks->SYSCLK_Frequency = HIRC_VALUE;
            break;
#elif defined(SC32f10xx)
        case RCC_SYSCLKSource_PLLRCLK:   /* PLL used as system clock source */
            if ( ( RCC->PLL_CFG & PLL_CFG_PLLCLKSEL ) == RESET ) /* HXT used as PLL clock source */
            {
                pllsource = HIRC_VALUE;
            }
            else   /* HIRC used as PLL clock source */
            {
                pllsource = HXT_VALUE;
            }

            pllm = ( ( RCC->PLL_CFG & PLL_CFG_MDIVM ) >> PLL_CFG_MDIVM_Pos );
            plln = ( ( RCC->PLL_CFG & PLL_CFG_NDIVN ) >> PLL_CFG_NDIVN_Pos );
            pllp = ( ( RCC->PLL_CFG & PLL_CFG_PDIVP ) >> PLL_CFG_PDIVP_Pos );

            RCC_Clocks->SYSCLK_Frequency = ( ( ( pllsource / pllm ) * plln ) >> ( pllp + 1 ) );
            break;
#endif
        }
    }

    /* Get AHB source -------------------------------------------------------*/
    tmp = ( ( RCCAHB->AHB_CFG & AHB_CFG_CLKDIV ) >> AHB_CFG_CLKDIV_Pos );
    RCC_Clocks->HCLK_Frequency = RCC_Clocks->SYSCLK_Frequency >> tmp;

    /* Get APB source -------------------------------------------------------*/
    tmp = ( ( RCCAPB0->APB0_CFG & APB0_CFG_CLKDIV ) >> APB0_CFG_CLKDIV_Pos );
    RCC_Clocks->PCLK0_Frequency = RCC_Clocks->HCLK_Frequency >> tmp;

    /* Get AHB source -------------------------------------------------------*/
    tmp = ( ( RCCAPB1->APB1_CFG & APB1_CFG_CLKDIV ) >> APB1_CFG_CLKDIV_Pos );
    RCC_Clocks->PCLK1_Frequency = RCC_Clocks->HCLK_Frequency >> tmp;

    /* Get AHB source -------------------------------------------------------*/
    tmp = ( ( RCCAPB2->APB2_CFG & APB2_CFG_CLKDIV ) >> APB2_CFG_CLKDIV_Pos );
    RCC_Clocks->PCLK2_Frequency = RCC_Clocks->HCLK_Frequency >> tmp;
}

/**
 * @brief  Select the number of waits Settings
 * @param  RCC_Wait[in]:Select the number of waits
 *         -RCC_WAIT_0:Wait number selection 0
 *         -RCC_WAIT_1:Wait number selection 1
 *         -RCC_WAIT_2:Wait number selection 2
 *         -RCC_WAIT_3:Wait number selection 3
 * @retval None
 */
void RCC_WaitConfig ( RCC_Wait_TypeDef RCC_Wait )
{
    RCC_Unlock ( 0xFF );
    /* Check the parameters */
    assert_param ( IS_RCC_Wait ( RCC_Wait ) );

    RCC->RCC_CFG0 &= ~RCC_CFG0_WAIT_Msk;
    RCC->RCC_CFG0 |= RCC_Wait;

}
/** @defgroup RCC_Group3 Peripheral clocks configuration functions
 *  @brief   Peripheral clocks configuration functions
 *
@verbatim
 ===============================================================================
		   #####  Peripheral clocks configuration functions #####
 ===============================================================================

@endverbatim
  * @{
  */
#if defined (SC32f11xx)|| defined(SC32f12xx)
/**
 * @brief Configures the PWM0 clock source
 * @param  RCC_LCDCLKSource[in] :
 *                  - RCC_PWM0CLKSource_Div1HIRC:LCD_LED clock = Div1HIRC
 *                  - RCC_PWM0CLKSource_PCLK:PWM0 clock = PCLK
 * @retval None
 */
void RCC_PWM0CLKConfig ( RCC_PWM0CLKSource_TypeDef RCC_PWM0CLKSource )
{
    RCC_Unlock ( 0xFF );
    /* Check the parameters */
    assert_param ( RCC_PWM0CLKSOURCE ( RCC_PWM0CLKSource ) );

    RCC->RCC_CFG1 &= ~ ( ( uint32_t ) RCC_CFG1_PWM0CLKSEL );
    RCC->RCC_CFG1 |= ( uint32_t ) ( RCC_PWM0CLKSource );
}
#endif
#if defined (SC32f11xx)|| defined(SC32f12xx)|| defined(SC32f10xx)
/**
 * @brief Configures the LCD/LED clock source
 * @param  RCC_LCDCLKSource[in] :
 *                  - RCC_LCDLEDCLKSource_LIRC:LCD_LED clock = LIRC
 *                  - RCC_LCDLEDCLKSource_LXT:PWM0 clock = LXT
 * @retval None
 */
void RCC_LCDLEDCLKConfig ( RCC_LCDLEDCLKSource_TypeDef RCC_LCDLEDCLKSource )
{
    RCC_Unlock ( 0xFF );
    /* Check the parameters */
    assert_param ( RCC_LCDLEDCLKSOURCE ( RCC_LCDLEDCLKSource ) );

    RCC->RCC_CFG1 &= ~ ( ( uint32_t ) RCC_CFG1_LCDCLKSEL );
    RCC->RCC_CFG1 |= ( uint32_t ) ( RCC_LCDLEDCLKSource );
}
#endif
/**
 * @brief Configures the BTM clock source
 * @param  RCC_BTMCLKSource[in] :
 *           - RCC_BTMCLKSource_LIRC:BTM clock = LIRC
 *           - RCC_BTMCLKSource_LXT:BTM clock = LXT
 * @retval None
 */
void RCC_BTMCLKConfig ( RCC_BTMCLKSource_TypeDef RCC_BTMCLKSource )
{
    RCC_Unlock ( 0xFF );
    /* Check the parameters */
    assert_param ( RCC_BTMCLKSOURCE ( RCC_BTMCLKSource ) );

    RCC->RCC_CFG1 &= ~ ( ( uint32_t ) RCC_CFG1_BTMCLKSEL );
    RCC->RCC_CFG1 |= ( uint32_t ) ( RCC_BTMCLKSource );
}


/**
  * @brief  Enables or disables the AHB Periph clock.
  * @param  RCC_AHBPeriph[in]: specifies the AHB1 peripheral to gates its clock.
	*                 SC32f10xx Selection range(RCC_AHBPeriph_DMA,RCC_AHBPeriph_CRC,RCC_AHBPeriph_IFB,RCC_AHBPeriph_ALL)
	*                 SC32f11xx Selection range(RCC_AHBPeriph_DMA,RCC_AHBPeriph_CRC,RCC_AHBPeriph_IFB,RCC_AHBPeriph_CAN,RCC_AHBPeriph_ALL)
	*                 SC32f12xx Selection range(RCC_AHBPeriph_DMA,RCC_AHBPeriph_CRC,RCC_AHBPeriph_IFB,RCC_AHBPeriph_ALL)
	*                 SC32f15xx Selection range(RCC_AHBPeriph_DMA,RCC_AHBPeriph_CRC,RCC_AHBPeriph_IFB,RCC_AHBPeriph_CAN,RCC_AHBPeriph_ALL)
  *                - RCC_AHBPeriph_DMA:Select peripheral DMA
  *                - RCC_AHBPeriph_CRC:Select peripheral CRC
  *                - RCC_AHBPeriph_IFB:Select peripheral IFB
  *                - RCC_AHBPeriph_CAN:Select peripheral CAN
  *                - RCC_AHBPeriph_ALL:Select ALL peripheral
  * @param  NewState[in]: new state of the AHB Periph clock.
  *                   - DISABLE:Function disable
  *                   - ENABLE:Function enable
  * @retval None
  */
void RCC_AHBPeriphClockCmd ( uint32_t RCC_AHBPeriph, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_RCC_AHBPERIPH ( RCC_AHBPeriph ) );

    if ( NewState != DISABLE )
    {
        RCCAHB->AHB_CFG |= RCC_AHBPeriph;
    }
    else
    {
        RCCAHB->AHB_CFG &= ~RCC_AHBPeriph;
    }
}

/**
  * @brief  Enables or disables the APB0 Periph clock.
  * @param  RCC_APB0Periph[in]: specifies the APB01 peripheral to gates its clock.
	*                 SC32f10xx Selection range(RCC_APB0Periph_TIM0-RCC_APB0Periph_TIM3,RCC_APB0Periph_TWI0,RCC_APB0Periph_SPI0,RCC_APB0Periph_UART0,RCC_APB0Periph_UART1,RCC_APB0Periph_PWM0,RCC_APB0Periph_ALL)
	*                 SC32f11xx Selection range(RCC_APB0Periph_TIM0-RCC_APB0Periph_TIM3,RCC_APB0Periph_TWI0,RCC_APB0Periph_SPI0,RCC_APB0Periph_UART0,RCC_APB0Periph_UART5,RCC_APB0Periph_UART1,RCC_APB0Periph_PWM0,RCC_APB0Periph_ALL)
	*                 SC32f12xx Selection range(RCC_APB0Periph_TIM0-RCC_APB0Periph_TIM3,RCC_APB0Periph_TWI0,RCC_APB0Periph_SPI0,RCC_APB0Periph_UART0,RCC_APB0Periph_UART5,RCC_APB0Periph_UART1,RCC_APB0Periph_PWM0,RCC_APB0Periph_ALL)
	*                 SC32f15xx Selection range(RCC_APB0Periph_TIM0-RCC_APB0Periph_TIM1,RCC_APB0Periph_TWI0,RCC_APB0Periph_SPI0,RCC_APB0Periph_UART0,RCC_APB0Periph_UART1,RCC_APB0Periph_PWM0,RCC_APB0Periph_ALL)
  *                  - RCC_APB0Periph_TIM0:Select peripheral TIM0
  *                  - RCC_APB0Periph_TIM1:Select peripheral TIM1
  *                  - RCC_APB0Periph_TIM2:Select peripheral TIM2
  *                  - RCC_APB0Periph_TIM3:Select peripheral TIM3
  *                  - RCC_APB0Periph_TWI0:Select peripheral TWI0
  *                  - RCC_APB0Periph_SPI0:Select peripheral SPI0
  *                  - RCC_APB0Periph_UART0:Select peripheral UART0
  *                  - RCC_APB0Periph_UART1:Select peripheral UART1
  *                  - RCC_APB0Periph_PWM0:Select peripheral PWM0
  *                  - RCC_APB0Periph_UART5:Select peripheral UART5
  *                  - RCC_APB0Periph_ALL:Select ALL peripheral
  * @param  NewState[in]:new state of the APB0 Periph clock.
  *                   - DISABLE:Function disable
  *                   - ENABLE:Function enable
  * @retval None
  */
void RCC_APB0PeriphClockCmd ( uint32_t RCC_APB0Periph, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_RCC_APB0PERIPH ( RCC_APB0Periph ) );

    if ( NewState != DISABLE )
    {
        RCCAPB0->APB0_CFG |= RCC_APB0Periph;
    }
    else
    {
        RCCAPB0->APB0_CFG &= ~RCC_APB0Periph;
    }
}

/**
  * @brief  Enables or disables the APB1 Periph clock.
  * @param  RCC_APB1Periph[in]: specifies the APB1 peripheral to gates its clock.
  *             SC32f10xx Selection range(RCC_APB1Periph_TIM4-RCC_APB1Periph_TIM7,RCC_APB1Periph_TWI1,RCC_APB1Periph_UART2,RCC_APB1Periph_ALL)
  *             SC32f11xx Selection range(RCC_APB1Periph_TIM4-RCC_APB1Periph_TIM7,RCC_APB1Periph_TWI1,RCC_APB1Periph_UART2,RCC_APB1Periph_UART4,RCC_APB1Periph_ALL)
  *             SC32f12xx Selection range(RCC_APB1Periph_TIM4-RCC_APB1Periph_TIM7,RCC_APB1Periph_TWI1,RCC_APB1Periph_SPI2,RCC_APB1Periph_UART2,RCC_APB1Periph_UART4,RCC_APB1Periph_ALL)
  *             SC32f15xx Selection range(RCC_APB1Periph_TIM2-RCC_APB1Periph_TIM3,RCC_APB1Periph_TWI1,RCC_APB1Periph_UART2,RCC_APB1Periph_ALL)
  *             - RCC_APB1Periph_TIM2:Select peripheral TIM2
  *             - RCC_APB1Periph_TIM3:Select peripheral TIM3 
  *             - RCC_APB1Periph_TIM4:Select peripheral TIM4
  *             - RCC_APB1Periph_TIM5:Select peripheral TIM5
  *             - RCC_APB1Periph_TIM6:Select peripheral TIM6
  *             - RCC_APB1Periph_TIM7:Select peripheral TIM7
  *             - RCC_APB1Periph_TWI1:Select peripheral TWI1
  *             - RCC_APB1Periph_SPI2:Select peripheral SPI2
  *             - RCC_APB1Periph_UART2:Select peripheral UART2
  *             - RCC_APB1Periph_UART4:Select peripheral UART4
  * -param  NewState[in]:new state of the APB1 Periph clock.
  *             - DISABLE:Function disable
  *             - ENABLE:Function enable
  * @retval None
  */
void RCC_APB1PeriphClockCmd ( uint32_t RCC_APB1Periph, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_RCC_APB1PERIPH ( RCC_APB1Periph ) );

    if ( NewState != DISABLE )
    {
        RCCAPB1->APB1_CFG |= RCC_APB1Periph;
    }
    else
    {
        RCCAPB1->APB1_CFG &= ~RCC_APB1Periph;
    }
}

/**
  * @brief  Enables or disables the APB2 Periph clock.
  * @param  RCC_APB2Periph[in]: specifies the APB21 peripheral to gates its clock.
  *             SC32f10xx Selection range(RCC_APB2Periph_LEDPWM,RCC_APB2Periph_LCD_LED,RCC_APB2Periph_UART3,RCC_APB2Periph_ALL)
  *             SC32f11xx Selection range(RCC_APB2Periph_LEDPWM,RCC_APB2Periph_LCD_LED,RCC_APB2Periph_UART3,RCC_APB2Periph_ALL)
  *             SC32f12xx Selection range(RCC_APB2Periph_LEDPWM,RCC_APB2Periph_LCD_LED,RCC_APB2Periph_UART3,RCC_APB2Periph_ALL)
  *             SC32f15xx Selection range(RCC_APB2Periph_QEP0-RCC_APB2Periph_QEP1,RCC_APB2Periph_ADC)
  *                   - RCC_APB2Periph_LEDPWM:Select peripheral LEDPWM
  *                   - RCC_APB2Periph_LCD_LED:Select peripheral LCD_LED
  *                   - RCC_APB2Periph_UART3:Select peripheral UART3
  *                   - RCC_APB2Periph_ALL:Select ALL peripheral
  *                  - RCC_APB2Periph_QEP0:Select peripheral QEP0EN,
  *                  - RCC_APB2Periph_QEP1:Select peripheral QEP1EN,
  *                  - RCC_APB2Periph_ADC:Select peripheral ADCEN,
  * @param  NewState[in]:new state of the APB2 Periph clock.
  *                   - DISABLE:Function disable
  *                   - ENABLE:Function enable
  * @retval None
  */
void RCC_APB2PeriphClockCmd ( uint32_t RCC_APB2Periph, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_RCC_APB2PERIPH ( RCC_APB2Periph ) );

    if ( NewState != DISABLE )
    {
        RCCAPB2->APB2_CFG |= RCC_APB2Periph;
    }
    else
    {
        RCCAPB2->APB2_CFG &= ~RCC_APB2Periph;
    }
}

/**
 * @brief  Forces or releases AHB peripheral reset.
  * @param  RCC_AHBPeriph[in]: specifies the AHB1 peripheral to gates its clock.
	*                 SC32f10xx Selection range(RCC_AHBPeriph_DMA,RCC_AHBPeriph_CRC,RCC_AHBPeriph_IFB,RCC_AHBPeriph_ALL)
	*                 SC32f11xx Selection range(RCC_AHBPeriph_DMA,RCC_AHBPeriph_CRC,RCC_AHBPeriph_IFB,RCC_AHBPeriph_CAN,RCC_AHBPeriph_ALL)
	*                 SC32f12xx Selection range(RCC_AHBPeriph_DMA,RCC_AHBPeriph_CRC,RCC_AHBPeriph_IFB,RCC_AHBPeriph_ALL)
	*                 SC32f15xx Selection range(RCC_AHBPeriph_DMA,RCC_AHBPeriph_CRC,RCC_AHBPeriph_IFB,RCC_AHBPeriph_CAN,RCC_AHBPeriph_ALL)
  *                - RCC_AHBPeriph_DMA:Select peripheral DMA
  *                - RCC_AHBPeriph_CRC:Select peripheral CRC
  *                - RCC_AHBPeriph_IFB:Select peripheral IFB
  *                - RCC_AHBPeriph_CAN:Select peripheral CAN
  *                - RCC_AHBPeriph_ALL:Select ALL peripheral
 * @param  NewState[in]:new state of the specified peripheral reset.
 *                   - DISABLE:Function disable
 *                   - ENABLE:Function enable
 * @retval None
 */
void RCC_AHBPeriphResetCmd ( uint32_t RCC_AHBPeriph, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_RCC_AHBPERIPH ( RCC_AHBPeriph ) );

    if ( NewState != DISABLE )
    {
        RCCAHB->AHB_RST |= RCC_AHBPeriph;
    }
    else
    {
        RCCAHB->AHB_RST &= ~RCC_AHBPeriph;
    }
}

/**
 * @brief  Forces or releases APB0 peripheral reset.
  * @param  RCC_APB0Periph[in]: specifies the APB01 peripheral to gates its clock.
	*                 SC32f10xx Selection range(RCC_APB0Periph_TIM0-RCC_APB0Periph_TIM3,RCC_APB0Periph_TWI0,RCC_APB0Periph_SPI0,RCC_APB0Periph_UART0,RCC_APB0Periph_UART1,RCC_APB0Periph_PWM0,RCC_APB0Periph_ALL)
	*                 SC32f11xx Selection range(RCC_APB0Periph_TIM0-RCC_APB0Periph_TIM3,RCC_APB0Periph_TWI0,RCC_APB0Periph_SPI0,RCC_APB0Periph_UART0,RCC_APB0Periph_UART5,RCC_APB0Periph_UART1,RCC_APB0Periph_PWM0,RCC_APB0Periph_ALL)
	*                 SC32f12xx Selection range(RCC_APB0Periph_TIM0-RCC_APB0Periph_TIM3,RCC_APB0Periph_TWI0,RCC_APB0Periph_SPI0,RCC_APB0Periph_UART0,RCC_APB0Periph_UART5,RCC_APB0Periph_UART1,RCC_APB0Periph_PWM0,RCC_APB0Periph_ALL)
	*                 SC32f15xx Selection range(RCC_APB0Periph_TIM0-RCC_APB0Periph_TIM1,RCC_APB0Periph_TWI0,RCC_APB0Periph_SPI0,RCC_APB0Periph_UART0,RCC_APB0Periph_UART1,RCC_APB0Periph_PWM0,RCC_APB0Periph_ALL)
  *                  - RCC_APB0Periph_TIM0:Select peripheral TIM0
  *                  - RCC_APB0Periph_TIM1:Select peripheral TIM1
  *                  - RCC_APB0Periph_TIM2:Select peripheral TIM2
  *                  - RCC_APB0Periph_TIM3:Select peripheral TIM3
  *                  - RCC_APB0Periph_TWI0:Select peripheral TWI0
  *                  - RCC_APB0Periph_SPI0:Select peripheral SPI0
  *                  - RCC_APB0Periph_UART0:Select peripheral UART0
  *                  - RCC_APB0Periph_UART1:Select peripheral UART1
  *                  - RCC_APB0Periph_PWM0:Select peripheral PWM0
  *                  - RCC_APB0Periph_UART5:Select peripheral UART5
  *                  - RCC_APB0Periph_ALL:Select ALL peripheral
 * @param  NewState[in]:new state of the specified peripheral reset.
 *                   - DISABLE:Function disable
 *                   - ENABLE:Function enable
 * @retval None
 */
void RCC_APB0PeriphResetCmd ( uint32_t RCC_APB0Periph, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_RCC_APB0PERIPH ( RCC_APB0Periph ) );

    if ( NewState != DISABLE )
    {
        RCCAPB0->APB0_RST |= RCC_APB0Periph;
    }
    else
    {
        RCCAPB0->APB0_RST &= ~RCC_APB0Periph;
    }
}

/**
 * @brief  Forces or releases APB1 peripheral reset.
  * @param  RCC_APB1Periph[in]: specifies the APB1 peripheral to gates its clock.
  *             SC32f10xx Selection range(RCC_APB1Periph_TIM4-RCC_APB1Periph_TIM7,RCC_APB1Periph_TWI1,RCC_APB1Periph_UART2,RCC_APB1Periph_ALL)
  *             SC32f11xx Selection range(RCC_APB1Periph_TIM4-RCC_APB1Periph_TIM7,RCC_APB1Periph_TWI1,RCC_APB1Periph_UART2,RCC_APB1Periph_UART4,RCC_APB1Periph_ALL)
  *             SC32f12xx Selection range(RCC_APB1Periph_TIM4-RCC_APB1Periph_TIM7,RCC_APB1Periph_TWI1,RCC_APB1Periph_SPI2,RCC_APB1Periph_UART2,RCC_APB1Periph_UART4,RCC_APB1Periph_ALL)
  *             SC32f15xx Selection range(RCC_APB1Periph_TIM2-RCC_APB1Periph_TIM3,RCC_APB1Periph_TWI1,RCC_APB1Periph_UART2,RCC_APB1Periph_ALL)
  *             - RCC_APB1Periph_TIM2:Select peripheral TIM2
  *             - RCC_APB1Periph_TIM3:Select peripheral TIM3 
  *             - RCC_APB1Periph_TIM4:Select peripheral TIM4
  *             - RCC_APB1Periph_TIM5:Select peripheral TIM5
  *             - RCC_APB1Periph_TIM6:Select peripheral TIM6
  *             - RCC_APB1Periph_TIM7:Select peripheral TIM7
  *             - RCC_APB1Periph_TWI1:Select peripheral TWI1
  *             - RCC_APB1Periph_SPI2:Select peripheral SPI2
  *             - RCC_APB1Periph_UART2:Select peripheral UART2
  *             - RCC_APB1Periph_UART4:Select peripheral UART4
 * @param  NewState[in]:new state of the specified peripheral reset.
 *                   - DISABLE:Function disable
 *                   - ENABLE:Function enable
 * @retval None
 */
void RCC_APB1PeriphResetCmd ( uint32_t RCC_APB1Periph, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_RCC_APB1PERIPH ( RCC_APB1Periph ) );

    if ( NewState != DISABLE )
    {
        RCCAPB1->APB1_RST |= RCC_APB1Periph;
    }
    else
    {
        RCCAPB1->APB1_RST &= ~RCC_APB1Periph;
    }
}

/**
 * @brief  Forces or releases APB2 peripheral reset.
  * @param  RCC_APB2Periph[in]: specifies the APB21 peripheral to gates its clock.
  *             SC32f10xx Selection range(RCC_APB2Periph_LEDPWM,RCC_APB2Periph_LCD_LED,RCC_APB2Periph_UART3,RCC_APB2Periph_ALL)
  *             SC32f11xx Selection range(RCC_APB2Periph_LEDPWM,RCC_APB2Periph_LCD_LED,RCC_APB2Periph_UART3,RCC_APB2Periph_ALL)
  *             SC32f12xx Selection range(RCC_APB2Periph_LEDPWM,RCC_APB2Periph_LCD_LED,RCC_APB2Periph_UART3,RCC_APB2Periph_ALL)
  *             SC32f15xx Selection range(RCC_APB2Periph_QEP0-RCC_APB2Periph_QEP1,RCC_APB2Periph_ADC)
  *                   - RCC_APB2Periph_LEDPWM:Select peripheral LEDPWM
  *                   - RCC_APB2Periph_LCD_LED:Select peripheral LCD_LED
  *                   - RCC_APB2Periph_UART3:Select peripheral UART3
  *                   - RCC_APB2Periph_ALL:Select ALL peripheral
  *                  - RCC_APB2Periph_QEP0:Select peripheral QEP0EN,
  *                  - RCC_APB2Periph_QEP1:Select peripheral QEP1EN,
  *                  - RCC_APB2Periph_ADC:Select peripheral ADCEN,
 * @param  NewState[in]:new state of the specified peripheral reset.
 *                   - DISABLE:Function disable
 *                   - ENABLE:Function enable
 * @retval None
 */
void RCC_APB2PeriphResetCmd ( uint32_t RCC_APB2Periph, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_RCC_APB2PERIPH ( RCC_APB2Periph ) );

    if ( NewState != DISABLE )
    {
        RCCAPB2->APB2_RST |= RCC_APB2Periph;
    }
    else
    {
        RCCAPB2->APB2_RST &= ~RCC_APB2Periph;
    }
}

/**
 * @brief  Forces or releases NMI peripheral reset.
 * @param  RCC_APB2Periph[in]: specifies the APB2 peripheral to reset its clock.
  *             SC32f10xx Selection range(RCC_NMIPeriph_CSS,RCC_NMIPeriph_CMP,RCC_NMIPeriph_INT0,RCC_NMIPeriph_ALL)
  *             SC32f11xx Selection range(RCC_NMIPeriph_CSS,RCC_NMIPeriph_CMP,RCC_NMIPeriph_INT0,RCC_NMIPeriph_ALL,RCC_NMIPeriph_SRAMPE)
  *             SC32f12xx Selection range(RCC_NMIPeriph_CSS,RCC_NMIPeriph_CMP,RCC_NMIPeriph_INT0,RCC_NMIPeriph_ALL,RCC_NMIPeriph_SRAMPE)
  *             SC32f15xx Selection range(RCC_NMIPeriph_INT0,RCC_NMIPeriph_SRAMPE,RCC_NMIPeriph_OP2,RCC_NMIPeriph_OP1,RCC_NMIPeriph_CMP£¬RCC_NMIPeriph_MCMP0,RCC_NMIPeriph_ALL)
 *                  - RCC_NMIPeriph_CSS:Select peripheral CSS
 *                  - RCC_NMIPeriph_CMP:Select peripheral CMP
 *                  - RCC_NMIPeriph_INT0:Select peripheral INT0EN,
 *                  - RCC_NMIPeriph_SRAMPE:Select peripheral SRAMPEEN,
 *                  - RCC_NMIPeriph_OP2:Select peripheral OP2EN,
 *                  - RCC_NMIPeriph_OP1:Select peripheral OP1EN,
 *                  - RCC_NMIPeriph_CMP:Select peripheral CMPEN,
 *                  - RCC_NMIPeriph_MCMP0:Select peripheral MCMP0EN,
 *                  - RCC_NMIPeriph_ALL:Select peripheral ALL,
 * @param  NewState[in]:new state of the specified peripheral reset.
 *                   - DISABLE:Function disable
 *                   - ENABLE:Function enable
 * @retval None
 */
void RCC_NMICmd ( uint32_t RCC_NMIPeriph, FunctionalState NewState )
{
    uint32_t temp;
    /* Check the parameters */
    assert_param ( IS_RCC_NMIPeriph ( RCC_NMIPeriph ) );

    temp = RCC->NMI_CFG;

    temp &= ( ~RCC_NMIPeriph );

    if ( NewState != DISABLE )
    {
        temp |= 0xA05F0000 | RCC_NMIPeriph;
    }
    else
    {
        temp |= 0xA05F0000;
    }
    RCC->NMI_CFG = temp;
}
/* End of RCC_Group3.	*/

/** @defgroup Systick Timer configuration functions
 *  @brief    Systick Timer configuration functions
 *
@verbatim
 ===============================================================================
		   ##### Systick Timer configuration functions #####
 ===============================================================================

@endverbatim
  * @{
  */
/**
 * @brief Configures the Systick clock source (SYSCLK).
 * @param  RCC_SysTickCLKSource[in] : Systick clock source.
 *                     - RCC_SysTickSource_HCLK_DIV8 :SysTickCLK clock = HCLK/8
 *                     - RCC_SysTickSource_HIRC_DIV2:SysTickCLK clock = HIRC/2
 *                     - RCC_SysTickSource_HXT_DIV2:SysTickCLK clock = HXT/2
 *                     - RCC_SysTickSource_LIRC:SysTickCLK clock = LIRC
 *                     - RCC_SysTickSource_LXT:SysTickCLK clock = LXT
 *                     - RCC_SysTickSource_HCLK:SysTickCLK clock = HCLK
 * @retval None
 */
void RCC_SystickCLKConfig ( RCC_SysTickSource_TypeDef RCC_SysTickSource )
{

    /* Check the parameters */
    assert_param ( IS_RCC_SYSTICKSOURCE ( RCC_SysTickSource ) );

    if ( RCC_SysTickSource == RCC_SysTickSource_HCLK )
    {
        SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
    }
    else
    {
        RCC_Unlock ( 0xFF );
        SysTick->CTRL &= ~SysTick_CTRL_CLKSOURCE_Msk;
        RCC->RCC_CFG1 &= ~ ( ( uint32_t ) RCC_CFG1_STCLKSEL );
        RCC->RCC_CFG1 |= ( uint32_t ) ( RCC_SysTickSource );
    }
}
/**
 * @brief Configures the count value of Systick Timer.
 * @param  Counter[in]:count value
 * @retval None
 */
void RCC_SystickSetCounter ( uint32_t Counter )
{
    if ( ( Counter - 1UL ) <= SysTick_LOAD_RELOAD_Msk ) /* Reload value possible */
    {
        SysTick->LOAD = ( uint32_t ) ( Counter - 1UL ); /* set reload register */
        SysTick->VAL  = 0UL;   /* Load the SysTick Counter Value */
    }
}
/**
  * @brief  Enables or disables the Systick Timer.
  * @param  NewState[in]:new state of the APB2 clock.
  *                   - DISABLE:Function disable
  *                   - ENABLE:Function enable
  * @retval None
  */
void RCC_SystickCmd ( FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        SysTick->CTRL |= ( uint32_t ) ( SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk ); /* Enable SysTick IRQ and SysTick Timer */
    }
    else
    {
        SysTick->CTRL &= ~ ( uint32_t ) ( SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk );
    }
}
/**
 * @brief  Checks whether the specified Systick flag is set or not.
 * @param  None
 * @retval The new state of Systick_FLAG (SET or RESET).
 *                  -  RESET:Flag reset
 *                  -  SET :Flag up
 */
FlagStatus RCC_SystickGetFlagStatus ( void )
{
    if ( ( SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk ) != ( uint32_t ) RESET )
    {
        return ( SET );
    }
    return ( RESET );
}
/**
 * @}
 */
/* End of RCC_Group4.	*/

/** @defgroup Interrupts and flags management functions
 *  @brief    Interrupts and flags management functions
 *
@verbatim
 ===============================================================================
		   ##### Interrupts and flags management functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  Enables or disables the RCC interrupt.
  * @param  NewState[in]:new state of the LXT clock.
  *                   - DISABLE:Function disable
  *                   - ENABLE:Function enable
  * @retval None
  */
void RCC_ITConfig ( FunctionalState NewState )
{
    RCC_Unlock ( 0xFF );
    if ( NewState != DISABLE )
    {
        RCC->RCC_CFG0 |= RCC_CFG0_INTEN;
    }
    else
    {
        RCC->RCC_CFG0 &= ( uint32_t ) ~ ( ( uint32_t ) RCC_CFG0_INTEN );
    }
}

/**
 * @brief  Checks whether the specified RCC flag is set or not.
 * @param  RCC_FLAG: specifies the flag to check.
 *                         SC32f10xx Selection range(RCC_FLAG_CLKIF,RCC_FLAG_LOCKERR,RCC_FLAG_PLLRDY)
 *                         SC32f12xx Selection range(RCC_FLAG_CLKIF,RCC_FLAG_SRAMPEIF)
 *                         - RCC_FLAG_CLKIF: Clock source exception flag
 *                         - RCC_FLAG_LOCKERR:PLL out-of-lock record flag
 *                         - RCC_FLAG_PLLRDY: PLL Clock Ready Flag
 *                         - RCC_FLAG_SRAMPEIF: SRAM parity error flag
 * @retval The new state of RCC_FLAG (SET or RESET).
 *                  -  RESET:Flag reset
 *                  -  SET :Flag up
 */
FlagStatus RCC_GetFlagStatus ( uint32_t RCC_FLAG )
{
    /* Check the parameters */
    assert_param ( IS_GET_RCC_FLAG ( RCC_FLAG ) );

    if( ( RCC->RCC_STS & RCC_FLAG ) != ( uint32_t ) RESET )
    {
        return ( SET );
    }
    return ( RESET );
}


/**
 * @}
 */
/* End of RCC_Group5.	*/


/**
 * @}
 */
/* End of functions ---------------------------------------------------------*/

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT SOC Microelectronics *****END OF FILE****/
