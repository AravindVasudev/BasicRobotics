#include<avr/io.h>
#include<util/delay.h>

void main()
{
   DDRD=0b00000000;   //setting PARTD as an input part
   DDRB=0b11111111;   //setting PARTB as an output part
   PORTD=0b11111111;  //pulling up all the pins of PARTD
   int c;
   while(1)
   {
      c=PIND;
	  if(c==0b11111111)      //No Obstacle
	     PORTB=0b00001010;   //Forward
	  if(c==0b11111110)     //obstacle to the right
         PORTB=0b00000110;  //Turn Left
      if(c==0b11111101)     //obstacle at the centre
      {
        PORTB=0b00000101;   //Go Back and Turn right
        _delay_ms(300);
        PORTB=0b00001001;
        _delay_ms(200);
      }
	  if(c==0b11111100)     //obstacle to the centre and right
	  {
	    PORTB=00000101;     //Go back and Turn Left
		_delay_ms(300);
		PORTB=0b00000110;
		_delay_ms(200);
	  }
      if(c==0b11111011)    //obstacle to the left
        PORTB=0b00001001;  //Turn right
      if(c==0b11111010)    //obstacle to both left and right
      {
        PORTB=0b00000101;  //Go Back and Turn Right
        _delay_ms(300);
        PORTB=0b00001001;
        _delay_ms(200);
      }
      if(c==0b11111001)    //Obstacle on the left and centre
      {
        PORTB=0b00000101;  //Go Back and Turn Right
        _delay_ms(300);
        PORTB=0b00001001;
        _delay_ms(200);
      }
      if(c==0b11111000)    //Obstacle on all sides
      {
        PORTB=0b00000101;  //U turn
        _delay_ms(300);
        PORTB=0b00001001;
        _delay_ms(1500);
      }
    }
}
