#include "gpio.h"
#include "system_timer.h"
#include "uart.h"

void blink_once()
{
    gpio[GPSET0] |= 1 << 23;

	timer_delay_ms(500);

	gpio[GPCLR0] |= 1 << 23;

	timer_delay_ms(500);

}

void blink_code(uint32_t err)
{
    for(int i = 0; i < err; ++i)
    {
        // Blink the LED
		blink_once();

    }

    // Delay for desired time
	timer_delay_sec(5);
    
}

int main()
{
    // Init GPIO select for external LED
	gpio[GPFSEL2] = 0x1000;

    // Init uart for debugging purposes
	init_uart();

    // Provide a buffer size for debug prints

    // You might need a count for something
    uint32_t blink_count = 1;

	put_string("Running\n\0");

    // Mainline loop
    while (1)
    {
        // implement error code described in lab
		if(blink_count <= 10){
			put_string("Blink\n\0");
			blink_code(blink_count);
			blink_count++;
		}
		else{
			blink_count = 1;
		}
    }
    
    return 0;
}
