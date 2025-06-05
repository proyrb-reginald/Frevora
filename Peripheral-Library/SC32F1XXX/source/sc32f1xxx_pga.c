/**
 ******************************************************************************
 * @file    sc32f1xxx_pga.c
 * @author  SOC AE Team
 * @version V1.7
 * @date     17-10-2024
 * @brief  PGA function module
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
#if defined(SC32f11xx)
#include "sc32f1xxx_pga.h"


/** @defgroup PGA_Exported_Functions_Group1 Configuration of the PGA computation unit functions
 *  @brief   Configuration of the PGA computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### PGA configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitialize the PGAx peripheral registers to their default reset values.
 * @param  PGAx[out]:where can to select the PGA peripheral.
 *                  - PGA:PGA peripheral select PGA
 * @retval None
 */
void PGA_DeInit ( PGA_TypeDef* PGAx )
{
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_PGA_ALL_PERIPH ( PGAx ) );

    if ( PGAx == PGA )
    {
        /* Get the PGAx PGA_CON value */
        tmpreg = PGAx->PGA_CON;

        /* Set PGAFS bit to PGA_FreqSelect value */
        tmpreg &= 0xFF00;

        /* Write to PGAx PGA_CON */
        PGAx->PGA_CON = ( uint32_t ) tmpreg;
    }
}

/**
 * @brief  DeInitializes the PGA peripheral
 * @param  PGAx[out]:where can to select the PGA peripheral.
 *                  - PGA:PGA peripheral select PGA
 * @param  PGA_InitStruct[out]: Pointer to structure PGA_InitTypeDef, to be initialized.
 * @retval None
 */
void PGA_Init ( PGA_TypeDef* PGAx, PGA_InitTypeDef* PGA_InitStruct )
{
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param ( IS_PGA_ALL_PERIPH ( PGAx ) );
    assert_param ( IS_PGA_COM ( PGA_InitStruct->PGA_COM ) );
    assert_param ( IS_PGA_GAN ( PGA_InitStruct->PGA_GAN ) );

    assert_param ( IS_PGA_INSEL ( PGA_InitStruct->PGA_INSEL ) );


    /*---------------------------- PGAx PGA_CON Configuration ------------------------*/
    /* Get the PGAx PGA_CON value */
    tmpreg = PGAx->PGA_CON;

    /* Clear PGAFS bits */
    tmpreg &= ( uint32_t ) ~ ( PGA_CON_PGACOM | PGA_CON_PGAGAN | PGA_CON_PGAIPT | PGA_CON_PGAINSEL );
    /* Set PGAFS bit to PGA_FreqSelect value */
    tmpreg |= ( uint32_t ) ( PGA_InitStruct->PGA_COM | PGA_InitStruct->PGA_GAN | PGA_InitStruct->PGA_INSEL );

    /* Write to PGAx PGA_CON */
    PGAx->PGA_CON = tmpreg;
}

/**
 * @brief  Enables or disables the specified PGA peripheral.
 * @param  PGAx[out]:where can to select the PGA peripheral.
 *                  - PGA:PGA peripheral select PGA
 * @param  NewState[in]: new state of the PGAx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void PGA_Cmd ( PGA_TypeDef* PGAx, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_PGA_ALL_PERIPH ( PGAx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Enable the PGA Function */
        PGAx->PGA_CON |= PGA_CON_ENPGA;
    }
    else
    {
        /* Disable the PGA Function */
        PGAx->PGA_CON &= ( uint16_t ) ~PGA_CON_ENPGA;
    }
}

/**
  * @brief  Configure the trimming value of the OPAMP.
	* @param  PGAx[out]:where can to select the PGA peripheral.
	*                  - PGA:PGA peripheral select PGA
  * @param  PGA_TrimValue[in]: the trimming value. This parameter can be any value lower
  *         or equal to 0x0000001F.
  * @retval None
  */
void PGA_OffsetTrimConfig ( PGA_TypeDef* PGAx,  uint32_t PGA_TrimValue )
{
    uint32_t tmpreg = 0;

    /* Check the parameters */
    assert_param ( IS_PGA_ALL_PERIPH ( PGA_Selection ) );
    assert_param ( IS_PGA_TRIMMINGVALUE ( PGA_TrimValue ) );

    /*!< Get the OPAMPx_CSR register value */
    tmpreg = PGAx->PGA_CON;

    /*!< Clear the trimming bits */
    tmpreg &= ( ( uint32_t ) ~ ( PGA_CON_PGAOFS ) );

    /*!< Configure the new trimming value */
    tmpreg |= ( uint32_t ) ( PGA_TrimValue << PGA_CON_PGAOFS_Pos );

    /*!< Write to OPAMPx_CSR register */
    PGAx->PGA_CON = tmpreg;
}

/**
  * @brief  Start or stop the calibration of selected OPAMP peripheral.
  * @param  PGAx[out]:where can to select the PGA peripheral.
	*                  - PGA:PGA peripheral select PGA
  * @param  NewState[in]: new state of the OPAMP peripheral.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable
  * @retval None
  */
void PGA_StartCalibration ( PGA_TypeDef* PGAx, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_PGA_ALL_PERIPH ( PGA_Selection ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );

    if ( NewState != DISABLE )
    {
        /* Start the OPAMPx calibration */
        PGAx->PGA_CON |= ( uint32_t ) ( PGA_CON_PGAOFC );
    }
    else
    {
        /* Stop the OPAMPx calibration */
        PGAx->PGA_CON &= ( uint32_t ) ( ~PGA_CON_PGAOFC );
    }
}
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

/************************ (C) COPYRIGHT SOC Microelectronics *****END OF FILE****/
