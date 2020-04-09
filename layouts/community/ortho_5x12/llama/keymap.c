#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif

enum custom_keycodes {
  RGB_DEC = SAFE_RANGE,
  RGB_INC,
  SCR_OFF,
  NAV_FN,
  NUM_SYM,
  NUM_PAD,
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all neniceniceed to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NAV_FN 1
#define _NUM_SYM 2
#define _NUM_SYM_SFT 3
#define _NUMPAD 4
#define _NAV_ALT 5
#define _ADJUST 6

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___X___ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
  [_QWERTY] = LAYOUT_ortho_5x12( \
    KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , \
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC, \
    KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, \
    KC_RCTL, KC_CAPS, KC_LGUI, KC_LALT, KC_SPC , NAV_FN , NUM_SYM, KC_SPC , NUM_PAD, ___X___, ___X___, ___X___),
  
  [_NAV_FN] = LAYOUT_ortho_5x12( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_ESC , KC_HOME, KC_UP  , KC_END , KC_PGUP, KC_INS , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_DEL , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , \
    _______, ___X___, ___X___, KC_GRV , KC_BSPC, KC_ENT , KC_ENT , _______, KC_LALT, KC_LGUI, KC_CAPS, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS),
  
  [_NUM_SYM] = LAYOUT_ortho_5x12( \
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, \
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, \
    _______, ___X___, KC_LBRC, KC_RBRC, KC_MINS, KC_BSLS, KC_BSLS, KC_MINS, KC_LBRC, KC_RBRC, KC_SCLN, KC_QUOT, \
    _______, ___X___, KC_LPRN, KC_RPRN, KC_EQL , KC_ENT , KC_ENT , KC_EQL , KC_COMM, KC_DOT , KC_SLSH, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU),
  
  [_NUM_SYM_SFT] = LAYOUT_ortho_5x12( \
    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    _______, ___X___, KC_LCBR, KC_RCBR, KC_UNDS, KC_PIPE, KC_PIPE, KC_UNDS, KC_LCBR, KC_RCBR, KC_COLN, KC_DQT , \
    _______, ___X___, KC_LT  , KC_GT  , KC_PLUS, KC_ENT , KC_ENT , KC_PLUS, KC_LT  , KC_GT  , KC_QUES, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
  
  [_NUMPAD] = LAYOUT_ortho_5x12( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, ___X___, KC_P7  , KC_P8  , KC_P9  , ___X___, _______, \
    _______, _______, _______, _______, _______, _______, KC_PMNS, KC_P4  , KC_P5  , KC_P6  , KC_PAST, KC_PENT, \
    _______, _______, _______, _______, _______, _______, KC_PPLS, KC_P1  , KC_P2  , KC_P3  , KC_PSLS, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_P0  , _______, KC_PDOT, ___X___, ___X___),
  
  [_NAV_ALT] = LAYOUT_ortho_5x12( \
    _______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, \
    _______, _______, _______, _______, _______, _______, ___X___, KC_HOME, KC_UP  , KC_END , KC_PGUP, _______, \
    _______, _______, _______, _______, _______, _______, ___X___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, \
    _______, KC_CAPS, KC_LGUI, KC_LALT, ___X___, ___X___, ___X___, ___X___, KC_LALT, KC_LGUI, KC_CAPS, _______, \
    _______, _______, _______, _______, _______, _______, _______, ___X___, _______, ___X___, ___X___, ___X___),
  
  
  [_ADJUST] = LAYOUT_ortho_5x12( \
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, \
    RESET,   ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, DEBUG  , \
    ___X___, RGB_HUI, RGB_SAI, RGB_VAI, RGB_INC, RGB_TOG, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, \
    ___X___, RGB_HUD, RGB_SAD, RGB_VAD, RGB_DEC, ___X___, ___X___, SCR_OFF, ___X___, ___X___, ___X___, ___X___, \
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, _______, ___X___, _______, ___X___, ___X___, ___X___)

};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
#ifdef RGBLIGHT_ENABLE
    rgblight_mode(RGB_current_mode);
#endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}  

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_INC:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        #endif
      }
      return false;

    case RGB_DEC:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_step_reverse();
          RGB_current_mode = rgblight_config.mode;
        #endif
      }
      return false;

    case SCR_OFF:
      if (record->event.pressed) {
        register_code(KC_EJCT);
      } else {
        unregister_code(KC_EJCT);
      }
      return false;

    case NAV_FN:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          RGB_current_mode = rgblight_config.mode;
          rgblight_setrgb(204 * rgblight_config.val / 255, 0, 204 * rgblight_config.val / 255);
        #endif
        layer_on(_NAV_FN);
      } else {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(RGB_current_mode);
        #endif
        layer_off(_NAV_FN);
      }
      update_tri_layer_RGB(_NAV_FN, _NUM_SYM, _NUM_SYM_SFT);
      update_tri_layer_RGB(_NAV_FN, _NUMPAD, _NAV_ALT);
      return false;

    case NUM_SYM:
      if (record->event.pressed) {
        layer_on(_NUM_SYM);
        #ifdef RGBLIGHT_ENABLE
          RGB_current_mode = rgblight_config.mode;
          rgblight_setrgb(255 * rgblight_config.val / 255, 0, 31 * rgblight_config.val / 255);
        #endif
      } else {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(RGB_current_mode);
        #endif
        layer_off(_NUM_SYM);
      }
      update_tri_layer_RGB(_NAV_FN, _NUM_SYM, _NUM_SYM_SFT);
      update_tri_layer_RGB(_NUMPAD, _NUM_SYM, _ADJUST);
      return false;

    case NUM_PAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
        #ifdef RGBLIGHT_ENABLE
          RGB_current_mode = rgblight_config.mode;
          rgblight_setrgb(0, 204 * rgblight_config.val / 255, 204 * rgblight_config.val / 255);
        #endif
      } else {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(RGB_current_mode);
        #endif
        layer_off(_NUMPAD);
      }
      update_tri_layer_RGB(_NAV_FN, _NUMPAD, _NAV_ALT);
      update_tri_layer_RGB(_NUMPAD, _NUM_SYM, _ADJUST);
      return false;
  }
  return true;
}