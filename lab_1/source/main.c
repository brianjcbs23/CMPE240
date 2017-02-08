/** 
* Lab 1 - GPIO Blinky
* - Drive an LED by GPIO
* - Developer - 
* - Date - 
* 
*/
#include "gpio.h"

// Write a function that will delay for n loops
// to satisfy timing constraints given in lab. 
// ....beware compiler optimization....
void delay(uint32_t count)
{
	while (count){
		count--;
	}
}

int main()
{
	gpio[GPFSEL2] = 0x1000;
	
	//gpio[GPSET0] |= 0x40000;
	//gpio[GPCLR0] |= 0x40000;
    while (1)
    {       
        gpio[GPSET0] |= 1 << 23;
        
        delay(375000);
        
        gpio[GPCLR0] |= 1 << 23;
        
        delay(375000);
    }
    
    return 0;
}
