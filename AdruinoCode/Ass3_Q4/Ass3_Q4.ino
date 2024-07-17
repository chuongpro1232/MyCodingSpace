#include <avr/io.h>
#include <avr/interrupt.h>
#define ADDRESS_COMMAND 0b10000011

volatile int cycle_count = 0;

volatile int bit = 0;

volatile bool timer1_flag = false;

volatile bool button_press_flag = false;
volatile bool button_pressed = false;

volatile bool send = false;

volatile bool low = false;
volatile bool high = false;
volatile bool rising_edge = false;
volatile bool falling_edge = false;


int main(void) {
  DDRB |= ((1 << DDB0) | (1 << DDB1) | (1 << DDB2));  // RST = PORTB0, CLK = PORTB1, DAT = PORTB2
  PORTB = 0x00;                                       //set low to all PORTB
  DDRD &= ~(1 << DDD2);                               //For button

  TCCR1B |= (1 << WGM12);   // Turn on the CTC mode
  TCCR1B |= (1 << CS12);    // Set up prescaler of 256
  TIFR1 &= ~(1 << OCF1A);   // set flag=0
  TIMSK1 |= (1 << OCIE1A);  // Enable Output Compare A Match Interrupt
  
  EIFR &= ~(1 << INTF0);  // set flag=0
  EIMSK |= (1 << INT0);   // set e_interrupt0
  EICRA |= (1 << ISC01);  // set falling edge

  sei();  //Enable the Global Interrupt Bit

  while (1) {
    if (cycle_count == 0 | cycle_count == 30){
      OCR1A = 624; //10ms delay
    } else{
      OCR1A = 468; //7.5ms delay
    }
    
    //When it ends
    if (cycle_count > 32) {
      PORTB = 0x00;  //set low to all PORTB
      cycle_count = 0;
      button_pressed = false;
      DDRB &= ~(1 << DDB2); // set to PORTB3 as input
    }

    // Generate SCLK waveforms
    if (button_pressed) {
      if (timer1_flag) {
        timer1_flag = false;
        if (cycle_count < 32) {
          if(low){
            PORTB |= (1<<PORTB1); //rising edge
            low = false;
            high = true;
            rising_edge = true;
            falling_edge = false;
            if(cycle_count >= 30){
              PORTB &= ~(1<<PORTB1);
            }

          } else if (high){
            PORTB &= ~(1<<PORTB1); //falling edge
            low = true;
            high = false;
            rising_edge = false;
            falling_edge = true;
          }
        }
        cycle_count++;
      }
    }

    //Send data to I/O
    if (send) {
      //last 8 bits falling edges reading data
      if (bit >= 8 && high) {
        PORTB &= ~(1 << PORTB2); //clear PB2
        bit = 0;
        send = false;
        DDRB &= ~(1 << DDB2);  // Set port DAT as input
      }
      //Send data to rising edge of first 8 bits
      if (falling_edge){
        if((ADDRESS_COMMAND >> bit) & 1){
          PORTB |= (1<<PORTB2); //turn on bit 0,2,7
        }else{
          PORTB &= ~(1<<PORTB2); //turn off the rest
        }
        falling_edge = false;
        bit++;
      }
    }

    //Generate CE waveforms
    if (button_press_flag) {
      button_press_flag = false;  // reset flag
      if (!button_pressed) {
          
        PORTB |= (1 << PORTB0);  // set RST high immediately
        DDRB |= (1 << DDB2);     // Set port DAT as ouput
        TIFR1 |= (1 << OCF1A);   // clear flag
        TCNT1 = 0;               //reset counter1

        low = true; button_pressed = true; //start to generate SLCK waveforms
        falling_edge = true;  // to set DAT at bit 0
        send = true;          // start sending data
        timer1_flag = false;  //clear timer flag
        
      }
    }
  }
}

ISR(TIMER1_COMPA_vect) {
  timer1_flag = !timer1_flag;
}

ISR(INT0_vect) {
  button_press_flag = true;
}
