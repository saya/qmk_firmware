/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include "keymap_us_international.h"

enum layers {
    _COLEMAK_DH = 0,
    _L_NUM,
    _L_FUN,
    _L_INTL,
    _R_SYM,
    _R_INTL,
    _R_NAV,
    _R_MOUSE,
    _R_ALT,
};

#define GER_AE   US_ADIA
#define GER_OE   US_ODIA
#define GER_UE   US_UDIA
#define GER_SS   US_SS

// Mod-taps with non-basic keycodes, remapped in process_record_user.
// See https://precondition.github.io/home-row-mods#using-non-basic-keycodes-in-mod-taps.
#define  LALT_CA MT(MOD_LALT, KC_F20) // --> MT(MOD_LALT, C(KC_A))
#define  LCTL_CR MT(MOD_LCTL, KC_F21) // --> MT(MOD_LCTL, C(KC_R))
#define  LSFT_CS MT(MOD_LSFT, KC_F22) // --> MT(MOD_LSFT, C(KC_S))

#define  LALT_A MT(MOD_LALT, KC_A)
#define  LCTL_R MT(MOD_LCTL, KC_R)
#define  LSFT_S MT(MOD_LSFT, KC_S)
#define  RSYM_D LT(_R_SYM, KC_D)

#define  LNUM_H LT(_L_NUM, KC_H)
#define  RSFT_E MT(MOD_RSFT, KC_E)
#define  RSFT_DOT MT(MOD_RSFT, KC_DOT)
#define  RCTL_I MT(MOD_RCTL, KC_I)
#define  LALT_O MT(MOD_LALT, KC_O)

#define LGUI_C LGUI_T(KC_C)
#define LGUI_COMM LGUI_T(KC_COMM)

#define RINTL_T LT(_R_INTL, KC_T)
#define LINTL_N LT(_L_INTL, KC_N)

#define NAV_SPC LT(_R_NAV, KC_SPACE)
#define MOU_TAB LT(_R_MOUSE, KC_TAB)
#define ALT_ESC LT(_R_ALT, KC_ESC)

