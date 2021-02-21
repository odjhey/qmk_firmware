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

enum idobo_layers {
  _QWERTY,
  _RAISE,
  _LOWER
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  LOWER,
  QMKBEST,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_ortho_5x15( \
    LT(_RAISE, KC_GRV),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             _______, _______, _______,   KC_6,                KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
    KC_TAB,              KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             _______, _______, _______,  KC_Y,                KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    CTL_T(KC_ESC),       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             _______,   RESET, _______,  KC_H,                KC_J,    KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT),  \
    KC_LSFT,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             _______, _______, _______,  KC_N,                KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_EQUAL), \
    KC_LCTL,             _______, _______, KC_LALT, KC_SPC,  LGUI_T(KC_BSPC),  _______, _______,   LOWER,  LT(_RAISE, KC_ENT),  KC_SPC,  KC_RALT, _______, KC_RCTL, RAISE    \
  ),
  [_RAISE] = LAYOUT_ortho_5x15( \
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     _______, _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   \
    _______, KC_LEFT, KC_RGHT, KC_LPRN, KC_RPRN, _______,   _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,  \
    _______, KC_DOWN, KC_UP,   KC_LCBR, KC_RCBR, _______,   _______,  RESET,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,  \
    _______, _______, _______, KC_LBRC, KC_RBRC, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______   \
  ),
  [_LOWER] = LAYOUT_ortho_5x15( \
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     _______, RGB_MOD, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   \
    _______, KC_LEFT, KC_RGHT, KC_LPRN, KC_RPRN, _______,   _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______,  \
    _______, KC_DOWN, KC_UP,   KC_LCBR, KC_RCBR, _______,   _______,   RESET, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,  \
    _______, _______, _______, KC_LBRC, KC_RBRC, _______,   _______, QMKBEST, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,  \
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______   \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

#define HSV_QWERTY 255, 0, 0
#define HSV_RAISE  0, 255, 0
#define HSV_LOWER  0, 0, 255

const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  { 0, 16, HSV_PINK }
);
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  { 8, 8, HSV_CYAN }
);
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  { 8, 8, HSV_GOLD }
);

const rgblight_segment_t* const PROGMEM odeebo_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  qwerty_layer,
  raise_layer,
  lower_layer
);

void keyboard_post_init_user() {
  rgblight_layers = odeebo_rgb_layers;
  layer_state_set_user(layer_state);
}

void matrix_init_user(void)
{
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(1, layer_state_cmp(state, _RAISE));
  rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
  return state;
}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
