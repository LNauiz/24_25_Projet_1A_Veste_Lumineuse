/*
 * ws2812.h
 *
 *  Created on: May 19, 2025
 *      Author: sidib
 */

#ifndef INC_WS2812_H_
#define INC_WS2812_H_


#include "main.h"

#define LED_COUNT 8

void WS2812_SetPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
void WS2812_Refresh(void);
void WS2812_Clear(void);


#endif /* INC_WS2812_H_ */
