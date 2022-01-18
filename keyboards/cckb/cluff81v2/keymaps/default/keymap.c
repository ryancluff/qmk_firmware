/* Copyright 2021 ryan cluff
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "cluff81v2/cluff81v2.h"
#include "cckb/cluff81v2/config.h"

enum custom_keycodes {
    MOVE,
    ENCODER,
    E_CW,
    E_CCW
};

bool move_mouse = false;
bool alt_held = false;

enum keyboard_layers {
    _BL,
    _ML,
    _TL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT(
        KC_MUTE,    KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_DEL,
        KC_F13,     KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,
        KC_F14,     KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,
        KC_F15,     MO(_TL),    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_ENT,
        KC_F16,     KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
        TG(_ML),    KC_LCTL,    KC_LGUI,    KC_LALT,    KC_SPC,     KC_BSPC,    KC_DEL,     KC_RALT,    KC_RCTL),
    [_ML] = LAYOUT(
        KC_MUTE,        KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_DEL,
        C(KC_RIGHT),    KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,
        C(KC_LEFT),     KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,
        KC_F15,         MO(_TL),    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_ENT,
        MOVE,           KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
        TG(_ML),        KC_LGUI,    KC_LCTL,    KC_LALT,    KC_SPC,     KC_BSPC,    KC_DEL,     KC_RALT,    KC_RCTL),
    [_TL] = LAYOUT(
        KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    RESET,      KC_TRNS,    KC_TRNS,
        KC_F18,      KC_NLCK,    KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_KP_0,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        RGB_TOG,     KC_TRNS,    KC_TRNS,    KC_UP,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        RGB_HUI,     KC_TRNS,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        RGB_SAI,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        RGB_VAI,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MOVE:
            if (record->event.pressed) {
                move_mouse = !move_mouse;
            }
            break;
        case ENCODER:
            if (record->event.pressed) {
                if (alt_held) {
                    alt_held = false;
                    unregister_code(KC_LALT);
                    unregister_code(KC_LSHIFT);
                }
                else {
                    tap_code(KC_LGUI);
                }
            }
            break;
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            alt_held = true;
            unregister_code(KC_LSHIFT);
            register_code(KC_LALT);
            tap_code(KC_TAB);
        } else {
            alt_held = true;
            register_code(KC_LSHIFT);
            register_code(KC_LALT);
            tap_code(KC_TAB);
        }
    }
    return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {
    if (move_mouse) {
        tap_code(KC_MS_UP);
        tap_code(KC_MS_DOWN);
        tap_code(KC_MS_LEFT);
        tap_code(KC_MS_RIGHT);
    }
}

void led_set_user(uint8_t usb_led) {}
