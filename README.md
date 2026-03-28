# 💊 Lembrete de Remédios com Digispark ATtiny85 (AT24C256 + I2C)

Projeto de um dispositivo USB inteligente que exibe automaticamente uma lista de medicamentos no computador ao ser conectado.

## 🚀 Como funciona

O Digispark ATtiny85 atua como um dispositivo USB HID (teclado), digitando automaticamente os dados armazenados na EEPROM AT24C256.

### 🔄 Fluxo:
1. Dados gravados na EEPROM
2. Leitura via I2C
3. Ao conectar no PC:
   - Abre o Notepad
   - Exibe os dados automaticamente

---

## 🔌 Componentes

- Digispark ATtiny85
- EEPROM AT24C256
- Resistores 4.7kΩ (pull-up)
- Jumpers

---

## 🔧 Ligações

| AT24C256 | Digispark |
|----------|----------|
| VCC      | 5V       |
| GND      | GND      |
| SDA      | P0       |
| SCL      | P2       |

---

## ⚠️ Importante

Use resistores pull-up de 4.7kΩ em:
- SDA → VCC
- SCL → VCC

---

## 💻 Códigos

### 🔹 Gravação da EEPROM
Arquivo: `gravar_eeprom.ino`

### 🔹 Leitura e envio via USB
Arquivo: `leitura_usb.ino`

---

## 📸 Projeto

## 🌐 Projeto completo no blog

https://rodrobot.blogspot.com/

---

## 🔥 Próximos passos

Este projeto pode evoluir para:

- ESP32 com Wi-Fi
- Notificações remotas
- Sistema IoT completo

---

## ⚠️ Aviso

Uso educacional. Não utilize dispositivos USB automatizados sem autorização.

---

## 🤖 Autor

RodRobot  
https://github.com/rodrobot01
