#include <avr/io.h>
// #include <avr/interrupt.h>
int main(void)
{
DDRB |= ( 1 << 5) ; // Set LED as out put
TCCR0A |= (1 << WGM01) ; // Tur n on t he CTC mode f or Ti mer 1
TCCR0B |= (1 << CS01 ) | (1 << CS00) ; // Set up Ti mer 1 wi t h t he pr escal er of 64
OCR0A = 124; // Set CTC compar e val ue t o 1Hz at 16 MHz AVR cl ock , wi t h a pr escal er of 256
TIMSK0 = 1 << OCIE0A; // Enabl e Out put Compar e A Mat ch I nt er r upt
sei () ; // Enabl e t he Gl obal I nt er r upt Bi t
while (1)
{
}
}
ISR ( TIMER0_COMPA_vect)
{
PORTB ^= ( 1 << 5) ; // Toggl e t he LED
}
