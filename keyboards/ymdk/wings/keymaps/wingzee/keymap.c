/* Copyright 2021 alittlepeace
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

enum {
      TD_SPC_ENT,
      TD_X_SPC,
};

qk_tap_dance_action_t tap_dance_actions[] = {
      [TD_SPC_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
      [TD_X_SPC]   = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_Z)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    OSL(1),   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_MINS, KC_EQL,       KC_DEL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,                MO(1),
    CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT), KC_ENT,                           RESET,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_EQUAL),                    KC_UP,
    KC_LCTL,          KC_LALT,          LGUI_T(KC_BSPC),  KC_ENT,          KC_SPC,           KC_RALT,                           KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [1] = LAYOUT_all(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  _______, _______, MO(0),
    _______, _______, _______, _______,   RESET, _______, _______, _______, _______, _______, _______, _______, _______,  KC_DEL,           _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                    _______,
    _______, TD(TD_SPC_ENT), TD(TD_X_SPC), _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______,          _______, _______,          KC_ENT,          _______,                            _______, _______, _______
  )
};
