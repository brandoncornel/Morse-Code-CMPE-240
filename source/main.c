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

int main()
{
    // Implement Lab 4 as described in the lab manual
    int counter = 0;
    const int bufferSize = 80;
    char buffer [bufferSize];
    uint32_t w;
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t f;
    uint32_t g;
	uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
    uint32_t R1;
    uint32_t R2;
	

	while(1){
		put_string("Enter 1 or 2:");
		put_string("\r\n");
		char input = get_char();
		if (input == '1'){
			put_string("w x y z f g");
			put_string("\r\n");
	
			for(w=0; w<2;w++){
				for (x=0; x<2; x++){
					for (y=0;y<2; y++){
						for(z=0;z<2;z++){
							put_char(w|0x30);
							put_char(' ');
							put_char(x|0x30);
							put_char(' ');
							put_char(y|0x30);
							put_char(' ');
							put_char(z|0x30);
							put_char(' ');
							put_char(((!w&&!x&&!y&&!z)||(!w&&!x&&y&&!z)||(!w&&x&&!y&&!z)||(!w&&x&&y&&z)||(!w&&x&&y&&!z)||(w&&x&&!y&&z)||(w&&x&&y&&z)||(w&&x&&y&&!z)|(w&&!x&&!y&&z))|0x30);\
							put_char(' ');
							put_char(((!w&&!z)||(w&&!y&&z)||(x&&y))|0x30);
							put_string("\r\n");
						}
						
					}
				}
		
		
			}
		}
		else if(input == '2'){
			
			put_string("a b c d R1 R2");
			put_string("\r\n");
			for(a=0; a<2;a++){
				for (b=0; b<2; b++){
					for (c=0;c<2; c++){
						for(d=0;d<2;d++){
							put_char(a|0x30);
							put_char(' ');
							put_char(b|0x30);
							put_char(' ');
							put_char(c|0x30);
							put_char(' ');
							put_char(d|0x30);
							put_char(' ');
							put_char(((!b&!d)|(b&c))|0x30);
							put_char(' ');
							put_char(((!b&!d)|(c&!d))|0x30);
							put_string("\r\n");
						}
						
					}
				}
			}
		}
		//else{
		//	put_string("Please enter 1 or 2\r\n");
		
        
    
	}
	return 0;
}
