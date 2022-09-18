#include QMK_KEYBOARD_H
#include "keymap_us_international.h"
#include "features/achordion.h"

#define LAYOUT_shaba( \
  K00, K01, K02, K03, K04, K05,    K06, K07, K08, K09, K0a, K0b, \
  K10, K11, K12, K13, K14, K15,    K16, K17, K18, K19, K1a, K1b, \
  K20, K21, K22, K23, K24, K25,    K26, K27, K28, K29, K2a, K2b, \
       K31, K32, K33, K34, K35,    K36, K37, K38, K39, K3a \
) \
LAYOUT( \
  K00, K01, K02, K03, K04, K05,                               K06, K07, K08, K09, K0a, K0b, \
  K10, K11, K12, K13, K14, K15,                               K16, K17, K18, K19, K1a, K1b, \
  K20, K21, K22, K23, K24, K25, KC_NO, KC_NO,   KC_NO, KC_NO, K26, K27, K28, K29, K2a, K2b, \
                 K31, K32, K33,   K34,   K35,     K36,   K37, K38, K39, K3a \
)

enum layers {
    _COLEMAK_DH = 0,
    _INTL,
    _FUN,
    _L_NUM,
    _R_SYM,
    _NAV,
    _SFT_CTL,
};

#define GER_AE   US_ADIA
#define GER_OE   US_ODIA
#define GER_UE   US_UDIA
#define GER_SS   US_SS

// Mod-taps with non-basic keycodes, remapped via 'tap_overrides'.
// See https://precondition.github.io/home-row-mods#using-non-basic-keycodes-in-mod-taps.
// The specific keycodes used for the tap actions (F20, F21, ...) are not important,
// they just need to be distinct.
#define LALT_CA MT(MOD_LALT, KC_F13) // --> MT(MOD_LALT, C(KC_A))
#define LCTL_CR MT(MOD_LCTL, KC_F14) // --> MT(MOD_LCTL, C(KC_R))
#define LSFT_CS MT(MOD_LSFT, KC_F15) // --> MT(MOD_LSFT, C(KC_S))
#define RNAV_CT LT(_NAV,     KC_F16) // --> LT(_NAV,     C(KC_T))

#define  LALT_A  MT(MOD_LALT, KC_A)
#define  LCTL_R  MT(MOD_LCTL, KC_R)
#define  LSFT_SS MT(MOD_LSFT, KC_F17) // --> MT(MOD_LSFT, GER_SS)
#define  LSFT_S  MT(MOD_LSFT, KC_S)
#define  RSYM_T  LT(_R_SYM, KC_T)

#define  LNUM_N LT(_L_NUM, KC_N)
#define  RSFT_E MT(MOD_RSFT, KC_E)
#define  RSFT_EU MT(MOD_RSFT, KC_F18) // --> MT(MOD_RSFT, US_EURO)
#define  RCTL_I MT(MOD_RCTL, KC_I)
#define  LALT_O MT(MOD_LALT, KC_O)

#define NAV_SPC LT(_NAV, KC_SPACE)
#define SFT_TAB LT(_SFT_CTL, KC_TAB)

#define INT_ENT LT(_INTL, KC_ENTER)
#define SFT_BSP MT(MOD_LSFT, KC_BSPACE)
#define FUN_DEL LT(_FUN, KC_DELETE)

struct TapOverride {
  uint16_t pressed_keycode;
  uint16_t tap_keycode_override;
};

const struct TapOverride tap_overrides [] = {
  {LALT_CA, C(KC_A)},
  {LCTL_CR, C(KC_R)},
  {LSFT_CS, C(KC_S)},
  {RNAV_CT, C(KC_T)},
  {LSFT_SS, GER_SS},
  {RSFT_EU, US_EURO},
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Index finger home row
        case LSFT_S:
        case RSFT_E:
            return TAPPING_TERM - 25;
        // Middle finger home row
        case RSYM_T:
        case LNUM_N:
            return TAPPING_TERM - 25;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Immediately select the hold action when another key is pressed.
        case INT_ENT:
        case SFT_BSP:
            return true;
        // Do not select the hold action when another key is pressed.
        default:
            return false;
    }
}

bool override_tap_with(uint16_t tap_keycode, keyrecord_t *record) {
      if (record->event.pressed && record->tap.count > 0) {
    tap_code16(tap_keycode);
        return false;
      }
  return true;
      }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }

  for (int i = 0; i < sizeof(tap_overrides)/sizeof(tap_overrides[0]); ++i) {
    if (keycode == tap_overrides[i].pressed_keycode) {
      return override_tap_with(tap_overrides[i].tap_keycode_override, record);
      }
  }

  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

