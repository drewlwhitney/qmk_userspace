#include QMK_KEYBOARD_H
#include "./caps_word/caps_word.h"
#include "./layers.h"
#include "./tap_dance/tap_dance.c"
#include "./tap_dance/tap_dance.h"
#include "./taphold/taphold_options.h"
#include "./utils/utils.h"
#include "stdbool.h"
#include "stdint.h"

bool NAV_enabled = false;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base
    [_BASE] = LAYOUT_ortho_4x12(
        KC_ESC,            KC_Q,                 KC_W,           KC_E,                  KC_R,            KC_T,               KC_Y,               KC_U,           KC_I,         KC_O,          KC_P,          KC_BSPC,
        CTL_T(KC_TAB),     KC_A,                 KC_S,           KC_D,                  KC_F,            KC_G,               KC_H,               KC_J,           KC_K,         KC_L,          KC_SCLN,       KC_QUOT,
        GUI_LAUNCH,        KC_Z,                 KC_X,           KC_C,                  KC_V,            KC_B,               KC_N,               KC_M,           KC_COMM,      KC_DOT,        KC_SLSH,       ALT_DEL,
        KC_NO,             FUNC_PLAY,            ALT_T(KC_LALT), TD(TD_CAD_LOCK_SLEEP), SFT_COMP,        NUM_SPC,            NAV_ENT,            SFT_CW,         KC_LEFT,      DOWN,          UP,            KC_RGHT
    ),
    // gamer
    [_GAME] = LAYOUT_ortho_4x12(
        KC_TRNS,           KC_TRNS,              KC_TRNS,        KC_TRNS,               KC_TRNS,         KC_TRNS,            KC_TRNS,            KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
        KC_TAB,            KC_TRNS,              KC_TRNS,        KC_TRNS,               KC_TRNS,         KC_TRNS,            KC_TRNS,            KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
        KC_LSFT,           KC_TRNS,              KC_TRNS,        KC_TRNS,               KC_TRNS,         KC_TRNS,            KC_TRNS,            KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
        KC_LCTL,           KC_TRNS,              KC_TRNS,        KC_PGDN,               KC_PGUP,         KC_TRNS,            KC_TRNS,            KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS
    ),
    // special characters
    // numbers
    [_NUM] = LAYOUT_ortho_4x12(
        KC_TRNS,           KC_SLSH,              KC_AT,          MULT,                  KC_MINS,         KC_PLUS,            KC_CIRC,            KC_AMPR,        KC_ASTR,      KC_LPRN,       KC_RPRN,       KC_TRNS,
        CTL_T(KC_DOT),     KC_1,                 KC_2,           KC_3,                  KC_4,            KC_5,               KC_6,               KC_7,           KC_8,         KC_9,          KC_0,          KC_TRNS,
        SFT_COMM,          LOW_6,                LOW_7,          LOW_8,                 LOW_9,           LOW_0,              KC_SCLN,            KC_COLN,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
        CTL_COLN,          KC_TRNS,              KC_TRNS,        KC_TRNS,               KC_TRNS,         KC_NO,              KC_TRNS,            KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS
    ),
    [_NAV] = LAYOUT_ortho_4x12(
        KC_GRV,            KC_EXLM,              KC_AT,          KC_HASH,               KC_DLR,          KC_PERC,            KC_CIRC,            KC_AMPR,        KC_ASTR,      KC_LPRN,       KC_RPRN,       KC_TRNS,
        KC_TRNS,           KC_BSLS,              KC_LBRC,        KC_RBRC,               KC_MINS,         KC_EQL,             KC_HOME,            KC_LEFT,        KC_DOWN,      KC_UP,         KC_RGHT,       KC_END,
        SFT_TILD,          KC_PIPE,              KC_LCBR,        KC_RCBR,               KC_UNDS,         KC_PLUS,            KC_NO,              KC_F2,          KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
        KC_TRNS,           KC_TRNS,              KC_TRNS,        KC_TRNS,               KC_TRNS,         KC_TRNS,            KC_NO,              KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS
    ),
    // function
    [_FUNC] = LAYOUT_ortho_4x12(
        KC_F1,             KC_F2,                KC_F3,          KC_F4,                 KC_F5,           KC_F6,              KC_F7,              KC_F8,          KC_F9,        KC_F10,        KC_F11,        KC_F12,
        KC_F7,             KC_F8,                KC_F9,          KC_F10,                KC_F11,          KC_F12,             KC_NO,              KC_NO,          KC_NO,        KC_NO,         KC_NO,         QK_RBT,
        KC_TRNS,           KC_MUTE,              KC_MPRV,        KC_VOLD,               KC_VOLU,         KC_MNXT,            KC_NO,              KC_NO,          KC_NO,        KC_NO,         TG(_GAME),     QK_BOOT,
        KC_TRNS,           KC_NO,                KC_BRID,        KC_BRIU,               KC_TRNS,         KC_TRNS,            KC_TRNS,            KC_TRNS,        KC_WBAK,      KC_TRNS,       KC_TRNS,       KC_WFWD
    ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        // make it possible to go from layer 3 to layer 2
        case NUM_SPC:
            if (!record->tap.count) {
                if (NAV_enabled) {
                    record->event.pressed ? layer_off(_NAV) : layer_on(_NAV);
                }
            } else {
                if (record->event.pressed) {
                    uint8_t mods = get_mods();
                    if (mods & MOD_MASK_CTRL) {
                        del_mods(MOD_MASK_CTRL);
                        tap_code16(MENU);
                        set_mods(mods);
                        return false;
                    }
                }
            }
            break;

        case NAV_ENT:
            if (!record->tap.count) {
                NAV_enabled = record->event.pressed;
            }
            break;

        case GUI_LAUNCH: {
            static bool tab_backward_held = false;
            if (record->tap.count) {
                if (record->event.pressed) {
                    uint8_t mods = get_mods();
                    if (mods & TABBING_TRIGGER_MODS) { // tabbing
                        del_mods(TABBING_TRIGGER_MODS);
                        register_code16(TAB_BACKWARD);
                        set_mods(mods);
                        tab_backward_held = true; // set the flag
                    } else {
                        tap_code16(LAUNCH);
                    }
                } else {
                    if (tab_backward_held) {
                        tab_backward_held = false; // clear the flag
                        unregister_code16(TAB_BACKWARD);
                        neutralize_flashing_mods();
                    }
                }
                return false;
            }
            break;
        }

        case ALT_DEL:
            if (record->tap.count) { // only trigger on taps, not holds
                uint8_t mods = get_mods();
                if (mods & OBLITERATE_TRIGGER_MODS) { // obliterate line forwards
                    if (record->event.pressed) {
                        del_mods(OBLITERATE_TRIGGER_MODS);
                        tap_code16(S(KC_END));
                        register_code(KC_DEL);
                        set_mods(mods);
                        return false;
                    } else {
                        neutralize_flashing_mods();
                    }
                }
            }
            break;

        case SFT_COMP:
            if (record->tap.count && record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code(KC_CAPS);
                    return false;
                }
            }
            break;

        case SFT_CW:
            if (record->tap.count && record->event.pressed) { // only trigger on taps
                if (get_mods() & MOD_MASK_SHIFT) { // caps lock
                    tap_code(KC_CAPS);
                } else { // caps word
                    caps_word_toggle();
                }
                return false;
            }
            break;

        case SFT_TILD: {
            static bool tab_backward_held = false;
            if (record->tap.count) {
                if (record->event.pressed) {
                    uint8_t mods = get_mods();
                    if (mods & TABBING_TRIGGER_MODS) { // tabbing
                        del_mods(TABBING_TRIGGER_MODS);
                        register_code16(TAB_BACKWARD);
                        set_mods(mods);
                        tab_backward_held = true; // set the flag
                    } else { // TILDE is 16-bit
                        register_code16(KC_TILD);
                    }
                } else {
                    if (tab_backward_held) {
                        tab_backward_held = false; // clear the flag
                        unregister_code16(TAB_BACKWARD);
                        neutralize_flashing_mods();
                    } else {
                        unregister_code16(KC_TILD);
                    }
                }
                return false;
            }
            break;
        }

        case SFT_COMM: {
            static bool tab_backward_held = false;
            if (record->tap.count) {
                if (record->event.pressed) {
                    uint8_t mods = get_mods();
                    if (mods & TABBING_TRIGGER_MODS) { // tabbing
                        del_mods(TABBING_TRIGGER_MODS);
                        register_code16(TAB_BACKWARD);
                        set_mods(mods);
                        tab_backward_held = true; // set the flag
                        return false;
                    }
                } else {
                    if (tab_backward_held) {
                        unregister_code16(TAB_BACKWARD);
                        neutralize_flashing_mods();
                        return false;
                    }
                }
            }
            break;
        }

        case CTL_COLN: // COLN is 16-bit
            if (record->tap.count) {
                (record->event.pressed ? register_code16 : unregister_code16)(KC_COLN);
                return false;
            }
            break;

        // make it so only the opposite-side shift key works
        case KC_Q:
        case KC_W:
        case KC_E:
        case KC_R:
        case KC_T:
        case KC_A:
        case KC_S:
        case KC_D:
        case KC_F:
        case KC_G:
        case KC_Z:
        case KC_X:
        case KC_C:
        case KC_V:
        case KC_B: // left-side
            if (record->event.pressed && get_mods() == MOD_BIT(KC_LSFT)) {
                del_mods(MOD_BIT(KC_LSFT)); // unmod the key
            }
            break;

        case KC_Y:
        case KC_U:
        case KC_I:
        case KC_O:
        case KC_P:
        case KC_H:
        case KC_J:
        case KC_K:
        case KC_L:
        case KC_SCLN:
        case KC_QUOT:
        case KC_N:
        case KC_M:
        case KC_COMM:
        case KC_DOT:
        case KC_SLSH:
            if (record->event.pressed && get_mods() == MOD_BIT(KC_RSFT)) {
                del_mods(MOD_BIT(KC_RSFT));
            }
            break;
    }
    return true;
}

