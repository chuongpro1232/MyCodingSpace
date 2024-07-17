#include <avr/io.h>

int main(void)
{
DDRC = 0xFF;
TCCR1B |= (1<<CS12) | (1<<CS10);
while (1){
  if(TCNT1 >= 15624){
    PORTC ^= (1<<2) | (1<<3) | (1<<4) | (1<<5);
    TCNT1 = 0;
  }
}
  

}
