/**
 * config.h
 *
 */
#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xDEAD
#define PRODUCT_ID      0x00BE
#define DEVICE_VER      0x6001
#define MANUFACTURER    astro
#define PRODUCT         60rgbble
#define DESCRIPTION     60% rgb ble keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14
#define UNUSED_PINS
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

//rgb light setting
#define RGBLED_NUM      18
#define RGB_DI_PIN      B4
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8



//rgb matrix setting
#define DRIVER_ADDR_1 0b1110100
#define DRIVER_ADDR_2 0b1110111
#define DRIVER_COUNT 2
#define DRIVER_1_LED_TOTAL 36
#define DRIVER_2_LED_TOTAL 36
#define DRIVER_LED_TOTAL DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL

// tapping setting
#define TAPPING_TERM    200
#define RETRO_TAPPING
#define PERMISSIVE_HOLD
