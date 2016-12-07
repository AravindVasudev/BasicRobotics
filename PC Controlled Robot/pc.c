#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 1000000UL // CPU Clock Frequency
#define BAUDRATE 4800 //UART baud rate
#define MYUBRR ( (F_CPU / (BAUDRATE * 16UL) ) - 1 ) //Calculates UBRRH & UBRRL Register Value



//Initialize UART
void uart_init() {

  //Setting Baud Rate
  UBRRH = MYUBRR >> 8;
  UBRRL = MYUBRR;

  //Enable Reciever & Transmitter
  UCSRB |= (1 << RXEN) | (1 << TXEN);

  //Setting reciever to recieve 8bit data, no parity and one stop bit
  UCSRC |= (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

//Receive Data
unsigned int uart_recieve() {
  //Wait while data is being recieved
  while(!(UCSRA & (1 << RXC)));

  return UDR;
}

int main() {
  unsigned char value;

  //Setting Part B as Output for Motor Driver
  DDRB = 0b11111111;

  //Initialize UART
  uart_init();
  _delay_ms(50);

  //Repeating code(LOOP)
  while(1) {
    //Recieve value from UART
    value = uart_recieve();

	if(value == 'w') PORTB = 0b00001010; //Move Forward

	else if(value == 's') {
		PORTB = 0b0000101; //Move Reverse
	}

	else if(value == 'a') PORTB = 0b00000110; //Move Left

	else if(value == 'd') PORTB = 0b00001001; //Move Right

	else PORTB = 0b00000000; //Stop

    UDR = 'z'; //Clearing recieved value
  }
  return 0;
}

