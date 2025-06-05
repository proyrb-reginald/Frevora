/********************************************************************************
 * @file    sc32f1xxx_gpio.c
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   GPIO function module
 *
 *******************************************************************************
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
#include "sc32f1xxx_gpio.h"
#include "sc32.h"

/** @defgroup GPIO_Group1 Initialization and Configuration
 *  @brief   Initialization and Configuration
 *
@verbatim
 ===============================================================================
                    ##### Initialization and Configuration #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
 * @brief  Deinitializes the GPIOx peripheral registers to their default reset
 *         values.
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral.
 *                SC32f10xx Selection range(GPIOA - GPIOC)
 *                SC32f11xx Selection range(GPIOA - GPIOD)
 *                SC32f12xx Selection range(GPIOA - GPIOC)
 *               - GPIOA: select the GPIOA peripheral
 *               - GPIOB: select the GPIOB peripheral
 *               - GPIOC: select the GPIOC peripheral
 *               - GPIOD: select the GPIOD peripheral
 * @retval None
 */
void GPIO_DeInit ( GPIO_TypeDef* GPIOx )
{
    /* Check the parameters */
    assert_param ( IS_GPIO_ALL_PERIPH ( GPIOx ) );

    /* Deinitializes the GPIOx PXCON register to their default reset values. */
    GPIOx->PXCON &= ( uint32_t ) ( ~GPIO_PIN_All );
    /* Deinitializes the GPIOx PXPH register to their default reset values. */
    GPIOx->PXPH &= ( uint32_t ) ( ~GPIO_PIN_All );
    /* Deinitializes the GPIOx PIN register to their default reset values. */
    GPIOx->PIN &= ( uint32_t ) ( ~GPIO_PIN_All );
    /* Deinitializes the GPIOx PXLEV register to their default reset values. */
    GPIOx->PXLEV &= ( uint32_t ) 0x00000000;
}

/**
 * @brief  Initializes the peripheral GPIOx register with the parameters specified in GPIO_InitStruct.
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral.
 *                SC32f10xx Selection range(GPIOA - GPIOC)
 *                SC32f11xx Selection range(GPIOA - GPIOD)
 *                SC32f12xx Selection range(GPIOA - GPIOC)
 *                SC32f15xx Selection range(GPIOA - GPIOC)
 *               - GPIOA: select the GPIOA peripheral
 *               - GPIOB: select the GPIOB peripheral
 *               - GPIOC: select the GPIOC peripheral
 *               - GPIOD: select the GPIOD peripheral
 * @param  GPIO_InitStruct[out]: Pointer to structure GPIO_InitTypeDef, to be initialized.
 * @retval None
 */
void GPIO_Init ( GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct )
{
    uint32_t tmppin, tmppos, tmpreg;

    /* Check the parameters */
    assert_param ( IS_GPIO_ALL_PERIPH ( GPIOx ) );
    assert_param ( IS_GPIO_PIN ( GPIO_InitStruct->GPIO_Pin ) );
    assert_param ( IS_GPIO_MODE ( GPIO_InitStruct->GPIO_Mode ) );

    if ( GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OUT_PP )
    {
        /* Configure Pins to High-resistance output mode */
        GPIOx->PXCON |= ( uint32_t ) GPIO_InitStruct->GPIO_Pin;
    }
    else if ( GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IN_PU )
    {
        /* Configure Pins to Pull-up input mode */
        GPIOx->PXCON &= ( uint32_t ) ( ~GPIO_InitStruct->GPIO_Pin );
        GPIOx->PXPH |= ( uint32_t ) GPIO_InitStruct->GPIO_Pin;
    }
    else if ( GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IN_HI )
    {
        /* Configure Pin to High-resistance intput mode */
        GPIOx->PXCON &= ( uint32_t ) ( ~GPIO_InitStruct->GPIO_Pin );
        GPIOx->PXPH &= ( uint32_t ) ( ~GPIO_InitStruct->GPIO_Pin );
    }

    /* Get GPIOx PXLEV value */
    tmpreg = GPIOx->PXLEV;
    /* Query the Pins that needs to be manipulated */
    for ( tmppos = 0; tmppos < 16; tmppos++ )
    {
        tmppin = ( uint32_t ) ( 0x01 << tmppos );
        if ( ( tmppin & GPIO_InitStruct->GPIO_Pin ) != RESET )
        {
            /* Clear the LEVx bits */
            tmpreg &= ( uint32_t ) ~ ( GPIO_DriveLevel_3 << ( tmppos * 2 ) );
            /* Set LEVx bits according to Drive Level value */
            tmpreg |= ( uint32_t ) ( GPIO_InitStruct->GPIO_DriveLevel << ( tmppos * 2 ) );
        }
    }
    /* Store GPIOx PXLEV the new value */
    GPIOx->PXLEV = tmpreg;
}

