/**
 * e6_rgb.c
 */

#include "e6_rgb.h"

#ifdef RGB_MATRIX_ENABLE
__attribute__ ((weak))
void matrix_init_kb(void) {
    matrix_init_user();
}

__attribute__ ((weak))
void matrix_scan_kb(void) {
    matrix_scan_user();
}

__attribute__ ((weak))
void matrix_init_user(void) {
  setPinOutput(D5);
  writePinHigh(D5);
}

__attribute__ ((weak))
void matrix_scan_user(void) {
}

const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
//cs1
    {0, K_1,    J_1,    L_1},
    {0, H_1,    G_1,    I_1},
    {0, E_1,    D_1,    F_1},
    {0, B_1,    A_1,    C_1},

//cs2
    {0, K_2,    J_2,    L_2},
    {0, H_2,    G_2,    I_2},
    {0, E_2,    D_2,    F_2},
    {0, B_2,    A_2,    C_2},
//cs3
    {0, K_3,    J_3,    L_3},
    {0, H_3,    G_3,    I_3},
    {0, E_3,    D_3,    F_3},
    {0, B_3,    A_3,    C_3},
//cs4
    {0, K_4,    J_4,    L_4},
    {0, H_4,    G_4,    I_4},
    {0, E_4,    D_4,    F_4},
    {0, B_4,    A_4,    C_4},
//cs5
    {0, K_5,    J_5,    L_5},
    {0, H_5,    G_5,    I_5},
    {0, E_5,    D_5,    F_5},
    {0, B_5,    A_5,    C_5},
//cs6
    {0, K_6,    J_6,    L_6},
    {0, H_6,    G_6,    I_6},
    {0, E_6,    D_6,    F_6},
    {0, B_6,    A_6,    C_6},
//cs7
    {0, K_7,    J_7,    L_7},
    {0, H_7,    G_7,    I_7},
    {0, E_7,    D_7,    F_7},
    {0, B_7,    A_7,    C_7},
//cs8
    {0, K_8,    J_8,    L_8},
    {0, H_8,    G_8,    I_8},
    {0, E_8,    D_8,    F_8},
    {0, B_8,    A_8,    C_8},
//cs9
    {0, K_9,    J_9,    L_9},
    {0, H_9,    G_9,    I_9},
    {0, E_9,    D_9,    F_9},
    {0, B_9,    A_9,    C_9},
//cs10
    {0, K_10,   J_10,   L_10},
    {0, H_10,   G_10,   I_10},
    {0, E_10,   D_10,   F_10},
    {0, B_10,   A_10,   C_10},
//cs11
    {0, K_11,   J_11,   L_11},
    {0, H_11,   G_11,   I_11},
    {0, E_11,   D_11,   F_11},
    {0, B_11,   A_11,   C_11},
//cs12
    {0, K_12,   J_12,   L_12},
    {0, H_12,   G_12,   I_12},
    {0, E_12,   D_12,   F_12},
    {0, B_12,   A_12,   C_12},
//cs13
    {0, K_13,   J_13,   L_13},
    {0, H_13,   G_13,   I_13},
    {0, E_13,   D_13,   F_13},
    {0, B_13,   A_13,   C_13},
//cs14
    {0, K_14,   J_14,   L_14},
    {0, H_14,   G_14,   I_14},
    {0, E_14,   D_14,   F_14},
    {0, B_14,   A_14,   C_14},
//cs15
    {0, K_15,   J_15,   L_15},

    {0, E_15,   D_15,   F_15},
    {0, B_15,   A_15,   C_15},
