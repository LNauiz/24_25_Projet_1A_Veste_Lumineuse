/*
 * ws2812.c
 *
 *  Created on: May 19, 2025
 *      Author: sidib
 */


#include "ws2812.h"

extern TIM_HandleTypeDef htim1;

#define TIMER_CLOCK 84000000
#define WS2812_FREQ 800000
#define TIMER_PERIOD (TIMER_CLOCK / WS2812_FREQ)

#define HIGH_TIME (TIMER_PERIOD * 2 / 3)
#define LOW_TIME  (TIMER_PERIOD * 1 / 3)

static uint16_t pwm_data[LED_COUNT * 24 + 50];
static uint8_t led_buffer[LED_COUNT][3];

void WS2812_SetPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b)
{
    if (n < LED_COUNT) {
        led_buffer[n][0] = g;
        led_buffer[n][1] = r;
        led_buffer[n][2] = b;
    }
}

void WS2812_Refresh(void)
{
    uint32_t indx = 0;

    for (int i = 0; i < LED_COUNT; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 7; k >= 0; k--) {
                if (led_buffer[i][j] & (1 << k))
                    pwm_data[indx++] = HIGH_TIME;
                else
                    pwm_data[indx++] = LOW_TIME;
            }
        }
    }

    for (int i = 0; i < 50; i++) {
        pwm_data[indx++] = 0;
    }

    HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_1, (uint32_t *)pwm_data, indx);
    HAL_Delay(1);
}

void WS2812_Clear(void)
{
    for (int i = 0; i < LED_COUNT; i++) {
        WS2812_SetPixelColor(i, 0, 0, 0);
    }
}

void WS2812_SendColorArray(uint8_t *colors, uint16_t len)
{
    uint16_t led_count = len / 3;
    if (led_count > LED_COUNT)
        led_count = LED_COUNT;

    for (uint16_t i = 0; i < led_count; i++) {
        WS2812_SetPixelColor(i, colors[3 * i], colors[3 * i + 1], colors[3 * i + 2]);
    }

    WS2812_Refresh();
}