#define SFT_BSP MT(MOD_LSFT, KC_BSPACE)
#define FUN_ENT LT(_L_FUN, KC_ENTER)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_S:
        case RSFT_E:
        case RSYM_D:
        case LNUM_H:
            return g_tapping_term - 25;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Immediately select the hold action when another key is pressed.
        case SFT_BSP:
            return true;
        // Do not select the hold action when another key is pressed.
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LALT_CA:
      if (record->event.pressed && record->tap.count > 0) {
        tap_code16(C(KC_A));
        return false;
      }
    case LCTL_CR:
      if (record->event.pressed && record->tap.count > 0) {
        tap_code16(C(KC_R));
        return false;
      }
    case LSFT_CS:
      if (record->event.pressed && record->tap.count > 0) {
        tap_code16(C(KC_S));
        return false;
      }
    default:
      return true; // Process all other keycodes normally
  }
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT_split_3x6_3(
                                                                                                    /*  ; : */
      KC_INS,    KC_Q,    KC_W,    KC_F,     KC_P,    KC_B,     KC_J,       KC_L,        KC_U,    KC_Y, KC_SCLN, _______,
   /* -                                                                                                             _ */
      KC_MINS,  LALT_A,  LCTL_R,  LSFT_S,   RINTL_T,    KC_G,     KC_M,     LINTL_N,      RSFT_E,  RCTL_I,  LALT_O, KC_UNDS,
      KC_ENTER, KC_Z,    KC_X,    LGUI_C,   RSYM_D,    KC_V,     KC_K,     LNUM_H,     LGUI_COMM,  RSFT_DOT, KC_SLSH, _______,
                                  MOU_TAB, NAV_SPC, ALT_ESC,     FUN_ENT, SFT_BSP, KC_DEL
    ),
    [_L_NUM] = LAYOUT_split_3x6_3(
            /*   @    ,                            %*/
      _______,   KC_AT,    KC_7,    KC_8,    KC_9, KC_PERC,  _______, _______, _______, _______, _______, _______,
            /*  =                                  *                                             : */
      _______,  KC_EQL,    KC_4,    KC_5,    KC_6, KC_ASTR,  _______, _______, _______, _______, KC_COLN, _______,
            /*  $                                  + */
      _______,  KC_DLR,    KC_1,    KC_2,    KC_3, KC_PLUS,  _______, _______, _______, _______, _______, _______,
               KC_0,  KC_SPC, _______,   _______, _______, _______
    ),
    [_L_FUN] = LAYOUT_split_3x6_3(
       KC_INS,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,  _______, _______, _______, _______, _______, _______,
      KC_CAPS,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,  _______, _______, _______, _______, _______, _______,
      _______,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,  _______, _______, _______, _______, _______, _______,
               _______,  _______, _______, _______, _______, _______
    ),
    [_L_INTL] = LAYOUT_split_3x6_3(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______,  GER_AE, _______,  GER_SS, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______, _______
    ),
    [_R_SYM] = LAYOUT_split_3x6_3(
                                                            /* |    ,  ` ~   , {      , }      , ^ */
      _______, _______, _______, _______, _______, _______,  KC_PIPE,  KC_GRV, KC_LCBR, KC_RCBR, KC_CIRC, _______,
                                                            /* &    , ' "    , (      , )      , ! */
      _______, _______, _______, _______, _______, _______,  KC_AMPR, KC_QUOT, KC_LPRN, KC_RPRN, KC_EXLM, _______,
                                                            /* ~    , "      , [      , ],     , \ */
      _______, _______, _______, _______, _______, _______,  KC_TILD, KC_DQUO, KC_LBRC, KC_RBRC, KC_BSLS, _______,
                                                            /* # */
               _______,  KC_SPC, _______,   _______, _______, KC_HASH
    ),
     [_R_INTL] = LAYOUT_split_3x6_3(
      _______, _______, _______, _______, _______, _______, _______, _______,  GER_UE, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, US_EURO, _______,  GER_OE, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______, _______
    ),
    [_R_NAV] = LAYOUT_split_3x6_3(
      _______, C(KC_Q), C(KC_W), C(KC_F), C(KC_P), C(KC_B),  _______, KC_HOME,    _______,  KC_END, _______, _______,
      _______, LALT_CA, LCTL_CR, LSFT_CS, C(KC_T),  KC_SPC,  _______, KC_LEFT,  KC_DOWN, KC_UP, KC_RGHT, _______,
      _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_D), C(KC_V),  _______, _______,  KC_PGDN, KC_PGUP, _______, _______,
               _______, _______, _______,   _______, _______,  _______
    ),
    [_R_MOUSE] = LAYOUT_split_3x6_3(
      _______, S(C(KC_Q)), S(C(KC_W)), S(C(KC_F)), S(C(KC_P)), S(C(KC_B)),  _______, KC_BTN4, KC_MS_U, KC_BTN5, _______, _______,
      _______, S(C(KC_A)), S(C(KC_R)), S(C(KC_S)), S(C(KC_T)), S(C(KC_G)),  _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
      _______, S(C(KC_Z)), S(C(KC_X)), S(C(KC_C)), S(C(KC_D)), S(C(KC_V)),  _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______,
                 _______,    _______,    _______,  KC_BTN3, KC_BTN1, KC_BTN2    ),
    [_R_ALT] = LAYOUT_split_3x6_3(
      _______, A(C(KC_Q)), A(C(KC_W)), A(C(KC_F)), A(C(KC_P)), A(C(KC_B)),  _______, _______, _______, _______, _______, _______,
      _______, A(C(KC_A)), A(C(KC_R)), A(C(KC_S)), A(C(KC_T)), A(C(KC_G)),  _______, _______, _______, _______, _______, _______,
      _______, A(C(KC_Z)), A(C(KC_X)), A(C(KC_C)), A(C(KC_D)), A(C(KC_V)),  _______, _______, _______, _______, _______, _______,
                  _______,  _______, _______, _______, _______, _______
    ),
};

