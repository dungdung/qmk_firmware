#pragma once
/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
*/


// #define TAPPING_TOGGLE 1
#define TAPPING_TERM 150
// #define ONESHOT_TAP_TOGGLE 2
// #define ONESHOT_LAYER_TOGGLE 2
// #define ONESHOT_TIMEOUT 800

// #define USE_SERIAL
// #define USE_I2C

// #define MOUSEKEY_INTERVAL 50
// #define MOUSEKEY_DELAY 0
// #define MOUSEKEY_TIME_TO_MAX 60
// #define MOUSEKEY_MAX_SPEED 7

// #define MOUSEKEY_WHEEL_DELAY 0
// #define MOUSEKEY_WHEEL_MAX_SPEED   8
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 40

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define MAGIC_KEY_SWITCH_LAYER_WITH_FKEYS  false
#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS  false


#define PREVENT_STUCK_MODIFIERS
// #define IGNORE_MOD_TAP_INTERRUPT
// #define PERMISSIVE_HOLD

// #define RGBLIGHT_ANIMATIONS
// #undef RGB_DI_PIN
// #define RGB_DI_PIN D1     // The pin the LED strip is connected to
// #undef RGBLED_NUM
// #define RGBLED_NUM 8     // Number of LEDs in your strip

//#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Selection of RGBLIGHT MODE to use.
#if defined(LED_ANIMATIONS)
   #define RGBLIGHT_EFFECT_BREATHING
   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
   #define RGBLIGHT_EFFECT_SNAKE
   #define RGBLIGHT_EFFECT_KNIGHT
   #define RGBLIGHT_EFFECT_CHRISTMAS
   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
   //#define RGBLIGHT_EFFECT_RGB_TEST
   //#define RGBLIGHT_EFFECT_ALTERNATING
#endif
