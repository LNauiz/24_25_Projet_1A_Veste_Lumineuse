/*
 * utils.c
 *
 *  Created on: May 12, 2025
 *      Author: leona
 */

#include <stdio.h>
#include "gpio.h"
#include "stm32g4xx_hal.h"

#include "adc.h"

#include <stdio.h>



float VMAX=5; //Tension Maximale de la batterie

int read_analog_input(void){

	uint32_t raw_value;
	uint32_t voltage;

	HAL_ADC_Start(&hadc1);

    if (HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY) == HAL_OK){
    	raw_value = HAL_ADC_GetValue(&hadc1);
    	voltage=raw_value*4.04/1596;

    	printf("Tension=%lu V\r\n", voltage);
    	return voltage;
    }

    return 0;
}

