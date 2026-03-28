/*
=========================================================
 Projeto: Dispositivo USB Lembrete de Remédios
 Plataforma: Digispark ATtiny85
 Autor: RodRobot
 Descrição:
   Este projeto utiliza o Digispark como teclado USB (HID)
   para exibir automaticamente uma lista de medicamentos
   armazenados na EEPROM AT24C256.

 Funcionamento:
   - Ao conectar no PC
   - Abre o Bloco de Notas
   - Exibe a lista de remédios automaticamente

 Hardware:
   - Digispark ATtiny85
   - EEPROM AT24C256
   - Resistores 4.7kΩ (SDA e SCL)

 Ligações:
   SDA -> P0
   SCL -> P2
   VCC -> 5V
   GND -> GND

 Aviso:
   Uso apenas educacional. Não utilize sem autorização.
=========================================================
*/

#include <TinyWireM.h>
#include <DigiKeyboard.h>

#define EEPROM_ADDR 0x50

void setup() {
  TinyWireM.begin();

  // Aguarda reconhecimento USB
  DigiKeyboard.delay(3000);

  abrirNotepad();
  mostrarDados();
}

void loop() {}

void abrirNotepad() {
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("notepad");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
}

void mostrarDados() {
  DigiKeyboard.println("Lembrete de Remedios");
  DigiKeyboard.println("---------------------");

  for (int i = 0; i < 400; i++) {
    char c = lerEEPROM(i);
    if (c == 0xFF) break;
    DigiKeyboard.print(c);
  }
}

char lerEEPROM(unsigned int endereco) {
  TinyWireM.beginTransmission(EEPROM_ADDR);
  TinyWireM.write((int)(endereco >> 8));
  TinyWireM.write((int)(endereco & 0xFF));
  TinyWireM.endTransmission();

  TinyWireM.requestFrom(EEPROM_ADDR, 1);
  return TinyWireM.read();
}