/**
 * @brief  Sets the I/O driver level
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral.
 *                SC32f10xx Selection range(GPIOA - GPIOC)
 *                SC32f11xx Selection range(GPIOA - GPIOD)
 *                SC32f12xx Selection range(GPIOA - GPIOC)
 *                SC32f15xx Selection range(GPIOA - GPIOC)
 *               - GPIOA: select the GPIOA peripheral
 *               - GPIOB: select the GPIOB peripheral
 *               - GPIOC: select the GPIOC peripheral
 *               - GPIOD: select the GPIOD peripheral
 * @param  GPIO_Pin[in]:specifies the port bit to be read.
 *                   - GPIO_Pin_0:Pin 0 selected
 *                   - GPIO_Pin_1:Pin 1 selected
 *                   - GPIO_Pin_2:Pin 2 selected
 *                   - GPIO_Pin_3:Pin 3 selected
 *                   - GPIO_Pin_4:Pin 4 selected
 *                   - GPIO_Pin_5:Pin 5 selected
 *                   - GPIO_Pin_6:Pin 6 selected
 *                   - GPIO_Pin_7:Pin 7 selected
 *                   - GPIO_Pin_8:Pin 8 selected
 *                   - GPIO_Pin_9:Pin 9 selected
 *                   - GPIO_Pin_10:Pin 10 selected
 *                   - GPIO_Pin_11:Pin 11 selected
 *                   - GPIO_Pin_12:Pin 12 selected
 *                   - GPIO_Pin_13:Pin 13 selected
 *                   - GPIO_Pin_14:Pin 14 selected
 *                   - GPIO_Pin_15:Pin 15 selected
 *                   - GPIO_PIN_LNIB:Pin Low 8 Bits selected
 *                   - GPIO_PIN_HNIB:Pin High 8 Bits selected
 *                   - GPIO_PIN_All:All pins selected
 * @param  GPIO_DriveLevel[in]: specifies the operating Drive Level for the selected pins.
 *                  - GPIO_DriveLevel_0:I/O output Drive: Level 0(Max)
 *                  - GPIO_DriveLevel_1:I/O output Drive: Level 1
 *                  - GPIO_DriveLevel_2:I/O output Drive: Level 2
 *                  - GPIO_DriveLevel_3:I/O output Drive: Level 3
 * @retval None
 */
void GPIO_SetDriveLevel ( GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_DriveLevel_TypeDef GPIO_DriveLevel )
{
    uint32_t tmppin, tmppos, tmpreg;
    /* Get GPIOx PXLEV value */
    tmpreg = GPIOx->PXLEV;
    /* Query the Pins that needs to be manipulated */
    for ( tmppos = 0; tmppos < 16; tmppos++ )
    {
        tmppin = ( uint32_t ) ( 0x01 << tmppos );
        if ( ( tmppin & GPIO_Pin ) != RESET )
        {
            /* Clear the LEVx bits */
            tmpreg &= ( uint32_t ) ~ ( GPIO_DriveLevel_3 << ( tmppos * 2 ) );
            /* Set LEVx bits according to Drive Level value */
            tmpreg |= ( uint32_t ) ( GPIO_DriveLevel << ( tmppos * 2 ) );
        }
    }
    /* Store GPIOx PXLEV the new value */
    GPIOx->PXLEV = tmpreg;

}

/**
 * @}
 */
