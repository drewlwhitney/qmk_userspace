#include QMK_KEYBOARD_H
#include "./alias.h"
#include "./combos/combos.h"
#include "./layers/layers.h"
#include "./tap_dance/tap_dance.h"
#include "./utils/utils.h"
#include <stdbool.h>
#include <stdint.h>

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                                  KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_ESC,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TAB,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                                   KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   CW_TOGG,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       TD_CLS,         GAME,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_DEL,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             LAUNCH_NUM, NAV_CANCEL, KC_SPC,                     OSO_SHIFT,  SYM_ENT,    COMP_ARROW
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_GAME] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,                                   KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_LCTL,    KC_A,       KC_S,       KC_D,       KC_F,                                   KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_TRNS,        KC_TRNS,    KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_ESC,     KC_I,       KC_SPC,                     KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_SYM] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,                                KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_BSLS,    KC_LBRC,    KC_RBRC,    KC_MINS,    KC_EQL,                                 KC_PLUS,    OS_RSFT,    OS_RCTL,    OS_RALT,    OS_RGUI,    KC_DQUO,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_CAPS,    KC_PIPE,    KC_LCBR,    KC_RCBR,    KC_UNDS,    KC_GRV,     KC_TRNS,        QK_BOOT,    KC_TILD,    KC_COLN,    KC_LABK,    KC_RABK,    KC_QUES,    KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    NAV_CANCEL, KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_NAV] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    ZOOM_OUT,   ZOOM_IN,    TAB_LEFT,   TAB_RIGHT,  KC_F11,                                 KC_WFWD,    KC_HOME,    KC_UP,      KC_END,     PH_P,       KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    OS_LGUI,    OS_LALT,    OS_LCTL,    OS_LSFT,    KC_MPLY,                                KC_WBAK,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_SCLN,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_CAPS,    KC_MUTE,    KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,    KC_TRNS,        QK_BOOT,    KC_NO,      KC_F2,      KC_COMM,    KC_DOT,     KC_SLSH,    KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             LAUNCH_NUM, NAV_CANCEL, KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_NUM] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_SLSH,    KC_E,       KC_ASTR,    KC_MINS,    KC_PLUS,                                KC_CIRC,    KC_NO,      KC_NO,      KC_LPRN,    KC_RPRN,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      KC_NO,      KC_SPC,     KC_NO,      KC_NO,      KC_TRNS,        QK_BOOT,    KC_NO,      KC_COLN,    KC_COMM,    KC_DOT,     KC_SCLN,    KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    NAV_CANCEL, KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_SH_NUM] = LAYOUT( // single-handed numbers
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_SLSH,    KC_DOT,     KC_COMM,    KC_NO,      KC_NO,                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_TRNS,        QK_BOOT,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    NAV_CANCEL, KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_SH_ARROW] = LAYOUT( // single-handed arrows
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                  KC_NO,      KC_NO,      KC_UP,      KC_NO,      KC_NO,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                  KC_NO,      KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_NO,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,        QK_BOOT,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    NAV_CANCEL, KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

};
// clang-format on

tap_dance_action_t tap_dance_actions[] = {
    [TD_CAD_LOCK_SLEEP] = ACTION_TAP_DANCE_FN(CAD_lock_sleep),
};

const uint16_t PROGMEM num_layer_combo[] = {NAV_CANCEL, SYM_ENT, COMBO_END};
const uint16_t PROGMEM win_swap_combo[] = {TAB_LEFT, TAB_RIGHT, COMBO_END};

combo_t key_combos[] = {
    [NumCombo] = COMBO(num_layer_combo, NUM),
    [WinSwapCombo] = COMBO(win_swap_combo, WIN_SWAP),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    static bool NAV_is_on = false;

    switch (keycode) {
        // allow the SYM and NAV layers to override each other
        case SYM_ENT:
            if (!record->tap.count) {
                // if NAV is on, turn it off when SYM is turned on, then restore it when SYM
                // is turned off
                // if we're NUM-latched, don't interfere with the states
                if (NAV_is_on) {
                    record->event.pressed && !NUM_latched ? layer_off(_NAV) : layer_on(_NAV);
                }
            }
            break;

        case NAV_CANCEL: // allow oneshot mods to be canceled by pressing this key
            if (!record->tap.count) {
                NAV_is_on = record->event.pressed; // track NAV's state for SYM
            } else {
                if (record->event.pressed) {
                    clear_oneshot_mods();
                }
                return false;
            }
            break;

        case WIN_SWAP: // easy Alt-Tab
            if (record->event.pressed) {
                register_mods(MOD_LALT);
                tap_code(KC_TAB);
            } else {
                unregister_mods(MOD_LALT);
            }
            break;

        case LAUNCH_NUM: // make the launch keycode work
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(LAUNCH);
                }
                return false;
            }
            break;

        case OSO_SHIFT: // make thumb shift oneshot-only
            if (record->event.pressed) {
                set_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            break;
    }
    return true;
}

