/**
 * Aluno: Guilherme Rodrigues
 * OC0A(PD6)  Período 4.096 mS : 25% , OC0B(PD5)  Período 4.096 mS : 75% 
 * OC1A(PB1)  Período 4.096 mS : 25% , OC1B(PB2)  Período 4.096 mS : 75% 
 * OC2A(PB3)  Período 4.096 mS : 25% , OC2B(PD3)  Período 4.096 mS : 75%
 * 
 * Para todos os TIMERS foi seguido o mesmo procedimentos:
 * - O sinal será gerado por Hardware.
 * - Configuracao do modulo e prescaler do TIMERx para um periodo de 4.096ms.
 * - Configuracao dos PWMs usando uma funcao de proporcao.
 * - Configuracao para Clear do pino na comparacao e modo não invertido.
 * - Configuracao do pino como saida digital
 **/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <Arduino.h>

#define TIMER0_MODULE               0xFF
#define TIMER1_MODULE               0xFFFF
#define TIMER2_MODULE               0xFF
#define _ltrans(x, xi, xm, yi, ym)  (long)((long)(x - xi) * (long)(ym - yi)) / (long)(xm - xi) + yi

void setup()
// int main(void)
{
  /**** TIMER0 - :: (1/16e6) * 256 * 0xFF = 4.096ms::****/
  OCR0A = (char)(_ltrans(25, 0, 100, 0, TIMER0_MODULE)); // PWM de 25%
  OCR0B = (char)(_ltrans(75, 0, 100, 0, TIMER0_MODULE)); // PWM de 75%
  TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
  TCCR0B = _BV(CS02);
  DDRD = _BV(DDD6) | _BV(DDD5);

  /**** TIMER1 - :: (1/16e6) * 1 * 0xFFFF = 4.096ms ::****/
  ICR1 = TIMER1_MODULE;
  OCR1A = (int)(_ltrans(25, 0, 100, 0, TIMER1_MODULE)); // PWM de 25%
  OCR1B = (int)(_ltrans(75, 0, 100, 0, TIMER1_MODULE)); // PWM de 75%
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM11);
  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10);
  DDRB = _BV(DDB2) | _BV(DDB1);

  /**** TIMER2 - :: (1/16e6) * 256 * 0xFF = 4.096ms::****/
  OCR2A = (char)(_ltrans(25, 0, 100, 0, TIMER2_MODULE)); // PWM de 25%
  OCR2B = (char)(_ltrans(75, 0, 100, 0, TIMER2_MODULE)); // PWM de 75%
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS22) | _BV(CS21);
  DDRB |= _BV(DDB3);
  DDRD |= _BV(DDD3);
}

void loop() { }