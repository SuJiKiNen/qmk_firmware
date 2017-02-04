#include "xd60.h"
#include "action_layer.h"
#include "eeconfig.h"
enum keymap_layout {
    QWERTY = 0,
    DVORAK,
    FUNCTION,
};
enum{
    MAGIC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // 0: QWERTY Layer
    [QWERTY] = KEYMAP(
            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_GRV,   KC_BSPC,   \
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,   \
            TD(0),   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,             KC_ENT,    \
            KC_LSPO, KC_BSPC, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_NO,   KC_NO,    KC_RSPC,   \
            KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RGUI, KC_RALT,  KC_LEFT, KC_DOWN,  KC_RIGHT),

    // 1: DVORAK Layer
    [DVORAK] = KEYMAP(
            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_LBRC,  KC_RBRC,  KC_GRV,  KC_BSPC,   \
            KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,   KC_Y,   KC_F,   KC_G,   KC_C,   KC_R,    KC_L,    KC_SLSH,  KC_EQL,            KC_BSLS,   \
            KC_TRNS, KC_A,    KC_O,    KC_E,    KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,    KC_S,    KC_MINS,  KC_NO,             KC_ENT,    \
            KC_LSPO, KC_BSPC, KC_SCLN, KC_Q,    KC_J,   KC_K,   KC_X,   KC_B,   KC_M,   KC_W,    KC_V,    KC_Z,     KC_NO,    KC_NO,   KC_RSPC,   \
            KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RGUI, KC_RALT,  KC_LEFT, KC_DOWN,  KC_RIGHT),

    [FUNCTION] = KEYMAP(
            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_GRV,   KC_BSPC,   \
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,   \
            TD(0),   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_LEFT,KC_DOWN,KC_UP,  KC_RIGHT,KC_SCLN, KC_QUOT,  KC_NO,             KC_ENT,    \
            KC_LSPO, KC_BSPC, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_NO,   KC_NO,    KC_RSPC,   \
            KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RGUI, KC_RALT,  KC_LEFT, KC_DOWN,  KC_RIGHT),


};
void dance_fin (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if timer_elapsed(state->time) > 150 {
            set_oneshot_mods(MOD_LSFT);
        }
    } else {
        if ( IS_LAYER_ON(QWERTY) ) {
            layer_move(DVORAK);
        }else{
            layer_move(QWERTY);
        }
    }
}
void dance_reset (qk_tap_dance_state_t *state,void *user_data){
    if ( state->count == 1) {
        unregister_code(KC_CAPS);
    }else{
        ;
    }
}
qk_tap_dance_action_t tap_dance_actions[] = {
    // type once for caps twice for toggle dvorak layout
    [0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_fin,dance_reset),
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
inline void xd60_dvorak_led_on(void){
    xd60_caps_led_on();
}
inline void xd60_dvorak_led_off(void){
    xd60_caps_led_off();
}

void matrix_scan_user(void) {
    // Layer LED indicators
    if ( IS_LAYER_ON(QWERTY) ) {
        xd60_dvorak_led_off();
    }else{
        xd60_dvorak_led_on();
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
