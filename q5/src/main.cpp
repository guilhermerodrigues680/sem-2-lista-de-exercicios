/**
 * Aluno: Guilherme Rodrigues
 * Para gerar um pwm por software com 75% e periodo de 4ms
 * Eu dividi o periodo que eu preciso por 4. No caso o modulo 64000 do TIMER1
 * Desta forma posso obter 4 interupcoes por comparacao de 1ms.
 * Assim eu conto as interupcoes e a cada 4 interupcoes:
 * 3 o pino deve estar em 5v e em 1 deve estar em 0v
 * Ciclo de maquina * preescaler * modulo do timer
 * (1/16e6) * 1 * 16000 = 1ms
 **/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <Arduino.h>

#define TIMER1_MODULE 16000

void setup()
// int main(void)
{
  cli();
  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10);
  OCR1A = TIMER1_MODULE - 1;
  TIMSK1 = _BV(OCIE1A);
  DDRC = _BV(PC2);
  sei();
}

void loop() { }


ISR (TIMER1_COMPA_vect)
{
  static unsigned char count = 0;
  count = ++count > 4 ? 1 : count;
  
  if (count > 3)
    PORTC &= ~_BV(PC2);
  else
    PORTC |= _BV(PC2);
}