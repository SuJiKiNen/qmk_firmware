#include "hhkb.h"

enum keymap_layout {
    DVORAK = 0,
    QWERTY,
    SYMBOL,
};
enum {
    LS = 0,
};

#define _______ KC_TRNS
#define DU_ENT  CTL_T(KC_ENT)
#define DU_TAB  ALT_T(KC_TAB)
#define DU_SPC  LT(SYMBOL,KC_SPC)
#define DU_BSLS ALT_T(KC_BSLS)
#define QWE QWERTY


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Dvorak Layer
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  [  |  ]  |  `  | BSp |
     * |-----------------------------------------------------------------------------------------|
     * |  Tab   |  '  |  ,  |  .  |  P  |  Y  |  F  |  G  |  C  |  R  |  L  |  /  |  =  |   \    |
     * |-----------------------------------------------------------------------------------------|
     * | Control  |  A  |  O  |  E  |  U  |  I  |  D  |  H  |  T  |  N  |  S  |  -  |   Enter    |
     * |-----------------------------------------------------------------------------------------|
     * |    Shift    |  ;  |  Q  |  J  |  K  |  X  |  B  |  M  |  W  |  V  |  Z  |  Shift  | Fn0 |
     * `-----------------------------------------------------------------------------------------'
     *           |LAlt |  LGui  |              SpaceFN              |  RGui  |RAlt |
     *           `-----------------------------------------------------------------'
     */
    [DVORAK] =
        KEYMAP(KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_LBRC,KC_RBRC,KC_GRV, KC_BSPC, \
               DU_TAB, KC_QUOT,KC_COMM,KC_DOT, KC_P,   KC_Y,   KC_F,   KC_G,   KC_C,   KC_R,   KC_L,   KC_SLSH,KC_EQL, DU_BSLS, \
               KC_LCTL,KC_A,   KC_O,   KC_E,   KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,   KC_S,   KC_MINS,DU_ENT, \
               KC_LSFT,KC_SCLN,KC_Q,   KC_J,   KC_K,   KC_X,   KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,   KC_RSFT ,KC_DEL, \
               KC_LGUI,KC_LALT,                DU_SPC,                                 TG(QWE),KC_RGUI),
    /* Layer 1: Qwerty Layer
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  `  | BSp |
     * |-----------------------------------------------------------------------------------------|
     * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \    |
     * |-----------------------------------------------------------------------------------------|
     * | Control  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |   Enter    |
     * |-----------------------------------------------------------------------------------------|
     * |    Shift    |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  Shift  | Fn0 |
     * `-----------------------------------------------------------------------------------------'
     *           |LAlt |  LGui  |               SpaceFN             |  RGui  |RAlt |
     *           `-----------------------------------------------------------------'
     */
    [QWERTY] =
        KEYMAP(KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_GRV, KC_BSPC, \
               DU_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,DU_BSLS, \
               _______,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,DU_ENT, \
        KC_LSFT,KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,KC_DEL, \
               KC_LGUI,KC_LALT,                DU_SPC,                                 _______,KC_RGUI),

    [SYMBOL] =
        KEYMAP(_______,KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,KC_F12,_______,_______, \
               _______,_______,KC_UP  ,_______,KC_LPRN,KC_SLSH,KC_BSLS,KC_RPRN,_______,_______,_______,_______,_______,_______, \
               KC_BSPC,KC_LEFT,KC_DOWN,KC_RGHT,KC_LCBR,KC_TILD,KC_PIPE,KC_RCBR,_______,_______,_______,_______,_______, \
               _______,_______,_______,_______,KC_LBRC,_______,_______,KC_RBRC,_______,_______,_______,_______,_______, \
                               _______,_______,                _______,                 _______,_______),
};
