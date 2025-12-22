/* Copyright 2018 MechMerlin
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

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define GUI_BSPC MT(MOD_LGUI, KC_BSPC)
#define L2_MVMT LT(2, KC_ENT)
#define CTL_ENT MT(MOD_RCTL, KC_ENT)
#define SFT_EQL MT(MOD_RSFT, KC_EQL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [0] = LAYOUT_ortho_5x15(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,            KC_5,     KC_6,           KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,            KC_T,     KC_Y,           KC_U,    KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC_DEL,
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,            KC_G,     KC_H,           KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT, CTL_ENT, KC_ENT,  _______,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,            KC_B,     KC_N,           KC_M,    KC_COMM, KC_DOT,   KC_SLSH, SFT_EQL, KC_PGDN, KC_UP,   KC_PGUP,
    KC_LCTL, _______, KC_LALT, KC_LGUI, KC_SPC,          GUI_BSPC, L2_MVMT,        KC_SPC,  KC_RALT, _______,  KC_RCTL, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
  ),

 [1] = LAYOUT_ortho_5x15(
    QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [2] = LAYOUT_ortho_5x15(
      _______, _______, _______, _______, _______,       _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,       _______, KC_HOME,         KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______, _______, _______,
      _______, _______, _______, KC_LBRC, KC_RBRC,       _______, KC_LEFT,         KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,       _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,       _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______
  )
};
