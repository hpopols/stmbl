//
//  setup.h
//  test
//
//  Created by Rene on 09/12/13.
//  Copyright (c) 2013 Rene Hopf. All rights reserved.
//

#ifndef test_setup_h
#define test_setup_h

#include <stm32f4_discovery.h>
#include <stm32f4xx_conf.h>
#include "stm32_ub_dac_dma.h"
#include "stm32_ub_encoder_tim3.h"

#ifdef USBTERM
#include "stm32_ub_usb_cdc.h"
#endif

//#define mag_res 5250
#define mag_res 8400


// res in:
// ADC1: SIN: PA3 ADC1 IN3, ADC2 IN3, ADC3 IN3
// ADC2: COS: PB1 ADC1 IN9, ADC2 IN9
// TODO: RCC_AHB1PeriphClockCmd hardcoded in setup.c
#define RES_SIN_PIN GPIO_Pin_3
#define RES_SIN_PORT GPIOA
#define RES_SIN_CHANNEL ADC_Channel_3

#define RES_COS_PIN GPIO_Pin_1
#define RES_COS_PORT GPIOB
#define RES_COS_CHANNEL ADC_Channel_9

//sample times for F4: 3,15,28,56,84,112,144,480
#define RES_SampleTime ADC_SampleTime_144Cycles

void setup();
void setup_adc();
void setup_pwm();
void setup_pid_timer();
void SysTick_Handler(void);

volatile int time;

TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
TIM_OCInitTypeDef TIM_OCInitStructure;
NVIC_InitTypeDef NVIC_InitStructure;
GPIO_InitTypeDef GPIO_InitStructure;
DAC_InitTypeDef DAC_InitStructure;
DMA_InitTypeDef DMA_InitStructure;
ADC_InitTypeDef ADC_InitStructure;

#endif