// Cantor rows:    cols:
// 000000 444444   012345 012345
// 111111 555555   012345 012345
// 222222 666666   012345 012345
//    333 777         012 012
static bool on_left_alphas(keypos_t pos) {
  return pos.row <= 2;
}

static bool on_right_alphas(keypos_t pos) {
  return 4 <= pos.row && pos.row <= 6;
}

// Revise selected tap-hold "hold" decisions to "tap".
// Called while a tap-hold key is pressed down and some other key is pressed
// after the tapping term and before achordion_timeout(). Usually this would
// count as a "hold". But if this method returns false, the decision is revised
// to "tap".
bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
  bool continue_treat_as_hold = true;

  switch (tap_hold_keycode) {
    case LALT_A:
    case LCTL_R:
    case LSFT_S:
      continue_treat_as_hold = !on_left_alphas(other_record->event.key);
      break;
    case RSFT_E:
    case RCTL_I:
    case LALT_O:
      continue_treat_as_hold = !on_right_alphas(other_record->event.key);
      break;
  }

  return continue_treat_as_hold;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT_shaba(
      G(KC_L),    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_UNDS,
      KC_MINS,  LALT_A,  LCTL_R,  LSFT_S,  RSYM_T,    KC_G,         KC_M,  LNUM_N,  RSFT_E,  RCTL_I,  LALT_O, KC_QUOT,
      KC_LGUI,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
               KC_LEFT, KC_RGHT,  KC_ESC, NAV_SPC, SFT_TAB,      INT_ENT, SFT_BSP, FUN_DEL,   KC_UP, KC_DOWN
    ),
    [_INTL] = LAYOUT_shaba(
      _______, _______, _______, _______, _______, _______,      _______, _______,  GER_UE, _______, _______, _______,
      _______,  GER_AE, _______, LSFT_SS, _______, _______,      _______, _______, RSFT_EU, _______,  GER_OE, _______,
      _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______
    ),
    [_FUN] = LAYOUT_shaba(
QK_BOOTLOADER,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,      _______, _______, _______, _______, _______, _______,
      KC_CAPS,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,      _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______,
       KC_INS,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,      _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
               _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______
    ),
    [_L_NUM] = LAYOUT_shaba(
      _______, KC_PERC,    KC_7,    KC_8,    KC_9, KC_HASH,      _______, _______, _______, _______, _______, _______,
      _______,  KC_EQL,    KC_4,    KC_5,    KC_6, KC_ASTR,      _______, _______, _______, _______, KC_COLN, _______,
      _______,  KC_DLR,    KC_1,    KC_2,    KC_3, KC_PLUS,      _______, _______, _______, _______, _______, _______,
               _______, _______,    KC_0,  KC_SPC,  KC_TAB,      _______, _______, _______, _______, _______
    ),
    [_R_SYM] = LAYOUT_shaba(
      _______, _______, _______, _______, _______, _______,        KC_AT, KC_PIPE, KC_LCBR, KC_RCBR, KC_CIRC, _______,
      _______, _______, _______, _______, _______, _______,      KC_AMPR, KC_DQUO, KC_LPRN, KC_RPRN, KC_EXLM, _______,
      _______, _______, _______, _______, _______, _______,      KC_TILD,  KC_GRV, KC_LBRC, KC_RBRC, KC_BSLS, _______,
               _______, _______, _______, _______, _______,      _______, KC_BSPC,  KC_DEL, _______, _______
    ),
    [_NAV] = LAYOUT_shaba(
      _______, C(KC_Q), C(KC_W), C(KC_F), C(KC_P), C(KC_B),      _______, KC_HOME,    KC_UP,  KC_END, _______, _______,
      _______, LALT_CA, LCTL_CR, LSFT_CS, RNAV_CT,  KC_SPC,      _______, KC_LEFT,  KC_DOWN, KC_RGHT, _______, _______,
      _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_D), C(KC_V),      _______, _______,  KC_PGUP, KC_PGDN, _______, _______,
               _______, _______, _______, _______, _______,      _______, _______,  _______, _______, _______
    ),
    [_SFT_CTL] = LAYOUT_shaba(
      _______, S(C(KC_Q)), S(C(KC_W)), S(C(KC_F)), S(C(KC_P)), S(C(KC_B)),      _______, _______, _______, _______, _______, _______,
      _______, S(C(KC_A)), S(C(KC_R)), S(C(KC_S)), S(C(KC_T)), S(C(KC_G)),      _______, _______, _______, _______, _______, _______,
      _______, S(C(KC_Z)), S(C(KC_X)), S(C(KC_C)), S(C(KC_D)), S(C(KC_V)),      _______, _______, _______, _______, _______, _______,
                  _______,    _______,    _______,    _______,    _______,      _______, _______, _______, _______, _______
    )
};
