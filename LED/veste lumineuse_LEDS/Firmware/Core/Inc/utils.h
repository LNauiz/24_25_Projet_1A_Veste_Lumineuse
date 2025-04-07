/*
 * utils.h
 *
 *  Created on: Apr 7, 2025
 *      Author: sidib
 */

#ifndef INC_UTILS_H_
#define INC_UTILS_H_

#include "main.h"  // nécessaire pour accéder à htim1 et les fonctions HAL

void PWM_Start(void);
void PWM_SetDutyCycle(uint16_t dutyCycle);

#endif /* INC_UTILS_H_ */


