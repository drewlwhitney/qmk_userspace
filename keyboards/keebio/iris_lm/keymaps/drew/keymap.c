#include QMK_KEYBOARD_H
#include "./alias.h"
#include "./combos/combos.h"
#include "./layers/layers.h"
#include "./utils/utils.h"
#include <stdbool.h>
#include <stdint.h>

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_NO,      KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_NO,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,                                   KC_J,       KC_L,       KC_U,       KC_Y,       KC_QUOT,    KC_BSPC,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_ESC,     KC_A,       KC_R,       KC_S,       KC_T,       KC_G,                                   KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       KC_ENT,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_NO,      KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,       KC_NO,          KC_NO,      KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_DEL,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             FUNC,       NAV,        KC_SPC,                     OS_LSFT,    SYM,        ARROW
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_SH_ARROW] = LAYOUT( // single-handed arrows
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                  KC_J,       KC_L,       KC_UP,      KC_NO,      KC_NO,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                  KC_NO,      KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_NO,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,        KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_SYM] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,                                KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_QUES,    KC_BSLS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_PIPE,    KC_PLUS,    KC_UNDS,    KC_MINS,    KC_EQL,                                 KC_DQUO,    OS_LSFT,    OS_LCTL,    OS_LALT,    OS_LGUI,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_LABK,    KC_LPRN,    KC_RPRN,    KC_LBRC,    KC_RBRC,    KC_TILD,    KC_TRNS,        KC_TRNS,    KC_SCLN,    KC_COLN,    KC_LCBR,    KC_RCBR,    KC_GRV,     KC_RABK,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_NAV] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      C(KC_Y),    TAB_LEFT,   TAB_RIGHT,  LAUNCH,                                 KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     KC_CAPS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    OS_LGUI,    OS_LALT,    OS_LCTL,    OS_LSFT,    KC_F2,                                  COMPOSE,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_NO,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    C(KC_Z),    C(KC_X),    C(KC_C),    KC_SPC,     C(KC_V),    KC_TRNS,        KC_TRNS,    KC_PGDN,    CW_TOGG,    KC_COMM,    KC_DOT,     KC_SLSH,    KC_DEL,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_NUM] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      KC_PLUS,    KC_E,       KC_MINS,    KC_EQL,                                 KC_CIRC,    KC_NO,      KC_ASTR,    KC_NO,      KC_NO,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_LPRN,    KC_RPRN,    KC_NO,      KC_SPC,     KC_NO,      KC_TRNS,        KC_TRNS,    KC_SCLN,    KC_COLN,    KC_COMM,    KC_DOT,     KC_SLSH,    KC_DEL,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_FUNC] = LAYOUT( // functions
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    CAD,        KC_F11,     ZOOM_OUT,   ZOOM_IN,    KC_SLEP,                                QK_BOOT,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_MPRV,    KC_MNXT,    KC_VOLD,    KC_VOLU,    KC_MUTE,                                KC_NO,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_BRID,    KC_BRIU,    KC_WBAK,    KC_WFWD,    KC_NO,      KC_TRNS,        KC_TRNS,    KC_NO,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_DEL,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

};
// clang-format on

const uint16_t PROGMEM num_layer_combo[] = {NAV_TAB, SYM_BSPC, COMBO_END};
const uint16_t PROGMEM win_swap_combo[] = {TAB_LEFT, TAB_RIGHT, COMBO_END};

combo_t key_combos[] = {
   //  [NumCombo] = COMBO(num_layer_combo, NUM),
    [WinSwapCombo] = COMBO(win_swap_combo, WIN_SWAP),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // static bool NAV_is_on = false;

    switch (keycode) {
        case WIN_SWAP: // easy Alt-Tab
            if (record->event.pressed) {
                register_mods(MOD_LALT);
                tap_code(KC_TAB);
            } else {
                unregister_mods(MOD_LALT);
            }
            break;

        case KC_SPC:
            // have to implement this here instead of as a key override because it was acting
            // weird with layers as a key override
            if (get_highest_layer(layer_state) != _BASE) {
                return true;
            }
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                if ((mods | get_oneshot_mods()) & MOD_MASK_CTRL) {
                    del_mods(MOD_MASK_CTRL);
                    clear_oneshot_mods();
                    tap_code16(MENU);
                    set_mods(mods);
                    return false;
                }
            }
            break;
    }
    return true;
}

const key_override_t DEL_TO_OBLITERATE = {
    .trigger = KC_DEL,
    .trigger_mods = OBLITERATE_TRIGGER_MODS,
    .layers = 0xFF,
    .custom_action = obliterate_line_forwards,
};

const key_override_t BSPC_TO_OBLITERATE = {
    .trigger = KC_BSPC,
    .trigger_mods = OBLITERATE_TRIGGER_MODS,
    .layers = 0xFF,
    .custom_action = obliterate_line_backwards,
};

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
    // blocking formatting with this line
    &DEL_TO_OBLITERATE,
    &BSPC_TO_OBLITERATE,

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
