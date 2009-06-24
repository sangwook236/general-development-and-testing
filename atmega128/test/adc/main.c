#include "adc.h"
#include "usart.h"
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <util/delay.h>


void system_init()
{
 	/*
	 *	ADC
	 */
	set_sleep_mode(SLEEP_MODE_ADC);  // ADC noise reduction mode

 	/*
	 *	analog comparator
	 */
	ACSR &= ~(_BV(ACIE));  // analog comparator interrupt disable
	ACSR |= _BV(ACD);  // analog comparator disable

	/*
	 *	I/O port
	 */
	DDRA = 0xFF;  // uses all pins on PortA for output
}

int main(void)
{
	cli();
	system_init();
	adc_init();
	usart0_init();
	sei();

	for (;;)
	{
		//sleep_mode();
		adc_start();

		while (!adc_is_complete()) ;

		uint16_t result = ADCL;
		result |= (ADCH << 8);

		PORTA = (result & 0xFF);

		//usart0_push_char(hex2ascii((result >> 12) & 0x0F));
		usart0_push_char(hex2ascii((result >> 8) & 0x03));
		usart0_push_char(hex2ascii((result >> 4) & 0x0F));
		usart0_push_char(hex2ascii(result & 0x0F));
		usart0_push_char(' ');

		adc_reset_complete();

		// a maximal possible delay time is (262.14 / Fosc in MHz) ms
		// if Fosc = 16 MHz, a maximal possible delay time = 16.38375 ms
		//	100 ms -> 10 ms * 50 count
		for (int i = 0; i < 10; ++i)
			_delay_ms(10);
	}

	return 0;
}

