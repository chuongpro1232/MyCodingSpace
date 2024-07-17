#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
// speed variables
volatile int tick = 1;
volatile bool first_interval_flag = false;
volatile bool second_interval_flag = false;
volatile bool third_interval_flag = false;
volatile int number_of_press = 1;

// direction variables
volatile int direction = 1;  // Sweeping direction
volatile int led = 0;        // Current LED

int main(void) {
  DDRB |= (1 << DDB0) | (1 << DDB1) | (1 << DDB2);  // Set LEDs as outputs
  DDRD &= ~((1 << DDD2) | (1 << DDD3));             // Set buttons as inputs
  PORTD |= (1 << PORTD2) | (1 << PORTD3);           // Enable pull-up resistors for buttons

  EICRA |= (1 << ISC01) | (1 << ISC11);  // Set falling edge detection for INT0 and INT1
  EIMSK |= (1 << INT0) | (1 << INT1);    // Enable INT0 and INT1 interrupts

  TCCR1B |= (1 << WGM12);               // Turn on CTC mode for Timer 1
  TCCR1B |= (1 << CS11) | (1 << CS10);  // Set up Timer 1 with prescaler of 64 (calculated from duration = 0,125s)
  OCR1A = 31249;                        // Set CTC compare value to 4Hz, with a prescaler of 64 (calculated from duration = 0,125s)
  TIMSK1 |= (1 << OCIE1A);              // Enable Output Compare A Match Interrupt for Timer 1

  sei();  // Enable global interrupts

  while (1) {
    if (number_of_press == 1) {
      if (first_interval_flag) {
        PORTB = 0;             // Turn off all LEDs
        PORTB |= (1 << led);   // Turn on current LED
        led += direction;      // Move to the next LED based on direction
        if (led > 2) led = 0;  // Wrap around if necessary
        if (led < 0) led = 2;
        first_interval_flag = false;
      }
    }
    if (number_of_press == 2) {
      if (second_interval_flag) {
        PORTB = 0;             // Turn off all LEDs
        PORTB |= (1 << led);   // Turn on current LED
        led += direction;      // Move to the next LED based on direction
        if (led > 2) led = 0;  // Wrap around if necessary
        if (led < 0) led = 2;
        second_interval_flag = false;
        tick = 1;
      }
    }
    if (number_of_press == 3) {
      if (third_interval_flag) {
        PORTB = 0;             // Turn off all LEDs
        PORTB |= (1 << led);   // Turn on current LED
        led += direction;      // Move to the next LED based on direction
        if (led > 2) led = 0;  // Wrap around if necessary
        if (led < 0) led = 2;
        third_interval_flag = false;
      }
    }
  }
}

ISR(INT0_vect)  // gear button pressed
{
  _delay_ms(50);               // Debounce delay
  if (!(PIND & (1 << PIND2)))  // Check if the button is still pressed after debounce
  {
    number_of_press++;                             // Increase gear every pressed
    if (number_of_press > 3) {
    number_of_press = 1;  // Reset gear multiplier if presse more than 3 times
    }
  }
}

ISR(INT1_vect)  // Direction button pressed
{
  _delay_ms(50);               // Debounce delay
  if (!(PIND & (1 << PIND3)))  // Check if the button is still pressed after debounce
  {
    direction *= -1;  // Change sweeping direction
  }
}

ISR(TIMER1_COMPA_vect) {
  first_interval_flag = true;
  second_interval_flag = false;
  third_interval_flag = false;

  if (tick == 2) {
    first_interval_flag = true;
    second_interval_flag = true;
    third_interval_flag = false;
  }

  if (tick == 3) {
    first_interval_flag = true;
    second_interval_flag = true;
    third_interval_flag = true;
    tick = 1;
  } else {
    tick++;
  }
}