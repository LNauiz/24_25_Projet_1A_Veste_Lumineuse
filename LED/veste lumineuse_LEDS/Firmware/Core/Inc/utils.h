/*
 * utils.h
 *
 *  Created on: Apr 7, 2025
 *      Author: sidib
 */

#ifndef INC_UTILS_H_
#define INC_UTILS_H_

//#include "main.h"
//#include "stm32g4xx_hal.h"
//
//extern TIM_HandleTypeDef htim1;
//
//
//// void PWM_Start(void);
//void PWM_SetDutyCycle(uint16_t dutyCycle);
//void PWM_Start(TIM_HandleTypeDef *htim, uint32_t channel);



#include "stm32g4xx_hal.h"

void WS2812_SendColor(uint8_t r, uint8_t g, uint8_t b);
void WS2812_SendColorArray(uint8_t *colors, uint16_t len);
void Delay_NS(uint32_t ns);


#endif /* INC_UTILS_H_ */


