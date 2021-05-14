#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
    KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,
    KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,
    KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,
    KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,
    KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,
    KC_1,   KC_1,   KC_1,           KC_1,           KC_1,           KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_1);
    } else {
      tap_code(KC_1);
    }
  }
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