/* End of PWM_Group1.	*/

/** @defgroup GPIO_Group2 IO operation functions
  *  @brief   GPIO Read and Write
  *
@verbatim
 ===============================================================================
                       ##### IO operation functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
 * @brief  Reads the specified input port pin.
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral.
 *                SC32f10xx Selection range(GPIOA - GPIOC)
 *                SC32f11xx Selection range(GPIOA - GPIOD)
 *                SC32f12xx Selection range(GPIOA - GPIOC)
 *                SC32f15xx Selection range(GPIOA - GPIOC)
 *               - GPIOA: select the GPIOA peripheral
 *               - GPIOB: select the GPIOB peripheral
 *               - GPIOC: select the GPIOC peripheral
 *               - GPIOD: select the GPIOD peripheral
 * @retval The input port pin value.
 *                   - GPIO_Pin_0:Pin 0 selected
 *                   - GPIO_Pin_1:Pin 1 selected
 *                   - GPIO_Pin_2:Pin 2 selected
 *                   - GPIO_Pin_3:Pin 3 selected
 *                   - GPIO_Pin_4:Pin 4 selected
 *                   - GPIO_Pin_5:Pin 5 selected
 *                   - GPIO_Pin_6:Pin 6 selected
 *                   - GPIO_Pin_7:Pin 7 selected
 *                   - GPIO_Pin_8:Pin 8 selected
 *                   - GPIO_Pin_9:Pin 9 selected
 *                   - GPIO_Pin_10:Pin 10 selected
 *                   - GPIO_Pin_11:Pin 11 selected
 *                   - GPIO_Pin_12:Pin 12 selected
 *                   - GPIO_Pin_13:Pin 13 selected
 *                   - GPIO_Pin_14:Pin 14 selected
 *                   - GPIO_Pin_15:Pin 15 selected
 *                   - GPIO_PIN_LNIB:Pin Low 8 Bits selected
 *                   - GPIO_PIN_HNIB:Pin High 8 Bits selected
 *                   - GPIO_PIN_All:All pins selected
 */
uint16_t GPIO_ReadData ( GPIO_TypeDef* GPIOx )
{
    /* Check the parameters */
    assert_param ( IS_GPIO_ALL_PERIPH ( GPIOx ) );

    return ( uint16_t ) ( GPIOx->PIN );
}

/**
 * @brief  Reads the selected data port bits.
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral.
 *                SC32f10xx Selection range(GPIOA - GPIOC)
 *                SC32f11xx Selection range(GPIOA - GPIOD)
 *                SC32f12xx Selection range(GPIOA - GPIOC)
 *                SC32f15xx Selection range(GPIOA - GPIOC)
 *               - GPIOA: select the GPIOA peripheral
 *               - GPIOB: select the GPIOB peripheral
 *               - GPIOC: select the GPIOC peripheral
 *               - GPIOD: select the GPIOD peripheral
 * @param  GPIO_Pin[in]: specifies the port bit to be read.
 *                   - GPIO_Pin_0:Pin 0 selected
 *                   - GPIO_Pin_1:Pin 1 selected
 *                   - GPIO_Pin_2:Pin 2 selected
 *                   - GPIO_Pin_3:Pin 3 selected
 *                   - GPIO_Pin_4:Pin 4 selected
 *                   - GPIO_Pin_5:Pin 5 selected
 *                   - GPIO_Pin_6:Pin 6 selected
 *                   - GPIO_Pin_7:Pin 7 selected
 *                   - GPIO_Pin_8:Pin 8 selected
 *                   - GPIO_Pin_9:Pin 9 selected
 *                   - GPIO_Pin_10:Pin 10 selected
 *                   - GPIO_Pin_11:Pin 11 selected
 *                   - GPIO_Pin_12:Pin 12 selected
 *                   - GPIO_Pin_13:Pin 13 selected
 *                   - GPIO_Pin_14:Pin 14 selected
 *                   - GPIO_Pin_15:Pin 15 selected
 *                   - GPIO_PIN_LNIB:Pin Low 8 Bits selected
 *                   - GPIO_PIN_HNIB:Pin High 8 Bits selected
 *                   - GPIO_PIN_All:All pins selected
 * @retval Bit state
 *              - Bit_RESET
 *              - Bit_SET
 */
