#include<avr/io.h>
#include<util/delay.h>

void main() {
  DDRB = 0b11111111;
  
  while(1) {
    PORTB = 0b00001010;
  }
}