#include "dz60.h"

enum{
     DV,
     QW,
     SY,
     BL,
};

#define DU_ENT    ALT_T(KC_ENT)
#define DU_TAB    ALT_T(KC_TAB)
#define DU_RSFT0  MT(MOD_RSFT,KC_Z)
#define DU_RSFT1  MT(MOD_RSFT,KC_SLSH)
#define ______    KC_TRNS
#define DU_SPC    LT(SY,KC_SPC)

#define KEYMAP_ARROW_3SPC_ISO( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K014, \
	K100,       K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, \
	K200,       K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213,       \
	K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310,       K312, K313, K314, \
	K400, K401,       K403, K404,       K406,       K408,       K410, K411, K412, K413, K414  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  KC_NO, K014 }, \
	{ K100,  KC_NO, K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113,  K114 }, \
	{ K200,  KC_NO, K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213,  KC_NO}, \
	{ K300,  KC_NO, K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  KC_NO, K312,  K313,  K314 }, \
	{ K400,  K401,  KC_NO, K403,  K404,  KC_NO, K406,  KC_NO, K408,  KC_NO, K410,  K411,  K412,  K413,  K414 }  \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[DV] = KEYMAP_ARROW_3SPC_ISO(
    KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC,  KC_BSPC,
    DU_TAB,  KC_QUOT, KC_COMM, KC_DOT, KC_P,   KC_Y,   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,   KC_BSLS,
    KC_LCTL, KC_A,    KC_O,    KC_E,   KC_U,   KC_I,   KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, DU_ENT,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,   KC_K,   KC_X,   KC_B,    KC_M,    KC_W,    KC_V,    DU_RSFT0,KC_UP,   KC_DEL,
    KC_LCTL, KC_LGUI, KC_LALT, DU_SPC, DU_SPC, DU_SPC, TG(QW),  MO(BL),  KC_LEFT, KC_DOWN, KC_RIGHT
  ),
	[QW] = KEYMAP_ARROW_3SPC_ISO(
    KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    DU_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, DU_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  DU_RSFT1,KC_UP,   KC_DEL,
    KC_LCTL, KC_LGUI, KC_LALT, DU_SPC, DU_SPC, DU_SPC, KC_TRNS, MO(BL),  KC_LEFT, KC_DOWN, KC_RIGHT
  ),
	[SY] = KEYMAP_ARROW_3SPC_ISO(
    ______,  KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ______,
    ______,  ______,  KC_UP,   ______, KC_LPRN,KC_SLSH,KC_BSLS, KC_RPRN, ______,  ______,  ______,  ______,  ______,______,
    KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT,KC_LCBR,KC_TILD,KC_PIPE, KC_RCBR, ______,  ______,  ______,  ______,  ______,
    ______,  ______,  ______,  ______, KC_LBRC,______, ______,  KC_RBRC, ______,  ______,  ______,  ______,  ______,
    ______,  ______,  ______,  ______, ______, ______, ______,  ______,  ______,  ______,  ______
  ),
	[BL] = KEYMAP_ARROW_3SPC_ISO(
    ______,  KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ______,
    ______,  BL_TOGG, BL_STEP, BL_INC, BL_INC, ______, ______,  ______,  ______,  ______,  ______,  ______,  ______,______,
    ______,  RGB_TOG, RGB_MOD, RGB_HUI,RGB_HUD,RGB_SAI,RGB_SAD, RGB_VAI, RGB_VAD, ______,  ______,  ______,  ______,
    ______,  ______,  ______,  ______, ______, ______, ______,  ______,  ______,  ______,  ______,  ______,  ______,
    ______,  ______,  ______,  ______, ______, ______, ______,  ______,  ______,  ______,  ______
  ),
};
