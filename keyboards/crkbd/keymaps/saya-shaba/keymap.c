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
#define RINTL_T LT(_R_INTL, KC_T)
#define LSFT_X LSFT_T(KC_X)
#define LGUI_C LGUI_T(KC_C)
#define NAV_SPC LT(_R_NAV, KC_SPACE)

#define LINTL_N LT(_L_INTL, KC_N)
#define RSFT_E RSFT_T(KC_E)
#define RCTL_I RCTL_T(KC_I)
#define LALT_O LALT_T(KC_O)
#define LNUM_H LT(_L_NUM, KC_H)
#define LGUI_COMM LGUI_T(KC_COMM)
#define RSFT_DOT RSFT_T(KC_DOT)
#define SFT_BSPC RSFT_T(KC_BSPC)
#define FUN_DEL LT(_L_FUN, KC_DEL)

#define RSFT_INS RSFT(KC_INS)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT_split_3x6_3(
                                                                                                /*  ; :       _   */
      RSFT_INS,   KC_Q,   KC_W,   KC_F,    KC_P,   KC_B,       KC_J,     KC_L,      KC_U,     KC_Y, KC_SCLN,  KC_UNDS,
    /* -                                                                                                      ' " */
       KC_MINS, LALT_A, LCTL_R, LSFT_S, RINTL_T,   KC_G,       KC_M,  LINTL_N,    RSFT_E,   RCTL_I,  LALT_O,  KC_QUOT,
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
    [_L_INTL] = LAYOUT_split_3x6_3(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______,  GER_AE, _______,  GER_SS, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______, _______
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
     [_R_INTL] = LAYOUT_split_3x6_3(
      _______, _______, _______, _______, _______, _______, _______, _______,  GER_UE, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, US_EURO, _______,  GER_OE, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______, _______
    ),
    [_R_NAV] = LAYOUT_split_3x6_3(
      _______, _______, _______, _______, _______, _______, _______,  KC_HOME, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,  KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
      _______, _______, _______, _______, _______, _______,  _______, KC_END , KC_PGDN, KC_PGUP, _______, _______,
               _______, _______, _______,   _______, _______,  _______
    )
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM caps_word_combo[] = {KC_W, KC_F, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(caps_word_combo, CAPS_WORD),
};
#endif

#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;
        case KC_GRV:
        default:
            return false;  // Deactivate Caps Word.
    }
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
