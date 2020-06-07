/**
 * Aluno: Guilherme Rodrigues
 */

#include <avr/io.h>
#include <avr/interrupt.h>

void setup()
// int main(void)
{
  /**
   * Aluno: Guilherme Rodrigues
   * A maior frequencia é do microcontrolador dividida por dois
   * Configura-se para trocar o estado do pino a cada comparacao
   * e configura o TIMER0 para CTC de modulo 0
   **/
  OCR0A = 0;
  TCCR0A = _BV(COM0A0);
  TCCR0B = _BV(CS00);

  DDRD = _BV(PORTD6);

  for (;;)
  {
  }
  
}

void loop() { }