BitAction GPIO_ReadDataBit ( GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin )
{
    BitAction bitstatus;
    /* Check the parameters */
    assert_param ( IS_GPIO_ALL_PERIPH ( GPIOx ) );
    assert_param ( IS_GPIO_PIN ( GPIO_Pin ) );

    if ( GPIOx->PIN & GPIO_Pin )
    {
        bitstatus = Bit_SET;
    }
    else
    {
        bitstatus = Bit_RESET;
    }

    return bitstatus;
}

/**
 * @brief  Sets the selected data port bits.
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral.
 *                SC32f10xx Selection range(GPIOA - GPIOC)
 *                SC32f11xx Selection range(GPIOA - GPIOD)
 *                SC32f12xx Selection range(GPIOA - GPIOC)
 *                SC32f15xx Selection range(GPIOA - GPIOC)
 *               - GPIOA: select the GPIOA peripheral
 *               - GPIOB: select the GPIOB peripheral
 *               - GPIOC: select the GPIOC peripheral
 *               - GPIOD: select the GPIOD peripheral
 * @param  GPIO_Pin[in]: specifies the port bit to be written.
 *                   - GPIO_Pin_0:Pin 0 selected
 *                   - GPIO_Pin_1:Pin 1 selected
 *                   - GPIO_Pin_2:Pin 2 selected
 *                   - GPIO_Pin_3:Pin 3 selected
 *                   - GPIO_Pin_4:Pin 4 selected
 *                   - GPIO_Pin_5:Pin 5 selected
 *                   - GPIO_Pin_6:Pin 6 selected
 *                   - GPIO_Pin_7:Pin 7 selected
 *                   - GPIO_Pin_8:Pin 8 selected
 *                   - GPIO_Pin_9:Pin 9 selected
 *                   - GPIO_Pin_10:Pin 10 selected
 *                   - GPIO_Pin_11:Pin 11 selected
 *                   - GPIO_Pin_12:Pin 12 selected
 *                   - GPIO_Pin_13:Pin 13 selected
 *                   - GPIO_Pin_14:Pin 14 selected
 *                   - GPIO_Pin_15:Pin 15 selected
 *                   - GPIO_PIN_LNIB:Pin Low 8 Bits selected
 *                   - GPIO_PIN_HNIB:Pin High 8 Bits selected
 *                   - GPIO_PIN_All:All pins selected
 * @retval None
 */
void GPIO_SetBits ( GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin )
{
    /* Check the parameters */
    assert_param ( IS_GPIO_ALL_PERIPH ( GPIOx ) );
    assert_param ( IS_GPIO_PIN ( GPIO_Pin ) );
    __IO uint32_t tmpreg = ( uint32_t ) GPIOx;
    while ( GPIO_Pin != 0 )
    {
        if ( GPIO_Pin & 0x0001 )
        {
            ( * ( ( uint8_t* ) ( tmpreg ) ) ) = 1;
        }
        GPIO_Pin = GPIO_Pin >> 1;
        tmpreg++;
    }
}

