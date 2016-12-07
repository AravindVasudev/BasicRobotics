#include<avr/io.h>
#include<util/delay.h>
void main()
{
   DDRD=0b00000000;     //setting part D as input port
   DDRB=0b11111111;     //setting paart D as output port
   PORTD=0b11111111;    //pilling up all the pins of part D
   int c;
   while(1)
   {
     c=PIND;
	 if(c==0b11110000)    //all sensors are on the table
	 PORTB=0b11111010;    //Move fwd
	 if(c==0b11111000)    //Sensor 1 is off the table
	 {
	   PORTB=0b11110101;  //Go back nd turn ryt
	   _delay_ms(300);
	   PORTB=0b11111001;
	   _delay_ms(300);
	 }
     if(c==0b11110100)    //Sensor 2 is off the table
     {
       PORTB=0b11110101;  //Go back and turn left
       _delay_ms(300);
       PORTB=0b11110110;
       _delay_ms(300);
     }
     if(c==0b11110010)   //Sensor 3 is off the table
     {
       PORTB=0b11111010; //Go fwd and turn right
       _delay_ms(300);
	   PORTB=0b11111001;
	   _delay_ms(300);
	 }
     if(c==0b11110001)   //Sensor 4 is off the table
     {
       PORTB=0b11111010; //Go fwd and turn right
       _delay_ms(300);
       PORTB=0b11110110;
       _delay_ms(300);
	 }
	 if(c == 0b11111100) //Sensors 1 and 2 are off the table
	 {
	   PORTB=0b11110101; //Go back and turn right
	   _delay_ms(300);
	   PORTB=0b11111001;
	   _delay_ms(300);
	 }
     if(c==0b11111001)    //Sensors 1 and 4 are off the table
		PORTB=0b11111001; //Turn right
     if(c==0b11110011)    //Sensors 3 and 4 are off the table
       PORTB=0b11111010;  //Go fwd
     if(c==0b11110110)    //Sensors 2 and 3 are off the table
		PORTB=0b11110110; //Turn left
     if(c==0b11111110)    //Sensors 1,2 and 3 are off the table
		PORTB=0b11110110; //Turn left
     if(c==0b11110111)    //Sensor 1 is on the table
		PORTB=0b11110110; //Turn left
     if(c==0b11111011)    //Sensor 2 is on the table
		PORTB=0b11111001; //Turn right
     if(c==0b11111101)    //Sensor 3 is on the table
		PORTB=0b11111001; //Turn right
    }
}
