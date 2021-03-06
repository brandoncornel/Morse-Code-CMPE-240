#include "gpio.h"
#include "system_timer.h"
#include "uart.h"
#include "morse.h"


int main()
{
    /*
	* User enters string that they want to translate to Morse
	* each character in the string is then ran throught the translate function
	* where a dictionary converts the character into dots and dashes.
	*/
	gpio[GPFSEL2] |= 0x8;
    int counter = 0;
    const int bufferSize = 140;
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
		put_string("\r\n");
    
	}
	return 0;
}