/**
 * @brief  Clears the specified data port bit.
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral.
 *                SC32f10xx Selection range(GPIOA - GPIOC)
 *                SC32f11xx Selection range(GPIOA - GPIOD)
 *                SC32f12xx Selection range(GPIOA - GPIOC)
 *                SC32f15xx Selection range(GPIOA - GPIOC)
 *               - GPIOA: select the GPIOA peripheral
 *               - GPIOB: select the GPIOB peripheral
 *               - GPIOC: select the GPIOC peripheral
 *               - GPIOD: select the GPIOD peripheral
 * @param  GPIO_Pin[in]: specifies the port bit to be written.
 *                   - GPIO_Pin_0:Pin 0 selected
 *                   - GPIO_Pin_1:Pin 1 selected
 *                   - GPIO_Pin_2:Pin 2 selected
 *                   - GPIO_Pin_3:Pin 3 selected
 *                   - GPIO_Pin_4:Pin 4 selected
 *                   - GPIO_Pin_5:Pin 5 selected
 *                   - GPIO_Pin_6:Pin 6 selected
 *                   - GPIO_Pin_7:Pin 7 selected
 *                   - GPIO_Pin_8:Pin 8 selected
 *                   - GPIO_Pin_9:Pin 9 selected
 *                   - GPIO_Pin_10:Pin 10 selected
 *                   - GPIO_Pin_11:Pin 11 selected
 *                   - GPIO_Pin_12:Pin 12 selected
 *                   - GPIO_Pin_13:Pin 13 selected
 *                   - GPIO_Pin_14:Pin 14 selected
 *                   - GPIO_Pin_15:Pin 15 selected
 *                   - GPIO_PIN_LNIB:Pin Low 8 Bits selected
 *                   - GPIO_PIN_HNIB:Pin High 8 Bits selected
 *                   - GPIO_PIN_All:All pins selected
 * @retval None
 */
void GPIO_ResetBits ( GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin )
{
    /* Check the parameters */
    assert_param ( IS_GPIO_ALL_PERIPH ( GPIOx ) );
    assert_param ( IS_GPIO_PIN ( GPIO_Pin ) );

    __IO uint32_t tmpreg = ( uint32_t ) GPIOx;

    while ( GPIO_Pin != 0 )
    {
        if ( GPIO_Pin & 0x0001 )
        {
            ( * ( ( uint8_t* ) ( tmpreg ) ) ) = 0;
        }
        GPIO_Pin = GPIO_Pin >> 1;
        tmpreg++;
    }
}


/**
 * @brief  Writes data to the specified GPIO data port.
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral.
 *                SC32f10xx Selection range(GPIOA - GPIOC)
 *                SC32f11xx Selection range(GPIOA - GPIOD)
 *                SC32f12xx Selection range(GPIOA - GPIOC)
 *                SC32f15xx Selection range(GPIOA - GPIOC)
 *               - GPIOA: select the GPIOA peripheral
 *               - GPIOB: select the GPIOB peripheral
 *               - GPIOC: select the GPIOC peripheral
 *               - GPIOD: select the GPIOD peripheral
 * @param  PortVal[in]: The value of the port data register to be written.
 * @retval None
 */
void GPIO_Write ( GPIO_TypeDef* GPIOx, uint16_t PortVal )
{
    /* Check the parameters */
    assert_param ( IS_GPIO_ALL_PERIPH ( GPIOx ) );

    /*  */
    GPIOx->PIN = PortVal;
}

/**
  * @brief  Sets or clears the specified data port bit.
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral.
 *                SC32f10xx Selection range(GPIOA - GPIOC)
 *                SC32f11xx Selection range(GPIOA - GPIOD)
 *                SC32f12xx Selection range(GPIOA - GPIOC)
 *                SC32f15xx Selection range(GPIOA - GPIOC)
 *               - GPIOA: select the GPIOA peripheral
 *               - GPIOB: select the GPIOB peripheral
 *               - GPIOC: select the GPIOC peripheral
 *               - GPIOD: select the GPIOD peripheral
 * @param  GPIO_Pin[in]:specifies the port bit to be read.
 *                   - GPIO_Pin_0:Pin 0 selected
 *                   - GPIO_Pin_1:Pin 1 selected
 *                   - GPIO_Pin_2:Pin 2 selected
 *                   - GPIO_Pin_3:Pin 3 selected
 *                   - GPIO_Pin_4:Pin 4 selected
 *                   - GPIO_Pin_5:Pin 5 selected
 *                   - GPIO_Pin_6:Pin 6 selected
 *                   - GPIO_Pin_7:Pin 7 selected
 *                   - GPIO_Pin_8:Pin 8 selected
 *                   - GPIO_Pin_9:Pin 9 selected
 *                   - GPIO_Pin_10:Pin 10 selected
 *                   - GPIO_Pin_11:Pin 11 selected
 *                   - GPIO_Pin_12:Pin 12 selected
 *                   - GPIO_Pin_13:Pin 13 selected
 *                   - GPIO_Pin_14:Pin 14 selected
 *                   - GPIO_Pin_15:Pin 15 selected
 *                   - GPIO_PIN_LNIB:Pin Low 8 Bits selected
 *                   - GPIO_PIN_HNIB:Pin High 8 Bits selected
 *                   - GPIO_PIN_All:All pins selected
  * @param  BitVal[in]: specifies the value to be written to the selected bit.
  *          This parameter can be one of the BitAction enum values:
 *            -  Bit_RESET: to clear the port pin
 *            -  Bit_SET: to set the port pin
  * @retval None
  */
