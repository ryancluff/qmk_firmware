#include QMK_KEYBOARD_H

enum custom_keycodes {
  MOVE
};

bool move_mouse = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_4x4(
        MOVE,   KC_1,   KC_2,   KC_RESET,
        KC_F21, KC_F22,  KC_F23,   KC_F24,
        KC_F17, KC_F18, KC_F19,   KC_F20,
        KC_F13, KC_F14, KC_F15, KC_F16
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MOVE:
            if (record->event.pressed) {
                move_mouse = !move_mouse;
            }
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    if (move_mouse) {
        tap_code(KC_MS_UP);
        tap_code(KC_MS_DOWN);
        tap_code(KC_MS_LEFT);
        tap_code(KC_MS_RIGHT);
    }
}

#ifdef ENCODER_ENABLE
#include "encoder.h"
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
  return true;
}
#endif
