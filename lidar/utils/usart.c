/*
 * usart.c
 *
 * Created: 14/09/2021 14:00:31
 *  Author: Lari
 */ 
#include "usart.h"

// USART Functions
/**
 * \brief Write a string on USART
 */
void usart_put_string(const char str[], const uint8_t STR_LEN)
{
    for (int i = 0; i < STR_LEN; i++) {
        USART_0_write(str[i]);
    }
}

// USART print float number
void usart_send_float(float number)
{
    char string[6];

    dtostrf(number, 2, 3, string);
    usart_put_string(string, 5);
    usart_put_string("V\n", 2);
}
