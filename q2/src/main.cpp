/**
 * Aluno: Guilherme Rodrigues
 * Gerando onda de 250Hz no PORTB3(0C2A) com TIMER2
 * ((1/16e6) * 256 * 125) = 2ms * 2 = 4ms
 * 1 / ((1/16e6) * 256 * 125) = 500Hz / 2 = 250Hz
 * Gerando PWM de 2.0ms e 25% no PORTD3(0C2B) com TIMER2
 * ((1/16e6) * 256 * 125) = 2ms
 * 1 / ((1/16e6) * 256 * 125) = 500Hz
 * PWM 25% = 125 * 0.25 ~= 31
 * 
 * Configurei um Fast PWM que conta até OCR2A
 * Configurei o pino OC2A para trocar de estado ao comparar.
 * Ele troca de estado e recomeça a contagem em zero (BOTTOM)
 * Configurei o OC2B como PWM nao invertido. Seu periodo é o modulo do timer
 * Como o OC2A troca de estado na comparacao ele leva dois modulos de tempo para fazer 1 periodo.
 * Assim a sua frequencia é 2vezes menor que a frequencia de OC2B
 * 
 */

#include <avr/io.h>
#include <avr/interrupt.h>


void setup()
// int main(void)
{
  OCR2A = 125;
  OCR2B = 31;
  TCCR2A = _BV(COM2A0) | _BV(COM2B1) | _BV(WGM21)  | _BV(WGM20); // Modo nao invertido e FAST PWM
  TCCR2B = _BV(WGM22) | _BV(CS22) | _BV(CS21); 

  DDRB = _BV(PORTB3);
  DDRD = _BV(PORTD3);
}

void loop() { }