void GPIO_WriteBit ( GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal )
{
    /* Check the parameters */
    assert_param ( IS_GPIO_ALL_PERIPH ( GPIOx ) );
    assert_param ( IS_GET_GPIO_PIN ( GPIO_Pin ) );
    assert_param ( IS_GPIO_BITACTION ( BitVal ) );

    if ( BitVal != Bit_RESET )
    {
        GPIOx->PIN |= GPIO_Pin;
    }
    else
    {
        GPIOx->PIN &= ( ~GPIO_Pin ) ;
    }
}

/**
 * @brief  Toggles the specified GPIO pins.
 * @param  GPIOx[in]: where x can be to select the GPIO peripheral.
 *                SC32f10xx Selection range(GPIOA - GPIOC)
 *                SC32f11xx Selection range(GPIOA - GPIOD)
 *                SC32f12xx Selection range(GPIOA - GPIOC)
 *                SC32f15xx Selection range(GPIOA - GPIOC)
 *               - GPIOA: select the GPIOA peripheral
 *               - GPIOB: select the GPIOB peripheral
 *               - GPIOC: select the GPIOC peripheral
 *               - GPIOD: select the GPIOD peripheral
 * @param  GPIO_Pin[in]:specifies the port bit to be read.
 *                   - GPIO_Pin_0:Pin 0 selected
 *                   - GPIO_Pin_1:Pin 1 selected
 *                   - GPIO_Pin_2:Pin 2 selected
 *                   - GPIO_Pin_3:Pin 3 selected
 *                   - GPIO_Pin_4:Pin 4 selected
 *                   - GPIO_Pin_5:Pin 5 selected
 *                   - GPIO_Pin_6:Pin 6 selected
 *                   - GPIO_Pin_7:Pin 7 selected
 *                   - GPIO_Pin_8:Pin 8 selected
 *                   - GPIO_Pin_9:Pin 9 selected
 *                   - GPIO_Pin_10:Pin 10 selected
 *                   - GPIO_Pin_11:Pin 11 selected
 *                   - GPIO_Pin_12:Pin 12 selected
 *                   - GPIO_Pin_13:Pin 13 selected
 *                   - GPIO_Pin_14:Pin 14 selected
 *                   - GPIO_Pin_15:Pin 15 selected
 *                   - GPIO_PIN_LNIB:Pin Low 8 Bits selected
 *                   - GPIO_PIN_HNIB:Pin High 8 Bits selected
 *                   - GPIO_PIN_All:All pins selected
 * @retval None
 */
void GPIO_TogglePins ( GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin )
{
    /* Check the parameters */
    assert_param ( IS_GPIO_ALL_PERIPH ( GPIOx ) );
    assert_param ( IS_GPIO_PIN ( GPIO_Pin ) );
    __IO uint32_t tmpreg = ( uint32_t ) GPIOx + ( 0x00000010UL );
    uint32_t temp = 0;
    /* Set the GPIOx PIN value  */
    while ( GPIO_Pin != 0 )
    {

        if ( GPIO_Pin & 0x0001 )
        {
            temp = ~ ( * ( ( uint8_t* ) ( tmpreg ) ) );
            ( * ( ( uint8_t* ) ( tmpreg ) ) ) = temp;
        }
        GPIO_Pin = GPIO_Pin >> 1;
        tmpreg++;
    }
}

/**
 * @}
 */
/* End of PWM_Group2.	*/

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/******************* (C) COPYRIGHT 2022 SinOne Microelectronics *****END OF FILE****/
