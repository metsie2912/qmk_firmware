#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // basic QWERTY layer
#define WORKMAN 1 // basic Workman layer
#define SYMB 2 // symbols
#define MDIA 3 // media keys
#define MCRO 4 // macro and reset layer


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic (QWERTY) layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  Del |           |Insert|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Escape |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;/L2 | '/Win  |
 * |--------+------+------+------+------+------| Macro|           | Macro|------+------+------+------+------+--------|
 * | LShift |Z/Ctrl| X/Alt|   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  | ./Alt|//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |      | Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LCtrl| LAlt |       | RAlt |Ctrl  |
 *                                        | App  | LGui |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Back- |------|       |------|   =    |Enter |
 *                                 |      |Space | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,            KC_5,           KC_DEL,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,            KC_T,           KC_NO,
        KC_ESCAPE,      KC_A,           KC_S,           KC_D,           KC_F,            KC_G,
        KC_LSPO,        CTL_T(KC_Z),    ALT_T(KC_X),    KC_C,           KC_V,            KC_B,           MO(MCRO),
        LT(SYMB,KC_GRV),KC_NO,        KC_NO,          KC_LEFT,        KC_RGHT,
                                                                                        CTL_T(KC_APP),  ALT_T(KC_LGUI),
                                                                                                         KC_HOME,
                                                                        KC_SPC,          KC_BSPC,        KC_END,
        // right hand
             KC_INS,      KC_6,           KC_7,           KC_8,           KC_9,           KC_0,              KC_MINS,
             KC_NO,    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,              KC_BSLS,
                          KC_H,           KC_J,           KC_K,           KC_L,           LT(MDIA, KC_SCLN), GUI_T(KC_QUOT),
             MO(MCRO),    KC_N,           KC_M,           KC_COMM,        ALT_T(KC_DOT),  CTL_T(KC_SLSH),    KC_RSPC,
                                          KC_UP,          KC_DOWN,        KC_LBRC,        KC_RBRC,           MO(SYMB),
             KC_RALT,     KC_RCTL,
             KC_PGUP,
             KC_PGDN,     KC_EQUAL, KC_ENT
    ),
/* Keymap 1: Basic WORKMAN layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  Del |           |Insert|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   D  |   R  |   W  |   B  |      |           |      |   J  |   F  |   U  |   P  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Escape |   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  | I/L2 | '/Win  |
 * |--------+------+------+------+------+------| Macro|           | Macro|------+------+------+------+------+--------|
 * |LShift/(|Z/Ctrl| X/Alt|   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |./RAlt|//Ctrl|RShift/)|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |      | Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LCtrl| LAlt |       | RAlt |Ctrl  |
 *                                        | App  | LGui |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Back- |------|       |------|   =    |Enter |
 *                                 |      |Space | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[WORKMAN] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,            KC_5,           KC_DEL,
        KC_TAB,         KC_Q,           KC_D,           KC_R,           KC_W,            KC_B,           KC_NO,
        KC_ESCAPE,      KC_A,           KC_S,           KC_H,           KC_T,            KC_G,
        KC_LSPO,        CTL_T(KC_Z),    ALT_T(KC_X),    KC_M,           KC_C,            KC_V,           MO(MCRO),
        LT(SYMB,KC_GRV),KC_NO,        KC_NO,          KC_LEFT,        KC_RGHT,
                                                                                         CTL_T(KC_APP),  ALT_T(KC_LGUI),
                                                                                                         KC_HOME,
                                                                        KC_SPC,          KC_BSPC,        KC_END,
        // right hand
             KC_INS,      KC_6,           KC_7,           KC_8,           KC_9,           KC_0,              KC_MINS,
             KC_NO,    KC_J,           KC_F,           KC_U,           KC_P,           KC_SCLN,              KC_BSLS,
                          KC_Y,           KC_N,           KC_E,           KC_O,           LT(MDIA, KC_I), GUI_T(KC_QUOT),
             MO(MCRO),    KC_K,           KC_L,           KC_COMM,        ALT_T(KC_DOT),  CTL_T(KC_SLSH),    KC_RSPC,
                                          KC_UP,          KC_DOWN,        KC_LBRC,        KC_RBRC,           MO(SYMB),
             KC_RALT,     KC_RCTL,
             KC_PGUP,
             KC_PGDN,     KC_EQUAL, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         | %/Alt|^/Ctrl|   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |3/Alt |\/Ctrl|        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_TRNS,  KC_TRNS, KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_TRNS,   KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,CTL_T(KC_PERC),ALT_T(KC_CIRC),KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
          EPRM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    ALT_T(KC_3),    CTL_T(KC_BSLS), KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      | mute |           |      |      |      |      |      |      |  Reset |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |MsWhUp| MsUp |MsWhDn|      |      |           |Bright|      |      |      |      |      |        |
 * |--------+------+------+------+------+------| VolUp|           |  Up  |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |Bright|------+------+------+------+------+--------|
 * |        |      |      |      |      |      | VolDn|           | Down |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |LMouse|RMouse|------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,    KC_TRNS,       KC_TRNS,        KC_MUTE,
       KC_TRNS, KC_TRNS,       KC_MS_WH_UP,   KC_MS_U,    KC_MS_WH_DOWN, KC_TRNS,        KC_VOLU,
       KC_TRNS, KC_MS_WH_LEFT, KC_MS_L,       KC_MS_D,    KC_MS_R,       KC_MS_WH_RIGHT,
       KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,    KC_TRNS,       KC_TRNS,        KC_VOLD,
       KC_TRNS, KC_TRNS,       KC_TRNS,       KC_BTN1,    KC_BTN2,
                                                                         KC_TRNS,        KC_TRNS,
                                                                                         KC_TRNS,
                                                          KC_MS_BTN1,    KC_MS_BTN2,     KC_TRNS,
    // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
       KC_BRIU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_BRID, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                         KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_ACL0, KC_ACL1, KC_ACL2
),
/* Keymap 3: Macro's and reset
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Reset  |      |      |      |      |      |      |           |      |      |      |      |      |      |  Reset |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |QWERTY|WORKMN|      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |BL Tog|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |BL  Up|      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |BL Dwn|      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MCRO] = LAYOUT_ergodox(
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
       KC_TRNS, DF(BASE), DF(WORKMAN), KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,
                                              KC_TRNS,    KC_TRNS,
                                                          KC_TRNS,
                                  KC_TRNS,    KC_TRNS,    KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       BL_TOGG, KC_TRNS,
       BL_INC,
       BL_DEC,  KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      break;
    case MCRO:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
    default:
      // none
      break;
  }

};
