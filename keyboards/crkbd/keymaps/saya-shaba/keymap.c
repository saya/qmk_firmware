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
    _R_SYM,
    _R_NAV
};

#define GER_AE US_ADIA
#define GER_OE US_ODIA
#define GER_UE US_UDIA
#define GER_SS US_SS

#define LALT_A LALT_T(KC_A)
#define LCTL_R LCTL_T(KC_R)
#define LSFT_S LSFT_T(KC_S)
#define RSYM_D LT(_R_SYM, KC_D)
#define RSYM_T LT(_R_SYM, KC_T)
#define LSFT_X LSFT_T(KC_X)
#define LGUI_C LGUI_T(KC_C)
#define NAV_SPC LT(_R_NAV, KC_SPACE)

#define RSFT_E RSFT_T(KC_E)
#define RCTL_I RCTL_T(KC_I)
#define LALT_O LALT_T(KC_O)
#define LNUM_H LT(_L_NUM, KC_H)
#define LNUM_N LT(_L_NUM, KC_N)
#define LGUI_COMM LGUI_T(KC_COMM)
#define RSFT_DOT RSFT_T(KC_DOT)
#define SFT_BSPC RSFT_T(KC_BSPC)
#define FUN_DEL LT(_L_FUN, KC_DEL)

#define RSFT_INS RSFT(KC_INS)

enum combos {
  UE_UMLAUT,
  OE_UMLAUT,
  SS_UMLAUT,
  AE_UMLAUT
};

const uint16_t PROGMEM ue_umlaut_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM oe_umlaut_combo[] = {LGUI_COMM, RSFT_DOT, COMBO_END};
const uint16_t PROGMEM ss_umlaut_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM ae_umlaut_combo[] = {LSFT_X, LGUI_C, COMBO_END};

combo_t key_combos[] = {
  [UE_UMLAUT] = COMBO(ue_umlaut_combo, GER_UE),
  [OE_UMLAUT] = COMBO(oe_umlaut_combo, GER_OE),
  [SS_UMLAUT] = COMBO(ss_umlaut_combo, GER_SS),
  [AE_UMLAUT] = COMBO(ae_umlaut_combo, GER_AE)
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT_split_3x6_3(
                                                                                                /*  ; :       _   */
      RSFT_INS,   KC_Q,   KC_W,   KC_F,    KC_P,   KC_B,       KC_J,     KC_L,      KC_U,     KC_Y, KC_SCLN,  KC_UNDS,
    /* -                                                                                                      ' " */
       KC_MINS, LALT_A, LCTL_R, LSFT_S,  RSYM_T,   KC_G,       KC_M,   LNUM_N,    RSFT_E,   RCTL_I,  LALT_O,  KC_QUOT,
      KC_ENTER,   KC_Z, LSFT_X, LGUI_C,  RSYM_D,   KC_V,       KC_K,   LNUM_H, LGUI_COMM, RSFT_DOT, KC_SLSH, KC_ENTER,
                                KC_ESC, NAV_SPC, KC_TAB,     KC_ENT, SFT_BSPC,   FUN_DEL
    ),
    [_L_NUM] = LAYOUT_split_3x6_3(
            /*  %      ,                   # */
      _______,  KC_PERC, KC_7, KC_8,   KC_9, KC_HASH,  _______, _______, _______, _______, _______, _______,
            /*   =                           *                                             : */
      _______,   KC_EQL, KC_4, KC_5,   KC_6, KC_ASTR,  _______, _______, _______, _______, KC_COLN, _______,
            /*    @                          + */
      _______,    KC_AT, KC_1, KC_2,   KC_3, KC_PLUS,  _______, _______, _______, _______, _______, _______,
                               KC_0, KC_SPC, _______,  _______, _______, _______
    ),
    [_L_FUN] = LAYOUT_split_3x6_3(
     RSFT_INS,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,  _______, _______, _______, _______, _______, _______,
      KC_CAPS,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,  _______, _______, _______, _______, _______, _______,
      _______,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,  _______, _______, _______, _______, _______, _______,
               _______,  _______, _______, _______, _______, _______
    ),
    [_R_SYM] = LAYOUT_split_3x6_3(
                                                          /* &      , |      , {      , }      , ^        */
      _______, _______, _______, _______, _______, _______,  KC_AMPR, KC_PIPE, KC_LCBR, KC_RCBR, KC_CIRC, _______,
                                                          /* $      , =      , (      , )      , ` ~      */
      _______, _______, _______, _______, _______, _______,   KC_DLR,  KC_EQL, KC_LPRN, KC_RPRN,  KC_GRV, _______,
                                                          /* ~      , !      , [      , ]      , \        */
      _______, _______, _______, _______, _______, _______,  KC_TILD, KC_EXLM, KC_LBRC, KC_RBRC, KC_BSLS, _______,
               _______,  KC_SPC, _______,   _______, _______, _______
    ),
    [_R_NAV] = LAYOUT_split_3x6_3(
      _______, _______, _______, _______, _______, _______, _______,  KC_HOME, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,  KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
      _______, _______, _______, _______, _______, _______,  _______, KC_END , KC_PGDN, KC_PGUP, _______, _______,
               _______, _______, _______,   _______, _______,  _______
    )
};

