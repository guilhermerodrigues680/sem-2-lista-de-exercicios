/**
 * Aluno: Guilherme Rodrigues
 * PD6 = OC0A
 * 
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

const unsigned char v[]  = {
    0,   3,   5,   8,  10,  13,  15,  18,  21,  23,  26,  28,
   31,  33,  36,  39,  41,  44,  46,  49,  51,  54,  57,  59,
   62,  64,  67,  69,  72,  75,  77,  80,  82,  85,  87,  90,
   93,  95,  98, 100, 103, 105, 108, 111, 113, 116, 118, 121,
  123, 126, 128, 131, 134, 136, 139, 141, 144, 146, 149, 152,
  154, 157, 159, 162, 164, 167, 170, 172, 175, 177, 180, 182,
  185, 188, 190, 193, 195, 198, 200, 203, 206, 208, 211, 213,
  216, 218, 221, 224, 226, 229, 231, 234, 236, 239, 242, 244,
  247, 249, 252, 254
};

unsigned char pa;


// void setup()
int main(void)
{
  cli();
  DDRD = _BV(PORTD6);
  TCCR0B = _BV(CS00);
  TIMSK0 = _BV(TOIE0);
  sei();
  pa = v[0];
  while (1)
  {
  }
}

// void loop() { }


ISR (TIMER0_OVF_vect)
{
  static unsigned char p1 = 0;
  static unsigned char i = 0;

  if (++p1 == 255)
  {
    p1 = 0;
    PORTD |= _BV(PORTD6);
    pa = v[++i];
    i %= 100;
  }
  if (p1 == pa)
  {
    PORTD &= ~_BV(PORTD6);
  }
  
}