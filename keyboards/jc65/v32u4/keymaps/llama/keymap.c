#include "jc65.h"
#include "version.h"

enum layers {
    _BL = 0,    // Base Layer
    _FL,        // Function Layer
    _AL,        // Adjust Layer
};

enum jc65_keycodes {
    DYNAMIC_MACRO_RANGE = SAFE_RANGE,
};

#include "dynamic_macro.h"
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define FN_CAPS LT(_FL, KC_CAPS)
#define KC_DMR1 DYN_REC_START1
#define KC_DMR2 DYN_REC_START2
#define KC_DMP1 DYN_MACRO_PLAY1
#define KC_DMP2 DYN_MACRO_PLAY2
#define KC_DMRS DYN_REC_STOP

static uint8_t current_layer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* _BL: Base Layer, mostly standard 65% QWERTY layout.
    *  .---------------------------------------------------------------.
    *  |GrE|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Ins|
    *  |---------------------------------------------------------------|
    *  |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|Del|
    *  |---------------------------------------------------------------|
    *  |FnCaps|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |PgU|
    *  |---------------------------------------------------------------|
    *  |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |PgD|
    *  |---------------------------------------------------------------|
    *  |Ctrl|Gui |Alt |      Space             |RAlt |Ctrl |Lft|Dwn|Rgt|
    *  *---------------------------------------------------------------*
    */
    [_BL] = LAYOUT(
        KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, MO(2),
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_LCTL,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_PGUP,
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_CAPS, KC_LGUI,          KC_LALT, KC_SPC,           MO(1),           KC_SPC,           KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* _FL: Function Layer.
    *  M0 opens Chrome
    *  .---------------------------------------------------------------.
    *  |M0 | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|SLock  |PSc|
    *  |---------------------------------------------------------------|
    *  |Fn_AL|   |   |   |   |   |   |   |   |   |   |   |   |     |Pau|
    *  |---------------------------------------------------------------|
    *  |FnCaps|   |   |   |   |   |Lft|Dwn|Up |Rgt|   |   |        |Hme|
    *  |---------------------------------------------------------------|
    *  |        |   |   |   |   |   |   |   |   |   |   |VlMute|VlU|End|
    *  |---------------------------------------------------------------|
    *  |    |    |Menu|                        |     |     |WBk|VlD|WFw|
    *  *---------------------------------------------------------------*
    */
    [_FL] = LAYOUT(
        KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, _______,
        KC_ESC,           KC_HOME,   KC_UP,  KC_END, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS,
        _______,          KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,  KC_DEL, KC_PSLS, KC_MINS, KC_LBRC, KC_RBRC, _______, _______, _______,          KC_HOME,
        _______, XXXXXXX, XXXXXXX, XXXXXXX,  KC_GRV, KC_BSPC,  KC_ENT, XXXXXXX,  KC_EQL, _______, _______, _______,          _______, KC_VOLU, KC_END,
        _______, _______,          _______, _______,          _______,          _______,          _______, _______, _______, KC_WBAK, KC_VOLD, KC_WFWD
    ),

    /* _AL: Adjust Layer.
    *  Default keymap, RGB Underglow, LED backlight, and Dynamic Macro settings.
    *  .---------------------------------------------------------------.
    *  |Ver|Tog|Mod|H- |H+ |S- |S+ |V- |V+ |   |BLT|BL-|BL+|       |MP1|
    *  |---------------------------------------------------------------|
    *  |Fn_AL|_BL|_WL|   |   |   |   |   |   |   |   |   |   |     |MR1|
    *  |---------------------------------------------------------------|
    *  |FnCaps|   |   |_DL|   |   |   |   |   |   |   |   |        |MS |
    *  |---------------------------------------------------------------|
    *  |        |   |   |_CL|   |_BL|_NL|   |   |   |   |      |   |MR2|
    *  |---------------------------------------------------------------|
    *  |Rst |    |    |                        |     |     |   |   |MP2|
    *  *---------------------------------------------------------------*
    */
    [_AL] = LAYOUT(
        RESET,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_TOGG, BL_DEC,  BL_INC,  XXXXXXX, XXXXXXX, _______,
        _______,          RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,          RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_DMRS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_DMR1, KC_DMR2,
        RESET,   XXXXXXX,          XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DMP1, KC_DMP2
    ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        case 0:
            if (record->event.pressed) {
                return MACRO(I(0), D(LGUI), T(R), U(LGUI), END);
            }
            else {
                SEND_STRING("chrome.exe https://geekhack.org/index.php?topic=86756.new;topicseen#new\n");
                return false;
            }
        break;
        case 1:
            if (record->event.pressed) {
                return MACRO(I(0), T(SPC), T(SPC), T(SPC), T(SPC), END);
            }
            else {
                return false;
            }
        break;
    }
    return MACRO_NONE;
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION(0),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case 0:
            if (record->event.pressed) {
                SEND_STRING ("[QMK:" QMK_KEYBOARD ":" QMK_KEYMAP ":" QMK_VERSION "]");
            }
        break;
    }
}

void matrix_init_user(void) {
    #ifdef BACKLIGHT_ENABLE
        backlight_level(0);
    #endif
    #ifdef RGBLIGHT_ENABLE
        rgblight_mode(1);
        rgblight_sethsv(180,100,100);
    #endif
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    if (current_layer == layer) {
    }
    else {
        current_layer = layer;
        // switch (layer) {
        //     case 0:
        //         backlight_level(0);
        //         rgblight_sethsv(180,100,255);
        //         break;
        //     case 1:
        //         backlight_level(1);
        //         rgblight_sethsv(180,95,240);
        //         break;
        //     case 2:
        //         backlight_level(1);
        //         rgblight_sethsv(180,90,225);
        //         break;
        //     case 3:
        //         backlight_level(1);
        //         rgblight_sethsv(180,85,210);
        //         break;
        //     case 4:
        //         backlight_level(1);
        //         rgblight_sethsv(180,80,195);
        //         break;
        //     case 5:
        //         backlight_level(2);
        //         rgblight_sethsv(230,255,255);
        //         break;
        //     case 6:
        //         backlight_level(3);
        //         rgblight_sethsv(350,255,255);
        //         break;
        //     default:
        //         backlight_level(0);
        //         rgblight_sethsv(180,100,100);
        //         break;
        // }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Enable Dynamic Macros.
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
    return true;
}
