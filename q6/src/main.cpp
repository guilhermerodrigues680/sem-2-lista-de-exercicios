/**
 * Aluno: Guilherme Rodrigues
 * Ciclo de maquina * preescaler * modulo do timer
 * (1/16e6) * 256 * 250 = 4ms
 * 1 / ((1/16e6) * 256 * 250) = 250Hz
 * 
 * (100% / modulo do timer) * Troca PWM
 * PWM no OC1A(DDB1)
 * (100/250) * 50 = 20%
 * 
 * PWM no OC1B(DDB2)
 * (100/250) * 200 = 80%
 **/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <Arduino.h>

void setup()
// int main(void)
{
  cli();
  // Modulo do TIMER1 de 250
  ICR1 = 249;
  // PWM de 20%
  OCR1A = 49;
  // PWM de 80%
  OCR1B = 199;

  // Fast PWM com TOP em ICR1
  // Clear OC1A/OC1B na comparacao, modo não-invertido
  // Prescaling de F_CPU/256
  // 0xA2 == 10100010 == _BV(COM1A1) | _BV(COM1B1) | _BV(WGM11)
  TCCR1A = 0xA2;
  // 0x1C == 00011100 == _BV(WGM13) | _BV(WGM12) | _BV(CS12)
  TCCR1B = 0x1C;
  // Configura como saida os pinos OC1A(DDB1) e OC1B(DDB2)
  DDRB = _BV(DDB2) | _BV(DDB1);
  sei();
}

void loop() { }