const key_override_t Q_TO_KILL = ko_make_with_layers(MOD_MASK_GUI, KC_Q, A(KC_F4), 1 << _BASE);

const key_override_t BSPC_TO_OBLITERATE = {
    .trigger = KC_BSPC,
    .trigger_mods = OBLITERATE_TRIGGER_MODS,
    .layers = 0xFF,
    .custom_action = obliterate_line_backwards,
    .suppressed_mods = OBLITERATE_TRIGGER_MODS,
};

const key_override_t HOME_NOCTRL = ko_make_basic(MOD_MASK_CTRL, KC_HOME, KC_HOME);
const key_override_t HOME_TO_MEGA_HOME = ko_make_basic(MOD_MASK_GUI, KC_HOME, C(KC_HOME));

const key_override_t END_NO_CTRL = ko_make_basic(MOD_MASK_CTRL, KC_END, KC_END);
const key_override_t END_TO_META_END = ko_make_basic(MOD_MASK_GUI, KC_END, C(KC_END));

const key_override_t ESC_TO_TAB_FORWARD = ko_make_basic(TABBING_TRIGGER_MODS, KC_ESC, TAB_FORWARD);

const key_override_t GRV_TO_TAB_FORWARD = ko_make_basic(TABBING_TRIGGER_MODS, KC_GRV, TAB_FORWARD);
const key_override_t GRV_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, KC_GRV);

