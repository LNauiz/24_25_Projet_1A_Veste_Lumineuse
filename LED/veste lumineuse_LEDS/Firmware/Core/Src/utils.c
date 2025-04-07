/*
 * utils.c
 *
 *  Created on: Apr 7, 2025
 *      Author: sidib
 */
#include "utils.h"


void PWM_Start(void)
{
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

void PWM_SetDutyCycle(uint16_t dutyCycle)
  {
    if (dutyCycle > __HAL_TIM_GET_AUTORELOAD(&htim1)) {
      dutyCycle = __HAL_TIM_GET_AUTORELOAD(&htim1);
    }

    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, dutyCycle);
  }
