/*  -*-  eval: (turn-on-orgtbl); -*-
 * default FN Layout
 */
#include QMK_KEYBOARD_H

enum layers
{
    BASE = 0,
    PINKY,
    FN
};

enum custom_keycodes {
  P_PARENT = SAFE_RANGE,
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case P_PARENT:
      if (record->event.pressed) {
        // when keycode P_PARENT is pressed
        SEND_STRING("cd .."SS_TAP(X_ENTER)"");
      } else {
        // when keycode P_PARENT is released
      }
      break;

  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE layer: Default Layer
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
     * |-----------------------------------------------------------------------------------------+
     * | Tab(fn)|  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | Shift     | fn  |
     * +-----------------------------------------------------------------------------------------+
     *         | Alt |  Gui   |               Space               | Gui   | Alt |
     *         `----------------------------------------------------------------´
     */

     [BASE] = LAYOUT( //  default layer
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
        LT(FN, KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(FN),
        KC_LGUI, KC_LALT, /*        */ (KC_SPC), KC_RGUI, KC_RALT),

    /* FN layer: In progress..
     * ,-----------------------------------------------------------------------------------------.
     * | PWR |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  | PGU |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl    |  A  |  S  | PGD |  F  |  G  | LEF | DOW | UP  | RIG |  ;  |  '  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  | par |  /  | Shift     | RES |
     * +-----------------------------------------------------------------------------------------+
     *         | Alt |  Gui   |               Space               | Gui   | Alt |
     *         `----------------------------------------------------------------´
     */

    [FN] = LAYOUT(
        KC_PWR, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, KC_TRNS, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_PGDN, KC_F, KC_G, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_SCLN, KC_QUOT, KC_ENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_END, P_PARENT, KC_DOWN, KC_TRNS, RESET,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    /* Pinky layer: Layer used to replace the most common right hand pinky keys such as enter and backspace
     * ,-----------------------------------------------------------------------------------------.
     * | PWR |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  | PGU |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl    |  A  |  S  | PGD |  F  |  G  | LEF | DOW | UP  | RIG |  ;  |  '  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  | par |  /  | Shift     | RES |
     * +-----------------------------------------------------------------------------------------+
     *         | Alt |  Gui   |               Space               | Gui   | Alt |
     *         `----------------------------------------------------------------´
     */

    [PINKY] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_BSPC, KC_ENT, KC_TRNS, KC_TAB, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, P_PARENT, KC_SLSH, KC_RSFT, MO(FN),
        KC_LGUI, KC_LALT, /*        */ (KC_SPC), KC_RGUI, KC_RALT)
};
