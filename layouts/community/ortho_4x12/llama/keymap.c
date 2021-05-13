#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif

typedef struct {
  bool is_press_action;
  int state;
} tap;

//Tap dance states
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  TAP_OVER,
};

//Tap dance keys
enum {
  NAV_SUPER = 0,
  NUMSYM_SUPER = 1,
  NUMPAD_SUPER = 2,
};

//Function associated with all tap dances
int cur_dance (qk_tap_dance_state_t *state);

//Functions associated with individual tap dances
void nav_finished (qk_tap_dance_state_t *state, void *user_data);
void nav_reset (qk_tap_dance_state_t *state, void *user_data);

void numsym_finished (qk_tap_dance_state_t *state, void *user_data);
void numsym_reset (qk_tap_dance_state_t *state, void *user_data);

void numpad_finished (qk_tap_dance_state_t *state, void *user_data);
void numpad_reset (qk_tap_dance_state_t *state, void *user_data);


enum custom_keycodes {
  NAV_FN = SAFE_RANGE,
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
#define _NUMPAD 4
#define _NAV_R 8
#define _ADJUST 16

#define KC______ KC_TRNS
#define KC___X__ KC_NO

#define KC_NAVFN NAV_FN
#define KC_NMSYM NUM_SYM
#define KC_NMPAD NUM_PAD

#define KC_NAV_S TD(NAV_SUPER)
#define KC_NMS_S TD(NUMSYM_SUPER)
#define KC_NMP_S TD(NUMPAD_SUPER)

#define KC_DEBUG DEBUG
#define KC_RESET RESET

#define KC_L_TOG RGB_TOG
#define KC_L_MOD RGB_MOD
#define KC_L_RMD RGB_RMOD
#define KC_L_HUI RGB_HUI
#define KC_L_HUD RGB_HUD
#define KC_L_SAI RGB_SAI
#define KC_L_SAD RGB_SAD
#define KC_L_VAI RGB_VAI
#define KC_L_VAD RGB_VAD
#define KC_L_RST RGB_MODE_PLAIN


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc_ortho_4x12( \
  //,-----------------------------------------.                ,-----------------------------------------.
        TAB,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  BSPC, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCTL,     A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN,  QUOT, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,     Z,     X,     C,     V,     B,                      N,     M,  COMM,   DOT,  SLSH,  RSFT, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LEFT, RIGHT,  LGUI,  LALT,   SPC, NAV_S,                  NMS_S,   SPC, NMP_S, __X__,  DOWN,    UP  \
  /*`-----------------------------------------'                `-----------------------------------------.*/
  ),

  [_NAV_FN] = LAYOUT_kc_ortho_4x12( \
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC,   GRV,  HOME,    UP,   END,  PGUP,                     F1,    F2,    F3,    F4,    F5, _____, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,  LALT,  LEFT,  DOWN,  RGHT,  PGDN,                     F6,    F7,    F8,    F9,   F10, _____, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,  LGUI,   INS,  BSPC,   DEL,   ENT,                    F11,   F12,  PSCR,  SLCK,  PAUS, _____, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____,  BSPC, _____,                  _____, _____, _____, _____, _____, _____  \
  //`-----------------------------------------'                `-----------------------------------------'
  ),

  [_NUM_SYM] = LAYOUT_kc_ortho_4x12( \
  //,-----------------------------------------.                ,-----------------------------------------.
        GRV,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0, _____, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____,  MINS, _____,                   BSLS,  MINS,  LBRC,  RBRC,  SCLN,  QUOT, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____,   EQL, _____,                    ENT,   EQL,  COMM,   DOT,  SLSH, _____, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____,                  _____, _____, _____,  MPLY,  VOLD,  VOLU  \
  //`-----------------------------------------'                `-----------------------------------------'
  ),

  [_NUMPAD] = LAYOUT_kc_ortho_4x12( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____, _____, _____, _____, _____, _____,                  __X__,    P7,    P8,    P9,  PDOT, _____, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____,                   PMNS,    P4,    P5,    P6,  PAST,  PENT, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____,                   PPLS,    P1,    P2,    P3,  PSLS,  LGUI, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____,                  _____,    P0, _____,  PDOT, __X__, __X__  \
  //`-----------------------------------------'                `-----------------------------------------'
  ),


  [_NAV_R] = LAYOUT_kc_ortho_4x12( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____, _____, _____, _____, _____, _____,                  __X__,  HOME,    UP,   END,  PGUP, _____, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____,                  __X__,  LEFT,  DOWN,  RGHT,  PGDN,   ENT, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____,                  __X__, __X__,  MPLY,  VOLD,  VOLU,  LGUI, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____,                  _____, _____, _____, __X__, __X__, __X__  \
  /*`-----------------------------------------'                `-----------------------------------------'*/
  ),

