/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum combos {
  DOTJ_ESC,
  DOTD_CTRLBSPC,
  DOTM_TAB
};

const uint16_t PROGMEM dotj_combo[] = {KC_DOT, KC_J, COMBO_END};
const uint16_t PROGMEM dotd_combo[] = {KC_D, KC_DOT, COMBO_END};
const uint16_t PROGMEM dotm_combo[] = {KC_M, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [DOTJ_ESC] = COMBO(dotj_combo, KC_ESC),
  [DOTD_CTRLBSPC] = COMBO_ACTION(dotd_combo),
  [DOTM_TAB] = COMBO(dotm_combo, KC_TAB)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case DOTD_CTRLBSPC:
      if (pressed) {
        tap_code16(LCTL(KC_BSPC));
      }
      break;
  }
}

const key_override_t delete_key_override = ko_make_basic(MOD_BIT(KC_LSHIFT), KC_BSPACE, KC_DELETE);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x5_3(
      KC_K,             KC_DOT,       LT(2,KC_A),    KC_COMMA,      KC_Y,     KC_P,   KC_D,         LT(2,KC_L), KC_M,         KC_J,
      LALT_T(KC_H),     LCTL_T(KC_O), LT(1,KC_E),    LSFT_T(KC_I),  KC_U,     KC_G,   LSFT_T(KC_T), LT(1,KC_R), LCTL_T(KC_N), LALT_T(KC_S), 
      LSFT_T(KC_Z),     KC_Q,         KC_SCOLON,     LGUI_T(KC_V),  KC_X,     KC_B,   LGUI_T(KC_C), KC_W,       KC_F,         LSFT_T(KC_SLSH),
                          LT(4,KC_ESC), LSFT_T(KC_BSPC),  LT(3,KC_TAB),         LT(3,KC_ENT),   LSFT_T(KC_SPACE), LT(4,KC_ESC)

  ),

  [1] = LAYOUT_split_3x5_3(
      KC_LBRACKET,  KC_7,   KC_8,   KC_9, KC_GRAVE,             KC_GRAVE,   KC_7,   KC_8,   KC_9,   KC_LBRACKET,
      KC_MINUS,     KC_4,   KC_5,   KC_6, KC_BSLASH,            KC_BSLASH,  KC_4,   KC_5,   KC_6,   KC_MINUS,
      KC_RBRACKET,  KC_1,   KC_2,   KC_3, KC_QUOTE,             KC_QUOTE,   KC_1,   KC_2,   KC_3,   KC_RBRACKET,
                        KC_TILDE, KC_0,  KC_EQUAL,              KC_EQUAL,   KC_0, KC_TILDE
  ),

  [2] = LAYOUT_split_3x5_3(
      KC_ESC,   KC_PGUP,  KC_PGDN,  KC_HOME,  KC_DELETE,                    KC_DELETE,  KC_HOME,   KC_PGDN, KC_PGUP,   KC_BSPC,
      KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT, XXXXXXX,                      XXXXXXX, KC_LEFT,  KC_DOWN, KC_UP,     KC_RIGHT,
      KC_ENTER, KC_DELETE,KC_BSPC,  KC_END,   XXXXXXX,                      XXXXXXX, KC_END,    KC_BSPC, KC_DELETE, KC_ENTER,
                                 XXXXXXX,   MO(4),  XXXXXXX,     XXXXXXX, MO(4), XXXXXXX
  ),

  [3] = LAYOUT_split_3x5_3(
      KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                    KC_F1,  KC_F2,  KC_F3,      KC_F4,      KC_F5,
      KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,                   KC_F6,  KC_F7,  KC_F8,      KC_F9,      KC_F10,
      KC_F11,   KC_F12,   XXXXXXX,  XXXXXXX,  XXXXXXX,                  KC_F11, KC_F12, XXXXXXX,    XXXXXXX,    XXXXXXX,
                                 KC_MS_BTN2,   KC_MS_BTN3,  KC_MS_BTN1,     KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2
  ),

  [4] = LAYOUT_split_3x5_3(
        RESET, XXXXXXX, ALGR(KC_Q), XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, ALGR(KC_P), XXXXXXX, XXXXXXX, ALGR(KC_Y),                      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, ALGR(KC_S),
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,
                  LGUI(LSFT(LCTL(KC_DELETE))),   XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, LGUI(LSFT(LCTL(KC_DELETE)))
  )
};