const key_override_t DOWN_TO_ZOOM_OUT = ko_make_basic(MOD_MASK_CTRL, DOWN, C(KC_MINS));
const key_override_t DOWN_DEFAULT = ko_make_basic(0, DOWN, KC_DOWN);
const key_override_t UP_TO_ZOOM_IN = ko_make_basic(MOD_MASK_CTRL, UP, C(KC_EQL));
const key_override_t UP_DEFAULT = ko_make_basic(0, UP, KC_UP);

// NUM layer
const key_override_t ONE_TO_A = ko_make_with_layers(MOD_MASK_CTRL, KC_1, C(KC_A), 1 << _NUM);
const key_override_t ONE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_1);

const key_override_t TWO_TO_S = ko_make_with_layers(MOD_MASK_CTRL, KC_2, C(KC_S), 1 << _NUM);
const key_override_t TWO_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_2);

const key_override_t THREE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_3, KC_3);

const key_override_t FOUR_TO_F = ko_make_with_layers(MOD_MASK_CTRL, KC_4, C(KC_F), 1 << _NUM);
const key_override_t FOUR_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_4, KC_4);

const key_override_t FIVE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_5, KC_5);

const key_override_t SIX_TO_H = ko_make_with_layers(MOD_MASK_CTRL, KC_6, C(KC_H), 1 << _NUM);
const key_override_t SIX_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_6);

