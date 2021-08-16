/*
Keymap for: caps-unlocked.com/cu7/
Based on: qmk/qmk_firmware/blob/master/keyboards/capsunlocked/cu7/keymaps/default/keymap.c

Layout (Top middle is rotary encoder that also has a click, click is press and hold for modifiers)
                ┌────────────────────────┐
                │ Vol Up/Down            │
                │ (Press and hold: Mod)  │
┌───────────────┼────────────────────────┼──────────────────┐
│ Play/Pause    │ Previous Track         │ Next Track       │
│ (RGB On/Off)  │ (Stop Recording Macro) │ (BootLoader)     │
├───────────────┼────────────────────────┼──────────────────┤
│ Mute/Unmute   │ Play Macro 1           │ Play Macro 2     │
│ (RGB Pattern) │ (Record Macro 1)       │ (Record Macro 2) │
└───────────────┴────────────────────────┴──────────────────┘ 

N.B. To enable dyanmic macros, first include DYNAMIC_MACRO_ENABLE = yes in your rules.mk
*/
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
             MO(1),
    KC_MPLY,  KC_MPRV,  KC_MNXT,
    KC_MUTE,  DM_PLY1,  DM_PLY2
  ),
  [1] = LAYOUT(
             _______,
    RGB_TOG,  DM_RSTP,  RESET,
    RGB_MOD,  DM_REC1,  DM_REC2
  ),
};

// Volume up/down on the encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code_delay(KC_VOLU, 10);
  }
  else {
    tap_code_delay(KC_VOLD, 10);
  }

  return true;
}