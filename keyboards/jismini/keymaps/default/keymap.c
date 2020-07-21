/* Copyright 2020 m-hayabusa
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
#include QMK_KEYBOARD_H
#include "keymap_jp.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FNL,
    _FNR,
    _FN2
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    tilde = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_TAB ,  JP_Q   ,  JP_W   ,  JP_E   ,  JP_R   ,  JP_T   ,  JP_Y   ,  JP_U   ,  JP_I   ,  JP_O   ,  JP_P   ,  JP_AT  ,  JP_LBRC,  KC_BSPC,
        KC_LCTL,  JP_A   ,  JP_S   ,  JP_D   ,  JP_F   ,  JP_G   ,  JP_H   ,  JP_J   ,  JP_K   ,  JP_L   ,  JP_SCLN,  JP_COLN,  JP_RBRC,  KC_ENT ,
        KC_LSFT,  JP_Z   ,  JP_X   ,  JP_C   ,  JP_V   ,  JP_B   ,  JP_N   ,  JP_M   ,  JP_COMM,  JP_DOT ,  JP_SLSH,  JP_BSLS,  KC_RSFT,
                  KC_LALT,  KC_LGUI, MO(_FNL), KC_SPC  ,           MO(_FNR),  KC_PSCR,  KC_RALT,  KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RGHT ),
    [_FNL] = LAYOUT(
        KC_ESC ,  JP_1   ,  JP_2   ,  JP_3   ,  JP_4   ,  JP_5   ,  JP_6   ,  JP_7   ,  JP_8   ,  JP_9   ,  JP_0   ,  JP_MINS,  JP_CIRC,  KC_DEL ,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_RETURN,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_SLCK,  KC_CAPS,  KC_INS ,  JP_YEN ,  _______,
                  _______,  _______,  _______,  _______,           MO(_FN2),  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END ),
    [_FNR] = LAYOUT(
        KC_ESC ,  JP_1   ,  JP_2   ,  JP_3   ,  JP_4   ,  JP_5   ,  JP_6   ,  JP_7   ,  JP_8   ,  JP_9   ,  JP_0   ,  JP_MINS,  JP_CIRC,  KC_DEL ,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_RETURN,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_SLCK,  KC_CAPS,  KC_INS ,  JP_YEN ,  _______,
                  _______,  _______, MO(_FN2),  _______,            _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END ),
    [_FN2] = LAYOUT(
        tilde  ,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,  KC_F6  ,  KC_F7  ,  KC_F8  ,  KC_F9  ,  KC_F10 ,  KC_F11 ,  KC_F12 ,  KC_DEL ,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______ )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case tilde:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING(SS_LSFT("="));

            } else {
                // when keycode QMKBEST is released
            }
            break;

        default:
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