const key_override_t SEVEN_TO_J = ko_make_with_layers(MOD_MASK_CTRL, KC_7, C(KC_J), 1 << _NUM);
const key_override_t SEVEN_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_7);

const key_override_t EIGHT_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_8);

const key_override_t NINE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_9);

const key_override_t ZERO_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_0);

const key_override_t LOW_6_TO_Z = ko_make_basic(MOD_MASK_CTRL, LOW_6, C(KC_Z));
const key_override_t LOW_6_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, LOW_6, KC_6);
const key_override_t LOW_6_DEFAULT = ko_make_basic(0, LOW_6, KC_6);

const key_override_t LOW_7_TO_X = ko_make_basic(MOD_MASK_CTRL, LOW_7, C(KC_X));
const key_override_t LOW_7_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, LOW_7, KC_7);
const key_override_t LOW_7_DEFAULT = ko_make_basic(0, LOW_7, KC_7);

const key_override_t LOW_8_TO_C = ko_make_basic(MOD_MASK_CTRL, LOW_8, C(KC_C));
const key_override_t LOW_8_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, LOW_8, KC_8);
const key_override_t LOW_8_DEFAULT = ko_make_basic(0, LOW_8, KC_8);

const key_override_t LOW_9_TO_V = ko_make_basic(MOD_MASK_CTRL, LOW_9, C(KC_V));
const key_override_t LOW_9_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, LOW_9, KC_9);
const key_override_t LOW_9_DEFAULT = ko_make_basic(0, LOW_9, KC_9);

const key_override_t LOW_0_TO_B = ko_make_basic(MOD_MASK_CTRL, LOW_0, C(KC_B));
const key_override_t LOW_0_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, LOW_0, KC_0);
const key_override_t LOW_0_DEFAULT = ko_make_basic(0, LOW_0, KC_0);

// minus -
const key_override_t MINUS_TO_R = ko_make_with_layers(MOD_MASK_CTRL, KC_MINS, C(KC_R), 1 << _NUM);
const key_override_t MINUS_TO_F = ko_make_with_layers(MOD_MASK_CTRL, KC_MINS, C(KC_F), 1 << _NAV);
const key_override_t MINUS_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_MINS);

// multiply symbol (prevents conflict with ASTR) *
const key_override_t MULT_DEFAULT = ko_make_basic(0, MULT, KC_ASTR);

// circ ^
const key_override_t CIRC_TO_Y = ko_make_basic(MOD_MASK_CTRL, KC_CIRC, C(KC_Y));

// ampr &
const key_override_t AMPR_TO_U = ko_make_basic(MOD_MASK_CTRL, KC_AMPR, C(KC_U));

// astr *
const key_override_t ASTR_TO_I = ko_make_basic(MOD_MASK_CTRL, KC_ASTR, C(KC_I));

// rprn (
const key_override_t RPRN_TO_P = ko_make_basic(MOD_MASK_CTRL, KC_RPRN, C(KC_P));

// coln )
const key_override_t COLN_TO_M = ko_make_with_layers(MOD_MASK_CTRL, KC_COLN, C(KC_M), 1 << _NUM);

// dlr $
const key_override_t DLR_TO_R = ko_make_with_layers(MOD_MASK_CTRL, KC_DLR, C(KC_R), 1 << _NAV);

