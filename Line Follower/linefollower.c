#include<avr/io.h>
#include<util/delay.h>

void main() {
	DDRD  = 0b00000000; //Setting Part D as Input
	DDRB  = 0b11111111; //Setting Part B as Output
	PORTD = 0b11111111; //Pulling up Part D

	int c;

	while(1){
		c = PIND; //Reading Input from Part D

		if(c == 0b11111100)
			PORTB=0b11101010; //Move Forward

		if(c == 0b11111101)
			PORTB=0b11101001; //Take Right

		if(c == 0b11111110)
			PORTB=0b11100110; //Take Left

		if(c == 0b11111111)
			PORTB=0b11101010; //Take forward

	}
}