//cs16
    {0, K_16,   J_16,   L_16},
    {0, H_16,   G_16,   I_16},
    {0, E_16,   D_16,   F_16},
    {0, B_16,   A_16,   C_16},
};
const rgb_led g_rgb_leds[DRIVER_LED_TOTAL] = {
/* {row | col << 4}
 *    |           {x=0..224, y=0..64}
 *    |              |            modifier
 *    |              |         | */
//cs1
    {{0|(0<<4)},    {  0,  0}, 1},
    {{0|(1<<4)},    { 17,  0}, 0},
    {{1|(0<<4)},    {  0, 16}, 1},
    {{2|(0<<4)},    {  0, 32}, 1},

//cs2
    {{0|(2<<4)},    { 34,  0}, 0},
    {{0|(3<<4)},    { 51,  0}, 0},
    {{1|(1<<4)},    { 17, 16}, 0},
    {{1|(2<<4)},    { 34, 16}, 0},
//cs3
    {{2|(1<<4)},    { 17, 32}, 0},
    {{2|(2<<4)},    { 34, 32}, 0},
    {{3|(1<<4)},    { 17, 48}, 0},
    {{3|(2<<4)},    { 34, 48}, 0},
//cs4
    {{0|(4<<4)},    { 68,  0}, 0},
    {{0|(5<<4)},    { 85,  0}, 0},
    {{1|(3<<4)},    { 51, 16}, 0},
    {{1|(4<<4)},    { 68, 16}, 0},
//cs5
    {{0|(11<<4)},   {187,  0}, 0},
    {{0|(12<<4)},   {204,  0}, 0},
    {{1|(11<<4)},   {187, 16}, 0},
    {{1|(12<<4)},   {204, 16}, 0},
//cs6
    {{0|(7<<4)},    {119,  0}, 0},
    {{0|(8<<4)},    {136,  0}, 0},
    {{1|(7<<4)},    {119, 16}, 0},
    {{1|(8<<4)},    {136, 16}, 0},
//cs7
    {{0|(9<<4)},    {153,  0}, 0},
    {{0|(10<<4)},   {170,  0}, 0},
    {{1|(9<<4)},    {153, 16}, 0},
    {{1|(10<<4)},   {170, 16}, 0},
//cs8
    {{0|(13<<4)},   {221,  0}, 0},
    {{0|(14<<4)},   {221,  0}, 0},
    {{1|(13<<4)},   {221, 32}, 1},
    {{2|(12<<4)},   {221, 16}, 1},
//cs9
    {{2|(3<<4)},    { 51, 32}, 0},
    {{2|(4<<4)},    { 68, 32}, 0},
    {{3|(3<<4)},    { 51, 48}, 0},
    {{3|(4<<4)},    { 68, 48}, 0},
//cs10
    {{0|(6<<4)},    {102,  0}, 0},
    {{1|(5<<4)},    { 85, 16}, 0},
    {{1|(6<<4)},    {102, 16}, 0},
    {{2|(5<<4)},    { 85, 32}, 0},
//cs11
    {{2|(6<<4)},    {102, 32}, 0},
    {{3|(5<<4)},    { 85, 48}, 0},
    {{3|(6<<4)},    {102, 48}, 0},
    {{4|(5<<4)},    {102, 64}, 0},
//cs12
    {{2|(7<<4)},    {119, 32}, 0},
    {{2|(8<<4)},    {136, 32}, 0},
    {{3|(7<<4)},    {119, 48}, 0},
    {{3|(8<<4)},    {136, 48}, 0},
//cs13
    {{2|(9<<4)},    {153, 32}, 0},
    {{2|(10<<4)},   {170, 32}, 0},
    {{3|(9<<4)},    {153, 48}, 0},
    {{4|(6<<4)},    {136, 48}, 1},
//cs14
    {{2|(11<<4)},   {187, 32}, 0},
    {{3|(10<<4)},   {170, 48}, 0},
    {{3|(11<<4)},   {187, 48}, 1},
    {{4|(7<<4)},    {153, 48}, 1},
//cs15
    {{3|(12<<4)},   {221, 48}, 1},

    {{4|(9<<4)},    {221, 64}, 1},
    {{4|(8<<4)},    {204, 64}, 1},
//cs16
    {{3|(0<<4)},    {  0, 48}, 1},
    {{4|(0<<4)},    {  0, 64}, 1},
    {{4|(1<<4)},    { 17, 64}, 1},
    {{4|(2<<4)},    { 34, 64}, 1},
};
#endif
#ifdef WEBUSB_ENABLE
#include "webusb.h"
#include "dynamic_keymap.h"

#define WEBUSB_KEYCOUNT  62
#define WEBUSB_LAYERCOUNT 2
typedef struct {
    uint8_t row;
    uint8_t col;
} webusb_pos_t;

const webusb_pos_t webusb_keymap[] = {
    {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, 8}, {0, 9}, {0, 10}, {0, 11}, {0, 12}, {0, 13}, {2, 13},

    {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}, {1, 8}, {1, 9}, {1, 10}, {1, 11}, {1, 12}, {1, 13},

    {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7}, {2, 8}, {2, 9}, {2, 10}, {2, 11}, {2, 12},

    {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}, {3, 7},         {3, 9}, {3, 10}, {3, 11}, {3, 12}, {3, 13},

    {4, 0}, {4, 1}, {4, 2},                         {4, 6},                                  {3, 11}, {3, 12}, {3, 13},
};

#define CMD_BUFFER_SIZE     32
#define CMD_ERROR_MASK      0x80    // the highest bit of command byte will be set while in error
#define CMD_VERSION         0x01    // current verison was 1
#define CMD_GET_KEYBOARD    0x02    // get keyboard information[key count][row count][column count][layer count]
#define CMD_GET_POSITION    0x03    // get the key positon[key index][row index][column index]
#define CMD_SET_KEYCODE     0x04    // set the keycode[layer][row index][column index][keycode(2 bytes)]
#define CMD_GET_KEYCODE     0x05    // get the keycode[layer][row index][column index][keycode(2 bytes)]

void webusb_receive( uint8_t *data, uint8_t length )
{
    //uint8_t *cmd_ver  = &(data[0]);
    uint8_t *cmd_type = &(data[1]);
    uint8_t *cmd_data = &(data[2]);
    switch (*cmd_type) {
    case CMD_GET_KEYBOARD:
        cmd_data[0] = WEBUSB_KEYCOUNT;
        cmd_data[1] = MATRIX_ROWS;
        cmd_data[2] = MATRIX_COLS;
        cmd_data[3] = WEBUSB_LAYERCOUNT;
        break;
    case CMD_GET_POSITION:
        cmd_data[1] = webusb_keymap[cmd_data[0]].row;
        cmd_data[2] = webusb_keymap[cmd_data[0]].col;
        break;
#ifdef DYNAMIC_KEYMAP_ENABLE
    case CMD_GET_KEYCODE:
        {
            uint16_t keycode = dynamic_keymap_get_keycode(cmd_data[0], cmd_data[1], cmd_data[2]);
            cmd_data[3]  = keycode >> 8;
            cmd_data[4]  = keycode & 0xFF;
        }
        break;
    case CMD_SET_KEYCODE:
        dynamic_keymap_set_keycode(cmd_data[0], cmd_data[1], cmd_data[2], (cmd_data[3] << 8) | cmd_data[4]);
        break;
#endif
    default:
      *cmd_type |= CMD_ERROR_MASK;
      break;
	}

	// Return same buffer with values changed
	webusb_send( data, length );
}

#endif
