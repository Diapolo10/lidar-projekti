/*
 * adc.c
 *
 * Created: 14/09/2021 13:49:49
 *  Author: Lari
 */ 
#include "adc.h"

void read_adc_single_conversion()
{
    adc_result = ADC_0_get_conversion(ADC_CHANNEL);
    calc_volt  = (adc_result * MAX_VOL) / RES_10BIT;
}

void read_adc_sample_accumulator()
{
    adc_result = ADC_0_get_conversion(ADC_CHANNEL);
    adc_result = adc_result >> 6; // divide by 64
    calc_volt  = (adc_result * MAX_VOL) / RES_10BIT;
}

void free_running()
{
    if (ADC_0_is_conversion_done()) {
        adc_result = ADC0.RES;
        calc_volt  = (adc_result * MAX_VOL) / RES_10BIT;
    }
}

void window_comparator_mode()
{
    if (ADC_0_is_conversion_done()) {
        adc_result = ADC0.RES;
        calc_volt  = (adc_result * MAX_VOL) / RES_10BIT;
    }
}
