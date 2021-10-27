/*
 * usart.h
 *
 * Created: 14/09/2021 14:00:45
 *  Author: Lari
 */ 


#ifndef USART_H_
#define USART_H_

#include <atmel_start.h>

void usart_put_string(const char str[], const uint8_t STR_LEN);
void usart_send_float(float number);

#endif /* USART_H_ */
