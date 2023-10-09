#include "I2C.h"
#include "MPL3115A2.h"
#include "uart.h"

#include <util/delay.h>

#define MILBAR_TO_INHG 0.02953 / 6400.0 
#define TWENTY_SECONDS 20000

int main(void) {

	USART_Init(9600);

	TWIInit(10000);
	while(init_MPL3115A2() != 1);	//setting up press sensor registers

	uint32_t pressure_meas;
	float pressure_meas_f;
	
	while (1) {
		pressure_meas = get_pressure_millibar();
		pressure_meas_f = (float) pressure_meas * MILBAR_TO_INHG;

		USART_Transmit_Float(pressure_meas_f);

		_delay_ms(TWENTY_SECONDS);
	
	}