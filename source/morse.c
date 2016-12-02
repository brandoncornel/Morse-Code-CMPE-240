#include "gpio.h"
#include "uart.h"
#include "morse.h"
#include "system_timer.h"

extern const char *morse_translate(const char c) {
  char ch;
  ch = lower_string(c);
  switch(ch) {
  case 'a':
    return ".-";
  case 'b':
    return "-...";
  case 'c':
    return "-.-.";
  case 'd':
    return "-..";
  case 'e':
    return ".";
  case 'f':
    return "..-.";
  case 'g':
    return "--.";
  case 'h':
    return "....";
  case 'i':
    return "..";
  case 'j': 
    return ".---";
  case 'k':
    return "-.-";
  case 'l':
    return ".-..";
  case 'm':
    return "--";
  case 'n':
    return "-.";
  case 'o':
    return "---";
  case 'p':
    return ".--.";
  case 'q':
    return "--.-";
  case 'r':
    return ".-.";
  case 's':
    return "...";
  case 't':
    return "-";
  case 'u':
    return "..-";
  case 'v':
    return "...-";
  case 'w':
    return ".--";
  case 'x':
    return "-..-";
  case 'y':
    return "-.--";
  case 'z':
    return "--..";
  case '0':
    return "-----";
  case '1':
    return ".----";
  case '2':
    return "..---";
  case '3':
    return "...--";
  case '4':
    return "....-";
  case '5':
    return ".....";
  case '6':
    return "-....";
  case '7':
    return "--...";
  case '8':
    return "---..";
  case '9':
    return "----.";
  case ' ':
	return " ";
  default:
    return "#";
  }

}

void blink(const char* character){
	
  do {
    switch(*character) {
    case '.':
      dit();
      break;
    case '-':
      dah();
      break;
	case ' ':
	  end_of_word();
	  break;
    default:
      break;
    }
  } while(*character++);
  end_of_char();
}

void dit(){
	gpio[GPFSEL2] |= 0x8;
	// Turn on LED
    gpio[GPSET0] |= 1 << 21;
    timer_one_unit();
	
    // Turn off LED
    gpio[GPCLR0] |= 1 << 21;
    timer_one_unit();
}

void dah(){
	gpio[GPFSEL2] |= 0x8;
	// Turn on LED
    gpio[GPSET0] |= 1 << 21;
    timer_three_unit();
	
    // Turn off LED
    gpio[GPCLR0] |= 1 << 21;
    timer_one_unit();
}

extern char lower_string(char chr){
	if(chr>='A' && chr<='Z'){
		chr = chr + 32;
	}
  return chr;
}



extern void translate(const char str){
	const char * character = morse_translate(str);
	put_string(character);
	blink(character);

	
}