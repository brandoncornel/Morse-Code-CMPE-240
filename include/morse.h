#define MORSE_H_

extern const char *morse_translate(const char c);
extern void lower_string(char chr);
extern void translate(const char str);
void blink(const char* character);
void dit();
void dah();