const key_override_t Q_TO_KILL = ko_make_with_layers(MOD_MASK_GUI, KC_Q, A(KC_F4), 1 << _BASE);

const key_override_t SPACE_TO_MENU = ko_make_basic(MOD_MASK_CTRL, KC_SPACE, MENU);

const key_override_t BSPC_TO_OBLITERATE = {
    .trigger = KC_BSPC,
    .trigger_mods = OBLITERATE_TRIGGER_MODS,
    .layers = 0xFF,
    .custom_action = obliterate_line_backwards,
    .suppressed_mods = OBLITERATE_TRIGGER_MODS,
};
const key_override_t DEL_TO_OBLITERATE = {
    .trigger = KC_DEL,
    .trigger_mods = OBLITERATE_TRIGGER_MODS,
    .layers = 0xFF,
    .custom_action = obliterate_line_forwards,
    .suppressed_mods = OBLITERATE_TRIGGER_MODS,
};

const key_override_t HOME_NOCTRL = ko_make_basic(MOD_MASK_CTRL, KC_HOME, KC_HOME);
const key_override_t HOME_TO_MEGA_HOME = ko_make_basic(MOD_MASK_GUI, KC_HOME, C(KC_HOME));

const key_override_t END_NO_CTRL = ko_make_basic(MOD_MASK_CTRL, KC_END, KC_END);
const key_override_t END_TO_META_END = ko_make_basic(MOD_MASK_GUI, KC_END, C(KC_END));

const key_override_t UP_NO_CTRL = ko_make_basic(MOD_MASK_CTRL, KC_UP, KC_UP);
const key_override_t DOWN_NO_CTRL = ko_make_basic(MOD_MASK_CTRL, KC_DOWN, KC_DOWN);

// SYM layer
// A S F R Z X C V B M P U Y I
const key_override_t BSLS_TO_A = ko_make_with_layers(MOD_MASK_CTRL, KC_BSLS, C(KC_A), 1 << _SYM);
const key_override_t LBRC_TO_S = ko_make_with_layers(MOD_MASK_CTRL, KC_LBRC, C(KC_S), 1 << _SYM);
const key_override_t MINS_TO_F = ko_make_with_layers(MOD_MASK_CTRL, KC_MINS, C(KC_F), 1 << _SYM);
const key_override_t DLR_TO_R = ko_make_with_layers(MOD_MASK_CTRL, KC_DLR, C(KC_R), 1 << _SYM);
const key_override_t PIPE_TO_Z = ko_make_with_layers(MOD_MASK_CTRL, KC_PIPE, C(KC_Z), 1 << _SYM);
const key_override_t LCBR_TO_X = ko_make_with_layers(MOD_MASK_CTRL, KC_LCBR, C(KC_X), 1 << _SYM);
const key_override_t RCBR_TO_C = ko_make_with_layers(MOD_MASK_CTRL, KC_RCBR, C(KC_C), 1 << _SYM);
const key_override_t UNDS_TO_V = ko_make_with_layers(MOD_MASK_CTRL, KC_UNDS, C(KC_V), 1 << _SYM);
const key_override_t GRV_TO_B = ko_make_with_layers(MOD_MASK_CTRL, KC_GRV, C(KC_B), 1 << _SYM);
const key_override_t COLN_TO_M = ko_make_with_layers(MOD_MASK_CTRL, KC_COLN, C(KC_M), 1 << _SYM);
const key_override_t RPRN_TO_P = ko_make_with_layers(MOD_MASK_CTRL, KC_RPRN, C(KC_P), 1 << _SYM);
const key_override_t AMPR_TO_U = ko_make_with_layers(MOD_MASK_CTRL, KC_AMPR, C(KC_U), 1 << _SYM);
const key_override_t ASTR_TO_I = ko_make_with_layers(MOD_MASK_CTRL, KC_ASTR, C(KC_I), 1 << _SYM);
const key_override_t CIRC_TO_Y = ko_make_with_layers(MOD_MASK_CTRL, KC_CIRC, C(KC_Y), 1 << _SYM);

