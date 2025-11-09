#include QMK_KEYBOARD_H
#include "./caps_word/caps_word.h"
#include "./layers.h"
#include "./tap_dance/tap_dance.c"
#include "./tap_dance/tap_dance.h"
#include "./utils/utils.h"
#include "stdbool.h"
#include "stdint.h"

bool NAV_enabled = false;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   TD_CLS,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       COMPOSE,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_ESC,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TAB,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                                   KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   CW_TOGG,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_NO,          QK_BOOT,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_DEL,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_LALT,    NAV,        NUM_SPC,                    KC_ENT,     SYM,        KC_NO
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_GAME] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TAB,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_LCTL,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_LSFT,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    KC_SPC,     KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_NAV] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   TD_CLS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      TAB_LEFT,   LAUNCH,     TAB_RIGHT,  KC_NO,                                  KC_NO,      KC_HOME,    KC_UP,      KC_END,     KC_NO,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TAB,     OS_LGUI,    OS_LALT,    OS_LCTL,    OS_LSFT,    KC_MPLY,                                KC_NO,      KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_CAPS,    KC_MUTE,    KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,    KC_TRNS,        KC_TRNS,    KC_NO,      KC_F2,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    NUM,        KC_TRNS,                    KC_ENT,     SYM,        KC_NO
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_SYM] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   TD_CLS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,                                KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,     KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TAB,     KC_BSLS,    KC_LBRC,    KC_RBRC,    KC_MINS,    KC_EQL,                                 KC_GRV,     OS_RSFT,    OS_RCTL,    OS_RALT,    OS_RGUI,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_CAPS,    KC_PIPE,    KC_LCBR,    KC_RCBR,    KC_UNDS,    KC_PLUS,    KC_TRNS,        KC_TRNS,    KC_TILD,    KC_F2,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    NUM,        KC_TRNS,                    KC_NO,      SYM,        KC_NO
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_NUM] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   TD_CLS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_SLSH,    KC_AT,      MULT,       KC_MINS,    KC_PLUS,                                KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,     KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_DOT,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_COMM,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_TRNS,        KC_TRNS,    KC_SCLN,    KC_COLN,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    NUM,        KC_TRNS,                    KC_ENT,     SYM,        KC_NO
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_FUNC] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   TD_CLS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_F1,      KC_F2,      TAB_LEFT,   LAUNCH,     TAB_RIGHT,  KC_NO,                                  KC_NO,      KC_HOME,    KC_UP,      KC_END,     KC_NO,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TAB,     OS_LGUI,    OS_LALT,    OS_LCTL,    OS_LSFT,    KC_MPLY,                                KC_NO,      KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_CAPS,    KC_MUTE,    KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,    KC_TRNS,        KC_TRNS,    KC_NO,      KC_F2,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    NUM,        KC_TRNS,                    KC_ENT,     SYM,        KC_NO
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    static bool 
    if (layer_state_cmp(state, _NAV) && layer_state_cmp(state, _SYM)) {
        layer_on(_NUM);
    } else {
        layer_off(_NUM);
    }
    return state;
}



// bool process_record_user(uint16_t keycode, keyrecord_t* record) {
//     switch (keycode) {
//         case GUI_TD_CLS: // make this keycode work (16-bit mod-tap)
//             if (record->tap.count) {
//                 if (record->event.pressed) {
//                     tap_code16(TD_CLS);
//                 }
//                 return false;
//             }
//             break;

//         // make it possible to go from layer 3 to layer 2
//         case NUM_SPC:
//             if (!record->tap.count) {
//                 if (NAV_enabled) {
//                     record->event.pressed ? layer_off(_NAV) : layer_on(_NAV);
//                 }
//             } else {
//                 if (record->event.pressed) {
//                     uint8_t mods = get_mods();
//                     if (mods & MOD_MASK_CTRL) {
//                         del_mods(MOD_MASK_CTRL);
//                         tap_code16(MENU);
//                         set_mods(mods);
//                         return false;
//                     }
//                 }
//             }
//             break;

//         case NAV_ENT:
//             if (!record->tap.count) {
//                 NAV_enabled = record->event.pressed;
//             }
//             break;

