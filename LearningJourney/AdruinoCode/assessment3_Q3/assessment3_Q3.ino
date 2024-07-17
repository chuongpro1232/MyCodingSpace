#include <avr/io.h>
#include <avr/interrupt.h>
volatile bool halfsec_elapsed = false;
volatile bool waveformEnabled = false;

int main(void)
{
	DDRD &= ~(1 << DDD2) ; // Clear PD2 pins for interrupt 0
	DDRB |= (1 << 0)|(1 << 1); // Set LED as output 

  EIMSK |= (1<<INT0); //enable PORTD2 as external interrupt
  EICRA |= (1<<ISC01); // Detect on falling edge
  EIFR |= (1<<INTF0); // Clear flag
  
  TCCR1B |= (1 << WGM12); // Turn on the CTC mode for Timer 1
  TCCR1B |= (1 << CS12);
  OCR1A = 18749;    // Set CTC compare value to 5Hz at 16 MHz AVR clock , with a prescaler of 256

	sei();
  int count = 0;
    int count1 = 0;
  
  // Enable timer overflow interrupt
				//Enable the Global Interrupt Bit
	while (1)
	{
    if (waveformEnabled){
      PORTB ^= (1 << 1);
      PORTB &= ~(1<<0);      // button_pressed 1 pressed      
        while (count < 34) { // pattern 2 flashes as 5Hz frequency 16 times
          if (halfsec_elapsed)
          { 
            if (PINB & (1 << 0 )||count==0 || count==33)
            { 
              PORTB &=~ (1 << 0);  
            }
            else 
            {
              PORTB ^= (1 << 0);         
            }
          count++;
          halfsec_elapsed = false;
        }
      }     // reset count value
      count = 0;
    waveformEnabled = false;
    }   
    PORTB &= ~(1<<0);
    PORTB &=~ (1<<1);
    
      
  }
}
ISR(INT0_vect)
{  
  //PORTB ^= (1 << 1);
  waveformEnabled = true;
  TCNT1 = 0;  
  TIMSK1 = 1<<OCIE1A;  
  //PORTB &= ~(1<<0); 
}
ISR ( TIMER1_COMPA_vect )
{
  halfsec_elapsed = true; 
}