// NAV layer
// R Z X C V B M P Y
const key_override_t TAB_RIGHT_TO_R =
    ko_make_with_layers(MOD_MASK_CTRL, TAB_RIGHT, C(KC_R), 1 << _NAV);
const key_override_t MUTE_TO_Z = ko_make_with_layers(MOD_MASK_CTRL, KC_MUTE, C(KC_Z), 1 << _NAV);
const key_override_t MPRV_TO_X = ko_make_with_layers(MOD_MASK_CTRL, KC_MPRV, C(KC_X), 1 << _NAV);
const key_override_t VOLD_TO_C = ko_make_with_layers(MOD_MASK_CTRL, KC_VOLD, C(KC_C), 1 << _NAV);
const key_override_t VOLU_TO_V = ko_make_with_layers(MOD_MASK_CTRL, KC_VOLU, C(KC_V), 1 << _NAV);
const key_override_t MNXT_TO_B = ko_make_with_layers(MOD_MASK_CTRL, KC_MNXT, C(KC_B), 1 << _NAV);
const key_override_t F2_TO_M = ko_make_with_layers(MOD_MASK_CTRL, KC_F2, C(KC_M), 1 << _NAV);
const key_override_t PLACEHOLDER_TO_P =
    ko_make_with_layers(MOD_MASK_CTRL, PH_P, C(KC_P), 1 << _NAV);
const key_override_t WFWD_TO_Y = ko_make_with_layers(MOD_MASK_CTRL, KC_WFWD, C(KC_Y), 1 << _NAV);

// noshifts
const key_override_t ONE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_1);
const key_override_t TWO_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_2);
const key_override_t THREE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_3, KC_3);
const key_override_t FOUR_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_4, KC_4);
const key_override_t FIVE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_5, KC_5);
const key_override_t SIX_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_6);
const key_override_t SEVEN_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_7);
const key_override_t EIGHT_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_8);
const key_override_t NINE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_9);
const key_override_t ZERO_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_0);

// \[]-=`
const key_override_t BSLS_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, KC_BSLS);
const key_override_t LBRC_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_LBRC);
const key_override_t RBRC_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, KC_RBRC);
const key_override_t MINS_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_MINS);
const key_override_t EQL_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_EQL);
const key_override_t GRV_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, KC_GRV);

// this globally defines all key overrides to be used
const key_override_t* key_overrides[] = {
    &Q_TO_KILL,

    &SPACE_TO_MENU,
    // blocking formatting with this line
    &BSPC_TO_OBLITERATE,
    &DEL_TO_OBLITERATE,

    &HOME_NOCTRL,
    &HOME_TO_MEGA_HOME,
    &END_NO_CTRL,
    &END_TO_META_END,

    &UP_NO_CTRL,
    &DOWN_NO_CTRL,

    // SYM layer Ctrl overrides
    &BSLS_TO_A,
    &LBRC_TO_S,
    &MINS_TO_F,
    &DLR_TO_R,
    &PIPE_TO_Z,
    &LCBR_TO_X,
    &RCBR_TO_C,
    &UNDS_TO_V,
    &GRV_TO_B,
    &COLN_TO_M,
    &RPRN_TO_P,
    &AMPR_TO_U,
    &ASTR_TO_I,
    &CIRC_TO_Y,

    // NAV layer Ctrl overrides
    &TAB_RIGHT_TO_R,
    &MUTE_TO_Z,
    &MPRV_TO_X,
    &VOLD_TO_C,
    &VOLU_TO_V,
    &MNXT_TO_B,
    &F2_TO_M,
    &PLACEHOLDER_TO_P,
    &WFWD_TO_Y,

    // noshifts
    &ONE_NOSHIFT,
    &TWO_NOSHIFT,
    &THREE_NOSHIFT,
    &FOUR_NOSHIFT,
    &FIVE_NOSHIFT,
    &SIX_NOSHIFT,
    &SEVEN_NOSHIFT,
    &EIGHT_NOSHIFT,
    &NINE_NOSHIFT,
    &ZERO_NOSHIFT,

    &BSLS_NOSHIFT,
    &LBRC_NOSHIFT,
    &RBRC_NOSHIFT,
    &MINS_NOSHIFT,
    &EQL_NOSHIFT,
    &GRV_NOSHIFT,
    &GRV_NOSHIFT,
};