//         // noshift homerow mods with control overrides
//         case GUI_1:
//             return unshift_register_or_ctrl_fallthrough(keycode, KC_A, record);
//             break;
//         case ALT_2:
//             return unshift_register_or_ctrl_fallthrough(keycode, KC_S, record);
//             break;
//         case SFT_4:
//             return unshift_register_or_ctrl_fallthrough(keycode, KC_F, record);
//             break;
//         case SFT_7:
//             return unshift_register_or_ctrl_fallthrough(keycode, KC_J, record);
//             break;
//         case GUI_BSLS:
//             return unshift_register_or_ctrl_fallthrough(keycode, KC_A, record);
//             break;
//         case ALT_LBRC:
//             return unshift_register_or_ctrl_fallthrough(keycode, KC_S, record);
//             break;
//         case SFT_MINS:
//             return unshift_register_or_ctrl_fallthrough(keycode, KC_F, record);
//             break;

//         case CTL_3:
//         case GUI_0:
//         case CTL_8:
//         case ALT_9:
//         case CTL_RBRC: // no control override, just unshift
//             return unshift_register(keycode, record);
//             break;

//         // make arrow key homerow mods trigger the tap action when held and the hold time expires
//         case ALT_UP:
//         case CTL_DOWN:
//             if (!record->tap.count && !record->tap.interrupted) {
//                 if (record->event.pressed) {
//                     register_code(keycode);
//                     return false;
//                 } else {
//                     unregister_code(keycode);
//                 }
//             } else {
//                 uint8_t mods = get_mods();
//                 if (record->event.pressed) {
//                     if (mods == MOD_BIT(KC_LCTL)) { // remove control
//                         del_mods(MOD_BIT(KC_LCTL));
//                         register_code(keycode);
//                         set_mods(mods);
//                         return false;
//                     }
//                 }
//             }
//         case SFT_LEFT:
//         case GUI_RGHT:
//             // if this is a hold action and it occurred naturally
//             if (!record->tap.count && !record->tap.interrupted) {
//                 if (record->event.pressed) {
//                     register_code(keycode);
//                     return false;
//                 } else {
//                     unregister_code(keycode);
//                 }
//             }
//             break;

//         // make it so only the opposite-side shift key works
//         case KC_Q:
//         case KC_W:
//         case KC_E:
//         case KC_R:
//         case KC_T:
//         case KC_G:
//         case KC_Z:
//         case KC_X:
//         case KC_C:
//         case KC_V:
//         case KC_B: // left-side
//             if (record->event.pressed && get_mods() == MOD_BIT(KC_LSFT)) {
//                 return false; // do nothing
//             }
//             break;

//         case GUI_A:
//         case ALT_S:
//         case CTL_D:
//         case SFT_F:
//             if (record->event.pressed && record->tap.count && get_mods() == MOD_BIT(KC_LSFT)) {
//                 return false; // do nothing
//             }
//             break;

//         case KC_Y:
//         case KC_U:
//         case KC_I:
//         case KC_O:
//         case KC_P:
//         case KC_H:
//         case KC_QUOT:
//         case KC_N:
//         case KC_M:
//         case KC_COMM:
//         case KC_DOT:
//         case KC_SLSH:
//             if (IS_LAYER_ON(_BASE) && record->event.pressed && get_mods() == MOD_BIT(KC_RSFT)) {
//                 return false; // do nothing
//             }
//             break;
//         case GUI_SCLN:
//         case ALT_L:
//         case CTL_K:
//         case SFT_J:
//             if (IS_LAYER_ON(_BASE) && record->event.pressed && record->tap.count &&
//                 get_mods() == MOD_BIT(KC_RSFT)) {
//                 return false; // do nothing
//             }
//             break;
//     }
//     return true;
// }

// const key_override_t CW_CL_TO_TAB_BACKWARDS =
//     ko_make_basic(TABBING_TRIGGER_MODS, TD(TD_CW_CL), TAB_BACKWARD);

// const key_override_t Q_TO_KILL = ko_make_with_layers(MOD_MASK_GUI, KC_Q, A(KC_F4), 1 << _BASE);

// const key_override_t COMM_TO_TAB_BACKWARDS =
//     ko_make_with_layers(TABBING_TRIGGER_MODS, KC_COMM, TAB_BACKWARD, 1 << _NUM);
// const key_override_t TILDE_TO_TAB_BACKWARDS =
//     ko_make_with_layers(TABBING_TRIGGER_MODS, KC_TILDE, TAB_BACKWARD, 1 << _NAV);

