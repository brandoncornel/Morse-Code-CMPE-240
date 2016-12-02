#include "gpio.h"
#include "system_timer.h"
#include "uart.h"
#include "morse.h"

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

int main()
{
    // Implement Lab 4 as described in the lab manual
    int counter = 0;
    const int bufferSize = 200;
    char buffer [bufferSize];
	while(1){
		put_string("Enter the sentence you want in morse code:");
		put_string("\r\n");
		size_t charsGot = get_string(buffer, bufferSize);
		timer_delay_sec(2);
		for(size_t i = 0;i < charsGot;i++){
			char ch = buffer[i];
			translate(ch);
		}
		//translate(input);
	
		
        
    
	}
	return 0;
}
