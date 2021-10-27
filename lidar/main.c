#include <atmel_start.h>
#include <util/delay.h>

#include "adc.h"
#include "usart.h"
#include "debug.h"

uint16_t adc_result = 0;
float    calc_volt;
bool     use_led = false;

int main(void)
{
    /* Initializes MCU, drivers and middleware */
    atmel_start_init();

#if EXAMPLE_CODE == FREE_RUNNING
    {
        use_free_running();
    }
#elif EXAMPLE_CODE == SAMPLE_ACCUMULATOR
    {
        use_adc_accumulator64();
    }
#elif EXAMPLE_CODE == WINDOW_COMPARATOR_MODE //will be run in free running mode
    {
        ADC_0_set_window_low(0x100);
        ADC_0_set_window_mode(ADC_WINCM_BELOW_gc);
        ADC0.CTRLA |= 1 << ADC_FREERUN_bp;
        ADC_0_start_conversion(ADC_CHANNEL);
    }
#endif

    /* Replace with your application code */
    while (1) {

#if EXAMPLE_CODE == SINGLE_CONVERSION
        {
            read_adc_single_conversion();
        }
#elif EXAMPLE_CODE == FREE_RUNNING
        {
            free_running();
        }
#elif EXAMPLE_CODE == WINDOW_COMPARATOR_MODE
        {
            window_comparator_mode();
        }
#elif EXAMPLE_CODE == SAMPLE_ACCUMULATOR
        {
            read_adc_sample_accumulator();
        }
#endif

        /* Print calc_volt to terminal. */
        /* Add carriage return as it is not done by usart_send_float() */
        printf("\rADC CH%d: ", ADC_CHANNEL);
        usart_send_float(calc_volt);

        /* Toggles LED0 in 3 application cases, except in WINDOW_COMPARATOR_MODE */
        if (EXAMPLE_CODE != WINDOW_COMPARATOR_MODE) {
            LED_D13_toggle_level();
        }
        else {
            /* LED0 is ON when ADC result is below the predefined window value */
            _DEBUG_INFO("Set LED value");
            LED_D13_toggle_level();
        }
        _delay_ms(500);
    }
}