// const key_override_t BSPC_TO_OBLITERATE = {
//     .trigger = KC_BSPC,
//     .trigger_mods = OBLITERATE_TRIGGER_MODS,
//     .layers = 0xFF,
//     .custom_action = obliterate_line_backwards,
//     .suppressed_mods = OBLITERATE_TRIGGER_MODS,
// };
// const key_override_t DEL_TO_OBLITERATE = {
//     .trigger = KC_DEL,
//     .trigger_mods = OBLITERATE_TRIGGER_MODS,
//     .layers = 0xFF,
//     .custom_action = obliterate_line_forwards,
//     .suppressed_mods = OBLITERATE_TRIGGER_MODS,
// };

// const key_override_t HOME_NOCTRL = ko_make_basic(MOD_MASK_CTRL, KC_HOME, KC_HOME);
// const key_override_t HOME_TO_MEGA_HOME = ko_make_basic(MOD_MASK_GUI, KC_HOME, C(KC_HOME));

// const key_override_t END_NO_CTRL = ko_make_basic(MOD_MASK_CTRL, KC_END, KC_END);
// const key_override_t END_TO_META_END = ko_make_basic(MOD_MASK_GUI, KC_END, C(KC_END));

// const key_override_t ESC_TO_TAB_FORWARD = ko_make_basic(TABBING_TRIGGER_MODS, KC_ESC,
// TAB_FORWARD);

// const key_override_t GRV_TO_TAB_FORWARD = ko_make_basic(TABBING_TRIGGER_MODS, KC_GRV,
// TAB_FORWARD); const key_override_t GRV_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, KC_GRV);

// const key_override_t DOWN_TO_ZOOM_OUT = ko_make_basic(MOD_MASK_CTRL, DOWN, C(KC_MINS));
// const key_override_t DOWN_DEFAULT = ko_make_basic(0, DOWN, KC_DOWN);
// const key_override_t UP_TO_ZOOM_IN = ko_make_basic(MOD_MASK_CTRL, UP, C(KC_EQL));
// const key_override_t UP_DEFAULT = ko_make_basic(0, UP, KC_UP);

// // NUM layer
// const key_override_t FIVE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_5, KC_5);
// const key_override_t SIX_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_6);

// const key_override_t LOW_6_TO_Z = ko_make_basic(MOD_MASK_CTRL, LOW_6, C(KC_Z));
// const key_override_t LOW_6_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, LOW_6, KC_6);
// const key_override_t LOW_6_DEFAULT = ko_make_basic(0, LOW_6, KC_6);

// const key_override_t LOW_7_TO_X = ko_make_basic(MOD_MASK_CTRL, LOW_7, C(KC_X));
// const key_override_t LOW_7_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, LOW_7, KC_7);
// const key_override_t LOW_7_DEFAULT = ko_make_basic(0, LOW_7, KC_7);

// const key_override_t LOW_8_TO_C = ko_make_basic(MOD_MASK_CTRL, LOW_8, C(KC_C));
// const key_override_t LOW_8_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, LOW_8, KC_8);
// const key_override_t LOW_8_DEFAULT = ko_make_basic(0, LOW_8, KC_8);

// const key_override_t LOW_9_TO_V = ko_make_basic(MOD_MASK_CTRL, LOW_9, C(KC_V));
// const key_override_t LOW_9_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, LOW_9, KC_9);
// const key_override_t LOW_9_DEFAULT = ko_make_basic(0, LOW_9, KC_9);

// const key_override_t LOW_0_TO_B = ko_make_basic(MOD_MASK_CTRL, LOW_0, C(KC_B));
// const key_override_t LOW_0_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, LOW_0, KC_0);
// const key_override_t LOW_0_DEFAULT = ko_make_basic(0, LOW_0, KC_0);

