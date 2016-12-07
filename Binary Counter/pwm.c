#include<avr/io.h>
#include<util/delay.h>

void main() {
    int i;
	DDRD = 0b11111111;

	while(1) {
		for(i = 0; i < 3; i++) {
			PORTD = 0b00000001; //BEEP
			_delay_ms(100);
			PORTD = 0b00000000; //STOP
			_delay_ms(400);

			PORTD = 0b00000001; //BEEP
			_delay_ms(300);
			PORTD = 0b00000000; //STOP
			_delay_ms(100);
		}

		for(i = 0; i < 2; i++) {
			PORTD = 0b00000001; //BEEP
			_delay_ms(400);
			PORTD = 0b00000000; //STOP
			_delay_ms(100);
		}

		PORTD = 0b00000001; //BEEP
			_delay_ms(400);
			PORTD = 0b00000000; //STOP
			_delay_ms(500);
	}
}