// bsls
const key_override_t BSLS_TO_A = ko_make_with_layers(MOD_MASK_CTRL, KC_BSLS, C(KC_A), 1 << _NAV);
const key_override_t BSLS_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, KC_BSLS);

// lbrc [
const key_override_t LBRC_TO_S = ko_make_with_layers(MOD_MASK_CTRL, KC_LBRC, C(KC_S), 1 << _NAV);
const key_override_t LBRC_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_LBRC);

// rbrc ]
const key_override_t RBRC_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, KC_RBRC);

// eql =
const key_override_t EQL_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_EQL);

// pipe |
const key_override_t PIPE_TO_Z = ko_make_with_layers(MOD_MASK_CTRL, KC_PIPE, C(KC_Z), 1 << _NAV);

// lcbr {
const key_override_t LCBR_TO_X = ko_make_with_layers(MOD_MASK_CTRL, KC_LCBR, C(KC_X), 1 << _NAV);

// rcbr }
const key_override_t RCBR_TO_C = ko_make_with_layers(MOD_MASK_CTRL, KC_RCBR, C(KC_C), 1 << _NAV);

// unds _
const key_override_t UNDS_TO_V = ko_make_with_layers(MOD_MASK_CTRL, KC_UNDS, C(KC_V), 1 << _NAV);

// plus +
const key_override_t PLUS_TO_B = ko_make_with_layers(MOD_MASK_CTRL, KC_PLUS, C(KC_B), 1 << _NAV);

// F2
const key_override_t F2_TO_M = ko_make_with_layers(MOD_MASK_CTRL, KC_F2, C(KC_M), 1 << _NAV);

// this globally defines all key overrides to be used
const key_override_t* key_overrides[] = {
    &Q_TO_KILL,
    //
    &BSPC_TO_OBLITERATE,

    &HOME_NOCTRL,
    &HOME_TO_MEGA_HOME,
    &END_NO_CTRL,
    &END_TO_META_END,

    &ESC_TO_TAB_FORWARD,

    &GRV_TO_TAB_FORWARD,
    &GRV_NOSHIFT,

    &DOWN_TO_ZOOM_OUT,
    &DOWN_DEFAULT,
    &UP_TO_ZOOM_IN,
    &UP_DEFAULT,

    &ONE_TO_A,
    &ONE_NOSHIFT,
    &TWO_TO_S,
    &TWO_NOSHIFT,
    &THREE_NOSHIFT,
    &FOUR_TO_F,
    &FOUR_NOSHIFT,
    &FIVE_NOSHIFT,
    &SIX_TO_H,
    &SIX_NOSHIFT,
    &SEVEN_TO_J,
    &SEVEN_NOSHIFT,
    &EIGHT_NOSHIFT,
    &NINE_NOSHIFT,
    &ZERO_NOSHIFT,
    &LOW_6_TO_Z,
    &LOW_6_NOSHIFT,
    &LOW_6_DEFAULT,
    &LOW_7_TO_X,
    &LOW_7_NOSHIFT,
    &LOW_7_DEFAULT,
    &LOW_8_TO_C,
    &LOW_8_NOSHIFT,
    &LOW_8_DEFAULT,
    &LOW_9_TO_V,
    &LOW_9_NOSHIFT,
    &LOW_9_DEFAULT,
    &LOW_0_TO_B,
    &LOW_0_NOSHIFT,
    &LOW_0_DEFAULT,

    &MINUS_TO_R,
    &MINUS_TO_F,
    &MINUS_NOSHIFT,

    &MULT_DEFAULT,

    &CIRC_TO_Y,

    &AMPR_TO_U,

    &ASTR_TO_I,

    &RPRN_TO_P,

    &COLN_TO_M,

    &DLR_TO_R,

    &BSLS_TO_A,
    &BSLS_NOSHIFT,

    &LBRC_TO_S,
    &LBRC_NOSHIFT,

    &RBRC_NOSHIFT,

    &EQL_NOSHIFT,

    &PIPE_TO_Z,

    &LCBR_TO_X,

    &RCBR_TO_C,

    &UNDS_TO_V,

    &PLUS_TO_B,

    &F2_TO_M,
};

