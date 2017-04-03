#include "gpio.h"
#include "system_timer.h"
#include "uart.h"

void blink_once()
{
    // Turn on GPIO 24
    gpio[GPSET0] |= 1 << 24;

    timer_delay_ms(500);

    // Turn off GPIO 24
    gpio[GPCLR0] |= 1 << 24;

    timer_delay_ms(500);
}

int main()
{
	gpio[GPFSEL2] |= (1 << 12);
	
	while(1){
		
	}
    
    return 0;
}
