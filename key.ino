#define led_pin PB0   // Пин для светодиода
#define button PB2 // Пин кнопки

#include "DigiKeyboard.h"
bool press = false;

void setup() {
  pinMode(button, INPUT);
  pinMode(led_pin, OUTPUT);
  DigiKeyboard.enableLEDFeedback();
}
+++++++++++++++++++++++++++++++++++++++++++++++
void loop() {
  if (digitalRead(button) == HIGH) {
    if (press == false) {
      press = true;
      DigiKeyboard.sendKeyPress(KEYPAD_PLUS); //KEY_RIGHT_ALT KEYPAD_PLUS MODIFIERKEY_RIGHT_ALT
      digitalWrite(led_pin, HIGH);
    } // else DigiKeyboard.delay(500);
  } else {
    if (press == true) {
      press = false;
      DigiKeyboard.sendKeyPress(0);
      digitalWrite(led_pin, LOW);
    }
  }
}