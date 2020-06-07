/**
 * Aluno: Guilherme Rodrigues
 * Gerando onda de 20kHz no PORTB5 com TIMER0
 * (1/16e6) * 8 * 100 = 50us
 * 1 / ((1/16e6) * 8 * 100) = 20kHz
 **/

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_COMPA_vect)
{
  PORTB ^= _BV(PORTB5);
}

int main(void)
{
  cli();
  DDRB = _BV(PORTB5);   // Define o PORTB5 como saida
  OCR0A = 50 - 1;       // Define o valor topo do TIMER0 (O topo é dividido por dois)
  TIMSK0 = _BV(OCIE0A); // Ativa a interupcao por comparacao
  TCCR0A = _BV(WGM01);  // Configura o modo CTC do TIMER0
  TCCR0B = _BV(CS01);   // Configura o preescaler de 8
  sei();

  for (;;)
  {
  }
}