#include "xd60.h"
#include "action_layer.h"

enum keymap_layout {
    QWERTY = 0,
    DVORAK,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: QWERTY Layer
  [QWERTY] = KEYMAP(
         KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_GRV,   KC_BSPC,   \
         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,   \
         KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,             KC_ENT,    \
   OSM(MOD_LSFT), KC_NO,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,    KC_DEL,    \
         KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RGUI, KC_RALT,  KC_LEFT, KC_DOWN,  KC_RIGHT),

  // 1: DVORAK Layer
  [DVORAK] = KEYMAP(
         KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_LBRC,  KC_RBRC,  KC_GRV,  KC_BSPC,   \
         KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,   KC_Y,   KC_F,   KC_G,   KC_C,   KC_R,    KC_L,    KC_SLSH,  KC_EQL,            KC_BSLS,   \
         KC_CAPS, KC_A,    KC_O,    KC_E,    KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,    KC_S,    KC_MINS,  KC_NO,             KC_ENT,    \
   OSM(MOD_LSFT), KC_NO,   KC_SCLN, KC_Q,    KC_J,   KC_K,   KC_X,   KC_B,   KC_M,   KC_W,    KC_V,    KC_Z,     KC_RSFT, KC_UP,    KC_DEL,    \
         KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RGUI, KC_RALT,  KC_LEFT, KC_DOWN,  KC_RIGHT),

};

const uint16_t PROGMEM fn_actions[] = {
//    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function

  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
    break;
  }

  return MACRO_NONE;
};

void matrix_scan_user(void) {

  // Layer LED indicators
  uint32_t layer = layer_state;

  if (layer & (1<<1)) {
    xd60_esc_led_on();
  } else {
    xd60_esc_led_off();
  }

  /*
  if (layer & (1<<2)) {
    xd60_poker_leds_on();
    xd60_esc_led_on();
  } else {
    xd60_poker_leds_off();
    xd60_esc_led_off();
  }
  */
};