// // minus -
// const key_override_t MINUS_TO_R = ko_make_with_layers(MOD_MASK_CTRL, KC_MINS, C(KC_R), 1 <<
// _NUM); const key_override_t MINUS_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_MINS);
// // multiply symbol (prevents conflict with ASTR) *
// const key_override_t MULT_DEFAULT = ko_make_basic(0, MULT, KC_ASTR);
// // circ ^
// const key_override_t CIRC_TO_Y = ko_make_basic(MOD_MASK_CTRL, KC_CIRC, C(KC_Y));
// // ampr &
// const key_override_t AMPR_TO_U = ko_make_basic(MOD_MASK_CTRL, KC_AMPR, C(KC_U));
// // astr *
// const key_override_t ASTR_TO_I = ko_make_basic(MOD_MASK_CTRL, KC_ASTR, C(KC_I));
// // rprn (
// const key_override_t RPRN_TO_P = ko_make_basic(MOD_MASK_CTRL, KC_RPRN, C(KC_P));
// // coln )
// const key_override_t COLN_TO_M = ko_make_with_layers(MOD_MASK_CTRL, KC_COLN, C(KC_M), 1 << _NUM);
// // dlr $
// const key_override_t DLR_TO_R = ko_make_with_layers(MOD_MASK_CTRL, KC_DLR, C(KC_R), 1 << _NAV);
// // eql =
// const key_override_t EQL_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_EQL);
// // pipe |
// const key_override_t PIPE_TO_Z = ko_make_with_layers(MOD_MASK_CTRL, KC_PIPE, C(KC_Z), 1 << _NAV);
// // lcbr {
// const key_override_t LCBR_TO_X = ko_make_with_layers(MOD_MASK_CTRL, KC_LCBR, C(KC_X), 1 << _NAV);
// // rcbr }
// const key_override_t RCBR_TO_C = ko_make_with_layers(MOD_MASK_CTRL, KC_RCBR, C(KC_C), 1 << _NAV);
// // unds _
// const key_override_t UNDS_TO_V = ko_make_with_layers(MOD_MASK_CTRL, KC_UNDS, C(KC_V), 1 << _NAV);
// // plus +
// const key_override_t PLUS_TO_B = ko_make_with_layers(MOD_MASK_CTRL, KC_PLUS, C(KC_B), 1 << _NAV);
// // F2
// const key_override_t F2_TO_M = ko_make_with_layers(MOD_MASK_CTRL, KC_F2, C(KC_M), 1 << _NAV);

// // this globally defines all key overrides to be used
// const key_override_t* key_overrides[] = {
//     &CW_CL_TO_TAB_BACKWARDS,
//     &COMM_TO_TAB_BACKWARDS,
//     &TILDE_TO_TAB_BACKWARDS,
//     &Q_TO_KILL,
//     //
//     &BSPC_TO_OBLITERATE,
//     &DEL_TO_OBLITERATE,

//     &HOME_NOCTRL,
//     &HOME_TO_MEGA_HOME,
//     &END_NO_CTRL,
//     &END_TO_META_END,

//     &ESC_TO_TAB_FORWARD,

//     &GRV_TO_TAB_FORWARD,
//     &GRV_NOSHIFT,

//     &DOWN_TO_ZOOM_OUT,
//     &DOWN_DEFAULT,
//     &UP_TO_ZOOM_IN,
//     &UP_DEFAULT,

//     &FIVE_NOSHIFT,
//     &SIX_NOSHIFT,
//     &LOW_6_TO_Z,
//     &LOW_6_NOSHIFT,
//     &LOW_6_DEFAULT,
//     &LOW_7_TO_X,
//     &LOW_7_NOSHIFT,
//     &LOW_7_DEFAULT,
//     &LOW_8_TO_C,
//     &LOW_8_NOSHIFT,
//     &LOW_8_DEFAULT,
//     &LOW_9_TO_V,
//     &LOW_9_NOSHIFT,
//     &LOW_9_DEFAULT,
//     &LOW_0_TO_B,
//     &LOW_0_NOSHIFT,
//     &LOW_0_DEFAULT,

//     &MINUS_TO_R,
//     &MINUS_NOSHIFT,

//     &MULT_DEFAULT,

//     &CIRC_TO_Y,

//     &AMPR_TO_U,

//     &ASTR_TO_I,

//     &RPRN_TO_P,

//     &COLN_TO_M,

//     &DLR_TO_R,

//     &EQL_NOSHIFT,

//     &PIPE_TO_Z,

//     &LCBR_TO_X,

//     &RCBR_TO_C,

//     &UNDS_TO_V,

//     &PLUS_TO_B,

//     &F2_TO_M,
// };
