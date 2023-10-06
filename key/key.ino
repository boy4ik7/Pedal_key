#define button PB2 // Пин кнопки

#include "DigiKeyboard.h"
bool press = false;

void setup() {
  pinMode(button, INPUT);
  DigiKeyboard.enableLEDFeedback();
}

void loop() {
  if (digitalRead(button) == HIGH) {
    if (press == false) {
      press = true;
      DigiKeyboard.sendKeyPress(KEYPAD_PLUS); //KEY_RIGHT_ALT KEYPAD_PLUS MODIFIERKEY_RIGHT_ALT
    } // else DigiKeyboard.delay(500);
  } else {
    if (press == true) {
      press = false;
      DigiKeyboard.sendKeyPress(0);
    }
  }
}
