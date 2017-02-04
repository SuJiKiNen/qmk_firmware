#include "tada68.h"


// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum kepmap_layout{
    QW = 0,
    DV,
    FN,
};
enum {
    TG_LY = 0,
};
enum macros{
    MACRO_BREATH_TOGGLE = 0,
    MACRO_BREATH_SPEED_INC,
    MACRO_BREATH_SPEED_DEC,
    MACRO_BREATH_DEFAULT,
};
#define M_BRTOG             M(MACRO_BREATH_TOGGLE)
#define M_BSPDU             M(MACRO_BREATH_SPEED_INC)
#define M_BSPDD             M(MACRO_BREATH_SPEED_DEC)
#define M_BDFLT             M(MACRO_BREATH_DEFAULT)

#define _______ KC_TRNS
#define DU_ENT CTL_T(KC_ENT)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap QW: (Base Layer) Default Layer
     * ,----------------------------------------------------------------.
     * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
     * |----------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
     * |----------------------------------------------------------------|
     * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
     * |----------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
     * |----------------------------------------------------------------|
     * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
     * `----------------------------------------------------------------'
     */
    [QW] = KEYMAP_ANSI(
            KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_GRV, \
            KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
            TD(TG_LY), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         DU_ENT ,KC_PGUP,\
            KC_LSPO,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,         KC_RSPC,KC_UP  ,KC_PGDN,\
            KC_LCTL,   KC_LGUI,KC_LALT,                KC_SPC,                         KC_RALT,MO(FN), KC_RCTRL,KC_LEFT,KC_DOWN,KC_RGHT),

    [DV] = KEYMAP_ANSI(
            KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_LBRC, KC_RBRC,KC_BSPC,KC_GRV, \
            KC_TAB,    KC_QUOT,KC_COMM,KC_DOT, KC_P,   KC_Y,   KC_F,   KC_G,   KC_C,   KC_R,   KC_L,   KC_SLSH, KC_EQL ,KC_BSLS,KC_DEL, \
            TD(TG_LY), KC_A,   KC_O,   KC_E,   KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,   KC_S,   KC_MINS,         DU_ENT ,KC_PGUP,\
            KC_LSPO,   KC_SCLN,KC_Q,   KC_J,   KC_K,   KC_X,   KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,            KC_RSPC,KC_UP  ,KC_PGDN,\
            KC_LCTL,   KC_LGUI,KC_LALT,                KC_SPC,                         KC_RALT,MO(FN), KC_RCTRL,KC_LEFT,KC_DOWN,KC_RGHT),

    [FN] = KEYMAP_ANSI(
            _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F8,  KC_F9, KC_F10,KC_F11,  KC_F12,_______,\
            _______,_______,  KC_UP,_______,_______,_______,_______,_______,_______,_______,_______, BL_DEC,BL_INC, BL_TOGG,BL_STEP,\
            _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,_______,_______,_______,_______,_______,_______,        M_BDFLT,_______,\
            _______,_______,_______,_______,_______,M_BRTOG,_______,_______,_______,_______,_______,        _______,M_BSPDU,_______,\
            _______,_______,_______,                _______,                        _______,_______,_______,_______,M_BSPDD,_______),
};


//static bool CTRL_PRESSED = false;
void dance_layer_switch(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            /*
            if (timer_elapsed(state->timer) > 200) {
                clear_oneshot_mods();
                register_code16(KC_LCTL);
                CTRL_PRESSED = true;
            }else{
                set_oneshot_mods(MOD_LSFT);
            }
            */
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
    /*
    if( CTRL_PRESSED ) {
        unregister_code16(KC_LCTL);
        CTRL_PRESSED = false;
    }
    */
    unregister_code16(KC_LCTL);
}
qk_tap_dance_action_t tap_dance_actions[] = {
    // tap one for oneshot shift,twice to switch between qwerty and dvorak
    [TG_LY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,dance_layer_switch,dance_layer_reset)
};

void led_set_dv_indicator(void) {
    if ( IS_LAYER_ON(DV) ) {
        // Turn on
        PORTB &= ~(1<<2);
    } else {
        // Turn off
        PORTB |= (1<<2);
    }
}
void matrix_scan_user(void){
    led_set_dv_indicator();
}
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id){
        case MACRO_BREATH_TOGGLE:
            if (record->event.pressed)
            {
                breathing_toggle();
            }
            break;

        case MACRO_BREATH_SPEED_INC:
            if (record->event.pressed)
            {
                breathing_speed_inc(1);
            }
            break;

        case MACRO_BREATH_SPEED_DEC:
            if (record->event.pressed)
            {
                breathing_speed_dec(1);
            }
            break;

        case MACRO_BREATH_DEFAULT:
            if (record->event.pressed)
            {
                breathing_defaults();
            }
            break;
    }
    return MACRO_NONE;
}
/*enum function_id {
//SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
//[0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
static uint8_t shift_esc_shift_mask;
switch (id) {
case SHIFT_ESC:
shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
if (record->event.pressed) {
if (shift_esc_shift_mask) {
add_key(KC_GRV);
send_keyboard_report();
} else {
add_key(KC_ESC);
send_keyboard_report();
}
} else {
if (shift_esc_shift_mask) {
del_key(KC_GRV);
send_keyboard_report();
} else {
del_key(KC_ESC);
send_keyboard_report();
}
}
break;
}
}*/
