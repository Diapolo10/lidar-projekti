/*
 * adc.h
 *
 * Created: 14/09/2021 13:49:33
 *  Author: Lari
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <atmel_start.h>

#define FREE_RUNNING 1
#define SINGLE_CONVERSION 2
#define WINDOW_COMPARATOR_MODE 3
#define SAMPLE_ACCUMULATOR 4

#define EXAMPLE_CODE FREE_RUNNING // WINDOW_COMPARATOR_MODE

#define MAX_VOL 2.5 // VREF=2.5V
#define RES_10BIT 0x3FF
#define ADC_CHANNEL 3 // Attn! 3 = pin PD03 at mcu, connected to Every header pin A0!

#define use_free_running() {ADC0.CTRLA |= 1 << ADC_FREERUN_bp; ADC_0_start_conversion(ADC_CHANNEL);}
#define use_adc_accumulator64() {ADC0.CTRLB = ADC_SAMPNUM_ACC64_gc}

extern uint16_t adc_result;
extern float    calc_volt;

void read_adc_single_conversion();
void read_adc_sample_accumulator();
void free_running();
void window_comparator_mode();

#endif /* ADC_H_ */
