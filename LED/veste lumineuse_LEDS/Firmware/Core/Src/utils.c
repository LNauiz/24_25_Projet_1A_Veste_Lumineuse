/*
 * utils.c
 *
 *  Created on: Apr 71, 2025
 *      Author: sidib
 */
#include "utils.h"
#include "tim.h"

#define LED_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_8

#define LED_NUMBER 8
#define BITARRAY_SIZE 8*3*24+1

#define T1H 800  // ns
#define T1L 450  // ns
#define T0H 400  // ns
#define T0L 850  // ns
#define RES 60000 // ns

static uint16_t bitarray[BITARRAY_SIZE] = 	{
		127,127,127,127,127,127,127,127,
		71,71,71,71,71,71,71,71,
		71,71,71,71,71,71,71,71,
		127,127,127,127,127,127,127,127,
		71,71,71,71,71,71,71,71,
		71,71,71,71,71,71,71,71,
		127,127,127,127,127,127,127,127,
		71,71,71,71,71,71,71,71,
		71,71,71,71,71,71,71,71,
		127,127,127,127,127,127,127,127,
		71,71,71,71,71,71,71,71,
		71,71,71,71,71,71,71,71,
		127,127,127,127,127,127,127,127,
		71,71,71,71,71,71,71,71,
		71,71,71,71,71,71,71,71,
		127,127,127,127,127,127,127,127,
		71,71,71,71,71,71,71,71,
		71,71,71,71,71,71,71,71,
		127,127,127,127,127,127,127,127,
		71,71,71,71,71,71,71,71,
		71,71,71,71,71,71,71,71,
		127,127,127,127,127,127,127,127,
		71,71,71,71,71,71,71,71,
		71,71,71,71,71,71,71,71,
		0
};

void Delay_NS(uint32_t ns)
{
	// approximation: 1 instruction ~ 1 cycle @ 64MHz = 15.625ns
	volatile uint32_t count = (ns / 15);
	while (count--) {
		__NOP();
	}
}

//void WS2812_WriteBit(uint8_t bit)
//{
//    if (bit) {
//        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
//        Delay_NS(T1H);
//        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
//        Delay_NS(T1L);
//    } else {
//        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
//        Delay_NS(T0H);
//        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
//        Delay_NS(T0L);
//    }
//}
//
//void WS2812_SendByte(uint8_t byte)
//{
//    for (int i = 71; i >= 0; i--) {
//        WS2812_WriteBit((byte >> i) & 0x01);
//    }
//}

void WS2812_SendColor(uint8_t r, uint8_t g, uint8_t b)
{
	//    WS2812_SendByte(g);
	//    WS2812_SendByte(r);
	//    WS2812_SendByte(b);

	// remplir le tableau
	// 127 pour un 1,
	// 71 pour un 0


	HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_1, (uint32_t*)bitarray, 24);
	HAL_Delay(20);
}
//
////void WS2812_SendColorArray(uint8_t *colors, uint16_t len)
//{
////	__disable_irq();
//
//	for (uint16_t i = 0; i < len; i += 3) {
//		WS2812_SendColor(colors[i], colors[i + 1], colors[i + 2]);
//	}
//
////	__enable_irq();
////	Delay_NS(RES);
//}

//
//void PWM_Start(void)
//{
//  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//}
//
//void PWM_SetDutyCycle(uint16_t dutyCycle)
//  {
//    if (dutyCycle > __HAL_TIM_GET_AUTORELOAD(&htim1)) {
//      dutyCycle = __HAL_TIM_GET_AUTORELOAD(&htim1);
//    }
//
//    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, dutyCycle);
//  }
