#include QMK_KEYBOARD_H

#define DV 0
#define QW 1
#define FN 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [DV] = LAYOUT_60_hhkb(
    KC_ESC,         KC_1,    KC_2,    KC_3,   KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, _______, KC_BSPC,
    LALT_T(KC_TAB), KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,           RALT_T(KC_BSLS),
    KC_LCTRL,       KC_A,    KC_O,    KC_E,   KC_U,     KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,                   RCTL_T(KC_ENT),
    KC_LSFT,        KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,                   KC_DEL,
                    KC_LGUI, KC_LALT,                            LT(FN, KC_SPC),            TG(QW),  KC_RGUI),

  [QW] = LAYOUT_60_hhkb(
    _______,        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  _______, _______,
    _______,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          _______,
    _______,        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   _______,
    _______,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   _______,
                    _______, _______,                            _______,                   _______, _______),

  [FN] = LAYOUT_60_hhkb(
    _______,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
    KC_BSPC,        KC_GRV,  KC_UP,   _______, KC_LPRN, KC_SLSH, KC_BSLS, KC_RPRN, _______, _______, _______, RGB_TOG, _______,          _______,
    _______,        KC_LEFT, KC_DOWN, KC_RGHT, KC_LCBR, KC_TILD, KC_PIPE, KC_RCBR, _______, _______, _______, _______,                   _______,
    _______,        _______, _______, _______, KC_LBRC, _______, _______, KC_RBRC, _______, _______, _______, _______,                   _______,
                    _______, _______,                            _______,                   _______, _______),

};
