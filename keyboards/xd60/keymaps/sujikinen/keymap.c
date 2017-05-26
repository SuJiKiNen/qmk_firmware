#include "xd60.h"
enum kepmap_layout{
    DV = 0,
    QW,
    FN,
    SY,
};

enum {
    LS = 0,
};

enum macros{
    MACRO_BREATH_TOGGLE = 0,
    MACRO_BREATH_SPEED_INC,
    MACRO_BREATH_SPEED_DEC,
    MACRO_BREATH_DEFAULT,
    MACRO_SYMBOL_LSFT_TAP,
    MACRO_SYMBOL_RSFT_TAP,
};

#define M_BRTOG             M(MACRO_BREATH_TOGGLE)
#define M_BSPDU             M(MACRO_BREATH_SPEED_INC)
#define M_BSPDD             M(MACRO_BREATH_SPEED_DEC)
#define M_BDFLT             M(MACRO_BREATH_DEFAULT)
#define M_LSFT              M(MACRO_SYMBOL_LSFT_TAP)
#define M_RSFT              M(MACRO_SYMBOL_RSFT_TAP)
#define _______ KC_TRNS
#define DU_ENT  CTL_T(KC_ENT)
#define DU_TAB  ALT_T(KC_TAB)
#define DU_BSLS ALT_T(KC_BSLS)
#define DU_SPC  LT(SY,KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // 0: DVORAK Layer
    [DV] = KEYMAP(
             KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_LBRC,KC_RBRC, KC_GRV, KC_BSPC,\
             DU_TAB,KC_QUOT,KC_COMM, KC_DOT,   KC_P,   KC_Y,   KC_F,   KC_G,   KC_C,   KC_R,   KC_L,KC_SLSH, KC_EQL,         DU_BSLS,\
             TD(LS),   KC_A,   KC_O,   KC_E,   KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,   KC_S,KC_MINS,  KC_NO,          DU_ENT,\
            KC_LSFT,  KC_NO,KC_SCLN,   KC_Q,   KC_J,   KC_K,   KC_X,   KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,KC_RSFT, KC_DEL,   KC_UP,\
            KC_LCTL,KC_LGUI,KC_LALT,                 DU_SPC,                                KC_RALT, MO(FN),KC_LEFT,KC_DOWN,KC_RIGHT),
    // 1: QWERTY Layer
    [QW] = KEYMAP(
             KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS, KC_EQL, KC_GRV, KC_BSPC,\
             DU_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,KC_RBRC,         DU_BSLS,\
             TD(LS),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,  KC_NO,          DU_ENT,\
            KC_LSFT,  KC_NO,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT, KC_DEL,   KC_UP,\
            KC_LCTL,KC_LGUI,KC_LALT,                 DU_SPC,                                KC_RALT, MO(FN),KC_LEFT,KC_DOWN,KC_RIGHT),


    [FN] = KEYMAP(
            _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,_______,_______,\
            _______,_______,  KC_UP,_______,_______,_______,_______,_______,_______,_______,_______,BL_TOGG, BL_INC,        BL_STEP,\
            _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,_______,_______,_______,_______,_______,_______, BL_DEC,        M_BDFLT,\
            _______,_______,_______,_______,_______,M_BRTOG,_______,_______,_______,_______,_______,_______,_______,_______,M_BSPDU,\
            _______,_______,_______,                _______,                                _______,_______,_______,_______,M_BSPDD),
    [SY] = KEYMAP(
            _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,KC_F11,  KC_F12,_______,_______,\
            _______,_______,  KC_UP,_______,KC_LPRN,_______,_______,KC_RPRN,_______,_______,_______,_______,_______,        _______,\
            _______,KC_LEFT,KC_DOWN,KC_RGHT,KC_LCBR,_______,_______,KC_RCBR,_______,_______,_______,_______,_______,        _______,\
            _______,_______,_______,_______,_______,KC_LBRC,_______,_______,KC_RBRC,_______,_______,_______,_______,_______,_______,\
            _______,_______,_______,                _______,                                _______,_______,_______,_______,_______),

};
void dance_layer_switch(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code16(KC_LCTL);
            break;
        case 2:
            if ( IS_LAYER_ON(QW) ){
                layer_move(DV);
            }else{
                layer_move(QW);
            }
            break;
    }
}
void dance_layer_reset(qk_tap_dance_state_t *state,void *user_data){
    unregister_code16(KC_LCTL);
}
qk_tap_dance_action_t tap_dance_actions[] = {
    // tap one for oneshot shift,twice to switch between qwerty and dvorak
    [LS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,dance_layer_switch,dance_layer_reset)
};

const uint16_t PROGMEM fn_actions[] = {
    //    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
};
void led_set_dv_indicator(void) {
    if ( IS_LAYER_ON(DV) ) {
        // Turn on
        xd60_caps_led_on();
    } else {
        // Turn off
        xd60_caps_led_off();
    }
}
void matrix_scan_user(void){
    led_set_dv_indicator();
}
void matrix_init_user(void){
    xd60_caps_led_on();
}
/*
static bool lshift_interrupted = false;
static bool rshift_interrupted = false;
static uint16_t lsft_pressed_time = 0;
static uint16_t rsft_pressed_time = 0;

// if we pressed shift,before we release the shift key,
// if we pressed any other key,not trigger the oneshot layer
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed){
        if (lsft_pressed_time > 0 ){
            lshift_interrupted = true;
        }
        if (rsft_pressed_time > 0 ){
            rshift_interrupted = true;
        }
    }
    return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id){
        case MACRO_BREATH_TOGGLE:
            if (record->event.pressed)
            {
                //breathing_toggle();
                return MACRO_NONE;
            }
            break;

        case MACRO_BREATH_SPEED_INC:
            if (record->event.pressed)
            {
                //breathing_speed_inc(1);
                return MACRO_NONE;
            }
            break;

        case MACRO_BREATH_SPEED_DEC:
            if (record->event.pressed)
            {
                //breathing_speed_dec(1);
                return MACRO_NONE;
            }
            break;

        case MACRO_BREATH_DEFAULT:
            if (record->event.pressed)
            {
               //breathing_defaults();
                return MACRO_NONE; 
            }
            break;
        // hold for shift,tap for one shot symbol layer
        case MACRO_SYMBOL_LSFT_TAP:
            if (record->event.pressed) {
                register_code16(KC_LSFT);
                lsft_pressed_time = timer_read();
            }else{
                unregister_code16(KC_LSFT);
                if (!lshift_interrupted && timer_elapsed(lsft_pressed_time) < 200 ){
                    set_oneshot_layer(SY, ONESHOT_START);
                    clear_oneshot_layer_state(ONESHOT_PRESSED);
                }
                lsft_pressed_time = 0;
                lshift_interrupted = false;
            }
            break;

        case MACRO_SYMBOL_RSFT_TAP:
            if (record->event.pressed) {
                register_code16(KC_RSFT);
                rsft_pressed_time = timer_read();
            }else{
                unregister_code16(KC_RSFT);
                if (!rshift_interrupted && timer_elapsed(rsft_pressed_time) < 200 ){
                    set_oneshot_layer(SY, ONESHOT_START);
                    clear_oneshot_layer_state(ONESHOT_PRESSED);
                }
                rsft_pressed_time = 0;
                rshift_interrupted = false;
            }
            break;
    }
    return MACRO_NONE;
}
*/