  [_ADJUST] = LAYOUT_kc_ortho_4x12( \
  //,-----------------------------------------.                ,-----------------------------------------.
      RESET, __X__, __X__, __X__, __X__, __X__,                   NLCK, __X__, __X__, __X__, __X__, DEBUG, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       CAPS, L_HUI, L_SAI, L_VAI, L_MOD, L_TOG,                  __X__, __X__, __X__, __X__, __X__, __X__, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      __X__, L_HUD, L_SAD, L_VAD, L_RMD, L_RST,                  __X__, __X__, __X__, __X__, __X__, __X__, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      __X__, __X__, __X__, __X__, __X__, __X__,                  _____, __X__, _____, __X__, __X__, __X__  \
  //`-----------------------------------------'                `-----------------------------------------'
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // switch (keycode) {

  //   case NAV_FN:
  //     if (record->event.pressed) {
  //       layer_on(_NAV_FN);
  //     } else {
  //       layer_off(_NAV_FN);
  //     }
  //     update_tri_layer(_NAV_FN, _NUM_SYM, _NUM_SYM_SFT);
  //     update_tri_layer(_NAV_FN, _NUMPAD, _NAV_ALT);
  //     return false;

  //   case NUM_SYM:
  //     if (record->event.pressed) {
  //       layer_on(_NUM_SYM);
  //     } else {
  //       layer_off(_NUM_SYM);
  //     }
  //     update_tri_layer(_NAV_FN, _NUM_SYM, _NUM_SYM_SFT);
  //     update_tri_layer(_NUMPAD, _NUM_SYM, _ADJUST);
  //     return false;

  //   case NUM_PAD:
  //     if (record->event.pressed) {
  //       layer_on(_NUMPAD);
  //     } else {
  //       layer_off(_NUMPAD);
  //     }
  //     update_tri_layer(_NAV_FN, _NUMPAD, _NAV_ALT);
  //     update_tri_layer(_NUMPAD, _NUM_SYM, _ADJUST);
  //     return false;
  // }
  return true;
}



//Determine the current tap dance state
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) {
      return SINGLE_TAP;
    } else {
      return SINGLE_HOLD;
    }
  } else if (state->count == 2) {
    if (!state->pressed) {
      return DOUBLE_TAP;
    } else {
      return DOUBLE_HOLD;
    }
  }
  else return TAP_OVER;
}

//Initialize tap structure associated with example tap dance key
static tap nav_tap_state = {
  .is_press_action = true,
  .state = 0
};

//Functions that control what our tap dance key does
void nav_finished (qk_tap_dance_state_t *state, void *user_data) {
  nav_tap_state.state = cur_dance(state);
  switch (nav_tap_state.state) {
    case SINGLE_TAP:
      break;
    case SINGLE_HOLD:
      layer_on(_NAV_FN);
      break;
    case DOUBLE_TAP:

      break;
    case DOUBLE_HOLD:
      if (layer_state_is(_NAV_FN)) {
        layer_off(_NAV_FN);
      }
      layer_on(_NUM_SYM);
      break;
    case TAP_OVER:
      if (layer_state_is(_NUM_SYM)) {
        layer_off(_NUM_SYM);
      }
      break;
  }
}

void nav_reset (qk_tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (nav_tap_state.state==SINGLE_HOLD) {
    layer_off(_NAV_FN);
  }
  if (nav_tap_state.state==DOUBLE_HOLD) {
    layer_off(_NUM_SYM);
  }
  nav_tap_state.state = 0;
}


//Initialize tap structure associated with example tap dance key
static tap numsym_tap_state = {
  .is_press_action = true,
  .state = 0
};

//Functions that control what our tap dance key does
void numsym_finished (qk_tap_dance_state_t *state, void *user_data) {
  numsym_tap_state.state = cur_dance(state);
  switch (numsym_tap_state.state) {
    case SINGLE_TAP:
      break;
    case SINGLE_HOLD:
      layer_on(_NUM_SYM);
      update_tri_layer(_NUMPAD, _NUM_SYM, _ADJUST);
      break;
    case DOUBLE_TAP:

      break;
    case DOUBLE_HOLD:
      if (layer_state_is(_NUM_SYM)) {
        layer_off(_NUM_SYM);
        update_tri_layer(_NUMPAD, _NUM_SYM, _ADJUST);
      }
      layer_on(_NAV_R);
      break;
    case TAP_OVER:
      if (layer_state_is(_NAV_R)) {
        layer_off(_NAV_R);
      }
      break;
  }
}

void numsym_reset (qk_tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (numsym_tap_state.state==SINGLE_HOLD) {
    layer_off(_NUM_SYM);
    update_tri_layer(_NUMPAD, _NUM_SYM, _ADJUST);
  }
  if (numsym_tap_state.state==DOUBLE_HOLD) {
    layer_off(_NAV_R);
  }
  numsym_tap_state.state = 0;
}



//Initialize tap structure associated with example tap dance key
static tap numpad_tap_state = {
  .is_press_action = true,
  .state = 0
};

//Functions that control what our tap dance key does
void numpad_finished (qk_tap_dance_state_t *state, void *user_data) {
  numpad_tap_state.state = cur_dance(state);
  switch (numpad_tap_state.state) {
    case SINGLE_TAP:
      break;
    case SINGLE_HOLD:
      layer_on(_NUMPAD);
      update_tri_layer(_NUMPAD, _NUM_SYM, _ADJUST);
      break;
    case DOUBLE_TAP:

      break;
    case DOUBLE_HOLD:
      if (layer_state_is(_NUMPAD)) {
        layer_off(_NUMPAD);
        update_tri_layer(_NUMPAD, _NUM_SYM, _ADJUST);
      }
      layer_on(_NAV_FN);
      break;
    case TAP_OVER:
      if (layer_state_is(_NAV_FN)) {
        layer_off(_NAV_FN);
      }
      break;
  }
}

void numpad_reset (qk_tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (numpad_tap_state.state==SINGLE_HOLD) {
    layer_off(_NUMPAD);
    update_tri_layer(_NUMPAD, _NUM_SYM, _ADJUST);
  }
  if (numpad_tap_state.state==DOUBLE_HOLD) {
    layer_off(_NAV_FN);
  }
  numpad_tap_state.state = 0;
}



//Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
  [NAV_SUPER] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, nav_finished, nav_reset, 175)
 ,[NUMSYM_SUPER] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, numsym_finished, numsym_reset, 175)
 ,[NUMPAD_SUPER] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, numpad_finished, numpad_reset, 175)
};
