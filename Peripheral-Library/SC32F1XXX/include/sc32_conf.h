/**
 ******************************************************************************
 * @file    sc32_conf.h
 * @author  SOC AE Team
 * @version V1.7
 * @date    17-10-2024
 * @brief   
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
#ifndef _sc32_CONF_H_
#define _sc32_CONF_H_
#include "sc32f1xxx.h"
#include "sc32f1xxx_rcc.h"
#include "sc32f1xxx_gpio.h"
#include "sc32f1xxx_iap.h"
#include "sc32f1xxx_adc.h"
#include "sc32f1xxx_cmp.h"
#include "sc32f1xxx_option.h"
#include "sc32f1xxx_int.h"
#include "sc32f1xxx_uart.h"
#include "sc32f1xxx_spi.h"
#include "sc32f1xxx_twi.h"
#include "sc32f1xxx_wdt.h"
#include "sc32f1xxx_btm.h"
#include "sc32f1xxx_crc.h"
#if !defined(SC32f15xx)
#include "sc32f1xxx_pwm.h"
#include "sc32f1xxx_ledpwm.h"
#include "sc32f1xxx_lcd.h"
#include "sc32f1xxx_led.h"
#endif
#include "sc32f1xxx_tim.h"
#include "sc32f1xxx_dma.h"
#include "sc32f1xxx_pwr.h"
#if defined(SC32f11xx)
#include "sc32f1xxx_pga.h"
#include "sc32f1xxx_can.h"	
#endif
#if defined(SC32f12xx)
#include "sc32f1xxx_op.h"	
#endif
#if defined(SC32f15xx)
#include "sc32f1xxx_dac.h"	
#include "sc32f1xxx_can.h"
#include "sc32f1xxx_temper.h"
#include "sc32f1xxx_spi1_twi1.h"
#include "sc32f1xxx_op.h"
#include "sc32f1xxx_qep.h"
#include "sc32f1xxx_vref.h"
#endif
#endif

