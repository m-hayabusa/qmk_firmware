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
#include "midi.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FNL,
    _FNR,
    _NUM,
    _FN2,
    _MID
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    tilde = SAFE_RANGE
};

#define MI_KILL MI_ALLOFF

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_TAB ,  JP_Q   ,  JP_W   ,  JP_E   ,  JP_R   ,  JP_T   ,  JP_Y   ,  JP_U   ,  JP_I   ,  JP_O   ,  JP_P   ,  JP_AT  ,  JP_LBRC,  KC_BSPC,
        KC_LCTL,  JP_A   ,  JP_S   ,  JP_D   ,  JP_F   ,  JP_G   ,  JP_H   ,  JP_J   ,  JP_K   ,  JP_L   ,  JP_SCLN,  JP_COLN,  JP_RBRC,  KC_ENT ,
        KC_LSFT,  JP_Z   ,  JP_X   ,  JP_C   ,  JP_V   ,  JP_B   ,  JP_N   ,  JP_M   ,  JP_COMM,  JP_DOT ,  JP_SLSH,  JP_BSLS,  KC_RSFT,
                  KC_LALT,  KC_LGUI, MO(_FNL), KC_SPC  ,           MO(_FNR),  KC_PSCR,  KC_RALT,  KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RGHT ),
    [_FNL] = LAYOUT(
        KC_ESC ,  JP_1   ,  JP_2   ,  JP_3   ,  JP_4   ,  JP_5   ,  JP_6   ,  JP_7   ,  JP_8   ,  JP_9   ,  JP_0   ,  JP_MINS,  JP_CIRC,  KC_DEL ,
        _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RGHT,  _______,  _______,  _______,  KC_RETURN,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  JP_YEN ,  _______,
                  _______,  _______,  _______, MO(_NUM),           MO(_FN2), TO(_MID),  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END ),
    [_FNR] = LAYOUT(
        KC_ESC ,  JP_1   ,  JP_2   ,  JP_3   ,  JP_4   ,  JP_5   ,  JP_6   ,  JP_7   ,  JP_8   ,  JP_9   ,  JP_0   ,  JP_MINS,  JP_CIRC,  KC_DEL ,
        _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RGHT,  _______,  _______,  _______,  KC_RETURN,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  JP_YEN ,  _______,
                  _______,  _______, MO(_FN2), MO(_NUM),            _______, TO(_MID),  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END ),
    [_NUM] = LAYOUT(
        _______,  KC_P7  ,  KC_P8  ,  KC_P9  ,  KC_PMNS,  _______,  KC_NLCK,  KC_P7  ,  KC_P8  ,  KC_P9  ,  KC_PMNS,  KC_SLCK,  KC_INS ,  _______,
        _______,  KC_P4  ,  KC_P5  ,  KC_P6  ,  KC_PPLS,  _______,  KC_CLCK,  KC_P4  ,  KC_P5  ,  KC_P6  ,  KC_PPLS,  _______,  _______,  KC_PENT,
        _______,  KC_P1  ,  KC_P2  ,  KC_P3  ,  KC_PENT,  _______,  _______,  KC_P1  ,  KC_P2  ,  KC_P3  ,  KC_PENT,  _______,  _______,
                  KC_P0  ,  KC_PDOT,  _______,  _______,            _______,  KC_P0  ,  KC_PDOT,  KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RGHT ),
    [_FN2] = LAYOUT(
        tilde  ,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,  KC_F6  ,  KC_F7  ,  KC_F8  ,  KC_F9  ,  KC_F10 ,  KC_F11 ,  KC_F12 ,  KC_DEL ,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______ ),
    [_MID] = LAYOUT(
        KC_ESC ,  MI_OCTD,  MI_OCTU,  MI_CHD ,  MI_CHU , MI_TRNSD, MI_TRNSU,  MI_VELD,  MI_VELU,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        MI_As_2,  MI_KILL,  MI_Cs_3,  MI_Ds_3,  XXXXXXX,  MI_Fs_3,  MI_Gs_3,  MI_As_3,  XXXXXXX,  MI_Cs_4,  MI_Ds_4,  XXXXXXX,  MI_Fs_4,  KC_ENT ,
        MI_B_2 ,  MI_C_3 ,  MI_D_3 ,  MI_E_3 ,  MI_F_3 ,  MI_G_3 ,  MI_A_3 ,  MI_B_3 ,  MI_C_4 ,  MI_D_4 ,  MI_E_4 ,  MI_F_4 ,  MI_G_4 ,
                  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_SPC ,            XXXXXXX,TO(_BASE),  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RGHT )

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
