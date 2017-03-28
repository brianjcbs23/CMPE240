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

void blink_code(uint32_t err)
{
    for(int i = 0; i < err; ++i)
    {
        blink_once();
    }

    // Only delay 4 seconds, since we delay for 1 additional
    // second in blink_once().
    timer_delay_ms(4500);
}

uint32_t W(uint32_t i){
	return (i & (1<<3))>>3;
}

uint32_t X(uint32_t i){
	return (i & (1<<2))>>2;
}

uint32_t Y(uint32_t i){
	return (i & (1<<1))>>1;
}

uint32_t Z(uint32_t i){
	return (i & (1<<0))>>0;
}

uint32_t not(uint32_t i){
	return (i & (1<<0))^(1);
}

uint32_t BE1F(uint32_t i){
	return (not(W(i)) & not(X(i)) & not(Y(i)) & not(Z(i))) |
	(not(W(i)) & not(X(i)) & Y(i) & not(Z(i))) |
	(not(W(i)) & X(i) & not(Y(i)) & not(Z(i))) |
	(not(W(i)) & X(i) & Y(i) & Z(i)) |
	(not(W(i)) & X(i) & Y(i) & not(Z(i))) |
	(W(i) & X(i) & not(Y(i)) & Z(i)) |
	(W(i) & X(i) & Y(i) & Z(i)) |
	(W(i) & X(i) & Y(i) & not(Z(i))) |
	(W(i) & not(X(i)) & not(Y(i)) & Z(i));
}

uint32_t BE1G(uint32_t i){
	return (not(W(i)) & not(Z(i))) | (W(i) & not(Y(i)) & Z(i)) | (X(i) & Y(i));
}

uint32_t BE2F(uint32_t i){
	return ((not(X(i)) & not(Z(i))) | (Y(i) & not(Z(i))));
}

uint32_t BE2G(uint32_t i){
	return ((not(X(i)) & not(Z(i))) | (X(i) & Y(i)));
}

void printBE1(uint32_t i){
	put_char(W(i) | 0x30);
	put_string(" \0");
	put_char(X(i) | 0x30);
	put_string(" \0");
	put_char(Y(i) | 0x30);
	put_string(" \0");
	put_char(Z(i) | 0x30);
	put_string(" | \0");
	put_char(BE1F(i) | 0x30);
	put_string(" \0");
	put_char(BE1G(i) | 0x30);
	put_string("\n\r\0");
}

void printBE2(uint32_t i){
	put_char(W(i) | 0x30);
	put_string(" \0");
	put_char(X(i) | 0x30);
	put_string(" \0");
	put_char(Y(i) | 0x30);
	put_string(" \0");
	put_char(Z(i) | 0x30);
	put_string(" | \0");
	put_char(BE2F(i) | 0x30);
	put_string(" \0");
	put_char(BE2G(i) | 0x30);
	put_string("\n\r\0");
}

int main()
{
	init_uart();
	
	put_string("W X Y Z | F G - Equivalence 1\n\r\0");
	uint32_t i = 0;
	while(i < 16){
		printBE1(i);
		++i;
	}
	put_string("\n\r\0");
	put_string("W X Y Z | F G - Equivalence 2\n\r\0");
	i = 0;
	while(i < 16){
		printBE2(i);
		++i;
	}
    
    return 0;
}
