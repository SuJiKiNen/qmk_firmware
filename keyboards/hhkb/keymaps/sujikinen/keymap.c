#include "hhkb.h"

enum keymap_layout {
    DVORAK = 0,
    QWERTY,
    SYMBOL,
};
enum {
    LS = 0,
};

enum macros{
    MACRO_SYMBOL_LSFT_TAP=0,
    MACRO_SYMBOL_RSFT_TAP,
};

#define _______ KC_TRNS
#define DU_ENT  CTL_T(KC_ENT)
#define DU_TAB  ALT_T(KC_TAB)
#define DU_SPC  LT(SYMBOL,KC_SPC)
#define DU_BSLS ALT_T(KC_BSLS)
#define M_LSFT              M(MACRO_SYMBOL_LSFT_TAP)
#define M_RSFT              M(MACRO_SYMBOL_RSFT_TAP)


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
               TD(LS), KC_A,   KC_O,   KC_E,   KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,   KC_S,   KC_MINS,DU_ENT, \
               M_LSFT, KC_SCLN,KC_Q,   KC_J,   KC_K,   KC_X,   KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,   M_RSFT ,KC_DEL, \
                               KC_LGUI,KC_LALT,                DU_SPC,                 KC_RALT,KC_RGUI),
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
        M_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,M_RSFT,KC_DEL, \
                               KC_LGUI,KC_LALT,                DU_SPC,                 KC_RALT,KC_RGUI),

    /* Layer 6: SpaceFN
     * ,-----------------------------------------------------------------------------------------.
     * |  `  | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |     | Del |
     * |-----------------------------------------------------------------------------------------|
     * |        | End | Up  | Hom |     |     |     | Hom | Up  | End | Psc | Slk | Pau |  Ins   |
     * |-----------------------------------------------------------------------------------------|
     * |          | Lef | Dow | Rig | PgU |     | PgU | Lef | Dow | Rig |     |     |            |
     * |-----------------------------------------------------------------------------------------|
     * |             |     |     | PgD |     | Spc | PgD |  `  |  ~  |     |     |         |     |
     * `-----------------------------------------------------------------------------------------'
     *           |     |        |                                   |        |     |
     *           `-----------------------------------------------------------------'
     */
    [SYMBOL] =
        KEYMAP(_______,KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,KC_F12,_______,_______, \
               _______,_______,KC_UP  ,_______,KC_LPRN,KC_BSLS,KC_SLSH,KC_RPRN,_______,_______,_______,_______,_______,_______, \
               KC_BSPC,KC_LEFT,KC_DOWN,KC_RGHT,KC_LCBR,KC_TILD,KC_PIPE,KC_RCBR,_______,_______,_______,_______,_______, \
               _______,_______,_______,_______,KC_LBRC,_______,_______,KC_RBRC,_______,_______,_______,_______,_______, \
                               _______,_______,                _______,                 _______,_______),
};

void dance_layer_switch(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code16(KC_LCTL);
            break;
        case 2:
            if ( IS_LAYER_ON(QWERTY) ){
                layer_move(DVORAK);
            }else{
                layer_move(QWERTY);
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
        // hold for shift,tap for one shot symbol layer
        case MACRO_SYMBOL_LSFT_TAP:
            if (record->event.pressed) {
                register_code16(KC_LSFT);
                lsft_pressed_time = timer_read();
            }else{
                unregister_code16(KC_LSFT);
                if (!lshift_interrupted && timer_elapsed(lsft_pressed_time) < 200 ){
                    set_oneshot_layer(SYMBOL, ONESHOT_START);
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
                    set_oneshot_layer(SYMBOL, ONESHOT_START);
                    clear_oneshot_layer_state(ONESHOT_PRESSED);
                }
                rsft_pressed_time = 0;
                rshift_interrupted = false;
            }
            break;
    }
    return MACRO_NONE;
}
