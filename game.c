#include<avr/io.h>
#include<util/delay.h>
void init_adc()

{
 ADCSRA=ADCSRA|(0b00000001<<ADEN);
ADCSRA=ADCSRA|(0b00000001<<ADPS2);
ADMUX=ADMUX|(0b00000001<<REFS0);
}
unsigned int read_adc1()
{
 int p=0b00000000;
ADMUX&=0b11111000;
ADMUX=ADMUX|p;
ADCSRA|=(1<<ADSC);
while((ADCSRA&(0b00000001<<ADIF))==0)
{}
ADCSRA=ADCSRA|(0b00000001<<ADIF);
return(ADC);

}
unsigned int read_adc2()
{ 
int q =0b00000001;
ADMUX&=0b11111000;
ADMUX=ADMUX|q;
ADCSRA|=(1<<ADSC);
while((ADCSRA&(0b00000001<<ADIF))==0)
{}
ADCSRA=ADCSRA|(0b00000001<<ADIF);
return(ADC);
}


void main()

{ DDRD=0b00000000;
  DDRB=0b11111111;
  PORTD=0b11111111;
  int c;
  
init_adc();
_delay_ms(50);
unsigned int a;
unsigned int p;
unsigned int q;
unsigned int T;
unsigned int TON;
unsigned int TOFF;

  while (1)
  { 
    c=PIND;
	if(c==0b11111101)         
	   PORTB=0b00001001; 
      
	if(c==0b11111110)          
	   PORTB=0b00000110;
         
	if(c==0b11111100)          
	   PORTB=0b00001010;
       
	if(c==0b11111111)          
	   PORTB=0b00011010;
	   
    if(c==0b11111001)
        PORTB=0b00011111;
		
    if(c==0b11111010)
        PORTB=0b00011111;
		
    if(c==0b11111000)
        PORTB=0b00011111;
		
    if(c==0b11111011)
        PORTB=0b00011111;  

p=read_adc1();
q=read_adc2();
a=(q/40);
T=25.6;
TOFF=a;
TON=T-TOFF;
    if (P<952)
	{
	if(c==0b11111101)         
	   PORTB=0b00001001; 
      
	if(c==0b11111110)          
	   PORTB=0b00000110;
         
	if(c==0b11111100)          
	   PORTB=0b00001010;
       
	if(c==0b11111111)          
	   PORTB=0b00011010;
	   
    if(c==0b11111001)
        PORTB=0b00011111;
		
    if(c==0b11111010)
        PORTB=0b00011111;
		
    if(c==0b11111000)
        PORTB=0b00011111;
		
    if(c==0b11111011)
        PORTB=0b00011111; 

}
    
else 
{ 
if(c==0b11111101)         
	   PORTB=0b00001001; 
	   delay_ms(TON);
PORTB=0b00000000;
_delay_ms(TOFF);

      
	if(c==0b11111110)          
	   PORTB=0b00000110;
         delay_ms(TON);
PORTB=0b00000000;
_delay_ms(TOFF);

	if(c==0b11111100)          
	   PORTB=0b00001010;
	   delay_ms(TON);
PORTB=0b00000000;
_delay_ms(TOFF);

       
	if(c==0b11111111)          
	   PORTB=0b00011010;
	   delay_ms(TON);
PORTB=0b00000000;
_delay_ms(TOFF);

	   
    if(c==0b11111001)
        PORTB=0b00011111;
		delay_ms(TON);
PORTB=0b00000000;
_delay_ms(TOFF);

		
    if(c==0b11111010)
        PORTB=0b00011111;
		delay_ms(TON);
PORTB=0b00000000;
_delay_ms(TOFF);

		
    if(c==0b11111000)
        PORTB=0b00011111;
		delay_ms(TON);
PORTB=0b00000000;
_delay_ms(TOFF);

		
    if(c==0b11111011)
        PORTB=0b00011111;
delay_ms(TON);
PORTB=0b00000000;
_delay_ms(TOFF);


} 


   } 
}