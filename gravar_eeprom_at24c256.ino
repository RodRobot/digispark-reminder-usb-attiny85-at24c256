/*
=========================================================
 Projeto: Gravador de Dados na EEPROM AT24C256
 Plataforma: Digispark ATtiny85
 Autor: RodRobot
 Descrição:
   Este código grava uma lista de medicamentos com horários
   na memória EEPROM AT24C256 utilizando comunicação I2C.

 Hardware:
   - Digispark ATtiny85
   - EEPROM AT24C256
   - Resistores 4.7kΩ (pull-up em SDA e SCL)

 Ligações:
   SDA -> P0
   SCL -> P2
   VCC -> 5V
   GND -> GND

 Observação:
   Execute este código apenas uma vez para gravar os dados.
=========================================================
*/

#include <TinyWireM.h>

#define EEPROM_ADDR 0x50

const char dados[] =
"Paracetamol - 08.00h\n"
"Ibuprofeno - 12.00h\n"
"Omeprazol - 07.00h\n"
"Dipirona - 18.00h\n"
"Vitamina D - 09.00h\n"
"Losartana - 10.00h\n"
"Aspirina - 14.00h\n"
"Amoxicilina - 16.00h\n"
"Loratadina - 20.00h\n"
"Metformina - 22.00h\n";

void setup() {
  TinyWireM.begin();

  for (unsigned int i = 0; i < sizeof(dados); i++) {
    escreverEEPROM(i, dados[i]);
    delay(5); // tempo necessário para escrita
  }
}

void loop() {}

void escreverEEPROM(unsigned int endereco, char dado) {
  TinyWireM.beginTransmission(EEPROM_ADDR);
  TinyWireM.write((int)(endereco >> 8));
  TinyWireM.write((int)(endereco & 0xFF));
  TinyWireM.write(dado);
  TinyWireM.endTransmission();
}