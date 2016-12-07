#include<avr/io.h>
#include<util/delay.h>

void init_adc() {
  ADCSRA |= (0b00000001 << ADEN);
  ADCSRA |= (0b00000001 << ADPS2);
  ADMUX |= (0b00000001 << REFS0);
}

unsigned int read_adc() {
  int p = 0b00000000;
  int ret;
  int c;

  ADMUX |= p;
  ADCSRA |= (0b00000001 << ADSC);
  while(!(ADCSRA & (0b00000001 << ADIF)));
  ADCSRA |= (0b00000001 << ADIF);

  return ADC;

}

void main() {
  DDRB = 0b11111111;
  DDRD = 0b00000000; //Setting PORT D as Input
  PORTD = 0b11111111; //Pulling Up PORT D

  int c;
  init_adc();

  _delay_ms(500);
  unsigned int a;
  unsigned int p;

  unsigned int T;
  unsigned int TON;
  unsigned int TOFF;

  while(1) {
	c = PIND;

	if(c & (1 << PD3) >>PD3)
		p = read_adc();
	else
		p = 250;

    a = (p / 40);

    T = 25.6;

    TON = a;

    TOFF = T - TON;

    PORTB = 0b00001010;
    _delay_ms(TON);
    PORTB = 0b00000000;
    _delay_ms(TOFF);
  }
}
