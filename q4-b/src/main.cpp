#include <avr/io.h>
#include <util/delay.h>
#include <Arduino.h>



void setup()
// int main(void)
{
  /**
   * Aluno: Guilherme Rodrigues
   * Ciclo de maquina * preescaler * modulo do timert
   * 1 / ((1/16e6) * 1 * 0xFFFF) = 244Hz
   * Como ele troca de estado nesta frequencia, multiplicase por dois o periodo
   * 1 / ((1/16e6) * 1 * 0xFFFF * 2) = 122Hz
   **/
  TCCR1A = _BV(COM1A0); // CTC com troca de OC1A
  TCCR1B = _BV(CS10);   // FPS de 1
  DDRB = _BV(DDB1);     // Configura como saida o pino OC1A(DDB1)
  OCR1A = 0;
}

void loop() { }