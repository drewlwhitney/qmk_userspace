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
   KC_NO,      KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_NO,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_NO,      KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_NO,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_NO,      KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                                   KC_H,       KC_J,       KC_K,       KC_L,       KC_QUOT,    KC_NO,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_NO,      KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       TD_CLS,         GAME,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_NO,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             FN_LAUNCH,  NAV_TAB,    KC_SPC,                     OS_LSFT,    SYM_BSPC,   ARROW
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
   KC_TRNS,    KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_TRNS,        TG(_GAME),  KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             FN_ESC,     KC_I,       KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_SYM] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,                                KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_BSLS,    KC_LBRC,    KC_RBRC,    KC_MINS,    KC_EQL,                                 KC_GRV,     OS_LSFT,    OS_LCTL,    OS_LALT,    OS_LGUI,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_CAPS,    KC_PIPE,    KC_LCBR,    KC_RCBR,    KC_UNDS,    KC_PLUS,    TD_CLS,         QK_BOOT,    KC_TILD,    KC_COLN,    KC_LABK,    KC_RABK,    KC_SCLN,    KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             FN_LAUNCH,  NAV_TAB,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_NAV] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_ESC,     LAUNCH,     TAB_LEFT,   TAB_RIGHT,  C(KC_Y),                                KC_NO,      KC_HOME,    KC_UP,      KC_END,     KC_SCLN,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    OS_LGUI,    OS_LALT,    OS_LCTL,    OS_LSFT,    CW_TOGG,                                KC_CAPS,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_ENT,     KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    C(KC_Z),    C(KC_X),    C(KC_C),    KC_SPC,     C(KC_V),    TD_CLS,         QK_BOOT,    COMPOSE,    KC_F2,      KC_COMM,    KC_DOT,     KC_DEL,     KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             FN_LAUNCH,  NAV_TAB,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_NUM] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_SLSH,    KC_E,       KC_ASTR,    KC_MINS,    KC_PLUS,                                KC_CIRC,    KC_NO,      KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_SPC,     KC_NO,      KC_DOT,         QK_BOOT,    KC_SCLN,    KC_COLN,    KC_COMM,    KC_DOT,     KC_SLSH,    KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             FN_LAUNCH,  NAV_TAB,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_FUNC] = LAYOUT( // functions
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      KC_NO,      ZOOM_OUT,   ZOOM_IN,    KC_F11,                                 KC_NO,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_MPRV,    KC_MNXT,    KC_VOLD,    KC_VOLU,    KC_MPLY,                                KC_NO,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_BRID,    KC_BRIU,    KC_WBAK,    KC_WFWD,    KC_MUTE,    TD_CLS,         QK_BOOT,    KC_NO,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             FN_LAUNCH,  NAV_TAB,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
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
   KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      TD_CLS,         QK_BOOT,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             FN_LAUNCH,  NAV_TAB,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

};
// clang-format on

tap_dance_action_t tap_dance_actions[] = {
    [TD_CAD_LOCK_SLEEP] = ACTION_TAP_DANCE_FN(CAD_lock_sleep),
    [TD_GAMER_MODE] = ACTION_TAP_DANCE_FN(enter_gamer_mode),
};

const uint16_t PROGMEM num_layer_combo[] = {NAV_TAB, SYM_BSPC, COMBO_END};
const uint16_t PROGMEM win_swap_combo[] = {TAB_LEFT, TAB_RIGHT, COMBO_END};

combo_t key_combos[] = {
    [NumCombo] = COMBO(num_layer_combo, NUM),
    [WinSwapCombo] = COMBO(win_swap_combo, WIN_SWAP),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    static bool NAV_is_on = false;

    switch (keycode) {
        // allow NAV and SYM to override each other
        case SYM_BSPC:
            if (!record->tap.count) {
                // if NAV is on, turn it off when SYM is turned on, then restore it when SYM is
                // turned off
                // if we're NUM-latched, don't interfere with the states
                if (NAV_is_on) {
                    record->event.pressed && !NUM_latched ? layer_off(_NAV) : layer_on(_NAV);
                }
            } else {
                // backspace -> obliterate line
                if (record->event.pressed) {
                    uint8_t mods = get_mods();
                    if ((mods | get_oneshot_mods()) & OBLITERATE_TRIGGER_MODS) {
                        tap_code(DUMMY_MOD_NEUTRALIZER_KEYCODE);
                        unregister_mods(OBLITERATE_TRIGGER_MODS);
                        clear_oneshot_mods();
                        tap_code16(S(KC_HOME));
                        register_code(KC_BSPC);
                        set_mods(mods);
                        return false;
                    }
                }
            }
            break;

        case NAV_TAB:
            if (!record->tap.count) {
                NAV_is_on = record->event.pressed;
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

        case FN_LAUNCH: // make the launch keycode work
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(LAUNCH);
                }
                return false;
            }
            break;

        case KC_SPC:
            if (get_highest_layer(layer_state) == _GAME) {
                return true; // return early
            }
            // have to implement this here instead of as a key override because it was acting
            // weird with layers as a key override
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

const key_override_t Q_TO_KILL = ko_make_with_layers(MOD_MASK_GUI, KC_Q, A(KC_F4), 1 << _BASE);

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

    // blocking formatting with this line
    &DEL_TO_OBLITERATE,

    &HOME_NOCTRL,
    &HOME_TO_MEGA_HOME,
    &END_NO_CTRL,
    &END_TO_META_END,

    &UP_NO_CTRL,
    &DOWN_NO_CTRL,

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
