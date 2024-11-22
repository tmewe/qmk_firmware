#include QMK_KEYBOARD_H

// GENERAL
// Layer switches
#define SPC_L1 LT(1, KC_SPC)
#define ENT_L2 LT(2, KC_ENT)
#define BSPC_L2 LT(2, KC_BSPC)

// Key overrides
const key_override_t ae_key_override = ko_make_basic(KC_RALT, KC_A, RALT_T(KC_Q));
const key_override_t oe_key_override = ko_make_basic(KC_LALT, KC_O, RALT_T(KC_P));
const key_override_t ue_key_override = ko_make_basic(KC_LALT, KC_U, RALT_T(KC_Y));

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&ae_key_override,
	&oe_key_override,
	&ue_key_override
};

// Combos
const uint16_t PROGMEM F_J_ESC[] = {LGUI_T(KC_F), RGUI_T(KC_J), COMBO_END};
combo_t key_combos[] = {
    COMBO(F_J_ESC, KC_ESC),
};


// LAYER 0
// Left-hand home row mods
#define SFT_A LSFT_T(KC_A)
#define CTL_S LCTL_T(KC_S)
#define ALT_D LALT_T(KC_D)
#define GUI_F LGUI_T(KC_F)

// Right-hand home row mods
#define GUI_J RGUI_T(KC_J)
#define ALT_K RALT_T(KC_K)
#define CTL_L RCTL_T(KC_L)
#define SFT_SC RSFT_T(KC_SCLN)


// LAYER 1
// Left-hand brackets with home row mods
#define SFT_CIR LSFT_T(KC_CIRC)
#define CTL_LBR LCTL_T(KC_LBRC)
#define ALT_LCB LALT_T(KC_LCBR)
#define GUI_LPR LGUI_T(KC_LPRN)


// LAYER 2
// Left hand math symbols with home row mods
#define SFT_MIN LSFT_T(KC_MINS)
#define CTL_AST LCTL_T(KC_PAST)
#define ALT_SLS LALT_T(KC_SLSH)
#define GUI_PLS LGUI_T(KC_PPLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, S(KC_H),    KC_VOLU,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,   SFT_A,   CTL_S,   ALT_D,   GUI_F,    KC_G, S(KC_M),    KC_VOLD,    KC_H,   GUI_J,   ALT_K,   CTL_L,  SFT_SC, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      CW_TOGG,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          KC_HYPR,  SPC_L1, BSPC_L2,     ENT_L2,  SPC_L1, KC_HYPR
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, KC_QUES, KC_AMPR,  KC_DLR, KC_PERC, KC_TILD, _______,    KC_BRIU, _______, KC_UNDS, KC_EXLM, KC_HASH, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, SFT_CIR, CTL_LBR, ALT_LCB, GUI_LPR,  KC_EQL, _______,    KC_BRID, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_MINS, _______,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      _______, KC_PIPE, KC_RBRC, KC_RCBR, KC_RPRN,   KC_AT,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______, _______,    KC_MNXT, _______,    KC_4,    KC_5,    KC_6, _______, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, SFT_MIN, CTL_AST, ALT_SLS, GUI_PLS,  KC_EQL, BL_TOGG,    KC_MPRV,    KC_0,    KC_1,    KC_2,    KC_3, _______, DB_TOGG,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______,    KC_7,    KC_8,    KC_9, _______, EE_CLR,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
};

// The basic keycode limitation with Mod-Tap can be worked around by intercepting it in process_record_user.
// (https://docs.qmk.fm/mod_tap#changing-tap-function)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_CIR:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_CIRC);
                return false;
            }
            break;
        case ALT_LCB:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LCBR);
                return false;
            }
            break;
        case GUI_LPR:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;
    }
    return true;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
